#include <SparkFunTMP102.h> 

TMP102 tmpSensor;   //Si crea l'oggetto di tipo sensore TMP102


float temp = 0;


void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); //led di segnalazione "I'm alive"

  //Si inizializza l'interfaccia di connessione I2C_1 della scheda per la connessione con il sensore  
  Wire1.setSDA(14); 
  Wire1.setSCL(15);
  Wire1.begin();

  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

   /*It will return true on success or false on failure to communicate. */
  if(!tmpSensor.begin(0x48, Wire1))
  {
    Serial.println("Cannot connect to TMP102.");
    Serial.println("Is the board connected? Is the device ID correct?");
    while(1);
  }

  Serial.println("Connected to TMP102!");
  delay(100);



}

void loop() {
  // put your main code here, to run repeatedly:
    temp = tmpSensor.readTempC();
    Serial.println("Temperatura rilevata: ");
    Serial.println(temp);

   
  delay(1000);

}
