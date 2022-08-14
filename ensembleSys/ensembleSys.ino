#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN0 9
#define PIN1 10
#define PIN2 11

#define NUMPIXELS 28
#define BRIGHTNESS 50

Adafruit_NeoPixel player1(NUMPIXELS, PIN0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel player2(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel player3(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

//////////////////////////////////////////////////////

int chordIndex0 [] = {4,4,7,7,7,10,10,10,13,13,20,20};
int chordIndex1 [] = {4,4,7,7,7,10,10,10,13,13,20,20};
int chordIndex2 [] = {4,4,7,7,7,10,10,10,13,13,20,20};

//////////////////////////////////////////////////////

int counter = 0; 

int LED_pin0 = 9;
int LED_pin1 = 10;
int LED_pin2 = 11;

void setup() {
  
  Serial.begin(115200);
  
  pinMode(LED_pin0,OUTPUT);
  pinMode(LED_pin1,OUTPUT);
  pinMode(LED_pin2,OUTPUT);
  
  ////////////////////////////////////////////////////
  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif

  player1.begin(); 
  player2.begin();  
  player3.begin(); 
}

//// Test Here // 
//player1.clear();
//player1.setPixelColor(chordIndex0[2], player1.Color(255, 255, 255));
//player1.show();
/////////////////

void loop() {

  int softPot0 = analogRead(0);
  int softPot1 = analogRead(1);
  int softPot2 = analogRead(2);

  if (Serial.available())
  {
    int value1 = Serial.read();
    if (value1 == 1)
      {
        player1.clear();
        player1.setPixelColor(chordIndex0[counter], player1.Color(255, 255, 255));
        player1.show();   // Send the updated pixel colors to the hardware.
        counter++;
      }
    else if (value1 == 0)
      {
        player1.clear();
      }
   }
  
  

//  delay(DELAYVAL); // Pause before next pass through loop
  
  Serial.print(softPot0);
  Serial.print(" ");
  Serial.print(softPot1);
  Serial.print(" ");
  Serial.println(softPot2);

  delay(5);

}