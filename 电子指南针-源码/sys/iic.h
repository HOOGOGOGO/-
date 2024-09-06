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

















