const int trigPin = 12;
const int echoPin = 13;
const float speedOfSound = 0.0343f;

long duration;
int distance;

const int red = 4;
const int yellow = 5;
const int green = 6;

void setup() {
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(red, OUTPUT);
	pinMode(yellow, OUTPUT);
	pinMode(green, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	duration = pulseIn(echoPin, HIGH);
	distance = duration * speedOfSound / 2;

	if(distance < 11) {
		digitalWrite(red, HIGH);
		digitalWrite(green, LOW);
		digitalWrite(yellow, LOW);
	} else if(distance < 36) {
		digitalWrite(yellow, HIGH);
		digitalWrite(red, LOW);
		digitalWrite(green, LOW);
	} else if(distance > 60) {
		digitalWrite(green, HIGH);
		digitalWrite(yellow, LOW);
		digitalWrite(red, LOW);
	}

	delay(200);
}