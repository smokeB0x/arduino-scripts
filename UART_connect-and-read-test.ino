//Script to demonstrate UART
//flash the script to an arduino, then connect to the arduino using a serial adapter to read the output.
//Must use baud rate 115200 when connecting, and connect serial-USB pin RX to the arduino TX (+GND)
void setup() {
  // Initialize the serial communication at 115200 baud rate
  Serial.begin(115200);
}

void loop() {
  // Print the secret password to the serial monitor
  Serial.println("My secret password is: Hunter2");
  // Wait for 5 seconds
  delay(5000);
}
