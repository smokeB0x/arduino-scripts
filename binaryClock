/*
Script for a binary clock of LEDs - 24h
Microcontroller: Arduino NANO
Created: 09.09.24
Version: 1.0
*/

//Not shure if I want to use this lib or not
//#include <TimeLib.h>

// Define the output pins of the LEDs and the buttons
int hourOne = ;
int hourTwo = ;
int hourFour = ;
int hourEight = ;
int hourSixteen = ;

int minOne = ;
int minTwo = ;
int minFour = ;
int minEight = ;
int minSixteen = ;
int minThirtyTwo = ;

int buttonIncrease = ;
int buttonDecrease = ;

//Define the output of the LEDs to be OUTPUT and the buttons to be INPUT
void setup() {

pinMode(hourOne, OUTPUT);
pinMode(hourTwo, OUTPUT);
pinMode(hourFour, OUTPUT);
pinMode(hourEight, OUTPUT);
pinMode(hourSixteen, OUTPUT);

pinMode(minOne, OUTPUT);
pinMode(minTwo, OUTPUT);
pinMode(minFour, OUTPUT);
pinMode(minEight, OUTPUT);
pinMode(minSixteen, OUTPUT);
pinMode(minThirtyTwo, OUTPUT);

pinMode(buttonIncrease, INPUT);
pinMode(buttonDecrease, INPUT);

Serial.begin(9600);
}

/*
TIME KEEPER FUNCTION
A function that keeps the time to a minute
Ensure that time does not go below 0 or above 23:59
*/

int timeKeeper(){

  unsigned long seconds = (millis() / 1000) % 3600;

  return seconds;
}

void loop() {
//Print the time every 5 seconds as a test
Serial.println(timeKeeper());
delay(5000);

}

/* TODO
BUTTON PRESS FUNCTION
Two button inputs
Function to increase the time with 60 seconds if one button is pressed, and decrease it with 60 seconds if the other is pressed
*/

/* TODO
LED POWER FUNCTION
Function that powers the correct LEDs based on the value in the time keeper function
*/
