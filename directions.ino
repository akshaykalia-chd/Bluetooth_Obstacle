void stop_moving(int ms_delay, bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW); //Stop
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
  }
  delay(ms_delay);
}

void move_forward(int ms_delay, bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);//9
    digitalWrite(motor2, HIGH);//10
    digitalWrite(motor3, LOW);//12
    digitalWrite(motor4, HIGH);//11
  }
  delay(ms_delay);
}

void move_backward(int ms_delay, bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH); //9//Move Backword
    digitalWrite(motor2, LOW);  //10
    digitalWrite(motor3, HIGH); //12
    digitalWrite(motor4, LOW);  //11
  }
  delay(ms_delay);
}

void turn_right(int ms_delay, bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
  }
  delay(ms_delay);
}

void turn_left(int ms_delay, bool debug)
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  }
  delay(ms_delay);
}


void look_left(bool debug)
{
  turn_left(500, debug);
}

void look_right(bool debug)
{
  turn_right(500, debug);
}

void look_back(bool debug)
{
  Serial.println("Spinning 180!");
  turn_right(500, debug);
  stop_moving(300, debug);
  turn_right(500, debug);
}
