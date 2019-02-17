class MenuItem{

    public:
        MenuItem();
        void display();
        void setName(String name);
        String getName();
        boolean hasSubroutine();
        boolean isSelectable();
        void setSubroutine(int subroutine);
        void setSelectable(boolean selectable);
        int getSubroutine();
        
    private:
        String name = "";
        boolean selectable = false;
        int subroutine;

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

void MenuItem::setSubroutine(int subroutine){
    this->subroutine = subroutine;
};

void MenuItem::setSelectable(boolean selectable){
    this->selectable = selectable;
};

int MenuItem::getSubroutine(){
    return this->subroutine;
};
