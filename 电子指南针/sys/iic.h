//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STC89C52,晶振11.0592M  单片机工作电压3.8V
//QDtech-TFT液晶驱动 for C51
//协会网站:https://hoogogogo.github.io/YanZhiBo/
//协会提供技术支持，任何技术问题欢迎随时交流学习
//邮箱:1711446177@qq.com
//技术交流QQ群:111446177
//创建日期:2024/9/7
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 燕之波协会 2024-2034
#ifndef __IIC_H_
#define __IIC_H_
 
extern unsigned char BUF[8]; 	//数据缓存
#define	Slave_Address   0x1a	 //定义器件在IIC总线中的从地址  read            	
sbit	SCL=P1^0;      //IIC时钟线
sbit	SDA=P1^1;      //IIC数据线


void QMC5883_Start();
void QMC5883_Stop();
void QMC5883_SendACK(bit ack);
bit QMC5883_RecvACK();
void QMC5883_SendByte(unsigned char dat);
unsigned char QMC5883_RecvByte();
void Single_Write_QMC5883(unsigned char REG_Address,unsigned char REG_data);
void Multiple_Read_QMC5883(void);
void Init_QMC5883();

#endif

















