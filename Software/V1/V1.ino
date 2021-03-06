#include <EEPROM.h>
int trigPin = 6;      // trig pin of HC-SR04
int echoPin = 7;     // Echo pin of HC-SR04
int motor1 = 9;
int motor2 = 10;
int motor3 = 12;
int motor4 = 11;
int ENABLEpin_1 = 8;
int ENABLEpin_2 = 13;
int val_recived = 0;
int current_val = 0;
int eprom_val = EEPROM.read(1);
int step_size = (eprom_val * 10) + 100;
int loop_count = 0;
String last_action = "";
typedef struct {
  bool resp;
  long dist;
} outcome;


void setup()
{
  Serial.begin(9600);
  pinMode(motor1, OUTPUT); // Digital pin 9 set as output Pin
  pinMode(motor2, OUTPUT); // Digital pin 10 set as output Pin
  pinMode(motor3, OUTPUT); // Digital pin 12 set as output Pin
  pinMode(motor4, OUTPUT); // Digital pin 11 set as output Pin
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop()
{
  char mode = read_dip();
  Serial.print("Step Size:");
  Serial.print(step_size);
  Serial.println();
  Serial.print("Mode:");
  Serial.print(mode);
  Serial.println();
  if (mode == '1' or mode == '4')
  {
    digitalWrite(ENABLEpin_1 , HIGH);
    digitalWrite(ENABLEpin_2 , HIGH);
    Serial.println("Debug false, Motors enabled");
    if (mode == '1')
    {
      Serial.println("Mode:Obstacle");
      while (true)
      {
        obstacle(false);
      }
    }
    else
    {
      Serial.println("Mode:Bluetooth ");
      while (true)
      {
        bluetooth(false);
      }
    }

  }

  if (mode == '2' or mode == '3')
  {
    digitalWrite(ENABLEpin_1 , LOW);
    digitalWrite(ENABLEpin_2 , LOW);
    Serial.println("Debug true, Motors disabled");
    if (mode == '2')
    {
      Serial.println("Mode:Bluetooth");
      while (true)
      {
        bluetooth(true);
      }
    }
    else
    {
      Serial.println("Mode:Obstacle");
      while (true)
      {
        obstacle(true);
      }
    }
  }
}
