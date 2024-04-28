#include <SoftwareSerial.h> 



char junk;
String inputString="";

 

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




 
void setup() 
{   
 Serial.begin(9600); 
  //bluetooth.begin(9600);

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
  
 if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }
    // clear the serial buffer
    if(inputString == "F"){        
      forward();  
    }else if(inputString == "B"){   
     backward();
    }
    else if(inputString == "R"){   
     right();
    }
    else if(inputString == "L"){   
     left();
    }
    else stop1();
    inputString = "";
  }


}