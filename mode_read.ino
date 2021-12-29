int read_dip()
{
  int sensorValue1 = analogRead(dip1);
  int sensorValue2 = analogRead(dip2);
  bool d01;
  bool d02;
  if (sensorValue1 >= 512)
  {
    d01 = true;
  }
  else
  {
    d01 = false;
  }

  if (sensorValue2 >= 512)
  {
    d02 = true;
  }
  else
  {
    d02 = false;
  }

  if (d01 and d02) //slected mid poit of 1024 as the mode was fliping due to noise
  {
    Serial.println("mode: 1");
    return 1;
  }
  if (d01 and not d02)
  {
    Serial.println("mode: 2");
    return 2;
  }
  if (not d01 and d02)
  {
    Serial.println("mode: 3");
    return 3;
  }
  if (not d01 and not d02)
  {
    Serial.println("mode: 4");
    return 4;
  }
}
