
void setup()
{

  pinMode(Relay1Pin, OUTPUT);
  pinMode(Relay2Pin, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Barbey Cidredrie");
  lcd.setCursor(0, 1);
  lcd.print("Press Select");
}
