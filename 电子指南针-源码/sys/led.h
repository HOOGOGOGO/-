#ifndef __LED_H__
#define __LED_H__		
#include "sys.h"


//支持横竖屏快速定义切换
#define USE_HORIZONTAL  	0 //定义液晶屏顺时针旋转方向 	0-0度旋转，1-90度旋转，2-180度旋转，3-270度旋转


//定义LCD的尺寸
#define LCD_W 240
#define LCD_H 198
//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	
#define RED         	 0xF800	

//IO连接
sbit LCD_RS = P1^2;  		 //数据/命令切换
sbit LCD_SDI = P1^5;		  //SPI写
sbit LCD_CS = P1^3;		//片选	
sbit LCD_CLK = P1^7;   //SPI时钟
sbit LCD_RESET = P3^5;	      //复位 
sbit LCD_BL=P3^4;		//背光控制，STC89C52RC单片滑接3.3V



void LCD_Init(void); 
void LCD_Clear(u16 Color);
void spi_write_byte(u8 d); //通过SPI写入一个字节数据
void LCD_WR_DATA(u8 Data); 
void LCD_WR_REG(u8 Reg);
void LCD_SetCursor(u16 Xpos, u16 Ypos);//设置光标位置
void LCD_SetWindows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);//设置显示窗口
void LCD_DrawPoint(u16 x,u16 y,u16 color);//画点
void LCD_WriteRAM_Prepare(void);
void LCD_direction(u8 direction );
void LCD_WR_DATA_16Bit(u16 Data);

/*****************************************         TFT屏幕显示函数        **********************************************************/
void LCD_ShowChar(u8 x,u8 y,u8 num,u8 mode);//显示一个字符
void LCD_ShowString(u8 x,u8 y,u16 width,u16 height,u8 *p);//显示字符串
void LCD_Fill(u8 xState,u8 yState,u8 xEnd,u8 yEnd,u16 color);//填充单色
void Draw_Circle(u8 x0,u8 y0,u8 r,u16 color);//画圆
void LCD_DrawLine(u8 x1, u8 y1, u8 x2, u8 y2,u16 color);//画直线
void LCD_ShowNum(u8 x,u8 y,u16 num,u8 len);//显示数字
void LCD_ShowFontHZ(u8 x, u8 y, u8 *cn);//显示汉字
#endif  