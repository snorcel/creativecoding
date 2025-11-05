#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  // get light level
  int light = CircuitPlayground.lightSensor();

  // left button
  if (CircuitPlayground.leftButton()) {
    CircuitPlayground.playTone(300, 200); // freq 300 hz, duration 200 ms
    // turn all pixels blue
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 0, 255);
    }
  }

  // right button
  else if (CircuitPlayground.rightButton()) {
    CircuitPlayground.playTone(600, 200); // freq 600 hz, duration 200 ms
    // turn all pixels red
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
    }
  }

  else {
  // turn on LEDs based on light level
  if (light < 500) {
    // if it's dark turn all pixels pink
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 255, 0, 127);
    }
  }
  else {
    // if it's bright turn all pixels off
      CircuitPlayground.clearPixels();
  }
  }

  // update LEDs to show changes
  CircuitPlayground.strip.show();

  delay(50);
}