/*
 * LOW_POWER_PMOS.h
 *
 *  Created on: May 9, 2025
 */

#ifndef SRC_DRIVER_PMOS_H_
#define SRC_DRIVER_PMOS_H_

// Macros d'alimentation (logique inverse : 0 = alimenté)
#define SENSOR_ON()  (HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET)) // PA2 à 0
#define SENSOR_OFF() (HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET)) // PA2 à 1

#define LED_ON()     (HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET))
#define LED_OFF()    (HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET))

#define XBEE_ON()    (HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET)) // A2 à 0
#define XBEE_OFF()   (HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET))   // A2 à 1

#endif /* SRC_DRIVER_PMOS_H_ */
