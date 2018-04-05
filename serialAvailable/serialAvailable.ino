int incomingByte = 0;   // for incoming serial data
int total [50];

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte += Serial.read() - (int)'0';
               
                
                // say what you got:+ incomin
                Serial.print("I received: ");
                Serial.println(incomingByte , DEC);
       }
}
