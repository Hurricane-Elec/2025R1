/**
 * @file    CSP_Config.h
 * @author  Deadline039
 * @brief   The CSP configuration of STM32H7xx.
 * @version 3.3.0
 * @date    2025-04-10
 * @note    Generate Automatically.
 */

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#ifndef __CSP_CONFIG_H
#define __CSP_CONFIG_H

// <e> LPUART1 (Low power universal asynchronous receiver transmitter)

#define LPUART1_ENABLE 0 

#if LPUART1_ENABLE

//   <o> LPUART1_TX Pin
//       <0=>Not Used <1=>PA9 <2=>PB6 
#define LPUART1_TX_ID 0

#if (LPUART1_TX_ID == 0)
#define LPUART1_TX 0
#elif (LPUART1_TX_ID == 1)
#define LPUART1_TX 1
#define LPUART1_TX_PORT A
#define LPUART1_TX_PIN GPIO_PIN_9
#elif (LPUART1_TX_ID == 2)
#define LPUART1_TX 1
#define LPUART1_TX_PORT B
#define LPUART1_TX_PIN GPIO_PIN_6
#else   /* LPUART1_TX_ID */
#error "Invalid LPUART1_TX Pin Configuration! "
#endif  /* LPUART1_TX_ID */

//   <o> LPUART1_RX Pin
//       <0=>Not Used <1=>PA10 <2=>PB7 
#define LPUART1_RX_ID 0

#if (LPUART1_RX_ID == 0)
#define LPUART1_RX 0
#elif (LPUART1_RX_ID == 1)
#define LPUART1_RX 1
#define LPUART1_RX_PORT A
#define LPUART1_RX_PIN GPIO_PIN_10
#elif (LPUART1_RX_ID == 2)
#define LPUART1_RX 1
#define LPUART1_RX_PORT B
#define LPUART1_RX_PIN GPIO_PIN_7
#else   /* LPUART1_RX_ID */
#error "Invalid LPUART1_RX Pin Configuration! "
#endif  /* LPUART1_RX_ID */

//   <o> LPUART1_CTS Pin
//       <0=>Not Used <1=>PA11 
#define LPUART1_CTS_ID 0

#if (LPUART1_CTS_ID == 0)
#define LPUART1_CTS 0
#elif (LPUART1_CTS_ID == 1)
#define LPUART1_CTS 1
#define LPUART1_CTS_PORT A
#define LPUART1_CTS_PIN GPIO_PIN_11
#else   /* LPUART1_CTS_ID */
#error "Invalid LPUART1_CTS Pin Configuration! "
#endif  /* LPUART1_CTS_ID */

//   <o> LPUART1_RTS Pin
//       <0=>Not Used <1=>PA12 
#define LPUART1_RTS_ID 0

#if (LPUART1_RTS_ID == 0)
#define LPUART1_RTS 0
#elif (LPUART1_RTS_ID == 1)
#define LPUART1_RTS 1
#define LPUART1_RTS_PORT A
#define LPUART1_RTS_PIN GPIO_PIN_12
#else   /* LPUART1_RTS_ID */
#error "Invalid LPUART1_RTS Pin Configuration! "
#endif  /* LPUART1_RTS_ID */

//   <e> Enable LPUART1 Interrupt
#define LPUART1_IT_ENABLE 0

#if LPUART1_IT_ENABLE

//   <o> LPUART1 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of LPUART1
#define LPUART1_IT_PRIORITY        2
//   <o> LPUART1 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of LPUART1
#define LPUART1_IT_SUB             3

//   </e>
#endif /* LPUART1_IT_ENABLE */

//   <e> Enable LPUART1 DMA RX
#define LPUART1_RX_DMA             0

#if LPUART1_RX_DMA

//     <o> BDMA Channel <0-7>
//     <i>  Selects BDMA Number
#define LPUART1_RX_BDMA_CHANNEL     1

//     <o LPUART1_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define LPUART1_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define LPUART1_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define LPUART1_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define LPUART1_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define LPUART1_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* LPUART1_RX_DMA */

//   <e> Enable LPUART1 DMA TX
#define LPUART1_TX_DMA             0

#if LPUART1_TX_DMA

//     <o> BDMA Channel <0-7>
//     <i>  Selects BDMA Number
#define LPUART1_TX_BDMA_CHANNEL     1

//     <o LPUART1_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define LPUART1_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define LPUART1_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define LPUART1_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define LPUART1_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* LPUART1_TX_DMA */

#endif  /* LPUART1_ENABLE */
// </e>

// <e> USART1 (Universal asynchronous receiver transmitter)

#define USART1_ENABLE 1 

#if USART1_ENABLE

//   <o> USART1_TX Pin
//       <0=>Not Used <1=>PA9 <2=>PB6 <3=>PB14 
#define USART1_TX_ID 1

#if (USART1_TX_ID == 0)
#define USART1_TX 0
#elif (USART1_TX_ID == 1)
#define USART1_TX 1
#define USART1_TX_PORT A
#define USART1_TX_PIN GPIO_PIN_9
#elif (USART1_TX_ID == 2)
#define USART1_TX 1
#define USART1_TX_PORT B
#define USART1_TX_PIN GPIO_PIN_6
#elif (USART1_TX_ID == 3)
#define USART1_TX 1
#define USART1_TX_PORT B
#define USART1_TX_PIN GPIO_PIN_14
#else   /* USART1_TX_ID */
#error "Invalid USART1_TX Pin Configuration! "
#endif  /* USART1_TX_ID */

//   <o> USART1_RX Pin
//       <0=>Not Used <1=>PA10 <2=>PB7 <3=>PB15 
#define USART1_RX_ID 1

#if (USART1_RX_ID == 0)
#define USART1_RX 0
#elif (USART1_RX_ID == 1)
#define USART1_RX 1
#define USART1_RX_PORT A
#define USART1_RX_PIN GPIO_PIN_10
#elif (USART1_RX_ID == 2)
#define USART1_RX 1
#define USART1_RX_PORT B
#define USART1_RX_PIN GPIO_PIN_7
#elif (USART1_RX_ID == 3)
#define USART1_RX 1
#define USART1_RX_PORT B
#define USART1_RX_PIN GPIO_PIN_15
#else   /* USART1_RX_ID */
#error "Invalid USART1_RX Pin Configuration! "
#endif  /* USART1_RX_ID */

//   <o> USART1_CTS Pin
//       <0=>Not Used <1=>PA11 
#define USART1_CTS_ID 0

#if (USART1_CTS_ID == 0)
#define USART1_CTS 0
#elif (USART1_CTS_ID == 1)
#define USART1_CTS 1
#define USART1_CTS_PORT A
#define USART1_CTS_PIN GPIO_PIN_11
#else   /* USART1_CTS_ID */
#error "Invalid USART1_CTS Pin Configuration! "
#endif  /* USART1_CTS_ID */

//   <o> USART1_RTS Pin
//       <0=>Not Used <1=>PA12 
#define USART1_RTS_ID 0

#if (USART1_RTS_ID == 0)
#define USART1_RTS 0
#elif (USART1_RTS_ID == 1)
#define USART1_RTS 1
#define USART1_RTS_PORT A
#define USART1_RTS_PIN GPIO_PIN_12
#else   /* USART1_RTS_ID */
#error "Invalid USART1_RTS Pin Configuration! "
#endif  /* USART1_RTS_ID */

//   <e> Enable USART1 Interrupt
#define USART1_IT_ENABLE 1

#if USART1_IT_ENABLE

//   <o> USART1 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of USART1
#define USART1_IT_PRIORITY        2
//   <o> USART1 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of USART1
#define USART1_IT_SUB             3

//   </e>
#endif /* USART1_IT_ENABLE */

//   <e> Enable USART1 DMA RX
#define USART1_RX_DMA             0

#if USART1_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART1_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART1_RX_DMA_STREAM      1

//     <o USART1_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART1_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART1_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART1_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART1_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART1_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* USART1_RX_DMA */

//   <e> Enable USART1 DMA TX
#define USART1_TX_DMA             0

#if USART1_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART1_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART1_TX_DMA_STREAM      1

//     <o USART1_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART1_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART1_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART1_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define USART1_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* USART1_TX_DMA */

#endif  /* USART1_ENABLE */
// </e>

// <e> USART2 (Universal asynchronous receiver transmitter)

#define USART2_ENABLE 0 

#if USART2_ENABLE

//   <o> USART2_TX Pin
//       <0=>Not Used <1=>PA2 <2=>PD5 
#define USART2_TX_ID 0

#if (USART2_TX_ID == 0)
#define USART2_TX 0
#elif (USART2_TX_ID == 1)
#define USART2_TX 1
#define USART2_TX_PORT A
#define USART2_TX_PIN GPIO_PIN_2
#elif (USART2_TX_ID == 2)
#define USART2_TX 1
#define USART2_TX_PORT D
#define USART2_TX_PIN GPIO_PIN_5
#else   /* USART2_TX_ID */
#error "Invalid USART2_TX Pin Configuration! "
#endif  /* USART2_TX_ID */

//   <o> USART2_RX Pin
//       <0=>Not Used <1=>PA3 <2=>PD6 
#define USART2_RX_ID 0

#if (USART2_RX_ID == 0)
#define USART2_RX 0
#elif (USART2_RX_ID == 1)
#define USART2_RX 1
#define USART2_RX_PORT A
#define USART2_RX_PIN GPIO_PIN_3
#elif (USART2_RX_ID == 2)
#define USART2_RX 1
#define USART2_RX_PORT D
#define USART2_RX_PIN GPIO_PIN_6
#else   /* USART2_RX_ID */
#error "Invalid USART2_RX Pin Configuration! "
#endif  /* USART2_RX_ID */

//   <o> USART2_CTS Pin
//       <0=>Not Used <1=>PA0 <2=>PD3 
#define USART2_CTS_ID 0

#if (USART2_CTS_ID == 0)
#define USART2_CTS 0
#elif (USART2_CTS_ID == 1)
#define USART2_CTS 1
#define USART2_CTS_PORT A
#define USART2_CTS_PIN GPIO_PIN_0
#elif (USART2_CTS_ID == 2)
#define USART2_CTS 1
#define USART2_CTS_PORT D
#define USART2_CTS_PIN GPIO_PIN_3
#else   /* USART2_CTS_ID */
#error "Invalid USART2_CTS Pin Configuration! "
#endif  /* USART2_CTS_ID */

//   <o> USART2_RTS Pin
//       <0=>Not Used <1=>PA1 <2=>PD4 
#define USART2_RTS_ID 0

#if (USART2_RTS_ID == 0)
#define USART2_RTS 0
#elif (USART2_RTS_ID == 1)
#define USART2_RTS 1
#define USART2_RTS_PORT A
#define USART2_RTS_PIN GPIO_PIN_1
#elif (USART2_RTS_ID == 2)
#define USART2_RTS 1
#define USART2_RTS_PORT D
#define USART2_RTS_PIN GPIO_PIN_4
#else   /* USART2_RTS_ID */
#error "Invalid USART2_RTS Pin Configuration! "
#endif  /* USART2_RTS_ID */

//   <e> Enable USART2 Interrupt
#define USART2_IT_ENABLE 0

#if USART2_IT_ENABLE

//   <o> USART2 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of USART2
#define USART2_IT_PRIORITY        2
//   <o> USART2 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of USART2
#define USART2_IT_SUB             3

//   </e>
#endif /* USART2_IT_ENABLE */

//   <e> Enable USART2 DMA RX
#define USART2_RX_DMA             0

#if USART2_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART2_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART2_RX_DMA_STREAM      1

//     <o USART2_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART2_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART2_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART2_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART2_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART2_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* USART2_RX_DMA */

//   <e> Enable USART2 DMA TX
#define USART2_TX_DMA             0

#if USART2_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART2_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART2_TX_DMA_STREAM      1

//     <o USART2_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART2_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART2_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART2_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define USART2_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* USART2_TX_DMA */

#endif  /* USART2_ENABLE */
// </e>

// <e> USART3 (Universal asynchronous receiver transmitter)

#define USART3_ENABLE 1

#if USART3_ENABLE

//   <o> USART3_TX Pin
//       <0=>Not Used <1=>PB10 <2=>PC10 <3=>PD8 
#define USART3_TX_ID 1

#if (USART3_TX_ID == 0)
#define USART3_TX 0
#elif (USART3_TX_ID == 1)
#define USART3_TX 1
#define USART3_TX_PORT B
#define USART3_TX_PIN GPIO_PIN_10
#elif (USART3_TX_ID == 2)
#define USART3_TX 1
#define USART3_TX_PORT C
#define USART3_TX_PIN GPIO_PIN_10
#elif (USART3_TX_ID == 3)
#define USART3_TX 1
#define USART3_TX_PORT D
#define USART3_TX_PIN GPIO_PIN_8
#else   /* USART3_TX_ID */
#error "Invalid USART3_TX Pin Configuration! "
#endif  /* USART3_TX_ID */

//   <o> USART3_RX Pin
//       <0=>Not Used <1=>PB11 <2=>PC11 <3=>PD9 
#define USART3_RX_ID 1

#if (USART3_RX_ID == 0)
#define USART3_RX 0
#elif (USART3_RX_ID == 1)
#define USART3_RX 1
#define USART3_RX_PORT B
#define USART3_RX_PIN GPIO_PIN_11
#elif (USART3_RX_ID == 2)
#define USART3_RX 1
#define USART3_RX_PORT C
#define USART3_RX_PIN GPIO_PIN_11
#elif (USART3_RX_ID == 3)
#define USART3_RX 1
#define USART3_RX_PORT D
#define USART3_RX_PIN GPIO_PIN_9
#else   /* USART3_RX_ID */
#error "Invalid USART3_RX Pin Configuration! "
#endif  /* USART3_RX_ID */

//   <o> USART3_CTS Pin
//       <0=>Not Used <1=>PB13 <2=>PD11 
#define USART3_CTS_ID 0

#if (USART3_CTS_ID == 0)
#define USART3_CTS 0
#elif (USART3_CTS_ID == 1)
#define USART3_CTS 1
#define USART3_CTS_PORT B
#define USART3_CTS_PIN GPIO_PIN_13
#elif (USART3_CTS_ID == 2)
#define USART3_CTS 1
#define USART3_CTS_PORT D
#define USART3_CTS_PIN GPIO_PIN_11
#else   /* USART3_CTS_ID */
#error "Invalid USART3_CTS Pin Configuration! "
#endif  /* USART3_CTS_ID */

//   <o> USART3_RTS Pin
//       <0=>Not Used <1=>PB14 <2=>PD12 
#define USART3_RTS_ID 0

#if (USART3_RTS_ID == 0)
#define USART3_RTS 0
#elif (USART3_RTS_ID == 1)
#define USART3_RTS 1
#define USART3_RTS_PORT B
#define USART3_RTS_PIN GPIO_PIN_14
#elif (USART3_RTS_ID == 2)
#define USART3_RTS 1
#define USART3_RTS_PORT D
#define USART3_RTS_PIN GPIO_PIN_12
#else   /* USART3_RTS_ID */
#error "Invalid USART3_RTS Pin Configuration! "
#endif  /* USART3_RTS_ID */

//   <e> Enable USART3 Interrupt
#define USART3_IT_ENABLE 1

#if USART3_IT_ENABLE

//   <o> USART3 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of USART3
#define USART3_IT_PRIORITY        2
//   <o> USART3 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of USART3
#define USART3_IT_SUB             3

//   </e>
#endif /* USART3_IT_ENABLE */

//   <e> Enable USART3 DMA RX
#define USART3_RX_DMA             1

#if USART3_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART3_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART3_RX_DMA_STREAM      1

//     <o USART3_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART3_RX_DMA_PRIORITY    DMA_PRIORITY_HIGH

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART3_RX_DMA_IT_PRIORITY 3

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART3_RX_DMA_IT_SUB      1

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART3_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART3_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* USART3_RX_DMA */

//   <e> Enable USART3 DMA TX
#define USART3_TX_DMA             1

#if USART3_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART3_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART3_TX_DMA_STREAM      2

//     <o USART3_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART3_TX_DMA_PRIORITY    DMA_PRIORITY_HIGH

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART3_TX_DMA_IT_PRIORITY 3

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART3_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define USART3_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* USART3_TX_DMA */

#endif  /* USART3_ENABLE */
// </e>

// <e> UART4 (Universal synchronous asynchronous receiver transmitter)

#define UART4_ENABLE 0 

#if UART4_ENABLE

//   <o> UART4_TX Pin
//       <0=>Not Used <1=>PA0 <2=>PA12 <3=>PB9 <4=>PC10 <5=>PD1 <6=>PH13 
#define UART4_TX_ID 0

#if (UART4_TX_ID == 0)
#define UART4_TX 0
#elif (UART4_TX_ID == 1)
#define UART4_TX 1
#define UART4_TX_PORT A
#define UART4_TX_PIN GPIO_PIN_0
#elif (UART4_TX_ID == 2)
#define UART4_TX 1
#define UART4_TX_PORT A
#define UART4_TX_PIN GPIO_PIN_12
#elif (UART4_TX_ID == 3)
#define UART4_TX 1
#define UART4_TX_PORT B
#define UART4_TX_PIN GPIO_PIN_9
#elif (UART4_TX_ID == 4)
#define UART4_TX 1
#define UART4_TX_PORT C
#define UART4_TX_PIN GPIO_PIN_10
#elif (UART4_TX_ID == 5)
#define UART4_TX 1
#define UART4_TX_PORT D
#define UART4_TX_PIN GPIO_PIN_1
#elif (UART4_TX_ID == 6)
#define UART4_TX 1
#define UART4_TX_PORT H
#define UART4_TX_PIN GPIO_PIN_13
#else   /* UART4_TX_ID */
#error "Invalid UART4_TX Pin Configuration! "
#endif  /* UART4_TX_ID */

//   <o> UART4_RX Pin
//       <0=>Not Used <1=>PA1 <2=>PA11 <3=>PB8 <4=>PC11 <5=>PD0 <6=>PH14 <7=>PI9 
#define UART4_RX_ID 0

#if (UART4_RX_ID == 0)
#define UART4_RX 0
#elif (UART4_RX_ID == 1)
#define UART4_RX 1
#define UART4_RX_PORT A
#define UART4_RX_PIN GPIO_PIN_1
#elif (UART4_RX_ID == 2)
#define UART4_RX 1
#define UART4_RX_PORT A
#define UART4_RX_PIN GPIO_PIN_11
#elif (UART4_RX_ID == 3)
#define UART4_RX 1
#define UART4_RX_PORT B
#define UART4_RX_PIN GPIO_PIN_8
#elif (UART4_RX_ID == 4)
#define UART4_RX 1
#define UART4_RX_PORT C
#define UART4_RX_PIN GPIO_PIN_11
#elif (UART4_RX_ID == 5)
#define UART4_RX 1
#define UART4_RX_PORT D
#define UART4_RX_PIN GPIO_PIN_0
#elif (UART4_RX_ID == 6)
#define UART4_RX 1
#define UART4_RX_PORT H
#define UART4_RX_PIN GPIO_PIN_14
#elif (UART4_RX_ID == 7)
#define UART4_RX 1
#define UART4_RX_PORT I
#define UART4_RX_PIN GPIO_PIN_9
#else   /* UART4_RX_ID */
#error "Invalid UART4_RX Pin Configuration! "
#endif  /* UART4_RX_ID */

//   <o> UART4_CTS Pin
//       <0=>Not Used <1=>PB0 <2=>PB15 
#define UART4_CTS_ID 0

#if (UART4_CTS_ID == 0)
#define UART4_CTS 0
#elif (UART4_CTS_ID == 1)
#define UART4_CTS 1
#define UART4_CTS_PORT B
#define UART4_CTS_PIN GPIO_PIN_0
#elif (UART4_CTS_ID == 2)
#define UART4_CTS 1
#define UART4_CTS_PORT B
#define UART4_CTS_PIN GPIO_PIN_15
#else   /* UART4_CTS_ID */
#error "Invalid UART4_CTS Pin Configuration! "
#endif  /* UART4_CTS_ID */

//   <o> UART4_RTS Pin
//       <0=>Not Used <1=>PA15 <2=>PB14 
#define UART4_RTS_ID 0

#if (UART4_RTS_ID == 0)
#define UART4_RTS 0
#elif (UART4_RTS_ID == 1)
#define UART4_RTS 1
#define UART4_RTS_PORT A
#define UART4_RTS_PIN GPIO_PIN_15
#elif (UART4_RTS_ID == 2)
#define UART4_RTS 1
#define UART4_RTS_PORT B
#define UART4_RTS_PIN GPIO_PIN_14
#else   /* UART4_RTS_ID */
#error "Invalid UART4_RTS Pin Configuration! "
#endif  /* UART4_RTS_ID */

//   <e> Enable UART4 Interrupt
#define UART4_IT_ENABLE 0

#if UART4_IT_ENABLE

//   <o> UART4 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of UART4
#define UART4_IT_PRIORITY        2
//   <o> UART4 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of UART4
#define UART4_IT_SUB             3

//   </e>
#endif /* UART4_IT_ENABLE */

//   <e> Enable UART4 DMA RX
#define UART4_RX_DMA             0

#if UART4_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART4_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART4_RX_DMA_STREAM      1

//     <o UART4_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART4_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART4_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART4_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART4_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART4_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* UART4_RX_DMA */

//   <e> Enable UART4 DMA TX
#define UART4_TX_DMA             0

#if UART4_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART4_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART4_TX_DMA_STREAM      1

//     <o UART4_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART4_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART4_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART4_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define UART4_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* UART4_TX_DMA */

#endif  /* UART4_ENABLE */
// </e>

// <e> UART5 (Universal synchronous asynchronous receiver transmitter)

#define UART5_ENABLE 0 

#if UART5_ENABLE

//   <o> UART5_TX Pin
//       <0=>Not Used <1=>PB6 <2=>PB13 <3=>PC12 
#define UART5_TX_ID 0

#if (UART5_TX_ID == 0)
#define UART5_TX 0
#elif (UART5_TX_ID == 1)
#define UART5_TX 1
#define UART5_TX_PORT B
#define UART5_TX_PIN GPIO_PIN_6
#elif (UART5_TX_ID == 2)
#define UART5_TX 1
#define UART5_TX_PORT B
#define UART5_TX_PIN GPIO_PIN_13
#elif (UART5_TX_ID == 3)
#define UART5_TX 1
#define UART5_TX_PORT C
#define UART5_TX_PIN GPIO_PIN_12
#else   /* UART5_TX_ID */
#error "Invalid UART5_TX Pin Configuration! "
#endif  /* UART5_TX_ID */

//   <o> UART5_RX Pin
//       <0=>Not Used <1=>PB5 <2=>PB12 <3=>PD2 
#define UART5_RX_ID 0

#if (UART5_RX_ID == 0)
#define UART5_RX 0
#elif (UART5_RX_ID == 1)
#define UART5_RX 1
#define UART5_RX_PORT B
#define UART5_RX_PIN GPIO_PIN_5
#elif (UART5_RX_ID == 2)
#define UART5_RX 1
#define UART5_RX_PORT B
#define UART5_RX_PIN GPIO_PIN_12
#elif (UART5_RX_ID == 3)
#define UART5_RX 1
#define UART5_RX_PORT D
#define UART5_RX_PIN GPIO_PIN_2
#else   /* UART5_RX_ID */
#error "Invalid UART5_RX Pin Configuration! "
#endif  /* UART5_RX_ID */

//   <o> UART5_CTS Pin
//       <0=>Not Used <1=>PC9 
#define UART5_CTS_ID 0

#if (UART5_CTS_ID == 0)
#define UART5_CTS 0
#elif (UART5_CTS_ID == 1)
#define UART5_CTS 1
#define UART5_CTS_PORT C
#define UART5_CTS_PIN GPIO_PIN_9
#else   /* UART5_CTS_ID */
#error "Invalid UART5_CTS Pin Configuration! "
#endif  /* UART5_CTS_ID */

//   <o> UART5_RTS Pin
//       <0=>Not Used <1=>PC8 
#define UART5_RTS_ID 0

#if (UART5_RTS_ID == 0)
#define UART5_RTS 0
#elif (UART5_RTS_ID == 1)
#define UART5_RTS 1
#define UART5_RTS_PORT C
#define UART5_RTS_PIN GPIO_PIN_8
#else   /* UART5_RTS_ID */
#error "Invalid UART5_RTS Pin Configuration! "
#endif  /* UART5_RTS_ID */

//   <e> Enable UART5 Interrupt
#define UART5_IT_ENABLE 0

#if UART5_IT_ENABLE

//   <o> UART5 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of UART5
#define UART5_IT_PRIORITY        2
//   <o> UART5 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of UART5
#define UART5_IT_SUB             3

//   </e>
#endif /* UART5_IT_ENABLE */

//   <e> Enable UART5 DMA RX
#define UART5_RX_DMA             0

#if UART5_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART5_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART5_RX_DMA_STREAM      1

//     <o UART5_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART5_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART5_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART5_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART5_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART5_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* UART5_RX_DMA */

//   <e> Enable UART5 DMA TX
#define UART5_TX_DMA             0

#if UART5_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART5_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART5_TX_DMA_STREAM      1

//     <o UART5_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART5_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART5_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART5_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define UART5_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* UART5_TX_DMA */

#endif  /* UART5_ENABLE */
// </e>

// <e> USART6 (Universal asynchronous receiver transmitter)

#define USART6_ENABLE 0 

#if USART6_ENABLE

//   <o> USART6_TX Pin
//       <0=>Not Used <1=>PC6 <2=>PG14 
#define USART6_TX_ID 0

#if (USART6_TX_ID == 0)
#define USART6_TX 0
#elif (USART6_TX_ID == 1)
#define USART6_TX 1
#define USART6_TX_PORT C
#define USART6_TX_PIN GPIO_PIN_6
#elif (USART6_TX_ID == 2)
#define USART6_TX 1
#define USART6_TX_PORT G
#define USART6_TX_PIN GPIO_PIN_14
#else   /* USART6_TX_ID */
#error "Invalid USART6_TX Pin Configuration! "
#endif  /* USART6_TX_ID */

//   <o> USART6_RX Pin
//       <0=>Not Used <1=>PC7 <2=>PG9 
#define USART6_RX_ID 0

#if (USART6_RX_ID == 0)
#define USART6_RX 0
#elif (USART6_RX_ID == 1)
#define USART6_RX 1
#define USART6_RX_PORT C
#define USART6_RX_PIN GPIO_PIN_7
#elif (USART6_RX_ID == 2)
#define USART6_RX 1
#define USART6_RX_PORT G
#define USART6_RX_PIN GPIO_PIN_9
#else   /* USART6_RX_ID */
#error "Invalid USART6_RX Pin Configuration! "
#endif  /* USART6_RX_ID */

//   <o> USART6_CTS Pin
//       <0=>Not Used <1=>PG13 <2=>PG15 
#define USART6_CTS_ID 0

#if (USART6_CTS_ID == 0)
#define USART6_CTS 0
#elif (USART6_CTS_ID == 1)
#define USART6_CTS 1
#define USART6_CTS_PORT G
#define USART6_CTS_PIN GPIO_PIN_13
#elif (USART6_CTS_ID == 2)
#define USART6_CTS 1
#define USART6_CTS_PORT G
#define USART6_CTS_PIN GPIO_PIN_15
#else   /* USART6_CTS_ID */
#error "Invalid USART6_CTS Pin Configuration! "
#endif  /* USART6_CTS_ID */

//   <o> USART6_RTS Pin
//       <0=>Not Used <1=>PG8 <2=>PG12 
#define USART6_RTS_ID 0

#if (USART6_RTS_ID == 0)
#define USART6_RTS 0
#elif (USART6_RTS_ID == 1)
#define USART6_RTS 1
#define USART6_RTS_PORT G
#define USART6_RTS_PIN GPIO_PIN_8
#elif (USART6_RTS_ID == 2)
#define USART6_RTS 1
#define USART6_RTS_PORT G
#define USART6_RTS_PIN GPIO_PIN_12
#else   /* USART6_RTS_ID */
#error "Invalid USART6_RTS Pin Configuration! "
#endif  /* USART6_RTS_ID */

//   <e> Enable USART6 Interrupt
#define USART6_IT_ENABLE 0

#if USART6_IT_ENABLE

//   <o> USART6 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of USART6
#define USART6_IT_PRIORITY        2
//   <o> USART6 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of USART6
#define USART6_IT_SUB             3

//   </e>
#endif /* USART6_IT_ENABLE */

//   <e> Enable USART6 DMA RX
#define USART6_RX_DMA             0

#if USART6_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART6_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART6_RX_DMA_STREAM      1

//     <o USART6_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART6_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART6_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART6_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART6_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART6_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* USART6_RX_DMA */

//   <e> Enable USART6 DMA TX
#define USART6_TX_DMA             0

#if USART6_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART6_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART6_TX_DMA_STREAM      1

//     <o USART6_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART6_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART6_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART6_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define USART6_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* USART6_TX_DMA */

#endif  /* USART6_ENABLE */
// </e>

// <e> UART7 (Universal synchronous asynchronous receiver transmitter)

#define UART7_ENABLE 0 

#if UART7_ENABLE

//   <o> UART7_TX Pin
//       <0=>Not Used <1=>PA15 <2=>PB4 <3=>PE8 <4=>PF7 
#define UART7_TX_ID 0

#if (UART7_TX_ID == 0)
#define UART7_TX 0
#elif (UART7_TX_ID == 1)
#define UART7_TX 1
#define UART7_TX_PORT A
#define UART7_TX_PIN GPIO_PIN_15
#elif (UART7_TX_ID == 2)
#define UART7_TX 1
#define UART7_TX_PORT B
#define UART7_TX_PIN GPIO_PIN_4
#elif (UART7_TX_ID == 3)
#define UART7_TX 1
#define UART7_TX_PORT E
#define UART7_TX_PIN GPIO_PIN_8
#elif (UART7_TX_ID == 4)
#define UART7_TX 1
#define UART7_TX_PORT F
#define UART7_TX_PIN GPIO_PIN_7
#else   /* UART7_TX_ID */
#error "Invalid UART7_TX Pin Configuration! "
#endif  /* UART7_TX_ID */

//   <o> UART7_RX Pin
//       <0=>Not Used <1=>PA8 <2=>PB3 <3=>PE7 <4=>PF6 
#define UART7_RX_ID 0

#if (UART7_RX_ID == 0)
#define UART7_RX 0
#elif (UART7_RX_ID == 1)
#define UART7_RX 1
#define UART7_RX_PORT A
#define UART7_RX_PIN GPIO_PIN_8
#elif (UART7_RX_ID == 2)
#define UART7_RX 1
#define UART7_RX_PORT B
#define UART7_RX_PIN GPIO_PIN_3
#elif (UART7_RX_ID == 3)
#define UART7_RX 1
#define UART7_RX_PORT E
#define UART7_RX_PIN GPIO_PIN_7
#elif (UART7_RX_ID == 4)
#define UART7_RX 1
#define UART7_RX_PORT F
#define UART7_RX_PIN GPIO_PIN_6
#else   /* UART7_RX_ID */
#error "Invalid UART7_RX Pin Configuration! "
#endif  /* UART7_RX_ID */

//   <o> UART7_CTS Pin
//       <0=>Not Used <1=>PE10 <2=>PF9 
#define UART7_CTS_ID 0

#if (UART7_CTS_ID == 0)
#define UART7_CTS 0
#elif (UART7_CTS_ID == 1)
#define UART7_CTS 1
#define UART7_CTS_PORT E
#define UART7_CTS_PIN GPIO_PIN_10
#elif (UART7_CTS_ID == 2)
#define UART7_CTS 1
#define UART7_CTS_PORT F
#define UART7_CTS_PIN GPIO_PIN_9
#else   /* UART7_CTS_ID */
#error "Invalid UART7_CTS Pin Configuration! "
#endif  /* UART7_CTS_ID */

//   <o> UART7_RTS Pin
//       <0=>Not Used <1=>PE9 <2=>PF8 
#define UART7_RTS_ID 0

#if (UART7_RTS_ID == 0)
#define UART7_RTS 0
#elif (UART7_RTS_ID == 1)
#define UART7_RTS 1
#define UART7_RTS_PORT E
#define UART7_RTS_PIN GPIO_PIN_9
#elif (UART7_RTS_ID == 2)
#define UART7_RTS 1
#define UART7_RTS_PORT F
#define UART7_RTS_PIN GPIO_PIN_8
#else   /* UART7_RTS_ID */
#error "Invalid UART7_RTS Pin Configuration! "
#endif  /* UART7_RTS_ID */

//   <e> Enable UART7 Interrupt
#define UART7_IT_ENABLE 0

#if UART7_IT_ENABLE

//   <o> UART7 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of UART7
#define UART7_IT_PRIORITY        2
//   <o> UART7 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of UART7
#define UART7_IT_SUB             3

//   </e>
#endif /* UART7_IT_ENABLE */

//   <e> Enable UART7 DMA RX
#define UART7_RX_DMA             0

#if UART7_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART7_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART7_RX_DMA_STREAM      1

//     <o UART7_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART7_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART7_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART7_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART7_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART7_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* UART7_RX_DMA */

//   <e> Enable UART7 DMA TX
#define UART7_TX_DMA             0

#if UART7_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART7_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART7_TX_DMA_STREAM      1

//     <o UART7_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART7_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART7_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART7_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define UART7_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* UART7_TX_DMA */

#endif  /* UART7_ENABLE */
// </e>

// <e> UART8 (Universal synchronous asynchronous receiver transmitter)

#define UART8_ENABLE 0 

#if UART8_ENABLE

//   <o> UART8_TX Pin
//       <0=>Not Used <1=>PE1 <2=>PJ8 
#define UART8_TX_ID 0

#if (UART8_TX_ID == 0)
#define UART8_TX 0
#elif (UART8_TX_ID == 1)
#define UART8_TX 1
#define UART8_TX_PORT E
#define UART8_TX_PIN GPIO_PIN_1
#elif (UART8_TX_ID == 2)
#define UART8_TX 1
#define UART8_TX_PORT J
#define UART8_TX_PIN GPIO_PIN_8
#else   /* UART8_TX_ID */
#error "Invalid UART8_TX Pin Configuration! "
#endif  /* UART8_TX_ID */

//   <o> UART8_RX Pin
//       <0=>Not Used <1=>PE0 <2=>PJ9 
#define UART8_RX_ID 0

#if (UART8_RX_ID == 0)
#define UART8_RX 0
#elif (UART8_RX_ID == 1)
#define UART8_RX 1
#define UART8_RX_PORT E
#define UART8_RX_PIN GPIO_PIN_0
#elif (UART8_RX_ID == 2)
#define UART8_RX 1
#define UART8_RX_PORT J
#define UART8_RX_PIN GPIO_PIN_9
#else   /* UART8_RX_ID */
#error "Invalid UART8_RX Pin Configuration! "
#endif  /* UART8_RX_ID */

//   <o> UART8_CTS Pin
//       <0=>Not Used <1=>PD14 
#define UART8_CTS_ID 0

#if (UART8_CTS_ID == 0)
#define UART8_CTS 0
#elif (UART8_CTS_ID == 1)
#define UART8_CTS 1
#define UART8_CTS_PORT D
#define UART8_CTS_PIN GPIO_PIN_14
#else   /* UART8_CTS_ID */
#error "Invalid UART8_CTS Pin Configuration! "
#endif  /* UART8_CTS_ID */

//   <o> UART8_RTS Pin
//       <0=>Not Used <1=>PD15 
#define UART8_RTS_ID 0

#if (UART8_RTS_ID == 0)
#define UART8_RTS 0
#elif (UART8_RTS_ID == 1)
#define UART8_RTS 1
#define UART8_RTS_PORT D
#define UART8_RTS_PIN GPIO_PIN_15
#else   /* UART8_RTS_ID */
#error "Invalid UART8_RTS Pin Configuration! "
#endif  /* UART8_RTS_ID */

//   <e> Enable UART8 Interrupt
#define UART8_IT_ENABLE 0

#if UART8_IT_ENABLE

//   <o> UART8 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of UART8
#define UART8_IT_PRIORITY        2
//   <o> UART8 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of UART8
#define UART8_IT_SUB             3

//   </e>
#endif /* UART8_IT_ENABLE */

//   <e> Enable UART8 DMA RX
#define UART8_RX_DMA             0

#if UART8_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART8_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART8_RX_DMA_STREAM      1

//     <o UART8_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART8_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART8_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART8_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART8_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART8_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* UART8_RX_DMA */

//   <e> Enable UART8 DMA TX
#define UART8_TX_DMA             0

#if UART8_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART8_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART8_TX_DMA_STREAM      1

//     <o UART8_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART8_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART8_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART8_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define UART8_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* UART8_TX_DMA */

#endif  /* UART8_ENABLE */
// </e>

// <e> UART9 (Universal synchronous asynchronous receiver transmitter)

#define UART9_ENABLE 0 

#if UART9_ENABLE

//   <o> UART9_TX Pin
//       <0=>Not Used <1=>PD15 <2=>PG1 
#define UART9_TX_ID 0

#if (UART9_TX_ID == 0)
#define UART9_TX 0
#elif (UART9_TX_ID == 1)
#define UART9_TX 1
#define UART9_TX_PORT D
#define UART9_TX_PIN GPIO_PIN_15
#elif (UART9_TX_ID == 2)
#define UART9_TX 1
#define UART9_TX_PORT G
#define UART9_TX_PIN GPIO_PIN_1
#else   /* UART9_TX_ID */
#error "Invalid UART9_TX Pin Configuration! "
#endif  /* UART9_TX_ID */

//   <o> UART9_RX Pin
//       <0=>Not Used <1=>PD14 <2=>PG0 
#define UART9_RX_ID 0

#if (UART9_RX_ID == 0)
#define UART9_RX 0
#elif (UART9_RX_ID == 1)
#define UART9_RX 1
#define UART9_RX_PORT D
#define UART9_RX_PIN GPIO_PIN_14
#elif (UART9_RX_ID == 2)
#define UART9_RX 1
#define UART9_RX_PORT G
#define UART9_RX_PIN GPIO_PIN_0
#else   /* UART9_RX_ID */
#error "Invalid UART9_RX Pin Configuration! "
#endif  /* UART9_RX_ID */

//   <o> UART9_CTS Pin
//       <0=>Not Used <1=>PD0 
#define UART9_CTS_ID 0

#if (UART9_CTS_ID == 0)
#define UART9_CTS 0
#elif (UART9_CTS_ID == 1)
#define UART9_CTS 1
#define UART9_CTS_PORT D
#define UART9_CTS_PIN GPIO_PIN_0
#else   /* UART9_CTS_ID */
#error "Invalid UART9_CTS Pin Configuration! "
#endif  /* UART9_CTS_ID */

//   <o> UART9_RTS Pin
//       <0=>Not Used <1=>PD13 
#define UART9_RTS_ID 0

#if (UART9_RTS_ID == 0)
#define UART9_RTS 0
#elif (UART9_RTS_ID == 1)
#define UART9_RTS 1
#define UART9_RTS_PORT D
#define UART9_RTS_PIN GPIO_PIN_13
#else   /* UART9_RTS_ID */
#error "Invalid UART9_RTS Pin Configuration! "
#endif  /* UART9_RTS_ID */

//   <e> Enable UART9 Interrupt
#define UART9_IT_ENABLE 0

#if UART9_IT_ENABLE

//   <o> UART9 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of UART9
#define UART9_IT_PRIORITY        2
//   <o> UART9 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of UART9
#define UART9_IT_SUB             3

//   </e>
#endif /* UART9_IT_ENABLE */

//   <e> Enable UART9 DMA RX
#define UART9_RX_DMA             0

#if UART9_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART9_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART9_RX_DMA_STREAM      1

//     <o UART9_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART9_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART9_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART9_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART9_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define UART9_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* UART9_RX_DMA */

//   <e> Enable UART9 DMA TX
#define UART9_TX_DMA             0

#if UART9_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define UART9_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define UART9_TX_DMA_STREAM      1

//     <o UART9_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define UART9_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define UART9_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define UART9_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define UART9_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* UART9_TX_DMA */

#endif  /* UART9_ENABLE */
// </e>

// <e> USART10 (Universal asynchronous receiver transmitter)

#define USART10_ENABLE 0 

#if USART10_ENABLE

//   <o> USART10_TX Pin
//       <0=>Not Used <1=>PE3 <2=>PG12 
#define USART10_TX_ID 0

#if (USART10_TX_ID == 0)
#define USART10_TX 0
#elif (USART10_TX_ID == 1)
#define USART10_TX 1
#define USART10_TX_PORT E
#define USART10_TX_PIN GPIO_PIN_3
#elif (USART10_TX_ID == 2)
#define USART10_TX 1
#define USART10_TX_PORT G
#define USART10_TX_PIN GPIO_PIN_12
#else   /* USART10_TX_ID */
#error "Invalid USART10_TX Pin Configuration! "
#endif  /* USART10_TX_ID */

//   <o> USART10_RX Pin
//       <0=>Not Used <1=>PE2 <2=>PG11 
#define USART10_RX_ID 0

#if (USART10_RX_ID == 0)
#define USART10_RX 0
#elif (USART10_RX_ID == 1)
#define USART10_RX 1
#define USART10_RX_PORT E
#define USART10_RX_PIN GPIO_PIN_2
#elif (USART10_RX_ID == 2)
#define USART10_RX 1
#define USART10_RX_PORT G
#define USART10_RX_PIN GPIO_PIN_11
#else   /* USART10_RX_ID */
#error "Invalid USART10_RX Pin Configuration! "
#endif  /* USART10_RX_ID */

//   <o> USART10_CTS Pin
//       <0=>Not Used <1=>PG13 
#define USART10_CTS_ID 0

#if (USART10_CTS_ID == 0)
#define USART10_CTS 0
#elif (USART10_CTS_ID == 1)
#define USART10_CTS 1
#define USART10_CTS_PORT G
#define USART10_CTS_PIN GPIO_PIN_13
#else   /* USART10_CTS_ID */
#error "Invalid USART10_CTS Pin Configuration! "
#endif  /* USART10_CTS_ID */

//   <o> USART10_RTS Pin
//       <0=>Not Used <1=>PG14 
#define USART10_RTS_ID 0

#if (USART10_RTS_ID == 0)
#define USART10_RTS 0
#elif (USART10_RTS_ID == 1)
#define USART10_RTS 1
#define USART10_RTS_PORT G
#define USART10_RTS_PIN GPIO_PIN_14
#else   /* USART10_RTS_ID */
#error "Invalid USART10_RTS Pin Configuration! "
#endif  /* USART10_RTS_ID */

//   <e> Enable USART10 Interrupt
#define USART10_IT_ENABLE 0

#if USART10_IT_ENABLE

//   <o> USART10 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of USART10
#define USART10_IT_PRIORITY        2
//   <o> USART10 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of USART10
#define USART10_IT_SUB             3

//   </e>
#endif /* USART10_IT_ENABLE */

//   <e> Enable USART10 DMA RX
#define USART10_RX_DMA             0

#if USART10_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART10_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART10_RX_DMA_STREAM      1

//     <o USART10_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART10_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART10_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART10_RX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART10_RX_DMA_BUF_SIZE    256

//     <o> The size of Receive FIFO [byte] (Must be power of 2)
//     <i>  Using FIFO and Buf to implement high reliable UART Receive
#define USART10_RX_DMA_FIFO_SIZE   256

//   </e>

#endif  /* USART10_RX_DMA */

//   <e> Enable USART10 DMA TX
#define USART10_TX_DMA             0

#if USART10_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define USART10_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define USART10_TX_DMA_STREAM      1

//     <o USART10_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define USART10_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define USART10_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define USART10_TX_DMA_IT_SUB      2

//     <o> The size of Receive buf [byte]
//     <i>  Write data to Send buf, and sending with thread safety
#define USART10_TX_DMA_BUF_SIZE    256

//   </e>

#endif  /* USART10_TX_DMA */

#endif  /* USART10_ENABLE */
// </e>

// <e> QUADSPI (Quad Serial Peripheral Interface)
#define QUADSPI_ENABLE  1

#if QUADSPI_ENABLE

//   <o> QUADSPI_CLK Pin
//       <0=>PB2<1=>PF10
#define QUADSPI_CLK_ID 0

#if (QUADSPI_CLK_ID == 0)
#define QUADSPI_CLK_PORT B
#define QUADSPI_CLK_PIN GPIO_PIN_2
#elif (QUADSPI_CLK_ID == 1)
#define QUADSPI_CLK_PORT F
#define QUADSPI_CLK_PIN GPIO_PIN_10
#else   /* QUADSPI_CLK_ID */
#error "Invalid QUADSPI_CLK Pin Configuration! "
#endif  /* QUADSPI_CLK_ID */

//  <e> QUADSPI Use Bank1
#define QUADSPI_BANK1_ENABLE    1

#if QUADSPI_BANK1_ENABLE

//   <o> QUADSPI_BK1_IO0 Pin
//       <0=>Not Used <1=>PC9 <2=>PD11 <3=>PE7 <4=>PF8 <5=>PH2 
#define QUADSPI_BK1_IO0_ID 4

#if (QUADSPI_BK1_IO0_ID == 0)
#define QUADSPI_BK1_IO0 0
#elif (QUADSPI_BK1_IO0_ID == 1)
#define QUADSPI_BK1_IO0 1
#define QUADSPI_BK1_IO0_PORT C
#define QUADSPI_BK1_IO0_PIN GPIO_PIN_9
#elif (QUADSPI_BK1_IO0_ID == 2)
#define QUADSPI_BK1_IO0 1
#define QUADSPI_BK1_IO0_PORT D
#define QUADSPI_BK1_IO0_PIN GPIO_PIN_11
#elif (QUADSPI_BK1_IO0_ID == 3)
#define QUADSPI_BK1_IO0 1
#define QUADSPI_BK1_IO0_PORT E
#define QUADSPI_BK1_IO0_PIN GPIO_PIN_7
#elif (QUADSPI_BK1_IO0_ID == 4)
#define QUADSPI_BK1_IO0 1
#define QUADSPI_BK1_IO0_PORT F
#define QUADSPI_BK1_IO0_PIN GPIO_PIN_8
#elif (QUADSPI_BK1_IO0_ID == 5)
#define QUADSPI_BK1_IO0 1
#define QUADSPI_BK1_IO0_PORT H
#define QUADSPI_BK1_IO0_PIN GPIO_PIN_2
#else   /* QUADSPI_BK1_IO0_ID */
#error "Invalid QUADSPI_BK1_IO0 Pin Configuration! "
#endif  /* QUADSPI_BK1_IO0_ID */

//   <o> QUADSPI_BK1_IO1 Pin
//       <0=>Not Used <1=>PC10 <2=>PD12 <3=>PE8 <4=>PF9 <5=>PH3 
#define QUADSPI_BK1_IO1_ID 4

#if (QUADSPI_BK1_IO1_ID == 0)
#define QUADSPI_BK1_IO1 0
#elif (QUADSPI_BK1_IO1_ID == 1)
#define QUADSPI_BK1_IO1 1
#define QUADSPI_BK1_IO1_PORT C
#define QUADSPI_BK1_IO1_PIN GPIO_PIN_10
#elif (QUADSPI_BK1_IO1_ID == 2)
#define QUADSPI_BK1_IO1 1
#define QUADSPI_BK1_IO1_PORT D
#define QUADSPI_BK1_IO1_PIN GPIO_PIN_12
#elif (QUADSPI_BK1_IO1_ID == 3)
#define QUADSPI_BK1_IO1 1
#define QUADSPI_BK1_IO1_PORT E
#define QUADSPI_BK1_IO1_PIN GPIO_PIN_8
#elif (QUADSPI_BK1_IO1_ID == 4)
#define QUADSPI_BK1_IO1 1
#define QUADSPI_BK1_IO1_PORT F
#define QUADSPI_BK1_IO1_PIN GPIO_PIN_9
#elif (QUADSPI_BK1_IO1_ID == 5)
#define QUADSPI_BK1_IO1 1
#define QUADSPI_BK1_IO1_PORT H
#define QUADSPI_BK1_IO1_PIN GPIO_PIN_3
#else   /* QUADSPI_BK1_IO1_ID */
#error "Invalid QUADSPI_BK1_IO1 Pin Configuration! "
#endif  /* QUADSPI_BK1_IO1_ID */

//   <o> QUADSPI_BK1_IO2 Pin
//       <0=>Not Used <1=>PE2 <2=>PE9 <3=>PF7 <4=>PG9 
#define QUADSPI_BK1_IO2_ID 3

#if (QUADSPI_BK1_IO2_ID == 0)
#define QUADSPI_BK1_IO2 0
#elif (QUADSPI_BK1_IO2_ID == 1)
#define QUADSPI_BK1_IO2 1
#define QUADSPI_BK1_IO2_PORT E
#define QUADSPI_BK1_IO2_PIN GPIO_PIN_2
#elif (QUADSPI_BK1_IO2_ID == 2)
#define QUADSPI_BK1_IO2 1
#define QUADSPI_BK1_IO2_PORT E
#define QUADSPI_BK1_IO2_PIN GPIO_PIN_9
#elif (QUADSPI_BK1_IO2_ID == 3)
#define QUADSPI_BK1_IO2 1
#define QUADSPI_BK1_IO2_PORT F
#define QUADSPI_BK1_IO2_PIN GPIO_PIN_7
#elif (QUADSPI_BK1_IO2_ID == 4)
#define QUADSPI_BK1_IO2 1
#define QUADSPI_BK1_IO2_PORT G
#define QUADSPI_BK1_IO2_PIN GPIO_PIN_9
#else   /* QUADSPI_BK1_IO2_ID */
#error "Invalid QUADSPI_BK1_IO2 Pin Configuration! "
#endif  /* QUADSPI_BK1_IO2_ID */

//   <o> QUADSPI_BK1_IO3 Pin
//       <0=>Not Used <1=>PA1 <2=>PD13 <3=>PE10 <4=>PF6 <5=>PG14 
#define QUADSPI_BK1_IO3_ID 4

#if (QUADSPI_BK1_IO3_ID == 0)
#define QUADSPI_BK1_IO3 0
#elif (QUADSPI_BK1_IO3_ID == 1)
#define QUADSPI_BK1_IO3 1
#define QUADSPI_BK1_IO3_PORT A
#define QUADSPI_BK1_IO3_PIN GPIO_PIN_1
#elif (QUADSPI_BK1_IO3_ID == 2)
#define QUADSPI_BK1_IO3 1
#define QUADSPI_BK1_IO3_PORT D
#define QUADSPI_BK1_IO3_PIN GPIO_PIN_13
#elif (QUADSPI_BK1_IO3_ID == 3)
#define QUADSPI_BK1_IO3 1
#define QUADSPI_BK1_IO3_PORT E
#define QUADSPI_BK1_IO3_PIN GPIO_PIN_10
#elif (QUADSPI_BK1_IO3_ID == 4)
#define QUADSPI_BK1_IO3 1
#define QUADSPI_BK1_IO3_PORT F
#define QUADSPI_BK1_IO3_PIN GPIO_PIN_6
#elif (QUADSPI_BK1_IO3_ID == 5)
#define QUADSPI_BK1_IO3 1
#define QUADSPI_BK1_IO3_PORT G
#define QUADSPI_BK1_IO3_PIN GPIO_PIN_14
#else   /* QUADSPI_BK1_IO3_ID */
#error "Invalid QUADSPI_BK1_IO3 Pin Configuration! "
#endif  /* QUADSPI_BK1_IO3_ID */

//   <o> QUADSPI_BK1_NCS Pin
//       <0=>Not Used <1=>PB6 <2=>PB10 <3=>PC11 <4=>PG6 
#define QUADSPI_BK1_NCS_ID 1

#if (QUADSPI_BK1_NCS_ID == 0)
#define QUADSPI_BK1_NCS 0
#elif (QUADSPI_BK1_NCS_ID == 1)
#define QUADSPI_BK1_NCS 1
#define QUADSPI_BK1_NCS_PORT B
#define QUADSPI_BK1_NCS_PIN GPIO_PIN_6
#elif (QUADSPI_BK1_NCS_ID == 2)
#define QUADSPI_BK1_NCS 1
#define QUADSPI_BK1_NCS_PORT B
#define QUADSPI_BK1_NCS_PIN GPIO_PIN_10
#elif (QUADSPI_BK1_NCS_ID == 3)
#define QUADSPI_BK1_NCS 1
#define QUADSPI_BK1_NCS_PORT C
#define QUADSPI_BK1_NCS_PIN GPIO_PIN_11
#elif (QUADSPI_BK1_NCS_ID == 4)
#define QUADSPI_BK1_NCS 1
#define QUADSPI_BK1_NCS_PORT G
#define QUADSPI_BK1_NCS_PIN GPIO_PIN_6
#else   /* QUADSPI_BK1_NCS_ID */
#error "Invalid QUADSPI_BK1_NCS Pin Configuration! "
#endif  /* QUADSPI_BK1_NCS_ID */

#endif  /* QUADSPI_BANK1_ENABLE */
// </e>

//  <e> QUADSPI Use Bank2
#define QUADSPI_BANK2_ENABLE    0

#if QUADSPI_BANK2_ENABLE

//   <o> QUADSPI_BK2_IO0 Pin
//       <0=>Not Used <1=>PC9 <2=>PD11 <3=>PE7 <4=>PF8 <5=>PH2 
#define QUADSPI_BK2_IO0_ID 0

#if (QUADSPI_BK2_IO0_ID == 0)
#define QUADSPI_BK2_IO0 0
#elif (QUADSPI_BK2_IO0_ID == 1)
#define QUADSPI_BK2_IO0 1
#define QUADSPI_BK2_IO0_PORT C
#define QUADSPI_BK2_IO0_PIN GPIO_PIN_9
#elif (QUADSPI_BK2_IO0_ID == 2)
#define QUADSPI_BK2_IO0 1
#define QUADSPI_BK2_IO0_PORT D
#define QUADSPI_BK2_IO0_PIN GPIO_PIN_11
#elif (QUADSPI_BK2_IO0_ID == 3)
#define QUADSPI_BK2_IO0 1
#define QUADSPI_BK2_IO0_PORT E
#define QUADSPI_BK2_IO0_PIN GPIO_PIN_7
#elif (QUADSPI_BK2_IO0_ID == 4)
#define QUADSPI_BK2_IO0 1
#define QUADSPI_BK2_IO0_PORT F
#define QUADSPI_BK2_IO0_PIN GPIO_PIN_8
#elif (QUADSPI_BK2_IO0_ID == 5)
#define QUADSPI_BK2_IO0 1
#define QUADSPI_BK2_IO0_PORT H
#define QUADSPI_BK2_IO0_PIN GPIO_PIN_2
#else   /* QUADSPI_BK2_IO0_ID */
#error "Invalid QUADSPI_BK2_IO0 Pin Configuration! "
#endif  /* QUADSPI_BK2_IO0_ID */

//   <o> QUADSPI_BK2_IO1 Pin
//       <0=>Not Used <1=>PC10 <2=>PD12 <3=>PE8 <4=>PF9 <5=>PH3 
#define QUADSPI_BK2_IO1_ID 0

#if (QUADSPI_BK2_IO1_ID == 0)
#define QUADSPI_BK2_IO1 0
#elif (QUADSPI_BK2_IO1_ID == 1)
#define QUADSPI_BK2_IO1 1
#define QUADSPI_BK2_IO1_PORT C
#define QUADSPI_BK2_IO1_PIN GPIO_PIN_10
#elif (QUADSPI_BK2_IO1_ID == 2)
#define QUADSPI_BK2_IO1 1
#define QUADSPI_BK2_IO1_PORT D
#define QUADSPI_BK2_IO1_PIN GPIO_PIN_12
#elif (QUADSPI_BK2_IO1_ID == 3)
#define QUADSPI_BK2_IO1 1
#define QUADSPI_BK2_IO1_PORT E
#define QUADSPI_BK2_IO1_PIN GPIO_PIN_8
#elif (QUADSPI_BK2_IO1_ID == 4)
#define QUADSPI_BK2_IO1 1
#define QUADSPI_BK2_IO1_PORT F
#define QUADSPI_BK2_IO1_PIN GPIO_PIN_9
#elif (QUADSPI_BK2_IO1_ID == 5)
#define QUADSPI_BK2_IO1 1
#define QUADSPI_BK2_IO1_PORT H
#define QUADSPI_BK2_IO1_PIN GPIO_PIN_3
#else   /* QUADSPI_BK2_IO1_ID */
#error "Invalid QUADSPI_BK2_IO1 Pin Configuration! "
#endif  /* QUADSPI_BK2_IO1_ID */

//   <o> QUADSPI_BK2_IO2 Pin
//       <0=>Not Used <1=>PE2 <2=>PE9 <3=>PF7 <4=>PG9 
#define QUADSPI_BK2_IO2_ID 0

#if (QUADSPI_BK2_IO2_ID == 0)
#define QUADSPI_BK2_IO2 0
#elif (QUADSPI_BK2_IO2_ID == 1)
#define QUADSPI_BK2_IO2 1
#define QUADSPI_BK2_IO2_PORT E
#define QUADSPI_BK2_IO2_PIN GPIO_PIN_2
#elif (QUADSPI_BK2_IO2_ID == 2)
#define QUADSPI_BK2_IO2 1
#define QUADSPI_BK2_IO2_PORT E
#define QUADSPI_BK2_IO2_PIN GPIO_PIN_9
#elif (QUADSPI_BK2_IO2_ID == 3)
#define QUADSPI_BK2_IO2 1
#define QUADSPI_BK2_IO2_PORT F
#define QUADSPI_BK2_IO2_PIN GPIO_PIN_7
#elif (QUADSPI_BK2_IO2_ID == 4)
#define QUADSPI_BK2_IO2 1
#define QUADSPI_BK2_IO2_PORT G
#define QUADSPI_BK2_IO2_PIN GPIO_PIN_9
#else   /* QUADSPI_BK2_IO2_ID */
#error "Invalid QUADSPI_BK2_IO2 Pin Configuration! "
#endif  /* QUADSPI_BK2_IO2_ID */

//   <o> QUADSPI_BK2_IO3 Pin
//       <0=>Not Used <1=>PA1 <2=>PD13 <3=>PE10 <4=>PF6 <5=>PG14 
#define QUADSPI_BK2_IO3_ID 0

#if (QUADSPI_BK2_IO3_ID == 0)
#define QUADSPI_BK2_IO3 0
#elif (QUADSPI_BK2_IO3_ID == 1)
#define QUADSPI_BK2_IO3 1
#define QUADSPI_BK2_IO3_PORT A
#define QUADSPI_BK2_IO3_PIN GPIO_PIN_1
#elif (QUADSPI_BK2_IO3_ID == 2)
#define QUADSPI_BK2_IO3 1
#define QUADSPI_BK2_IO3_PORT D
#define QUADSPI_BK2_IO3_PIN GPIO_PIN_13
#elif (QUADSPI_BK2_IO3_ID == 3)
#define QUADSPI_BK2_IO3 1
#define QUADSPI_BK2_IO3_PORT E
#define QUADSPI_BK2_IO3_PIN GPIO_PIN_10
#elif (QUADSPI_BK2_IO3_ID == 4)
#define QUADSPI_BK2_IO3 1
#define QUADSPI_BK2_IO3_PORT F
#define QUADSPI_BK2_IO3_PIN GPIO_PIN_6
#elif (QUADSPI_BK2_IO3_ID == 5)
#define QUADSPI_BK2_IO3 1
#define QUADSPI_BK2_IO3_PORT G
#define QUADSPI_BK2_IO3_PIN GPIO_PIN_14
#else   /* QUADSPI_BK2_IO3_ID */
#error "Invalid QUADSPI_BK2_IO3 Pin Configuration! "
#endif  /* QUADSPI_BK2_IO3_ID */

//   <o> QUADSPI_BK2_NCS Pin
//       <0=>Not Used <1=>PB6 <2=>PB10 <3=>PC11 <4=>PG6 
#define QUADSPI_BK2_NCS_ID 0

#if (QUADSPI_BK2_NCS_ID == 0)
#define QUADSPI_BK2_NCS 0
#elif (QUADSPI_BK2_NCS_ID == 1)
#define QUADSPI_BK2_NCS 1
#define QUADSPI_BK2_NCS_PORT B
#define QUADSPI_BK2_NCS_PIN GPIO_PIN_6
#elif (QUADSPI_BK2_NCS_ID == 2)
#define QUADSPI_BK2_NCS 1
#define QUADSPI_BK2_NCS_PORT B
#define QUADSPI_BK2_NCS_PIN GPIO_PIN_10
#elif (QUADSPI_BK2_NCS_ID == 3)
#define QUADSPI_BK2_NCS 1
#define QUADSPI_BK2_NCS_PORT C
#define QUADSPI_BK2_NCS_PIN GPIO_PIN_11
#elif (QUADSPI_BK2_NCS_ID == 4)
#define QUADSPI_BK2_NCS 1
#define QUADSPI_BK2_NCS_PORT G
#define QUADSPI_BK2_NCS_PIN GPIO_PIN_6
#else   /* QUADSPI_BK2_NCS_ID */
#error "Invalid QUADSPI_BK2_NCS Pin Configuration! "
#endif  /* QUADSPI_BK2_NCS_ID */

#endif  /* QUADSPI_BANK2_ENABLE */
// </e>

//   <e> Enable QUADSPI Interrupt
#define QUADSPI_IT_ENABLE 0

#if QUADSPI_IT_ENABLE

//   <o> QUADSPI Interrupt Priority <0-15>
//   <i> The Interrupt Priority of QUADSPI
#define QUADSPI_IT_PRIORITY        2
//   <o> QUADSPI Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of QUADSPI
#define QUADSPI_IT_SUB             3

//   </e>
#endif /* QUADSPI_IT_ENABLE */

//   <e> Enable QUADSPI DMA
#define QUADSPI_MDMA 0

#if QUADSPI_MDMA

//     <o> Channel <1-15>
//     <i>  Selects DMA Channel
#define QUADSPI_MDMA_CHANNEL     1

//     <o QUADSPI_MDMA_PRIORITY> Priority
//     <MDMA_PRIORITY_LOW=> Low
//     <MDMA_PRIORITY_MEDIUM=> Medium
//     <MDMA_PRIORITY_HIGH=> High
//     <MDMA_PRIORITY_VERY_HIGH=> Very high
#define QUADSPI_MDMA_PRIORITY    MDMA_PRIORITY_HIGH

//     <o> DMA  Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define QUADSPI_MDMA_IT_PRIORITY 2

//     <o> DMA  Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define QUADSPI_MDMA_IT_SUB      2

//   </e>

#endif /* QUADSPI_MDMA */

#endif  /* QUADSPI_ENABLE */
// </e>

// <e> SPI1 (Serial Peripheral Interface)
#define SPI1_ENABLE  0

#if SPI1_ENABLE

//   <o> SPI1_MISO Pin
//       <0=>Not Used <1=>PA6 <2=>PB4 <3=>PG9 
#define SPI1_MISO_ID 0

#if (SPI1_MISO_ID == 0)
#define SPI1_MISO 0
#elif (SPI1_MISO_ID == 1)
#define SPI1_MISO 1
#define SPI1_MISO_PORT A
#define SPI1_MISO_PIN GPIO_PIN_6
#elif (SPI1_MISO_ID == 2)
#define SPI1_MISO 1
#define SPI1_MISO_PORT B
#define SPI1_MISO_PIN GPIO_PIN_4
#elif (SPI1_MISO_ID == 3)
#define SPI1_MISO 1
#define SPI1_MISO_PORT G
#define SPI1_MISO_PIN GPIO_PIN_9
#else   /* SPI1_MISO_ID */
#error "Invalid SPI1_MISO Pin Configuration! "
#endif  /* SPI1_MISO_ID */

//   <o> SPI1_MOSI Pin
//       <0=>Not Used <1=>PA7 <2=>PB5 <3=>PD7 
#define SPI1_MOSI_ID 0

#if (SPI1_MOSI_ID == 0)
#define SPI1_MOSI 0
#elif (SPI1_MOSI_ID == 1)
#define SPI1_MOSI 1
#define SPI1_MOSI_PORT A
#define SPI1_MOSI_PIN GPIO_PIN_7
#elif (SPI1_MOSI_ID == 2)
#define SPI1_MOSI 1
#define SPI1_MOSI_PORT B
#define SPI1_MOSI_PIN GPIO_PIN_5
#elif (SPI1_MOSI_ID == 3)
#define SPI1_MOSI 1
#define SPI1_MOSI_PORT D
#define SPI1_MOSI_PIN GPIO_PIN_7
#else   /* SPI1_MOSI_ID */
#error "Invalid SPI1_MOSI Pin Configuration! "
#endif  /* SPI1_MOSI_ID */

//   <o> SPI1_NSS Pin
//       <0=>Not Used <1=>PA4 <2=>PA15 <3=>PG10 
#define SPI1_NSS_ID 0

#if (SPI1_NSS_ID == 0)
#define SPI1_NSS 0
#elif (SPI1_NSS_ID == 1)
#define SPI1_NSS 1
#define SPI1_NSS_PORT A
#define SPI1_NSS_PIN GPIO_PIN_4
#elif (SPI1_NSS_ID == 2)
#define SPI1_NSS 1
#define SPI1_NSS_PORT A
#define SPI1_NSS_PIN GPIO_PIN_15
#elif (SPI1_NSS_ID == 3)
#define SPI1_NSS 1
#define SPI1_NSS_PORT G
#define SPI1_NSS_PIN GPIO_PIN_10
#else   /* SPI1_NSS_ID */
#error "Invalid SPI1_NSS Pin Configuration! "
#endif  /* SPI1_NSS_ID */

//   <o> SPI1_SCK Pin
//       <0=>PA5<1=>PB3<2=>PG11
#define SPI1_SCK_ID 0

#if (SPI1_SCK_ID == 0)
#define SPI1_SCK_PORT A
#define SPI1_SCK_PIN GPIO_PIN_5
#elif (SPI1_SCK_ID == 1)
#define SPI1_SCK_PORT B
#define SPI1_SCK_PIN GPIO_PIN_3
#elif (SPI1_SCK_ID == 2)
#define SPI1_SCK_PORT G
#define SPI1_SCK_PIN GPIO_PIN_11
#else   /* SPI1_SCK_ID */
#error "Invalid SPI1_SCK Pin Configuration! "
#endif  /* SPI1_SCK_ID */

//   <e> Enable SPI1 Interrupt
#define SPI1_IT_ENABLE 0

#if SPI1_IT_ENABLE

//   <o> SPI1 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of SPI1
#define SPI1_IT_PRIORITY        2
//   <o> SPI1 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of SPI1
#define SPI1_IT_SUB             3

//   </e>
#endif /* SPI1_IT_ENABLE */

//   <e> Enable SPI1 DMA RX
#define SPI1_RX_DMA             0

#if SPI1_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI1_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI1_RX_DMA_STREAM      1

//     <o SPI1_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI1_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI1_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI1_RX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI1_RX_DMA */

//   <e> Enable SPI1 DMA TX
#define SPI1_TX_DMA             0

#if SPI1_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI1_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI1_TX_DMA_STREAM      1

//     <o SPI1_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI1_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI1_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI1_TX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI1_TX_DMA */

#endif  /* SPI1_ENABLE */
// </e>

// <e> SPI2 (Serial Peripheral Interface)
#define SPI2_ENABLE  0

#if SPI2_ENABLE

//   <o> SPI2_MISO Pin
//       <0=>Not Used <1=>PB14 <2=>PC2 <3=>PI2 
#define SPI2_MISO_ID 0

#if (SPI2_MISO_ID == 0)
#define SPI2_MISO 0
#elif (SPI2_MISO_ID == 1)
#define SPI2_MISO 1
#define SPI2_MISO_PORT B
#define SPI2_MISO_PIN GPIO_PIN_14
#elif (SPI2_MISO_ID == 2)
#define SPI2_MISO 1
#define SPI2_MISO_PORT C
#define SPI2_MISO_PIN GPIO_PIN_2
#elif (SPI2_MISO_ID == 3)
#define SPI2_MISO 1
#define SPI2_MISO_PORT I
#define SPI2_MISO_PIN GPIO_PIN_2
#else   /* SPI2_MISO_ID */
#error "Invalid SPI2_MISO Pin Configuration! "
#endif  /* SPI2_MISO_ID */

//   <o> SPI2_MOSI Pin
//       <0=>Not Used <1=>PB15 <2=>PC1 <3=>PC3 <4=>PI3 
#define SPI2_MOSI_ID 0

#if (SPI2_MOSI_ID == 0)
#define SPI2_MOSI 0
#elif (SPI2_MOSI_ID == 1)
#define SPI2_MOSI 1
#define SPI2_MOSI_PORT B
#define SPI2_MOSI_PIN GPIO_PIN_15
#elif (SPI2_MOSI_ID == 2)
#define SPI2_MOSI 1
#define SPI2_MOSI_PORT C
#define SPI2_MOSI_PIN GPIO_PIN_1
#elif (SPI2_MOSI_ID == 3)
#define SPI2_MOSI 1
#define SPI2_MOSI_PORT C
#define SPI2_MOSI_PIN GPIO_PIN_3
#elif (SPI2_MOSI_ID == 4)
#define SPI2_MOSI 1
#define SPI2_MOSI_PORT I
#define SPI2_MOSI_PIN GPIO_PIN_3
#else   /* SPI2_MOSI_ID */
#error "Invalid SPI2_MOSI Pin Configuration! "
#endif  /* SPI2_MOSI_ID */

//   <o> SPI2_NSS Pin
//       <0=>Not Used <1=>PA11 <2=>PB4 <3=>PB9 <4=>PB12 <5=>PI0 
#define SPI2_NSS_ID 0

#if (SPI2_NSS_ID == 0)
#define SPI2_NSS 0
#elif (SPI2_NSS_ID == 1)
#define SPI2_NSS 1
#define SPI2_NSS_PORT A
#define SPI2_NSS_PIN GPIO_PIN_11
#elif (SPI2_NSS_ID == 2)
#define SPI2_NSS 1
#define SPI2_NSS_PORT B
#define SPI2_NSS_PIN GPIO_PIN_4
#elif (SPI2_NSS_ID == 3)
#define SPI2_NSS 1
#define SPI2_NSS_PORT B
#define SPI2_NSS_PIN GPIO_PIN_9
#elif (SPI2_NSS_ID == 4)
#define SPI2_NSS 1
#define SPI2_NSS_PORT B
#define SPI2_NSS_PIN GPIO_PIN_12
#elif (SPI2_NSS_ID == 5)
#define SPI2_NSS 1
#define SPI2_NSS_PORT I
#define SPI2_NSS_PIN GPIO_PIN_0
#else   /* SPI2_NSS_ID */
#error "Invalid SPI2_NSS Pin Configuration! "
#endif  /* SPI2_NSS_ID */

//   <o> SPI2_SCK Pin
//       <0=>PA9<1=>PA12<2=>PB10<3=>PB13<4=>PD3<5=>PI1
#define SPI2_SCK_ID 0

#if (SPI2_SCK_ID == 0)
#define SPI2_SCK_PORT A
#define SPI2_SCK_PIN GPIO_PIN_9
#elif (SPI2_SCK_ID == 1)
#define SPI2_SCK_PORT A
#define SPI2_SCK_PIN GPIO_PIN_12
#elif (SPI2_SCK_ID == 2)
#define SPI2_SCK_PORT B
#define SPI2_SCK_PIN GPIO_PIN_10
#elif (SPI2_SCK_ID == 3)
#define SPI2_SCK_PORT B
#define SPI2_SCK_PIN GPIO_PIN_13
#elif (SPI2_SCK_ID == 4)
#define SPI2_SCK_PORT D
#define SPI2_SCK_PIN GPIO_PIN_3
#elif (SPI2_SCK_ID == 5)
#define SPI2_SCK_PORT I
#define SPI2_SCK_PIN GPIO_PIN_1
#else   /* SPI2_SCK_ID */
#error "Invalid SPI2_SCK Pin Configuration! "
#endif  /* SPI2_SCK_ID */

//   <e> Enable SPI2 Interrupt
#define SPI2_IT_ENABLE 0

#if SPI2_IT_ENABLE

//   <o> SPI2 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of SPI2
#define SPI2_IT_PRIORITY        2
//   <o> SPI2 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of SPI2
#define SPI2_IT_SUB             3

//   </e>
#endif /* SPI2_IT_ENABLE */

//   <e> Enable SPI2 DMA RX
#define SPI2_RX_DMA             0

#if SPI2_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI2_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI2_RX_DMA_STREAM      1

//     <o SPI2_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI2_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI2_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI2_RX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI2_RX_DMA */

//   <e> Enable SPI2 DMA TX
#define SPI2_TX_DMA             0

#if SPI2_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI2_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI2_TX_DMA_STREAM      1

//     <o SPI2_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI2_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI2_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI2_TX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI2_TX_DMA */

#endif  /* SPI2_ENABLE */
// </e>

// <e> SPI3 (Serial Peripheral Interface)
#define SPI3_ENABLE  0

#if SPI3_ENABLE

//   <o> SPI3_MISO Pin
//       <0=>Not Used <1=>PB4 <2=>PC11 
#define SPI3_MISO_ID 0

#if (SPI3_MISO_ID == 0)
#define SPI3_MISO 0
#elif (SPI3_MISO_ID == 1)
#define SPI3_MISO 1
#define SPI3_MISO_PORT B
#define SPI3_MISO_PIN GPIO_PIN_4
#elif (SPI3_MISO_ID == 2)
#define SPI3_MISO 1
#define SPI3_MISO_PORT C
#define SPI3_MISO_PIN GPIO_PIN_11
#else   /* SPI3_MISO_ID */
#error "Invalid SPI3_MISO Pin Configuration! "
#endif  /* SPI3_MISO_ID */

//   <o> SPI3_MOSI Pin
//       <0=>Not Used <1=>PB2 <2=>PB5 <3=>PC12 <4=>PD6 
#define SPI3_MOSI_ID 0

#if (SPI3_MOSI_ID == 0)
#define SPI3_MOSI 0
#elif (SPI3_MOSI_ID == 1)
#define SPI3_MOSI 1
#define SPI3_MOSI_PORT B
#define SPI3_MOSI_PIN GPIO_PIN_2
#elif (SPI3_MOSI_ID == 2)
#define SPI3_MOSI 1
#define SPI3_MOSI_PORT B
#define SPI3_MOSI_PIN GPIO_PIN_5
#elif (SPI3_MOSI_ID == 3)
#define SPI3_MOSI 1
#define SPI3_MOSI_PORT C
#define SPI3_MOSI_PIN GPIO_PIN_12
#elif (SPI3_MOSI_ID == 4)
#define SPI3_MOSI 1
#define SPI3_MOSI_PORT D
#define SPI3_MOSI_PIN GPIO_PIN_6
#else   /* SPI3_MOSI_ID */
#error "Invalid SPI3_MOSI Pin Configuration! "
#endif  /* SPI3_MOSI_ID */

//   <o> SPI3_NSS Pin
//       <0=>Not Used <1=>PA4 <2=>PA15 
#define SPI3_NSS_ID 0

#if (SPI3_NSS_ID == 0)
#define SPI3_NSS 0
#elif (SPI3_NSS_ID == 1)
#define SPI3_NSS 1
#define SPI3_NSS_PORT A
#define SPI3_NSS_PIN GPIO_PIN_4
#elif (SPI3_NSS_ID == 2)
#define SPI3_NSS 1
#define SPI3_NSS_PORT A
#define SPI3_NSS_PIN GPIO_PIN_15
#else   /* SPI3_NSS_ID */
#error "Invalid SPI3_NSS Pin Configuration! "
#endif  /* SPI3_NSS_ID */

//   <o> SPI3_SCK Pin
//       <0=>PB3<1=>PC10
#define SPI3_SCK_ID 0

#if (SPI3_SCK_ID == 0)
#define SPI3_SCK_PORT B
#define SPI3_SCK_PIN GPIO_PIN_3
#elif (SPI3_SCK_ID == 1)
#define SPI3_SCK_PORT C
#define SPI3_SCK_PIN GPIO_PIN_10
#else   /* SPI3_SCK_ID */
#error "Invalid SPI3_SCK Pin Configuration! "
#endif  /* SPI3_SCK_ID */

//   <e> Enable SPI3 Interrupt
#define SPI3_IT_ENABLE 0

#if SPI3_IT_ENABLE

//   <o> SPI3 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of SPI3
#define SPI3_IT_PRIORITY        2
//   <o> SPI3 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of SPI3
#define SPI3_IT_SUB             3

//   </e>
#endif /* SPI3_IT_ENABLE */

//   <e> Enable SPI3 DMA RX
#define SPI3_RX_DMA             0

#if SPI3_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI3_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI3_RX_DMA_STREAM      1

//     <o SPI3_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI3_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI3_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI3_RX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI3_RX_DMA */

//   <e> Enable SPI3 DMA TX
#define SPI3_TX_DMA             0

#if SPI3_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI3_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI3_TX_DMA_STREAM      1

//     <o SPI3_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI3_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI3_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI3_TX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI3_TX_DMA */

#endif  /* SPI3_ENABLE */
// </e>

// <e> SPI4 (Serial Peripheral Interface)
#define SPI4_ENABLE  0

#if SPI4_ENABLE

//   <o> SPI4_MISO Pin
//       <0=>Not Used <1=>PE5 <2=>PE13 
#define SPI4_MISO_ID 0

#if (SPI4_MISO_ID == 0)
#define SPI4_MISO 0
#elif (SPI4_MISO_ID == 1)
#define SPI4_MISO 1
#define SPI4_MISO_PORT E
#define SPI4_MISO_PIN GPIO_PIN_5
#elif (SPI4_MISO_ID == 2)
#define SPI4_MISO 1
#define SPI4_MISO_PORT E
#define SPI4_MISO_PIN GPIO_PIN_13
#else   /* SPI4_MISO_ID */
#error "Invalid SPI4_MISO Pin Configuration! "
#endif  /* SPI4_MISO_ID */

//   <o> SPI4_MOSI Pin
//       <0=>Not Used <1=>PE6 <2=>PE14 
#define SPI4_MOSI_ID 0

#if (SPI4_MOSI_ID == 0)
#define SPI4_MOSI 0
#elif (SPI4_MOSI_ID == 1)
#define SPI4_MOSI 1
#define SPI4_MOSI_PORT E
#define SPI4_MOSI_PIN GPIO_PIN_6
#elif (SPI4_MOSI_ID == 2)
#define SPI4_MOSI 1
#define SPI4_MOSI_PORT E
#define SPI4_MOSI_PIN GPIO_PIN_14
#else   /* SPI4_MOSI_ID */
#error "Invalid SPI4_MOSI Pin Configuration! "
#endif  /* SPI4_MOSI_ID */

//   <o> SPI4_NSS Pin
//       <0=>Not Used <1=>PE4 <2=>PE11 
#define SPI4_NSS_ID 0

#if (SPI4_NSS_ID == 0)
#define SPI4_NSS 0
#elif (SPI4_NSS_ID == 1)
#define SPI4_NSS 1
#define SPI4_NSS_PORT E
#define SPI4_NSS_PIN GPIO_PIN_4
#elif (SPI4_NSS_ID == 2)
#define SPI4_NSS 1
#define SPI4_NSS_PORT E
#define SPI4_NSS_PIN GPIO_PIN_11
#else   /* SPI4_NSS_ID */
#error "Invalid SPI4_NSS Pin Configuration! "
#endif  /* SPI4_NSS_ID */

//   <o> SPI4_SCK Pin
//       <0=>PE2<1=>PE12
#define SPI4_SCK_ID 0

#if (SPI4_SCK_ID == 0)
#define SPI4_SCK_PORT E
#define SPI4_SCK_PIN GPIO_PIN_2
#elif (SPI4_SCK_ID == 1)
#define SPI4_SCK_PORT E
#define SPI4_SCK_PIN GPIO_PIN_12
#else   /* SPI4_SCK_ID */
#error "Invalid SPI4_SCK Pin Configuration! "
#endif  /* SPI4_SCK_ID */

//   <e> Enable SPI4 Interrupt
#define SPI4_IT_ENABLE 0

#if SPI4_IT_ENABLE

//   <o> SPI4 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of SPI4
#define SPI4_IT_PRIORITY        2
//   <o> SPI4 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of SPI4
#define SPI4_IT_SUB             3

//   </e>
#endif /* SPI4_IT_ENABLE */

//   <e> Enable SPI4 DMA RX
#define SPI4_RX_DMA             0

#if SPI4_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI4_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI4_RX_DMA_STREAM      1

//     <o SPI4_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI4_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI4_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI4_RX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI4_RX_DMA */

//   <e> Enable SPI4 DMA TX
#define SPI4_TX_DMA             0

#if SPI4_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI4_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI4_TX_DMA_STREAM      1

//     <o SPI4_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI4_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI4_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI4_TX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI4_TX_DMA */

#endif  /* SPI4_ENABLE */
// </e>

// <e> SPI5 (Serial Peripheral Interface)
#define SPI5_ENABLE  0

#if SPI5_ENABLE

//   <o> SPI5_MISO Pin
//       <0=>Not Used <1=>PF8 <2=>PH7 <3=>PJ11 
#define SPI5_MISO_ID 0

#if (SPI5_MISO_ID == 0)
#define SPI5_MISO 0
#elif (SPI5_MISO_ID == 1)
#define SPI5_MISO 1
#define SPI5_MISO_PORT F
#define SPI5_MISO_PIN GPIO_PIN_8
#elif (SPI5_MISO_ID == 2)
#define SPI5_MISO 1
#define SPI5_MISO_PORT H
#define SPI5_MISO_PIN GPIO_PIN_7
#elif (SPI5_MISO_ID == 3)
#define SPI5_MISO 1
#define SPI5_MISO_PORT J
#define SPI5_MISO_PIN GPIO_PIN_11
#else   /* SPI5_MISO_ID */
#error "Invalid SPI5_MISO Pin Configuration! "
#endif  /* SPI5_MISO_ID */

//   <o> SPI5_MOSI Pin
//       <0=>Not Used <1=>PF9 <2=>PF11 <3=>PJ10 
#define SPI5_MOSI_ID 0

#if (SPI5_MOSI_ID == 0)
#define SPI5_MOSI 0
#elif (SPI5_MOSI_ID == 1)
#define SPI5_MOSI 1
#define SPI5_MOSI_PORT F
#define SPI5_MOSI_PIN GPIO_PIN_9
#elif (SPI5_MOSI_ID == 2)
#define SPI5_MOSI 1
#define SPI5_MOSI_PORT F
#define SPI5_MOSI_PIN GPIO_PIN_11
#elif (SPI5_MOSI_ID == 3)
#define SPI5_MOSI 1
#define SPI5_MOSI_PORT J
#define SPI5_MOSI_PIN GPIO_PIN_10
#else   /* SPI5_MOSI_ID */
#error "Invalid SPI5_MOSI Pin Configuration! "
#endif  /* SPI5_MOSI_ID */

//   <o> SPI5_NSS Pin
//       <0=>Not Used <1=>PF6 <2=>PH5 <3=>PK1 
#define SPI5_NSS_ID 0

#if (SPI5_NSS_ID == 0)
#define SPI5_NSS 0
#elif (SPI5_NSS_ID == 1)
#define SPI5_NSS 1
#define SPI5_NSS_PORT F
#define SPI5_NSS_PIN GPIO_PIN_6
#elif (SPI5_NSS_ID == 2)
#define SPI5_NSS 1
#define SPI5_NSS_PORT H
#define SPI5_NSS_PIN GPIO_PIN_5
#elif (SPI5_NSS_ID == 3)
#define SPI5_NSS 1
#define SPI5_NSS_PORT K
#define SPI5_NSS_PIN GPIO_PIN_1
#else   /* SPI5_NSS_ID */
#error "Invalid SPI5_NSS Pin Configuration! "
#endif  /* SPI5_NSS_ID */

//   <o> SPI5_SCK Pin
//       <0=>PF7<1=>PH6<2=>PK0
#define SPI5_SCK_ID 0

#if (SPI5_SCK_ID == 0)
#define SPI5_SCK_PORT F
#define SPI5_SCK_PIN GPIO_PIN_7
#elif (SPI5_SCK_ID == 1)
#define SPI5_SCK_PORT H
#define SPI5_SCK_PIN GPIO_PIN_6
#elif (SPI5_SCK_ID == 2)
#define SPI5_SCK_PORT K
#define SPI5_SCK_PIN GPIO_PIN_0
#else   /* SPI5_SCK_ID */
#error "Invalid SPI5_SCK Pin Configuration! "
#endif  /* SPI5_SCK_ID */

//   <e> Enable SPI5 Interrupt
#define SPI5_IT_ENABLE 0

#if SPI5_IT_ENABLE

//   <o> SPI5 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of SPI5
#define SPI5_IT_PRIORITY        2
//   <o> SPI5 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of SPI5
#define SPI5_IT_SUB             3

//   </e>
#endif /* SPI5_IT_ENABLE */

//   <e> Enable SPI5 DMA RX
#define SPI5_RX_DMA             0

#if SPI5_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI5_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI5_RX_DMA_STREAM      1

//     <o SPI5_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI5_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI5_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI5_RX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI5_RX_DMA */

//   <e> Enable SPI5 DMA TX
#define SPI5_TX_DMA             0

#if SPI5_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define SPI5_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define SPI5_TX_DMA_STREAM      1

//     <o SPI5_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI5_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI5_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI5_TX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI5_TX_DMA */

#endif  /* SPI5_ENABLE */
// </e>

// <e> SPI6 (Serial Peripheral Interface)
#define SPI6_ENABLE  0

#if SPI6_ENABLE

//   <o> SPI6_MISO Pin
//       <0=>Not Used <1=>PA6 <2=>PB4 <3=>PG12 
#define SPI6_MISO_ID 0

#if (SPI6_MISO_ID == 0)
#define SPI6_MISO 0
#elif (SPI6_MISO_ID == 1)
#define SPI6_MISO 1
#define SPI6_MISO_PORT A
#define SPI6_MISO_PIN GPIO_PIN_6
#elif (SPI6_MISO_ID == 2)
#define SPI6_MISO 1
#define SPI6_MISO_PORT B
#define SPI6_MISO_PIN GPIO_PIN_4
#elif (SPI6_MISO_ID == 3)
#define SPI6_MISO 1
#define SPI6_MISO_PORT G
#define SPI6_MISO_PIN GPIO_PIN_12
#else   /* SPI6_MISO_ID */
#error "Invalid SPI6_MISO Pin Configuration! "
#endif  /* SPI6_MISO_ID */

//   <o> SPI6_MOSI Pin
//       <0=>Not Used <1=>PA7 <2=>PB5 <3=>PG14 
#define SPI6_MOSI_ID 0

#if (SPI6_MOSI_ID == 0)
#define SPI6_MOSI 0
#elif (SPI6_MOSI_ID == 1)
#define SPI6_MOSI 1
#define SPI6_MOSI_PORT A
#define SPI6_MOSI_PIN GPIO_PIN_7
#elif (SPI6_MOSI_ID == 2)
#define SPI6_MOSI 1
#define SPI6_MOSI_PORT B
#define SPI6_MOSI_PIN GPIO_PIN_5
#elif (SPI6_MOSI_ID == 3)
#define SPI6_MOSI 1
#define SPI6_MOSI_PORT G
#define SPI6_MOSI_PIN GPIO_PIN_14
#else   /* SPI6_MOSI_ID */
#error "Invalid SPI6_MOSI Pin Configuration! "
#endif  /* SPI6_MOSI_ID */

//   <o> SPI6_NSS Pin
//       <0=>Not Used <1=>PA4 <2=>PA15 <3=>PG8 <4=>PA0 
#define SPI6_NSS_ID 0

#if (SPI6_NSS_ID == 0)
#define SPI6_NSS 0
#elif (SPI6_NSS_ID == 1)
#define SPI6_NSS 1
#define SPI6_NSS_PORT A
#define SPI6_NSS_PIN GPIO_PIN_4
#elif (SPI6_NSS_ID == 2)
#define SPI6_NSS 1
#define SPI6_NSS_PORT A
#define SPI6_NSS_PIN GPIO_PIN_15
#elif (SPI6_NSS_ID == 3)
#define SPI6_NSS 1
#define SPI6_NSS_PORT G
#define SPI6_NSS_PIN GPIO_PIN_8
#elif (SPI6_NSS_ID == 4)
#define SPI6_NSS 1
#define SPI6_NSS_PORT A
#define SPI6_NSS_PIN GPIO_PIN_0
#else   /* SPI6_NSS_ID */
#error "Invalid SPI6_NSS Pin Configuration! "
#endif  /* SPI6_NSS_ID */

//   <o> SPI6_SCK Pin
//       <0=>PA5<1=>PB3<2=>PG13<3=>PC12
#define SPI6_SCK_ID 0

#if (SPI6_SCK_ID == 0)
#define SPI6_SCK_PORT A
#define SPI6_SCK_PIN GPIO_PIN_5
#elif (SPI6_SCK_ID == 1)
#define SPI6_SCK_PORT B
#define SPI6_SCK_PIN GPIO_PIN_3
#elif (SPI6_SCK_ID == 2)
#define SPI6_SCK_PORT G
#define SPI6_SCK_PIN GPIO_PIN_13
#elif (SPI6_SCK_ID == 3)
#define SPI6_SCK_PORT C
#define SPI6_SCK_PIN GPIO_PIN_12
#else   /* SPI6_SCK_ID */
#error "Invalid SPI6_SCK Pin Configuration! "
#endif  /* SPI6_SCK_ID */

//   <e> Enable SPI6 Interrupt
#define SPI6_IT_ENABLE 0

#if SPI6_IT_ENABLE

//   <o> SPI6 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of SPI6
#define SPI6_IT_PRIORITY        2
//   <o> SPI6 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of SPI6
#define SPI6_IT_SUB             3

//   </e>
#endif /* SPI6_IT_ENABLE */

//   <e> Enable SPI6 DMA RX
#define SPI6_RX_DMA             0

#if SPI6_RX_DMA

//     <o> BDMA Channel <0-7>
//     <i>  Selects BDMA Number
#define SPI6_RX_BDMA_CHANNEL     1

//     <o SPI6_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI6_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI6_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI6_RX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI6_RX_DMA */

//   <e> Enable SPI6 DMA TX
#define SPI6_TX_DMA             0

#if SPI6_TX_DMA

//     <o> BDMA Channel <0-7>
//     <i>  Selects BDMA Number
#define SPI6_TX_BDMA_CHANNEL     1

//     <o SPI6_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define SPI6_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define SPI6_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define SPI6_TX_DMA_IT_SUB      2

//   </e>

#endif  /* SPI6_TX_DMA */

#endif  /* SPI6_ENABLE */
// </e>

// <e> I2C1 (Inter-integrated Circuit Interface)
#define I2C1_ENABLE  0

#if I2C1_ENABLE

//   <o> I2C1_SCL Pin
//       <0=>PB6<1=>PB8
#define I2C1_SCL_ID 0

#if (I2C1_SCL_ID == 0)
#define I2C1_SCL_PORT B
#define I2C1_SCL_PIN GPIO_PIN_6
#elif (I2C1_SCL_ID == 1)
#define I2C1_SCL_PORT B
#define I2C1_SCL_PIN GPIO_PIN_8
#else   /* I2C1_SCL_ID */
#error "Invalid I2C1_SCL Pin Configuration! "
#endif  /* I2C1_SCL_ID */

//   <o> I2C1_SDA Pin
//       <0=>PB7<1=>PB9
#define I2C1_SDA_ID 0

#if (I2C1_SDA_ID == 0)
#define I2C1_SDA_PORT B
#define I2C1_SDA_PIN GPIO_PIN_7
#elif (I2C1_SDA_ID == 1)
#define I2C1_SDA_PORT B
#define I2C1_SDA_PIN GPIO_PIN_9
#else   /* I2C1_SDA_ID */
#error "Invalid I2C1_SDA Pin Configuration! "
#endif  /* I2C1_SDA_ID */

//   <e> Enable I2C1 Interrupt
#define I2C1_IT_ENABLE 0

#if I2C1_IT_ENABLE

//   <o> I2C1 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of I2C1
#define I2C1_IT_PRIORITY        2
//   <o> I2C1 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of I2C1
#define I2C1_IT_SUB             3

//   </e>
#endif /* I2C1_IT_ENABLE */

//   <e> Enable I2C1 DMA RX
#define I2C1_RX_DMA             0

#if I2C1_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C1_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C1_RX_DMA_STREAM      1

//     <o I2C1_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C1_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C1_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C1_RX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C1_RX_DMA */

//   <e> Enable I2C1 DMA TX
#define I2C1_TX_DMA             0

#if I2C1_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C1_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C1_TX_DMA_STREAM      1

//     <o I2C1_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C1_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C1_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C1_TX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C1_TX_DMA */

#endif  /* I2C1_ENABLE */
// </e>

// <e> I2C2 (Inter-integrated Circuit Interface)
#define I2C2_ENABLE  1

#if I2C2_ENABLE

//   <o> I2C2_SCL Pin
//       <0=>PB10<1=>PF1<2=>PH4
#define I2C2_SCL_ID 2

#if (I2C2_SCL_ID == 0)
#define I2C2_SCL_PORT B
#define I2C2_SCL_PIN GPIO_PIN_10
#elif (I2C2_SCL_ID == 1)
#define I2C2_SCL_PORT F
#define I2C2_SCL_PIN GPIO_PIN_1
#elif (I2C2_SCL_ID == 2)
#define I2C2_SCL_PORT H
#define I2C2_SCL_PIN GPIO_PIN_4
#else   /* I2C2_SCL_ID */
#error "Invalid I2C2_SCL Pin Configuration! "
#endif  /* I2C2_SCL_ID */

//   <o> I2C2_SDA Pin
//       <0=>PB11<1=>PF0<2=>PH5
#define I2C2_SDA_ID 2

#if (I2C2_SDA_ID == 0)
#define I2C2_SDA_PORT B
#define I2C2_SDA_PIN GPIO_PIN_11
#elif (I2C2_SDA_ID == 1)
#define I2C2_SDA_PORT F
#define I2C2_SDA_PIN GPIO_PIN_0
#elif (I2C2_SDA_ID == 2)
#define I2C2_SDA_PORT H
#define I2C2_SDA_PIN GPIO_PIN_5
#else   /* I2C2_SDA_ID */
#error "Invalid I2C2_SDA Pin Configuration! "
#endif  /* I2C2_SDA_ID */

//   <e> Enable I2C2 Interrupt
#define I2C2_IT_ENABLE 0

#if I2C2_IT_ENABLE

//   <o> I2C2 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of I2C2
#define I2C2_IT_PRIORITY        2
//   <o> I2C2 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of I2C2
#define I2C2_IT_SUB             3

//   </e>
#endif /* I2C2_IT_ENABLE */

//   <e> Enable I2C2 DMA RX
#define I2C2_RX_DMA             0

#if I2C2_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C2_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C2_RX_DMA_STREAM      1

//     <o I2C2_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C2_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C2_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C2_RX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C2_RX_DMA */

//   <e> Enable I2C2 DMA TX
#define I2C2_TX_DMA             0

#if I2C2_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C2_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C2_TX_DMA_STREAM      1

//     <o I2C2_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C2_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C2_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C2_TX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C2_TX_DMA */

#endif  /* I2C2_ENABLE */
// </e>

// <e> I2C3 (Inter-integrated Circuit Interface)
#define I2C3_ENABLE  0

#if I2C3_ENABLE

//   <o> I2C3_SCL Pin
//       <0=>PA8<1=>PH7
#define I2C3_SCL_ID 0

#if (I2C3_SCL_ID == 0)
#define I2C3_SCL_PORT A
#define I2C3_SCL_PIN GPIO_PIN_8
#elif (I2C3_SCL_ID == 1)
#define I2C3_SCL_PORT H
#define I2C3_SCL_PIN GPIO_PIN_7
#else   /* I2C3_SCL_ID */
#error "Invalid I2C3_SCL Pin Configuration! "
#endif  /* I2C3_SCL_ID */

//   <o> I2C3_SDA Pin
//       <0=>PC9<1=>PH8
#define I2C3_SDA_ID 0

#if (I2C3_SDA_ID == 0)
#define I2C3_SDA_PORT C
#define I2C3_SDA_PIN GPIO_PIN_9
#elif (I2C3_SDA_ID == 1)
#define I2C3_SDA_PORT H
#define I2C3_SDA_PIN GPIO_PIN_8
#else   /* I2C3_SDA_ID */
#error "Invalid I2C3_SDA Pin Configuration! "
#endif  /* I2C3_SDA_ID */

//   <e> Enable I2C3 Interrupt
#define I2C3_IT_ENABLE 0

#if I2C3_IT_ENABLE

//   <o> I2C3 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of I2C3
#define I2C3_IT_PRIORITY        2
//   <o> I2C3 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of I2C3
#define I2C3_IT_SUB             3

//   </e>
#endif /* I2C3_IT_ENABLE */

//   <e> Enable I2C3 DMA RX
#define I2C3_RX_DMA             0

#if I2C3_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C3_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C3_RX_DMA_STREAM      1

//     <o I2C3_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C3_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C3_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C3_RX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C3_RX_DMA */

//   <e> Enable I2C3 DMA TX
#define I2C3_TX_DMA             0

#if I2C3_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C3_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C3_TX_DMA_STREAM      1

//     <o I2C3_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C3_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C3_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C3_TX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C3_TX_DMA */

#endif  /* I2C3_ENABLE */
// </e>

// <e> I2C4 (Inter-integrated Circuit Interface)
#define I2C4_ENABLE  0

#if I2C4_ENABLE

//   <o> I2C4_SCL Pin
//       <0=>PB6<1=>PB8<2=>PD12<3=>PF14<4=>PH11
#define I2C4_SCL_ID 0

#if (I2C4_SCL_ID == 0)
#define I2C4_SCL_PORT B
#define I2C4_SCL_PIN GPIO_PIN_6
#elif (I2C4_SCL_ID == 1)
#define I2C4_SCL_PORT B
#define I2C4_SCL_PIN GPIO_PIN_8
#elif (I2C4_SCL_ID == 2)
#define I2C4_SCL_PORT D
#define I2C4_SCL_PIN GPIO_PIN_12
#elif (I2C4_SCL_ID == 3)
#define I2C4_SCL_PORT F
#define I2C4_SCL_PIN GPIO_PIN_14
#elif (I2C4_SCL_ID == 4)
#define I2C4_SCL_PORT H
#define I2C4_SCL_PIN GPIO_PIN_11
#else   /* I2C4_SCL_ID */
#error "Invalid I2C4_SCL Pin Configuration! "
#endif  /* I2C4_SCL_ID */

//   <o> I2C4_SDA Pin
//       <0=>PB7<1=>PB9<2=>PD13<3=>PF15<4=>PH12
#define I2C4_SDA_ID 0

#if (I2C4_SDA_ID == 0)
#define I2C4_SDA_PORT B
#define I2C4_SDA_PIN GPIO_PIN_7
#elif (I2C4_SDA_ID == 1)
#define I2C4_SDA_PORT B
#define I2C4_SDA_PIN GPIO_PIN_9
#elif (I2C4_SDA_ID == 2)
#define I2C4_SDA_PORT D
#define I2C4_SDA_PIN GPIO_PIN_13
#elif (I2C4_SDA_ID == 3)
#define I2C4_SDA_PORT F
#define I2C4_SDA_PIN GPIO_PIN_15
#elif (I2C4_SDA_ID == 4)
#define I2C4_SDA_PORT H
#define I2C4_SDA_PIN GPIO_PIN_12
#else   /* I2C4_SDA_ID */
#error "Invalid I2C4_SDA Pin Configuration! "
#endif  /* I2C4_SDA_ID */

//   <e> Enable I2C4 Interrupt
#define I2C4_IT_ENABLE 0

#if I2C4_IT_ENABLE

//   <o> I2C4 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of I2C4
#define I2C4_IT_PRIORITY        2
//   <o> I2C4 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of I2C4
#define I2C4_IT_SUB             3

//   </e>
#endif /* I2C4_IT_ENABLE */

//   <e> Enable I2C4 DMA RX
#define I2C4_RX_DMA             0

#if I2C4_RX_DMA

//     <o> BDMA Channel <0-7>
//     <i>  Selects BDMA Number
#define I2C4_RX_BDMA_CHANNEL     1

//     <o I2C4_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C4_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C4_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C4_RX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C4_RX_DMA */

//   <e> Enable I2C4 DMA TX
#define I2C4_TX_DMA             0

#if I2C4_TX_DMA

//     <o> BDMA Channel <0-7>
//     <i>  Selects BDMA Number
#define I2C4_TX_BDMA_CHANNEL     1

//     <o I2C4_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C4_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C4_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C4_TX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C4_TX_DMA */

#endif  /* I2C4_ENABLE */
// </e>

// <e> I2C5 (Inter-integrated Circuit Interface)
#define I2C5_ENABLE  0

#if I2C5_ENABLE

//   <o> I2C5_SCL Pin
//       <0=>PA8<1=>PC11<2=>PF1
#define I2C5_SCL_ID 0

#if (I2C5_SCL_ID == 0)
#define I2C5_SCL_PORT A
#define I2C5_SCL_PIN GPIO_PIN_8
#elif (I2C5_SCL_ID == 1)
#define I2C5_SCL_PORT C
#define I2C5_SCL_PIN GPIO_PIN_11
#elif (I2C5_SCL_ID == 2)
#define I2C5_SCL_PORT F
#define I2C5_SCL_PIN GPIO_PIN_1
#else   /* I2C5_SCL_ID */
#error "Invalid I2C5_SCL Pin Configuration! "
#endif  /* I2C5_SCL_ID */

//   <o> I2C5_SDA Pin
//       <0=>PC9<1=>PC10<2=>PF0
#define I2C5_SDA_ID 0

#if (I2C5_SDA_ID == 0)
#define I2C5_SDA_PORT C
#define I2C5_SDA_PIN GPIO_PIN_9
#elif (I2C5_SDA_ID == 1)
#define I2C5_SDA_PORT C
#define I2C5_SDA_PIN GPIO_PIN_10
#elif (I2C5_SDA_ID == 2)
#define I2C5_SDA_PORT F
#define I2C5_SDA_PIN GPIO_PIN_0
#else   /* I2C5_SDA_ID */
#error "Invalid I2C5_SDA Pin Configuration! "
#endif  /* I2C5_SDA_ID */

//   <e> Enable I2C5 Interrupt
#define I2C5_IT_ENABLE 0

#if I2C5_IT_ENABLE

//   <o> I2C5 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of I2C5
#define I2C5_IT_PRIORITY        2
//   <o> I2C5 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of I2C5
#define I2C5_IT_SUB             3

//   </e>
#endif /* I2C5_IT_ENABLE */

//   <e> Enable I2C5 DMA RX
#define I2C5_RX_DMA             0

#if I2C5_RX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C5_RX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C5_RX_DMA_STREAM      1

//     <o I2C5_RX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C5_RX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA RX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C5_RX_DMA_IT_PRIORITY 2

//     <o> DMA RX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C5_RX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C5_RX_DMA */

//   <e> Enable I2C5 DMA TX
#define I2C5_TX_DMA             0

#if I2C5_TX_DMA

//     <o> Number <1-2>
//     <i>  Selects DMA Number
#define I2C5_TX_DMA_NUMBER      1

//     <o> Stream <0-7>
//     <i>  Selects DMA Stream
#define I2C5_TX_DMA_STREAM      1

//     <o I2C5_TX_DMA_PRIORITY> Priority
//      <DMA_PRIORITY_LOW=>Low
//      <DMA_PRIORITY_MEDIUM=>Medium
//      <DMA_PRIORITY_HIGH=>High
//      <DMA_PRIORITY_VERY_HIGH=>Very High
//     <i> Selects DMA Priority
#define I2C5_TX_DMA_PRIORITY    DMA_PRIORITY_LOW

//     <o> DMA TX Interrupt Priority <0-15>
//     <i>  The Interrupt Priority of DMA Rx
#define I2C5_TX_DMA_IT_PRIORITY 2

//     <o> DMA TX Interrupt SubPriority <0-15>
//     <i>  The Interrupt SubPriority of DMA Rx
#define I2C5_TX_DMA_IT_SUB      2

//   </e>

#endif  /* I2C5_TX_DMA */

#endif  /* I2C5_ENABLE */
// </e>

// <e> FDCAN1 (Flexible Data-Rate Controller Area Network)
#define FDCAN1_ENABLE  0

#if FDCAN1_ENABLE

//   <o> FDCAN1_RX Pin
//       <0=>PA11<1=>PB8<2=>PD0<3=>PH14<4=>PI9
#define FDCAN1_RX_ID 0

#if (FDCAN1_RX_ID == 0)
#define FDCAN1_RX_PORT A
#define FDCAN1_RX_PIN GPIO_PIN_11
#elif (FDCAN1_RX_ID == 1)
#define FDCAN1_RX_PORT B
#define FDCAN1_RX_PIN GPIO_PIN_8
#elif (FDCAN1_RX_ID == 2)
#define FDCAN1_RX_PORT D
#define FDCAN1_RX_PIN GPIO_PIN_0
#elif (FDCAN1_RX_ID == 3)
#define FDCAN1_RX_PORT H
#define FDCAN1_RX_PIN GPIO_PIN_14
#elif (FDCAN1_RX_ID == 4)
#define FDCAN1_RX_PORT I
#define FDCAN1_RX_PIN GPIO_PIN_9
#else   /* FDCAN1_RX_ID */
#error "Invalid FDCAN1_RX Pin Configuration! "
#endif  /* FDCAN1_RX_ID */

//   <o> FDCAN1_TX Pin
//       <0=>PA12<1=>PB9<2=>PD1<3=>PH13
#define FDCAN1_TX_ID 0

#if (FDCAN1_TX_ID == 0)
#define FDCAN1_TX_PORT A
#define FDCAN1_TX_PIN GPIO_PIN_12
#elif (FDCAN1_TX_ID == 1)
#define FDCAN1_TX_PORT B
#define FDCAN1_TX_PIN GPIO_PIN_9
#elif (FDCAN1_TX_ID == 2)
#define FDCAN1_TX_PORT D
#define FDCAN1_TX_PIN GPIO_PIN_1
#elif (FDCAN1_TX_ID == 3)
#define FDCAN1_TX_PORT H
#define FDCAN1_TX_PIN GPIO_PIN_13
#else   /* FDCAN1_TX_ID */
#error "Invalid FDCAN1_TX Pin Configuration! "
#endif  /* FDCAN1_TX_ID */

//   <e> Enable FDCAN1 IT0 Interrupt
#define FDCAN1_IT0_IT_ENABLE 0

#if FDCAN1_IT0_IT_ENABLE

//   <o> FDCAN1 IT0 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of FDCAN1 IT0
#define FDCAN1_IT0_IT_PRIORITY        2
//   <o> FDCAN1 IT0 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of FDCAN1 IT0
#define FDCAN1_IT0_IT_SUB             3

//   </e>
#endif /* FDCAN1_IT0_IT_ENABLE */

//   <e> Enable FDCAN1 IT1 Interrupt
#define FDCAN1_IT1_IT_ENABLE 0

#if FDCAN1_IT1_IT_ENABLE

//   <o> FDCAN1 IT1 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of FDCAN1 IT1
#define FDCAN1_IT1_IT_PRIORITY        2
//   <o> FDCAN1 IT1 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of FDCAN1 IT1
#define FDCAN1_IT1_IT_SUB             3

//   </e>
#endif /* FDCAN1_IT1_IT_ENABLE */

#endif  /* FDCAN1_ENABLE */
// </e>

// <e> FDCAN2 (Flexible Data-Rate Controller Area Network)
#define FDCAN2_ENABLE  0

#if FDCAN2_ENABLE

//   <o> FDCAN2_RX Pin
//       <0=>PB5<1=>PB12
#define FDCAN2_RX_ID 0

#if (FDCAN2_RX_ID == 0)
#define FDCAN2_RX_PORT B
#define FDCAN2_RX_PIN GPIO_PIN_5
#elif (FDCAN2_RX_ID == 1)
#define FDCAN2_RX_PORT B
#define FDCAN2_RX_PIN GPIO_PIN_12
#else   /* FDCAN2_RX_ID */
#error "Invalid FDCAN2_RX Pin Configuration! "
#endif  /* FDCAN2_RX_ID */

//   <o> FDCAN2_TX Pin
//       <0=>PB6<1=>PB13
#define FDCAN2_TX_ID 0

#if (FDCAN2_TX_ID == 0)
#define FDCAN2_TX_PORT B
#define FDCAN2_TX_PIN GPIO_PIN_6
#elif (FDCAN2_TX_ID == 1)
#define FDCAN2_TX_PORT B
#define FDCAN2_TX_PIN GPIO_PIN_13
#else   /* FDCAN2_TX_ID */
#error "Invalid FDCAN2_TX Pin Configuration! "
#endif  /* FDCAN2_TX_ID */

//   <e> Enable FDCAN2 IT0 Interrupt
#define FDCAN2_IT0_IT_ENABLE 0

#if FDCAN2_IT0_IT_ENABLE

//   <o> FDCAN2 IT0 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of FDCAN2 IT0
#define FDCAN2_IT0_IT_PRIORITY        2
//   <o> FDCAN2 IT0 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of FDCAN2 IT0
#define FDCAN2_IT0_IT_SUB             3

//   </e>
#endif /* FDCAN2_IT0_IT_ENABLE */

//   <e> Enable FDCAN2 IT1 Interrupt
#define FDCAN2_IT1_IT_ENABLE 0

#if FDCAN2_IT1_IT_ENABLE

//   <o> FDCAN2 IT1 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of FDCAN2 IT1
#define FDCAN2_IT1_IT_PRIORITY        2
//   <o> FDCAN2 IT1 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of FDCAN2 IT1
#define FDCAN2_IT1_IT_SUB             3

//   </e>
#endif /* FDCAN2_IT1_IT_ENABLE */

#endif  /* FDCAN2_ENABLE */
// </e>

// <e> FDCAN3 (Flexible Data-Rate Controller Area Network)
#define FDCAN3_ENABLE  0

#if FDCAN3_ENABLE

//   <o> FDCAN3_RX Pin
//       <0=>PD12<1=>PF6<2=>PG10
#define FDCAN3_RX_ID 0

#if (FDCAN3_RX_ID == 0)
#define FDCAN3_RX_PORT D
#define FDCAN3_RX_PIN GPIO_PIN_12
#elif (FDCAN3_RX_ID == 1)
#define FDCAN3_RX_PORT F
#define FDCAN3_RX_PIN GPIO_PIN_6
#elif (FDCAN3_RX_ID == 2)
#define FDCAN3_RX_PORT G
#define FDCAN3_RX_PIN GPIO_PIN_10
#else   /* FDCAN3_RX_ID */
#error "Invalid FDCAN3_RX Pin Configuration! "
#endif  /* FDCAN3_RX_ID */

//   <o> FDCAN3_TX Pin
//       <0=>PD13<1=>PF7<2=>PG9
#define FDCAN3_TX_ID 0

#if (FDCAN3_TX_ID == 0)
#define FDCAN3_TX_PORT D
#define FDCAN3_TX_PIN GPIO_PIN_13
#elif (FDCAN3_TX_ID == 1)
#define FDCAN3_TX_PORT F
#define FDCAN3_TX_PIN GPIO_PIN_7
#elif (FDCAN3_TX_ID == 2)
#define FDCAN3_TX_PORT G
#define FDCAN3_TX_PIN GPIO_PIN_9
#else   /* FDCAN3_TX_ID */
#error "Invalid FDCAN3_TX Pin Configuration! "
#endif  /* FDCAN3_TX_ID */

//   <e> Enable FDCAN3 IT0 Interrupt
#define FDCAN3_IT0_IT_ENABLE 0

#if FDCAN3_IT0_IT_ENABLE

//   <o> FDCAN3 IT0 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of FDCAN3 IT0
#define FDCAN3_IT0_IT_PRIORITY        2
//   <o> FDCAN3 IT0 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of FDCAN3 IT0
#define FDCAN3_IT0_IT_SUB             3

//   </e>
#endif /* FDCAN3_IT0_IT_ENABLE */

//   <e> Enable FDCAN3 IT1 Interrupt
#define FDCAN3_IT1_IT_ENABLE 0

#if FDCAN3_IT1_IT_ENABLE

//   <o> FDCAN3 IT1 Interrupt Priority <0-15>
//   <i> The Interrupt Priority of FDCAN3 IT1
#define FDCAN3_IT1_IT_PRIORITY        2
//   <o> FDCAN3 IT1 Interrupt SubPriority <0-15>
//   <i> The Interrupt SubPriority of FDCAN3 IT1
#define FDCAN3_IT1_IT_SUB             3

//   </e>
#endif /* FDCAN3_IT1_IT_ENABLE */

#endif  /* FDCAN3_ENABLE */
// </e>

// <e> RTC (Real Time Clock)
#define RTC_ENABLE            1

//   <e> RTC Wake Up Interrupt
#define RTC_WKUP_IT_ENABLE    0
//      <o> RTC Wake up Interrupt Priority <0-15>
//      <i> The Interrupt Priority of RTC Wake up
#define RTC_WKUP_IT_PRIORITY  2
//      <o> RTC Wake up Interrupt SubPriority <0-15>
//      <i> The Interrupt SubPriority of RTC Wake up
#define RTC_WKUP_IT_SUB       3
//   </e>

//   <e> RTC Alarm Interrupt
#define RTC_ALARM_IT_ENABLE   0
//      <o> RTC Alarm  Interrupt Priority <0-15>
//      <i> The Interrupt Priority of RTC Alarm
#define RTC_ALARM_IT_PRIORITY 2
//      <o> RTC Alarm Interrupt SubPriority <0-15>
//      <i> The Interrupt SubPriority of RTC Alarm
#define RTC_ALARM_IT_SUB      3
//   </e>

// </e>

// <<< end of configuration section >>>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Enable and disable the clock of GPIO. */
#define _CSP_GPIO_PORT(x)          GPIO##x
#define CSP_GPIO_PORT(x)           _CSP_GPIO_PORT(x)
#define _CSP_GPIO_CLK_ENABLE(x)    __HAL_RCC_GPIO##x##_CLK_ENABLE()
#define CSP_GPIO_CLK_ENABLE(x)     _CSP_GPIO_CLK_ENABLE(x)

/* Enable and disable the clock of DMA. */
#define _CSP_DMA_CLK_ENABLE(x)     __HAL_RCC_DMA##x##_CLK_ENABLE()
#define CSP_DMA_CLK_ENABLE(x)      _CSP_DMA_CLK_ENABLE(x)

/* Pasting the DMA Stream. */
#define _CSP_DMA_STREAM(x, y)      DMA##x##_Stream##y
#define CSP_DMA_STREAM(x, y)       _CSP_DMA_STREAM(x, y)

/* Pasting the DMA Stream IRQn and IRQHandler. */
#define _CSP_DMA_STREAM_IRQn(x, y) DMA##x##_Stream##y##_IRQn
#define CSP_DMA_STREAM_IRQn(x, y)  _CSP_DMA_STREAM_IRQn(x, y)

#define _CSP_DMA_STREAM_IRQ(x, y)  DMA##x##_Stream##y##_IRQHandler
#define CSP_DMA_STREAM_IRQ(x, y)   _CSP_DMA_STREAM_IRQ(x, y)

/* Pasting the MDMA Channel. */
#define _CSP_MDMA_CHANNEL(x)       MDMA_Channel##x
#define CSP_MDMA_CHANNEL(x)        _CSP_MDMA_CHANNEL(x)

/* Pasting the BDMA Channel. */
#define _CSP_BDMA_CHANNEL(x)       BDMA_Channel##x
#define CSP_BDMA_CHANNEL(x)        _CSP_BDMA_CHANNEL(x)

/* Pasting the BDMA Channel IRQn and IRQHandler. */
#define _CSP_BDMA_CHANNEL_IRQn(x)  BDMA_Channel##x##_IRQn
#define CSP_BDMA_CHANNEL_IRQn(x)   _CSP_BDMA_CHANNEL_IRQn(x)

#define _CSP_BDMA_CHANNEL_IRQ(x)   BDMA_Channel##x##_IRQHandler
#define CSP_BDMA_CHANNEL_IRQ(x)    _CSP_BDMA_CHANNEL_IRQ(x)

/* CSP memory management functions. */
#define CSP_MALLOC(x)              malloc(x)
#define CSP_FREE(x)                free(x)
#define CSP_REALLOC(p, x)          realloc(p, x)
#include <stdlib.h>

/* Devices Family header files.  */
#include "stm32h7xx_hal.h"


#if (LPUART1_ENABLE || USART1_ENABLE || USART2_ENABLE || USART3_ENABLE || UART4_ENABLE || UART5_ENABLE || USART6_ENABLE || UART7_ENABLE || UART8_ENABLE || UART9_ENABLE || USART10_ENABLE)
#include "../UART_STM32H7xx.h"
#endif  /* (LPUART1_ENABLE || USART1_ENABLE || USART2_ENABLE || USART3_ENABLE || UART4_ENABLE || UART5_ENABLE || USART6_ENABLE || UART7_ENABLE || UART8_ENABLE || UART9_ENABLE || USART10_ENABLE) */

#if (I2C1_ENABLE || I2C2_ENABLE || I2C3_ENABLE || I2C4_ENABLE || I2C5_ENABLE)
#include "../I2C_STM32H7xx.h"
#endif  /* (I2C1_ENABLE || I2C2_ENABLE || I2C3_ENABLE || I2C4_ENABLE || I2C5_ENABLE) */
    
#if (SPI1_ENABLE || SPI2_ENABLE || SPI3_ENABLE || SPI4_ENABLE || SPI5_ENABLE || SPI6_ENABLE || QUADSPI_ENABLE)
#include "../SPI_STM32H7xx.h"
#endif  /* (SPI1_ENABLE || SPI2_ENABLE || SPI3_ENABLE || SPI4_ENABLE || SPI5_ENABLE || SPI6_ENABLE || QUADSPI_ENABLE) */

#if (FDCAN1_ENABLE || FDCAN2_ENABLE || FDCAN3_ENABLE)
#include "../CAN_STM32H7xx.h"
#endif  /* (FDCAN1_ENABLE || FDCAN2_ENABLE || FDCAN3_ENABLE) */

#if (RTC_ENABLE)
#include "../RTC_STM32H7xx.h"
#endif /* RTC_ENABLE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CSP_CONFIG_H */

