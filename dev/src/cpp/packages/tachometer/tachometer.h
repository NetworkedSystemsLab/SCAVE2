#ifndef __TACHOMETER_H__
#define __TACHOMETER_H__

#include "../common/common.h"
#include "../jetsonTX2/jetsonTX2.h"
class tachometer
{
public:
GPIO* pin;
pthread_t thread;
double rpm, avgRpm, runningAvgRpm;
unsigned revolutions, odometer;

tachometer();
~tachometer();

void calibrate();
void calibrateToNeutral();
static void* read(void* args);
operator std::string() const;
};

#endif
