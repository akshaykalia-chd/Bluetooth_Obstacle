void stop_moving(bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW); //Stop
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
  }
  Serial.println("Stop");
  delay(step_size);
}

void move_forward(bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);//9
    digitalWrite(motor2, HIGH);//10
    digitalWrite(motor3, LOW);//12
    digitalWrite(motor4, HIGH);//11
  }
  Serial.println("Forward");
  delay(step_size);
}

void move_backward(bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH); //9//Move Backword
    digitalWrite(motor2, LOW);  //10
    digitalWrite(motor3, HIGH); //12
    digitalWrite(motor4, LOW);  //11
  }
  Serial.println("Backward");
  delay(step_size);
}

void turn_right(bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
  }
  Serial.println("Right");
  delay(step_size);
}

void turn_left(bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  }
  Serial.println("Left");
  delay(step_size);
}

void un_stuck(bool debug)
{
  Serial.println("Trying to run un-stuck protocal");  
  int r = random(10);
  if (r % 2 == 0)
  {
    while (r > 0)
    {
      turn_right(debug);
      r = r - 1;
    }
  }
  else
  {
    while (r > 0)
    {
      turn_left(debug);
      r = r - 1;
    }
  }
  return;
}
