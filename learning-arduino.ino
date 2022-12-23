const int redButton = 1;
const int greenButton = 2;
const int blueButton = 3;
const int flagButton = 13;

const int redPin = 8;
const int greenPin = 10;
const int bluePin = 9;

const int greenLED = 7;
const int redLED = 6;

bool flag = true;

const float incrementor = 1.0f;

int redState = 0;
int greenState = 0;
int blueState = 0;
int flagState = 0;

float red = 0.0f;
float green = 0.0f;
float blue = 0.0f;

void setup() {
	pinMode(redButton, INPUT);
	pinMode(greenButton, INPUT);
	pinMode(blueButton, INPUT);

	pinMode(greenLED, OUTPUT);
	pinMode(redLED, OUTPUT);

	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	redState = digitalRead(redButton);
	greenState = digitalRead(greenButton);
	blueState = digitalRead(blueButton);
	flagState = digitalRead(flagButton);

	if(flagState == LOW) {
		flag = !flag;
	}

	if(flag) {
		digitalWrite(greenLED, HIGH);
		digitalWrite(redLED, LOW);
	} else {
		digitalWrite(redLED, HIGH);
		digitalWrite(greenLED, LOW);
	}

	if(redState == LOW && flag && red < 255) {
		red += incrementor;
	} else if(greenState == LOW && flag && green < 255) {
		green += incrementor;
	} else if (blueState == LOW && flag && blue < 255) {
		blue += incrementor;
	}

	if(redState == LOW && !flag && red > 0) {
		red -= incrementor;
	} else if(greenState == LOW && !flag && green > 0) {
		green -= incrementor;
	} else if (blueState == LOW && !flag && blue > 0) {
		blue -= incrementor;
	}

	if(red > 255) {
		red = 255;
	} else if(green > 255) {
		green = 255;
	} else if(blue > 255) {
		blue = 255;
	}

	digitalWrite(redPin, red);
	digitalWrite(greenPin, green);
	digitalWrite(bluePin, blue);
}