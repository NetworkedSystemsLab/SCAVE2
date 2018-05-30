#ifndef __JETSONGPIO_H__
#define __JETSONGPIO_H__

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOT (3 * 1000)
#define MAX_BUF 64

typedef unsigned int jetsonGPIO;
typedef unsigned int pinDirection;
typedef unsigned int pinValue;

enum pinDirections{
 inputPin=0,
 outputPin=1,
 in=0,
 out=1
};
enum pinValues{
 low=0,
 high=1,
 off=0,
 on=1
};

enum TX2pin
{
  //pin1        3.3v
  //pin2        5v
  //pin4        5v
  //pin6        GND
  pin7 = 396,   //GPIO                  //trig 0
  //pin9        GND
  pin11 = 466,  //UART0 RTS             //captain
  pin13 = 397,  //GPIO                  //tachometer
  //pin14       GND
  pin15 = 255,  //GPIO                  //echo 0
  //pin17       3.3v
  pin18 = 481,  //GPIO                  //trig 1
  pin19 = 429,  //SPI_MOSI              //echo 3
  //pin20       GND
  pin21 = 428,  //SPI_MISO              //trig 3
  pin22 = 254,  //GPIO                  //echo 1
  pin23 = 427,  //SPI_CLK
  pin24 = 430,  //SPI_ChipSelect #0
  //pin25       GND
  pin29 = 398,  //GPIO                  //trig 2
  //pin30       GND
  pin31 = 298,  //GPIO                  //echo 2
  pin33 = 389,  //GPIO                  //emergency pin
  //pin34       GND
  pin37 = 388   //GPIO                  //tone pin
  //pin39	GND
};

class GPIO
{
public:
jetsonGPIO pin;

GPIO(jetsonGPIO pin, pinDirection dir=in);
~GPIO();

int Export();
int Unexport();
int SetDirection(pinDirection out_flag);
int SetValue(pinValue value);
int GetValue(unsigned int* value);
int SetEdge(char* edge);
int Open();
int Close(int fd);
int ActiveLow(unsigned int value);
};
#endif
