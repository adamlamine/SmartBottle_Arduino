#include "HX711.h"

class LoadCell{
  
  public:
    LoadCell(int DT_PIN, int SCK_PIN, int calibrationFactor);
    void setCalibrationFactor(int calibrationFactor);
    float getWeight();

  private: 
    int DT_PIN;
    int SCK_PIN;
    int calibrationFactor;
    HX711 scale;
};

LoadCell::LoadCell(int DT_PIN, int SCK_PIN, int calibrationFactor){
  this->DT_PIN = DT_PIN;
  this->SCK_PIN = SCK_PIN;
  this->calibrationFactor = calibrationFactor;
  this->scale = HX711(DT_PIN, SCK_PIN);
  
  this->scale.set_scale(calibrationFactor);
  this->scale.tare();
}

void LoadCell::setCalibrationFactor(int calibrationFactor){
  this->calibrationFactor = calibrationFactor;
}

float LoadCell::getWeight(){

  float weight = this->scale.get_units(4);

  if (weight < 0) {
    return 0;
  } else {
    return weight;
  }
  
}
