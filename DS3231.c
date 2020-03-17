#include "gpio.h"
#include "DS3231.h"
#include "stm32f0xx_hal.h"
#include"stdio.h"
#include "i2c.h"
//#include "usart.h"

//#define 0x68 0x68

uint8_t bcdToDec(uint8_t bcd) {
	return (bcd & 0x0F) + ((bcd >> 4) * 10);
}

uint8_t decToBCD(uint8_t dec) {
	return ((dec / 10) << 4) + (dec % 10);
}

uint8_t read_register(uint8_t addr) {
	uint8_t data[8];
	HAL_I2C_Mem_Read(&hi2c1, 0xD1, addr, 1, data, 1, 100);
//	HAL_UART_Transmit(&huart5, (uint8_t*) "data:", 5, 100);
//	HAL_UART_Transmit(&huart5, data, 1, 100);
//	HAL_UART_Transmit(&huart5, (uint8_t*) "\r\n", 2, 10);
	return data[0];
}
void RTC_init() {
	uint8_t value[8];
	sprintf((char*) value, "%c", 0xD8); //80
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x0E, 1, value, 1, 100);
	for (int i = 0; i < 8; i++)
		value[i] = 0;
	sprintf((char*) value, "%c", 0x08);
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x0E, 1, value, 1, 100);
//	read_register(0x0E);
}
uint8_t get_seconds() {
	uint8_t sec = read_register(0x00);
	return bcdToDec(sec & 0x7F);
}
uint8_t get_minits() {
	uint8_t min = read_register(0x01);
	return bcdToDec(min & 0x7F);
}
uint8_t get_hours() {
	uint8_t hour = read_register(0x02);
	return bcdToDec(hour & 0x3F);
}
uint8_t get_Date() {
	uint8_t date = read_register(0x04);
	return bcdToDec(date & 0x3F);
}
uint8_t get_Month() {
	uint8_t month = read_register(0x05);
	return bcdToDec(month & 0x1F);
}
uint8_t get_Year() {
	uint8_t year = read_register(0x06);
	return bcdToDec(year);
}
void set_seconds(unsigned short int sec) {
	uint8_t value[8];
	uint8_t yert = decToBCD(sec & 0x7F);
	sprintf((char*) value, "%c", yert);
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x00, 1, value, 1, 100);
//	read_register(0x00);
}
void set_minits(unsigned short int min) {
	uint8_t value[8];
	uint8_t yert = decToBCD(min & 0x7F);
	sprintf((char*) value, "%c", yert);
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x01, 1, value, 1, 100);
//	read_register(0x01);
}
void set_hours(unsigned short int hour) {
	uint8_t value[8];
	uint8_t yert = decToBCD(hour);
	sprintf((char*) value, "%c", yert);
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x02, 1, value, 1, 100);
//	read_register(0x02);
}
void set_Date(unsigned short int date) {
	uint8_t value[8];
	uint8_t yert = decToBCD(date & 0x3F);
	sprintf((char*) value, "%c", yert);
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x04, 1, value, 1, 100);
//	read_register(0x04);

}
void set_Month(unsigned short int month) {
	uint8_t value[8];
	uint8_t yert = decToBCD(month & 0x1F);
	sprintf((char*) value, "%c", yert);
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x05, 1, value, 1, 100);
//	read_register(0x05);
}
void set_year(unsigned short int year) {
	uint8_t value[8];
//	year = year - 2000;
	uint8_t yert = decToBCD(year);
	sprintf((char*) value, "%c", yert);
	HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x06, 1, value, 1, 100);
//	read_register(0x06);
}

