# mbed-password-door-lock

# Password-Based Door Lock System

## Overview

This project implements a **password-based door locking system** using an **mbed C++** program on the **Nucleo F152RE** board. The system takes a \*\*4-digit password \*\* via a keypad, displays feedback on an LCD, and controls a **servo motor** to unlock the door upon correct entry.

![image](https://github.com/user-attachments/assets/c79fed72-53ea-467e-8e14-7079272d8b1b) ![image](https://github.com/user-attachments/assets/56ad81b9-5101-4165-a78e-81f343f7ac14)



## Features

- **User Authentication**: Accepts a 4-digit password via a 4x4 keypad.
- **LCD Display**:
  - "Enter Password" message on the first line.
  - Asterisk (\*) symbols for each digit entered on the second line.
  - "Correct Password" and "Door Opening" on success.
  - "Incorrect Password" and "Door Can’t Open" on failure.
- **Servo Motor Control**:
  - Activates to unlock the door upon successful password entry.
- **Buzzer Alert**:
  - Activates if an incorrect password is entered.
- **Operates in 4-bit Mode**:
  - LCD is connected with **EN** and **RS** active states.

## How It Works

1. The system displays "Enter Password" on the LCD.
2. The user enters a **4-digit password** using the keypad.
3. The system displays `* * * *` on the second line of the LCD as the password is entered.
4. After entering 4 digits:
   - If the password is correct:
     - LCD displays "Correct Password" and "Door Opening".
     - The **servo motor** activates to unlock the door.
   - If the password is incorrect:
     - LCD displays "Incorrect Password" and "Door Can’t Open".
     - The **buzzer** activates for an alert.
5. The system resets for the next password entry.

## Components Required

1. **STM32 Nucleo F152RE** board
2. **16x2 LCD display** (4-bit mode)
3. **4x4 Keypad**
4. **Servo motor**
5. **Buzzer**
6. **Resistors and connecting wires**

## Diagram 

![image](https://github.com/user-attachments/assets/e2ec8ac8-e068-4d65-8dc8-9c97f42cfe3e)



## Applications

- **Home Security**: Can be used to secure residential doors with password-based access.
- **Office and Industrial Security**: Used to restrict access to authorized personnel only.
- **Safe and Locker Systems**: Can be integrated into safes for secure access control.
- **Automated Entry Systems**: Used in buildings, labs, and server rooms for secure authentication.

## Future Enhancements

- **Add EEPROM Storage** for saving multiple passwords.
- **Use RFID for alternative authentication.**
- **Integrate IoT features** for remote access.

## License

MIT License.

