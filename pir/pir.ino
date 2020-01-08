#define SIGNAL_PIN 7
#define LED 8
void setup()
{
  Serial.begin(9600);
  pinMode(SIGNAL_PIN, INPUT);
  pinMode(LED, OUTPUT);
}
void loop() {
  Serial.println("debug");
  if(digitalRead(SIGNAL_PIN)==HIGH) {
    Serial.println("Movement detected.");
    digitalWrite(LED,1);
    
  } else {
    Serial.println("Did not detect movement.");
    digitalWrite(LED,0);
  }
  delay(1000);
}
