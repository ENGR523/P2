// EXAMPLE USAGE

#include "application.h"
#include "wave.h"

// iot.lukefahr.org
IPAddress remoteIp (18, 218, 51, 247 );
uint32_t remote_port = 10001;

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

	//max sendPacket length is 1024 bytes 
    // or 256 4-byte floats
	const int MAX_PACKET_SIZE = 256;
	int j; 
	for (int i = 0; i < WAVE_LENGTH; i += MAX_PACKET_SIZE){
		j = ( i + MAX_PACKET_SIZE < WAVE_LENGTH ? i + MAX_PACKET_SIZE : WAVE_LENGTH);

		udp.sendPacket( (const char *) &WAVE_DATA[i], sizeof(float) * (j-i), 
					remoteIp, remote_port);
	} 

	delay(10000); //10 second delay

}
