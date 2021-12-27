int trigPin = 6;      // trig pin of HC-SR04
int echoPin = 7;     // Echo pin of HC-SR04
int motor1 = 9;
int motor2 = 10;
int motor3 = 12;
int motor4 = 11;
int ENABLEpin_1 = 8;
int ENABLEpin_2 = 13;
int mode = LOW;
int dip1 = A2;
int dip2 = A3 ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
digitalWrite(ENABLEpin_1 , HIGH);
digitalWrite(ENABLEpin_2 , HIGH);
pinMode(motor1, OUTPUT); // Digital pin 9 set as output Pin
pinMode(motor2, OUTPUT); // Digital pin 10 set as output Pin
pinMode(motor3, OUTPUT); // Digital pin 12 set as output Pin
pinMode(motor4, OUTPUT); // Digital pin 11 set as output Pin
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
}

void loop() 
  {
    int mode = read_dip();          
    if(mode == 1 or mode == 2)
      {        
        bluetooth();        
      }
    else if (mode == 3 or mode == 4)
      {              
        obstacle();                 
      }    
  }
  
void obstacle()
  { 
    Serial.println("Obstacle Mode");    
      long cm ;
      send_echo();    
      cm = cal_distance();   
      if(cm>40)
        {
          move_forward();
        }
      if(cm<40)
        {
          stop_moving();
          delay(500);
          move_backward();  
          delay(500);
          stop_moving();
        }
      if(cm<40&cm>30)
        {
          stop_moving();
          delay(500);
          move_right();
          delay(500);      
          send_echo();    
          cm = cal_distance();
          if (cm <40) 
            {
              move_backward();
              delay(500);
              move_right();
              delay(500);          
            }                   
        }  
      if(cm<20)
        {
         stop_moving();
         delay(500);
         move_backward();
         delay(500);
         stop_moving();
         send_echo();    
         cm = cal_distance();
         if (cm < 20) 
          {
            move_backward();
            delay(500);
          }     
        }
    }


void bluetooth()
{  
      int val;
      Serial.println("Bluetooth Mode");
      while (Serial.available() > 0)
       {    
         val = Serial.read();
         Serial.println(val);
       }
      
      if( val == 1) // Forward
       { 
          move_forward();
       }
      else if(val == 2) // Backward
       {
          move_backward(); 
       }
       
      else if(val == 4) //Left
       { 
          turn_left();    
       }
      
      else if(val == 3) //Right
       { 
          turn_right();
       }
      
      else if(val == 5) //Stop
       { 
          stop_moving();
       }      
    }  


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
    long duration,cm;
    duration = pulseIn(echoPin, HIGH);
    cm = microsecondsToCentimeters(duration);
    Serial.print("cm:");
    Serial.print(cm);
    Serial.print("\n");    
    return cm;
  }

void move_forward()
  {
    digitalWrite(motor1, LOW);//9
    digitalWrite(motor2, HIGH);//10
    digitalWrite(motor3, LOW);//12
    digitalWrite(motor4, HIGH);//11  
  }

void move_backward()
  {
    digitalWrite(motor1, HIGH); //9//Move Backword
    digitalWrite(motor2, LOW);  //10
    digitalWrite(motor3, HIGH); //12
    digitalWrite(motor4, LOW);  //11  
  }

void stop_moving()
  {
    digitalWrite(motor1, LOW); //Stop
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);  
  }

void move_right()
  {
    digitalWrite(motor1, HIGH); //Forward Right
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);  
  }

void turn_right()
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);    
  }

void turn_left()
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);    
  }

int read_dip()
  {
    int sensorValue1 = analogRead(dip1);  
    int sensorValue2 = analogRead(dip2);
    if (sensorValue1 == 0 and sensorValue2 == 0)
      {
        Serial.println("mode: 1");
        return 1;
      }
    if (sensorValue1 == 0 and sensorValue2 > 0)
      {
        Serial.println("mode: 2");
        return 2;
      }
    if (sensorValue1 > 0 and sensorValue2 == 0)
      {
        Serial.println("mode: 3");
        return 3;
      }
    if (sensorValue1 > 0 and sensorValue2 > 0)
      {
        Serial.println("mode: 4");
        return 4;
      }
  }
