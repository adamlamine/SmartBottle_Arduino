Navigator navigator;

void buttonClicked(){
    navigator.click();
}

void buttonHeld(){
    navigator.reset();
}

void encoderRotated(int direction){
    navigator.change(direction);
}