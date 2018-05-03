#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
LiquidCrystal_I2C lcd(0x27, 20, 4);

const int SW_PIN = 7;
const int X_PIN = 0;
const int Y_PIN = 1;

const int green_LED = 6;
const int red_LED = 5;

const int trigPin = 4;
const int echoPin = 3;

long duration;
int distance;
int servoAngle;

Servo servo;

void servo_left(){
  for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);
//    sensor();              
    delay(10);                  
  }
}

void servo_right(){
  for(servoAngle = 180; servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
  {                                
    servo.write(servoAngle);
//    sensor();        
    delay(10);      
  }
}

void start() {
  digitalWrite(green_LED, LOW);
  digitalWrite(red_LED, LOW);
}

void sensor() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 50 || distance > 1000) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(green_LED, HIGH);
      delay(200);
      digitalWrite(green_LED, LOW);
      delay(200);
      digitalWrite(green_LED, HIGH);
      delay(200);
      digitalWrite(green_LED, LOW);
    }
  } else {
    digitalWrite(red_LED, HIGH);
    delay(100);
    digitalWrite(red_LED, LOW);
    delay(100);
  }
}

void joystick() {
  Serial.println("X-Axis : ");
  Serial.println(analogRead(X_PIN));
  Serial.println("Y-Axis : ");
  Serial.println(analogRead(Y_PIN));
  if (analogRead(X_PIN) < 20) {
    servo_left();
//    delay(1000);
  } else if (analogRead(X_PIN) > 800) {
    servo_right();
//    servo.write(180);
//    delay(1000);
  } else {
//    servo.write(0);
  }
}

void setup() {
  //init sensor
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);

  //init joystick
  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);

  //init servo
  servo.attach(2); //pin 0
  servo.write(0); //start position

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  start();
  Serial.println();
}

void loop() {


  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    //Print the UID
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    //Store the UID to the content variable
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "08 28 B4 79") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(green_LED, HIGH);
    digitalWrite(red_LED, LOW);
    Serial.println("Authorized access");
    //    lcd.clear();
    //    lcd.setCursor(0,0);
    //    lcd.print("Authorized access");
    Serial.println();
    //    servo.write(180);
    //    delay(3000);
    //    servo.write(0);
    //    lcd.clear();
    //    lcd.setCursor(0,0);
    //    lcd.print("SUKSES");
    //    lcd.setCursor(0,1);
    //    lcd.print("AMBIL DUIT");
    Serial.println("gerakan servo");
    delay(1000);
    joystick();
    sensor();
    start();
  }

  else   {
    digitalWrite(green_LED, LOW);
    digitalWrite(red_LED, HIGH);
    //    lcd.clear();
    //    lcd.setCursor(0,0);
    //    lcd.print("Access denied");
    Serial.println("Access denied");
    delay(2000);
    start();
  }
}

