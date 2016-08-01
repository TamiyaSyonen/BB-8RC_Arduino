//v0.1
#include <SoftwareSerial.h>

//BB-8  Bluetooth version
#include <stdlib.h>

int txPin = 10;
int rxPin = 11;

SoftwareSerial bdSerial(rxPin,txPin);

bool availFrag = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  pinMode(13,OUTPUT);

  bdSerial.begin(9600);
  Serial.begin(115200);
  Serial.println("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (bdSerial.available()>0){
        //Serial.write(bdSerial.read());
        char data =bdSerial.read();
         if(data == 'a'){
          digitalWrite(13,HIGH);
         }else if(data == 'b'){
          digitalWrite(13,LOW);
         }
        availFrag = true;
  }else if(availFrag){
   // Serial.print("end");
    availFrag = false;
  }

 
}
