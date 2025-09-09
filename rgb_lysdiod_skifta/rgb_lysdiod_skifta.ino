const int buttonPin = 4;
const int red = 7;
const int green = 8;
const int blue =9;

int color;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  //gör att knappen tolkas "på" om den inte trycks in, och "av" om den trycks in
}

void loop() {
  if (!digitalRead(buttonPin)) {  // ! betyder "inte".
    color = 1 + color ; 
    if(color==4) color=0;
    delay(250);
  } else if(color==0){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if(color==1){
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if(color==2){
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  else if(color==3){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
}
