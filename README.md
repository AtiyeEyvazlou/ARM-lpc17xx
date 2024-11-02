# ARM-lpc17xx
A repository for ARM Cortex-M3 development using the LPC17xx series microcontrollers. This collection includes main files for various embedded functionalities, designed to be used with CMSIS libraries. Each file is an independent project.
![lpc1768](http://mbed.org/media/uploads/synvox/lpc1768_mbed_pinout.gif)

The **ARM-lpc17xx** repository provides main files for core ARM microcontroller functionalities. These files can be adapted into individual projects, each showcasing specific tasks like GPIO control, ADC conversion, and RTOS setup. Code here is designed to be compiled and run with CMSIS libraries for effective ARM Cortex-M3 development.

## Features

- **ADC**: Analog-to-digital conversion (ADC) for processing sensor inputs.
- **GPIO**: Digital input/output (GPIO) operations.
- **LCD Control**: Code to drive LCD displays.
- **RTOS Integration**: Basic RTOS example for multitasking.
- **I2C Communication**: I2C master and slave setup.
- **Timer Setup**: Timer initialization and control.

## File Overview

Each file here represents a standalone "main" file for a specific project. To proceed, set up separate projects for each, integrating the necessary CMSIS libraries:

- **ADC.C**: Initializes and manages the ADC for analog input.
- **GPIO.C**: Manages digital I/O operations.
- **LCD.c**: Controls an LCD display.
- **RTOS.c**:This project includes an RTOS configuration that manages three concurrent tasks: reading voltage via ADC, driving a motor using PWM based on the measured voltage, and displaying the motor speed on an LCD. The tasks are prioritized to ensure optimal performance, with ADC reading set as the highest priority, LCD display as the second, and PWM control as the third.
- **i2c-master.c / i2c-slave.c**: Master and slave I2C communication examples.
- **timer.c**: Manages timer setup and interrupts.
