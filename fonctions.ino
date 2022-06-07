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

  if (button1State == 0)
  {
    if (temp <= temperature_consigne - .3)
    {
      digitalWrite(Relay1Pin, LOW);
      digitalWrite(Relay2Pin, LOW);
    }
    if (temp >= temperature_consigne + .3)
    {
      digitalWrite(Relay1Pin, HIGH);
      digitalWrite(Relay2Pin, HIGH);
    }
    NOMBRE nombre = creer_nombre(temperature);
    affiche_temperature(nombre); // Affichage
  }
  if (button1State == 1)
  {
    digitalWrite(Relay1Pin, LOW);
    digitalWrite(Relay2Pin, LOW);
    NOMBRE nombre = creer_nombre(tempSelect*10);
    affiche_temperature(nombre); // Affichage
  }
}

float readTemp()
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

  v = average * (5.05 / 1023.0);
  // New temp calculation using pandas
  temp = 0.05334 * pow(v, 6) - 0.9057 * pow(v, 5) + 6.367 * pow(v, 4) - 24.7 * pow(v, 3) + 57.69 * pow(v, 2) - 94.88 * pow(v, 1) + 105.5;
  temp = temp + tempOffset;
  return temp;
}

int selectTemp()
{
  // Simple button on off function with simple temperature regulation
  {
    aktKey = digitalRead(KEY);
    if (aktKey == 1 && button1Last == 0)
      if (aktKey == 1)
      {
        if (button1State == 0)
        {
          button1State++;
        }
        else if (button1State == 1)
        {
          button1State--;
        }
      }
    button1Last = aktKey;
  }

  {
    aktS1 = digitalRead(S1);
    aktS2 = digitalRead(S2);

    aktPattern = (aktS1 << 1) | aktS2;

    if (aktPattern != prevPattern && button1State == 1)
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
    temperature_consigne = tempSelect;
  }
}