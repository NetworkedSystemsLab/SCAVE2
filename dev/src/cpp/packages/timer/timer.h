#ifndef __TIMER_H__
#define __TIMER_H__

#include "../common/common.h"

class timer
{
public:
struct timeval begin, end;
double us, ms, s;

timer();

timer& reset();
timer& update();
double micros();
double millis();
double seconds();

operator std::string() const;
};

#endif
