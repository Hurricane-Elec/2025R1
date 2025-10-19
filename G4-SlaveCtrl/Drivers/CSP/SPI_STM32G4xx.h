/**
 * @file    SPI_STM32G4xx.h
 * @author  Deadline039
 * @brief   Chip Support Package of SPI and QSPI on STM32G4xx
 * @version 3.3.0
 * @date    2025-04-10
 * @note    Generate Automatically.
 */

#ifndef __SPI_STM32G4xx_H
#define __SPI_STM32G4xx_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*****************************************************************************
 * @defgroup SPI Public Marcos and Types. 
 * @{
 */

#define SPI_INIT_OK         0
#define SPI_INIT_FAIL       1
#define SPI_INIT_DMA_FAIL   2
#define SPI_INITED          3

#define SPI_DEINIT_OK       0
#define SPI_DEINIT_FAIL     1
#define SPI_DEINIT_DMA_FAIL 2
#define SPI_NO_INIT         3

#define SPI_RW_TIMEOUT      1000

/**
 * @brief SPI Clock Mode select.
 */
typedef enum {
    SPI_CLK_MODE0, /*!< Mode 0: CPOL=0; CPHA=0 */
    SPI_CLK_MODE1, /*!< Mode 1: CPOL=0; CPHA=1 */
    SPI_CLK_MODE2, /*!< Mode 2: CPOL=1; CPHA=0 */
    SPI_CLK_MODE3  /*!< Mode 3: CPOL=1; CPHA=1 */
} spi_clk_mode_t;

/**
 * @}
 */


/*****************************************************************************
 * @defgroup SPI1 Functions
 * @{
 */

#if SPI1_ENABLE

#if (SPI1_SCK_ID == 0)
#  define SPI1_SCK_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_SCK_ID == 1)
#  define SPI1_SCK_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_SCK_ID == 2)
#  define SPI1_SCK_GPIO_AF GPIO_AF5_SPI1
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PG2 can not be configured as SPI1 SCK on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI1_SCK_ID */

#if (SPI1_MISO_ID == 0)
#elif (SPI1_MISO_ID == 1)
#  define SPI1_MISO_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_MISO_ID == 2)
#  define SPI1_MISO_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_MISO_ID == 3)
#  define SPI1_MISO_GPIO_AF GPIO_AF5_SPI1
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PG3 can not be configured as SPI1 MISO on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI1_MISO_ID */

#if (SPI1_MOSI_ID == 0)
#elif (SPI1_MOSI_ID == 1)
#  define SPI1_MOSI_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_MOSI_ID == 2)
#  define SPI1_MOSI_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_MOSI_ID == 3)
#  define SPI1_MOSI_GPIO_AF GPIO_AF5_SPI1
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PG4 can not be configured as SPI1 MOSI on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI1_MOSI_ID */

#if (SPI1_NSS_ID == 0)
#elif (SPI1_NSS_ID == 1)
#  define SPI1_NSS_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_NSS_ID == 2)
#  define SPI1_NSS_GPIO_AF GPIO_AF5_SPI1
#elif (SPI1_NSS_ID == 3)
#  define SPI1_NSS_GPIO_AF GPIO_AF5_SPI1
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PG5 can not be configured as SPI1 NSS on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI1_NSS_ID */

extern SPI_HandleTypeDef spi1_handle;

uint8_t spi1_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
                  uint32_t first_bit);
uint8_t spi1_deinit(void); 

#  if SPI1_RX_DMA
#    define SPI1_RX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI1_RX_DMA_NUMBER, SPI1_RX_DMA_CHANNEL)
#    define SPI1_RX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI1_RX_DMA_NUMBER, SPI1_RX_DMA_CHANNEL)
#  endif /* SPI1_RX_DMA */

#  if SPI1_TX_DMA
#    define SPI1_TX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI1_TX_DMA_NUMBER, SPI1_TX_DMA_CHANNEL)
#    define SPI1_TX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI1_TX_DMA_NUMBER, SPI1_TX_DMA_CHANNEL)
#  endif /* SPI1_TX_DMA */

#endif /* SPI1_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI2 Functions
 * @{
 */

#if SPI2_ENABLE

#if (SPI2_SCK_ID == 0)
#  define SPI2_SCK_GPIO_AF GPIO_AF5_SPI2
#elif (SPI2_SCK_ID == 1)
#  define SPI2_SCK_GPIO_AF GPIO_AF5_SPI2
#elif (SPI2_SCK_ID == 2)
#  define SPI2_SCK_GPIO_AF GPIO_AF5_SPI2
#  if (defined(STM32GBK1CB))
#    error "PF9 can not be configured as SPI2 SCK on STM32GBK1CB! "
#  endif  /* (defined(STM32GBK1CB)) */
#elif (SPI2_SCK_ID == 3)
#  define SPI2_SCK_GPIO_AF GPIO_AF5_SPI2
#  if (defined(STM32GBK1CB))
#    error "PF10 can not be configured as SPI2 SCK on STM32GBK1CB! "
#  endif  /* (defined(STM32GBK1CB)) */
#endif  /* SPI2_SCK_ID */

#if (SPI2_MISO_ID == 0)
#elif (SPI2_MISO_ID == 1)
#  define SPI2_MISO_GPIO_AF GPIO_AF5_SPI2
#elif (SPI2_MISO_ID == 2)
#  define SPI2_MISO_GPIO_AF GPIO_AF5_SPI2
#endif  /* SPI2_MISO_ID */

#if (SPI2_MOSI_ID == 0)
#elif (SPI2_MOSI_ID == 1)
#  define SPI2_MOSI_GPIO_AF GPIO_AF5_SPI2
#elif (SPI2_MOSI_ID == 2)
#  define SPI2_MOSI_GPIO_AF GPIO_AF5_SPI2
#endif  /* SPI2_MOSI_ID */

#if (SPI2_NSS_ID == 0)
#elif (SPI2_NSS_ID == 1)
#  define SPI2_NSS_GPIO_AF GPIO_AF5_SPI2
#elif (SPI2_NSS_ID == 2)
#  define SPI2_NSS_GPIO_AF GPIO_AF6_SPI2
#  if (defined(STM32GBK1CB))
#    error "PD15 can not be configured as SPI2 NSS on STM32GBK1CB! "
#  endif  /* (defined(STM32GBK1CB)) */
#elif (SPI2_NSS_ID == 3)
#  define SPI2_NSS_GPIO_AF GPIO_AF5_SPI2
#endif  /* SPI2_NSS_ID */

extern SPI_HandleTypeDef spi2_handle;

uint8_t spi2_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
                  uint32_t first_bit);
uint8_t spi2_deinit(void); 

#  if SPI2_RX_DMA
#    define SPI2_RX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI2_RX_DMA_NUMBER, SPI2_RX_DMA_CHANNEL)
#    define SPI2_RX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI2_RX_DMA_NUMBER, SPI2_RX_DMA_CHANNEL)
#  endif /* SPI2_RX_DMA */

#  if SPI2_TX_DMA
#    define SPI2_TX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI2_TX_DMA_NUMBER, SPI2_TX_DMA_CHANNEL)
#    define SPI2_TX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI2_TX_DMA_NUMBER, SPI2_TX_DMA_CHANNEL)
#  endif /* SPI2_TX_DMA */

#endif /* SPI2_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI3 Functions
 * @{
 */

#if SPI3_ENABLE

#if (SPI3_SCK_ID == 0)
#  define SPI3_SCK_GPIO_AF GPIO_AF6_SPI3
#elif (SPI3_SCK_ID == 1)
#  define SPI3_SCK_GPIO_AF GPIO_AF6_SPI3
#  if (defined(STM32GBK1CB))
#    error "PC10 can not be configured as SPI3 SCK on STM32GBK1CB! "
#  endif  /* (defined(STM32GBK1CB)) */
#elif (SPI3_SCK_ID == 2)
#  define SPI3_SCK_GPIO_AF GPIO_AF6_SPI3
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PG9 can not be configured as SPI3 SCK on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI3_SCK_ID */

#if (SPI3_MISO_ID == 0)
#elif (SPI3_MISO_ID == 1)
#  define SPI3_MISO_GPIO_AF GPIO_AF6_SPI3
#elif (SPI3_MISO_ID == 2)
#  define SPI3_MISO_GPIO_AF GPIO_AF6_SPI3
#  if (defined(STM32GBK1CB))
#    error "PC11 can not be configured as SPI3 MISO on STM32GBK1CB! "
#  endif  /* (defined(STM32GBK1CB)) */
#endif  /* SPI3_MISO_ID */

#if (SPI3_MOSI_ID == 0)
#elif (SPI3_MOSI_ID == 1)
#  define SPI3_MOSI_GPIO_AF GPIO_AF6_SPI3
#elif (SPI3_MOSI_ID == 2)
#  define SPI3_MOSI_GPIO_AF GPIO_AF6_SPI3
#  if (defined(STM32GBK1CB))
#    error "PC12 can not be configured as SPI3 MOSI on STM32GBK1CB! "
#  endif  /* (defined(STM32GBK1CB)) */
#endif  /* SPI3_MOSI_ID */

#if (SPI3_NSS_ID == 0)
#elif (SPI3_NSS_ID == 1)
#  define SPI3_NSS_GPIO_AF GPIO_AF6_SPI3
#elif (SPI3_NSS_ID == 2)
#  define SPI3_NSS_GPIO_AF GPIO_AF6_SPI3
#endif  /* SPI3_NSS_ID */

extern SPI_HandleTypeDef spi3_handle;

uint8_t spi3_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
                  uint32_t first_bit);
uint8_t spi3_deinit(void); 

#  if SPI3_RX_DMA
#    define SPI3_RX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI3_RX_DMA_NUMBER, SPI3_RX_DMA_CHANNEL)
#    define SPI3_RX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI3_RX_DMA_NUMBER, SPI3_RX_DMA_CHANNEL)
#  endif /* SPI3_RX_DMA */

#  if SPI3_TX_DMA
#    define SPI3_TX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI3_TX_DMA_NUMBER, SPI3_TX_DMA_CHANNEL)
#    define SPI3_TX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI3_TX_DMA_NUMBER, SPI3_TX_DMA_CHANNEL)
#  endif /* SPI3_TX_DMA */

#endif /* SPI3_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI4 Functions
 * @{
 */

#if SPI4_ENABLE

#if (SPI4_SCK_ID == 0)
#  define SPI4_SCK_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE2 can not be configured as SPI4 SCK on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#elif (SPI4_SCK_ID == 1)
#  define SPI4_SCK_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE12 can not be configured as SPI4 SCK on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI4_SCK_ID */

#if (SPI4_MISO_ID == 0)
#elif (SPI4_MISO_ID == 1)
#  define SPI4_MISO_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE5 can not be configured as SPI4 MISO on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#elif (SPI4_MISO_ID == 2)
#  define SPI4_MISO_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE13 can not be configured as SPI4 MISO on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI4_MISO_ID */

#if (SPI4_MOSI_ID == 0)
#elif (SPI4_MOSI_ID == 1)
#  define SPI4_MOSI_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE6 can not be configured as SPI4 MOSI on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#elif (SPI4_MOSI_ID == 2)
#  define SPI4_MOSI_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE14 can not be configured as SPI4 MOSI on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI4_MOSI_ID */

#if (SPI4_NSS_ID == 0)
#elif (SPI4_NSS_ID == 1)
#  define SPI4_NSS_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE3 can not be configured as SPI4 NSS on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#elif (SPI4_NSS_ID == 2)
#  define SPI4_NSS_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE4 can not be configured as SPI4 NSS on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#elif (SPI4_NSS_ID == 3)
#  define SPI4_NSS_GPIO_AF GPIO_AF5_SPI4
#  if (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx))
#    error "PE11 can not be configured as SPI4 NSS on STM32G491xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G441xx)) */
#endif  /* SPI4_NSS_ID */

extern SPI_HandleTypeDef spi4_handle;

uint8_t spi4_init(uint32_t mode, spi_clk_mode_t clk_mode, uint32_t data_size,
                  uint32_t first_bit);
uint8_t spi4_deinit(void); 

#  if SPI4_RX_DMA
#    define SPI4_RX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI4_RX_DMA_NUMBER, SPI4_RX_DMA_CHANNEL)
#    define SPI4_RX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI4_RX_DMA_NUMBER, SPI4_RX_DMA_CHANNEL)
#  endif /* SPI4_RX_DMA */

#  if SPI4_TX_DMA
#    define SPI4_TX_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(SPI4_TX_DMA_NUMBER, SPI4_TX_DMA_CHANNEL)
#    define SPI4_TX_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(SPI4_TX_DMA_NUMBER, SPI4_TX_DMA_CHANNEL)
#  endif /* SPI4_TX_DMA */

#endif /* SPI4_ENABLE */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup SPI Public Functions
 * @{
 */

uint8_t spi_rw_one_byte(SPI_HandleTypeDef *hspi, uint8_t byte);
uint16_t spi_rw_two_byte(SPI_HandleTypeDef *hspi, uint16_t tx_data);

uint8_t spi_change_speed(SPI_HandleTypeDef *hspi, uint8_t speed);

/**
 * @}
 */
 
/* clang-format off */

#if QUADSPI1_ENABLE

#if (QUADSPI_CLK_ID == 0)
#  define QUADSPI_CLK_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PA3 can not be configured as QUADSPI CLK on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_CLK_ID == 1)
#  define QUADSPI_CLK_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB10 can not be configured as QUADSPI CLK on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_CLK_ID == 2)
#  define QUADSPI_CLK_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE10 can not be configured as QUADSPI CLK on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_CLK_ID == 3)
#  define QUADSPI_CLK_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF10 can not be configured as QUADSPI CLK on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_CLK_ID */

#if QUADSPI1_BANK1_ENABLE

#if (QUADSPI_BK1_IO0_ID == 0)
#elif (QUADSPI_BK1_IO0_ID == 1)
#  define QUADSPI_BK1_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB1 can not be configured as QUADSPI BK1_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO0_ID == 2)
#  define QUADSPI_BK1_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC1 can not be configured as QUADSPI BK1_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO0_ID == 3)
#  define QUADSPI_BK1_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD4 can not be configured as QUADSPI BK1_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO0_ID == 4)
#  define QUADSPI_BK1_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE12 can not be configured as QUADSPI BK1_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO0_ID == 5)
#  define QUADSPI_BK1_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF8 can not be configured as QUADSPI BK1_IO0 on STM32G491xx, STM32G483xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK1_IO0_ID */

#if (QUADSPI_BK1_IO1_ID == 0)
#elif (QUADSPI_BK1_IO1_ID == 1)
#  define QUADSPI_BK1_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB0 can not be configured as QUADSPI BK1_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO1_ID == 2)
#  define QUADSPI_BK1_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB2 can not be configured as QUADSPI BK1_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO1_ID == 3)
#  define QUADSPI_BK1_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC2 can not be configured as QUADSPI BK1_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO1_ID == 4)
#  define QUADSPI_BK1_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD5 can not be configured as QUADSPI BK1_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO1_ID == 5)
#  define QUADSPI_BK1_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE13 can not be configured as QUADSPI BK1_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO1_ID == 6)
#  define QUADSPI_BK1_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF9 can not be configured as QUADSPI BK1_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK1_IO1_ID */

#if (QUADSPI_BK1_IO2_ID == 0)
#elif (QUADSPI_BK1_IO2_ID == 1)
#  define QUADSPI_BK1_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PA7 can not be configured as QUADSPI BK1_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO2_ID == 2)
#  define QUADSPI_BK1_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC3 can not be configured as QUADSPI BK1_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO2_ID == 3)
#  define QUADSPI_BK1_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD6 can not be configured as QUADSPI BK1_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO2_ID == 4)
#  define QUADSPI_BK1_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE14 can not be configured as QUADSPI BK1_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO2_ID == 5)
#  define QUADSPI_BK1_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF7 can not be configured as QUADSPI BK1_IO2 on STM32G491xx, STM32G483xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK1_IO2_ID */

#if (QUADSPI_BK1_IO3_ID == 0)
#elif (QUADSPI_BK1_IO3_ID == 1)
#  define QUADSPI_BK1_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PA6 can not be configured as QUADSPI BK1_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO3_ID == 2)
#  define QUADSPI_BK1_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC4 can not be configured as QUADSPI BK1_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO3_ID == 3)
#  define QUADSPI_BK1_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD7 can not be configured as QUADSPI BK1_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO3_ID == 4)
#  define QUADSPI_BK1_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE15 can not be configured as QUADSPI BK1_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_IO3_ID == 5)
#  define QUADSPI_BK1_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF6 can not be configured as QUADSPI BK1_IO3 on STM32G491xx, STM32G483xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK1_IO3_ID */

#if (QUADSPI_BK1_NCS_ID == 0)
#elif (QUADSPI_BK1_NCS_ID == 1)
#  define QUADSPI_BK1_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PA2 can not be configured as QUADSPI BK1_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_NCS_ID == 2)
#  define QUADSPI_BK1_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB11 can not be configured as QUADSPI BK1_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_NCS_ID == 3)
#  define QUADSPI_BK1_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD3 can not be configured as QUADSPI BK1_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK1_NCS_ID == 4)
#  define QUADSPI_BK1_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE11 can not be configured as QUADSPI BK1_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK1_NCS_ID */

#endif /* QUADSPI1_BANK1_ENABLE */

#if QUADSPI1_BANK2_ENABLE

#if (QUADSPI_BK2_IO0_ID == 0)
#elif (QUADSPI_BK2_IO0_ID == 1)
#  define QUADSPI_BK2_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB1 can not be configured as QUADSPI BK2_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO0_ID == 2)
#  define QUADSPI_BK2_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC1 can not be configured as QUADSPI BK2_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO0_ID == 3)
#  define QUADSPI_BK2_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD4 can not be configured as QUADSPI BK2_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO0_ID == 4)
#  define QUADSPI_BK2_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE12 can not be configured as QUADSPI BK2_IO0 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO0_ID == 5)
#  define QUADSPI_BK2_IO0_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF8 can not be configured as QUADSPI BK2_IO0 on STM32G491xx, STM32G483xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK2_IO0_ID */

#if (QUADSPI_BK2_IO1_ID == 0)
#elif (QUADSPI_BK2_IO1_ID == 1)
#  define QUADSPI_BK2_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB0 can not be configured as QUADSPI BK2_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO1_ID == 2)
#  define QUADSPI_BK2_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB2 can not be configured as QUADSPI BK2_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO1_ID == 3)
#  define QUADSPI_BK2_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC2 can not be configured as QUADSPI BK2_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO1_ID == 4)
#  define QUADSPI_BK2_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD5 can not be configured as QUADSPI BK2_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO1_ID == 5)
#  define QUADSPI_BK2_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE13 can not be configured as QUADSPI BK2_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO1_ID == 6)
#  define QUADSPI_BK2_IO1_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF9 can not be configured as QUADSPI BK2_IO1 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK2_IO1_ID */

#if (QUADSPI_BK2_IO2_ID == 0)
#elif (QUADSPI_BK2_IO2_ID == 1)
#  define QUADSPI_BK2_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PA7 can not be configured as QUADSPI BK2_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO2_ID == 2)
#  define QUADSPI_BK2_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC3 can not be configured as QUADSPI BK2_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO2_ID == 3)
#  define QUADSPI_BK2_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD6 can not be configured as QUADSPI BK2_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO2_ID == 4)
#  define QUADSPI_BK2_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE14 can not be configured as QUADSPI BK2_IO2 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO2_ID == 5)
#  define QUADSPI_BK2_IO2_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF7 can not be configured as QUADSPI BK2_IO2 on STM32G491xx, STM32G483xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK2_IO2_ID */

#if (QUADSPI_BK2_IO3_ID == 0)
#elif (QUADSPI_BK2_IO3_ID == 1)
#  define QUADSPI_BK2_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PA6 can not be configured as QUADSPI BK2_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO3_ID == 2)
#  define QUADSPI_BK2_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PC4 can not be configured as QUADSPI BK2_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO3_ID == 3)
#  define QUADSPI_BK2_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD7 can not be configured as QUADSPI BK2_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO3_ID == 4)
#  define QUADSPI_BK2_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE15 can not be configured as QUADSPI BK2_IO3 on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_IO3_ID == 5)
#  define QUADSPI_BK2_IO3_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PF6 can not be configured as QUADSPI BK2_IO3 on STM32G491xx, STM32G483xx, STM32G4A1xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G491xx) || defined(STM32G483xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK2_IO3_ID */

#if (QUADSPI_BK2_NCS_ID == 0)
#elif (QUADSPI_BK2_NCS_ID == 1)
#  define QUADSPI_BK2_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PA2 can not be configured as QUADSPI BK2_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_NCS_ID == 2)
#  define QUADSPI_BK2_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PB11 can not be configured as QUADSPI BK2_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_NCS_ID == 3)
#  define QUADSPI_BK2_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PD3 can not be configured as QUADSPI BK2_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#elif (QUADSPI_BK2_NCS_ID == 4)
#  define QUADSPI_BK2_NCS_GPIO_AF GPIO_AF10_QUADSPI
#  if (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx))
#    error "PE11 can not be configured as QUADSPI BK2_NCS on STM32G483xx, STM32GBK1CB, STM32G431xx, STM32G471xx, STM32G473xx, STM32G441xx! "
#  endif  /* (defined(STM32G483xx) || defined(STM32GBK1CB) || defined(STM32G431xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G441xx)) */
#endif  /* QUADSPI_BK2_NCS_ID */

#endif /* QUADSPI1_BANK2_ENABLE */

extern QSPI_HandleTypeDef qspi1_handle;

uint8_t quadspi1_init(uint32_t clock_mode, uint32_t flash_size);

#  if QUADSPI1_DMA
#    define QUADSPI1_DMA_IRQn                                                  \
      CSP_DMA_CHANNEL_IRQn(QUADSPI1_DMA_NUMBER, QUADSPI1_DMA_CHANNEL)
#    define QUADSPI1_DMA_IRQHandler                                             \
      CSP_DMA_CHANNEL_IRQ(QUADSPI1_DMA_NUMBER, QUADSPI1_DMA_CHANNEL)
#  endif /* QUADSPI1_DMA */

/* clang-format on */

/*****************************************************************************
 * @defgroup QSPI Public Functions
 * @{
 */

#define QSPI_INIT_OK            0
#define QSPI_INIT_FAIL          1
#define QSPI_INIT_DMA_FAIL      2
#define QSPI_INITED             3

#define QSPI_DEINIT_OK          0
#define QSPI_DEINIT_FAIL        1
#define QSPI_DEINIT_DMA_FAIL    2
#define QSPI_NO_INIT            3

#define QSPI_RW_TIMEOUT         1000

uint8_t qspi_send_cmd(uint8_t cmd, uint32_t address, uint8_t mode,
                      uint8_t dummy_cycles);
uint8_t qspi_transmit(uint8_t *data, uint32_t len);
uint8_t qspi_receive(uint8_t *data, uint32_t len);

#endif /* QUADSPI1_ENABLE */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SPI_STM32G4xx_H */

