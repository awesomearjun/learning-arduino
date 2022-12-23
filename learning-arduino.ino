const int redButton = 1;
const int greenButton = 2;
const int blueButton = 3;

const int redPin = 8;
const int greenPin = 10;
const int bluePin = 9;

const float incrementor = 0.1f;

int redState = 0;
int greenState = 0;
int blueState = 0;

float red;
float green;
float blue;

void setup() {
	pinMode(redButton, INPUT);
	pinMode(greenButton, INPUT);
	pinMode(blueButton, INPUT);

	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	redState = digitalRead(redButton);
	greenState = digitalRead(greenButton);
	blueState = digitalRead(blueButton);

	if(redState == LOW) {
		red += incrementor;
	} else if(greenState == LOW) {
		green += incrementor;
	} else if (blueState == LOW) {
		blue += incrementor;
	}

	digitalWrite(redPin, red);
	digitalWrite(greenPin, green);
	digitalWrite(bluePin, blue);
}