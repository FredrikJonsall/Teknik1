//Includes:
#include <math.h> //contains common math functions
//Variables:
void setup() {
// put your setup code here, to run once:
Serial.begin(9600); //Start serial
Serial.println("Rather than reinvent the wheel I used code found at: ");
Serial.println("http://forum.arduino.cc/index.php?topic=209133.0");
}
void loop() {
// put your main code here, to run repeatedly:
Serial.print(Thermister(analogRead(A0))); //This is basically saying - first run the Thermister function, passing in the value from the sensor, then print the returned value to the console
Serial.println("c"); //then print the c for celcius, and send a newline character (as denoted by the println rather than print
delay(500); //wait half a second before repeating
}
//custom functions
double Thermister(int RawADC) {
double Temp;
Temp = log(((10240000/RawADC) - 10000));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = Temp - 273.15;// Convert Kelvin to Celcius
return Temp;
}
