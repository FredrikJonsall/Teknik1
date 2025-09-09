const int buttonPin = 4;
const int red = 7;
const int green = 8;
const int blue =9;

const int sensorPin=0; //A0

int sensor;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  //gör att knappen tolkas "på" om den inte trycks in, och "av" om den trycks in
}

void loop() {
  
    sensor=analogRead(sensorPin); //ljussensor på A0 

    delay(250);
  
  if(sensor<250){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if(sensor<500){
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if(sensor<750){
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  else if(sensor<1000){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
}
