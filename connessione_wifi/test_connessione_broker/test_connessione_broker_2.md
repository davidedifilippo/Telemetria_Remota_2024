### Tentativo di connessione ad un broker pubblico

Si includono la libreria di gestione del modulo wifi e il file contente le credenziali di accesso al router:

    #include <WiFi.h>
    #include "credentials.h"

Si include la libreria di gestione del sensore tmp102:

    #include <SparkFunTMP102.h> 

Si include la libreria di gestione del protocollo di comunicazione mqtt:

    #include <ArduinoMqttClient.h>

Si crea l'oggetto per la gestione del modulo WiFi del raspberry:

    WiFiClient wifiClient;

Si crea un oggetto per la gestione della comunicazione con il broker tramite protocollo mqtt:

    MqttClient mqttClient(wifiClient);

Si crea un oggetto per interagire con il sensore tmp102:
    
    TMP102 tmpSensor;

Bisogna ora inserire il nome dl broker:

    const char broker[] = "test.mosquitto.org";

La porta di ascolto del server:

    int  port = 1883;
    
Il topic ossia l'argomento con cui individuo le pubblicazioni sul broker:

    const char topic[]  = "lab20/tx_test";

Trasmetto ogni tre secondi:

    const long interval = 3000;

Mi serve un segnatempo:

    unsigned long previousMillis = 0;

Trasmetto il valore di un contatore che si incrementa ogni 3 secondi:

    float temp = 0;



### Fase di SETUP

Inizializzo la porta seriale e aspetto che sia pronta:

    Serial.begin(9600);
      while (!Serial) {
        ; //aspetto che la seriale sia disponibile
      }

  Testo la connessione con il sensore di temperatura:

        Wire1.setSDA(14);
        Wire1.setSCL(15);
        Wire1.begin();

     /*It will return true on success or false on failure to communicate. */
    if(!tmpSensor.begin(0x48,Wire1))
    { 
       Serial.print("Cannot connect " );
       Serial.print("to tmp102 sensor!");
       Serial.print("Stop");
       while(1);
    }

 Se il sensore risponde:

     Serial.println("Connesione al sensore tmp102 ok!");
     Serial.println();

  Tento di connettermi al router:
  
      Serial.print("Tentativo diconnessione al router SSID: ");
      Serial.println(ssid);
      
      while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
            // niente da fare, riprovo
            Serial.print(".");
            delay(5000);
            }

Tutto ok, connessione al router avvenuta:

    Serial.println("Connesione al router ok!");
    Serial.println();

  
Tentativo di connessione al broker remoto:


    Serial.print("Attempting to connect to the MQTT broker: ");
    Serial.println(broker);

    if (!mqttClient.connect(broker, port)) {
      Serial.print("Connessione MQTT fallita! Codice di errore = ");
      Serial.println(mqttClient.connectError());
      while (1); //Blocco tutto
  }

Connessione avvenuta con successo:

      Serial.println("You're connected to the MQTT broker!");
      Serial.println();

### Fase di LOOP

Devo mantenere la connessione al broker inviando un segnale di presenza ad ogni ciclo di loop:

    // call poll() regularly to allow the library to send MQTT keep alives which
    // avoids being disconnected by the broker
       mqttClient.poll();

Qunatoi tempo è passato dall'ultimo reset (istante di accensione):
  
    unsigned long currentMillis = millis();

Se sono passati piu di tre secondi dall'ultimo invio, trasmetto:

    if (currentMillis - previousMillis >= interval) {
    
mi segno il tempo di invio:

        previousMillis = currentMillis;

leggo la temperatura:

     temp = tmpSensor.readTempC();

Invio il messaggio al broker con topic e dato valido:

    mqttClient.beginMessage(topic);
    mqttClient.print(temp);
    mqttClient.endMessage();

Stampo alcune info di debug:

    Serial.print("Messaggio pubblicato con il topic : ");
    Serial.println(topic);
    Serial.print("temperatura=");
    Serial.print(temp);
    Serial.println();

    }


