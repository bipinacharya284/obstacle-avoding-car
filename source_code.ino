#include <Servo.h>

Servo myservo;
int servo_pos = 0;

int servo_pin = 12;

int trigPin = 9;      // trig pin of HC-SR04

int echoPin = 10;     // Echo pin of HC-SR04


int left_fwd = 5;       //ForWarD motion of Left motor

int left_rev = 4;       //REVerse motion of Left motor

int right_fwd = 7;      //ForWarD motion of Right motor

int right_rev = 6;      //REVerse motion of Right motor



long duration, distance;


void setup() {

  

  delay(random(500,2000));   // delay for random time

  Serial.begin(9600);

  pinMode(left_rev, OUTPUT);      // set Motor pins as output

  pinMode(left_fwd, OUTPUT);

  pinMode(right_rev, OUTPUT);

  pinMode(right_fwd, OUTPUT);

  

  pinMode(trigPin, OUTPUT);         // set trig pin as output

  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  
  
  myservo.attach(servo_pin);


}



void loop() {
  
// rotate_servo();

movement_decision();
// Serial.print(distance);
// rotate_servo(distance);
  
 


}

void movement_decision()
{
  rotate_servo_angle(0);
  distance = calculate_distance(9, 10);
  if (distance >10)
  {
    move_right();
    move_forward();
  }else{
    rotate_servo_angle(45);
    distance = calculate_distance(9, 10);
    if(distance > 10)
    {
      move_right();
      move_forward();
    }else{
      rotate_servo_angle(90);
      distance = calculate_distance(9, 10);
      if(distance > 10)
      {
        move_forward();
      }else{
        rotate_servo_angle(135);
        distance = calculate_distance(9, 10);
        if(distance > 10)
        {
          move_left();
          move_forward();
        }else{
           rotate_servo_angle(180);
           distance = calculate_distance(9, 10);
          if(distance > 10){
            move_left();
            move_forward();
          }else{
            stop();
            move_backward();
          }
        }
      }
    }
  }

  
}



void rotate_servo_angle(int angle)
{
  delay(500);
  myservo.write(angle);
  
  delay(1000);
}


long calculate_distance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);   

  digitalWrite(trigPin, HIGH);     // send waves for 10 us

  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH); // receive reflected waves

  distance = duration / 58.2;   // convert to distance
  // Serial.print("Calculating Distance");
  return distance;

}

void move_forward()
{
	// Left Motor controls
  	digitalWrite(left_fwd, HIGH);
  	digitalWrite(left_rev, LOW);
      
  	// Right motor controls
  	digitalWrite(right_fwd, HIGH);
  	digitalWrite(right_rev, LOW);
  
  	Serial.print("Moving Forward \n");
  	delay(500);

}

void stop()
{
	// Left Motor controls
  	digitalWrite(left_fwd, LOW);
  	digitalWrite(left_rev, LOW);
      
  	// Right motor controls
  	digitalWrite(right_fwd, LOW);
  	digitalWrite(right_rev, LOW);
  
  	Serial.print("Stop \n");
  	delay(500);

}


void move_backward()
{
	// Left Motor controls
  	digitalWrite(left_fwd, LOW);
  	digitalWrite(left_rev, HIGH);
      
  	// Right motor controls
  	digitalWrite(right_fwd, LOW);
  	digitalWrite(right_rev, HIGH);
  
  	Serial.print("Moving Backward \n");
  	delay(500);

}

void move_left()
{
	// Left Motor controls
  	digitalWrite(left_fwd, LOW);
  	digitalWrite(left_rev, HIGH);
      
  	// Right motor controls
  	digitalWrite(right_fwd, HIGH);
  	digitalWrite(right_rev, LOW);
  
  	Serial.print("Moving Left \n");
  	delay(500);

}

void move_right()
{
	// Left Motor controls
  	digitalWrite(left_fwd, HIGH);
  	digitalWrite(left_rev, LOW);
      
  	// Right motor controls
  	digitalWrite(right_fwd, LOW);
  	digitalWrite(right_rev, HIGH);
  
  	Serial.print("Moving Right \n");
  	delay(500);

}



