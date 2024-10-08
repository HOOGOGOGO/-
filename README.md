**使用芯片及模块：**

51单片机-STC89C52

GY-271 磁力模块 

LCD 显示屏模块 

3.7V 700 毫安可充电锂电池


## 开发需要的软件

编译环境：Keil5 C51架构 

烧录程序：STC-ISP

> 把指南针插到电脑上，烧录程序上串口号部分会自动识别，如果没有变化则没有识别成功，可能是电路虚焊问题或者电脑上没有安装CH340驱动。点击打开程序文件，选择hex结尾文件，点击“下载/编程”按钮，交互框中会显示“正在检测目标单片机 ...”，此时给板子断电后再通电，就可以进行烧录。

## 指南针源码说明
详细注释请看源码。
Target 1
- sys
  - sys.c 延时函数所在文件
  - sys.h 同名.c文件中有关函数和变量的声明
- TFT
  - led.c LCD电子屏幕的主要功能函数，包括屏幕初始化，画图，写数据等函数
  - led.h 同名.c文件中有关函数和变量的声明
- QMC
  - iic.c 磁传感器模块的主要函数，包含磁传感器模块与单片机在IIC(I2C)总线上的读写功能
  - iic.h 同名.c文件中有关函数和变量的声明
- main.c 包括获得磁传感器数据并计算相对于地理北极的角度；显示动态指针；画表盘。


## 指南针电路板说明
以下版本，在打板过后，除了板子上标注的元器件之外，需要再购买屏幕模块和磁传感器模块，以及电池。

屏幕模块：8Pin插槽

磁传感器模块：QMC5883L电子罗盘模块（5Pin）

电池：3.7V或3.8V锂电池，1.25红黑插头

 ### 简化屏幕模块 1.0
 无法持续为时钟模块供电，开关断电后时钟模块停止工作。因此，时钟模块名存实亡，时钟模块整体可以去除，不影响其他模块工作。
 
 ### 简化屏幕模块 1.5
 可以持续为时钟模块供电，开关断电后时钟模块依旧可以工作。
 
 新增4个按钮，用来调整时间：
 
 - CHANGE按钮用来进入时间编辑模式。
 - SWITCH按钮用来切换编辑位置（小时：分钟：秒）
 - HIGH和LOW分别是增加和减少数字。
 
 ### 简化屏幕模块 2.0
 仅去除冗余的稳压模块

**注意：**
- 指南针烧录时需要STC-ISP软件进行烧录，并且**需要冷启动才能烧录，即按下开关断电再开机**。
- 磁传感器模块下方尽量不要铺铜，防止干扰。电池不要和磁传感器放置在板子同一侧，也会干扰。晶振要尽最大可能离单片机近，且附近不要铺铜。

**可能存在的问题（电路板部分）：**
- 不识别串口号：表现为STC-ISP烧录软件中的“串口号”后面没有“USB-SERIAL CH340(COMx)”标识的选项。
    - 检查数据线是否可以传输数据，有一些线只能用于充电，不能传输数据。
    - 检查电脑是否安装CH340驱动，打开设备管理器，如果有端口(COM和LPT)并且其下有带感叹号的usb图标，则为没有安装驱动，安装驱动即可。如果没有端口(COM和LPT)，则检查其他原因。
    - 检查USB母座与板子之间的引脚焊接是否虚焊或者连焊。
    - 检查CH340芯片供电引脚是否有电压，数据引脚是否虚焊或者连焊。
    - 检查CH340引脚中V3连接的电容是否虚焊连焊或者电容值不对。
- 不识别单片机：表现为STC-ISP烧录软件点击“下载/编程”按钮，并进行冷启动之后，窗口中仅显示“正在检测目标单片机 ...”，并没有烧录过程。
    - 检查单片机的引脚，尤其是TXD、RXD、ACC、GND引脚是否虚焊或者连焊。
    - 检查CH340芯片到单片机路径中的元器件是否虚焊或者连焊。
- 屏幕不显示：表现为屏幕根本不亮、灯亮了但是不刷新（一直是黑色的）等。
    - 检查单片机上对应引脚是否虚焊或连焊。
    - 检查屏幕连接器母座与电路板的焊盘是否虚焊。

 > 后续我们计划使用arm架构的芯片优化指南针。因此如果使用其他芯片想要优化现有程序，需要更换电路图。
