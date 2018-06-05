#define outA 7
#define outB 8
#define pwm1 9

void setup() {
  // put your setup code here, to run once:
  pinMode(outA, OUTPUT);
  pinMode(outB, OUTPUT);
  pinMode(pwm1, OUTPUT);
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
  // put your main code here, to run repeatedly:
motor1manual(255, false);
}
