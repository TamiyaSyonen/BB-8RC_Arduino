/*BB-8RC BluetoothVersion Arduino Sketch
 * Only Serial test.
 */

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
  char *data;
  char *output[20];
  int avail = bdSerial.available();
  if(avail>0){
    while(avail>0){
      *data<<bdSerial.read();
    }
  }
  Serial.println(*data);
  split(*data,',',*output);
  
Serial.println("-"+Xstring);
 delay(1000);
}
int split( char *str, const char *delim, char *outlist[] ) {
    char    *tk;
    int     cnt = 0;

    tk = strtok( str, delim );
    while( tk != NULL && cnt < MAXITEM ) {
        outlist[cnt++] = tk;
        tk = strtok( NULL, delim );
    }
    return cnt;
}
