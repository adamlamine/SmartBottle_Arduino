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

  displaySplashScreen();

}

void loop() {
    encoder.update();
    navigator.navigate();

    
  if(navigator.getCurrentItem() == 0){
    displayStats();
  }
}

void displaySplashScreen(){
  String initialLines[4] = {"    SmartBottle    ","     BUILD 0.1a     "," ","  (c) Adam Lamine   "};
  displayHandler.display(initialLines);
  displayHandler.update(lcd);
  delay(2000);
  lcd.setCursor(0,0);
  displayHandler.clear();
  displayHandler.update(lcd);
  delay(500);
  navigator.navigate();
  lcd.setCursor(0,1);
  displayHandler.update(lcd);
}

void displayStats(){
  lcd.setCursor(10, 1);
  lcd.print(drinkConsumed);
  lcd.setCursor(13, 1);
  lcd.print("L");
  lcd.setCursor(17, 1);
  lcd.print(drinkName);
  lcd.setCursor(15, 2);
  lcd.print(alcoholConsumed);
  lcd.setCursor(17,2);
  lcd.print("/");
  lcd.setCursor(18,2);
  lcd.print(alcoholGoal);
  lcd.setCursor(13,3);
  lcd.print(loadCell.getWeight());
  lcd.setCursor(17,3);
  lcd.print("/");
  lcd.print("1k");
}