/* Arduino powered cloud lamp example code
  by: Alex - Super Make Something
  date: March 7, 2015
  license: Public domain.  Please use, reuse, and modify this sketch!
  additional: modified from "simple.ino" NeoPixel example sketch by Shae Erisson of Adafruit Industries.  
*/

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN           3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS     3

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Declare variables for thunder selector, duration, and brightness
long randomNumber;
long randomBrightness;
long randomDelay;

void setup() 
{
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() 
{
  // Generate random numbers for thunder selector, duration, and brightness
  randomNumber = random(1,9);
  randomBrightness = random(0,256);
  randomDelay = random(100,400);
  
  // Execute one of the below if statements depending on value of randomNumber
  if (randomNumber==1)
  { 
    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    // Assign randomBrightness to red, green, and blue LED of each NeoPixel unit to display white light
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (randomNumber==2)
  {
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (randomNumber==3)
  {
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (randomNumber==4)
  {
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (randomNumber==5)
  {
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (randomNumber==6)
  {
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
 }
  
  else if (randomNumber==7)
  {
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else
  {
    pixels.setPixelColor(0, pixels.Color(0,0,0));
    pixels.setPixelColor(1, pixels.Color(0,0,0));
    pixels.setPixelColor(2, pixels.Color(0,0,0));
  }
  
  //Once the desired color of the NeoPixel unit is set, call pixel.show() to make LEDs illuminate
  pixels.show();
  // Keep lights on for a random number of milliseconds
  delay(randomDelay);
  // Turn off all lights for next cycle
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.setPixelColor(1, pixels.Color(0,0,0));
  pixels.setPixelColor(2, pixels.Color(0,0,0));
  pixels.show();
}  
