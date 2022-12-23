const int buttonPin = 2;
const int ledPin = 3;

int buttonState = 0;
bool flag = false;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT);
}

void loop() {
	buttonState = digitalRead(buttonPin);

	Serial.println(buttonState);

	if(!flag && buttonState == LOW) {
		flag = true;
	} else if (flag && buttonState == LOW) {
		flag = false;
	}

	if(flag) {
		digitalWrite(ledPin, HIGH);
	} else {
		digitalWrite(ledPin, LOW);
	}

	delay(200);
}
