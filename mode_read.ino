int read_dip()
{
  int sensorValue1 = analogRead(dip1);
  int sensorValue2 = analogRead(dip2);
  if (sensorValue1 <= 512 and sensorValue2 <= 512) //slected mid poit of 1024 as the mode was fliping due to noise
  {
    Serial.println("mode: 1");
    return 1;
  }
  if (sensorValue1 <= 512 and sensorValue2 >= 512)
  {
    Serial.println("mode: 2");
    return 2;
  }
  if (sensorValue1 >= 512 and sensorValue2 <= 0)
  {
    Serial.println("mode: 3");
    return 3;
  }
  if (sensorValue1 >= 512 and sensorValue2 >= 0)
  {
    Serial.println("mode: 4");
    return 4;
  }
}
