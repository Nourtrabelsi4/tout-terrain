//#include <SoftwareSerial.h> 
#include<PS2X_lib.h>
//char junk;
//String inputString="";
#define PS2_DAT        12  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        13  //17

//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false


 int i=0;

int error = 0; 


unsigned int data = 0;                                    // data stores the controller response
PS2X ps2x;
//1:avant
//2:arrière
//moteur droite
//1:avant
int md1f=2;
int md1b=3;
//2:arrière
int md2f=8;
int md2b=9;
//moteur gauche
//1:avant
int mg1b=4;
int mg1f=5;
//2:arrière
int mg2f=7;
int mg2b=6;
                                                      

void stop1()
{
  //moteur droit
  //1 
digitalWrite(md1b,LOW );
digitalWrite(md1f, LOW); 
//2
digitalWrite(md2b,LOW );
digitalWrite(md2f, LOW); 

//moteur gauche
//1
digitalWrite(mg1b, LOW);
digitalWrite(mg1f, LOW); 
//2
digitalWrite(mg2b, LOW);
digitalWrite(mg2f, LOW); 
}
//////////////////////////////////////////
void forward()
{
//moteur droit
//1
digitalWrite(md1b,LOW );
digitalWrite(md1f, HIGH); 
//2
digitalWrite(md2b,LOW );
digitalWrite(md2f, HIGH); 

//moteur gauche
//1
digitalWrite(mg1b, LOW);
digitalWrite(mg1f, HIGH); 
//2
digitalWrite(mg2b, LOW);
digitalWrite(mg2f, HIGH); 
}
//////////////////////////////////////////
void backward()
{
 //moteur droit
  //1
digitalWrite(md1b,HIGH );
digitalWrite(md1f, LOW); 
//2
digitalWrite(md2b,HIGH );
digitalWrite(md2f, LOW); 

//moteur gauche
//1
digitalWrite(mg1b, HIGH);
digitalWrite(mg1f, LOW); 
//2
digitalWrite(mg2b, HIGH);
digitalWrite(mg2f, LOW); 

}
//////////////////////////////////////////////
void right()
{
//moteur droit
//1
digitalWrite(md1b,HIGH );
digitalWrite(md1f, LOW); 
//2
digitalWrite(md2b,HIGH );
digitalWrite(md2f, LOW); 

//moteur gauche
//1
digitalWrite(mg1b, LOW);
digitalWrite(mg1f, HIGH); 
//2
digitalWrite(mg2b, LOW);
digitalWrite(mg2f, HIGH);  
}
////////////////////////////////////////////////
void left()
{
//moteur droit

//1
digitalWrite(md1b,LOW );
digitalWrite(md1f, HIGH); 
//2
digitalWrite(md2b,LOW );
digitalWrite(md2f, HIGH); 

//moteur gauche
//1
digitalWrite(mg1b, HIGH);
digitalWrite(mg1f, LOW); 
//2
digitalWrite(mg2b, HIGH);
digitalWrite(mg2f, LOW); 
}
/*
void forwardleft()
{
//moteur droit
//1
digitalWrite(md1b,LOW );
digitalWrite(md1f, HIGH); 
//2
digitalWrite(md2b,LOW );
digitalWrite(md2f, HIGH); 

//moteur gauche
//1
digitalWrite(mg1b, LOW);
digitalWrite(mg1f, LOW); 
//2
digitalWrite(mg2b, LOW);
digitalWrite(mg2f, LOW); 

}

void forwardright()
{
   //moteur droit
  //1
digitalWrite(md1b,LOW );
digitalWrite(md1f, LOW); 
//2
digitalWrite(md2b,LOW );
digitalWrite(md2f, LOW); 

//moteur gauche
//1
digitalWrite(mg1b, LOW);
digitalWrite(mg1f, HIGH); 
//2
digitalWrite(mg2b, LOW);
digitalWrite(mg2f, HIGH); 

}

void backwardright()
{
   //moteur droit
  //1
digitalWrite(md1b,LOW );
digitalWrite(md1f, LOW); 
//2
digitalWrite(md2b,LOW );
digitalWrite(md2f, LOW); 

//moteur gauche
//1
digitalWrite(mg1b, HIGH);
digitalWrite(mg1f, LOW); 
//2
digitalWrite(mg2b, HIGH);
digitalWrite(mg2f, LOW); 

}
void backwardleft()
{
   //moteur droit
  //1
digitalWrite(md1b,HIGH);
digitalWrite(md1f, LOW); 
//2
digitalWrite(md2b,HIGH );
digitalWrite(md2f, LOW); 

//moteur gauche
//1
digitalWrite(mg1b, LOW);
digitalWrite(mg1f, LOW); 
//2
digitalWrite(mg2b, LOW);
digitalWrite(mg2f, LOW); 
}
*/

void setup() 
{   
 Serial.begin(9600); 
 //bluetooth.begin(9600);

  // put your setup code here, to run once:
   error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);// Defines what each pin is used
                                                          // (Data Pin #, Cmnd Pin #, Att Pin #, Clk Pin #, Delay)
                                                          // Delay measures how long the clock remains at each state,
                                                          // measured in microseconds.


 
  pinMode(md1f,OUTPUT);
  pinMode(md1b,OUTPUT);
  pinMode(md2f,OUTPUT);
  pinMode(md2b,OUTPUT);

  pinMode(mg1f,OUTPUT);
  pinMode(mg1b,OUTPUT);
  pinMode(mg2f,OUTPUT);
  pinMode(mg2b,OUTPUT);
} 
void loop() { 
  
  // put your main code here, to run repeatedly:
    ps2x.read_gamepad(); 
    if(ps2x.Button(PSB_PAD_UP)) {      //will be TRUE as long as button is pressed
      forward();
      Serial.println("up");
    }
    else if(ps2x.Button(PSB_PAD_RIGHT)){
      right();
       Serial.println("right");
    }
     else if(ps2x.Button(PSB_PAD_LEFT)){
       left();
     Serial.println("left");
    }
     else if(ps2x.Button(PSB_PAD_DOWN)){
      backward();
       Serial.println("down");
    } /*
      else if(ps2x.Button(PSB_R1)) {              //will be TRUE if button was JUST pressed OR released
      Serial.println("l1 just changed");
      digitalWrite(ARM,HIGH);
      } 
      else if(ps2x.Button(PSB_L1)) {              //will be TRUE if button was JUST pressed OR released
      Serial.println("R1 just changed");
      digitalWrite(ARM,LOW);
      } */  
       else { 
        stop1();}
          delay(20);

}