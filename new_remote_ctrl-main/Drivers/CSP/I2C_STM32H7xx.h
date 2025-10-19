/**
 * @file    I2C_STM32H7xx.h
 * @author  Deadline039
 * @brief   Chip Support Package of I2C on STM32H7xx
 * @version 3.3.0
 * @date    2025-04-22
 * @note    Generate Automatically.
 */

#ifndef __I2C_STM32H7xx_H
#define __I2C_STM32H7xx_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*****************************************************************************
 * @defgroup I2C Public Marco. 
 * @{
 */

#define I2C_INIT_OK         0
#define I2C_INIT_FAIL       1
#define I2C_INIT_DMA_FAIL   2
#define I2C_INITED          3

#define I2C_DEINIT_OK       0
#define I2C_DEINIT_FAIL     1
#define I2C_DEINIT_DMA_FAIL 2
#define I2C_NO_INIT         3

/**
 * @}
 */
 
/* clang-format off */


/*****************************************************************************
 * @defgroup I2C1 Functions
 * @{
 */

#if I2C1_ENABLE

#if (I2C1_SCL_ID == 0)
#  define I2C1_SCL_GPIO_AF GPIO_AF4_I2C1
#elif (I2C1_SCL_ID == 1)
#  define I2C1_SCL_GPIO_AF GPIO_AF4_I2C1
#endif  /* I2C1_SCL_ID */

#if (I2C1_SDA_ID == 0)
#  define I2C1_SDA_GPIO_AF GPIO_AF4_I2C1
#elif (I2C1_SDA_ID == 1)
#  define I2C1_SDA_GPIO_AF GPIO_AF4_I2C1
#endif  /* I2C1_SDA_ID */

extern I2C_HandleTypeDef i2c1_handle;

uint8_t i2c1_init(uint32_t clock_speed, uint32_t address,
                  uint32_t address_mode);
uint8_t i2c1_deinit(void); 

#  if I2C1_RX_DMA
#    define I2C1_RX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C1_RX_DMA_NUMBER, I2C1_RX_DMA_STREAM)
#    define I2C1_RX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C1_RX_DMA_NUMBER, I2C1_RX_DMA_STREAM)
#  endif /* I2C1_RX_DMA */

#  if I2C1_TX_DMA
#    define I2C1_TX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C1_TX_DMA_NUMBER, I2C1_TX_DMA_STREAM)
#    define I2C1_TX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C1_TX_DMA_NUMBER, I2C1_TX_DMA_STREAM)
#  endif /* I2C1_TX_DMA */

#endif /* I2C1_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup I2C2 Functions
 * @{
 */

#if I2C2_ENABLE

#if (I2C2_SCL_ID == 0)
#  define I2C2_SCL_GPIO_AF GPIO_AF4_I2C2
#elif (I2C2_SCL_ID == 1)
#  define I2C2_SCL_GPIO_AF GPIO_AF4_I2C2
#elif (I2C2_SCL_ID == 2)
#  define I2C2_SCL_GPIO_AF GPIO_AF4_I2C2
#  if (defined(STM32H733xx) || defined(STM32H723xx))
#    error "PH4 can not be configured as I2C2 SCL on STM32H733xx, STM32H723xx! "
#  endif  /* (defined(STM32H733xx) || defined(STM32H723xx)) */
#endif  /* I2C2_SCL_ID */

#if (I2C2_SDA_ID == 0)
#  define I2C2_SDA_GPIO_AF GPIO_AF4_I2C2
#elif (I2C2_SDA_ID == 1)
#  define I2C2_SDA_GPIO_AF GPIO_AF4_I2C2
#elif (I2C2_SDA_ID == 2)
#  define I2C2_SDA_GPIO_AF GPIO_AF4_I2C2
#  if (defined(STM32H733xx) || defined(STM32H723xx))
#    error "PH5 can not be configured as I2C2 SDA on STM32H733xx, STM32H723xx! "
#  endif  /* (defined(STM32H733xx) || defined(STM32H723xx)) */
#endif  /* I2C2_SDA_ID */

extern I2C_HandleTypeDef i2c2_handle;

uint8_t i2c2_init(uint32_t clock_speed, uint32_t address,
                  uint32_t address_mode);
uint8_t i2c2_deinit(void); 

#  if I2C2_RX_DMA
#    define I2C2_RX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C2_RX_DMA_NUMBER, I2C2_RX_DMA_STREAM)
#    define I2C2_RX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C2_RX_DMA_NUMBER, I2C2_RX_DMA_STREAM)
#  endif /* I2C2_RX_DMA */

#  if I2C2_TX_DMA
#    define I2C2_TX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C2_TX_DMA_NUMBER, I2C2_TX_DMA_STREAM)
#    define I2C2_TX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C2_TX_DMA_NUMBER, I2C2_TX_DMA_STREAM)
#  endif /* I2C2_TX_DMA */

#endif /* I2C2_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup I2C3 Functions
 * @{
 */

#if I2C3_ENABLE

#if (I2C3_SCL_ID == 0)
#  define I2C3_SCL_GPIO_AF GPIO_AF4_I2C3
#elif (I2C3_SCL_ID == 1)
#  define I2C3_SCL_GPIO_AF GPIO_AF4_I2C3
#  if (defined(STM32H733xx) || defined(STM32H723xx))
#    error "PH7 can not be configured as I2C3 SCL on STM32H733xx, STM32H723xx! "
#  endif  /* (defined(STM32H733xx) || defined(STM32H723xx)) */
#endif  /* I2C3_SCL_ID */

#if (I2C3_SDA_ID == 0)
#  define I2C3_SDA_GPIO_AF GPIO_AF4_I2C3
#elif (I2C3_SDA_ID == 1)
#  define I2C3_SDA_GPIO_AF GPIO_AF4_I2C3
#  if (defined(STM32H733xx) || defined(STM32H723xx))
#    error "PH8 can not be configured as I2C3 SDA on STM32H733xx, STM32H723xx! "
#  endif  /* (defined(STM32H733xx) || defined(STM32H723xx)) */
#endif  /* I2C3_SDA_ID */

extern I2C_HandleTypeDef i2c3_handle;

uint8_t i2c3_init(uint32_t clock_speed, uint32_t address,
                  uint32_t address_mode);
uint8_t i2c3_deinit(void); 

#  if I2C3_RX_DMA
#    define I2C3_RX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C3_RX_DMA_NUMBER, I2C3_RX_DMA_STREAM)
#    define I2C3_RX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C3_RX_DMA_NUMBER, I2C3_RX_DMA_STREAM)
#  endif /* I2C3_RX_DMA */

#  if I2C3_TX_DMA
#    define I2C3_TX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C3_TX_DMA_NUMBER, I2C3_TX_DMA_STREAM)
#    define I2C3_TX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C3_TX_DMA_NUMBER, I2C3_TX_DMA_STREAM)
#  endif /* I2C3_TX_DMA */

#endif /* I2C3_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup I2C4 Functions
 * @{
 */

#if I2C4_ENABLE

#if (I2C4_SCL_ID == 0)
#  define I2C4_SCL_GPIO_AF GPIO_AF6_I2C4
#elif (I2C4_SCL_ID == 1)
#  define I2C4_SCL_GPIO_AF GPIO_AF6_I2C4
#elif (I2C4_SCL_ID == 2)
#  define I2C4_SCL_GPIO_AF GPIO_AF4_I2C4
#elif (I2C4_SCL_ID == 3)
#  define I2C4_SCL_GPIO_AF GPIO_AF4_I2C4
#elif (I2C4_SCL_ID == 4)
#  define I2C4_SCL_GPIO_AF GPIO_AF4_I2C4
#  if (defined(STM32H733xx) || defined(STM32H723xx))
#    error "PH11 can not be configured as I2C4 SCL on STM32H733xx, STM32H723xx! "
#  endif  /* (defined(STM32H733xx) || defined(STM32H723xx)) */
#endif  /* I2C4_SCL_ID */

#if (I2C4_SDA_ID == 0)
#  define I2C4_SDA_GPIO_AF GPIO_AF6_I2C4
#elif (I2C4_SDA_ID == 1)
#  define I2C4_SDA_GPIO_AF GPIO_AF6_I2C4
#elif (I2C4_SDA_ID == 2)
#  define I2C4_SDA_GPIO_AF GPIO_AF4_I2C4
#elif (I2C4_SDA_ID == 3)
#  define I2C4_SDA_GPIO_AF GPIO_AF4_I2C4
#elif (I2C4_SDA_ID == 4)
#  define I2C4_SDA_GPIO_AF GPIO_AF4_I2C4
#  if (defined(STM32H733xx) || defined(STM32H723xx))
#    error "PH12 can not be configured as I2C4 SDA on STM32H733xx, STM32H723xx! "
#  endif  /* (defined(STM32H733xx) || defined(STM32H723xx)) */
#endif  /* I2C4_SDA_ID */

extern I2C_HandleTypeDef i2c4_handle;

uint8_t i2c4_init(uint32_t clock_speed, uint32_t address,
                  uint32_t address_mode);
uint8_t i2c4_deinit(void); 

#  if I2C4_RX_DMA
#    define I2C4_RX_DMA_IRQn                                                  \
      CSP_BDMA_CHANNEL_IRQn(I2C4_RX_BDMA_CHANNEL)
#    define I2C4_RX_DMA_IRQHandler                                             \
      CSP_BDMA_CHANNEL_IRQ(I2C4_RX_BDMA_CHANNEL)
#  endif /* I2C4_RX_DMA */

#  if I2C4_TX_DMA
#    define I2C4_TX_DMA_IRQn                                                  \
      CSP_BDMA_CHANNEL_IRQn(I2C4_TX_BDMA_CHANNEL)
#    define I2C4_TX_DMA_IRQHandler                                             \
      CSP_BDMA_CHANNEL_IRQ(I2C4_TX_BDMA_CHANNEL)
#  endif /* I2C4_TX_DMA */

#endif /* I2C4_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup I2C5 Functions
 * @{
 */

#if I2C5_ENABLE

#if (I2C5_SCL_ID == 0)
#  define I2C5_SCL_GPIO_AF GPIO_AF6_I2C5
#elif (I2C5_SCL_ID == 1)
#  define I2C5_SCL_GPIO_AF GPIO_AF4_I2C5
#elif (I2C5_SCL_ID == 2)
#  define I2C5_SCL_GPIO_AF GPIO_AF6_I2C5
#endif  /* I2C5_SCL_ID */

#if (I2C5_SDA_ID == 0)
#  define I2C5_SDA_GPIO_AF GPIO_AF6_I2C5
#elif (I2C5_SDA_ID == 1)
#  define I2C5_SDA_GPIO_AF GPIO_AF4_I2C5
#elif (I2C5_SDA_ID == 2)
#  define I2C5_SDA_GPIO_AF GPIO_AF6_I2C5
#endif  /* I2C5_SDA_ID */

extern I2C_HandleTypeDef i2c5_handle;

uint8_t i2c5_init(uint32_t clock_speed, uint32_t address,
                  uint32_t address_mode);
uint8_t i2c5_deinit(void); 

#  if I2C5_RX_DMA
#    define I2C5_RX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C5_RX_DMA_NUMBER, I2C5_RX_DMA_STREAM)
#    define I2C5_RX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C5_RX_DMA_NUMBER, I2C5_RX_DMA_STREAM)
#  endif /* I2C5_RX_DMA */

#  if I2C5_TX_DMA
#    define I2C5_TX_DMA_IRQn                                                  \
      CSP_DMA_STREAM_IRQn(I2C5_TX_DMA_NUMBER, I2C5_TX_DMA_STREAM)
#    define I2C5_TX_DMA_IRQHandler                                             \
      CSP_DMA_STREAM_IRQ(I2C5_TX_DMA_NUMBER, I2C5_TX_DMA_STREAM)
#  endif /* I2C5_TX_DMA */

#endif /* I2C5_ENABLE */

/**
 * @}
 */

    
/* clang-format on */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __I2C_STM32H7xx_H */  
