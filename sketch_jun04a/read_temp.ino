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

  v = average * (5.0 / 1023.0);
  temp = 0.1939 * pow(v, 6) - 3.5228 * pow(v, 5) + 24.898 * pow(v, 4) - 88.351 * pow(v, 3) + 168.26 * pow(v, 2) - 185.45 * v + 132.38;
 
  return temp;
}


void relais()
{

  if (temp/10 <= temp_consigne - .3)
  {
    digitalWrite(Relay1Pin, LOW);
    digitalWrite(Relay2Pin, LOW);
  }
  if (temp/10 >= temp_consigne + .3)
  {
    digitalWrite(Relay1Pin, HIGH);
    digitalWrite(Relay2Pin, HIGH);
  }
}
