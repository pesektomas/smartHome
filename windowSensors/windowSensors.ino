// Arduino mega - 54 I/O pins
// 6-17 and 36-47 light controll
// 18 - 35 free

const byte windowAlarmCount = 6;
const byte sensorPins[] = {0, 1, 2, 3, 4, 5};
const byte alarmPins[] = {53, 52, 51, 50, 49, 48};

void setup() {
  for (byte i = 0; i < windowAlarmCount; i ++) {
    initAlarm(sensorPins[i], alarmPins[i]);
  }
}

void loop() { 
  for (byte i = 0; i < windowAlarmCount; i ++) {
    loopAlarm(sensorPins[i], alarmPins[i]);
  }
  delay(1);
}

void initAlarm(byte sensorPin, byte alarmPin) {
  pinMode(sensorPin, INPUT);
  pinMode(alarmPin, OUTPUT);
  digitalWrite(sensorPin, HIGH);
}

void loopAlarm(byte sensorPin, byte alarmPin) {
  if(digitalRead(sensorPin) == LOW){
    digitalWrite(alarmPin, LOW);
  } else {
    digitalWrite(alarmPin, HIGH);
  }
}
