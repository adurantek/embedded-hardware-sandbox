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

void clear_pixels() {
	uint8_t clear_list[129];
	clear_list[0] = 0x40;

	for (uint8_t i=1;i<129;i++) {
		clear_list[i] = 0x00;
	}

	for (uint8_t j=0;j<8;j++) {
		I2C_Write_Byte(clear_list,0x3C,129);
	}
}

int main (void) {
	setup();

	//OLED SCREEN ADRESSES

	uint8_t oled_init_cmd[27] = {
		0x00,       // KONTROL BAYTI
	    0xAE,       // (Display OFF)
	    0xD5, 0x80, // CLOCK FREQUENCY CONFIG
	    0xA8, 0x3F, // MULTIPLEX CONFIG (64 SATIR ICIN)
	    0xD3, 0x00, // SCREEN MOVEMENT RESET
	    0x40,       // BASLANGIC SATIRINI 0 YAP
	    0x8D, 0x14, // ŞARJ POMPASINI AC
	    0x20, 0x00, // HAFIZA ADRESLEME MODUNU 'YATAY' (Horizontal) YAP
	    0xA1,       // SUTUN ADRSLERINI TERS CEVIR (EKRAN TERS DURMASIN DIYE)
	    0xC8,       // SATIR TARAMA YONUNU TER CEVIR
	    0xDA, 0x12, // HARDWARE PIN CONFIGURATION
	    0x81, 0xCF, // KONTRAST CONGIG
	    0xD9, 0xF1, // PRE-CHARGE PERIOD
	    0xDB, 0x40, // VCOMH VOLTAGE LEVEL
	    0xA4,       // ALL PIXELS CONNECT TO RAM
	    0xA6,       // NORMAL GORUNUM (SIYAH ARKA PLAN, BYAZ YAZI)
	    0xAF        // EKRANI AÇ (Display ON)
	};

	I2C_Write_Byte(oled_init_cmd, 0x3C, 27);

	//OLED OFF CODE 0XAE

	clear_pixels();

	uint8_t pixel_verisi[129];
	pixel_verisi[0] = 0x40; //CONTROL BYTE

	for (uint8_t i=1;i<129;i++) {
		pixel_verisi[i] = 0xFF; //0xFF PIXELS WHITE
	}

	for(uint8_t j=0;j<8;j++) {
		I2C_Write_Byte(pixel_verisi, 0x3C, 129);
	}


	while (1) {}
}
