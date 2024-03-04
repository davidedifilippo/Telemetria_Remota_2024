#include <WiFi.h>
#include "secret.h"

// To connect with SSL/TLS:
// 1) Change WiFiClient to WiFiSSLClient.
// 2) Change port value from 1883 to 8883.
// 3) Change broker value to a server with a known SSL/TLS root certificate 
//    flashed in the WiFi module.

WiFiClient wifiClient;

void setup() {

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    lcd.print("." );
    delay(5000);
  }

 
 Serial.print("Connected!" );
 delay(2000);

}

void loop() {
 
  
}
