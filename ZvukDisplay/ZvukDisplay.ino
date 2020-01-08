    #include <NewPing.h>
        #include <LiquidCrystal.h>
    LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
    #define PIN_TRIG 13
    #define PIN_ECHO 12
    #define MAX_DISTANCE 4000 // Константа для определения максимального расстояния, которое мы будем считать корректным.
    // Создаем объект, методами которого будем затем пользоваться для получения расстояния.
    // В качестве параметров передаем номера пинов, к которым подключены выходы ECHO и TRIG датчика
    NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);
    void setup() {
      // Инициализируем взаимодействие по последовательному порту на скорости 9600
      Serial.begin(9600);
      lcd.begin(16, 2);
      lcd.setCursor(0, 0);
      lcd.print("Arduino Master");
    }
    void loop() {
      // Стартовая задержка, необходимая для корректной работы.
      delay(100);
      // Получаем значение от датчика расстояния и сохраняем его в переменную
      unsigned int distance = sonar.ping_cm();
      // Печатаем расстояние в мониторе порта
      if ( distance!=0){
      Serial.print(distance);
      Serial.println("см");
      lcd.setCursor(0, 1);
      lcd.print("        ");
      lcd.setCursor(0, 1);
      lcd.print(distance);
      }else {};
    }
