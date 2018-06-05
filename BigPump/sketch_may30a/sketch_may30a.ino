#define in 10

void setup() {
  // put your setup code here, to run once:
  pinMode(in, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(in));
  Serial.print("\n");

}
