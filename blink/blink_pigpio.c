#include <signal.h>
#include <stdio.h>
#include <pigpio.h>
const int RedLED = 21;

uint * x,k;

volatile sig_atomic_t signal_received = 0;
void del(uint * jj) {
	uint y,z;

	z=*jj;
	//printf("%d\n",z);
	for(y=0;y<z;y++) {
	}
}


void sigint_handler(int signal) {
   signal_received = signal;
}

int main() {
	k = 10;
    x = &k;
   if (gpioInitialise() == PI_INIT_FAILED) {
      printf("ERROR: Failed to initialize the GPIO interface.\n");
      return 1;
   }
   gpioSetMode(RedLED, PI_OUTPUT);
   signal(SIGINT, sigint_handler);
   printf("Press CTRL-C to exit.\n");
   while (!signal_received) {
      gpioWrite(RedLED, PI_HIGH);
      //time_sleep(1);
	  del(x);	
      gpioWrite(RedLED, PI_LOW);
      //time_sleep(1);
	  del(x);
   }
   gpioSetMode(RedLED, PI_INPUT);
   gpioTerminate();
   printf("\n");
   return 0;
}