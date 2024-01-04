#include "aos/init.h"
#include "board.h"
#include <aos/errno.h>
#include <aos/kernel.h>
#include <k_api.h>
#include <stdio.h>
#include <stdlib.h>
//引入gpio以及引脚相关头文件
#include <aos/hal/gpio.h>           //gpio相关的头文件
#include <hal_iomux_haas1000.h>     //引脚所在的头文件3

    gpio_dev_t blueLed;
    gpio_dev_t redLed;
    gpio_dev_t greenLed;

/**Led灯初始化
 * @param output int  LED灯初始状态
 * @return void
*/
void led_init(int output){
    //为结构体变量进行赋初值
    blueLed.port = HAL_GPIO_PIN_P4_2;
    redLed.port = HAL_GPIO_PIN_P4_4;
    greenLed.port = HAL_GPIO_PIN_P4_3;
    
    //配置信息：推挽输出
    blueLed.config = OUTPUT_PUSH_PULL;
    redLed.config = OUTPUT_PUSH_PULL;
    greenLed.config = OUTPUT_PUSH_PULL;

    //无私有数据
    blueLed.priv = NULL;
    greenLed.priv = NULL;
    redLed.priv = NULL;

    //保存gpio的初始化
    hal_gpio_init(&blueLed);
    hal_gpio_init(&greenLed);
    hal_gpio_init(&redLed);
    if(output){
        hal_gpio_output_high(&blueLed);
        hal_gpio_output_high(&redLed);
        hal_gpio_output_high(&greenLed);
    }else{
        //蓝灯的初始化的状态:熄灭状态
        hal_gpio_output_low(&blueLed);
        hal_gpio_output_low(&greenLed);
        hal_gpio_output_low(&redLed);
    }
    
}

/**延时方法
 * @param time int 延时时间,单位:毫秒
 * @return void
*/
void delay(int time){
    aos_msleep(time);
}
