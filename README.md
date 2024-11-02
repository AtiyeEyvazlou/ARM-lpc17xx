# ARM-lpc17xx
A repository for ARM Cortex-M3 development using the LPC17xx series microcontrollers. This collection includes main files for various embedded functionalities, designed to be used with CMSIS libraries. Each file is an independent project.
![lpc1768](http://mbed.org/media/uploads/synvox/lpc1768_mbed_pinout.gif)
# ARM-lpc17xx

A repository for ARM Cortex-M3 development using the LPC17xx series microcontrollers. This collection includes main files for various embedded functionalities, designed to be used with CMSIS libraries. Each file can be set up as an independent project.

## Table of Contents
- [About](#about)
- [Features](#features)
- [File Overview](#file-overview)
- [Setup](#setup)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

---

## About

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
- **RTOS.c**: Provides a basic RTOS configuration.
- **i2c-master.c / i2c-slave.c**: Master and slave I2C communication examples.
- **timer.c**: Manages timer setup and interrupts.
