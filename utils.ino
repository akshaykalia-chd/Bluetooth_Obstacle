long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void send_echo()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
}

long cal_distance()
{
  long duration, cm;
  send_echo();
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print("cm:");
  Serial.print(cm);
  Serial.print("\n");
  return cm;
}

long cal_displacment()
{
  long displacment = cm  - prev_cm;
  if (displacment < 0)
  {
    displacment = displacment * (-1);
  }
  return displacment;
}

void am_i_stuck()
{
  if (loop_count != 0)
  {
    Serial.println("Checking if I am stuck");
    stuck = false;
    long displacment = cal_displacment();
    Serial.print("Displacment:");
    Serial.print(displacment);
    Serial.println();
    if (displacment < 10 )
    {
      stuck = true;
    }
    else
    {
      Serial.println("Yaa! moving on.");
      return;
    }
  }
  else
  {
    return;
  }
}
