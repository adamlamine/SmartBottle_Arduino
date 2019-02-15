#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class DisplayHandler{

    public:
        DisplayHandler(LiquidCrystal_I2C lcd);
        void update(LiquidCrystal_I2C lcd);
        void display(String lines[4]);
        String lines[4] = {"a","b","c","d"};

    private:
        

};

DisplayHandler::DisplayHandler(LiquidCrystal_I2C lcd){

}

void DisplayHandler::update(LiquidCrystal_I2C lcd){
    
    for(int i = 0; i < 4; i++){
        lcd.setCursor(0,i);
        lcd.print(lines[i]);
        Serial.println(lines[i]);
    }
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


DisplayHandler displayHandler(lcd);