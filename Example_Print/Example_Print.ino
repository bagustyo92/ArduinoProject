void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Mencetak Sekali");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Mencetak berkali kali");
  delay(1000);
}
