#include <Wire.h>
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define TEMP_MAX 30
#define TEMP_MIN 0

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 ); //interfacing pins

//parametres pour le capteur de temperature
#define ONE_WIRE_BUS 24
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);



const int numReadings = 60;
int sensorValue = 0;
int Relay1Pin = 25;
int Relay2Pin = 27;

//int readings[numReadings];      // the readings from the analog input
//int readIndex = 0;              // the index of the current reading
//int total = 0;                  // the running total
//int average = 0;                // the average
//float v = 0.0;
//int tempSelect = 0;

//int maxtemp = 30;
//int mintemp = 1;
int cuve_no = 1;
//float tempOffset;
int temp_consigne;
float temperature;
enum etat { MENU, TEMP_SETUP, REGUL};

enum motion {
  UP, DOWN, LEFT, RIGHT, SELECT, NONE
};
int etat_general = MENU;



void loop()
{
  int accessMenu = Current_Boutton();
  switch (etat_general) {
    case MENU:
      if (accessMenu == SELECT) {
        lcd.clear();
        //selection_menu();
        main_menu(Current_Boutton());
      }
      break;
    case TEMP_SETUP:
      lcd.clear();
      lcd.print("Temp. Consigne");
      set_temp ();
      break;
    case REGUL:
      accessMenu = NONE;
      delay(150);
      lcd.setCursor(12, 1);
      lcd.print(temperature);
      lcd.setCursor(0, 1);
      lcd.print("Temperature");

      temperature = readTemp(); // lecture de temperature par NTC
      relais();
      accessMenu = Current_Boutton();
      Serial.println(accessMenu);
      if (accessMenu == SELECT) {
        etat_general = MENU;
      }

  }
}
