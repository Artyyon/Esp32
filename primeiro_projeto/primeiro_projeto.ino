#define LD_1 18

void setup() {
  Serial.begin(9600);
  Serial.println("Esp32");
  pinMode(LD_1, OUTPUT);
}

void loop() {
  digitalWrite(LD_1, HIGH);
  delay(500);
  digitalWrite(LD_1, LOW);
  delay(500);
}
