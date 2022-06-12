/*
 * Setup
*/
void setup() {
  sensors.begin();
  pinMode(Relay1Pin, OUTPUT);
  pinMode(Relay2Pin, OUTPUT);
  digitalWrite(Relay1Pin, LOW);
  digitalWrite(Relay2Pin, LOW);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Barbey Cidredrie");
  lcd.setCursor(0, 1);
  lcd.print("Press Select");
}
