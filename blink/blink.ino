void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); //led di segnalazione "I'm alive"

  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
      // wait for serial port to connect. Needed for native USB port only
    }

}

void loop() {
  Serial.println("So far....so good.... ");
  delay(1000);
}
