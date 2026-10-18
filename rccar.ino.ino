char data; // Variable to store received data

// Define motor control pins
#define MOTOR_A_PIN1 7
#define MOTOR_A_PIN2 6
#define MOTOR_B_PIN1 5
#define MOTOR_B_PIN2 4

// Define PWM pins for speed control
#define MOTOR_A_SPEED 9
#define MOTOR_B_SPEED 10

void setup() {
  Serial.begin(9600);

  pinMode(MOTOR_A_PIN1, OUTPUT); 
  pinMode(MOTOR_A_PIN2, OUTPUT);
  pinMode(MOTOR_B_PIN1, OUTPUT);
  pinMode(MOTOR_B_PIN2, OUTPUT);

  pinMode(MOTOR_A_SPEED, OUTPUT);
  pinMode(MOTOR_B_SPEED, OUTPUT);

  analogWrite(MOTOR_A_SPEED, 255);
  analogWrite(MOTOR_B_SPEED, 255);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();

    switch (data) {

      // L → FORWARD
      case 'L':
        digitalWrite(MOTOR_A_PIN1, HIGH);
        digitalWrite(MOTOR_A_PIN2, LOW);
        digitalWrite(MOTOR_B_PIN1, HIGH);
        digitalWrite(MOTOR_B_PIN2, LOW);
        analogWrite(MOTOR_A_SPEED, 255);
        analogWrite(MOTOR_B_SPEED, 255);
        break;

      // R → BACKWARD
      case 'R':
        digitalWrite(MOTOR_A_PIN1, LOW);
        digitalWrite(MOTOR_A_PIN2, HIGH);
        digitalWrite(MOTOR_B_PIN1, LOW);
        digitalWrite(MOTOR_B_PIN2, HIGH);
        analogWrite(MOTOR_A_SPEED, 255);
        analogWrite(MOTOR_B_SPEED, 255);
        break;

      // F → LEFT
      case 'F':
        digitalWrite(MOTOR_A_PIN1, LOW);
        digitalWrite(MOTOR_A_PIN2, HIGH);
        digitalWrite(MOTOR_B_PIN1, HIGH);
        digitalWrite(MOTOR_B_PIN2, LOW);
        analogWrite(MOTOR_A_SPEED, 255);
        analogWrite(MOTOR_B_SPEED, 255);
        break;

      // B → RIGHT
      case 'B':
        digitalWrite(MOTOR_A_PIN1, HIGH);
        digitalWrite(MOTOR_A_PIN2, LOW);
        digitalWrite(MOTOR_B_PIN1, LOW);
        digitalWrite(MOTOR_B_PIN2, HIGH);
        analogWrite(MOTOR_A_SPEED, 255);
        analogWrite(MOTOR_B_SPEED, 255);
        break;

      // STOP
      case 'S':
        digitalWrite(MOTOR_A_PIN1, LOW);
        digitalWrite(MOTOR_A_PIN2, LOW);
        digitalWrite(MOTOR_B_PIN1, LOW);
        digitalWrite(MOTOR_B_PIN2, LOW);
        analogWrite(MOTOR_A_SPEED, 0);
        analogWrite(MOTOR_B_SPEED, 0);
        break;
    }
  }
}
