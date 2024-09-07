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
#ifndef __SYS_H_
#define __SYS_H_
#include <REGX52.H>
#include <intrins.h>

//声明标识符
#define	u8 unsigned char
#define	u16 unsigned int
#define	u32 unsigned long  




//函数声明
void delay_ms(int count); //延时时间（ms）
void delay_us(); //延时时间（us）




#endif 