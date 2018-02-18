/*
  Test the 3x3x3 cube
 */

#define __ASSERT_USE_STDERR

#include <assert.h>

int col = 2;
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4};  //https://arduino.stackexchange.com/a/1617

// set layers (cathodes) to logic HIGH 
void layersOff() {
  for (int i=0;i<5;i++) {
    analogWrite(analog_pins[i], 1023);
  }
}

void columnsOff() {
  for (int i=0;i<8;i++) {
    digitalWrite(i+2, LOW);
  }
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int c=2; c<=10; c++) {
     pinMode(c, OUTPUT);
  }
  layersOff();
}

//column_chaser number columns from 1..9
void column_chaser(int col) {
  assert(col>0);
  assert(col<10);
  digitalWrite(col+1, HIGH);   // turn the LED on (HIGH is the voltage level)
  for (int layer=0; layer<3; layer++) {
    layersOff();
    analogWrite(analog_pins[layer], 0); //ground this layers' cathodes
    delay(50);
  }
  digitalWrite(col+1, LOW);
}

//see how two pins look with POV
void two() {
  layersOff();
  analogWrite(analog_pins[2], 0);   //turn on middle layer
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  delay(150);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  delay(150);
}

// the loop routine runs over and over again forever:
void loop() {
  two();
  //for (int col=1;col<10;col++) {
    //column_chaser(col);
  //}
}

