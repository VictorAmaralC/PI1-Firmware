#include <LiquidCrystal.h>
#include <Wire.h>
// Creates an LCD object. Parameters: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd = LiquidCrystal(13,12,14,27,26,25);
// Make custom characters:
byte heart_h[8] = {
  B00000,
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,  
  B00000
}; 
byte heart_f[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,  
  B00000
}; 
int z = 1;
int c = 2;
void setup() {
  // Specify the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Create a new characters:
  lcd.createChar (1, heart_h);    // load  heart_h to memory 1
  lcd.createChar (2, heart_f);  // load heart_f to memory 2
  lcd.clear();
  // Print a message to the lcd:
  lcd.setCursor(1,0);
  lcd.print("Test");
}
void loop() {
  c = c - 1;
  z = z + 1;
  // Print all the custom characters:
  lcd.setCursor(7,2); //set cursor to bottom left second line
  lcd.print(char(z));
  lcd.print(char(c));
  lcd.print(char(z)); 
  if (z==2){
    z = 0;
    c = 3;
    }
  delay(500);
}