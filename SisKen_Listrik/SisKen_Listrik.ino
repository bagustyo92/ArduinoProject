#include <PID_v1.h>

double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;
PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

const int MQ2InPin = A2;
const int MQ2OutPin = A3;
const int ledPin = 13;
const int fanPin = 9;

int fanValue = 0;
int in2Value = 0;
int out2Value = 0;
int sensorFan = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Input = map(analogRead(MQ2InPin), 0, 1023, 255, 0);
  Setpoint = 200;
  myPID.SetOutputLimits(0, 255);
  //turn the PID ON
  myPID.SetMode(AUTOMATIC);
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
    analogWrite(fanPin, 0);
    digitalWrite(ledPin, LOW);
  }

  //Deteksi Voltage
  fanValue = analogRead (fanPin);
  fanValue = fanValue * 5;
  Serial.println (fanValue);         
}
