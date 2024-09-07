//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STC89C52,����11.0592M  ��Ƭ��������ѹ3.8V
//QDtech-TFTҺ������ for C51
//Э����վ:https://hoogogogo.github.io/YanZhiBo/
//Э���ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//����:1711446177@qq.com
//��������QQȺ:111446177
//��������:2024/9/7
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ��֮��Э�� 2024-2034
#ifndef __IIC_H_
#define __IIC_H_
 
extern unsigned char BUF[8]; 	//���ݻ���
#define	Slave_Address   0x1a	 //����������IIC�����еĴӵ�ַ  read            	
sbit	SCL=P1^0;      //IICʱ����
sbit	SDA=P1^1;      //IIC������


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

















