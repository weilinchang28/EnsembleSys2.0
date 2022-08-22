///// ADAFRUIT /////
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

int LEDPos = 0; // Imporv Mode
int counter = 0; 
int value1; // ?? 

int softPot0 = analogRead (0);
int softPot1 = analogRead (1);
int softPot2 = analogRead (2);


///// PITCHES /////
float sG3 = 207.65;
float nA3 = 220.0;
float sA3 = 233.08;
float nB3 = 246.94;
float nC4 = 261.63;
float sC4 = 277.18;
float nD4 = 293.66;
float sD4 = 311.13;
float nE4 = 329.63;
float nF4 = 349.23;
float sF4 = 369.99;
float nG4 = 392.0;
float sG4 = 415.3;
float nA4 = 440.0;
float sA4 = 466.16; 
float nB4 = 493.88;
float nC5 = 523.25;
float sC5 = 554.37;
float nD5 = 587.33; 
float sD5 = 622.25;


///// Chord Progression - Sys /////
int userPitch1 [ ] = {nF4, nF4, nG4, nG4, nG4, nA4, nA4, nA4, nA4, sA4, sA4, nC5, nC5};
int userPitch2 [ ] = {nD4, nD4, nD4, nD4, nE4, nE4, nE4, nF4, nF4, nG4, nG4, nA4};
int userPitch3 [ ] = {nA3, sA3, sA3, nC4, nC4, nC4, nD4, nD4, nD4, nE4, nE4, nF4};
int userChord [ ] = {userPitch1, userPitch2, userPitch3};

///// Chord Progression 01 - LEDs ///// 
int userPitchLED1 [ ] = {26, 26, 20, 20, 20, 13, 13, 13, 9, 9, 2, 2}; // {27, 27, 19, 19, 19, 11, 11, 11, 7, 7, 0, 0}
int userPitchLED2 [ ] = {26, 26, 26, 26, 20, 20, 20, 17, 17, 8, 8, 0}; // {27, 27, 27, 27, 19, 19, 19, 15, 15, 7, 7, 0}
int userPitchLED3 [ ] = {26, 24, 24, 18, 18, 18, 11, 11, 11, 3, 3, 0}; // {27, 23, 23, 15, 15, 15, 7, 7, 7, 2, 2, 0}
int userLEDs [ ] = {userPitchLED1, userPitchLED2, userPitchLED3};

float mapSoftPot0;
float mapSoftPot1;
float mapSoftPot2;


int chordIndex = 0;
int LEDchordIndex = 0;
int acceptRange = 5; // out of tune range




void setup() 
{
  
  Serial.begin (9600);
  
//  pinMode (LED_pin0, OUTPUT);
//  pinMode (LED_pin1, OUTPUT);
//  pinMode (LED_pin2, OUTPUT);

  // ADAFRUIT // 
  #if defined (__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set (clock_div_1);
  #endif

  // LED Setup // 
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


///// PLAYCHORD FUNC /////

//void playChord ()
//{
//  boolean result [3] = {false, false, false};
//
//  if (abs(mapSoftPot0 - user1[chordIndex] < acceptRange))
//  {
//    result [0] = true;
//    Serial.println ("YAY1");
//  }
//
//    if (abs(mapSoftPot1 - user2[chordIndex] < acceptRange))
//  {
//    result [1] = true;
//    Serial.println ("YAY2");
//  }
//
//    if (abs(mapSoftPot2 - user3[chordIndex] < acceptRange))
//  {
//    result [2] = true;
//    Serial.println ("YAY3");
//  }
//
//  int numInTune = 0;
//  for (int i = 0; i < sizeof(result); i++) // 
//  {
//    if (result[i] == true)
//    {
//      numInTune++; 
//    }
//  }
//  
//  Serial.print ("numInTune ");
//  Serial.println (numInTune);
//  
//  if (numInTune == 3) // if all three are in tune 
//  {
//    Serial.println ("!!ALL IN TUNE!!"); // "all in tune " + true
//    
//    if (counter > 100) // define the deboucing value
//    {
//      chordIndex++;
//      counter = 0;
//    } 
//    else
//    {
//      counter++;
//    }
//  }
//  else // if not all of them are in tune
//  {
//     Serial.println ("out of tune");
//  }
//
//  Serial.print ("chordIndex ");
//  Serial.println (chordIndex);
//  Serial.print ("counter ");
//  Serial.println (counter);
//  Serial.println (" ");
//
//}



void loop() {

softPot0 = analogRead (0);
softPot1 = analogRead (1);
softPot2 = analogRead (2);

mapSoftPot0 = map (softPot0, 1023, 0, nE4, sC5); // nF4, nC5
mapSoftPot1 = map (softPot1, 1023, 0, sC4, nA4); //nD4
mapSoftPot2 = map (softPot2, 1023, 0, sG3, nF4); //nA3

int fsr0 = analogRead (3);
int fsr1 = analogRead (4);
int fsr2 = analogRead (5);

// playChord();

player1.clear();
player1.setPixelColor (userPitchLED1 [LEDchordIndex], 255, 255, 255);
player1.show();

player2.clear();
player2.setPixelColor (userPitchLED2 [LEDchordIndex], 255, 255, 255);
player2.show();

player3.clear();
player3.setPixelColor (userPitchLED3 [LEDchordIndex], 255, 255, 255);
player3.show();
  
/////
/////

boolean result [3] = {false, false, false};

  if (abs(mapSoftPot0 - userPitch1[chordIndex] < acceptRange))
  {
    result [0] = true;
    Serial.println ("YAY1");
  }

    if (abs(mapSoftPot1 - userPitch2[chordIndex] < acceptRange))
  {
    result [1] = true;
    Serial.println ("YAY2");
  }

    if (abs(mapSoftPot2 - userPitch3[chordIndex] < acceptRange))
  {
    result [2] = true;
    Serial.println ("YAY3");
  }

  int numInTune = 0;
  for (int i = 0; i < sizeof(result); i++) // 
  {
    if (result[i] == true)
    {
      numInTune++; 
    }
  }
  
  Serial.print ("numInTune ");
  Serial.println (numInTune);
  
  if (numInTune == 3) // if all three are in tune 
  {
    Serial.println ("!!ALL IN TUNE!!"); // "all in tune " + true
    
    if (counter > 100) // define the deboucing value
    {
      chordIndex++;
      LEDchordIndex++;
      counter = 0;
    } 
    else
    {
      counter++;
    }
  }
  else // if not all of them are in tune
  {
    Serial.println ("out of tune");
  }

  Serial.print ("chordIndex ");
  Serial.println (chordIndex);
  Serial.print ("counter ");
  Serial.println (counter);
  Serial.println (" ");


/////
/////



//  int softPot0 = analogRead (0);
//  int softPot1 = analogRead (1);
//  int softPot2 = analogRead (2);
//
//  int fsr0 = analogRead (3);
//  int fsr1 = analogRead (4);
//  int fsr2 = analogRead (5);
  



//  delay(DELAYVAL); // Pause before next pass through loop
//  Serial.print ("INCOMING ");
//  Serial.println (value1);

  
//  Serial.print (softPot0);
//  Serial.print (" ");
//  Serial.print (softPot1);
//  Serial.print (" ");
//  Serial.print (softPot2); 
//  Serial.print (" ");
//  Serial.print (fsr0);
//  Serial.print (" ");
//  Serial.print (fsr1);
//  Serial.print (" ");
//  Serial.println (fsr2);

  Serial.print (mapSoftPot0);
  Serial.print (" ");
  Serial.print (mapSoftPot1);
  Serial.print (" ");
  Serial.print (mapSoftPot2); 
  Serial.print (" ");
  Serial.print (fsr0);
  Serial.print (" ");
  Serial.print (fsr1);
  Serial.print (" ");
  Serial.println (fsr2);
  
  delay(5);


//  ///// IMPROV MODE - LEDs (HANDS) off /////
//  
//  //// Player 1 //// 
//  if (softPot0 < 15) 
//  {
//    player1.clear();
//    player1.show();
//  }
//
//  if (softPot0 > 15 && fsr0 > 10) 
//  {
//    LEDPos = map (softPot0, 0 , 1023, 0, 30);
//    player1.clear ();
//    player1.setPixelColor (LEDPos, 255, 255, 255);
//    player1.show ();
//  }
//
//  //// Player 2 //// 
//  if (softPot1 < 15) 
//  {
//    player2.clear();
//    player2.show();
//  }
//
//  if (softPot1 > 15 && fsr1 > 10) 
//  {
//    LEDPos = map (softPot1, 0 , 1023, 0, 30);
//    player2.clear();
//    player2.setPixelColor (LEDPos, 255, 255, 255);
//    player2.show();
//  }
//
//  //// Player 3 //// 
//  if (softPot2 < 15) 
//  {
//    player3.clear();
//    player3.show();
//  }
//
//  if (softPot2 > 15 && fsr2 > 10) 
//  {
//    LEDPos = map (softPot2, 0 , 1023, 0, 30);
//    player3.clear();
//    player3.setPixelColor (LEDPos, 255, 255, 255);
//    player3.show();
//  }
//
//  //////////////////////////////////////////
  
}


////// Set all LEDs off (IMPROV MODE) //////

void clearLEDs()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    player1.setPixelColor (i, 0);
  }
}

//////////
//  if ( Serial.available() )
//  {
//    value1 = Serial.read();
//
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
//   }
////////////
