#include <ClickEncoder.h>
#include <TimerOne.h>

class Encoder{

    public:
        Encoder(int CLK_PIN, int DT_PIN, int SW_PIN);
        void timerTick();
        void setValue(int value);
        int getValue();
        void update();


    private:
        ClickEncoder *encoder;
        int CLK_PIN;
        int DT_PIN;
        int SW_PIN;
        int encoderValue;
        int oldEncoderValue;


};

Encoder::Encoder(int CLK_PIN, int DT_PIN, int SW_PIN){
    this->CLK_PIN = CLK_PIN;
    this->DT_PIN = DT_PIN;
    this->SW_PIN = SW_PIN;
    this->encoder = new ClickEncoder(DT_PIN, CLK_PIN, SW_PIN, 4);
    this->encoder->setAccelerationEnabled(false);
    this->oldEncoderValue = 0;
    this->encoderValue = 0;
}

void Encoder::timerTick(){
    this->encoder->service();
}

int Encoder::getValue(){
    return this->encoderValue;
}

void Encoder::setValue(int value){
    this->encoderValue = value;
}

void Encoder::update(){

    ClickEncoder::Button button = this->encoder->getButton();
    this->encoderValue += this->encoder->getValue();

    if(this->encoderValue != this->oldEncoderValue){
        
        if(this->oldEncoderValue > this->encoderValue){
            encoderRotated(1);
        } else {
            encoderRotated(-1);
        }
        this->oldEncoderValue = this->encoderValue;
    }
    
    switch(button){
        case (ClickEncoder::Clicked):
            buttonClicked();
        break;

        case (ClickEncoder::Held):
            buttonHeld();
        break;

        default:
        break;

    }





}
