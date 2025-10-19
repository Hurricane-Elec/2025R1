/**
 * @file        lcd.c
 * @author      正点原子团队 (ALIENTEK)
 * @version     1.1
 * @date        2022-04-20
 * @brief       2.8 寸 / 3.5 寸 / 4.3 寸 / 7 寸 TFTLCD (MCU 屏) 驱动代码
 *              支持驱动 IC 型号包括:
 *              ILI9341/NT35310/NT35510/SSD1963/ST7789/ST7796/ILI9806 等
 * @copyright   2020-2032, 广州市星翼电子科技有限公司
 *
 *****************************************************************************
 * Change Logs:
 * Date         Version     Author      Notes
 * 2022-04-20   1.0         Alientek    第一次发布
 * 2023-06-07   1.1         Alientek    1. 新增对 ST7796 和 ILI9806 支持
 *                                      2. 添加对 LTDC RGBLCD 的兼容
 */

#include "lcd.h"

#include "lcdfont.h"

/* LCD 的画笔颜色和背景色 */
uint32_t g_point_color = 0xFF000000; /* 画笔颜色 */
uint32_t g_back_color = 0xFFFFFFFF;  /* 背景色 */

/* 管理 LCD 重要参数 */
lcd_dev_t lcddev;

/**
 * @brief 读取个某点的颜色值
 *
 * @param x x 坐标
 * @param y y 坐标
 * @retval 此点的颜色 (32 位颜色, 方便兼容 LTDC)
 */
uint32_t lcd_read_point(uint16_t x, uint16_t y) {
    if (x >= lcddev.width || y >= lcddev.height) {
        return 0; /* 超过了范围, 直接返回 */
    }

#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        return ltdc_read_point(x, y);
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief LCD 开启显示
 *
 */
void lcd_display_on(void) {

#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        ltdc_switch(1); /* 开启LTDC */
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief LCD 关闭显示
 *
 */
void lcd_display_off(void) {
#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        ltdc_switch(0); /* 开启LTDC */
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 设置窗口 (对 RGB 屏无效), 并自动设置画点坐标到窗口左上角(sx, sy).
 *
 * @param sx 窗口起始 x 坐标 (左上角)
 * @param sy 窗口起始 y 坐标 (左上角)
 * @param width 窗口宽度, 必须大于 0!!
 * @param height 窗口高度, 必须大于 0!!
 * @note 窗体大小: `width * height`
 */
void lcd_set_window(uint16_t sx, uint16_t sy, uint16_t width, uint16_t height) {
#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        /* RGB 屏幕不支持 */
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 画点
 *
 * @param x x 坐标
 * @param y y 坐标
 * @param color 点的颜色 (32 位颜色, 方便兼容 LTDC)
 */
void lcd_draw_point(uint16_t x, uint16_t y, uint32_t color) {
#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        ltdc_draw_point(x, y, color);
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 有限制的画点函数
 * 
 * @param x 
 * @param y 
 * @param x_limit x方向点位限制
 * @param y_limit y方向点位限制
 * @param color 颜色
 */
void lcd_draw_point_limt(uint16_t x, uint16_t y, uint16_t x_limit,
                         uint16_t y_limit, uint32_t color) {
#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        if (x < x_limit && y < y_limit) {
            ltdc_draw_point(x, y, color);
        }
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 设置 LCD 显示方向
 *
 * @param dir 0, 竖屏;1, 横屏
 */
void lcd_display_dir(uint8_t dir) {
    lcddev.dir = dir; /* 竖屏 / 横屏 */

#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        ltdc_display_dir(dir);
        lcddev.width = lcdltdc.width;
        lcddev.height = lcdltdc.height;
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 初始化 LCD
 *
 * @note 该初始化函数可以初始化各种型号的 LCD (详见本 .c 文件最前面的描述)
 */
void lcd_init(void) {
    lcddev.id = 0x4384;
    ltdc_init();

    lcd_display_dir(0); /* 默认为竖屏 */
    LCD_BL(1);          /* 点亮背光 */
    lcd_clear(WHITE);
}

/**
 * @brief 清屏函数
 *
 * @param color 要清屏的颜色
 */
void lcd_clear(uint16_t color) {
    uint32_t index = 0;
    uint32_t totalpoint = lcddev.width;

#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        /* 如果是RGB屏 */
        ltdc_clear(color);
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 在指定区域内填充单个颜色
 *
 * @param sx 起始 x 坐标
 * @param sy 起始 y 坐标
 * @param ex 终点 x 坐标
 * @param ey 终点 y 坐标
 * @param color 要填充的颜色
 * @note 区域大小为:`(ex - sx + 1) * (ey - sy + 1)`
 */
void lcd_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey,
              uint32_t color) {
#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        /* 如果是RGB屏 */
        ltdc_fill(sx, sy, ex, ey, color);
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 在指定区域内填充指定颜色块
 *
 * @param sx 起始 x 坐标
 * @param sy 起始 y 坐标
 * @param ex 终点 x 坐标
 * @param ey 终点 y 坐标
 * @param color 填充的颜色数组首地址
 * @note 区域大小为:`(ex - sx + 1) * (ey - sy + 1)`
 */
void lcd_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey,
                    uint16_t *color) {
#if LCD_USE_RGB
    if (lcdltdc.pwidth != 0) {
        /* 如果是RGB屏 */
        ltdc_color_fill(sx, sy, ex, ey, color);
        return;
    }
#endif /* LCD_USE_RGB */
}

/**
 * @brief 画线
 *
 * @param x1 起点 x 坐标
 * @param y1 起点 y 坐标
 * @param x2 终点 x 坐标
 * @param y2 终点 y 坐标
 * @param color 线的颜色
 */
void lcd_draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                   uint16_t color) {
    uint16_t t;
    int xerr = 0, yerr = 0, delta_x, delta_y, distance;
    int incx, incy, row, col;
    delta_x = x2 - x1; /* 计算坐标增量 */
    delta_y = y2 - y1;
    row = x1;
    col = y1;

    if (delta_x > 0) {
        incx = 1; /* 设置单步方向 */
    } else if (delta_x == 0) {
        incx = 0; /* 垂直线 */
    } else {
        incx = -1;
        delta_x = -delta_x;
    }

    if (delta_y > 0) {
        incy = 1;
    } else if (delta_y == 0) {
        incy = 0; /* 水平线 */
    } else {
        incy = -1;
        delta_y = -delta_y;
    }

    if (delta_x > delta_y) {
        distance = delta_x; /* 选取基本增量坐标轴 */
    } else {
        distance = delta_y;
    }

    for (t = 0; t <= distance + 1; t++) /* 画线输出 */
    {
        lcd_draw_point_limt(row, col, 800, 480, color); /* 画点 */
        xerr += delta_x;
        yerr += delta_y;

        if (xerr > distance) {
            xerr -= distance;
            row += incx;
        }

        if (yerr > distance) {
            yerr -= distance;
            col += incy;
        }
    }
}

/**
 * @brief 画水平线
 *
 * @param x 起点 x 坐标
 * @param y 起点 x 坐标
 * @param len 线长度
 * @param color 矩形的颜色
 */
void lcd_draw_hline(uint16_t x, uint16_t y, uint16_t len, uint16_t color) {
    if ((len == 0) || (x > lcddev.width) || (y > lcddev.height)) {
        return;
    }

    lcd_fill(x, y, x + len - 1, y, color);
}

/**
 * @brief 画矩形
 *
 * @param x1 起点 x 坐标
 * @param y1 起点 y 坐标
 * @param x2 终点 x 坐标
 * @param y2 终点 y 坐标
 * @param color 矩形的颜色
 */
void lcd_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                        uint16_t color) {
    lcd_draw_line(x1, y1, x2, y1, color);
    lcd_draw_line(x1, y1, x1, y2, color);
    lcd_draw_line(x1, y2, x2, y2, color);
    lcd_draw_line(x2, y1, x2, y2, color);
}

/**
 * @brief 画圆
 *
 * @param x 圆心 x 坐标
 * @param y 圆心 y 坐标
 * @param r 半径
 * @param color 圆的颜色
 */
void lcd_draw_circle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color) {
    int a, b;
    int di;
    a = 0;
    b = r;
    di = 3 - (r << 1); /* 判断下个点位置的标志 */

    while (a <= b) {
        lcd_draw_point(x0 + a, y0 - b, color); /* 5 */
        lcd_draw_point(x0 + b, y0 - a, color); /* 0 */
        lcd_draw_point(x0 + b, y0 + a, color); /* 4 */
        lcd_draw_point(x0 + a, y0 + b, color); /* 6 */
        lcd_draw_point(x0 - a, y0 + b, color); /* 1 */
        lcd_draw_point(x0 - b, y0 + a, color);
        lcd_draw_point(x0 - a, y0 - b, color); /* 2 */
        lcd_draw_point(x0 - b, y0 - a, color); /* 7 */
        a++;

        /* 使用 Bresenham 算法画圆 */
        if (di < 0) {
            di += 4 * a + 6;
        } else {
            di += 10 + 4 * (a - b);
            b--;
        }
    }
}

/**
 * @brief 填充实心圆
 *
 * @param x 圆心 x 坐标
 * @param y 圆心 y 坐标
 * @param r 半径
 * @param color 圆的颜色
 */
void lcd_fill_circle(uint16_t x, uint16_t y, uint16_t r, uint16_t color) {
    uint32_t i;
    uint32_t imax = ((uint32_t)r * 707) / 1000 + 1;
    uint32_t sqmax = (uint32_t)r * (uint32_t)r + (uint32_t)r / 2;
    uint32_t xr = r;

    lcd_draw_hline(x - r, y, 2 * r, color);

    for (i = 1; i <= imax; i++) {
        if ((i * i + xr * xr) > sqmax) {
            /* draw lines from outside */
            if (xr > imax) {
                lcd_draw_hline(x - i + 1, y + xr, 2 * (i - 1), color);
                lcd_draw_hline(x - i + 1, y - xr, 2 * (i - 1), color);
            }

            xr--;
        }

        /* draw lines from inside (center) */
        lcd_draw_hline(x - xr, y + i, 2 * xr, color);
        lcd_draw_hline(x - xr, y - i, 2 * xr, color);
    }
}

/**
 * @brief 在指定位置显示一个字符
 *
 * @param x x 坐标
 * @param y y 坐标
 * @param chr 要显示的字符 ' ' --> '~'
 * @param size 字体大小 12/16/24/32
 * @param mode 叠加方式 (1); 非叠加方式 (0);
 * @param color 字符的颜色;
 */
void lcd_show_char(uint16_t x, uint16_t y, char chr, uint8_t size, uint8_t mode,
                   uint16_t color) {
    uint8_t temp, t1, t;
    uint16_t y0 = y;
    uint8_t csize = 0;
    uint8_t *pfont = 0;

    /* 得到字体一个字符对应点阵集所占的字节数 */
    csize = (size / 8 + ((size % 8) ? 1 : 0)) * (size / 2);
    chr = chr - ' '; /* 得到偏移后的值 (ASCII 字库是从空格开始取模) */

    switch (size) {
        case 12:
            pfont = (uint8_t *)asc2_1206[(uint8_t)chr]; /* 调用 1206 字体 */
            break;

        case 16:
            pfont = (uint8_t *)asc2_1608[(uint8_t)chr]; /* 调用 1608 字体 */
            break;

        case 24:
            pfont = (uint8_t *)asc2_2412[(uint8_t)chr]; /* 调用 2412 字体 */
            break;

        case 32:
            pfont = (uint8_t *)asc2_3216[(uint8_t)chr]; /* 调用 3216 字体 */
            break;

        default:
            return;
    }

    for (t = 0; t < csize; t++) {
        temp = pfont[t]; /* 获取字符的点阵数据 */

        for (t1 = 0; t1 < 8; t1++) /* 一个字节 8 个点 */
        {
            if (temp & 0x80) {
                /* 有效点, 需要显示 */
                lcd_draw_point(x, y, color); /* 画点出来, 要显示这个点 */
            } else if (mode == 0) {
                /* 无效点, 不显示 */
                /* 画背景色, 相当于这个点不显示 (注意背景色由全局变量控制) */
                lcd_draw_point(x, y, g_back_color);
            }

            temp <<= 1; /* 移位, 以便获取下一个位的状态 */
            y++;

            if (y >= lcddev.height) {
                return; /* 超区域了 */
            }

            if ((y - y0) == size) {
                /* 显示完一列了?*/
                y = y0; /* y 坐标复位 */
                x++;    /* x 坐标递增 */

                if (x >= lcddev.width) {
                    return; /* x 坐标超区域了 */
                }

                break;
            }
        }
    }
}

/**
 * @brief 幂函数, m^n
 *
 * @param m 底数
 * @param n 指数
 * @retval m 的 n 次方
 */
static uint32_t lcd_pow(uint8_t m, uint8_t n) {
    uint32_t result = 1;

    while (n--) {
        result *= m;
    }

    return result;
}

/**
 * @brief 显示 len 个数字
 *
 * @param x x 坐标
 * @param y y 坐标
 * @param num 数值 (0 ~ 2^32)
 * @param len 显示数字的位数
 * @param size 选择字体 12/16/24/32
 * @param color 数字的颜色;
 */
void lcd_show_num(uint16_t x, uint16_t y, uint32_t num, uint8_t len,
                  uint8_t size, uint16_t color) {
    uint8_t t, temp;
    uint8_t enshow = 0;

    for (t = 0; t < len; t++) {
        /* 按总显示位数循环 */
        temp = (num / lcd_pow(10, len - t - 1)) % 10; /* 获取对应位的数字 */

        if (enshow == 0 && t < (len - 1)) {
            /* 没有使能显示, 且还有位要显示 */
            if (temp == 0) {
                /* 显示空格, 占位 */
                lcd_show_char(x + (size / 2) * t, y, ' ', size, 0, color);
                continue; /* 继续下个一位 */
            } else {
                enshow = 1; /* 使能显示 */
            }
        }

        lcd_show_char(x + (size / 2) * t, y, temp + '0', size, 0, color);
    }
}

/**
 * @brief 扩展显示 len 个数字 (高位是 0 也显示)
 *
 * @param x x 坐标
 * @param y y 坐标
 * @param num 数值 (0 ~ 2^32)
 * @param len 显示数字的位数
 * @param size 选择字体 12/16/24/32
 * @param mode 显示模式
 *             bit[7]:   0, 不填充;1, 填充 0.
 *             bit[6:1]: 保留
 *             bit[0]:   0, 非叠加显示;1, 叠加显示.
 * @param color 数字的颜色;
 */
void lcd_show_xnum(uint16_t x, uint16_t y, uint32_t num, uint8_t len,
                   uint8_t size, uint8_t mode, uint16_t color) {
    uint8_t t, temp;
    uint8_t enshow = 0;

    for (t = 0; t < len; t++) {
        /* 按总显示位数循环 */
        temp = (num / lcd_pow(10, len - t - 1)) % 10; /* 获取对应位的数字 */

        if (enshow == 0 && t < (len - 1)) {
            /* 没有使能显示, 且还有位要显示 */
            if (temp == 0) {
                if (mode & 0X80) {
                    /* 高位需要填充 0 */
                    /* 用 0 占位 */
                    lcd_show_char(x + (size / 2) * t, y, '0', size, mode & 0X01,
                                  color);
                } else {
                    /* 用空格占位 */
                    lcd_show_char(x + (size / 2) * t, y, ' ', size, mode & 0X01,
                                  color);
                }

                continue;
            } else {
                enshow = 1; /* 使能显示 */
            }
        }

        lcd_show_char(x + (size / 2) * t, y, temp + '0', size, mode & 0X01,
                      color);
    }
}

/**
 * @brief 显示字符串
 *
 * @param x 起始 x 坐标
 * @param y 起始 y 坐标
 * @param width 区域宽度
 * @param height 区域高度
 * @param size 选择字体 12/16/24/32
 * @param p 字符串首地址
 * @param color 字符串的颜色
 */
void lcd_show_string(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
                     uint8_t size, char *p, uint16_t color) {
    uint8_t x0 = x;
    width += x;
    height += y;

    while ((*p <= '~') && (*p >= ' ')) {
        /* 判断是不是非法字符!*/
        if (x >= width) {
            x = x0;
            y += size;
        }

        if (y >= height) {
            break; /* 退出 */
        }

        lcd_show_char(x, y, *p, size, 0, color);
        x += size / 2;
        p++;
    }
}

/**
 * @brief 非重叠方式显示字符串
 *
 * @param x 起始 x 坐标
 * @param y 起始 y 坐标
 * @param width 区域宽度
 * @param height 区域高度
 * @param size 选择字体 12/16/24/32
 * @param p 字符串首地址
 * @param color 字符串的颜色
 */
void lcd_show_string_no_overlap(uint16_t x, uint16_t y, uint16_t width,
                                uint16_t height, uint8_t size, char *p,
                                uint16_t color) {
    uint8_t x0 = x;
    width += x;
    height += y;

    while ((*p <= '~') && (*p >= ' ')) {
        /* 判断是不是非法字符!*/
        if (x >= width) {
            x = x0;
            y += size;
        }

        if (y >= height) {
            break; /* 退出 */
        }

        lcd_show_char(x, y, *p, size, 1, color);
        x += size / 2;
        p++;
    }
}

/**
 * @brief LCD画点位置限制
 * 
 * @param x_limt    x轴显示位置 超过此位置的点不显示 
 * @param y_limt 
 * @param x 将要限制的点的坐标
 * @param y 
 */
void point_limit(int16_t x_limt, int16_t y_limt, int16_t *x, int16_t *y) {
    int16_t x_origin = *x;
    int16_t y_origin = *y;
    if (x_origin < 0 || x_origin > x_limt) {
        x_origin = NULL;
    }
    if (y_origin < 0 || y_origin > y_limt) {
        y_origin = NULL;
    }
    *x = x_origin;
    *y = y_origin;
}
