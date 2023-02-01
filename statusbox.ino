// Using Arduino Nano
// Neopixel connected to 5V, GND and 2
// Black button connected to GND,3 
// Green button connected to GND, 4
// Yellow button connected to GND, 5
// Red buttton connected to GND, 6
/////////////////////////////////////////////////////////////////

#include <Button2.h>
#include <Adafruit_NeoPixel.h>

/////////////////////////////////////////////////////////////////

#define BUTTON_A_PIN  3 // Black button
#define BUTTON_B_PIN  4 // Green button
#define BUTTON_C_PIN  5 // Yellow button
#define BUTTON_D_PIN  6 // Red button
#define LED_PIN 2
#define NUMPIXELS 1

/////////////////////////////////////////////////////////////////

Button2 buttonA, buttonB, buttonC, buttonD;
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

/////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  delay(50);
  Serial.println("\n\nMultiple Buttons Demo");

  pinMode(BUTTON_A_PIN, INPUT_PULLUP);
  pinMode(BUTTON_B_PIN, INPUT_PULLUP);
  pinMode(BUTTON_C_PIN, INPUT_PULLUP);
  pinMode(BUTTON_D_PIN, INPUT_PULLUP);

  buttonA.begin(BUTTON_A_PIN);
  buttonA.setClickHandler(click);
  buttonA.setLongClickHandler(click);
  
  buttonB.begin(BUTTON_B_PIN);
  buttonB.setClickHandler(click);
  buttonB.setLongClickHandler(click);
  
  buttonC.begin(BUTTON_C_PIN);
  buttonC.setClickHandler(click);
  buttonC.setLongClickHandler(click);
  
  buttonD.begin(BUTTON_D_PIN);
  buttonD.setClickHandler(click);
  buttonD.setLongClickHandler(click);
  
  pixels.begin();
  pixels.clear();
  pixels.show();
}

/////////////////////////////////////////////////////////////////

void loop() {
  buttonA.loop();
  buttonB.loop();
  buttonC.loop();
  buttonD.loop();
}

/////////////////////////////////////////////////////////////////

void click(Button2& btn) {
  pixels.clear();
  
  if (btn == buttonA) {
    Serial.println("Black button clicked");
    Serial.println("All lights off");
    pixels.clear();
    pixels.show();
  } else if (btn == buttonB) {
    Serial.println("Green button clicked");
    Serial.println("Green light on, amber and red off");
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.show();
  } else if (btn == buttonC) {
    Serial.println("Yellow button clicked");
    Serial.println("Amber light on, green and red off");
    pixels.setPixelColor(0, pixels.Color(255, 255, 0));
    pixels.show();
  } else if (btn == buttonD) {
    Serial.println("Red button clicked");
    Serial.println("Red light on, green and amber off");
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
  }
}
