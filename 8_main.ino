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

  doSubroutine(0);

  volatilityTimer();
  // Serial.println(drinkName);
}

void displaySplashScreen(){
  String initialLines[4] = {"    SmartBottle    ","     BUILD 0.1a     "," ","  (c) Adam Lamine   "};
  displayHandler.display(initialLines);
  displayHandler.update(lcd);
  delay(2000);
  lcd.setCursor(0,0);
  navigator.navigate();
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

void doSubroutine(int input){

    
    switch( navigator.getSubRoutine() ){
        
        
        
        case 0:
        break;

        case 1: //GETRAENKEWAHL BESTAETIGEN
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Getraenk gewaehlt:");
          lcd.setCursor(6, 2);
          lcd.print(navigator.getSelectedItem().getName());
          lcd.setCursor(6, 3);
          lcd.print(navigator.getSelectedItem().getAlcoholPercentage());
          lcd.print("% alc");
          delay(1500);

          alcoholPercentage = navigator.getSelectedItem().getAlcoholPercentage();
          drinkName = navigator.getSelectedItem().getName();
          
          navigator.setSubRoutine(0);
          navigator.reset();
        break;
      
        case 2: //MIXING ASSISTANT

          if(!mixingAssistantStarted){
            baseWeight = (int) loadCell.getWeight();
            mixingAssistantStarted = true;
          }

          int currentWeight = (int) loadCell.getWeight();

          //STATISCHER TEXT
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("MIXING: ");
          lcd.print(navigator.getSelectedItem().getName());
          lcd.setCursor(5, 1);
          lcd.print("Bitte noch ");
          lcd.setCursor(4, 3);
          lcd.print("hinzufuegen");

          //REZEPT
          
          int remaining = ( (baseWeight + 80) - currentWeight );

          if(navigator.getSelectedItem().getName() == "Gin Tonic"){
          

          }
          
        break;
    }
}




void checkVolatility(){
  static int lastWeight = 0;
  static int volatilityCounter = 3;
  static int volatilityTreshold = 7;
  static int volatilityMeasurements = 4;

  int currentWeight = (int) loadCell.getWeight();

  if( abs(currentWeight - lastWeight) < volatilityTreshold){
    volatilityCounter++;
  } else {
    volatilityCounter = 0;
  }

  if(volatilityCounter > volatilityMeasurements || lastWeight == 0){
    // Serial.println("SYSTEM STABIL!");
    weight = currentWeight;
    updateConsumed();
  } else {
    // lcd.clear();
    // lcd.setCursor(3,0);
    //lcd.print("ERSCHUETTERUNG");
    // lcd.setCursor(6,1);
    //lcd.print("ERKANNT");
    // lcd.setCursor(3,2);
    //lcd.print("NICHT TRINKEN.");
    // delay(1000);
    // lcd.clear();
    // navigator.navigate();
  }
  lastWeight = currentWeight;
}


void volatilityTimer(){
	static int lastTime = 0;

	if(millis() - lastTime >= 1000)
	{
		lastTime += 1000;
    checkVolatility();
	}
}


int lastWeightMeasurement;

void updateConsumed(){

    static int lastWeightMeasurement = -1;
    
    if(lastWeightMeasurement != -1 && lastWeightMeasurement > weight && abs(lastWeightMeasurement - weight) > 5){
        float difference = lastWeightMeasurement - weight;
        drinkConsumed += (difference/1000);

        alcoholConsumed += (difference/100) * alcoholPercentage;
    } 

    lastWeightMeasurement = weight;
    
}