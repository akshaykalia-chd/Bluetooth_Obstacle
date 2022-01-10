
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


outcome can_i_move_left(bool debug)
{
  look_left(debug);
  stop_moving(100, debug);
  long distance = cal_distance();
  outcome  left = {false, distance};
  look_right(debug);
  stop_moving(100, debug);
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

outcome can_i_move_right(bool debug)
{
  look_right(debug);
  stop_moving(100, debug);
  long distance = cal_distance();
  outcome right = {false, distance};
  look_left(debug);
  stop_moving(100, debug);
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

bool am_i_stuck()
{
  int i = 0;
  int turn = 0;
  int look_back = 0;
  int move_forward = 0;
  while (i <= 27)
  { String action = "";
    char a = last_action[i];
    action += a;
    a = last_action[i + 1];
    action += a;
    a = last_action[i + 2];
    action += a;    
    if (action == "C10" or action == "C11" or action == "C30" or action == "C31")
    {
      turn += 1;
    }
    if (action == "C20")
    {
      look_back += 1;
    }
    if (action == "C00")
    {
      move_forward += 1;
    }
    i += 3;
  }
  Serial.print("No of Turns:");
  Serial.print(turn);
  Serial.println();
  Serial.print("No of look_back:");
  Serial.print(look_back);
  Serial.println();
  Serial.print("No of move_forward:");
  Serial.print(move_forward);
  Serial.println();
  if (move_forward == 10)
  {
    return false;
  }
  return true;
}
