#include "serial.h"

int main(int argc, char** argv)
{
 std::cout << "Testing serial" << std::endl;
 serial* ports[2];

 ports[0] = new writer;
 ports[1] = new reader;



 delete ports[0];
 delete ports[1];

 pthread_exit(NULL);
}
