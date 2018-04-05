int nilai = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai = analogRead(A0);
  //digitalWrite(13, nilai);
  analogWrite(9, nilai/4);
  Serial.print("PWM Value = ");
  Serial.println(nilai, DEC);
}
