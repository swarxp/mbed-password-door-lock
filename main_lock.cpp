#include "mbed.h"
#include "keypad.h"
#include "TextLCD.h"

// Initialize LCD display (RS, E, D4, D5, D6, D7)
TextLCD lcd(PC_0, PC_1, PB_0, PA_4, PA_1, PA_0);

// Initialize keypad (Row pins, Column pins)
Keypad keypad(PA_10, PB_3, PB_5, PB_4, PB_10, PA_8, PA_9, PC_7);

// Initialize buzzer for incorrect password indication
DigitalOut buzzer(PC_6);

// Initialize servo motor for door control
PwmOut servo(PC_8);

// Set the actual password
const char actual[4] = {'1', '2', '3', '4'};

// Array to store entered password
char entered[4];

// Counter variable
int count;

int main() {
    // Enable pull-up resistors for keypad
    keypad.enablePullUp();
    
    while (1) {
        // Clear LCD and prompt user to enter password
        lcd.cls();
        lcd.locate(0, 0);
        lcd.printf("Enter Password ");

        // Set servo to initial position (locked door)
        servo.period_ms(20);
        servo.pulsewidth_us(500);
        buzzer = 0; // Ensure buzzer is off initially

        // Loop to get 4-digit password input from keypad
        for (count = 0; count < 4; count++) {
            while (keypad.getKey() == '\0'); // Wait until a key is pressed
            
            entered[count] = keypad.getKey(); // Store the key pressed
            
            // Display '*' on LCD instead of actual key for security
            lcd.locate(count, 1);
            lcd.printf("*");
            wait(1); // Small delay for readability
        }

        // Compare entered password with actual password
        if ((actual[0] == entered[0]) && (actual[1] == entered[1]) && 
            (actual[2] == entered[2]) && (actual[3] == entered[3])) {
            
            // Password is correct: Open the door
            lcd.cls();
            lcd.locate(0, 0);
            lcd.printf("Correct Password");
            lcd.locate(0, 1);
            lcd.printf("Door opening");

            // Move servo to open position
            servo.period_ms(20);
            servo.pulsewidth_us(1500);
            wait(3); // Keep door open for 3 seconds
        } else {
            // Incorrect password: Deny access
            lcd.cls();
            lcd.locate(0, 0);
            lcd.printf("INCORRECT PW");
            lcd.locate(0, 1);
            lcd.printf("Door Can't open");

            // Activate buzzer to indicate incorrect password
            buzzer = 1;
            wait(3);
            buzzer = 0; // Turn off buzzer after 3 seconds
        }
    }
}
