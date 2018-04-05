int potensio = 0;
float volt;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potensio = analogRead(0);
  volt = potensio * (5.0/1023.0);
  Serial.println(volt);
  delay(1000);
}
