void setup() {
  pinMode(5, OUTPUT);

  pinMode(7, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  if ( digitalRead(7) == 0 ) {

    analogWrite(5, 78);

    Serial.println("Don't Touch Me!");

    delay(200);

  } else {

    digitalWrite(8, LOW);
  }
}
