/*
 * LSM6DS3.c
 *
 *  Created on: Dec 30, 2022
 *      Author: Szymon and chatbot open AI
 */

#include <lsm6ds3.h>
#include "lsm6ds3_config.h"
// I2C handle and other variables
//I2C_HandleTypeDef hi2c1;
uint8_t lsm6ds3_address = 0x6A; // default I2C address for LSM6DS3

// Initialize the LSM6DS3 sensor
int lsm6ds3_init(void)
{
  // Initialize the I2C peripheral (e.g., hi2c1)

  // Check that the LSM6DS3 sensor is present on the I2C bus
  uint8_t who_am_i;
  HAL_I2C_Mem_Read(&hi2c1, lsm6ds3_address, LSM6DS3_REG_WHO_AM_I, I2C_MEMADD_SIZE_8BIT, &who_am_i, 1, 1000);
  if (who_am_i != LSM6DS3_WHO_AM_I)
  {
    // Sensor is not present on the I2C bus
    return -1;
  }

  // Enable the accelerometer and gyroscope
  uint8_t ctrl1_xl = LSM6DS3_CTRL1_XL_ODR_104HZ | LSM6DS3_CTRL1_XL_FS_2G;
  HAL_I2C_Mem_Write(&hi2c1, lsm6ds3_address, LSM6DS3_REG_CTRL1_XL, I2C_MEMADD_SIZE_8BIT, &ctrl1_xl, 1, 1000);
  uint8_t ctrl2_g = LSM6DS3_CTRL2_G_ODR_104HZ | LSM6DS3_CTRL2_G_FS_2000DPS;
  HAL_I2C_Mem_Write(&hi2c1, lsm6ds3_address, LSM6DS3_REG_CTRL2_G, I2C_MEMADD_SIZE_8BIT, &ctrl2_g, 1, 1000);

  // Sensor initialization was successful
  return 0;
}



// Read accelerometer data from the LSM6DS3 sensor
void lsm6ds3_read_accelerometer(int16_t *x, int16_t *y, int16_t *z)
{
  // Read the accelerometer data registers
  uint8_t data[6];
  HAL_I2C_Mem_Read(&hi2c1, lsm6ds3_address, LSM6DS3_REG_OUTX_L_XL, I2C_MEMADD_SIZE_8BIT, data, 6, 1000);

  // Convert the data to signed 16-bit integers
  *x = (int16_t)(data[0] | (data[1] << 8));
  *y = (int16_t)(data[2] | (data[3] << 8));
  *z = (int16_t)(data[4] | (data[5] << 8));
}

// Read gyroscope data from the LSM6DS3 sensor
void lsm6ds3_read_gyroscope(int16_t *x, int16_t *y, int16_t *z)
{
  // Read the gyroscope data registers
  uint8_t data[6];
  HAL_I2C_Mem_Read(&hi2c1, lsm6ds3_address, LSM6DS3_REG_OUTX_L_G, I2C_MEMADD_SIZE_8BIT, data, 6, 1000);

  // Convert the data to signed 16-bit integers
  *x = (int16_t)(data[0] | (data[1] << 8));
  *y = (int16_t)(data[2] | (data[3] << 8));
  *z = (int16_t)(data[4] | (data[5] << 8));
}

