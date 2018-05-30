#include "serial.h"

pthread_mutex_t serial::serialMutex;
int serial::fd;
bool serial::loadedFile;

serial::serial(void* (*func)(void*), void* args)
{
 pthread_mutex_lock(&serialMutex);
 serial::fd = -1;
 serial::loadedFile = false;
 pthread_mutex_unlock(&serialMutex);

 baudrate = B9600;
 port = "/dev/ttyACM0";
 pthread_create(&thread, NULL, func, args);

 std::cout << "Creating seral";
}
serial::~serial()
{
 std::cout << "Destroying serial object" << std::endl;
 pthread_cancel(thread);
 pthread_mutex_lock(&serial::serialMutex);
 if(serial::loadedFile)
 {
  close(serial::fd);
  serial::loadedFile = false;
 }
 pthread_mutex_unlock(&serial::serialMutex);
}

//std::vector<char> data;

writer::writer(): serial(writer::Write, this)
{
 std::cout << " writer" << std::endl;
}
void* writer::Write(void* args)
{
 pthread_exit(NULL);
}

std::istream& operator >>(std::istream& stream, writer& rhs)
{
 return stream;
}

//std::vector<std::string> data;

reader::reader(): serial(reader::Read, this)
{
 std::cout << " reader" << std::endl;
}

void* reader::Read(void* args)
{
 pthread_exit(NULL);
}

std::ostream& operator <<(std::ostream& stream, reader& rhs)
{
 return stream;
}
