class MenuItem{

    public:
        MenuItem();
        void display();
        void setName(String name);
        String getName();
        void hover();
        void dehover();
        boolean hoverState = false;
        boolean getHover();
        
    private:
        String name = "Empty Menu";

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

void MenuItem::hover(){
    this->hoverState = true;
    String tempName = "->";
    this -> name = tempName + this->name;
    this -> name.remove(19,2);
}

void MenuItem::dehover(){
    this->hoverState = false;
    this->name.remove(0,2);
}

boolean MenuItem::getHover(){
    return this->hoverState;
}