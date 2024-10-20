#define CHANNEL_A 2
#define CHANNEL_B 3

volatile int POS = 0; // Variable that tracks your ticks

void tick_A() {
  // Check the state of channel B to determine the direction
  if (digitalRead(CHANNEL_B) == HIGH) {
    POS++; // Rotate clockwise
  } else {
    POS--; // Rotate counterclockwise
  }
}

void tick_B() {
  // Check the state of channel A to determine the direction
  if (digitalRead(CHANNEL_A) == HIGH) {
    POS--; // Rotate counterclockwise
  } else {
    POS++; // Rotate clockwise
  }
}

void setup() {
  Serial.begin(9600); // Enable serial communication

  // Init pins and attach interrupts
  pinMode(CHANNEL_A, INPUT); 
  pinMode(CHANNEL_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(CHANNEL_A), tick_A, RISING);
  attachInterrupt(digitalPinToInterrupt(CHANNEL_B), tick_B, RISING);
}

void loop() {
  Serial.println(POS);
  delay(100); // Add a small delay to make output more readable
}
