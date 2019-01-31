/*
 * Here's a little example code for the Sparkfun Serial LCD Kit 
 * that includes a 16 x 2 liquid crystal display 
 * 
 * Hardware setup (used in this case):
 * Plug in power and ground respectively, then yellow wire (RX), to D3 on Arduino UNO
 * 
 * More commands and special commands can be found on github at: 
 * https://github.com/jimblom/Serial-LCD-Kit/wiki/Serial-Enabled-LCD-Kit-Datasheet
 * 
 * Code assembled and collected by Ty 
 * 
 */
 
//_-_-_-_-_-_-_-_-_ Initial Setup _-_-_-_-_-_-_-_-_-_-_

#include <SoftwareSerial.h>

SoftwareSerial lcd(2, 3);      // This is required, to start an instance of an LCD ( TX , RX )

void setup()
{
  lcd.begin(9600);             // Start the LCD at 9600 baud
  clearDisplay();              // Clear the display
  
  setLCDCursor(2);             
  lcd.print("Hello, world!");  // Statement that prints to 1st row, 3rd column
  setLCDCursor(17);            
  lcd.print("Begin Setup..."); // Statement that prints SIMULTANEOUSLY to 2nd row, 2nd column
  delay(2000);
  
  for (int i=0; i<3; i++)      // Flashes the backlight while above statements display on startup:
  {
    setBacklight(0);           // Minimum Brightness of 0
    delay(250);
    setBacklight(255);         // Maximum Brightness of 255
    delay(250);               
  }
}

//_-_-_-_-_-_-_-_-_-_-_   Loop  _-_-_-_-_-_-_-_-_-_-_-_

void loop()
 {
    clearDisplay();            // Clear the display
    delay(500);
    setLCDCursor(4);           // set cursor to 1st row, 5th column
    lcd.print("LCD TEST");
    delay(1000);
    setLCDCursor(17);          // set cursor to 2nd row, 3rd column
    lcd.print("Great Success!");
    delay(3000);

  }

// _-_-_-_-_-_-_ Set ups for Byte Definitions _-_-_-_-_-_-_
//        (uncomment, copy, paste, and use as needed)

void setBacklight(byte brightness) // adjusts backlight brightness from 0-255
{
  lcd.write(0x80);             // send the backlight command
  lcd.write(brightness);       // send the brightness value
}
/*
void setBaudRate (byte baud_rate)  // Sets the baud rate 
{
  lcd.write(0x81);             // send the baud rate command
  lcd.write(baud_rate);        // send the baud value from 0 - 10 to correspond to 300 - 115200
}
*/
//____________THIS SECTION IS SPECIAL COMMANDS ONLY______________

void clearDisplay()            // Clears out the display, MUST USE for this kit!
{
  lcd.write(0xFE);             // send the SPECIAL COMMMAND! (necessary for thes commands)
  lcd.write(0x01);             // send the clear screen command
}

void setLCDCursor(byte cursor_position)  
{
  lcd.write(0xFE);  
  lcd.write(0x80);  
  lcd.write(cursor_position);  // Enter value from 0 - 31 for cursor postion 
}

/*
void scrollCursorRight()       // Scrolls the text to the right, disappears on same row
{
  lcd.write(0xFE);  
  lcd.write(0x1C);  
}

void scrollCursorLeft()        // Scrolls the text to the left
{
  lcd.write(0xFE);  
  lcd.write(0x18);  
}

void turnScreenOff()           // Turns the display OFF 
{
  lcd.write(0xFE);  
  lcd.write(0x08);  
}

void turnScreenOn()            // Turns the display ON
{
  lcd.write(0xFE);  
  lcd.write(0x18);  
}
*/
