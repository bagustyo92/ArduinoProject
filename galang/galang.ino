#include <dht.h> 
dht DHT; 
//Constants 
#define DHT22_PIN 7     // DHT 22  (AM2302) - what pin we're connected to 

//Variables 
float hum;  //Stores humidity value 
float temp; //Stores temperature value 

const int MQ7InPin = A2;  
const int MQ135InPin = A0;  
const int MQ2InPin =A1;  
const int led = 6;  

int MQ7 = 0;  
int MQ135 = 0;  
int MQ2 = 0;  
int DHT22 = 0; 

void setup() 
{ 
    Serial.begin(9600); 
} 

void loop() 
{ 
    int chk = DHT.read22(DHT22_PIN); 
    //Read data and store it to variables hum and temp 
    hum = DHT.humidity; 
    temp= DHT.temperature; 
    //Print temp and humidity values to serial monitor 
    //Serial.print("Humidity: "); 
    //Serial.print(hum); 
    Serial.print(" %, Temp: "); 
    Serial.print(temp); 
    Serial.println(" Celsius"); 

     digitalWrite (led , HIGH);  
  MQ7 = analogRead(MQ7InPin);  
  Serial.print("CO : ");  
  Serial.println(MQ7);  
    
  MQ135 = analogRead(MQ135InPin);  
  Serial.print("CO2 : ");  
  Serial.println(MQ135);  
    
  MQ2 = analogRead(MQ2InPin);  
  Serial.print("H : ");  
  Serial.println(MQ2); 
  Serial.println(" "); 
     
  if (MQ2>235 || MQ7>235||MQ135>235){ 
    analogWrite(led, 255); 
    delay (200); 
    analogWrite(led,0); 
  } 
  else { 
    analogWrite(led,0); 
  } 

  delay(1000); //Delay 2 sec. 
     
}
