#include<PS2X_lib.h>

                                          // Includes the Psx Librar                                                     // Any pins can be used since it is done in software
#define PS2_DAT        6  //14    
#define PS2_CMD        7  //15
#define PS2_SEL        8  //16
#define PS2_CLK        9  //17
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false


int a=13;
int b=12;
int c=11;
int d=10;
int error = 0;                              // Initializes the library

unsigned int data = 0;                                    // data stores the controller response
PS2X ps2x;
void setup()
{
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);// Defines what each pin is used
                                                          // (Data Pin #, Cmnd Pin #, Att Pin #, Clk Pin #, Delay)
                                                          // Delay measures how long the clock remains at each state,
                                                          // measured in microseconds.
                                                          // too small delay may not work (under 5 
  pinMode(b, OUTPUT);  
  pinMode(a, OUTPUT);
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT);

  Serial.begin(9600);
  delay(30); 
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);

  
}

void loop()
{
   digitalWrite(b, HIGH);
ps2x.read_gamepad();                                      // Psx.read() initiates the PSX controller and returns
                                                          // the button data
  if (ps2x.Button(PSB_PAD_LEFT))                                       // If the data anded with a button's hex value is true,
                                                          // it signifies the button is pressed. Hex values for each
                                                          // button can be found in Psx.h
  {
    Serial.println("left");
    
     digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);

                          // If button is pressed, turn on the LED
  }
  else if (ps2x.Button(PSB_PAD_UP))                                       // If the data anded with a button's hex value is true,
                                                          // it signifies the button is pressed. Hex values for each
                                                          // button can be found in Psx.h
  {
      Serial.println("up");
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);

  }
  else if (ps2x.Button(PSB_PAD_DOWN))                                       // If the data anded with a button's hex value is true,
                                                          // it signifies the button is pressed. Hex values for each
                                                          // button can be found in Psx.h
  {
      Serial.println("down");
   digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);

  }
  else if (ps2x.Button(PSB_PAD_RIGHT))                                       // If the data anded with a button's hex value is true,
                                                          // it signifies the button is pressed. Hex values for each
                                                          // button can be found in Psx.h
  {Serial.println("right");
   digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);

  }
  else
  {
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);

  }
  delay(20);
}
