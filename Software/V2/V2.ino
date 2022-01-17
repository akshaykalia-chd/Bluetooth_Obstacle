#include "Obstacle.h"

Obstacle bot(true, 300, 500, 50);
int loopcount = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  loopcount += 1;  
  char mode = '1';
  if (loopcount > 5)
  {
    mode = '2';  
  }

  if (mode == '1' | mode == '4')
  {
    bot._debug = false; 
  }
  if (mode == '2' | mode == '3')
  {
    bot._debug = true;    
  }
 
  bot.set_debug();
  bot.print_data();
  bot.start_moving();
}
