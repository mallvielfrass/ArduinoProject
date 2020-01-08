    #include <NewPing.h>
    #include <Wire.h>
    #include <BH1750.h>
    BH1750 lightMeter;
    #define PIN_TRIG 12
    #define PIN_ECHO 11
    #define LED 10
    #define MAX_DISTANCE 400 // Константа для определения максимального расстояния, которое мы будем считать корректным.
    // Создаем объект, методами которого будем затем пользоваться для получения расстояния.
    // В качестве параметров передаем номера пинов, к которым подключены выходы ECHO и TRIG датчика
    NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);
    void setup() {
      // Инициализируем взаимодействие по последовательному порту на скорости 9600
      Serial.begin(9600);
      lightMeter.begin();
      pinMode(LED , OUTPUT);
    }
     int minMax( int temp1,int temp2,int* n1,int* n2){
      
      int temp3=0;
      if (temp1>=temp2){
        temp3=temp1;
        temp1=temp2;
        temp2=temp3;
        }
      
      *n1=temp1;
      *n2=temp2;
      return 0;
      }
    void loop() {
      // Стартовая задержка, необходимая для корректной работы.
      delay(50);
      // Получаем значение от датчика расстояния и сохраняем его в переменную
      unsigned int distance = sonar.ping_cm();
      // Печатаем расстояние в мониторе порта
      if (distance!=0){
        if (distance<=240){
        uint16_t lux = lightMeter.readLightLevel();
 // Serial.print("Light: ");
  //Serial.print(lux);
          if (lux<200){
            int x1=distance;
            delay(70);
            int x2=sonar.ping_cm();
          //delay(70);
         // int x3=distance;
          //delay(70);
            int n1, n2, n3;
            n1=0;
            n2=0;
            minMax(x1,x2, &n1, &n2);
            n3=n2-n1;
            if(n3<15){
                  digitalWrite(LED,1);
                  delay(15000);
                  digitalWrite(LED,0);
                }
            }
        }
      }
      Serial.print(distance);
      Serial.println("см");
    }
