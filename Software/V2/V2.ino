#include "Bot.h"

int loopcount = 0;
Bot bot('P', true, 500, 50, 9, 10, 12, 11, 8, 13, 6, 7, A2, A3);
void setup()
{
  Serial.begin(9600);
  bot.set_mode_debug();
}

void loop()
{
  bot.print_data();  
  bot.lets_go();
}
