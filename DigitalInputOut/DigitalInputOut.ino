/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/
    #include <LiquidCrystal.h>
    LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
  //start serial connection
  Serial.begin(9600);
        lcd.begin(16, 2);
      lcd.setCursor(0, 0);
      lcd.print("Arduino Master");
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(10);
  //print out the value of the pushbutton


  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  delay(100);
   lcd.setCursor(0, 1);
      lcd.print(sensorVal);
  if (sensorVal == HIGH) {
    digitalWrite(11, HIGH);
   
   // delay(1000);
  } else {
    digitalWrite(11, LOW);
  }
  
}
