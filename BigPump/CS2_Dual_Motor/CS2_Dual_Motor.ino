#include <PID_v1.h>
#include <Encoder.h>
#include <cmath> 

#define outA 7
#define outB 8
#define pwm1 9

#define outC 14
#define outD 15
#define pwm2 10

double Setpoint, Input, Output;
bool Forwards; 

double Setpoint1, Input1, Output1;
bool Forwards1; 

bool mot1, mot2;

PID motor1(&Input, &Output, &Setpoint,17.5, 0.27, 0, DIRECT);

PID motor2(&Input1, &Output1, &Setpoint1,17.5, 0.27,0, DIRECT);

Encoder motorEncoder1(0, 1);
Encoder motorEncoder2(4, 5);

void setup() {
  pinMode(outA, OUTPUT);
  pinMode(outB, OUTPUT);
  pinMode(outC, OUTPUT);
  pinMode(outD, OUTPUT);
  
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  
  motorEncoder1.write(0);
  motorEncoder2.write(0);
  
  Input = motorEncoder1.read();
  Input1 = motorEncoder2.read();

  motor1.SetMode(AUTOMATIC);
  motor2.SetMode(AUTOMATIC);

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

void motor2manual(int PWM, boolean BACK){
  analogWrite(pwm2, PWM);
  if(BACK){
    digitalWrite(outC, LOW);
    digitalWrite(outD, HIGH);
  }
  else{
    digitalWrite(outC, HIGH);
    digitalWrite(outD, LOW);
  }

}

void loop() {



  Setpoint = 500;
  Setpoint1 = 500;
  
  Forwards = false;
  Forwards1 = false;

  motorEncoder1.write(0);
  motorEncoder2.write(0);

  
  Input = abs(motorEncoder1.read());
  Input1 = abs(motorEncoder2.read());


  for(int x = 0; x < 50000; x++){
  Input = abs(motorEncoder1.read());
  motor1.Compute();
  
  Input1 = abs(motorEncoder2.read());
  motor2.Compute();

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
    Serial.print("Target1");
  }

   if(Setpoint1 > Input1 && Forwards1 != true){
    motor2manual(Output1, false);
  }
  else if (Setpoint1 < Input1 && Forwards1 != true){
    motor2manual(Output1, true);
  }
  else if(Setpoint1 < Input1 && Forwards1 == true){
    motor2manual(Output1, false);
  }
  else if (Setpoint1 > Input1 && Forwards1 == true){
    motor2manual(Output1, true);
  }
  else{
    Serial.print("Target2");
  }
  }
  motor1manual(0, true);
  motor2manual(0, true);
 

 //break
 delay(1000);
 Serial.print("break");

motorEncoder1.write(0);
motorEncoder2.write(0);

 
  Setpoint = 257 ;
  Setpoint1 = 0;
  
  Forwards = false;
  Forwards1 = true;
  Input = abs(motorEncoder1.read());
  Input1 = abs(motorEncoder2.read());


  for(int y = 0; y < 80000; y++){
  Input = abs(motorEncoder1.read());
  motor1.Compute();
  
  Input1 = abs(motorEncoder2.read());
  motor2.Compute();

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
    Serial.print("Target1");
  }

   if(Setpoint1 > Input1 && Forwards1 != true){
    motor2manual(Output1, false);
  }
  else if (Setpoint1 < Input1 && Forwards1 != true){
    motor2manual(Output1, true);
  }
  else if(Setpoint1 < Input1 && Forwards1 == true){
    motor2manual(Output1, false);
  }
  else if (Setpoint1 > Input1 && Forwards1 == true){
    motor2manual(Output1, true);
  }
  else{
    Serial.print("Target2");
  }
  }
  motor1manual(0, true);
  motor2manual(0, true);



  
  }
 

