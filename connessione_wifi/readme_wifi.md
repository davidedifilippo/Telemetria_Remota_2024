### File secret.h

Per creqre il file secret.h dove memorizzare le credenziali di accesso al router WiFi cliccare sui tre puntini in alto a destra 
e aggiungere un tab: scegliere il nome secret.h

Si creano due vettori di caratteri con SSID del router e la password di accesso

    char ssid[] = "WiFi_Router" ;   
    char pass[] = "password_di_accesso";   

### Sketch principale

Includo la libreria di gestione del modulo di comunicazioni WiFi:

    #include <WiFi.h>

Includo il file con le credenziali di accesso al router locale:

    #include "secret.h"

Creo un oggetto di tipo WiFiClient che rappresenti il mio modulo WiFI:

    WiFiClient wifiClient;

### Fase di SETUP

Si stampano informazioni di debug del codice:

          Serial.print("Tentativo di connessione all'SSID: ");
          Serial.println(ssid);

Si prova a far connettere il modulo WiFi del raspberry con il router:

     while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
          // failed, retry
             Serial.print("." );
             delay(5000);
       }

Il while assicura che il tentativo continui fino al successo dell'operazione.

     Serial.print("Connected!" );
     delay(2000);

### Fase di LOOP

Per ora è vuota




