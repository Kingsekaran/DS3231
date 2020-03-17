#ifndef  DS32311_RTC_
#define DS3231_RTC_

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

uint8_t bcdToDec(uint8_t bcd);
uint8_t decToBCD(uint8_t dec);
uint8_t read_register(uint8_t addr);
void RTC_init();
uint8_t get_seconds();
uint8_t get_minits();
uint8_t get_hours();
uint8_t get_Date();
uint8_t get_Month();
uint8_t get_Year();

void set_seconds(unsigned short int sec);
void set_minits(unsigned short int min);
void set_hours(unsigned short int hour);
void set_Date(unsigned short int date);
void set_Month(unsigned short int month);
void set_year(unsigned short int year);
#endif
