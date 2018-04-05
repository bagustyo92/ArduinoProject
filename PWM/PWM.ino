int val = 0;
//int valMax = 255;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);
  //chalenge1
  //analogWrite(9, valMax - val/4));
  
  Serial.print ("PWM Value = ");
  Serial.println(val,DEC);
  delay (300);

  //chalange2
  if (val%2 == 0){
    analogWrite(9, 255);
    delay(1000);
  } else {
    analogWrite(9, 0);
    delay(1000);
  }
}
