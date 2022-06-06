#include <Wire.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 ); //interfacing pins

const int numReadings = 60;
int inputPin = A15;
int sensorValue = 0;
int Relay1Pin = 25;
int Relay2Pin = 27;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
float v = 0.0;
int tempSelect = 0;

int maxtemp = 30;
int mintemp = 1;
int cuve_no = 1;
float temp = 0.0;
int temp_consigne;
int temperature = 27;
enum etat { SETUP, TEMP_SETUP, REGUL};

enum motion {
  UP, DOWN, LEFT, RIGHT, SELECT, NONE
};
int etat_general = SETUP;


void loop()
{
  int accessMenu = Current_Boutton();
  switch (etat_general) {
    case SETUP:
      if (accessMenu == SELECT) {
        do {
          lcd.clear();
          //selection_menu();
          main_menu(Current_Boutton());
        } while (etat_general == SETUP);
      }
      break;
    case TEMP_SETUP:
      lcd.clear();
      lcd.print("Temp. Consigne");
      set_temp ();
      break;
    case REGUL:
    delay(150);
      accessMenu = NONE;
      Serial.println(temp);
      lcd.setCursor(12, 1);
      lcd.print(temperature);
      lcd.setCursor(0, 1);
      lcd.print("Temperature");

      accessMenu = Current_Boutton();
      temperature = readTemp(); // lecture de temperature par NTC
      relais();
      if (accessMenu == SELECT) {
        etat_general = SETUP;
      }

  }
}
