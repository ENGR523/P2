// EXAMPLE USAGE

#include "application.h"
#include "wave.h"

// FIXME
IPAddress remoteIp (0,0,0,0);
uint32_t remote_port = 0;

UDP udp;

void setup() {

  Serial.begin(9600);

  // wait up to 10 seconds for USB host to connect
  // requires firmware >= 0.5.3
  //waitFor(Serial.isConnected, 10000);
  Serial.printf("Connected\n");

  //Needs to be here for UDP to work correctly
  udp.begin(8888);

}

void loop(){

	Serial.printf("Sending Data\n"); 
	
  	if( WAVE_SAMPLE_RATE != 16000)
		Serial.printf("Warning:  Incorrect sampling rate!\n");

	//FIXME:  your code here! 

	delay(10000); //10 second delay

}
