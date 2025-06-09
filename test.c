#include "stm32f4xx.h"
#include "sys.h" 
#include "usart.h"
#include "delay.h" 

//ALIENTEK 阿波罗STM32F429开发板 实验0
//新建工程实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

int main(void)
{ 
    u8 t=0; // 定义一个8位无符号变量t，用于计数
    
    // 初始化系统时钟
    // 参数1：PLL倍频系数360(实际倍频360/2=180)
    // 参数2：PLLM分频系数25
    // 参数3：PLLP分频系数2
    // 参数4：PLLQ分频系数8
    // 最终系统时钟频率为180MHz
    Stm32_Clock_Init(360,25,2,8);
    
    // 初始化延时函数
    // 参数：系统时钟频率(单位MHz)
    delay_init(180);
    
    // 初始化串口1
    // 参数1：波特率分频系数
    // 参数2：波特率115200bps
    uart_init(90,115200);
    
    // 主循环
    while(1)
    {
        // 通过串口发送当前计数值
        printf("t:%d\r\n",t);
        
        // 延时500毫秒
        delay_ms(500);
        
        // 计数器递增
        t++;
    }
}