#include "timer.h"

timer::timer()
{
 reset();
}

timer& timer::reset()
{
 gettimeofday(&begin, NULL);
 memcpy(&end, &begin, sizeof(struct timeval));
 us = ms = s = 0.0;
 return *this;
}
timer& timer::update()
{
 gettimeofday(&end, NULL);
 ms = ((end.tv_usec - begin.tv_usec) / 1000) + ((end.tv_sec - begin.tv_sec) * 1000);
 us = ms * 1000;
 s = ms / 1000;
 return *this;
}
double timer::micros()
{
 return update().us;
}
double timer::millis()
{
 return update().ms;
}
double timer::seconds()
{
 return update().s;
}
timer::operator std::string() const
{
 std::ostringstream output;
 double ms = this->ms;
 unsigned _ms = ms;
 if(_ms >= 1000)
 {
  _ms = (unsigned)ms % 1000;
  unsigned _s = ms / 1000;
  if(_s >= 60)
  {
   unsigned _min = _s / 60;
   _s %= 60;
   output << _min << "min : ";
  }
  output << _s << "s : ";
 }
 output << _ms << "ms";
 return output.str();
}
