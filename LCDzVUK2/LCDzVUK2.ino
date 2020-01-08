    #define PIN_TRIG 13
    #define PIN_ECHO 12
        #include <LiquidCrystal.h>
    long duration, cm;
    LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
    void setup() {
      // Инициализируем взаимодействие по последовательному порту
      Serial.begin (9600);
lcd.begin(16, 2);
      lcd.setCursor(0, 0);
      lcd.print("Arduino Master");
      //Определяем вводы и выводы
      pinMode(PIN_TRIG, OUTPUT);
      pinMode(PIN_ECHO, INPUT);
    }
        void clearLine(int line){
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    void printDisplay(String message){
      Serial.println(message);
      lcd.setCursor(0, 1);
      lcd.print(message);
      //delay(1000);
     
    }
    void loop() {
      // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.
      digitalWrite(PIN_TRIG, LOW);
      delayMicroseconds(5);
      digitalWrite(PIN_TRIG, HIGH);
      // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
      delayMicroseconds(10);
      digitalWrite(PIN_TRIG, LOW);
      //  Время задержки акустического сигнала на эхолокаторе.
      duration = pulseIn(PIN_ECHO, HIGH);
      // Теперь осталось преобразовать время в расстояние
      cm = (duration / 2) / 29.1;
      Serial.print("Расстояние до объекта: ");
      Serial.print(cm);lcd.setCursor(0, 1);
       lcd.print("                ");
      lcd.print(cm);
      lcd.print(" см.");
      // Задержка между измерениями для корректной работы скеча
      delay(250);
    }
