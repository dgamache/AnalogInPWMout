/* Sketch ET156 Lab 3 Analog Input
David Gamache
Use potentiometer to enter a brightness to light an LED
6/28/16
*/
unsigned int brightness=0;
unsigned int data_in = 0;
int led=3;

// Set up the i/o
void setup()
{
	pinMode(led, OUTPUT);
	Serial.begin(9600);
}

// poll the potentiometer and 
void loop()
{
	data_in = analogRead(0); // returns 0 to 1023
  Serial.print("data_in: ");
  Serial.print(data_in);
	brightness = ((float)data_in / 1023.0) * 255.0;
	// calculate the value to drive the brightness of the LED
  Serial.print(" Brightness: ");
	Serial.println(brightness);
	analogWrite(led, brightness);
	delay(400);// wait before testing the pot again
}
