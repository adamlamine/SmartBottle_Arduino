Navigator navigator;

void buttonClicked(){
    navigator.click();
    navigator.change(0);
}

void buttonHeld(){
    navigator.reset();
    navigator.change(0);
}

void encoderRotated(int direction){
    navigator.change(direction);
}