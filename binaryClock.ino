/*
Script for a binary clock of LEDs - 24h
Microcontroller: Arduino NANO
Created: 09.09.24
Last updated: 10.09.24
Version: 1.3
*/

unsigned long previousMillis = 0;  // Store the last time minutes were updated
const unsigned long interval = 60000;  // 60000 milliseconds = 60 seconds
int minutes = 45;
int hours = 23;

//Declare buttons
int buttonDecrease = A4;
int buttonIncrease = A5;

//Declare hour LEDs
int hourOne = 8;
int hourTwo = 9;
int hourFour = 10;
int hourEight = 11;
int hourSixteen = 12;

//Declare minute LEDs
int minOne = 2;
int minTwo = 3;
int minFour = 4;
int minEight = 5;
int minSixteen = 6;
int minThirtyTwo = 7;

void setup() {
  pinMode(buttonDecrease, INPUT);
  pinMode(buttonIncrease, INPUT);
  
  pinMode (hourOne, OUTPUT);
  pinMode (hourTwo, OUTPUT);
  pinMode (hourFour, OUTPUT);
  pinMode (hourEight, OUTPUT);
  pinMode (hourSixteen, OUTPUT);
  
  pinMode (minOne, OUTPUT);
  pinMode (minTwo, OUTPUT);
  pinMode (minFour, OUTPUT);
  pinMode (minEight, OUTPUT);
  pinMode (minSixteen, OUTPUT);
  pinMode (minThirtyTwo, OUTPUT);
  
  Serial.begin(9600); //Serial for testin purposes
}

/*
LOOP FUNCTION
First section keeps the time to a minute
Ensures that time does not go below 0 or above 23:59
Also included two buttons that increase or decrease the minute by 1
Lastly it lights up the LEDs based on the values in hour and minutes
*/


void loop() {
  unsigned long currentMillis = millis();
  
  // Check if 60 seconds have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Update the time
    minutes++;  // Increment the minutes

    // When minutes reach 60, reset to 0 and increment hours
    if (minutes >= 60) {
      minutes = 0;
      hours++;
      
      // Reset hours after 24 (for 24-hour clock)
      if (hours >= 24) {
        hours = 0;
      }
    }
  }

  // Check button presses
  if (digitalRead(buttonIncrease) == HIGH) {
    minutes++;
    if (minutes >= 60) {
      minutes = 0;
      hours++;
      if (hours >= 24) {
        hours = 0;
      }
    }
    delay(200);  // Debouncing delay
  }
  
  if (digitalRead(buttonDecrease) == HIGH) {
    if (minutes > 0) {
      minutes--;
    } else {
      minutes = 59;
      if (hours > 0) {
        hours--;
      } else {
        hours = 23;
      }
    }
    delay(200);  // Debouncing delay
  }

  // Print the time - for testing purposes
  Serial.print("Hours: ");
  Serial.print(hours);
  Serial.print(" Minutes: ");
  Serial.println(minutes);
  delay(1000);
  
  //Binary representation of hours: use bitwise operations
  digitalWrite(hourOne, (hours & 0b00001) ? HIGH : LOW);
  digitalWrite(hourTwo, (hours & 0b00010) ? HIGH : LOW);
  digitalWrite(hourFour, (hours & 0b00100) ? HIGH : LOW);
  digitalWrite(hourEight, (hours & 0b01000) ? HIGH : LOW);
  digitalWrite(hourSixteen, (hours & 0b10000) ? HIGH : LOW);
  
  // Binary representation of minutes: use bitwise operations
  digitalWrite(minOne, (minutes & 0b000001) ? HIGH : LOW);
  digitalWrite(minTwo, (minutes & 0b000010) ? HIGH : LOW);
  digitalWrite(minFour, (minutes & 0b000100) ? HIGH : LOW);
  digitalWrite(minEight, (minutes & 0b001000) ? HIGH : LOW); 
  digitalWrite(minSixteen, (minutes & 0b010000) ? HIGH : LOW);
  digitalWrite(minThirtyTwo, (minutes & 0b100000) ? HIGH : LOW); 
  
}
