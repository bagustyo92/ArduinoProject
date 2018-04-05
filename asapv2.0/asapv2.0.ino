const int MQ2InPin = A2;
const int MQ2OutPin = A3;
const int MQ7InPin = A1;
const int MQ7OutPin = A4;
const int tempPin = A0;
const int ledPin = 13;
const int fanPin = 9;

float temp;
int in2Value = 0;
int out2Value = 0;
int in7Value = 0;
int out7Value = 0;
int sensorFan = 0;
int maxSense = 100;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT); 
}

void loop() {
  in2Value = analogRead(MQ2InPin);  
  out2Value = analogRead(MQ2OutPin);
  Serial.print("In : ");
  Serial.println(in2Value);   
  Serial.print("Out : ");           
  Serial.println(out2Value);
  Serial.println(" ");   
  

  if (in2Value >= 200 || in2Value <= 340) {
    //PWMValue
    analogWrite(fanPin, 85);
    //LED
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    
  } else if (in2Value > 340 || in2Value <= 680){
    //PWMValue
    analogWrite(fanPin, 170);
    //LED
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  } else if (in2Value > 680) {
    //PWMValue
    analogWrite(fanPin, 255);
    //LED
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(fanPin, LOW);
    //PWMValue
  }

  //Deteksi Voltage
  fanValue = analogRead (fanPin);
  fanValue = fanValue * 5;
  Serial.println (fanValue);
  
  sensorFan = digitalRead(fanPin);
  Serial.println(sensorFan);            
}
