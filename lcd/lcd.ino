    #include <LiquidCrystal.h>
    LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
    #define BTN_UP   1
    #define BTN_DOWN 2
    #define BTN_LEFT 3
    #define BTN_RIGHT 4
    #define BTN_SELECT 5
    #define BTN_NONE 10
 #include <NewPing.h>
#define PIN_TRIG 12
#define PIN_ECHO 11
#define MAX_DISTANCE 4000
NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

    int detectButton() {
      int keyAnalog =  analogRead(A0);
      if (keyAnalog < 100) {
        // Значение меньше 100 – нажата кнопка right
        return BTN_RIGHT;
      } else if (keyAnalog < 200) {
        // Значение больше 100 (иначе мы бы вошли в предыдущий блок результата сравнения, но меньше 200 – нажата кнопка UP
        return BTN_UP;
      } else if (keyAnalog < 400) {
        // Значение больше 200, но меньше 400 – нажата кнопка DOWN
        return BTN_DOWN;
      } else if (keyAnalog < 600) {
        // Значение больше 400, но меньше 600 – нажата кнопка LEFT
        return BTN_LEFT;
      } else if (keyAnalog < 800) {
        // Значение больше 600, но меньше 800 – нажата кнопка SELECT
        return BTN_SELECT;
      } else {
        // Все остальные значения (до 1023) будут означать, что нажатий не было
        return BTN_NONE;
      }
    }
    void clearLine(int line){
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    void printDisplay(String message){
      Serial.println(message);
      lcd.setCursor(0, 1);
      lcd.print(message);
      delay(1000);
      clearLine(1);
    }
    void setup() {
      Serial.begin(9600);
      lcd.begin(16, 2);
      lcd.print("Arduino Master");
      delay(3000);
      lcd.setCursor(0, 0);
      lcd.print("Arduino Master");
      
    }
    void loop() {
       delay(200);
        unsigned int distance = sonar.ping_cm();
  // Печатаем расстояние в мониторе порта
  Serial.print(distance);
  Serial.println("см");
      lcd.setCursor(0, 1);
     lcd.print("              ");
     lcd.setCursor(0, 1);
      lcd.print(distance);
      int button = detectButton();
      switch (button) {
        case BTN_UP:
          printDisplay("UP");
          break;
        case BTN_DOWN:
          printDisplay("DOWN");
          break;
        case BTN_LEFT:
          printDisplay("LEFT");
          break;
        case BTN_RIGHT:
          printDisplay("RIGHT");
          break;
        case BTN_SELECT:
          printDisplay("SELECT");
          break;
        default:
          //printDisplay("Press any key");
          break;
      }
    }
