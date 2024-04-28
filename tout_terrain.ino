
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
                                                      
//****************************************************************************************************
// Setup Drive Motors using the Adafruit Motor Controller version 1.0 Library

int mtr_Spd = 250;                                        // set the speed of the motors

//*****************************************************************************************************
// Bluetooth Variables & Setup

String str;                                               // raw string received from android to arduino
int blueToothVal;                                         // stores the last value sent over via bluetooth

//*****************************************************************************************************

void setup() 
{  
  Serial.begin(115200);                                  // Serial 0 is for communication with the serial monitor
  Serial1.begin(9600);                                   // Serial 1 is for Bluetooth communication - DO NOT MODIFY  

  pinMode(md1f,OUTPUT);
  pinMode(md1b,OUTPUT);
  pinMode(md2f,OUTPUT);
  pinMode(md2b,OUTPUT);

  pinMode(mg1f,OUTPUT);
  pinMode(mg1b,OUTPUT);
  pinMode(mg2f,OUTPUT);
  pinMode(mg2b,OUTPUT);

}

//*****************************************************************************************************
// Main Loop

void loop()
{   
  bluetooth();                                          // Run the Bluetooth procedure to see if there is any data being sent via BT
}




//*****************************************************************************************************
// This procedure reads the serial port - Serial1 - for bluetooth commands being sent from the Android device

void bluetooth()
{
 while (Serial1.available())                             // Read bluetooth commands over Serial1 // Warning: If an error with Serial1 occurs, make sure Arduino Mega 2560 is Selected
 {  
  {  
      str = Serial1.readStringUntil('\n');               // str is the temporary variable for storing the last sring sent over bluetooth from Android device
      //Serial.print(str);             
  } 
    
    blueToothVal = (str.toInt());                        //  convert the string 'str' into an integer and assign it to blueToothVal
    Serial.print("BlueTooth Value ");
    Serial.println(blueToothVal);    



// Bluetooth Section
// *********************************************************************************************************

 switch (blueToothVal) 
 {
      case 1:                                
        Serial1.println("Forward");
        Forward();
        break;

      case 2:                 
        Serial1.println("Reverse");
        Reverse();
        break;

      case 3:         
        Serial1.println("Left");
        LeftTurn();
        Stop();
        break;
        
      case 4:                     
        Serial1.println("Right");
        RightTurn();
        Stop();
        break;
        
      case 5:                                            
        Serial1.println("Stop");
        Stop();
        break;      

 }                                                              // end of switch case 

 }                                                              // end of while loop Serial1 read
 
                                                                // if no data from Bluetooth 
   if (Serial1.available() < 0)                              
    {
     Serial1.println("No Bluetooth Data ");          
    }
  
}




// Motor Control Section
// **********************************************************************************************************************************************************************

void Forward()
{
  Serial.println("forword");
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

// **********************************************************************************************************************************************************************

void Reverse()
{
  Serial.println("reverse");
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

// **********************************************************************************************************************************************************************

 
void LeftTurn()
{
Serial.println("Left");
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



// **********************************************************************************************************************************************************************

void RightTurn()
{
Serial.println("Right");
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


// **********************************************************************************************************************************************************************

void Stop()
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
