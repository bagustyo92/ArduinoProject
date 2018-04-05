const int gas = A0;
int sensorValue = 0;
int LedMerah = 11;
int LedHijau = 12;
int buzzer = 8;
int kipas = 9;
char psd[256];
int counter = 1;
int lamabocor = 1;
char kondisi;
String pil;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LedMerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(kipas, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  system ("sqlite3 -csv -header /home/root/lpg.db 'create table bocor(kadar integer, lamabocor integer, kondisi varchar(20));' &> /dev/ttyGS0 ");
}

void loop() {
  Serial.println("Masukkan menu pilihan :");
  Serial.println("1. Baca Kadar Gas");
  Serial.println("2. Lama Kebocoran Gas");
  while (!Serial.available());
  pil = Serial.readString();
  Serial.println(pil);
  delay(1000);
  if (pil == "1") {
    lamabocor = 0;
    while (true) {
      sensorValue = analogRead(gas);
      if (sensorValue >= 90 && sensorValue <= 150) {
        digitalWrite(LedHijau, LOW);
        digitalWrite(kipas, HIGH);
        digitalWrite(LedMerah, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(800);
        digitalWrite(LedMerah, LOW);
        digitalWrite(buzzer, LOW);
        delay(800);
        kondisi = '1';
        lamabocor++;
      } else if (sensorValue > 150) {
        digitalWrite(LedHijau, LOW);
        digitalWrite(kipas, HIGH);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LedMerah, HIGH);
        delay(300);
        digitalWrite(LedMerah, LOW);
        digitalWrite(buzzer, LOW);
        delay(300);
        kondisi = '2';
        lamabocor++;
      } else {
        break;
        digitalWrite(LedHijau, HIGH);
        digitalWrite(kipas, LOW);
        digitalWrite(buzzer, LOW);
        delay(1000);
        kondisi = '0';
        lamabocor = 0;
      }
      Serial.println(sensorValue);
    }
    //Serial.println(sensorValue);
    delay(1000);
    system("sqlite3 -csv /home/root/lpg.db 'select kadar from bocor;' &> /dev/ttyGS0 ");
  } else if (pil == "2") {
    Serial.print("Lama Bocor = ");
    Serial.print(lamabocor);
    Serial.println(" detik");
    Serial.println();
  }
  sprintf(psd, "sqlite3 -csv -header /home/root/lpg.db 'INSERT INTO bocor VALUES(\"%d\",\"%d\",\"%c\");' &> /dev/ttyGS0 ", sensorValue, lamabocor, kondisi);
  system(psd);
  //system("sqlite3 -csv /home/root/lpg.db 'select kadar from bocor;' &> /dev/ttyGS0 ");
}
