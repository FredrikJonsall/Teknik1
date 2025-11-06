
int red = 5;
int blue = 6;
int button = 9;

int count = 0;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode( button , INPUT_PULLUP);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
}

void loop() {

if( digitalRead(knapp) == 0 ) {
count = count+1;
if (count == 2) count = 0;
}
if( count == 0 ){
digitalWrite(red, LOW);
digitalWrite(blue, HIGH);
} 
else{
digitalWrite(blue, LOW);
digitalWrite(red, HIGH);
}
}
