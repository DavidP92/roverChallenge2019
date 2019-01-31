/*
 * Here's a little example code for the LCD Kit and it's functionality
 * 
 * More commands and special commands can be found at 
 * https://github.com/jimblom/Serial-LCD-Kit/wiki/Serial-Enabled-LCD-Kit-Datasheet
 * 
 * Assembled by Ty, hit me up for any questions
 */

 
//_-_-_-_-_-_-_-_-_ Initial Setup  _-_-_-_-_-_-_-_-_-_-_

#include <SoftwareSerial.h>

SoftwareSerial lcd(2, 3);  // This is required, to start an instance of an LCD ( TX , RX )

void setup()
{
  lcd.begin(9600);             // Start the LCD at 9600 baud
  clearDisplay();              // Clear the display
  setLCDCursor(2);             // Set cursor to the 1st row, 3rd column
  lcd.print("Hello, world");   // Statement that prints to 3rd spot on LCD 
  setLCDCursor(18);            // Set the cursor to the beginning of the 2nd line
  lcd.print("Begin Setup..."); // Statement that prints SIMULTANEOUSLY to 2nd row, 3rd column
  
  for (int i=0; i<3; i++)      // Flashes the backlight while above statements display on startup:
  {
    setBacklight(0);           // Minimum Brightness is 0
    delay(250);
    setBacklight(255);         // Maximum Brightness is 255
    delay(250);
  }
}
//_-_-_-_-_-_-_-_-_ Loop Action _-_-_-_-_-_-_-_-_-_-_

void loop()
 {
    clearDisplay();            // Clear the display
    setLCDCursor(0);           // set cursor to 1st row, 1st column
    lcd.print("LCD Functioning!");
    delay(1000);

    clearDisplay();            // Clear the display
    setLCDCursor(0);           // set cursor to 1st row, 1st column
    lcd.print("Rover lcd test!");
    delay(1000);
  }
  
// _-_-_-_-_-_-_ Set ups for Byte Definitions _-_-_-_-_-_-_
//              (uncomment and use as necessary)

void setBacklight(byte brightness)
{
  lcd.write(0x80);  // send the backlight command
  lcd.write(brightness);  // send the brightness value
}

void clearDisplay()
{
  lcd.write(0xFE);  // send the SPECIAL COMMMAND! (necessary for special commands like clear screen)
  lcd.write(0x01);  // send the clear screen command
}

void setLCDCursor(byte cursor_position)  
{
  lcd.write(0xFE);  // send the SPECIAL COMMAND!
  lcd.write(0x80);  // send the set cursor command
  lcd.write(cursor_position);  // send the cursor position
}

