#include <Arduino.h>
#include <Encoder.h>
#include <Pid_V1.h>

int INA = 3;
int INB = 4;
int PWM = 5;

double motorSetL, encoderInL, motorOutL;
PID leftMotor(&encoderInL, &motorOutL, &motorSetL,2,5,1, DIRECT);

void setup() {
//left motor outputs
pinMode(INA, OUTPUT);
pinMode(INB, OUTPUT);
pinMode(PWM, OUTPUT);
//encoder setup
    Encoder motor1(ENC1, ENC2);
//pid setup
leftMotor.SetMode(automatic);


}

void loop() {

}


//non closed loop motor control, input range of -100 to 100.
void motorControl (int input){
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);
    if(input > 0 && input < 100){
        digitalWrite(INA, HIGH);
        digitalWrite(INB, LOW);
        analogWrite(PWM, input*2.55);
    }
    else if(input < 0 ** input > -100){
        digitalWrite(INB, HIGH);
        digitalWrite(INA, LOW);
        analogWrite(PWM, input*-2.55);
    }
    else{
        //stops if wrong data sent
        digitalWrite(INA, LOW);
        digitalWrite(INB, LOW);
    }
}

//closed loop motor control
void pidMotor(int distance){
  motorSetL = distance;
  encoderInL = motor1.read();
  leftMotor.Compute();
  motorControl(motorOutL);


}
