class MenuItem{

    public:
        MenuItem();
        void display();
        void setName(String name);
        String getName();
        boolean hasSubroutine();
        boolean isSelectable();
        void setSubRoutine(int subroutine);
        void setSelectable(boolean selectable);
        int getSubroutine();
        float getAlcoholPercentage();
        void setAlcoholPercentage(float alcoholPercentage);
        
    private:
        String name = "";
        boolean selectable = false;
        int subroutine = 0;
        float alcoholPercentage = 0;

};

MenuItem::MenuItem(){
}

void MenuItem::display(){
}

void MenuItem::setName(String name){
    this->name = name;
}

String MenuItem::getName(){
    return this->name;
}

boolean MenuItem::hasSubroutine(){
    if(this->subroutine != 0){
        return true;
    } else {
        return false;
    }
};

boolean MenuItem::isSelectable(){
    return this->selectable;
};

void MenuItem::setSubRoutine(int subroutine){
    this->subroutine = subroutine;
};

void MenuItem::setSelectable(boolean selectable){
    this->selectable = selectable;
};

int MenuItem::getSubroutine(){
    return this->subroutine;
};

float MenuItem::getAlcoholPercentage(){
    return this->alcoholPercentage;
};

void MenuItem::setAlcoholPercentage(float alcoholPercentage){
    this->alcoholPercentage = alcoholPercentage;
}