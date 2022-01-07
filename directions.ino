void stop_moving(bool debug, int ms_delay)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW); //Stop
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
  }
  Serial.println("Stop");
  delay(ms_delay);
}

void move_forward(bool debug, int ms_delay)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);//9
    digitalWrite(motor2, HIGH);//10
    digitalWrite(motor3, LOW);//12
    digitalWrite(motor4, HIGH);//11
  }
  Serial.println("Forward");
  delay(ms_delay);
}

void move_backward(bool debug, int ms_delay)
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH); //9//Move Backword
    digitalWrite(motor2, LOW);  //10
    digitalWrite(motor3, HIGH); //12
    digitalWrite(motor4, LOW);  //11
  }
  Serial.println("Backward");
  delay(ms_delay);
}

void turn_right(bool debug, int ms_delay)
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
  }
  Serial.println("Right");
  delay(ms_delay);
}

void turn_left(bool debug, int ms_delay)
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  }
  Serial.println("Left");
  delay(ms_delay);
}


void look_left(bool debug)
{
  turn_left(debug, 1000);
}

void look_right(bool debug)
{
  turn_right(debug, 1000);
}
