#include "tachometer.h"
#include "../timer/timer.h"

pthread_t thread;
double rpm, avgRpm, runningAvgRpm;
unsigned revolutions, odometer;

tachometer::tachometer()
{
#ifndef JETSON
 #define TACHOMETER_PIN pin7
#endif
 pin = new GPIO(TACHOMETER_PIN, in);
 std::cout << "Creating tachometer" << std::endl;
 rpm = avgRpm = runningAvgRpm = 0.0;
 revolutions = odometer = 0;
 pthread_create(&thread, NULL, tachometer::read, this);
}
tachometer::~tachometer()
{
 std::cout << "Releasing tachometer" << std::endl;
 pthread_cancel(thread);
 delete pin;
}

void tachometer::calibrate()
{
 std::cout << "Calibrating tachometer" << std::endl;
#ifndef JETSON
 #define CALIBRATE_REVOLUTIONS 10
#endif
 while(revolutions < CALIBRATE_REVOLUTIONS)
 {

 }
 std::cout << "Braking" << std::endl;
//brake();
 revolutions = 0;
}
void tachometer::calibrateToNeutral()
{
 std::cout << "Calibrating tachometer" << std::endl;
 while(revolutions < CALIBRATE_REVOLUTIONS)
 {

 }
 std::cout << "Going to neutral" << std::endl;
//neutral();
 revolutions = 0;
}
void* tachometer::read(void* args)
{
 std::cout << "Launching tachometer thread" << std::endl;

 tachometer* tach = (tachometer*)args;
 if(!tach)
 {
  std::cout << "ERROR launching tachometer. aborting..." << std::endl;
  pthread_exit(NULL);
 }

 //timers[0] = edge timer
 //timers[1] = timeout timer
 //timers[2] = brake timeout
 timer timers[3];

 //values[0] = current tachometer value
 //values[1] = previous tachometer value
 unsigned values[2] = {0, 0};

 std::cout << "Running tachometer thread" << std::endl;
 while(tach)
 {
  values[1] = values[0];

  //get the current tachometer pin value
  tach->pin->GetValue( &values[0] );

  //there is an edge b/c the two values are different
  if(values[0] != values[1])
  {
   //one revolution has occurred
   if(values[1] == 0)
   {
    //GEAR_RATIO = 3 : 1
//TODO: delete next def:
#ifndef JETSON
 #define GEAR_RATIO 3
 #define DISTANCE_WHEEL_REV_CM (4.41 * 2.54)
#endif
    tach->odometer += DISTANCE_WHEEL_REV_CM / GEAR_RATIO;
    tach->revolutions++;
   }
  }

  timers[0].reset();
 }
 std::cout << "ERROR tachometer is now NULL. aborting..." << std::endl;

 //(should be) never reached; is terminated (cancelled)
 pthread_exit(NULL);
}
tachometer::operator std::string() const
{
 std::ostringstream output;

 output << "Tachometer object" << std::endl;
 output << rpm << " : RPM" << std::endl;
 output << revolutions << " : cm" << std::endl;
 output << odometer << " : cm" << std::endl;

 return output.str();
}
