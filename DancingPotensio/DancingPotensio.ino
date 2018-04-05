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
  
  if (volt >= 1 && volt < 2){
    for (int i=0; i<5; i++){
      digitalWrite (8, LOW);
      delay (1000);
      digitalWrite (8, HIGH);
      delay (1000);
      } 
  } else if (volt >=2 && volt < 3){
    for (int i=0; i<5; i++){
      digitalWrite (8, LOW);
      delay (300);
      digitalWrite (8, HIGH);
      delay (300);
      }
    } else if (volt >= 3){
      digitalWrite (8, HIGH);
    } else {
      digitalWrite (8, LOW);
    }
}
