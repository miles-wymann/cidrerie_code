#define DIGIT3 45
#define DIGIT1 43
#define DIGIT2 47
#define SEGA 53
#define SEGB 49
#define SEGC 50
#define SEGD 46
#define SEGE 44
#define SEGF 51
#define SEGG 52
#define SEGP 48

//encoder
#define KEY 24 // KEY pin
#define S2 26  // S2 pin
#define S1 28  // S1 pin
#define CCW 0b010010  // knob turn CCW pattern
#define CW 0b100001   // knob turn CW pattern
#define DEF 0b11  // default / base value of encoder signal

byte prevPattern = 0; // previous signal pattern
byte pattern = 0;     // actual signal pattern
bool keyPushed = false;     // button push status

int tempSelect = 0;
int maxtemp = 30;
int mintemp = 1;

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
float temp = 0.0;

byte aktS1 = digitalRead(S1);
byte aktS2 = digitalRead(S2);
byte aktKey = !digitalRead(KEY);
byte button1Last = 0;
byte button1State = 0;


int temperature;
float temperature_consigne = 27;

struct NOMBRE
{
  int dizaine;
  int unite;
  int decimale;
};

int readTemp();
void affiche_temperature(NOMBRE nombre);
NOMBRE creer_nombre(float temp);
void relais();

void loop() {
  Serial.println(temp);

  selectTemp(); // potntiometre + bouton
  temperature = readTemp(); // lecture de temperature par NTC
  NOMBRE nombre = creer_nombre(temperature);
  affiche_temperature(nombre); // Affichage
  relais();


}
