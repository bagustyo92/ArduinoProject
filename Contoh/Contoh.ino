#include <Boards.h>
#include <Firmata.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int mq;
  mq = analogRead(A0);
  Serial.print("Data : ");
  Serial.println(mq);
  delay(1000);
}
