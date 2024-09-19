#include<Arduino.h>
// Pin definitions for inputs and output
const int selectPin = 2;    // Select line (S)
const int input1Pin = 3;    // Input 1
const int feedbackPin = 4;  // Feedback (Inverted Input 0)
const int outputPin = 5;    // Output pin (Y)

// Function to calculate the multiplexer output and display the result
void testMultiplexer(int S, int feedback, int input1) {
  // Boolean equation for 2x1 multiplexer
  int outputValue = (!S && feedback) || (S && input1);

  // Set the output pin based on the result of the Boolean logic
  digitalWrite(outputPin, outputValue);

  // Output the result to the Serial Monitor
  Serial.print("Select Pin (S): ");
  Serial.print(S);
  Serial.print(" | Input 1: ");
  Serial.print(input1);
  Serial.print(" | Feedback (Inverted Input 0): ");
  Serial.print(feedback);
  Serial.print(" | Output (Y): ");
  Serial.println(outputValue);
}

void setup() {
  // Initialize pins for inputs
  pinMode(selectPin, INPUT);
  pinMode(input1Pin, INPUT);
  pinMode(feedbackPin, INPUT);

  // Initialize output pin
  pinMode(outputPin, OUTPUT);

  // Start Serial communication to monitor the output
  Serial.begin(9600);
}

void loop() {
  // Read input values from digital pins
  int S = digitalRead(selectPin);      // Select line (S)
  int input1 = digitalRead(input1Pin); // Input 1 state
  int feedback = digitalRead(feedbackPin); // Feedback (inverted output)

  // Test the multiplexer with the read values
  testMultiplexer(S, feedback, input1);

  delay(3000);  // Wait before repeating or exiting

  // If you want the loop to stop after testing all cases, you can include:
  // while (true);  // Uncomment this to stop the loop
}

