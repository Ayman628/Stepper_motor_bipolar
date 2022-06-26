// A very small State Machine
void STEPPER_MOTOR(int whatSpeed, int whatDirection, int what_MODE, int How_many_Steps) {

   // map whatSped variable between 1...100 milliseconds 
   int VAL = map(whatSpeed, 0, 100, 100, 1);

    // Delay until Stepper motor Starts
    static uint16_t MOTORDelay;

    // Timer for notification process has completed
    static unsigned long STEP1Millis;
    static unsigned long STEP2Millis;
    static unsigned long STEP3Millis;
    static unsigned long STEP4Millis;

    // Declare the states in meaningful English. Enums start enumerating
    // at zero, incrementing in steps of 1 unless overridden. We use an
    // enum 'class' here for type safety and code readability
    enum class MOTORState : uint8_t {
        STAND_BY,  // defaults to 0
        STEP_1,    // defaults to 1
        STEP_2,    // defaults to 2
        STEP_3,    // defaults to 3
        STEP_4,    // defaults to 4
    };

    // Keep track of the current State (it's an MOTORState variable)
    static MOTORState currState = MOTORState::STAND_BY;
    
    // Process according to our State Diagram
    switch (currState) {

        // Initial state (or final returned state)
        case MOTORState::STAND_BY:
            //Start = false;
            digitalWrite(motorPins[0], LOW);
            digitalWrite(motorPins[1], LOW);
            digitalWrite(motorPins[2], LOW);
            digitalWrite(motorPins[3], LOW);
            

            // Someone pushed the button yet?
            if (Start == true){
                // Set the millis counter for the Motor's first step timer
                STEP1Millis = millis();
                // Not really part of this process, simulates background action
                // Motor's Steps delay from Speed input
                MOTORDelay = VAL;
                // Move to next state
                currState = MOTORState::STEP_1;
            }
            break;

        // First step (1010)
        case MOTORState::STEP_1:
            // Motor's Steps delay from Speed input 
            MOTORDelay = VAL;
            First_step(whatDirection);   

            if (Start != true){
              Start = false;
              currState = MOTORState::STAND_BY;
            }
                        
            // Has the Stepper completed his first Step yet?
            if (millis() - STEP1Millis >= MOTORDelay) {
                // If mode = 0 GO in continue 
                if (what_MODE == 0){
                  // Move to next state
                  currState = MOTORState::STEP_2;
                  STEP2Millis = millis();
                  } 
                  // else Go the number of Steps entered by user 
                  else {
                    // Record step into last_step
                    last_step = last_step + 1;                      
                    // if last_step that was recorded more then or equal to the number of steps entered by user 
                    // Stop motor by return Start variable to false, reset last_step to 0 change case to stand_by 
                    if (last_step >= How_many_Steps){
                        Start = false;
                        last_step = 0;
                        currState = MOTORState::STAND_BY;
                      } 
                      // else continu to next step until you reach the Steps entered by user 
                      else {
                        currState = MOTORState::STEP_2;
                        STEP2Millis = millis();
                      }
                  }
            }
            break;

        // Second step (0110)
        case MOTORState::STEP_2:
            // Motor's Steps delay from Speed input
            MOTORDelay = VAL;
            Second_step(whatDirection);

            if (Start != true){
              Start = false;
              currState = MOTORState::STAND_BY;
            }            
            
            // Has the Stepper completed his Second Step yet?
            if (millis() - STEP2Millis >= MOTORDelay) {
                if (what_MODE == 0){
                  // Move to next state
                  currState = MOTORState::STEP_3;
                  STEP3Millis = millis();   
                } else {
                  // Record step into last_step
                  last_step = last_step + 1;                    
                  if (last_step >= How_many_Steps){
                      Start = false;
                      last_step = 0;
                      currState = MOTORState::STAND_BY;
                    } else {
                     currState = MOTORState::STEP_3;
                     STEP3Millis = millis();                  
                    }          
                }
            }
            break;
            
        //Third step (0101)
        case MOTORState::STEP_3:
            // Motor's Steps delay from Speed input
            MOTORDelay = VAL;
            Third_step(whatDirection);

            if (Start != true){
              Start = false;
              currState = MOTORState::STAND_BY;
            }            
            
            // Has the Stepper completed his theard Step yet?
            if (millis() - STEP3Millis >= MOTORDelay) {
                if (what_MODE == 0){
                  // Move to next state
                  currState = MOTORState::STEP_4;
                  STEP4Millis = millis();   
                } else {
                 // Record step into last_step
                 last_step = last_step + 1; 
                  if (last_step >= How_many_Steps){
                      Start = false;
                      last_step = 0;
                      currState = MOTORState::STAND_BY;
                    } else {
                     currState = MOTORState::STEP_4;
                     STEP4Millis = millis();                   
                    }          
                }    
            }
            break;
            
        // Fourth step (1001)
        case MOTORState::STEP_4:
            // Motor's Steps delay from Speed input
            MOTORDelay = VAL;
            Fourth_step(whatDirection);

            if (Start != true){
              Start = false;
              currState = MOTORState::STAND_BY;
            }            
            
            // Has the Stepper completed his fourth Step yet?
            if (millis() - STEP4Millis >= MOTORDelay) {
                if (what_MODE == 0){
                  // Move to next state
                  currState = MOTORState::STEP_1;
                  STEP1Millis = millis();   
                } else {
                  // Record step into last_step
                  last_step = last_step + 1;   
                  if (last_step >= How_many_Steps){
                      Start = false;
                      last_step = 0;
                      currState = MOTORState::STAND_BY;
                    } else {
                     currState = MOTORState::STEP_1;
                     STEP1Millis = millis();                 
                    }          
                }
            }
            break;
}
}

void First_step(int dir){ 
  if (dir == 0){                      // if... turn in clockwise direction
    digitalWrite(motorPins[0], HIGH);                   
    digitalWrite(motorPins[1], LOW);                    
    digitalWrite(motorPins[2], HIGH);                   
    digitalWrite(motorPins[3], LOW);
  } else {                            // else... turn in anti-clockwise dirction
    digitalWrite(motorPins[0], HIGH);                   
    digitalWrite(motorPins[1], LOW);                    
    digitalWrite(motorPins[2], LOW);                   
    digitalWrite(motorPins[3], HIGH);
  }
            
}
void Second_step(int dir){
  if (dir == 0){                      // if... turn in clockwise direction
    digitalWrite(motorPins[0], LOW);
    digitalWrite(motorPins[1], HIGH);
    digitalWrite(motorPins[2], HIGH);
    digitalWrite(motorPins[3], LOW);
  } else {                            // else... turn in anti-clockwise dirction
    digitalWrite(motorPins[0], LOW);
    digitalWrite(motorPins[1], HIGH);
    digitalWrite(motorPins[2], LOW);
    digitalWrite(motorPins[3], HIGH);
  }
}
void Third_step(int dir){
  if (dir == 0){                      // if... turn in clockwise direction 
    digitalWrite(motorPins[0], LOW);
    digitalWrite(motorPins[1], HIGH);
    digitalWrite(motorPins[2], LOW);
    digitalWrite(motorPins[3], HIGH);
  } else {                            // else... turn in anti-clockwise dirction
    digitalWrite(motorPins[0], LOW);
    digitalWrite(motorPins[1], HIGH);
    digitalWrite(motorPins[2], HIGH);
    digitalWrite(motorPins[3], LOW);
  }
}
void Fourth_step(int dir){
  if (dir == 0){                      // if... turn in clockwise direction
    digitalWrite(motorPins[0], HIGH);
    digitalWrite(motorPins[1], LOW);
    digitalWrite(motorPins[2], LOW);
    digitalWrite(motorPins[3], HIGH);
  } else {                            // else... turn in anti-clockwise dirction
    digitalWrite(motorPins[0], HIGH);
    digitalWrite(motorPins[1], LOW);
    digitalWrite(motorPins[2], HIGH);
    digitalWrite(motorPins[3], LOW);
  }
}
