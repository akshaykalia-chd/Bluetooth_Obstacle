char read_dip()
{
  int dip1 = A2;
  int dip2 = A3 ;
  int sensorValue1 = analogRead(dip1);
  int sensorValue2 = analogRead(dip2);
  bool d01;
  bool d02;
  if (sensorValue1 >= 512) //slected mid point of 1024 as the mode was fliping due to noise
  {
    d01 = true;
  }
  else
  {
    d01 = false;
  }

  if (sensorValue2 >= 512) //slected mid point of 1024 as the mode was fliping due to noise
  {
    d02 = true;
  }
  else
  {
    d02 = false;
  }

  if (d01 and d02) 
  {    
    return '1';
  }
  if (d01 and not d02)
  {    
    return '2';
  }
  if (not d01 and d02)
  {    
    return '3';
  }
  if (not d01 and not d02)
  {    
    return '4';
  }
}
