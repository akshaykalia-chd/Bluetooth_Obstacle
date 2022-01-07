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
long distance  = 0;
long prev_distance = 0;
int eprom_val = EEPROM.read(1);
int step_size = (eprom_val * 10) + 100;
long displacment = 0;
typedef struct {   
  bool resp;
  long dist;
} outcome;


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
  if (mode == 1 or mode == 2)
  {
    while (true)
    {
      if (mode == 2)
      {
        call_action( 'b', true); //bluethooh debug true
      }
      else
      {
        call_action( 'b', false); //bluethooh debug false
      }
    }
  }

  if (mode == 4 or mode == 3)
  {
    while (true)
    {
      if (mode == 3)
      {
        call_action( 'o', true); //Obstacle debug true
      }
      else
      {
        call_action( 'o', false); //Obstacle debug false
      }
    }
  }
}

void call_action( char action, bool debug)
{
  if (debug)
  {
    Serial.println("Debug Mode");
  }
  if (action == 'b')
  {
    bluetooth(debug);
  }
  if (action == 'o')
  {
    obstacle(debug);
  }
}
