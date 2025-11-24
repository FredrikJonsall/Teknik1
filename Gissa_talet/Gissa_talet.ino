#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ratt = A0;
int knapp = 2;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(knapp, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int hemligtTal = random(0, 100);  // tal mellan 0 och 100
  int forsok = 0;                  // antalet gissningar som gjorts
  int gissning;
  bool harVunnit = false;

  lcd.setCursor(0, 0);
  lcd.print("Gissa ett nummer");
  lcd.setCursor(0, 1);
  lcd.print("mellan 0 och 99");
  delay(250);

  while (forsok < 5 && harVunnit == false) {
    while (digitalRead(knapp)) {
      gissning = map(analogRead(ratt), -10, 1023, 0, 110);
      gissning = constrain(gissning, 0 , 99);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Gissning: ");
      lcd.print(gissning);
      lcd.setCursor(0, 1);
      lcd.print("Antal forsok: ");
      lcd.print(forsok);
      delay(250);
    }
    delay(300);
    forsok = forsok + 1;  // forsok +=1;   forsok++;
    if (gissning == hemligtTal) {
      harVunnit = true;
    } else if (gissning < hemligtTal) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Talet ar storre!");
      delay(1000);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Talet ar mindre!");
      delay(1000);
    }
  }
  if (harVunnit == false) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DU MISSLYCKADES!");
    lcd.setCursor(0, 1);
    lcd.print("Talet var: ");
    lcd.print(hemligtTal);
    delay(3000);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DU VANN! Tal:");
    lcd.print(hemligtTal);
    lcd.setCursor(0, 1);
    lcd.print("Antal gissn: ");
    lcd.print(forsok);
    delay(3000);
  }

  delay(250);  // medan vi prövar oss fram
}
