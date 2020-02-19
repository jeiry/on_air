// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        5 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int av = 0;
String str;
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  if(Serial.available()){
    Serial.println("avaibable");
    av = 1;
    str = Serial.readString();
  }else{
    av = 0;
  }

  if(av == 1){
    int c1 = getValue(str,',',0).toInt();
    int c2 = getValue(str,',',1).toInt();
    int c3 = getValue(str,',',2).toInt();
    pixels.setPixelColor(0, pixels.Color(c1, c2, c3));
    pixels.show();
  }
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
//  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
//
//    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
//    // Here we're using a moderately bright green color:
//    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
//
//    pixels.show();   // Send the updated pixel colors to the hardware.
//
//    delay(DELAYVAL); // Pause before next pass through loop
//  }
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
