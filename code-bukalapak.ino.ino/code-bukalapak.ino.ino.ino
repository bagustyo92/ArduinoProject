#define SS_PIN 10 
#define RST_PIN 13 

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);  
Servo myservo;  
#define LED1 5  
#define LED2 4 
#define LED3 3 

int pos = 0; 
int statuss = 0;
int out = 0;


void setup()
{
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init(); 
  myservo.attach(6);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, 1);
  
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
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
  
  if (content.substring(1) == "08 28 B4 79")
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
    delay(1000);
    digitalWrite(LED3, 0);
    for (int a = 0; a<=10; a++){
    tone(2, 200,  100);
    delay(300);
    }
  }
}

void servo(){
  for (pos = 0; pos <= 180; pos += 1) { 
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
