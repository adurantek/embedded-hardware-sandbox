#include <stdio.h>
#include "stm32c0xx.h"

void setup (void) {
	RCC -> CR &= ~(1 << 12); //CONFIGURED FREQUENCY TO 48MHZ

	RCC -> IOPENR |= (1 << 1);   // PORT B ENABLE
	RCC -> APBENR1 |= (1 << 21); //I2C1 PERHIPRAL ENABLE

	GPIOB -> MODER &= ~((1 << 16) | (1 << 18)); //PA8 AND PA9 AF ENABLE
	GPIOB -> OTYPER |= ((1 << 8) | (1 << 9));   //OPEN-DRAİN ENABLE
	GPIOB -> AFR[1] |= ((1 << 1) | (1 << 2) | (1 << 5) | (1 << 6)); //SCL AND SDA ENABLE

	//100Khz for 48Mhz Table 115.

	I2C1 -> TIMINGR |= ((0xB << 28)   //PRESC
					|  (0x13 << 0)    //SCLL
					|  (0xF << 8)     //SCLH
					|  (0x2 << 16)    //SDADEL
					|  (0x4 << 20));  //SCLDEL

	I2C1 -> CR1 |= (1 << 0);	 //PERHIPRAL ENABLE

}

void I2C_Write_Byte(uint8_t *data_array, uint8_t adres, uint8_t size) {
	I2C1 -> CR2	=     ((adres << 1) //SADD
				    |  (size << 16)    //NBYTE (1 byte)
					|  (1 << 13));  //START

	// NOTE: READ/WRİTE 0 DEFAULT

	for (uint8_t i=0; i < size; i++) {

	while((I2C1 -> ISR & (1 << 1)) == 0) /* TXIS FLAG CONTROL*/ { }

	I2C1 -> TXDR = data_array[i];

	}

	while((I2C1 -> ISR & (1 << 6)) == 0) /*COMPLETE FLAG CONTROL*/ { }

	I2C1 -> CR2 |= (1 << 14); //STOP
}

int main (void) {
	setup();

	//OLED OFF CODE 0XAE
	uint8_t test_verisi[2] = {0x00,0xAE};

	I2C_Write_Byte(test_verisi, 0x3C, 2);

	while (1) {}
}
