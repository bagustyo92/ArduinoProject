const int MQ7InPin = A3; 
const int MQ135InPin = A0; 
const int MQ2InPin =A2; 
const int led = 7; 
const int DHT22InPin = A4; 

int MQ7 = 0; 
int MQ135 = 0; 
int MQ2 = 0; 
int DHT22 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  MQ7 = analogRead(MQ7InPin); 
  Serial.print("MQ7 : "); 
  Serial.println(MQ7); 
   
  MQ135 = analogRead(MQ135InPin); 
  Serial.print("MQ135 : "); 
  Serial.println(MQ135); 
   
  MQ2 = analogRead(MQ2InPin); 
  Serial.print("MQ2 : "); 
  Serial.println(MQ2);
  Serial.println(" ");
  delay(1000); //Delay 2 sec.
}
