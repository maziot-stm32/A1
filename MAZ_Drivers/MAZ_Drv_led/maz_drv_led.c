/*
 * MAZ_Drv_led.c
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#include <stm32f1xx_hal.h>
#include <maz_drv_led.h>
#include <maz_com_errors.h>

#if defined(MAZ_PRODUCT_A1)
static MAZDRV_LED_CTRL g_mazdrv_led_ctrl[MAZDRV_LED_MAX] =
{
    [MAZDRV_LED0] =
    {
        .port   = MAZDRV_LED_GPIO_PORTA,
        .pin    = MAZDRV_LED_GPIO_PIN8,
        .light  = MAZDRV_LED_GPIO_LEVEL_LOW,
        .status = MAZDRV_LED_STATUS_OFF,
    },
    [MAZDRV_LED1] =
    {
        .port   = MAZDRV_LED_GPIO_PORTD,
        .pin    = MAZDRV_LED_GPIO_PIN2,
        .light  = MAZDRV_LED_GPIO_LEVEL_LOW,
        .status = MAZDRV_LED_STATUS_OFF,
    },
};
#elif defined(MAZ_PRODUCT_A2)
static MAZDRV_LED_CTRL g_mazdrv_led_ctrl[MAZDRV_LED_MAX] =
{
    [MAZDRV_LED0] =
    {
         MAZDRV_LED_GPIO_PORTC,
         MAZDRV_LED_GPIO_PIN13,
         MAZDRV_LED_GPIO_LEVEL_HIGH,
         MAZDRV_LED_STATUS_OFF,
    },
};
#endif

/**
 * @brief  MAZ_Drv_led_init
 * @retval Error code
 */
int MAZ_Drv_led_init(void)
{
    MAZDRV_LED led;
    MAZDRV_LED_CTRL *ctrl = NULL;
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    ctrl = g_mazdrv_led_ctrl;

    for (led = MAZDRV_LED0; led < MAZDRV_LED_MAX; led++)
    {
        /* GPIO Ports Clock Enable */
        MAZ_Drv_led_gpio_prot_clk_enable(ctrl[led].port);

        /* Configure GPIO pin */
        GPIO_InitStruct.Pin = ctrl[led].pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Pull = (ctrl[led].light == MAZDRV_LED_GPIO_LEVEL_HIGH) ? GPIO_PULLDOWN : GPIO_PULLUP;
        HAL_GPIO_Init((GPIO_TypeDef*) ctrl[led].port, &GPIO_InitStruct);

        /* Set default status */
        MAZ_Drv_led_set_status(led, ctrl[led].status);
    }

    return MAZRET_NOERR;
}

/**
 * @brief  MAZ_Drv_led_set_status
 * @retval Error code
 */
int MAZ_Drv_led_set_status(MAZDRV_LED led, MAZDRV_LED_STATUS status)
{
    MAZDRV_LED_GPIO_LEVEL level;
    MAZDRV_LED_CTRL *ctrl = NULL;

    if (status < MAZDRV_LED_STATUS_ON || status > MAZDRV_LED_STATUS_TOGGLE)
    {
        return MAZRET_EINVAL;
    }

    ctrl = g_mazdrv_led_ctrl;

    switch (status)
    {
        case MAZDRV_LED_STATUS_ON:
            level = ctrl[led].light;
            HAL_GPIO_WritePin((GPIO_TypeDef*) ctrl[led].port, ctrl[led].pin, level);
            break;
        case MAZDRV_LED_STATUS_OFF:
            if (MAZDRV_LED_GPIO_LEVEL_HIGH == ctrl[led].light)
                level = MAZDRV_LED_GPIO_LEVEL_LOW;
            else if (MAZDRV_LED_GPIO_LEVEL_LOW == ctrl[led].light)
                level = MAZDRV_LED_GPIO_LEVEL_HIGH;
            HAL_GPIO_WritePin((GPIO_TypeDef*) ctrl[led].port, ctrl[led].pin, level);
            break;
        case MAZDRV_LED_STATUS_TOGGLE:
            HAL_GPIO_TogglePin((GPIO_TypeDef*) ctrl[led].port, ctrl[led].pin);
            break;
    }

    return MAZRET_NOERR;
}

/**
 * @brief  MAZ_Drv_led_gpio_prot_clk_enable
 * @retval Error code
 */
int MAZ_Drv_led_gpio_prot_clk_enable(MAZDRV_LED_GPIO_PORT port)
{
    if (port < MAZDRV_LED_GPIO_PORTA || port > MAZDRV_LED_GPIO_PORTG)
    {
        return MAZRET_EINVAL;
    }

    /* GPIO Ports Clock Enable */
    switch (port)
    {
        case MAZDRV_LED_GPIO_PORTA:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;
        case MAZDRV_LED_GPIO_PORTB:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;
        case MAZDRV_LED_GPIO_PORTC:
            __HAL_RCC_GPIOC_CLK_ENABLE();
            break;
        case MAZDRV_LED_GPIO_PORTD:
            __HAL_RCC_GPIOD_CLK_ENABLE();
            break;
        case MAZDRV_LED_GPIO_PORTE:
            __HAL_RCC_GPIOE_CLK_ENABLE();
            break;
        case MAZDRV_LED_GPIO_PORTF:
            __HAL_RCC_GPIOF_CLK_ENABLE();
            break;
        case MAZDRV_LED_GPIO_PORTG:
            __HAL_RCC_GPIOG_CLK_ENABLE();
            break;
    }

    return MAZRET_NOERR;
}

