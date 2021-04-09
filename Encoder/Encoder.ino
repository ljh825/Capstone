/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

unsigned long currPosition = 0; // current position of the 

const int encoder_a = 0; // A output will trigger inturrupt on pin 0
const int encoder_b = 1; // B output will trigger inturrupt on pin 1

const in north_hall = 4; // North Hall sensor on Interrupt 4

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(encoder_a, encoder_b);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting up...");
}

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.write(newPosition);
  }
}
