class Navigator{

    public:
        void change(int direction);
        void click();
        void reset();
        Navigator();

    private:
        int currentMode = 0; // 0 = Hauptmenü, 1 = Submenü, 2 = aktives Subprogramm
        int currentItem;
        int currentSubItem;
        MenuItem menuItems[4][4];
        
};

Navigator::Navigator(){
    menuItems[0][0] = MenuItem();
    menuItems[0][0].setName("Overview      ");

    menuItems[1][0] =  MenuItem();
    menuItems[1][0].setName("Select Drink         ");

    menuItems[2][0] =  MenuItem();
    menuItems[2][0].setName("Mode Select        ");

    menuItems[3][0] =  MenuItem();
    menuItems[3][0].setName("Calibrate          ");
}

void Navigator::change(int direction){

    
    switch (currentMode){
        
        case 0:
            currentItem += direction;
        break;

        case 1:
            currentSubItem += direction;
        break;

        case 2:
        break;

    }

    if(this->currentItem <= 0){this->currentItem = 0;}
    if(this->currentSubItem <= 0){this->currentSubItem = 0;}

    Serial.print("Current Item: ");
    Serial.println(this->currentItem);
    Serial.print("Current SubItem: ");
    Serial.println(this->currentSubItem);

    String lines[4] = {this->menuItems[currentItem][currentSubItem].getName(), "Test2", "Test3", "Test4"};

    displayHandler.display(lines);
}

void Navigator::reset(){
    
    switch (currentMode){
        
        case 0:
            currentMode = 0;
            currentSubItem = 0;
        break;
        case 1:
            currentMode = 0;
            currentSubItem = 0;
        break;

        case 2:
            currentMode = 1;
        break;
    }

}

void Navigator::click(){

    switch (currentMode){
        
        case 0:
            currentMode = 1;
        break;

        case 1:
            if(false){ //TODO: In Subroutine kann nur geschalten werden, wenn eine verfügbar ist.
                currentMode = 2;
            }
        break;

        case 2:
        break;

    }

}