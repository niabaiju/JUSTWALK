#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 8
#define motorPin1 9 // New pin for the Vibe Board
#define motorPin2 10
#define motorPin3 11

long duration, distance, RightSensor, BackSensor, FrontSensor, LeftSensor;

void setup()
{
    Serial.begin (9600);
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT); // Set the Vibe Board pin as OUTPUT
}

void loop() {
    SonarSensor(trigPin1, echoPin1);
    RightSensor = distance;
    SonarSensor(trigPin2, echoPin2);
    LeftSensor = distance;
    SonarSensor(trigPin3, echoPin3);
    FrontSensor = distance;

    digitalWrite(9, HIGH);

    // // If any sensor reads a distance of 70cm or less, vibrate the Vibe Board
    // if (RightSensor <= 70 || LeftSensor <= 70 || FrontSensor <= 70) {
    //     digitalWrite(9, HIGH); // Vibrate the Vibe Board
    // } else {
    //     digitalWrite(9, LOW); // Stop the vibration
    // }

        // If any sensor reads a distance of 70cm or less, vibrate the Vibe Board
    if (RightSensor <= 80) {
        digitalWrite(motorPin1, HIGH); // Vibrate the Vibe Board
    } else {
        digitalWrite(motorPin1, LOW); // Stop the vibration
    }

             // If any sensor reads a distance of 70cm or less, vibrate the Vibe Board
    if (FrontSensor <= 80) {
        digitalWrite(motorPin2, HIGH); // Vibrate the Vibe Board
    } else {
        digitalWrite(motorPin2, LOW); // Stop the vibration
    }

      // If any sensor reads a distance of 70cm or less, vibrate the Vibe Board
    if (LeftSensor <= 80) {
        digitalWrite(motorPin3, HIGH); // Vibrate the Vibe Board
    } else {
        digitalWrite(motorPin3, LOW); // Stop the vibration
    }

    Serial.print(LeftSensor);
    Serial.print(" - ");
    Serial.print(FrontSensor);
    Serial.print(" - ");
    Serial.println(RightSensor);
}

void SonarSensor(int trigPin,int echoPin)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
}