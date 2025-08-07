char i = '12345';

void setup() {
  Serial1.begin(234000);
}

void loop() {
  Serial1.print(i);
  delay(1000);
}

