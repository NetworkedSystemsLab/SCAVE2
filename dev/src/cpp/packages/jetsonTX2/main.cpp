#include "jetsonTX2.h"

int main(int argc, char** argv)
{
 GPIO* pins[14];
 pins[0] = new GPIO(pin7);
 pins[1] = new GPIO(pin11);
 pins[2] = new GPIO(pin13);
 pins[3] = new GPIO(pin15);
 pins[4] = new GPIO(pin18);
 pins[5] = new GPIO(pin19);
 pins[6] = new GPIO(pin21);
 pins[7] = new GPIO(pin22);
 pins[8] = new GPIO(pin23);
 pins[9] = new GPIO(pin24);
 pins[10] = new GPIO(pin29);
 pins[11] = new GPIO(pin31);
 pins[12] = new GPIO(pin33);
 pins[13] = new GPIO(pin37);

 
 return 0;
}
