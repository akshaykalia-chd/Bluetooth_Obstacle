
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
//  Serial.print("cm:");
//  Serial.print(cm);
//  Serial.println();
  return cm;
}

outcome can_i_move_forward()
{
  long distance = cal_distance();
  outcome  forward = {false, distance};
  if (distance > 50 and distance < 1200)
  {
    forward = {true, distance};
  }
  Serial.print("Can i move forward?");
  if (forward.resp)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  return forward;
}


outcome can_i_move_left()
{
  look_left();
  stop_moving(100);
  long distance = cal_distance();
  outcome  left = {false, distance};
  look_right();
  stop_moving(100);
  if (distance > 50 and distance < 1200)
  {
    left = {true, distance};
  }
  Serial.print("Can i move forward on the left?");
  if (left.resp)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  return left;
}

outcome can_i_move_right()
{
  look_right();
  stop_moving(100);  
  long distance = cal_distance();
  outcome right = {false, distance};
  look_left();
  stop_moving(100);
  if (distance > 50 and distance < 1200)
  {
    right = {true, distance};
  }
  Serial.print("Can i move forward on the right?");
  if (right.resp)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  return right;
}
