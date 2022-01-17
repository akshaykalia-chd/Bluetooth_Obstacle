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
