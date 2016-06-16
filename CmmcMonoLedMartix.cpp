#include <Wire.h>

#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif

#include "CmmcMonoLedMartix.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

CmmcMonoLedMartix::CmmcMonoLedMartix(){
	
}

void CmmcMonoLedMartix::begin(int addr){
  addI2c = addr;
  Wire.begin();// wake up I2C bus
  Wire.setClock(1700000);
  Wire.beginTransmission(addI2c); // Connect to chip
  Wire.write((byte)0x01);       // Select Bank B
  Wire.write((byte)0x00);       // Set all of bank B to outputs
  Wire.endTransmission();       // Close connection

  //Wire.begin();                 // wake up I2C bus
  Wire.beginTransmission(addI2c); // Connect to chip
  Wire.write((byte)0x00);       // Select Bank A
  Wire.write((byte)0x00);       // Set all of bank B to outputs
  Wire.endTransmission();       // Close connection

}

void CmmcMonoLedMartix::showPic8bit(int dataPic[8]){
	//if (millis() - time_prev_control >= 2) {
		//time_prev_control = millis();
		 //do led
		 //coL
		 Wire.beginTransmission(addI2c);  // Connect to chip
		 Wire.write(0x12);              // Set Memory Pointer to Bank A
         Wire.write(byte(colList[countArray]));                 // Write the Byte
         Wire.endTransmission();        // Close connection
		
		 //roW
		 Wire.beginTransmission(addI2c);  // Connect to chip
         Wire.write(0x13);              // Set Memory Pointer to Bank B
         Wire.write(byte(dataPic[countArray]));                 // Write the Byte
         Wire.endTransmission();        // Close connection
		 delayMicroseconds(500);
		 //
		 //close roW and coL prevent bug
		 Wire.beginTransmission(addI2c);  // Connect to chip
         Wire.write(0x13);              // Set Memory Pointer to Bank B
         Wire.write(0);                 // Write the Byte
         Wire.endTransmission();        // Close connection

         Wire.beginTransmission(addI2c);  // Connect to chip
         Wire.write(0x12);              // Set Memory Pointer to Bank A
         Wire.write(0);                 // Write the Byte
         Wire.endTransmission();        // Close connection
		
		 countArray++;
		 if(countArray>7){
			 countArray = 0;
		 }
//}

}