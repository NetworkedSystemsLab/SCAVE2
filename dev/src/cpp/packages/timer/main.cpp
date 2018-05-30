#include "timer.h"

bool testUs();
bool testMs();
bool testS();
bool testWait();
bool testTimer();

timer* sharedTimer;
int main(int argc, char** argv)
{
 sharedTimer = new timer;

 std::cout << "Testing Timer" << std::endl;

 unsigned flags, passed = 0, total = 5;

 flags = (testUs() ? 0x1 : 0) |
	 (testMs() ? 0x2 : 0) |
	 (testS() ? 0x4 : 0) |
	 (testWait() ? 0x8 : 0) |
	 (testTimer() ? 0x10 : 0);

 if(flags & 0x1)
 {
  std::cout << "Microseconds test passed" << std::endl;
  passed++;
 }
 if(flags & 0x2)
 {
  std::cout << "Milliseconds test passed" << std::endl;
  passed++;
 }
 if(flags & 0x4)
 {
  std::cout << "Seconds test passed" << std::endl;
  passed++;
 }
 if(flags & 0x8)
 {
  std::cout << "Wait test passed" << std::endl;
  passed++;
 }
 if(flags & 0x10)
 {
  std::cout << "Timer test passed" << std::endl;
  passed++;
 }

 if(passed == total)
 {
  std::cout << "ALL OK";
 } else {
  std::cout << passed << " / " << total << " tests passed";
 }
 sharedTimer->update();
 std::cout << "\t[" << (std::string)*sharedTimer << "]" << std::endl;

 delete sharedTimer;
 pthread_exit(NULL);
}




bool testUs()
{
 timer test;
 usleep(1000);
 if(test.micros() > 0) return true;
 return false;
}
bool testMs()
{
 timer test;
 usleep(5000);
 if(test.millis() > 0) return true;
 return false;
}
bool testS()
{
 timer test;
 usleep(1500000);
 if(test.seconds() > 0) return true;
 return false;
}
bool testWait()
{
 timer test;

 while(test.millis() < 3000)
 {
  usleep(100000);
 }

 return true;
}
bool testTimer()
{
 return testUs() && testMs() && testS();
}
