#include <LiquidCrystal.h>


// initialize the library with the numbers of the interface pins


LiquidCrystal lcd(0, 1, 8,9,10,11); /// REGISTER SELECT PIN,ENABLE PIN,D4 PIN,D5 PIN, D6 PIN, D7 PIN



void setup()
{
  pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);
  pinMode(12, OUTPUT);
     lcd.begin(16, 2);
    Serial.begin(9600);
    
  
}

void loop()
{

delay(750);//delay of 0.75sec


lcd.setCursor(0, 0);// set the cursor to column 0, line1
  
  
  double analogVal = analogRead(A4); //read values from A0
  double analogVal1= analogRead(A5);
  Serial.println(analogVal1);
  delay(100);
  Serial.println(analogVal);
 
  lcd.print("Light is " );
  lcd.setCursor(0,1);
 lcd.print (((analogVal+analogVal1-150)/140)*100);
  


  
  

   

    double lux=((analogVal+analogVal1-150)/140)*100;
    if(lux<25.00)
     {digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(5,LOW);
      digitalWrite(12,LOW);
      delay(100);
      
     }
     else
     if(lux>=25.01&&75<=lux)
     {digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(12,HIGH );
     }
     else
     {digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(12,HIGH);
     }
     
     
     
   delay(10);
}
