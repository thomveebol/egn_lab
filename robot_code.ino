// Define pins
const int TRIG_PIN = 7;
const int ECHO_PIN = 8;
const int MAX_DISTANCE = 15;

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 9;
const int IN4 = 10;

void setup() {

// Initialize pins
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);

// Initialize serial
Serial.begin(9600);
}

void loop() {

// Get distance
int distance = getDistance();

// Wheels follow hand if close
if(distance <= MAX_DISTANCE) {

// Turn both wheels forward
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);

// Otherwise stop
} else {

digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

}

}

// Get distance from ultrasonic sensor
int getDistance() {

digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);

long duration = pulseIn(ECHO_PIN, HIGH);
int distance = duration * 0.034 / 2;

return distance;
}