#include<Servo.h>

Servo servo;

int servoPin = 2;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++) {
    servo.write(90);
    delay(1000);
    servo.write(180);
    delay(1000);
    servo.write(0);
  }
}
