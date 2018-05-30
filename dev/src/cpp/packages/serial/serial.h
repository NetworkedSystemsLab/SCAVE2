#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "../common/common.h"

class serial
{
public:
static pthread_mutex_t serialMutex;
static int fd;
static bool loadedFile;

pthread_t thread;
speed_t baudrate;
std::string port;
struct termios settings;

serial(void* (*func)(void*), void* args);
~serial();
};

class writer: public serial
{
public:
std::vector<char> data;

writer();

static void* Write(void* args);

friend std::istream& operator >>(std::istream& stream, writer& rhs);
};

class reader: public serial
{
public:
std::vector<std::string> data;

reader();

static void* Read(void* args);

friend std::ostream& operator <<(std::ostream& stream, reader& rhs);
};

#endif
