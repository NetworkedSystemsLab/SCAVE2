#include "common.h"

bool testThread();
bool testFileStream();
bool testVector();



struct timeval timer;
int main(int argc, char** argv)
{
 gettimeofday(&timer, NULL);
 std::cout << "Testing Common.h" << std::endl << std::endl;

 unsigned passFlags, passed = 0, total = 3;
 if(testThread())
 {
  passFlags |= 0x1;
  passed++;
 }
 if(testFileStream())
 {
  passFlags |= 0x2;
  passed++;
 }
 if(testVector())
 {
  passFlags |= 0x4;
  passed++;
 }

 if(passFlags & 0x1)
  std::cout << "Passed Thread Test" << std::endl;
 if(passFlags & 0x2)
  std::cout << "Passed Filestream Test" << std::endl;
 if(passFlags & 0x4)
  std::cout << "Passed Vector Test" << std::endl;
 std::cout << std::endl;
 if(passed == total)
 {
  std::cout << "ALL OK";
 } else {
  std::cout << passed << " / " << total << " tests passed" << std::endl;
  std::cout << "(" << (total - passed) << " tests failed)";
 }

 struct timeval end;
 gettimeofday(&end, NULL);
 unsigned ms = ((end.tv_sec - timer.tv_sec) * 1000) + ((double)(end.tv_usec - timer.tv_usec) / 1000);

 std::cout << "\t[";
 if(ms > 1000)
 {
  unsigned s = ms / 1000;
  ms %= 1000;

  if(s > 60)
  {
   unsigned min = s / 60;
   s %= 60;
   std::cout << min << "min : ";
  }
  std::cout << s << "s : ";
 }
 std::cout << ms << "ms]" << std::endl;

 pthread_exit(NULL);
}










void* null(void* args)
{
 //sleep 10 s
 printf("Pausing");
 for(unsigned i = 0; i < 10; i++)
 {
  printf(".");
  usleep(1000000);
 }
 std::cout << std::endl;
 pthread_exit(NULL);
}
bool testThread()
{
 pthread_t thread;
 pthread_create(&thread, NULL, null, NULL);
 pthread_join(thread, NULL);
 return true;
}
bool testFileStream()
{
 char string[22] = {'T', 'h', 'i', 's', ' ',
		    'i', 's', ' ', 'a', ' ',
		    't', 'e', 's', 't', ' ',
		    's', 't', 'r', 'i', 'n',
		    'g', '\0'};
 std::ofstream ofile(".testfile.txt");
 ofile << string << std::endl;
 ofile.close();

 std::ifstream ifile(".testfile.txt");
 for(unsigned i = 0; i < 22; i++)
 {
  char in;
  ifile >> in;
 }
 return true;
}
bool testVector()
{
 std::vector<unsigned> veryLargeVector;
 for(unsigned i = 0; i < 100000; i++)
 {
  veryLargeVector.push_back(i * i);
 }
 return veryLargeVector.size() == 100000;
}
