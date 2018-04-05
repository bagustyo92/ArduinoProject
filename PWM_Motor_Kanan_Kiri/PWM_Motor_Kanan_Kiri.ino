int val = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);
  Serial.print("PWM Value =");
  Serial.println(val, DEC);
  delay(500);

  if(val < 450){
    analogWrite(9, 0);
    analogWrite(6 , 255);
  } else if(val > 550){
    analogWrite(9, 255);
    analogWrite(6 , 0);
  } else {
    analogWrite(9, 0);
  }
}
