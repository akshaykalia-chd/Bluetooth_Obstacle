#include <EEPROM.h>
int trigPin = 6;      // trig pin of HC-SR04
int echoPin = 7;     // Echo pin of HC-SR04
int motor1 = 9;
int motor2 = 10;
int motor3 = 12;
int motor4 = 11;
int ENABLEpin_1 = 8;
int ENABLEpin_2 = 13;
int mode = 0;
int dip1 = A2;
int dip2 = A3 ;
int val_recived = 0;
int current_val = 0;
long cm  = 0;
long prev_cm  = 0;
int eprom_val = EEPROM.read(1);
int step_size = (eprom_val * 10) + 100;
int loop_count = 0;
long displacment = 0;


void setup() {
  Serial.begin(9600);
  digitalWrite(ENABLEpin_1 , HIGH);
  digitalWrite(ENABLEpin_2 , HIGH);
  pinMode(motor1, OUTPUT); // Digital pin 9 set as output Pin
  pinMode(motor2, OUTPUT); // Digital pin 10 set as output Pin
  pinMode(motor3, OUTPUT); // Digital pin 12 set as output Pin
  pinMode(motor4, OUTPUT); // Digital pin 11 set as output Pin
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  mode = read_dip();
}

void loop()
{
  int rand_no = 0;
  if (mode == 1 or mode == 2)
  {
    while (true)
    {
      rand_no = random(100);
      if (mode == 2)
      {
        call_action( 'b', true, rand_no); //bluethooh debug true
      }
      else
      {
        call_action( 'b', false, rand_no); //bluethooh debug false
      }
    }
  }

  if (mode == 4 or mode == 3)
  {
    while (true)
    {
      rand_no = random(100);
      if (mode == 3)
      {
        call_action( 'o', true, rand_no); //Obstacle debug true
      }
      else
      {
        call_action( 'o', false, rand_no); //Obstacle debug false
      }
    }
  }
}



void call_action( char action, bool debug, int rand_no)
{
  if (debug)
  {
    Serial.println("Debug Mode");
  }
  if (action == 'b')
  {
    pre_action_tasks();
    bluetooth(debug, rand_no);
  }
  if (action == 'o')
  {
    pre_action_tasks();
    obstacle(debug, rand_no);
  }
}

void pre_action_tasks()
{
  loop_count = loop_count + 1;
  prev_cm = cm;
  cm = cal_distance();
  displacment = displacment + cal_displacment();
  if (loop_count > 10)
  {
    loop_count = 0;
    displacment = 0;
  }
}
