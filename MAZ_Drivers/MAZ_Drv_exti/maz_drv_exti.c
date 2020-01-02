/*
 * MAZ_Drv_exti.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Paul@maziot.com
 */

#include <maz_drv_gpio.h>
#include <maz_com_errors.h>

int MAZ_Drv_exti_irq_enable(MAZDRV_GPIO_PIN pin)
{
    if (pin < MAZDRV_GPIO_PIN0 || pin > MAZDRV_GPIO_PIN15)
    {
        return MAZRET_EINVAL;
    }

    /* GPIO Ports Clock Enable */
    switch (pin)
    {
        case MAZDRV_GPIO_PIN0:
            HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 2);
            HAL_NVIC_EnableIRQ(EXTI0_IRQn);
            break;
        case MAZDRV_GPIO_PIN1:
            HAL_NVIC_SetPriority(EXTI1_IRQn, 2, 2);
            HAL_NVIC_EnableIRQ(EXTI1_IRQn);
            break;
        case MAZDRV_GPIO_PIN2:
            HAL_NVIC_SetPriority(EXTI2_IRQn, 2, 2);
            HAL_NVIC_EnableIRQ(EXTI2_IRQn);
            break;
        case MAZDRV_GPIO_PIN3:
            HAL_NVIC_SetPriority(EXTI3_IRQn, 2, 2);
            HAL_NVIC_EnableIRQ(EXTI3_IRQn);
            break;
        case MAZDRV_GPIO_PIN4:
            HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 2);
            HAL_NVIC_EnableIRQ(EXTI4_IRQn);
            break;
        case MAZDRV_GPIO_PIN5:
        case MAZDRV_GPIO_PIN6:
        case MAZDRV_GPIO_PIN7:
        case MAZDRV_GPIO_PIN8:
        case MAZDRV_GPIO_PIN9:
            HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 2);
            HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
            break;
        case MAZDRV_GPIO_PIN10:
        case MAZDRV_GPIO_PIN11:
        case MAZDRV_GPIO_PIN12:
        case MAZDRV_GPIO_PIN13:
        case MAZDRV_GPIO_PIN14:
        case MAZDRV_GPIO_PIN15:
            HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 2);
            HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
            break;
    }

    return MAZRET_NOERR;
}

