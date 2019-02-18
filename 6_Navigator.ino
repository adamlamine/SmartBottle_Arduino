class Navigator{

    public:
        int getCurrentItem();
        int getCurrentSubItem();
        int getSubRoutine();
        MenuItem getSelectedItem();
        void change(int direction);
        void click();
        void reset();
        void navigate();
        void setMode(int mode);
        void setSubRoutine(int subRoutine);
        Navigator();
        int currentMode = 0; // 0 = Hauptmenü, 1 = Submenü, 2 = aktives Subprogramm

    private:
        int currentItem = 0;
        int currentSubItem = 0;
        int subRoutine = 0;
        MenuItem menuItems[5][4];
        
};


Navigator::Navigator(){

    //MAIN MENU
    menuItems[0][0] = MenuItem();
    menuItems[0][0].setName("<     OVERVIEW     >");

    menuItems[1][0] =  MenuItem();
    menuItems[1][0].setName("<   SELECT DRINK   >");

    menuItems[2][0] =  MenuItem();
    menuItems[2][0].setName("< MIXING ASSISTANT >");

    menuItems[3][0] =  MenuItem();
    menuItems[3][0].setName("<      SETUP       >");

    //SUB MENU - OVERVIEW
    menuItems[0][1] =  MenuItem();
    menuItems[0][1].setName("Getrunken:");

    menuItems[0][2] =  MenuItem();
    menuItems[0][2].setName("Alkoholpegel:");

    menuItems[0][3] =  MenuItem();
    menuItems[0][3].setName("Flasche:");

    //SUB MENU - SELECT DRINK
    menuItems[1][1] =  MenuItem();
    menuItems[1][1].setName("Wasser");
    menuItems[1][1].setSubRoutine(1);
    menuItems[1][1].setAlcoholPercentage(0);

    menuItems[1][2] =  MenuItem();
    menuItems[1][2].setName("Spritzer");
    menuItems[1][2].setSubRoutine(1);
    menuItems[1][2].setAlcoholPercentage(5.2);

    menuItems[1][3] =  MenuItem();
    menuItems[1][3].setName("Gin Tonic");

    menuItems[1][3].setSubRoutine(1);
    menuItems[1][3].setAlcoholPercentage(9.5);

    //SUB MENU - MIXING ASSISTANT
    menuItems[2][1] =  MenuItem();
    menuItems[2][1].setName("Gin Tonic");
    menuItems[2][1].setSubRoutine(2);

    menuItems[2][2] =  MenuItem();
    menuItems[2][2].setName("Long Island");
    menuItems[2][2].setSubRoutine(2);

    menuItems[2][3] =  MenuItem();
    menuItems[2][3].setName("Whisky Sour");
    menuItems[2][3].setSubRoutine(2);
    

    //SUB MENU - SETUP
    menuItems[3][1] =  MenuItem();
    menuItems[3][1].setName("Goal");

    menuItems[3][2] =  MenuItem();
    menuItems[3][2].setName("Tara");

    menuItems[3][3] =  MenuItem();
    menuItems[3][3].setName("Calibration");


}

int Navigator::getCurrentItem(){
    return this->currentItem;
}

int Navigator::getCurrentSubItem(){
    return this->currentSubItem;
}

void Navigator::setMode(int mode){
    this->currentMode = mode;
}

void Navigator::setSubRoutine(int subRoutine){
    this->subRoutine = subRoutine;
}

int Navigator::getSubRoutine(){
    return this->subRoutine;
}

void Navigator::change(int direction){

    

    switch (currentMode){
        
        case 0:
            lcd.clear();
            currentItem += direction;
            navigate();
        break;

        case 1:
            currentSubItem += direction;
            navigate();
        break;

        case 2:
        break;

    }


    
    
}

MenuItem Navigator::getSelectedItem(){
    return this->menuItems[this->currentItem][this->currentSubItem];
}

void Navigator::navigate(){

    if(this->currentItem < 0){this->currentItem = 3;}
    if(this->currentSubItem < 0){this->currentSubItem = 3;}
    if(this->currentSubItem <= 0 && this->currentMode == 1){this->currentSubItem = 3;}

    if(this->currentItem >= 4){this->currentItem = 0;}
    if(this->currentSubItem >= 4){this->currentSubItem = 1;}

    String arrow = "->";



    String line0 = this->menuItems[currentItem][0].getName();
    String line1 = this->menuItems[currentItem][1].getName();
    String line2 = this->menuItems[currentItem][2].getName();
    String line3 = this->menuItems[currentItem][3].getName();

    if(this->currentSubItem == 0){
        line0.setCharAt(0, '<');
        line0.setCharAt(19, '>');
    } else {
        line0.setCharAt(0, ' ');
        line0.setCharAt(19, ' ');
    }

    if(currentSubItem == 1){
        line1 = arrow + line1;
    } else if (currentSubItem == 2){
        line2 = arrow + line2;
    } else if (currentSubItem == 3){
        line3 = arrow + line3;
    }


    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print(line0);
    lcd.setCursor(0,1);
    lcd.print(line1);
    lcd.setCursor(0,2);
    lcd.print(line2);
    lcd.setCursor(0,3);
    lcd.print(line3);
    
    lcd.setCursor(0,0);
    mixingAssistantStarted = false;

    //HIER RUHT DIE SAUBERE LÖSUNG STRINGS ANZUZEIGEN. ICH VERSTEHE CPP STRING HANDLING LEIDER NICHT :(
    // String lines[4] = {
    //                     this->menuItems[currentItem][0].getName(),
    //                     this->menuItems[currentItem][1].getName(),
    //                     this->menuItems[currentItem][2].getName(),
    //                     this->menuItems[currentItem][3].getName()
    //                   };

    // for(int i = 0; i < 4; i++){
    //     if(i == currentSubItem && currentSubItem != 0){
    //         lines[i] = arrow + this->menuItems[currentItem][i].getName();
    //     } else {
    //         lines[i] = this->menuItems[currentItem][i].getName();
    //     }
    // }

    // if(this->currentSubItem == 0){
    //     lines[0].setCharAt(0, '<');
    //     lines[0].setCharAt(19, '>');
    // } else {
    //     lines[0].setCharAt(0, ' ');
    //     lines[0].setCharAt(19, ' ');
    // }

    // for(int i = 0; i < 4; i++){
    //     lcd.setCursor(0, i);
    //     lcd.print(lines[i]);
    // }
    
}


void Navigator::reset(){
    
    // switch (currentMode){

        // case 0:
        //     currentSubItem = 0;
        // break;
        
        // case 1:
        //     currentSubItem = 0;
        // break;

        // case 2:
        //     currentSubItem = 0;
        // break;

        // default:
        //     currentSubItem = 0;
        // break;
    // }

    this->currentMode = 0;
    this->currentSubItem = 0;
    this->subRoutine = 0;
    
    mixingAssistantStarted = false;

    lcd.clear();
    this->navigate();
}

void Navigator::click(){

    MenuItem selectedItem = this->menuItems[this->currentItem][this->currentSubItem];

    switch (currentMode){
        
        case 0:
            if(this->currentItem != 0){
                currentMode = 1;
                currentSubItem = 1;
            }
        break;

        case 1:
            if(selectedItem.hasSubroutine()){
                currentMode = 2;
                this->subRoutine = selectedItem.getSubroutine();
            }
        break;

        case 2:
        break;
    }
    
}