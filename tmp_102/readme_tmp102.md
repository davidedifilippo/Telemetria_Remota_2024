### Spiegazione del codice di gestione del sensore

Si include il file della libreria di gestione del tmp102:

    #include <SparkFunTMP102.h> 

La libreria deve essere installata nell'IDE di Arduino.

Si crea un oggetto di tipo TMP102:

    TMP102 tmpSensor;   //Si crea l'oggetto di tipo sensore TMP102

Si dichiara una variabile per la gestione della temperatura letta tramite il sensore digitale:

      float temp = 0;

### Fase di setup

Si dichiara il piedino di gestione del led BUILTIN come uscita:

      pinMode(LED_BUILTIN, OUTPUT);

Si accende il led per segnalare che la board funziona:

      digitalWrite(LED_BUILTIN, HIGH); //led di segnalazione "I'm alive"

Si inizializza l'interfaccia di connessione I2C_1 della scheda per la connessione con il sensore  
  
    Wire1.setSDA(14); Piedino 14 della board per la comunicazione dei dati
    Wire1.setSCL(15); Piedino 15 per il segnale di clock
    Wire1.begin();

  Initialize serial and wait for port to open:
  
      Serial.begin(9600);

      while (!Serial) {
          ; // wait for serial port to connect. Needed for native USB port only
      }

  Controllo che il sensore risponda all'interrogazione sul bus I2C1:  

       It will return true on success or false on failure to communicate. */
      if(!tmpSensor.begin(0x48, Wire1))
        {
            Serial.println("Cannot connect to TMP102.");
            Serial.println("Is the board connected? Is the device ID correct?");
            while(1);
        }

  In caso di successo stampo la frase di rito:

        Serial.println("Connected to TMP102!");
        delay(100);


### Fase di loop

    temp = tmpSensor.readTempC();
    Serial.println("Temperatura rilevata: ");
    Serial.println(temp);
    
Aspetto un secondo per ripetere la lettura della temperatura:

    delay(1000);

