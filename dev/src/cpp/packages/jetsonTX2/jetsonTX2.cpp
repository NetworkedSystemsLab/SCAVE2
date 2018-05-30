// jetsonGPIO.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include "jetsonTX2.h"

GPIO::GPIO(jetsonGPIO pin, pinDirection dir)
{
 this->pin = pin;
 this->Export();
 this->SetDirection(dir);
}
GPIO::~GPIO()
{
 this->Unexport();
}
//
// gpioExport
// Export the given gpio to userspace;
// Return: Success = 0 ; otherwise open file error
int GPIO::Export ()
{

    
    

    int fileDescriptor, length;
    char commandBuffer[MAX_BUF];
    fileDescriptor = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioExport unable to open gpio%d",pin) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    length = snprintf(commandBuffer, sizeof(commandBuffer), "%d", pin);
    if (write(fileDescriptor, commandBuffer, length) != length) {
        perror("gpioExport");
        return fileDescriptor ;

    }
    close(fileDescriptor);
    return 0;
}

//
// gpioUnexport
// Unexport the given gpio from userspace
// Return: Success = 0 ; otherwise open file error
int GPIO::Unexport ()
{

    
    

    int fileDescriptor, length;
    char commandBuffer[MAX_BUF];

    fileDescriptor = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioUnexport unable to open gpio%d",pin) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    length = snprintf(commandBuffer, sizeof(commandBuffer), "%d", pin);
    if (write(fileDescriptor, commandBuffer, length) != length) {
        perror("gpioUnexport") ;
        return fileDescriptor ;
    }
    close(fileDescriptor);
    return 0;
}

// gpioSetDirection
// Set the direction of the GPIO pin 
// Return: Success = 0 ; otherwise open file error
int GPIO::SetDirection ( unsigned int out_flag )
{

    
    

    int fileDescriptor;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_GPIO_DIR  "/gpio%d/direction", pin);

    fileDescriptor = open(commandBuffer, O_WRONLY);
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioSetDirection unable to open gpio%d",pin) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    if (out_flag) {
        if (write(fileDescriptor, "out", 4) != 4) {
            perror("gpioSetDirection") ;
            return fileDescriptor ;
        }
    }
    else {
        if (write(fileDescriptor, "in", 3) != 3) {
            perror("gpioSetDirection") ;
            return fileDescriptor ;
        }
    }
    close(fileDescriptor);
    return 0;
}

//
// gpioSetValue
// Set the value of the GPIO pin to 1 or 0
// Return: Success = 0 ; otherwise open file error
int GPIO::SetValue ( unsigned int value )
{

    
    

    int fileDescriptor;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_GPIO_DIR "/gpio%d/value", pin);

    fileDescriptor = open(commandBuffer, O_WRONLY);
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioSetValue unable to open gpio%d",pin) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    if (value) {
        if (write(fileDescriptor, "1", 2) != 2) {
            perror("gpioSetValue") ;
            return fileDescriptor ;
        }
    }
    else {
        if (write(fileDescriptor, "0", 2) != 2) {
            perror("gpioSetValue") ;
            return fileDescriptor ;
        }
    }
    close(fileDescriptor);
    return 0;
}

//
// gpioGetValue
// Get the value of the requested GPIO pin ; value return is 0 or 1
// Return: Success = 0 ; otherwise open file error
int GPIO::GetValue ( unsigned int *value)
{

    
    

    int fileDescriptor;
    char commandBuffer[MAX_BUF];
    char ch;

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_GPIO_DIR "/gpio%d/value", pin);

    fileDescriptor = open(commandBuffer, O_RDONLY);
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioGetValue unable to open gpio%d",pin) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    if (read(fileDescriptor, &ch, 1) != 1) {
        perror("gpioGetValue") ;
        return fileDescriptor ;
     }

    if (ch != '0') {
        *value = 1;
    } else {
        *value = 0;
    }

    close(fileDescriptor);
    return 0;
}


//
// gpioSetEdge
// Set the edge of the GPIO pin
// Valid edges: 'none' 'rising' 'falling' 'both'
// Return: Success = 0 ; otherwise open file error
int GPIO::SetEdge ( char *edge )
{

    
    

    int fileDescriptor;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_GPIO_DIR "/gpio%d/edge", pin);

    fileDescriptor = open(commandBuffer, O_WRONLY);
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioSetEdge unable to open gpio%d",pin) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    if (write(fileDescriptor, edge, strlen(edge) + 1) != ((int)(strlen(edge) + 1))) {
        perror("gpioSetEdge") ;
        return fileDescriptor ;
    }
    close(fileDescriptor);
    return 0;
}

//
// gpioOpen
// Open the given pin for reading
// Returns the file descriptor of the named pin
int GPIO::Open()
{

    int fileDescriptor;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_GPIO_DIR "/gpio%d/value", pin);

    fileDescriptor = open(commandBuffer, O_RDONLY | O_NONBLOCK );
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioOpen unable to open gpio%d",pin) ;
        perror(errorBuffer);
    }
    return fileDescriptor;
}

//
// gpioClose
// Close the given file descriptor 
int GPIO::Close ( int fileDescriptor )
{

    return close(fileDescriptor);
}

// gpioActiveLow
// Set the active_low attribute of the GPIO pin to 1 or 0
// Return: Success = 0 ; otherwise open file error
int GPIO::ActiveLow ( unsigned int value )
{


    int fileDescriptor;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_GPIO_DIR "/gpio%d/active_low", pin);

    fileDescriptor = open(commandBuffer, O_WRONLY);
    if (fileDescriptor < 0) {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "gpioActiveLow unable to open gpio%d",pin) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    if (value) {
        if (write(fileDescriptor, "1", 2) != 2) {
            perror("gpioActiveLow") ;
            return fileDescriptor ;
        }
    }
    else {
        if (write(fileDescriptor, "0", 2) != 2) {
            perror("gpioActiveLow") ;
            return fileDescriptor ;
        }
    }
    close(fileDescriptor);
    return 0;
}

