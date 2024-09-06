#ifndef __LED_H__
#define __LED_H__		
#include "sys.h"


//֧�ֺ��������ٶ����л�
#define USE_HORIZONTAL  	0 //����Һ����˳ʱ����ת���� 	0-0����ת��1-90����ת��2-180����ת��3-270����ת


//����LCD�ĳߴ�
#define LCD_W 240
#define LCD_H 198
//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	
#define RED         	 0xF800	

//IO����
sbit LCD_RS = P1^2;  		 //����/�����л�
sbit LCD_SDI = P1^5;		  //SPIд
sbit LCD_CS = P1^3;		//Ƭѡ	
sbit LCD_CLK = P1^7;   //SPIʱ��
sbit LCD_RESET = P3^5;	      //��λ 
sbit LCD_BL=P3^4;		//������ƣ�STC89C52RC��Ƭ����3.3V



void LCD_Init(void); 
void LCD_Clear(u16 Color);
void spi_write_byte(u8 d); //ͨ��SPIд��һ���ֽ�����
void LCD_WR_DATA(u8 Data); 
void LCD_WR_REG(u8 Reg);
void LCD_SetCursor(u16 Xpos, u16 Ypos);//���ù��λ��
void LCD_SetWindows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);//������ʾ����
void LCD_DrawPoint(u16 x,u16 y,u16 color);//����
void LCD_WriteRAM_Prepare(void);
void LCD_direction(u8 direction );
void LCD_WR_DATA_16Bit(u16 Data);

/*****************************************         TFT��Ļ��ʾ����        **********************************************************/
void LCD_ShowChar(u8 x,u8 y,u8 num,u8 mode);//��ʾһ���ַ�
void LCD_ShowString(u8 x,u8 y,u16 width,u16 height,u8 *p);//��ʾ�ַ���
void LCD_Fill(u8 xState,u8 yState,u8 xEnd,u8 yEnd,u16 color);//��䵥ɫ
void Draw_Circle(u8 x0,u8 y0,u8 r,u16 color);//��Բ
void LCD_DrawLine(u8 x1, u8 y1, u8 x2, u8 y2,u16 color);//��ֱ��
void LCD_ShowNum(u8 x,u8 y,u16 num,u8 len);//��ʾ����
void LCD_ShowFontHZ(u8 x, u8 y, u8 *cn);//��ʾ����
#endif  