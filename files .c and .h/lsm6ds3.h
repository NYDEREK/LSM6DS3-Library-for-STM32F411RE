#ifndef LSM6DS3_H
#define LSM6DS3_H

#include <stdint.h>
#include "stm32f4xx_hal.h"

// LSM6DS3 registers
#define LSM6DS3_REG_WHO_AM_I        0x0F
#define LSM6DS3_REG_CTRL1_XL        0x10
#define LSM6DS3_REG_CTRL2_G         0x11
#define LSM6DS3_REG_OUTX_L_XL       0x28
#define LSM6DS3_REG_OUTX_L_G        0x22

// LSM6DS3 WHO_AM_I value
#define LSM6DS3_WHO_AM_I            0x69

// LSM6DS3 CTRL1_XL register bits
#define LSM6DS3_CTRL1_XL_ODR_MASK   0xF0
#define LSM6DS3_CTRL1_XL_ODR_POWERDOWN  0x00
#define LSM6DS3_CTRL1_XL_ODR_13HZ  0x10
#define LSM6DS3_CTRL1_XL_ODR_26HZ  0x20
#define LSM6DS3_CTRL1_XL_ODR_52HZ  0x30
#define LSM6DS3_CTRL1_XL_ODR_104HZ 0x40
#define LSM6DS3_CTRL1_XL_ODR_208HZ 0x50
#define LSM6DS3_CTRL1_XL_ODR_416HZ 0x60
#define LSM6DS3_CTRL1_XL_ODR_833HZ 0x70
#define LSM6DS3_CTRL1_XL_ODR_1_66KHZ 0x80
#define LSM6DS3_CTRL1_XL_ODR_3_33KHZ 0x90
#define LSM6DS3_CTRL1_XL_ODR_6_66KHZ 0xA0
#define LSM6DS3_CTRL1_XL_FS_MASK   0x0C
#define LSM6DS3_CTRL1_XL_FS_2G     0x00
#define LSM6DS3_CTRL1_XL_FS_16G    0x04
#define LSM6DS3_CTRL1_XL_FS_4G     0x08
#define LSM6DS3_CTRL1_XL_FS_8G     0x0C

// LSM6DS3 CTRL2_G register bits
#define LSM6DS3_CTRL2_G_ODR_MASK   0xF0
#define LSM6DS3_CTRL2_G_ODR_POWERDOWN  0x00
#define LSM6DS3_CTRL2_G_ODR_13HZ  0x10
#define LSM6DS3_CTRL2_G_ODR_26HZ  0x20
#define LSM6DS3_CTRL2_G_ODR_52HZ  0x30
#define LSM6DS3_CTRL2_G_ODR_104HZ 0x40
#define LSM6DS3_CTRL2_G_ODR_208HZ 0x50
#define LSM6DS3_CTRL2_G_ODR_416HZ 0x60
#define LSM6DS3_CTRL2_G_ODR_833HZ 0x70
#define LSM6DS3_CTRL2_G_ODR_1_66KHZ 0x80
#define LSM6DS3_CTRL2_G_ODR_3_33KHZ 0x90
#define LSM6DS3_CTRL2_G_ODR_6_66KHZ 0xA0
#define LSM6DS3_CTRL2_G_FS_MASK   0x0C
#define LSM6DS3_CTRL2_G_FS_245DPS  0x00
#define LSM6DS3_CTRL2_G_FS_500DPS  0x04
#define LSM6DS3_CTRL2_G_FS_1000DPS 0x08
#define LSM6DS3_CTRL2_G_FS_2000DPS 0x0C
// Initialize the LSM6DS3 sensor
int lsm6ds3_init(void);

// Read accelerometer data from the LSM6DS3 sensor
void lsm6ds3_read_accelerometer(int16_t *x, int16_t *y, int16_t *z);

// Read gyroscope data from the LSM6DS3 sensor
void lsm6ds3_read_gyroscope(int16_t *x, int16_t *y, int16_t *z);

#endif // LSM6DS3_H
