void loop() {

unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval_) {
   previousMillis = currentMillis;
   
   Active_Settings();
   Navigate();
   Increment();
   Decrement();
   Start_Motor();
}

   if (Active_Menu == false) {
      HMI();
    } else {
      Settings();
    }

 
  STEPPER_MOTOR(Speed, Direction, MODE, Steps);

}
