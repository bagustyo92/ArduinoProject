const int sensor = A0;
int valSensor = 0;
int count = 0;
int hari = 1;
char psd[256];
String pil;
char menu[10];
char menu2[10];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  system ("sqlite3 -csv -header /home/root/praktikumTerakhir.db 'create table project (hari varchar(20), sensor integer);' &> /dev/ttyGS0 ");
  pinMode(sensor, INPUT);
}

void loop() {
  count = count + 1;
  valSensor = analogRead(sensor);

  
  Serial.print("Data Sensor Hari ke-");
  Serial.print(hari);
  Serial.print(" Jam ke-");
  Serial.print(count);
  Serial.print(" :");
  Serial.println(valSensor);
  //delay(500);

  if (hari == 1){
    sprintf(psd, "sqlite3 -csv -header /home/root/praktikumTerakhir.db 'INSERT INTO project VALUES(\"SENIN\", \"%d\");' &> /dev/ttyGS0 ", valSensor);
    system (psd);
  } else if (hari == 2){
    sprintf(psd, "sqlite3 -csv -header /home/root/praktikumTerakhir.db 'INSERT INTO project VALUES(\"SELASA\", \"%d\");' &> /dev/ttyGS0 ", valSensor);
    system (psd);
  } else if (hari == 3){
   sprintf(psd, "sqlite3 -csv -header /home/root/praktikumTerakhir.db 'INSERT INTO project VALUES(\"RABU\", \"%d\");' &> /dev/ttyGS0 ", valSensor);
   system (psd);
  } else if (hari == 4){
   sprintf(psd, "sqlite3 -csv -header /home/root/praktikumTerakhir.db 'INSERT INTO project VALUES(\"KAMIS\", \"%d\");' &> /dev/ttyGS0 ", valSensor);
   system (psd);
  } else if (hari == 5){
    sprintf(psd, "sqlite3 -csv -header /home/root/praktikumTerakhir.db 'INSERT INTO project VALUES(\"JUMAT\", \"%d\");' &> /dev/ttyGS0 ", valSensor);
    system (psd);
  } else if (hari == 6){
    sprintf(psd, "sqlite3 -csv -header /home/root/praktikumTerakhir.db 'INSERT INTO project VALUES(\"SABTU\", \"%d\");' &> /dev/ttyGS0 ", valSensor);
    system (psd);
  } else {
    sprintf(psd, "sqlite3 -csv -header /home/root/praktikumTerakhir.db 'INSERT INTO project VALUES(\"MINGGU\", \"%d\");' &> /dev/ttyGS0 ", valSensor);
    system (psd);
  }
  
  if (count == 24)
  {
    count = 0;
    hari++;
    if (hari == 8){
      Serial.println("Seluruh data sensor telah di rekam selama 1 minggu penuh");
      Serial.println("Apakah anda mau melihat data? [y/n]");
      while (!Serial.available());
      pil = Serial.readString();
      Serial.println(pil);
      delay(1000);
      hari = 0;
      if(pil == "y"){
        Serial.println("1. Tampilkan Data Semua hari");
        Serial.println("2. Tampilkan Nilai Rata-Rata Data Sensor 1 Minggu");
        Serial.println("3. Tampilkan Nilai Tertinggi Data Sensor 1 Minggu");
        Serial.println("4. Tampilkan Nilai Terendah Data Sensor 1 Minggu");
        Serial.println("5. Tampilkan Nilai per-hari");
        while (!Serial.available());
        menu[0] = Serial.read();
        Serial.println(menu);
        delay(500);
        switch (menu[0]){
          case '1' : Serial.println("Seluruh data seminggu adalah : ");
                     system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select * from project;' &> /dev/ttyGS0 ");
                     while(!Serial.available());
                     break;
          case '2' : Serial.println("Nilai Rata-rata data sensor 1 Minggu adalah : ");
                     system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select avg(sensor) from project;' &> /dev/ttyGS0 ");
                     while(!Serial.available());
                     break;
          case '3' : Serial.println("Nilai tertinggi data sensor 1 Minggu adalah : ");
                     system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select max(sensor) from project;' &> /dev/ttyGS0 ");
                     while(!Serial.available());
                     break;
          case '4' : Serial.println("Nilai terendah data sensor 1 Minggu adalah : ");
                     system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select min(sensor) from project;' &> /dev/ttyGS0 ");
                     while(!Serial.available());
                     break;
          case '5' : Serial.println("1. Senin");
                     Serial.println("2. Selasa");
                     Serial.println("3. Rabu");
                     Serial.println("4. Kamis");
                     Serial.println("5. Jumat");
                     Serial.println("6. Sabtu");
                     Serial.println("7. Minggu");
                     while (!Serial.available());
                     menu2[0] = Serial.read();
                     Serial.println(menu2);
                     delay(500);
                     switch (menu2[0]){
                      case '1' : system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select sensor from project where hari = \"SENIN\";' &> /dev/ttyGS0 ");
                                 while(!Serial.available());
                      case '2' : system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select sensor from project where hari = \"SELASA\";' &> /dev/ttyGS0 ");
                                 while(!Serial.available());
                      case '3' : system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select sensor from project where hari = \"RABU\";' &> /dev/ttyGS0 ");
                                 while(!Serial.available());
                      case '4' : system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select sensor from project where hari = \"KAMIS\";' &> /dev/ttyGS0 ");
                                 while(!Serial.available());
                      case '5' : system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select sensor from project where hari = \"JUMAT\";' &> /dev/ttyGS0 ");
                                 while(!Serial.available());
                      case '6' : system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select sensor from project where hari = \"SABTU\";' &> /dev/ttyGS0 ");
                                 while(!Serial.available());
                      case '7' : system("sqlite3 -csv /home/root/praktikumTerakhir.db 'select sensor from project where hari = \"MINGGU\";' &> /dev/ttyGS0 ");
                                 while(!Serial.available());
                     }
        }
       
        
      }
    }
  }
}
