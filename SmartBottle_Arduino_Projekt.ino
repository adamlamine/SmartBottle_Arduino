#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 1, 0);








// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// LoadCell loadCell(6, 5, 385); //DT, SCK, calibrationFactor
// Encoder encoder(A0, A1, A2);
// LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


// class DisplayHandler{

//     public:
//         DisplayHandler(LiquidCrystal_I2C lcd);
//         void update(LiquidCrystal_I2C lcd);

//     private:
//         int a;

// };

// DisplayHandler::DisplayHandler(LiquidCrystal_I2C lcd){
// }

// void DisplayHandler::update(LiquidCrystal_I2C lcd){
    
//     lcd.setCursor(1,0);
//     lcd.print("Aktuelles Gewicht: ");
//     lcd.setCursor(8,2);
//     lcd.print(loadCell.getWeight());

// }


// DisplayHandler displayHandler(lcd);


// int SDA_PIN = 4;
// int SCL_PIN = 5;

// void timerTick(){
//   encoder.timerTick();
// }

// void setup() {
//   Serial.begin(9600);
//   Timer1.initialize(1000);
//   Timer1.attachInterrupt(timerTick);
  
//   lcd.begin(20, 4);
//   lcd.clear();
// }

// void loop() {
//     encoder.update();
//     displayHandler.update(lcd);
// }





    // Serial.println("---------------------------------------");
    // Serial.println("-----------------LINES-----------------");
    // Serial.println("-----------------VVVVV-----------------");
    // Serial.println(lines[0]);
    // Serial.println(lines[1]);
    // Serial.println(lines[2]);
    // Serial.println(lines[3]);
    // Serial.println("---------------------------------------");

    // Serial.println("---------------------------------------");
    // Serial.println("-----------------getName-----------------");
    // Serial.println("-----------------VVVVV-----------------");
    // Serial.println(this->menuItems[currentItem][0].getName());
    // Serial.println(this->menuItems[currentItem][1].getName());
    // Serial.println(this->menuItems[currentItem][2].getName());
    // Serial.println(this->menuItems[currentItem][3].getName());
    // Serial.println("---------------------------------------");