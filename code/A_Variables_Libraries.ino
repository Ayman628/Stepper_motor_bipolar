/* Introduction:
 *  Project to drive a bibolar stepper motor using buttons or rotary encoder.
 *  In addition we'll add a display.
*
/******************************************** Display **********************************************/
// Libraries For display
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Stepper.h>

// Variables For Display
#define SCREEN_WIDTH 128                  // OLED display width, in pixels
#define SCREEN_HEIGHT 64                  // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3D               // See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);


/******************************************** Rotary **********************************************/
// Buttons PINs
int Buttons[] = {9, 10, 11, 12, 8};       // an array of pin numbers to which Buttons are attached
int pinCount = 5;                         // the number of pins (i.e. the length of the array)

int button_State_1;                       // the current reading from the input pin 9
int button_State_2;                       // the current reading from the input pin 10
int button_State_3;                       // the current reading from the input pin 11
int button_State_4;                       // the current reading from the input pin 12

int button_State_5;                       // the current reading from the input pin 12
int lastButtonState_5 = HIGH;             // the previous reading from the input pin 12

int lastButtonState_1 = HIGH;             // the previous reading from the input pin 9
int lastButtonState_2 = HIGH;             // the previous reading from the input pin 10
int lastButtonState_3 = HIGH;             // the previous reading from the input pin 11
int lastButtonState_4 = HIGH;             // the previous reading from the input pin 12

int Direction = 0;
int Steps = 0;
int Speed = 0;
int MODE = 0;

bool Active_Menu = false;
int Select;

/******************************************* Stepper **********************************************/
char *MODES[] = {"CONT", "ONCE"};
char *DIRECTIONS[] = {"RIGHT","LEFT"};
// Motor PINs 
int motorPins[] = {2, 3, 4, 5};        // an array of pin numbers to which motorPins are attached
int pinCount_1 = 4;                    // the number of pins (i.e. the length of the array)
bool Start = false;
int last_step = 0;


/******************************************** Timer **********************************************/

unsigned long debounceDelay = 50;     
static unsigned long HmiUpdate = 100;
static unsigned long MenuUpdate = 100;

unsigned long previousMillis = 0;      
const long interval_ = 100;            
