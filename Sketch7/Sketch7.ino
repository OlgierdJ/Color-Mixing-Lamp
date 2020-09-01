/*
 Name:		Sketch7.ino
 Created:	7/28/2020 9:52:01 AM
 Author:	Janie
*/
#pragma region Variables
const int redLED = 11, greenLED = 9, blueLED = 10, redSensorPin = A0, greenSensorPin = A1, blueSensorPin = A2;

int redValue = 0, greenValue = 0, blueValue = 0, redSensorValue = 0, greenSensorValue = 0, blueSensorValue = 0;
#pragma endregion

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);

	pinMode(redLED, OUTPUT);
	pinMode(greenLED, OUTPUT);
	pinMode(blueLED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	redSensorValue = analogRead(redSensorPin);
	delay(5);
	greenSensorValue = analogRead(greenSensorPin);
	delay(5);
	blueSensorValue = analogRead(blueSensorPin);
	Serial.print("Raw sensor values \t red: ");
	Serial.print(redSensorValue);
	Serial.print("\t green: ");
	Serial.print(greenSensorValue);
	Serial.print("\t blue: ");
	Serial.println(blueSensorValue);

	redValue = redSensorValue / 4;
    greenValue = greenSensorValue / 4;
	blueValue = blueSensorValue / 4;

	Serial.print("Mapped sensor values \t red: ");
	Serial.print(redValue);
	Serial.print("\t green: ");
	Serial.print(greenValue);
	Serial.print("\t blue: ");
	Serial.println(blueValue);

	analogWrite(redLED, redValue);
	analogWrite(greenLED, greenValue);
	analogWrite(blueLED, blueValue);
}
