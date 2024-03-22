### Si include la libreria locale di gestione del display

	#include "LiquidCrystal_I2C.h"

Si crea un oggetto di tipo LiquidCrystal_I2C:

    // Set the LCD address to 0x27 for a 20 chars and 4 line display
    LiquidCrystal_I2C lcd(0x27, 20, 4);

 Interfaccia I2C di connessione del tmp102
  	
    Wire1.setSDA(14);
    Wire1.setSCL(15);
    Wire1.begin();

Interfaccia I2C di connessione del display LCD: 

    Wire.setSDA(20);
    Wire.setSCL(21);
    Wire.begin();

Inizializzo il display:
 
     lcd.begin();

Accendo la retro illuminazione:
 
    lcd.backlight();
 
Stampo un messaggio di prova:
 
     lcd.print("Trasmissione dati");
     
Mi sposto sulla seconda riga del display:
  
      lcd.setCursor(0,2);
      lcd.print("3A Elettronica 2024");
      delay(4000);
      
Cancello tutto e riposiziono il cursore:

    lcd.clear();
    lcd.setCursor(0,0);

Interrogo il sensore TMP102: in caso di successo ritorna true, false in caso di fallimento

 	 if(!tmpSensor.begin(0x48,Wire1))
  	{ 
   	  lcd.print("Cannot connect " );
    	  lcd.setCursor(0,1);
     	  lcd.print("to tmp102 sensor!");
     	  lcd.setCursor(0,2);
     	  lcd.print("Stop");
   	  while(1);
 	 }

In caso di successo, lo segnalo per due secondi:

 	lcd.print("Connected to tmp102!" );
	delay(2000);
    
### Fase di loop

Leggo la temperatura del sensore:

    float temp = tmpSensor.readTempC();

Cancello tutto e riposiziono il cursore:

    lcd.clear();
    lcd.setCursor(0,0);
    
Stampo la temperatura:

    lcd.print("temperatura: " );
    lcd.print(temp);
    delay(2000);
    	

