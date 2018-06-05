#include <PID_v1.h>

#include <Encoder.h>
  
  #define outA 7
  #define outB 8
  #define pwm1 9

#define outC 12
#define outD 11
#define pwm2 10

double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint,1, 0, 0, DIRECT);

Encoder knobLeft(0, 1);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(outA, OUTPUT);
  pinMode(outB, OUTPUT);
  pinMode(pwm1, OUTPUT);

  Setpoint = 100;
  knobLeft.write(0);
  Input = knobLeft.read();

   myPID.SetMode(AUTOMATIC);

}

void motor1manual(int PWM){
  analogWrite(pwm1, PWM);
  if(PWM < 0){
    digitalWrite(outA, LOW);
    digitalWrite(outB, HIGH);
  }
  else if (PWM > 0){
    digitalWrite(outA, HIGH);
    digitalWrite(outB, LOW);
  }
  else{
    digitalWrite(outA, LOW);
    digitalWrite(outB, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(knobLeft.read());
  Serial.printf("\n");
  
  Input = (double)knobLeft.read();
  myPID.Compute();
  if(Setpoint < Input){
    motor1manual(Output * -1);
  }
   else{
    motor1manual(Output);
   }
  }



