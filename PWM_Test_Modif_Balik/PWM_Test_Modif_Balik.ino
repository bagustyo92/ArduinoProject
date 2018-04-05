int val = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);
  analogWrite(9, 255 - val/4);
  Serial.print("PWM Value =");
  Serial.println(val, DEC);
  delay(500);
}
