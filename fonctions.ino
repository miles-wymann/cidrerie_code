// Displays temperature, by writing each digit to 7 segment display

void affiche_temperature(NOMBRE nombre)
{
  digitalWrite(DIGIT1, LOW);
  digitalWrite(DIGIT2, HIGH);
  digitalWrite(DIGIT3, HIGH);
  affiche_numero(nombre.decimale);
  digitalWrite(SEGP, LOW);
  delay(1);
  digitalWrite(DIGIT1, HIGH);
  digitalWrite(DIGIT2, LOW);
  digitalWrite(DIGIT3, HIGH);
  affiche_numero(nombre.unite);
  digitalWrite(SEGP, HIGH);
  delay(1);
  digitalWrite(DIGIT1, HIGH);
  digitalWrite(DIGIT2, HIGH);
  digitalWrite(DIGIT3, LOW);
  affiche_numero(nombre.dizaine);
  digitalWrite(SEGP, LOW);
  delay(1);
}

NOMBRE creer_nombre(float temp)
{
  NOMBRE nombre;
  nombre.dizaine = (int)temp / 100;
  nombre.unite = (int)(temp - (nombre.dizaine * 100)) / 10;
  nombre.decimale = temp - nombre.dizaine * 100 - nombre.unite * 10;
  return nombre;
}
void relais()
{

  if (temp <= temperature_consigne - .5)
  {
    digitalWrite(Relay1Pin, LOW);
    digitalWrite(Relay2Pin, LOW);
  }
  if (temp >= temperature_consigne + .5)
  {
    digitalWrite(Relay1Pin, HIGH);
    digitalWrite(Relay2Pin, HIGH);
  }
}

int readTemp()
{
  // subtract the last reading:
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings)
  {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits

  v = average * (5.0 / 1023.0);
  temp = 0.1939 * pow(v, 6) - 3.5228 * pow(v, 5) + 24.898 * pow(v, 4) - 88.351 * pow(v, 3) + 168.26 * pow(v, 2) - 185.45 * v + 132.38;
  temp = temp * 10;
  return temp;
}

int selectTemp()
{
  // Test this button function, it might have errors. It will be used to start the cooling and regulation process

  if (aktKey == 1 && button1State == 0)
  {
    button1State = 1;
  }
  if (aktKey == 1 && button1State == 1)
  {
    button1State == 0;
  }

  Serial.println(button1State);

  byte aktPattern = (aktS1 << 1) | aktS2; // je ne comprend pas vraiment cette partie :/

  if (aktPattern != prevPattern)
  {
    prevPattern = aktPattern;
    if (aktPattern != DEF)
    {
      pattern = (pattern << 2) | aktPattern;
    }
    else
    {
      if (pattern == CW)
      {
        tempSelect++;
        if (tempSelect >= maxtemp)
        {
          tempSelect = maxtemp;
        }
      }
      else if (pattern == CCW)
      {
        tempSelect--;
        if (tempSelect <= mintemp)
        {
          tempSelect = mintemp;
        }
      }
      pattern = 0;
    }
  }
}
