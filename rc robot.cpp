// Motor driver pins
#define ENA 9  // PWM control for Motor A
#define ENB 10 // PWM control for Motor B
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

// Speed levels
int speedHigh = 255; // Maximum speed
int speedMedium = 180; // Medium speed
int speedLow = 100; // Low speed
int currentSpeed = speedMedium; // Default speed

void setup() {
  // Motor control pins as output
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set up Serial Communication for Bluetooth
  Serial.begin(9600);

  // Default motor states
  stopMotors();
}

void loop() {
  // Check if Bluetooth data is available
  if (Serial.available()) {
    char command = Serial.read(); // Read the command from mobile

    switch (command) {
      case 'F': // Move forward
        moveForward(currentSpeed);
        break;

      case 'B': // Move backward
        moveBackward(currentSpeed);
        break;

      case 'L': // Turn left
        turnLeft(currentSpeed);
        break;

      case 'R': // Turn right
        turnRight(currentSpeed);
        break;

      case 'S': // Stop
        stopMotors();
        break;

      case 'H': // High speed
        currentSpeed = speedHigh;
        break;

      case 'M': // Medium speed
        currentSpeed = speedMedium;
        break;

      case 'L': // Low speed
        currentSpeed = speedLow;
        break;

      default:
        stopMotors();
        break;
    }
  }
}

// Function to stop all motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// Function to move forward
void moveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Function to move backward
void moveBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Function to turn left
void turnLeft(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed / 2); // Reduce speed for smoother turns
  analogWrite(ENB, speed);
}

// Function to turn right
void turnRight(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed / 2); // Reduce speed for smoother turns
}
