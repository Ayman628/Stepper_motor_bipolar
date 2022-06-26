// Function to enter inside the menu
void Active_Settings(){
  static unsigned long lastDebounceTime_1;                          // the last time the output pin was toggled
  
  int read_1 = digitalRead(Buttons[3]);
  
  if (read_1 != lastButtonState_1) {
      lastDebounceTime_1 = millis();
  }

   if (millis() + lastDebounceTime_1 >= debounceDelay) {
     
     if (read_1 != button_State_1) {                                // if the button state has changed:
         button_State_1 = read_1;  

      if (button_State_1 == LOW) {                                  // only toggle the variable if the new button state is HIGH
          Active_Menu =! Active_Menu;
      }
    }
  }
}
// Function to navigate in the menu
void Navigate(){
  static unsigned long lastDebounceTime_2;                          // the last time the output pin was toggled
  int read_2 = digitalRead(Buttons[2]);
  
  if (read_2 != lastButtonState_2) {
      lastDebounceTime_2 = millis();
  }

   if (millis() + lastDebounceTime_2 >= debounceDelay) {
     
     if (read_2 != button_State_2) {                                // if the button state has changed:
         button_State_2 = read_2;  

      if (button_State_2 == LOW) {                                  // only toggle the variable if the new button state is HIGH
          Select = Select + 1;
      }
    }
  }
  if (Select == 4){
    Select = 0;
    }
}
// Function to increment the values
void Increment(){
  static unsigned long lastDebounceTime_3;                          // the last time the output pin was toggled

  int read_3 = digitalRead(Buttons[1]);
   if (read_3 != lastButtonState_3) {
      lastDebounceTime_3 = millis();
  }
   if (millis() + lastDebounceTime_3 >= debounceDelay) {
     
     if (read_3 != button_State_3) {                                // if the button state has changed:
         button_State_3 = read_3;   
         }
         
          switch(Select){
            case 0:
              if (Active_Menu == HIGH && Select == 0 && button_State_3 == LOW){Direction = Direction + 1;}
              if (Direction > 1){Direction = 0;}
              break;
              
            case 1:
              if (Active_Menu == HIGH && Select == 1 && button_State_3 == LOW ){Steps = Steps + 1;}
              if (Steps > 200){Steps = 0;}
              break;
        
            case 2:
              if (Active_Menu == HIGH && Select == 2 && button_State_3 == LOW ){Speed = Speed + 1;}
              if (Speed > 100){Speed = 0;}
              break;
        
            case 3:
              if (Active_Menu == HIGH && Select == 3 && button_State_3 == LOW ){MODE = MODE + 1;}
              if (MODE > 1){MODE = 0;}
              break;
    }
  }
}
// Function to Decrement the values
void Decrement(){
   static unsigned long lastDebounceTime_4;                         // the last time the output pin was toggled
   int read_4 = digitalRead(Buttons[0]);
   if (read_4 != lastButtonState_4) {
      lastDebounceTime_4 = millis();
  }
   if (millis() + lastDebounceTime_4 >= debounceDelay) {
     
     if (read_4 != button_State_4) {                                // if the button state has changed:
         button_State_4 = read_4;  
     }
      switch(Select){
        case 0:
          if (Active_Menu == HIGH && Select == 0 && button_State_4 == LOW){Direction = Direction - 1;}
          if (Direction < 0){Direction = 1;}
          break;
          
        case 1:
          if (Active_Menu == HIGH && Select == 1 && button_State_4 == LOW ){Steps = Steps - 1 ;}
          if (Steps < 0){Steps = 200;}
          break;
    
        case 2:
          if (Active_Menu == HIGH && Select == 2 && button_State_4 == LOW ){Speed = Speed - 1;}
          if (Speed < 0){Speed = 100;}
          break;
    
        case 3:
          if (Active_Menu == HIGH && Select == 3 && button_State_4 == LOW ){MODE = MODE - 1;}
          if (MODE < 0){MODE = 1;}
          break;
    }
  }
}
// Function to put motor on/off
void Start_Motor(){
  static unsigned long lastDebounceTime_5;
  int read_5 = digitalRead(Buttons[4]);
  
  if (read_5 != lastButtonState_5) {
      lastDebounceTime_5 = millis();
  }

   if (millis() + lastDebounceTime_5 >= debounceDelay) {
     
     if (read_5 != button_State_5) {                                // if the button state has changed:
         button_State_5 = read_5;  

      if (button_State_5 == LOW) {                                  // only toggle the LED if the new button state is HIGH
          Start =! Start;
      }
    }
  }
}
