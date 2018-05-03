/*
    Created by TheCircuit
*/

#define SS_PIN 10  //D2
#define RST_PIN 13 //D1

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
#define LED1 5  //D2
#define LED2 4 //D1
#define LED3 3 //D1

int pos = 0; 
int statuss = 0;
int out = 0;


void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myservo.attach(6);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, 1);
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content = "";
  byte letter;
  
  
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "08 28 B4 79") //change UID of the card that you want to give access
  {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 1);
    Serial.println(" Access Granted ");
    Serial.println(" You can take any money ");
    Serial.println(" in 5 second "); 
    delay(1000);
    Serial.println();
    servo();
    digitalWrite(LED2, 0);
    statuss = 1;
  }

  else   {
    Serial.println(" Access Denied ");
    digitalWrite(LED1, 0);
    digitalWrite(LED3, 1);
    delay(2000);
    tone(2, 200,  1000);
    digitalWrite(LED3, 0);
    delay(3000);
  }
}

void servo(){
  for (pos = 0; pos <= 180; pos += 1) { 
      // in steps of 1 degree
      myservo.write(pos);              
      delay(5);                       
    }
    delay(5000);
    for (pos = 180; pos >= 0; pos -= 1) { 
      myservo.write(pos);              
      delay(5);                       
    }
    return;
  }
