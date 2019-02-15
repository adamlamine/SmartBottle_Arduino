class MenuItem{

    public:
        MenuItem();
        void display();
        void setName(String name);
        String getName();
        
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