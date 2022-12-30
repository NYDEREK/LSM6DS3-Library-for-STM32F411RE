LSM6DS3 Library for STM32F411RE
This library allows you to easily interface with the LSM6DS3 inertial measurement unit (IMU) on the STM32F411RE microcontroller.

Features
Initialize the LSM6DS3 and configure its settings
Read acceleration and gyroscope data
Set the output data rate and full-scale range for both the accelerometer and gyroscope
Getting Started
To use this library, you will need to have the following tools and libraries installed:

STM32CubeIDE
STM32F4xx HAL Library
Installation
Download the lsm6ds3 folder and add it to your project's Core/Inc and Core/Src directories.
Include the following files in your main project file:

#include "lsm6ds3_config.h"
#include "lsm6ds3.h"

Initialize the LSM6DS3 in your main() function:
lsm6ds3_init();

Read acceleration and gyroscope data in your main loop:
int16_t ax, ay, az;
int16_t gx, gy, gz;
lsm6ds3_read_accelerometer(&ax, &ay, &az);
lsm6ds3_read_gyroscope(&gx, &gy, &gz);

Credits
This library was created by Szymon Nyderek and Assistant, a large language model trained by OpenAI.

License
This project is licensed under the MIT License - see the LICENSE file for details.

This README.txt file should provide enough information for someone to understand what the library does and how to use it. Let me know if you have any questions or need further clarification.
