#ifndef __TACH_H__
#define __TACH_H__

#include "main.h"
#include "threads.h"
#include "keys.h"

class tachometer
{
public:
 input* inputSrc;
 double odometer;
 double rpm;
 double avg_rpm;
 double running_avg_rpm;
 unsigned revolutions;
 int running;
 thread* process;
 bool calibrated;

 tachometer(input* kb);
 ~tachometer();

 void calibrate();
 void calibrateToNeutral();
 static void* read_tach(void* args);
};

#endif
