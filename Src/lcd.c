/*
 * Lcd.c
 *
 *  Created on: 29 paü 2017
 *      Author: speedfight
 */


#include <lcd.h>

#define	CE_SET	HAL_GPIO_WritePin(PORT_LCD_CE,PIN_LCD_CE,GPIO_PIN_SET);
#define	DC_SET	HAL_GPIO_WritePin(PORT_LCD_DC,PIN_LCD_DC,GPIO_PIN_SET);
#define	RST_SET	HAL_GPIO_WritePin(PORT_LCD_RST,PIN_LCD_RST,GPIO_PIN_SET);

#define	CE_RESET	HAL_GPIO_WritePin(PORT_LCD_CE,PIN_LCD_CE,GPIO_PIN_RESET);
#define	DC_RESET	HAL_GPIO_WritePin(PORT_LCD_DC,PIN_LCD_DC,GPIO_PIN_RESET);
#define	RST_RESET	HAL_GPIO_WritePin(PORT_LCD_RST,PIN_LCD_RST,GPIO_PIN_RESET);

extern SPI_HandleTypeDef hspi1;

#define PCD8544_FUNCTION_SET		0x20
#define PCD8544_DISP_CONTROL		0x08
#define PCD8544_DISP_NORMAL			0x0c
#define PCD8544_SET_Y				0x40
#define PCD8544_SET_X				0x80
#define PCD8544_H_TC				0x04
#define PCD8544_H_BIAS				0x10
#define PCD8544_H_VOP				0x80

#define LCD_BUFFER_SIZE			(84 * 48 / 8)

uint8_t lcd_buffer[LCD_BUFFER_SIZE];

void lcd_send_command(uint8_t cmd)
{
	CE_RESET;
	DC_RESET;
	HAL_SPI_Transmit(&hspi1, &cmd, 1, 0xFFFu);
	HAL_GPIO_WritePin(PORT_LCD_DC,PIN_LCD_DC,GPIO_PIN_RESET);
	CE_RESET;
}
void lcd_send_data(const uint8_t* data, int size)
{
	 uint32_t i;
	 DC_SET;
	 CE_RESET;
	 for (i = 0; i < size; i++)
	 {
		 HAL_SPI_Transmit(&hspi1, &data[i], 1, 0xFFFu);
	 }
	 CE_SET;
}

void lcd_reset()
{
	RST_RESET;
	RST_SET;

}

void lcd_init()
{
	CE_SET;
	DC_RESET;
	RST_SET;

	HAL_Delay(200);
	lcd_reset();

	lcd_send_command(0x21);
	lcd_send_command(0x14);
	lcd_send_command(0x80 | 0x27); //Ustawienie kontrastu
	lcd_send_command(0x20);
	lcd_send_command(0x0c);
}

void lcd_clear(void)
{
	memset(lcd_buffer, 0, LCD_BUFFER_SIZE);
}

void lcd_draw_bitmap(const uint8_t* data)
{
	memcpy(lcd_buffer, data, LCD_BUFFER_SIZE);
}

void lcd_draw_text(int row, int col, const char* text)
{
	 int i;
	 uint8_t* pbuf = &lcd_buffer[row * 84 + col];

	 while ((*text) && (pbuf < &lcd_buffer[LCD_BUFFER_SIZE - 6]))
	 {
		 int ch = *text++;
		 const uint8_t* font = &font_ASCII[ch - ' '][0];
		 for (i = 0; i < 5; i++)
		 {
			 *pbuf++ = *font++;
		 }
		 *pbuf++ = 0;
	 }
}

void lcd_copy(void)
{
	lcd_send_data(lcd_buffer, sizeof(lcd_buffer));
}
