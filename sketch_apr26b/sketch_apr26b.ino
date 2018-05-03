const int SW_PIN = 7;
const int X_PIN = 0;
const int Y_PIN = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Switch : ");
  Serial.println(digitalRead(SW_PIN));
  Serial.println("X-Axis : ");
  Serial.println(analogRead(X_PIN));
  Serial.println("Y-Axis : ");
  Serial.println(analogRead(Y_PIN));
  delay(1000);
}
