Navigator navigator;

void buttonClicked(){
    navigator.click();
    navigator.change(0);
}

boolean lastheld = false;

void buttonHeld(){
    
    if(!lastheld){
        navigator.reset();
        navigator.change(0);
    }

    lastheld = true;
}

void encoderRotated(int direction){
    navigator.change(direction);
}

void buttonReleased(){
    lastheld = false;
}