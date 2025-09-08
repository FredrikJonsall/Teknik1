const int buttonPin = 4;
const int ledPin = 7;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  //gör att knappen tolkas "på" om den inte trycks in, och "av" om den trycks in
}

void loop() {
  if (!digitalRead(buttonPin)) {  // ! betyder "inte".
    digitalWrite(ledPin, HIGH);   //Sätt igång port 7
  } else {
    digitalWrite(ledPin, LOW);
  }
}
