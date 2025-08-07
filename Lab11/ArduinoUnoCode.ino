char i = 'a';

void setup() {
  Serial.begin(57600);
}

void loop() {
  Serial.print(i);
  delay(1000);
}

