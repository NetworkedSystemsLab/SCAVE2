#include "tachometer.h"

int main(int argc, char** argv)
{
 std::cout << "Testing tachometer" << std::endl;

 tachometer tach;
 std::cout << (std::string)tach << std::endl;

 pthread_exit(NULL);
}
