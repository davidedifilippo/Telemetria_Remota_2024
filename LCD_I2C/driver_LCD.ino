#include "LiquidCrystal_I2C.h"
#include <SparkFunTMP102.h> // Used to send and recieve specific information from tmp102 sensor

TMP102 tmpSensor;
// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {


  //Interfaccia I2C di connessione del tmp102
  Wire1.setSDA(14);
  Wire1.setSCL(15);
  Wire1.begin();

  //Interfaccia I2C di connessione del display LCD 
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();
 	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("Trasmissione dati");
  lcd.setCursor(0,2);
  lcd.print("3A Elettronica 2024");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);

   /*It will return true on success or false on failure to communicate. */
  if(!tmpSensor.begin(0x48,Wire1))
  { 
     lcd.print("Cannot connect " );
     lcd.setCursor(0,1);
     lcd.print("to tmp102 sensor!");
     lcd.setCursor(0,2);
     lcd.print("Stop");
    while(1);
  }

 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Connected to tmp102!" );
 delay(2000);
}

void loop() {
  

    float temp = tmpSensor.readTempC();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("temperatura: " );
    lcd.print(temp);
    delay(2000);
}
