#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class DisplayHandler{

    public:
        DisplayHandler(LiquidCrystal_I2C lcd);
        void update(LiquidCrystal_I2C lcd);
        void display(String lines[4]);
        void clear();
        String lines[4] = {"    SmartBottle    ","     BUILD 0.1a     "," ","  (c) Adam Lamine   "};

    private:
        

};

DisplayHandler::DisplayHandler(LiquidCrystal_I2C lcd){
    
}

void DisplayHandler::update(LiquidCrystal_I2C lcd){
    lcd.setCursor(0,0);
    for(int i = 0; i < 4; i++){
        lcd.setCursor(0,i);
        lcd.print(lines[i]);
    }
    lcd.setCursor(0,0);
}

void DisplayHandler::display(String lines[4]){
    for(int i = 0; i < 4; i++){
        if(lines[i] != NULL){
            this->lines[i] = lines[i];
        } else {
            this->lines[i] = "                    ";
        }
    }
}

void DisplayHandler::clear(){
    for(int i = 0; i < 4; i++){
            this->lines[i] = "                    ";
    }
}

DisplayHandler displayHandler(lcd);