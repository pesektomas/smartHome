// Arduino mega - 54 I/O pins
// 0-5 and 48-53 sensors
// 6-17 and 36-47 light controll
// 18 - 35 free

const byte lightControllCount = 12;
const byte buttons[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
const byte relaies[] = {47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36};
bool buttonState[] = {false, false, false, false, false, false, false, false, false, false, false, false};

void setup() {
  for (byte i = 0; i < lightControllCount; i ++) {
    initControll(buttons[i], relaies[i]);
  }
}

void loop() {
  for (byte i = 0; i < lightControllCount; i ++) {
    loopControll(buttons[i], relaies[i], i);
  }

  // TODO ethernet controll here
  
  delay(1);
}

void initControll(byte buttonPin, byte relayPin) {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loopControll(byte buttonPin, byte relayPin, byte position) {
  if (digitalRead(buttonPin) == HIGH) {
    buttonState[position] = !buttonState[position];
    digitalWrite(relayPin, buttonState[position]);
    delay(500);
  }
}
