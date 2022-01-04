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
  Serial.println();
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

bool am_i_stuck()
{
  if (loop_count == 10)
  {
    Serial.println("Checking if I am stuck");
    long avg_displacment = displacment/11;
    Serial.print("Average Displacment:");
    Serial.print(avg_displacment);
    Serial.println();
    if (avg_displacment < 20 )
    {      
      Serial.println("Oh!,I am stuck.");
      return true;
    }
  }
return false;
}
