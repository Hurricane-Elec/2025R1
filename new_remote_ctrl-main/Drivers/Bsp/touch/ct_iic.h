/**
 * @file        ct_iic.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-04-20
 * @brief       电容触摸屏 I2C 驱动代码
 * @warning     私有头文件, 不可以被其他文件包含
 * @copyright   2020-2032, 广州市星翼电子科技有限公司
 *
 ****************************************************************************************************
 * Change Logs:
 * Date         Version     Author      Notes
 * 2022-04-20   1.0         Alientek    第一次发布
 */

/* CT_IIC 引脚 定义 */
#define CT_IIC_SCL_GPIO_PORT H
#define CT_IIC_SCL_GPIO_PIN  GPIO_PIN_6

#define CT_IIC_SDA_GPIO_PORT I
#define CT_IIC_SDA_GPIO_PIN  GPIO_PIN_3

#define CT_IIC_SCL(x)                                                          \
    x ? HAL_GPIO_WritePin(CSP_GPIO_PORT(CT_IIC_SCL_GPIO_PORT),                 \
                          CT_IIC_SCL_GPIO_PIN, GPIO_PIN_SET)                   \
      : HAL_GPIO_WritePin(CSP_GPIO_PORT(CT_IIC_SCL_GPIO_PORT),                 \
                          CT_IIC_SCL_GPIO_PIN, GPIO_PIN_RESET);

#define CT_IIC_SDA(x)                                                          \
    x ? HAL_GPIO_WritePin(CSP_GPIO_PORT(CT_IIC_SDA_GPIO_PORT),                 \
                          CT_IIC_SDA_GPIO_PIN, GPIO_PIN_SET)                   \
      : HAL_GPIO_WritePin(CSP_GPIO_PORT(CT_IIC_SDA_GPIO_PORT),                 \
                          CT_IIC_SDA_GPIO_PIN, GPIO_PIN_RESET);

#define CT_READ_SDA                                                            \
    HAL_GPIO_ReadPin(CSP_GPIO_PORT(CT_IIC_SDA_GPIO_PORT), CT_IIC_SDA_GPIO_PIN)

/**
 * @brief 控制 I2C 速度的延时
 *
 */
static void ct_iic_delay(void) {
    delay_us(2);
}

/**
 * @brief 电容触摸芯片 IIC 接口初始化
 *
 */
void ct_iic_init(void) {
    GPIO_InitTypeDef gpio_init_struct;

    CSP_GPIO_CLK_ENABLE(CT_IIC_SCL_GPIO_PORT);
    CSP_GPIO_CLK_ENABLE(CT_IIC_SDA_GPIO_PORT);

    gpio_init_struct.Pin = CT_IIC_SCL_GPIO_PIN;  /* PH6 */
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_OD; /* 开漏输出 */
    gpio_init_struct.Pull = GPIO_PULLUP;         /* 上拉 */
    gpio_init_struct.Speed = GPIO_SPEED_HIGH;    /* 高速 */
    HAL_GPIO_Init(CSP_GPIO_PORT(CT_IIC_SCL_GPIO_PORT), &gpio_init_struct);

    gpio_init_struct.Pin = CT_IIC_SDA_GPIO_PIN; /* PI3 */
    HAL_GPIO_Init(CSP_GPIO_PORT(CT_IIC_SDA_GPIO_PORT), &gpio_init_struct);

    CT_IIC_SDA(1);
    CT_IIC_SCL(1);
}

/**
 * @brief 产生 IIC 起始信号
 *
 */
void ct_iic_start(void) {
    CT_IIC_SDA(1);
    CT_IIC_SCL(1);
    ct_iic_delay();
    CT_IIC_SDA(0); /* START 信号: 当 SCL 为高时, SDA 从高变成低, 表示起始信号 */
    ct_iic_delay();
    CT_IIC_SCL(0); /* 钳住 I2C 总线, 准备发送或接收数据 */
    ct_iic_delay();
}

/**
 * @brief 产生 IIC 停止信号
 *
 */
void ct_iic_stop(void) {
    CT_IIC_SDA(0); /* STOP 信号: 当 SCL 为高时, SDA 从低变成高, 表示停止信号 */
    ct_iic_delay();
    CT_IIC_SCL(1);
    ct_iic_delay();
    CT_IIC_SDA(1); /* 发送 I2C 总线结束信号 */
    ct_iic_delay();
}

/**
 * @brief 等待应答信号到来
 *
 * @return 是否等待应答信号
 * @retval - 1: 接收应答失败
 * @retval - 0: 接收应答成功
 */
uint8_t ct_iic_wait_ack(void) {
    uint8_t waittime = 0;
    uint8_t rack = 0;

    CT_IIC_SDA(1); /* 主机释放 SDA 线 (此时外部器件可以拉低 SDA 线) */
    ct_iic_delay();
    CT_IIC_SCL(1); /* SCL=1, 此时从机可以返回 ACK */
    ct_iic_delay();

    while (CT_READ_SDA) {
        /* 等待应答 */
        waittime++;

        if (waittime > 250) {
            ct_iic_stop();
            rack = 1;
            break;
        }

        ct_iic_delay();
    }

    CT_IIC_SCL(0); /* SCL=0, 结束 ACK 检查 */
    ct_iic_delay();

    return rack;
}

/**
 * @brief 产生 ACK 应答
 *
 */
void ct_iic_ack(void) {
    CT_IIC_SDA(0); /* SCL 0 -> 1  时 SDA = 0, 表示应答 */
    ct_iic_delay();
    CT_IIC_SCL(1);
    ct_iic_delay();
    CT_IIC_SCL(0);
    ct_iic_delay();
    CT_IIC_SDA(1); /* 主机释放 SDA 线 */
    ct_iic_delay();
}

/**
 * @brief 不产生 ACK 应答
 *
 */
void ct_iic_nack(void) {
    CT_IIC_SDA(1); /* SCL 0 -> 1  时 SDA = 1, 表示不应答 */
    ct_iic_delay();
    CT_IIC_SCL(1);
    ct_iic_delay();
    CT_IIC_SCL(0);
    ct_iic_delay();
}

/**
 * @brief IIC 发送一个字节
 *
 * @param data 要发送的数据
 */
void ct_iic_send_byte(uint8_t data) {
    uint8_t t;

    for (t = 0; t < 8; ++t) {
        CT_IIC_SDA((data & 0x80) >> 7); /* 高位先发送 */
        ct_iic_delay();
        CT_IIC_SCL(1);
        ct_iic_delay();
        CT_IIC_SCL(0);
        data <<= 1; /* 左移 1 位, 用于下一次发送 */
    }

    CT_IIC_SDA(1); /* 发送完成, 主机释放 SDA 线 */
}

/**
 * @brief IIC 发送一个字节
 *
 * @param ack 是否发送 ACK
 *  @arg - 1: 发送 ack
 *  @arg - 0: 发送 nack
 * @retval 接收到的数据
 */
uint8_t ct_iic_read_byte(unsigned char ack) {
    uint8_t i, receive = 0;

    for (i = 0; i < 8; ++i) {
        /* 接收 1 个字节数据 */
        receive <<= 1; /* 高位先输出, 所以先收到的数据位要左移 */
        CT_IIC_SCL(1);
        ct_iic_delay();

        if (CT_READ_SDA) {
            receive++;
        }

        CT_IIC_SCL(0);
        ct_iic_delay();
    }

    if (!ack) {
        ct_iic_nack(); /* 发送 nACK */
    } else {
        ct_iic_ack(); /* 发送 ACK */
    }

    return receive;
}
