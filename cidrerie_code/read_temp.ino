float readTemp()
{
 Serial.begin(9600);
 Serial.println(sensors.getTempCByIndex(0));
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 return(sensors.getTempCByIndex(0));
}


  /*
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
    Serial.println(v);
  temp = 0.05334 * pow(v, 6) - 0.9057 * pow(v, 5) + 6.367 * pow(v, 4) - 24.7 * pow(v, 3) + 57.69 * pow(v, 2) - 94.88 * pow(v, 1) + 105.5;
  return temp + tempOffset;
  */


void relais()
{

  if (temperature <= temp_consigne - .3)
  {
    digitalWrite(Relay1Pin, LOW);
    digitalWrite(Relay2Pin, LOW);
  }
  if (temperature >= temp_consigne + .3)
  {
    digitalWrite(Relay1Pin, HIGH);
    digitalWrite(Relay2Pin, HIGH);
  }
}
