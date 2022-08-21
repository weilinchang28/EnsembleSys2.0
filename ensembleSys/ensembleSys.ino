#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN0 9
#define PIN1 10
#define PIN2 11

#define NUMPIXELS 28
#define BRIGHTNESS 50

Adafruit_NeoPixel player1 (NUMPIXELS, PIN0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel player2 (NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel player3 (NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

int LED_pin0 = 9;
int LED_pin1 = 10;
int LED_pin2 = 11;

int LEDPos = 0;
int counter = 0; 
int value1;

//////////////////////////////////////////////////////

// Chord Progression 01 
int chordIndex0 [ ] = {4,4,7,7,7,10,10,10,13,13,20,20};
int chordIndex1 [ ] = {4,4,7,7,7,10,10,10,13,13,20,20};
int chordIndex2 [ ] = {4,4,7,7,7,10,10,10,13,13,20,20};

//////////////////////////////////////////////////////


////// SETUP //////

void setup() {
  
  Serial.begin (115200);
  
  pinMode (LED_pin0, OUTPUT);
  pinMode (LED_pin1, OUTPUT);
  pinMode (LED_pin2, OUTPUT);
  
  /////////////////////////
  
  #if defined (__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set (clock_div_1);
  #endif

  player1.begin();  
  player1.clear();
  player1.show();
  
  player2.begin(); 
  player2.clear();
  player2.show();
   
  player3.begin();
  player3.clear();
  player3.show();
  
}

////// LOOP //////

void loop() {

  int softPot0 = analogRead (0);
  int softPot1 = analogRead (1);
  int softPot2 = analogRead (2);

  int fsr0 = analogRead (3);
  int fsr1 = analogRead (4);
  int fsr2 = analogRead (5);
  

  if ( Serial.available() )
  {
    value1 = Serial.read();

//    if (value1 == 1);
//    {
//    Serial.println ("ONE");
//    }
    
//      if (value1 == 1);
//      {
//        // Serial.println ("AD == 1");
//        // Serial.println(value1);
//      }
        
//    if (value1 == 1)
//      {
//        player1.clear();
//        player1.setPixelColor(chordIndex0[counter], player1.Color(255, 255, 255));
//        player1.show();   // Send the updated pixel colors to the hardware.
//        counter++;
//      }
//    else if (value1 == 0)
//      {
//        player1.clear();
//      }
   }

//  delay(DELAYVAL); // Pause before next pass through loop
//  Serial.print ("INCOMING ");
//  Serial.println (value1);

  
  Serial.print (softPot0);
  Serial.print (" ");
  Serial.print (softPot1);
  Serial.print (" ");
  Serial.print (softPot2); 
  Serial.print (" ");
  Serial.print (fsr0);
  Serial.print (" ");
  Serial.print (fsr1);
  Serial.print (" ");
  Serial.println (fsr2);
  
  delay(5);


  ///// IMPROV MODE - LEDs (HANDS) off /////
  
  //// Player 1 //// 
  if (softPot0 < 15) 
  {
    player1.clear();
    player1.show();
  }

  if (softPot0 > 15 && fsr0 > 10) 
  {
    LEDPos = map (softPot0, 0 , 1023, 0, 30);
    player1.clear ();
    player1.setPixelColor (LEDPos, 255, 255, 255);
    player1.show ();
  }

  //// Player 2 //// 
  if (softPot1 < 15) 
  {
    player2.clear();
    player2.show();
  }

  if (softPot1 > 15 && fsr1 > 10) 
  {
    LEDPos = map (softPot1, 0 , 1023, 0, 30);
    player2.clear();
    player2.setPixelColor (LEDPos, 255, 255, 255);
    player2.show();
  }

  //// Player 3 //// 
  if (softPot2 < 15) 
  {
    player3.clear();
    player3.show();
  }

  if (softPot2 > 15 && fsr2 > 10) 
  {
    LEDPos = map (softPot2, 0 , 1023, 0, 30);
    player3.clear();
    player3.setPixelColor (LEDPos, 255, 255, 255);
    player3.show();
  }

  //////////////////////////////////////////
  
}


////// Set all LEDs off (IMPROV MODE) //////

void clearLEDs()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    player1.setPixelColor (i, 0);
  }
}
