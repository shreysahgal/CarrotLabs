#include <PID_v1.h>
#include <Encoder.h>
#include <cmath> 

#define outA 7
#define outB 8
#define pwm1 9

double secs = 10;
int distance1;
int distance2;
int distanceAvg;


double Setpoint, Input, Output;
bool Forwards; 

PID motor1(&Input, &Output, &Setpoint, 10000, 0, 0, DIRECT);

Encoder motorEncoder1(0, 1);

void setup() {
  Setpoint = 0.3;
  Forwards = true;
  
  pinMode(outA, OUTPUT);
  pinMode(outB, OUTPUT);
  pinMode(pwm1, OUTPUT);
  
  motorEncoder1.write(0);

  motor1.SetMode(AUTOMATIC);

}

void motor1manual(int PWM, boolean BACK){
  analogWrite(pwm1, PWM);
  if(BACK){
    digitalWrite(outA, LOW);
    digitalWrite(outB, HIGH);
  }
  else{
    digitalWrite(outA, HIGH);
    digitalWrite(outB, LOW);
  }

}

double motor1velocity(){
  distance1 = motorEncoder1.read();
  delay(secs);
  distance2 = motorEncoder1.read();
  distanceAvg = abs(distance1 - distance2);
  return distanceAvg/secs;
}

void loop() {
  Input = motor1velocity();
  motor1.Compute();
  
  Serial.println(motor1velocity());
  Serial.println("\n");
  
  if(Setpoint < Input && Forwards != true){
    motor1manual(Output, false);
  }
  else if (Setpoint < Input && Forwards != true){
    motor1manual(Output, true);
  }
  else if(Setpoint > Input && Forwards == true){
    motor1manual(Output, false);
  }
    else if (Setpoint < Input && Forwards == true){
    motor1manual(Output, true);
  }
  else{
    Serial.print("Target");
  }
    
}
