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

    
  if(navigator.getCurrentItem() == 0){
    displayStats();
  }

  doSubroutine();


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

  
  lcd.setCursor(15, 1);
  lcd.print(drinkConsumed);
  lcd.setCursor(19, 1);
  lcd.print("L");

  if(alcoholConsumed < 10){
  lcd.setCursor(16, 2);
  } else {
  lcd.setCursor(15, 2);
  }

  lcd.print(alcoholConsumed);
  lcd.setCursor(17,2);
  lcd.print("/");
  lcd.setCursor(18,2);
  lcd.print(alcoholGoal);
  lcd.setCursor(9, 3);
  
  String tempDrinkName = drinkName.substring(0,3);
  tempDrinkName.toUpperCase();
  lcd.setCursor(10,3);
  lcd.print(tempDrinkName);
  
  int weight = (int) loadCell.getWeight();

  if(weight < 10){
  lcd.setCursor(14,3);
  lcd.print("   ");
  } else if (weight < 100){
  lcd.setCursor(14,3);
  lcd.print("  ");
  } else if (weight < 1000){
  lcd.setCursor(14,3);
  lcd.print(" ");
  } else {
  lcd.setCursor(14,3);
  }
  
  lcd.print(weight);

  lcd.setCursor(18,3);
  lcd.print("ml");


}

void doSubroutine(){
    
    switch(navigator.getSubRoutine()){

        case 0:
        break;

        case 1: //GETRAENKEWAHL BESTAETIGEN
          MenuItem currentItem = navigator.getSelectedItem();
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Getraenk gewaehlt:");
          lcd.setCursor(6, 2);
          lcd.print(currentItem.getName());
          lcd.setCursor(6, 3);
          lcd.print(currentItem.getAlcoholPercentage());
          lcd.print("% alc");
          delay(1500);

          navigator.setSubRoutine(0);
          navigator.reset();
          
          alcoholPercentage = currentItem.getAlcoholPercentage();
          drinkName = currentItem.getName();
         break;

        default:
        navigator.setSubRoutine(0);
        break;






    }


}