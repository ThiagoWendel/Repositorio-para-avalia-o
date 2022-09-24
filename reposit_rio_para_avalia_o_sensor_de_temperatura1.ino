// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal LCD(7, 6, 5, 4, 3, 2);
 int temperatura = 0;
void setup ()
  
{
 
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  LCD.begin(16, 2);
  LCD.print("    CURSO DE ");
  LCD.setCursor(0,1);
  LCD.print("    EXTENSAO!");
  delay(2000);
  
  LCD.clear();

  LCD.begin(16, 2);
  LCD.print("   SISTEMA DE");
  LCD.setCursor(0,1);
  LCD.print("  TEMPERATURA!");
  delay(2000);
  LCD.clear();
  
}  

void loop()
{
  temperatura = ((-40 + 0.488155 * (analogRead(A0) - 20)));
  
  if ((-40 + 0.488155 * (analogRead(A0) - 20)) >= 32) {
    
  LCD.begin(16, 2);
  LCD.print("TEMPERATURA: ");
  LCD.print(temperatura);
  LCD.print("C");

  LCD.setCursor(0,1);
  LCD.print("Temperatura Alta");
  delay(1000);
 LCD.clear();
 LCD.begin(16, 2);
 LCD.print("Ar condicionado");
 LCD.setCursor(0,1);
 LCD.print("Ligado...");
 delay(1000);
 LCD.clear();
 
    
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
    if ((-40 + 0.488155 * (analogRead(A0) - 20)) <= 15) {
      
  LCD.begin(16, 2);
  LCD.print("TEMPERATURA: ");
  LCD.print(temperatura);
  LCD.print("C");

  LCD.setCursor(0,1);
  LCD.print("   Temp. baixa");
  delay(1000);
 LCD.clear();
 LCD.begin(16, 2);
 LCD.print("Ar condicionado");
 LCD.setCursor(0,1);
 LCD.print("Desligado...");
 delay(1000);
 LCD.clear();
      
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
  
  } else {
    if ((-40 + 0.488155 * (analogRead(A0) - 20)) > 15 && (-40 + 0.488155 * (analogRead(A0) - 20)) < 32) {
      
  LCD.begin(16, 2);
  LCD.print("TEMPERATURA: ");
  LCD.print(temperatura);
  LCD.print("C");

  LCD.setCursor(0,1);
  LCD.print("Ambiente Fresco ");
  delay(1000);
  LCD.clear();
 
   
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    }
  }
}