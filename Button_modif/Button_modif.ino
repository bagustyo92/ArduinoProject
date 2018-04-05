int potensio = 0;
float volt;
void setup(){
  Serial.begin(9600);
  pinMode (8, OUTPUT);
}

void loop(){
  potensio = analogRead(0);
  volt = potensio * (5.0/1023.0);
  Serial.println("Nilai Potensio : ");
  Serial.println(volt);
  if (volt >= 1 && volt < 4){
    digitalWrite (8, HIGH);
    Serial.println ("LAMPU ON");
    delay(1000);
  }else if (volt >= 4){
    for (int i=0; i<5; i++){
      digitalWrite (8, LOW);
      delay (300);
      digitalWrite (8, HIGH);
      delay (300);
      Serial.println("DANGER!!");
      } 
    } else {
      digitalWrite (8, LOW);
      Serial.println ("LAMPU OFF");
      delay(1000);
    }
}
