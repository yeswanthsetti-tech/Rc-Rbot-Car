Components
Arduino Uno
L298N Motor Driver
HC-05 Bluetooth Module
4 Motors (12V, 120 torque)
12V Battery
Mobile App (e.g., Arduino Bluetooth Controller or any custom app)
Circuit Connections
L298N to Motors:

OUT1 -> Motor 1 positive terminal
OUT2 -> Motor 1 negative terminal
OUT3 -> Motor 2 positive terminal
OUT4 -> Motor 2 negative terminal
L298N to Arduino:

IN1 -> Pin 7
IN2 -> Pin 6
IN3 -> Pin 5
IN4 -> Pin 4
ENA -> Pin 9 (PWM for speed control)
ENB -> Pin 10 (PWM for speed control)
Bluetooth Module:

VCC -> 5V
GND -> GND
TXD -> RX (Pin 0)
RXD -> TX (Pin 1)





Here are the detailed connections for your RC car project:

Connections for L298N Motor Driver to Motors
For 4 Motors:
Motor 1:

Positive terminal -> OUT1 of L298N
Negative terminal -> OUT2 of L298N
Motor 2:

Positive terminal -> OUT3 of L298N
Negative terminal -> OUT4 of L298N
Connections for L298N Motor Driver to Arduino
Control Pins:
ENA (Enable Motor A) -> Pin 9 of Arduino (PWM control for speed)
IN1 -> Pin 7 of Arduino
IN2 -> Pin 6 of Arduino
ENB (Enable Motor B) -> Pin 10 of Arduino (PWM control for speed)
IN3 -> Pin 5 of Arduino
IN4 -> Pin 4 of Arduino
Power Pins:
12V (Power input) -> Positive terminal of the 12V battery
GND (Ground) -> Negative terminal of the 12V battery and GND of Arduino
5V (Output) -> 5V pin of Arduino
Connections for HC-05 Bluetooth Module
VCC -> 5V pin of Arduino
GND -> GND pin of Arduino
TX -> RX pin of Arduino (Pin 0)
RX -> TX pin of Arduino (Pin 1)
Connections for 12V Battery
Positive terminal -> 12V input pin on the L298N motor driver
Negative terminal -> GND pin on the L298N motor driver (also connected to Arduino GND)


Power Supply:

Use the 12V battery to power the L298N motor driver.
The L298N provides 5V power to the Arduino via the 5V output pin.
Ground Connection:

Ensure all GND pins (Arduino, L298N, and the battery) are connected together for proper operation.
Bluetooth Setup:

Pair the HC-05 with your mobile device before testing.
Use a mobile app to send commands like F, B, L, R, etc.
