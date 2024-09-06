#include "sys.h"
#include "iic.h"

/**************************************
起始信号
**************************************/
void QMC5883_Start()
{
    SDA = 1;                    //拉高数据线
    SCL = 1;                    //拉高时钟线
    delay_us();                 //延时
    SDA = 0;                    //产生下降沿
    delay_us();                 //延时
    SCL = 0;                    //拉低时钟线
}

/**************************************
停止信号
**************************************/
void QMC5883_Stop()
{
    SDA = 0;                    //拉低数据线
    SCL = 1;                    //拉高时钟线
    delay_us();                 //延时
    SDA = 1;                    //产生上升沿
    delay_us();                 //延时
}

/**************************************
发送应答信号
入口参数:ack (0:ACK 1:NAK)
**************************************/
void QMC5883_SendACK(bit ack)
{
    SDA = ack;                  //写应答信号
    SCL = 1;                    //拉高时钟线
    delay_us();                 //延时
    SCL = 0;                    //拉低时钟线
    delay_us();                 //延时
}

/**************************************
接收应答信号
**************************************/
bit QMC5883_RecvACK()
{
    SCL = 1;                    //拉高时钟线
    delay_us();                //延时
    CY = SDA;                   //进位标志 读应答信号
    SCL = 0;                    //拉低时钟线
    delay_us();                //延时
    return CY;
}

/**************************************
向IIC总线发送一个字节数据
**************************************/
void QMC5883_SendByte(u8 dat)
{
    u8 i;

    for (i=0; i<8; i++)         //8位计数器
    {
        dat <<= 1;              //移出数据的最高位
        SDA = CY;               //送数据口
        SCL = 1;                //拉高时钟线
        delay_us();             //延时
        SCL = 0;                //拉低时钟线
        delay_us();             //延时
    }
    QMC5883_RecvACK();
}

/**************************************
从IIC总线接收一个字节数据
**************************************/
u8 QMC5883_RecvByte()
{
    u8 i;
    u8 dat = 0;

    SDA = 1;                    //使能内部上拉,准备读取数据,
    for (i=0; i<8; i++)         //8位计数器
    {
        dat <<= 1;
        SCL = 1;                //拉高时钟线
        delay_us();             //延时
        dat |= SDA;             //读数据               
        SCL = 0;                //拉低时钟线
        delay_us();             //延时
    }
    return dat;
}

//************************写入单字节数据***************************

void Single_Write_QMC5883(u8 REG_Address,u8 REG_data)
{
    QMC5883_Start();                  //起始信号
    QMC5883_SendByte(Slave_Address);   //发送设备地址+写信号
    QMC5883_SendByte(REG_Address);    //内部寄存器地址，请参考中文pdf 
    QMC5883_SendByte(REG_data);       //内部寄存器数据，请参考中文pdf
    QMC5883_Stop();                   //发送停止信号
}


//******************************************************
//连续读出QMC5883内部角度数据，地址范围0x00~0x05
//******************************************************
void Multiple_Read_QMC5883(void)
{   
    u8 i;
    QMC5883_Start();                          //起始信号
    QMC5883_SendByte(Slave_Address);          //发送设备地址+写信号
    QMC5883_SendByte(0x00);                   //发送存储单元地址，从0x00开始	
    QMC5883_Start();                          //起始信号
    QMC5883_SendByte(Slave_Address+1);        //发送设备地址+读信号
	 for (i=0; i<6; i++)                      //连续读取6个地址数据，存储中BUF
    {
        BUF[i] = QMC5883_RecvByte();          //BUF[0]存储数据
        if (i == 5)
        {
           QMC5883_SendACK(1);                //最后一个数据需要回非应答NOACK
        }
        else
        {
          QMC5883_SendACK(0);                 //应答ACK
       }
   }
    QMC5883_Stop();                           //停止信号
    delay_ms(5);
}

//初始化QMC5883，根据需要请参考pdf进行修改****
void Init_QMC5883()
{

	Single_Write_QMC5883(0x09,0x0d);  //控制寄存器配置
	Single_Write_QMC5883(0x0b,0x01);  //设置清除时间寄存器
	Single_Write_QMC5883(0x20,0x40);  //
	Single_Write_QMC5883(0x21,0x01);  //	
}