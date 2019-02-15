LoadCell loadCell(6, 5, 385); //DT, SCK, calibrationFactor
Encoder encoder(A0, A1, A2);




int SDA_PIN = 4;
int SCL_PIN = 5;

void timerTick(){
  encoder.timerTick();
}

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerTick);
  
  lcd.begin(20, 4);
  lcd.clear();
  
}

void loop() {
    encoder.update();
    displayHandler.update(lcd);
}



