//#include "CmmcMonoLedMartix.h"
#include "CmmcMonoLedMartix.h" 

//byte ledBitmap[8] = {
//  B00000000,
//  B11111100,
//  B01110010,
//  B11110011,
//  B01111111,
//  B11110011,
//  B01110010,
//  B11111100
//};

int data[8] = {0,252,114,243,127,243,114,252};

CmmcMonoLedMartix ledX;

void setup() {
  // put your setup code here, to run once:
  ledX.begin(0x20);
}

void loop() {
  // put your main code here, to run repeatedly:
  ledX.showPic8bit(data);
}
