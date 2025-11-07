/*****************************************************************************
 * MORSEKODSAVKÄNNARE
 * av Fredrik Jonsäll senast ändrad 2019-09-27
 * 
 */

#include <time.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

/* Skapar variabler för pins / tidsmätning / lagra morsealfabetet via binär kodning */
const int buttonPin = 5; // digital ingång används för inkoppling av knapp
const unsigned long longPress = 250; // om knapp intryckt längre än detta i millisekunder - lång signal
const unsigned long longPaus = 1000; // om knapp släppt längre än detta i millisekunder - ny bokstav
const String alfabet="etianmsurwdkgohvf l pjbxcyzq  54 3   2        6        7   8 90"; //används av morsetolkare
const char kort='.', lang='-'; // kort och lång signal sparas i ord för tolkning till bokstav.

unsigned long startTime = 0; // används för att lagra startpunkt för tidsmätning
unsigned long onTime = 0 ; // används för att spara hur lång tid knappen varit intryckt
unsigned long offTime = 0; // används för att spara hur lång tid knappen varit släppt 
String morseKod =""; //används för att spara knapptryckningar

/*skapar ett objekt för att skicka meddelanden till en lcd-skärm inkopplad via I2C  
        lcdPin - arduinoNanoPin: GND - GND , VCC - 5V, SDA - A4, SCL - A5 */
boolean LCD = true;
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  /* deklarerar port som en ingång */
  pinMode(buttonPin, INPUT);
  /* sätter igång seriekommunikation via usb */
  Serial.begin(9600);
  /* initierar vår lcdskärm för användning */
  if(LCD == true ){
    lcd.init();
    lcd.backlight();
  }
  
}

void loop() {
  startTime=millis();

  while(!digitalRead(buttonPin)){     //väntar på att knappen blir intryckt
     offTime=millis();
     if( (offTime - startTime) > longPaus ) {
       morsetolkare(morseKod, LCD);
       morseKod = "";
       break;
     }
  }
  while(!digitalRead(buttonPin));
  
  startTime = millis(); 
  onTime=millis();
  while( (onTime - startTime)<longPress){
    if (!digitalRead(buttonPin)) { 
      morseKod += kort;
      break;
    }
    
    onTime=millis();
    
  }
  if((onTime - startTime)>=longPress) morseKod += lang;
  while (digitalRead(buttonPin));
}

void morsetolkare(String morse, boolean i2c){
  int index=0, indexBas=2^(morse.length())-2;
  if (morse.length()==0);
  else {
    for (int i=0; i<(morse.length()-1); i++){
      index*=2;
      if(morse[i]==lang) index+=1;
    }
    if (i2c== true) lcd.write(alfabet[index+indexBas]);
    else Serial.println(alfabet[index+indexBas]);
   }
}

