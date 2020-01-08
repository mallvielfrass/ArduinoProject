int led = 5 ;// назначение пина для светодиода
int pirPin = 6; // назначение пина для мини ИК датчика
int value ;// переменная для хранения положения датчика
void setup ()
{
  Serial.begin(9600);
  pinMode (led, OUTPUT) ;// пин светодиода работает как выход
  pinMode (pirPin, INPUT) ; // пин датчика работает как вход
}
void loop ()
{
  value = digitalRead (pirPin) ;// чтение значения с датчика
  if (value == HIGH) // когда с ИК сенсора появляется высокий уровень, светодиод загорается
  {
    digitalWrite (led, HIGH);
    Serial.println("movement");
  }
  else
  {
    digitalWrite (led, LOW);
    Serial.println("no movement");
  }
  delay(1000);
}
