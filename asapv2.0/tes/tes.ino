const int a = A0;
const int ab = A1;
const int cd = A2;
const int ef = A3;
int b = 0;
int bc = 0;
int de = 0;
int fg = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  Serial.print("mq2 : ");
  b = analogRead (a);
  Serial.println (b);
  Serial.print("mq7 : ");
  bc = analogRead (ab);
  Serial.println (bc);
  Serial.print("mq2in : ");
  de = analogRead (cd);
  Serial.println (de);
  Serial.print("mq7in : ");
  fg = analogRead (ef);
  Serial.println (fg);
  
  delay (1000);
  // put your main code here, to run repeatedly:

}
