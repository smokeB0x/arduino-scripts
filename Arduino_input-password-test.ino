//Script to demonstrate reading and writing over UART.
//The user is prompted for a password and must input the right one to get the secret message.

const String password = "Hunter2"; // Define the correct password
String inputString = "";         // A string to hold incoming data

void setup() {
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);
  Serial.println("Enter the secret password to find the cake:");
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    char incomingChar = Serial.read(); // Read a single character

    // Echo the character back to the Serial Monitor
    Serial.print(incomingChar);

    // Check if the character is a newline (Enter key) or carriage return
    if (incomingChar == '\n' || incomingChar == '\r') {
      // Check if the input string matches the password
      if (inputString.equals(password)) {
        Serial.println("\nThe cake is a lie!");
        delay(5000);
        Serial.println("\nBut the password was correct\n");
      } else {
        Serial.println("\nAccess denied. Wrong password.");
      }

      // Clear the input string
      inputString = "";
      Serial.println("Enter the secret password to find the cake:");
    } else {
      // Append the incoming character to the input string
      inputString += incomingChar;
    }
  }
}
