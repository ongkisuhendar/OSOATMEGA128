
//#define input_1 52
//#define input_2 51
//#define input_3 50
//#define input_4 49
//#define input_5 23
//#define input_6 4
//#define input_7 48
//#define input_8 47

char pin_led[17] = {44, 43, 42, 41, 40, 39, 13, 3, 52, 51, 50, 49, 23, 4, 48, 47, 16};

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (int i = 0; i < pin_led[16]; i++) {
    pinMode(pin_led[i], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < pin_led[16]; i++) {
    digitalWrite(pin_led[i], HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);                       // wait for a second
    digitalWrite(pin_led[i], LOW);    // turn the LED off by making the voltage LOW
    delay(50);                       // wait for a second
  }
}
