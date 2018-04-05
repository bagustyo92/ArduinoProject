const int MQ2InPin = A2;
const int MQ2OutPin = A3;
const int MQ7InPin = A1;
const int MQ7OutPin = A4;
const int tempPin = A0;
const int ledPin = 13;
const int fanPin = 12;

float temp;
int in2Value = 0;
int out2Value = 0;
int in7Value = 0;
int out7Value = 0;
int sensorFan = 0;
int maxSense = 300;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
}

void loop() {

  temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  //Serial.print("TEMPRATURE = ");
  //Serial.print(temp-15);
  //Serial.print("*C");
  //Serial.println(temp-15);

//  if(out2Value > in2Value){
//    Serial.println("Overlap!");
//    Serial.println(" ");
//  } else {
//    Serial.println(" "); 
//  }

  //Serial.println("***MQ2 HERE***");   
  in2Value = analogRead(MQ2InPin);  
  out2Value = analogRead(MQ2OutPin);
  //Serial.print("In : ");
  Serial.println(in2Value);   
  //Serial.print("Out : ");           
  Serial.println(out2Value);
  //Serial.println(" ");   
  
  //Serial.println("***MQ7 HERE***");
  in7Value = analogRead(MQ7InPin);  
  out7Value = analogRead(MQ7OutPin);
  //Serial.print("In : ");
  Serial.println(in7Value);   
  //Serial.print("Out : ");           
  Serial.println(out7Value);
  
  if (in7Value >= maxSense || in2Value >= maxSense) {
    digitalWrite(fanPin, HIGH);
  } else {
    digitalWrite(fanPin, LOW);
  }
  sensorFan = digitalRead(fanPin);
  Serial.println(sensorFan);
  //Serial.println(" ");
  
  if (out7Value >= maxSense || out2Value >= maxSense) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(1000);                   
}
