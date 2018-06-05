#include <PID_v1.h>
#include <Encoder.h>
#include <cmath> 

#define outA 7
#define outB 8
#define pwm1 9

double Setpoint, Input, Output;
bool Forwards; 
PID motor1(&Input, &Output, &Setpoint,17.5, 0.027, 0, DIRECT);

Encoder motorEncoder1(0, 1);

void setup() {
  pinMode(outA, OUTPUT);
  pinMode(outB, OUTPUT);
  pinMode(pwm1, OUTPUT);

  Setpoint = 255;
  Forwards = false;
  motorEncoder1.write(0);
  //Input = motorEncoder1.read();

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

void loop() {
  Serial.print(motorEncoder1.read());
  Serial.printf("\n");

  Input = abs(motorEncoder1.read());
  motor1.Compute();

  if(Setpoint > Input && Forwards != true){
    motor1manual(Output, false);
  }
  else if (Setpoint < Input && Forwards != true){
    motor1manual(Output, true);
  }
  else if(Setpoint < Input && Forwards == true){
    motor1manual(Output, false);
  }
  else if (Setpoint > Input && Forwards == true){
    motor1manual(Output, true);
  }
  else{
    Serial.print("Target");
  }
    

}

