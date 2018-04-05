#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <BH1750.h>

Adafruit_BMP280 bmp; // I2C
BH1750 lightMeter;// I2C

byte sensorInterrupt = 0;  // 0 = digital pin 2
byte sensorPin       = 2;
float calibrationFactor = 4.5;
volatile byte pulseCount;
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;


void pulseCounter();
void setup() {
  Serial.begin(9600);
  //Serial.println(F("BMP280 test"));
  lightMeter.begin();
  //Serial.println(F("BH1750 Test"));
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}

void loop() {
  uint16_t lux = lightMeter.readLightLevel(); 
  //Water Flow
  if ((millis() - oldTime) > 1000)     {
    detachInterrupt(sensorInterrupt);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;
    unsigned int frac;
    pulseCount = 0;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
  String data = "{\"temp\": " + String(bmp.readTemperature()) + ", \"light\": " + String(lux) + ",  \"water\": " + String(totalMilliLitres) + "}";
  Serial.println(data);
  delay(2000);
}


void pulseCounter(){  
  pulseCount++;
}


















//  root["temp"] = bmp.readTemperature();
//  root["light"] = lux;
//  root["water"] = totalMilliLitres;
//  root.prettyPrintTo(Serial);
//    Serial.println(String (bmp.readTemperature()) + "," + String(lux)+ "," + String(totalMilliLitres));
//    delay(1000);

