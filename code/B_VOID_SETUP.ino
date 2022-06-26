void setup() {

  // Setup display
  display.begin(SCREEN_ADDRESS);                     // Initite display with the Address
  Start_with_Bitmap();                               // Show Boot Bitmap
  delay(500);
  //myStepper.setSpeed(60);

  for (int thisPin = 0; thisPin <= pinCount; thisPin++){
    pinMode(Buttons[thisPin], INPUT_PULLUP);
    }
    

  // Setup the PINs of Motor 
  for (int thisPins = 0; thisPins <= pinCount_1 ; thisPins++){
    pinMode(motorPins[thisPins], OUTPUT);
    }

}
