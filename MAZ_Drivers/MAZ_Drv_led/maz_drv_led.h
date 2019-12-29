/*
 * MAZ_Drv_led.h
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#ifndef MAZ_DRV_LED_H_
#define MAZ_DRV_LED_H_

#include <stm32f1xx_hal.h>
#include <maz_com_products.h>

#if defined(MAZ_PRODUCT_A1)
typedef enum _MAZDRV_LED_
{
    MAZDRV_LED0 = 0,
    MAZDRV_LED1,
    MAZDRV_LED_MAX,
} MAZDRV_LED;

#elif defined(MAZ_PRODUCT_A2)
typedef enum _MAZDRV_LED_
{
    MAZDRV_LED0 = 0,
    MAZDRV_LED_MAX,
} MAZDRV_LED;

#endif

typedef enum _MAZDRV_LED_GPIO_PORT_
{
    MAZDRV_LED_GPIO_PORTA = GPIOA_BASE,
    MAZDRV_LED_GPIO_PORTB = GPIOB_BASE,
    MAZDRV_LED_GPIO_PORTC = GPIOC_BASE,
    MAZDRV_LED_GPIO_PORTD = GPIOD_BASE,
    MAZDRV_LED_GPIO_PORTE = GPIOE_BASE,
    MAZDRV_LED_GPIO_PORTF = GPIOF_BASE,
    MAZDRV_LED_GPIO_PORTG = GPIOG_BASE,
} MAZDRV_LED_GPIO_PORT;

typedef enum _MAZDRV_LED_GPIO_PIN_
{
    MAZDRV_LED_GPIO_PIN0 = GPIO_PIN_0,
    MAZDRV_LED_GPIO_PIN1 = GPIO_PIN_1,
    MAZDRV_LED_GPIO_PIN2 = GPIO_PIN_2,
    MAZDRV_LED_GPIO_PIN3 = GPIO_PIN_3,
    MAZDRV_LED_GPIO_PIN4 = GPIO_PIN_4,
    MAZDRV_LED_GPIO_PIN5 = GPIO_PIN_5,
    MAZDRV_LED_GPIO_PIN6 = GPIO_PIN_6,
    MAZDRV_LED_GPIO_PIN7 = GPIO_PIN_7,
    MAZDRV_LED_GPIO_PIN8 = GPIO_PIN_8,
    MAZDRV_LED_GPIO_PIN9 = GPIO_PIN_9,
    MAZDRV_LED_GPIO_PIN10 = GPIO_PIN_10,
    MAZDRV_LED_GPIO_PIN11 = GPIO_PIN_11,
    MAZDRV_LED_GPIO_PIN12 = GPIO_PIN_12,
    MAZDRV_LED_GPIO_PIN13 = GPIO_PIN_13,
    MAZDRV_LED_GPIO_PIN14 = GPIO_PIN_14,
    MAZDRV_LED_GPIO_PIN15 = GPIO_PIN_15,
    MAZDRV_LED_GPIO_PIN_ALL = GPIO_PIN_All,
} MAZDRV_LED_GPIO_PIN;

typedef enum _MAZDRV_LED_GPIO_LEVEL_
{
    MAZDRV_LED_GPIO_LEVEL_HIGH = GPIO_PIN_SET,
    MAZDRV_LED_GPIO_LEVEL_LOW = GPIO_PIN_RESET,
} MAZDRV_LED_GPIO_LEVEL;

typedef enum _MAZDRV_LED_STATUS_
{
    MAZDRV_LED_STATUS_ON = 0,
    MAZDRV_LED_STATUS_OFF,
    MAZDRV_LED_STATUS_TOGGLE,
} MAZDRV_LED_STATUS;

typedef struct _MAZDRV_LED_CTRL_
{
    MAZDRV_LED_GPIO_PORT port;              // 连接LED的GPIO PORT
    MAZDRV_LED_GPIO_PIN pin;                // 连接LED的GPIO PIN
    MAZDRV_LED_GPIO_LEVEL light;            // 高电平还是低电平点亮
    MAZDRV_LED_STATUS status;               // 默认状态是点亮还是熄灭
} MAZDRV_LED_CTRL;

int MAZ_Drv_led_init(void);
int MAZ_Drv_led_set_status(MAZDRV_LED led, MAZDRV_LED_STATUS status);
int MAZ_Drv_led_gpio_prot_clk_enable(MAZDRV_LED led);

#endif /* MAZ_DRV_LED_H_ */