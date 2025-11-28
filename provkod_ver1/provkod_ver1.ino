void setup() {
  pinMode(8, OUTPUT);

  pinMode(7, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  if (!digitalRead(7)) {

    digitalWrite(8, HIGH);

    Serial.println("You pressed it!");

    delay(200);

  } else {

    digitalWrite(8, LOW);
  }
}
