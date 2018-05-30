#include "../include/tach.h"

tachometer::tachometer(input* kb):
 running(1),
 revolutions(0),
 odometer(0.0),
 rpm(0.0),
 avg_rpm(0.0),
 running_avg_rpm(0.0),
 calibrated(false),
 inputSrc(kb)
{
 printf("Creating tachometer...\n");
 initPin(TACHOMETER, TACHOMETER_SYSFS, 0);
 process = new thread(tachometer::read_tach, this);
 process->launch();
}


tachometer::~tachometer()
{
 printf("Closing tachometer...\n");
 running = 0;
 if(process)
 {
  process->await();
  delete process;
 }
 closePin(TACHOMETER);
}


void tachometer::calibrate()
{
 printf("[TACH] calibrating...\n");
 calibrated = false;
 revolutions = 0;
 while(revolutions < CALIBRATE_REVOLUTIONS);
 calibrated = true;
 revolutions = 0;
 hardBrake();
 printf("[TACH] done calibrating\n");
 inputSrc->flush();
}



void tachometer::calibrateToNeutral()
{
 printf("[TACH] calibrating...\n");
 calibrated = false;
 revolutions = 0;
 while(revolutions < CALIBRATE_REVOLUTIONS);
 calibrated = true;
  revolutions = 0;
 goNeutral();
 printf("[TACH] done calibrating to neutral\n");
 inputSrc->flush();
}




void* tachometer::read_tach(void* args)
{
 printf("Launching tachometer thread...\n");
 tachometer* tach = (tachometer*)args;

 if(!tach)
 {
  printf("ERROR launching tach. aborting...\n");
  pthread_exit(NULL);
 }

 FILE* fp = fopen("tachometer_edges.txt", "w");
 if(fp)
 {
  fprintf(fp, "[last edge] [this edge] [global time]\n");
  fclose(fp);
 } else {
  printf("Nah, tachometer_edges.txt can't be written to\n");
 }

 fp = fopen("tachometer_info.txt", "w");
 if(fp)
 {
  fprintf(fp, "[RPM] [AVG RPM] [ODOMETER] [REVOLUTION] [global time] [is calibrated?]\n");
  fclose(fp);
 } else {
  printf("Nah, tachometer_info.txt can't be written to\n");
 }
 TIMER edgeTimer, timeout, brakeTimeout;
 initTimer(&edgeTimer);
 initTimer(&timeout);

 unsigned counts = 0;
 unsigned values[2] = {0,0};
 printf("Beginning main tach loop\n");
 while(tach && tach->running)
 {
  values[1] = values[0];
  values[0] = readPin(TACHOMETER);

  //edge occurred
  if(values[0] != values[1])
  {
   fp = fopen("tachometer_edges.txt", "a");
   fprintf(fp, "%u %u %lf\n", values[1], values[0], millis(&global_timer));
   fclose(fp);

   if(values[1] == 0)
   {
    tach->odometer += DIST_WHEEL_REV / 3.0;
    tach->revolutions++;
    counts++;
    printf("[TACH]\todom: %lf\trev: %u\n", tach->odometer, tach->revolutions);
    if(tach->calibrated)
    {
     printf("[TACH]\tovershot by %lf in [%u rotations]\n", tach->odometer, tach->revolutions);
     fp = fopen("tachometer_info.txt", "a");
     fprintf(fp, "%lf %lf %lf %u %lf %s\n", tach->rpm, tach->avg_rpm, tach->odometer, tach->revolutions, millis(&global_timer), tach->calibrated ? "TRUE" : "FALSE");
     fclose(fp);
    }
   }
   initTimer(&edgeTimer);
  }

  double ms = millis(&timeout);
  static unsigned avg_rpm_counter = 0;
  if(counts > 0)
  {
   avg_rpm_counter++;
   tach->rpm = (((double)counts)/ms)*60000;
   tach->running_avg_rpm += tach->rpm;
   if(avg_rpm_counter % 3 == 0)
   {
    tach->avg_rpm = tach->running_avg_rpm/3;
    tach->running_avg_rpm = 0;
   }
   fp = fopen("tachometer_info.txt", "a");
   fprintf(fp, "%lf %lf %lf %u %lf %s\n", tach->rpm, tach->avg_rpm, tach->odometer, tach->revolutions, millis(&global_timer), tach->calibrated ? "TRUE" : "FALSE");
   fclose(fp);
   printf("[TACH]: rpm={ %lf }, avg_rpm={ %lf }\n", tach->rpm, tach->avg_rpm);
   initTimer(&timeout);
   counts = 0;
   //always reset brakeTimeout when we're moving
   initTimer(&brakeTimeout);
  }
  if(ms > 2000)
  {
   bool brakeDisengaged = false;
   pthread_mutex_lock(&brake_mutex);
   if(brake_commanded && (millis(&brakeTimeout) > 3000))
   {
    brake_commanded = false;
    brakeDisengaged = true;
   }
   pthread_mutex_unlock(&brake_mutex);

   if(brakeDisengaged)
   {
    goNeutral();
    if(tach->inputSrc)
     tach->inputSrc->flush();

    //we told it to go neutral, thus "brake_commanded" is set. so we must reset it.
    pthread_mutex_lock(&brake_mutex);
    brake_commanded = false;
    pthread_mutex_unlock(&brake_mutex);
//    writePin(BRAKING_PIN, 0);
   }
   avg_rpm_counter = 0;
   tach->running_avg_rpm = 0;
   tach->avg_rpm = 0;
   tach->rpm = 0;
   printf("[TACH]: rpm= { 0 }, avg_rpm={ 0 }\n");
   initTimer(&timeout);
   counts = 0;
  }
 }

 printf("Terminating tachometer thread...\n");
 pthread_exit(NULL);
}
