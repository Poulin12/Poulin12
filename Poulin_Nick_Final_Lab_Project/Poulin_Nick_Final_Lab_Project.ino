// Define connection pins:
#define pirPin 2
#define pirPin 7
#define ledPin 13
#define ledPin 10
#define LED 7
// Create variables:
int val = 0;
bool motionState = false; // We start with no motion detected.

#include <LiquidCrystal.h> // adapting for the lcd display, lcd = liquid crystal display

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 8; // creatinf the corresponding inputs
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // display ports recognized by lcd


void setup() {
  // Configure the pins as input or output:
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
pinMode(LED, OUTPUT);
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

  
}

void loop() {
  // Read out the pirPin and store as val:
  val = digitalRead(pirPin);

  // If motion is detected (pirPin = HIGH), do the following:
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the on-board LED.

  digitalWrite(LED, HIGH);
    // Change the motion state to true (motion detected):
    if (motionState == false) {
      Serial.println("Motion detected!");
      motionState = true;



      lcd.begin(26, 2); // lcd rows and columns 
  lcd.print("Nick Poulin Lab8"); // msg for the top line of the lcd 
  lcd.setCursor(0,1); // indentation form line 1 to line 2
  lcd.print("Lab 002 11/5/21"); // msg for bottom 

    }
  }

  // If no motion is detected (pirPin = LOW), do the following:
  else {
    digitalWrite(ledPin, LOW); // Turn off the on-board LED.
digitalWrite(LED,LOW);
    // Change the motion state to false (no motion):
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;



          lcd.begin(26, 2); // lcd rows and columns 
  lcd.print("Go Away, walk by"); // msg for the top line of the lcd 
  lcd.setCursor(0,1); // indentation form line 1 to line 2
  lcd.print(" for a surpise"); // msg for bottom 

  
    }
  }
}
