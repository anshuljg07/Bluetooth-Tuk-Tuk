# Bluetooth-Controlled Tuk Tuk

## Overview

This repository contains the documentation and code for a Bluetooth-controlled Tuk Tuk, an embedded systems project that allows remote control of a Tuk Tuk vehicle using a mobile app. The project leverages an ATMega328P microcontroller, various peripherals, and communication interfaces to achieve this functionality.
<br />
<br />
<img width="400" alt="Screen Shot 2024-01-25 at 3 15 03 PM" src="https://github.com/anshuljg07/Bluetooth-Tuk-Tuk/assets/72891464/0b3847d9-765a-4676-8df6-13054946066f">
<img width="500" alt="Screen Shot 2024-01-25 at 3 15 03 PM" src="https://github.com/anshuljg07/Bluetooth-Tuk-Tuk/assets/72891464/c2856166-a316-479f-90da-8abd64e953bf">
<br />
## Table of Contents

- Schematic
- Technical Details
  - Hardware Components
    - Motor Drivers and Power Supply
    - Micro Servomotor SG90
  - Communication Interfaces
    - USART Communication
  - PWM Control
  - Software Implementation
- Conclusion

## Schematic
<img width="500" alt="Screen Shot 2024-01-25 at 3 15 03 PM" src="https://github.com/anshuljg07/Bluetooth-Tuk-Tuk/assets/72891464/f5d57d04-c806-4c6e-85b7-64662923b92d">

## Technical Details

### Hardware Components

#### Motor Drivers and Power Supply

- **Motor Driver**: The project employs the L298N Dual H-bridge Motor Driver to control two 7.2V DC motors responsible for the Tuk Tuk's movement. The motor driver acts as an interface between the microcontroller and the motors, amplifying PWM signals to meet the motors' power requirements.

- **Voltage Amplification**: To power the 7.2V DC motors, a higher voltage source (typically a 9V battery) is used. The motor driver amplifies the PWM signals to match the voltage source, ensuring adequate power supply to the motors.

#### Micro Servomotor SG90

- **Steering Control**: The Tuk Tuk's steering is controlled using a Micro-Servomotor SG90 attached to a pivotable front wheel. The servomotor allows for incremental rotations based on PWM signals, with specific on-times corresponding to different steering angles.

### Communication Interfaces

#### USART Communication

- **USART Interface**: USART (Universal Synchronous and Asynchronous Receiver-Transmitter) is employed as the communication protocol between the Arduino microcontroller and the HM-10 Bluetooth module. This bi-directional serial communication interface enables seamless data exchange between the two devices.

- **Configuration**: The USART interface is configured with a baud rate of 9600 to ensure synchronized data transfer between the microcontroller and the Bluetooth module. This ensures reliable communication between the mobile app terminal and the embedded system.

### PWM Control

- **DC Motor Speed Control**: PWM signals are used to control the speed of the DC motors, offering options such as "Fast," "Normal," and "Slow" speed modes. Adjusting the duty cycle of the PWM signal regulates the average voltage applied to the motors, resulting in different motor speeds.

- **Servo Motor Position Control**: PWM signals precisely control the position of the Micro-Servomotor SG90 for steering. Each position is defined by a specific on-time duration within the PWM signal. For instance, a 1 ms on-time corresponds to a 90-degree left turn, while a 2 ms on-time results in a 90-degree right turn. By adjusting the PWM on-time, the servo motor's position is accurately manipulated to achieve desired turns or maintain a straight path.

### Software Implementation

- **Main Program Logic**: The Tuk Tuk is controlled through an infinite loop that constantly checks for new data from the USART interface. User commands, such as "Fast," "Normal," "Slow," "Left," "Right," "Backup," and "Stop," are received through Bluetooth and processed to adjust the motor speeds and steering angle accordingly.

- **Micro Servomotor Control**: Timer/Counter 0 is used to generate PWM signals for the servomotor. The PWM settings are configured to achieve the desired steering angles.

- **DC Motor Control via H Bridge Motor Driver**: Timer/Counter 2 generates PWM signals to control the speed of both DC motors. The duty cycle of the PWM signal adjusts the voltage applied to the motors, allowing for variable speeds.

- **HM-10 USART Interface**: The USART interface handles communication between the Bluetooth module and the Arduino. Baud rate settings and USART initialization ensure seamless data exchange between the mobile app and the embedded system.

## Conclusion

The project's combination oof diverse peripherals working together created a robust system. Our experience and comfort with serial communication, facilitated by the USART interface, grew significantly, and we learned about Bluetooth's usefulness in standalone systems. In addition, dealing with the motor driver made us consider power and voltage requirements for our system's operation.

Making this bluetooth controlled Tuk Tuk was a fantastic challenge and was one of the most fun projects we have done!

## Contributors
This project was developed and is currently maintained by Anshul Gowda and Rafael Ragel de la Tejera.

## Get in Contact:
 [Anshul Gowda's LinkedIn](https://www.linkedin.com/in/anshul-gowda)
<br />
Rafa Rangel de la Tejera's LinkedIn
<br />
