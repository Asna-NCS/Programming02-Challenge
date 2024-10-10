#define CHANNEL_A 2
#define CHANNEL_B 3

volatile int POS = 0; //Variable that tracks your ticks

void tick_A() {
  //Your code here
}

void tick_B() {
  //Your code here
}


void setup() {
  Serial.begin(9600); //Enable serial communication

  //Init pins and attach interrupts
  pinMode(CHANNEL_A, INPUT); 
  pinMode(CHANNEL_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(CHANNEL_A), tick_A, RISING);
  attachInterrupt(digitalPinToInterrupt(CHANNEL_B), tick_B, RISING);

  
}

void loop() {
  Serial.println(POS);
}
