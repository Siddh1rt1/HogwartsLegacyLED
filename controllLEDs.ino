
#include <Adafruit_NeoPixel.h>

#define PIN      5
#define N_LEDS 20
int incomingByte; 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
}

void loop() {
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'O') {
    chase(strip.Color(255, 0, 20)); // Red
    }
    // PEWPEW
    if (incomingByte == 'P') {
    fastchase(strip.Color(255, 0, 0)); // Green
    }
     // Revelio
    if (incomingByte == 'R') {
      chase(strip.Color(204, 102, 0));
      dechase(strip.Color(204, 102, 0));
      chase(strip.Color(204, 102, 0));
    }
    if (incomingByte == 'L') {
    luchase(strip.Color(255, 255, 255));
    }
    if (incomingByte == 'S') {
    slowchase(strip.Color(255, 255, 255));
    }
    //Protego
    if (incomingByte == 'T') {
    fade(strip.Color(150, 0, 155));
    delay(5);
    fade(strip.Color(204, 0, 204));
    delay(2);
    fade(strip.Color(100, 0, 100));
    delay(2);
    fade(strip.Color(50, 0, 50));
    delay(2);
    fade(strip.Color(0, 0, 0));
    
    }
  
  
}
}
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+15; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-15, 0); // Erase pixel a few steps back
      strip.show();
      delay(10);
  }
}
static void fastchase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+15; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-15, 0); // Erase pixel a few steps back
      strip.show();
      delay(5);
  }
}
static void slowchase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+15; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-15, 0); // Erase pixel a few steps back
      strip.show();
      delay(20);
  }
}
static void dechase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+15; i++) {
      strip.setPixelColor((20-i)  , c); // Draw new pixel
      strip.setPixelColor((i+15), 0); // Erase pixel a few steps back
      strip.show();
      delay(5);
  }
}

static void luchase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+0; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
 
      strip.show();
      delay(10);
  }
}

static void fade(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+15; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel

      strip.show();
      delay(5);
  }
}
