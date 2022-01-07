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
  send_echo();
  long duration = pulseIn(echoPin, HIGH);
  long cm = microsecondsToCentimeters(duration);
  Serial.print("cm:");
  Serial.print(cm);
  Serial.println();
  return cm;
}

long cal_displacment()
{
  long displacment = distance  - prev_distance;
  if (displacment < 0)
  {
    displacment = displacment * (-1);
  }
  return displacment;
}

bool can_i_move_forward()
{
  bool outcome = false;
  long cms = cal_distance();
  if (cms > 70 and cms < 1200)
  {
    outcome = true;
  }
  Serial.print("Can i move forward?");
  if (outcome)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  return outcome;
}


bool can_i_move_left(bool debug)
{
  bool outcome = false;
  look_left(debug);
  long cms = cal_distance();
  if (cms > 70 and cms < 1200)
  {
    outcome = true;
  }
  Serial.print("Can i move forward on the left?");
  if (outcome)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  look_right(debug);
  return outcome;
}

bool can_i_move_right(bool debug)
{
  bool outcome = false;
  look_right(debug);  
  long cms = cal_distance();
  if (cms > 70 and cms < 1200)
  {
    outcome = true;
  }
  Serial.print("Can i move forward on the left?");
  if (outcome)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  look_left(debug);
  return outcome;
}
