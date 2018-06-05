
void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);

digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);

analogWrite(9, 255);
analogWrite(10, 255);
}

void loop() {
  // put your main code here, to run repeatedly:

}
