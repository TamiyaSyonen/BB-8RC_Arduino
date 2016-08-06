#include <SoftwareSerial.h>
SoftwareSerial BT(11,10);
void setup()
{
  BT.begin(9600);
}
char a;
void loop()
{
  if (BT.available()) {
    a = (BT.read());
    if (a == '1') {
      Serial.println("HELLO &lt;Bluetooth&gt; WORLD!");
    }
    if (a == '2') {
      Serial.println("2 is comming.");
    }
  }
}
