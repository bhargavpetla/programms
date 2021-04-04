
#include <LiquidCrystal.h>
char Incoming_value = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
                
void setup() 
{
  Serial.begin(9600);         
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("FREQUENCY OF LED");       
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1')  
      do{          
      digitalWrite(13, HIGH); 
      delay(1000); 
      digitalWrite(13, LOW);
      delay(1000);
      lcd.setCursor(0, 1);
  // print the number of seconds since reset:
      lcd.print("0.001");
      Incoming_value = Serial.read();
      }while((Incoming_value == -1));
    else if(Incoming_value == '2')   
      do
      {          
      digitalWrite(13, HIGH); 
      delay(100); 
      digitalWrite(13, LOW);
      delay(100);
      lcd.setCursor(0, 1);
  // print the number of seconds since reset:
      lcd.print("0.01");
      Incoming_value = Serial.read();
      }while(Incoming_value == -1);        
    else if(Incoming_value == '3')   
      do
      {          
      digitalWrite(13, HIGH); 
      delay(500); 
      digitalWrite(13, LOW);
      delay(500);
      lcd.setCursor(0, 1);
  // print the number of seconds since reset:
      lcd.print("0.002");
      Incoming_value = Serial.read();
      }while(Incoming_value == -1); 
      
    else if(Incoming_value == '0')     
      {  
      digitalWrite(13, LOW); 
      lcd.setCursor(0, 1);
  // print the number of seconds since reset:
      lcd.print("0");
      }  
  }                            
} 