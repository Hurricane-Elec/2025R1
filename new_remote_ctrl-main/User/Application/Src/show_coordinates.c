/**
 * @file show_coordinates
 * @author lingborong
 * @brief 屏幕上显示底盘的位置
 * @version 0.1
 * @date 2025-04-25
 * @note 底盘gui如图所示,原点可以通过正方形(不含yaw角),或三角形(含yaw角)显示
 *       底盘默认方向为
 *          y 
 *          |
 *          |
 *          |________x
 *      
 *         ( 49, 79)----------------(799, 79)
 *             |                        |
 *             |                        |
 *             |                        |
 *             |                        |
 *             |                        |
 *             |                        |
 *             |                        |
 *         ( 49,479)----------------(799,479)
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "includes.h"
#include "my_math/my_math.h"

/* 接收底盘消息的消息队列 */
QueueHandle_t position_data_queue;

#define COORD_SHAPE            1 /* 选择使用三角形打点 */

#define COORD_SIZE             21 /* 画点尺寸，奇数中点为全场定位当前位置*/

#define KEY_NUMBER_ENTER       1  /* 进入原点选择 */
#define KEY_NUMBER_CHOOSE_LAST 2  /* 选择上一个原点 */
#define KEY_NUMBER_CHOOSE_NEXT 3  /* 选择下一个原点 */
#define KEY_NUMBER_EXIT        4  /* 退出原点选择 */
#define KEY_NUMBER_DIRECTION   18 /* 选择原点方向 */

#define COONRDINGATES_ADJ_ADDR 100  /* 保存校准值的起始地址 */
#define COONRDINGATES_ADJ_FLAG 0x77 /* 原点是否通过校准标志位 */

/* 底盘状态 */
#define FOCUS_POS              1
#define FOCUS_MSK              (1U << FOCUS_POS)

#define WORLD_POS              0
#define WORLD_MSK              (1U << WORLD_POS)

/* 坐标系位置偏移结构体 */
typedef struct __packed coonrdingates {
    int16_t x; /* 单位是像素 */
    int16_t y;
    uint8_t flag;   /* 校准标记 */
    uint16_t angle; /* 起始方向 */
} coonrdingates_t;

/* 坐标点数据结构体 */
typedef struct point_last_t {
    int16_t x;      /* 上一个点x坐标 */
    int16_t y;      /* 上一个点y坐标 */
    uint16_t color; /* 上一个点的颜色 */
} point_t;

static coonrdingates_t coonrdingates_offset_data;
static QueueHandle_t origin_queue;
static uint8_t chassis_last_data = 0;
static uint8_t chassis_coord_flag = 1;

/* 原点 ,在这里添加自己想要起始的点位，可以在地图所有位置添加，同时将宏定义点位个数合理增加*/
#define ORIGIN_POINT_SIZE 8
const point_t origin_point[ORIGIN_POINT_SIZE] = {
    {49, 79},   {424, 79},  {799, 79}, {799, 279},
    {799, 479}, {424, 479}, {49, 479}, {49, 279}};
void gui_origin_set_int(uint8_t key, remote_key_event_t event);
void gui_origin_set(void);
uint8_t bit_change(uint8_t *data_a, uint8_t data_b);

/**
 * @brief 显示底盘坐标位置
 * 
 * @param pvParameters 
 */
void show_coordinates_task(void *pvParameters) {
    UNUSED(pvParameters);
    position_data_t recv_position_data = {0, 0, 0};
    uint8_t origin_set_data = 0;
    origin_queue = xQueueCreate(1, sizeof(uint8_t));

    /* 接收底盘回传数据坐标 */
    position_data_queue = xQueueCreate(1, sizeof(position_data_t));

    remote_register_key_callback(KEY_NUMBER_ENTER, REMOTE_KEY_PRESSING,
                                 gui_origin_set_int);

    /* 从at24c02中读取坐标系偏移 */
    at24cxx_read(&at24c02_handle, COONRDINGATES_ADJ_ADDR,
                 (uint8_t *)&coonrdingates_offset_data,
                 sizeof(coonrdingates_offset_data));
    vTaskDelay(1000);
    /* 读取标志位，没设过原点必须要设置一次原点 */
    if (coonrdingates_offset_data.flag != COONRDINGATES_ADJ_FLAG) {
        gui_origin_set();
    }
    uint32_t start_time = HAL_GetTick();
    do {
        xQueueReceive(origin_queue, &origin_set_data, 1);
        vTaskDelay(1);
        if (origin_set_data != ORIGIN_SET_INT) {
            break;
        }
    } while (HAL_GetTick() - start_time < 3000);

    /* 这里判断时间 */
    if (HAL_GetTick() - start_time >= 3000) {
        gui_origin_set();
    }

    remote_unregister_key_callback(KEY_NUMBER_ENTER, REMOTE_KEY_PRESSING);
    vQueueDelete(origin_queue);

    while (1) {
        /* 接收信息阻塞超时 */
        if (xQueueReceive(position_data_queue, &recv_position_data, 1500) ==
            pdFAIL) {
            /* 显示断联图标文本 */
            lv_obj_clear_flag(objects.lvble_nrfsignal, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(objects.lvble_nrfsignal,
                            LV_OBJ_FLAG_HIDDEN); /* 隐藏部件 */
            /* 更新全场定位数据 */
            lv_label_set_text_fmt(objects.lvble_angle_number, "%d °",
                                  recv_position_data.angle);
            lv_label_set_text_fmt(objects.lvble_p_x, "x = %.1f cm",
                                  (float)recv_position_data.x / 10.0f);
            lv_label_set_text_fmt(objects.lvble_p_y, "y = %.1f cm",
                                  (float)recv_position_data.y / 10.0f);
            /* 当传入数据较上一次发生改变时改变GUI */
            if (chassis_last_data != recv_position_data.chassis_status) {
                /* 判断有变化的位，选择性更新 */
            lable_bit_compare:
                switch (bit_change(&chassis_last_data,
                                   recv_position_data.chassis_status)) {
                    case 1: /* 第一位坐标系 */
                        if (READ_BIT(recv_position_data.chassis_status,
                                     WORLD_MSK)) {
                            /* 是世界坐标 */
                            lv_obj_clear_flag(objects.lvble_coordinate_world,
                                              LV_OBJ_FLAG_HIDDEN);
                            lv_obj_add_flag(objects.lvble_coordinate_itself,
                                            LV_OBJ_FLAG_HIDDEN);
                        } else {
                            lv_obj_clear_flag(objects.lvble_coordinate_itself,
                                              LV_OBJ_FLAG_HIDDEN);
                            lv_obj_add_flag(objects.lvble_coordinate_world,
                                            LV_OBJ_FLAG_HIDDEN);
                        }
                        goto lable_bit_compare;
                    case 2: /* 第二位自瞄 */
                        if (READ_BIT(recv_position_data.chassis_status,
                                     FOCUS_MSK)) {
                            lv_label_set_text(objects.lvble_auto_focus,
                                              LV_SYMBOL_EYE_OPEN);
                        } else {
                            lv_label_set_text(objects.lvble_auto_focus,
                                              LV_SYMBOL_EYE_CLOSE);
                        }
                        goto lable_bit_compare;
                    default: /* 完成所有位变化后从这里退出 */
                        break;
                }
            }
            if (chassis_coord_flag) {
                origin_point_draw(recv_position_data.x, recv_position_data.y,
                                  recv_position_data.angle, 0xD892);
            }
            chassis_last_data = recv_position_data.chassis_status;
        }
    }
}
/************************** 设置原点部分*****************************/

/**
 * @brief 对比两个数据有变化的位
 * 
 * @param data_a 要变化的数据
 * @param data_b 
 * @note 对比两个数据中有变化的位并将前者中有变化的位改变
 * @return uint8_t 变化的位
 */
uint8_t bit_change(uint8_t *data_a, uint8_t data_b) {
    uint8_t i = 0;
    for (i = 0; i < 8; i++) {
        if (((*data_a >> i) & 0x01) != ((data_b >> i) & 0x01)) {
            if (((*data_a >> i) & 0x01) > 0) {
                *data_a -= (0x01 << i);
            } else {
                *data_a |= (0x01 << i);
            }
            return i + 1;
        }
    }
    return 0;
}

/**
 * @brief gui界面切换回调函数
 * 
 * @param key 
 * @param event 
 * @note 按下相应按键进行页面切换，再次按下之后页面会切换回来。
 */
void gui_screen_switch(uint8_t key, remote_key_event_t event) {
    UNUSED(key);
    UNUSED(event);
    static uint8_t screen_signal = 0;
    screen_signal ? lv_tabview_set_act(objects.tabview, 0, LV_ANIM_OFF)
                  : lv_tabview_set_act(objects.tabview, 1, LV_ANIM_OFF);
    if (screen_signal) {
        chassis_coord_flag = 1;
    } else {
        chassis_coord_flag = 0;
    }
    screen_signal = screen_signal ? 0 : 1;
}

/**
 * @brief 进入原点设置的回调函数
 * 
 * @param key 
 * @param event 
 */
void gui_origin_set_int(uint8_t key, remote_key_event_t event) {
    UNUSED(key);
    UNUSED(event);
    uint8_t origin_set_data = ORIGIN_SET_INT;
    xQueueSend(origin_queue, &origin_set_data, 1);
}

/**
 * @brief 选择上一个原点
 * 
 * @param key 
 * @param event 
 */
void gui_origin_set_choose_last(uint8_t key, remote_key_event_t event) {
    UNUSED(key);
    UNUSED(event);
    uint8_t origin_set_data = ORIGIN_SET_LAST;
    xQueueSend(origin_queue, &origin_set_data, 1);
}

/**
 * @brief 选择下一个原点
 * 
 * @param key 
 * @param event 
 */
void gui_origin_set_choose_next(uint8_t key, remote_key_event_t event) {
    UNUSED(key);
    UNUSED(event);
    uint8_t origin_set_data = ORIGIN_SET_NEXT;
    xQueueSend(origin_queue, &origin_set_data, 1);
}

/**
 * @brief 设置该原点方向的函数
 * 
 * @param key 
 * @param event 
 */
void gui_origin_set_direction(uint8_t key, remote_key_event_t event) {
    UNUSED(key);
    UNUSED(event);
    uint8_t origin_set_data = ORIGIN_SET_DIRECTION;
    xQueueSend(origin_queue, &origin_set_data, 1);
}

/**
 * @brief 退出原点选择的函数
 * 
 * @param key 
 * @param event 
 */
void gui_origin_set_out(uint8_t key, remote_key_event_t event) {
    UNUSED(key);
    UNUSED(event);
    uint8_t origin_set_data = ORIGIN_SET_OUT;
    xQueueSend(origin_queue, &origin_set_data, 1);
}

/**
 * @brief 设置原点
 * 
 */
void gui_origin_set(void) {
    coonrdingates_offset_data.x = 49; /* 按键初始偏移 */
    coonrdingates_offset_data.y = 79;
    coonrdingates_offset_data.angle = 0; /* 初始角度偏移 */
    uint8_t origin_set_data = 0;
    int8_t origin_index = 0;
    /* 创建提示文本部件 */

    vTaskSuspend(gui_task_handle);
    lv_obj_t *set_origin_remain_txt = create_Fontlable(
        LV_SIMHEI_22, "使用按键2,3,18进行原点的选择\n按下按键4退出并保存原点",
        lv_scr_act(), 0, 50, 0x1393);
    vTaskResume(gui_task_handle);
    vTaskDelay(2000);
    remote_register_key_callback(KEY_NUMBER_CHOOSE_LAST, REMOTE_KEY_PRESS_DOWN,
                                 gui_origin_set_choose_last);
    remote_register_key_callback(KEY_NUMBER_CHOOSE_NEXT, REMOTE_KEY_PRESS_DOWN,
                                 gui_origin_set_choose_next);
    remote_register_key_callback(KEY_NUMBER_EXIT, REMOTE_KEY_PRESS_DOWN,
                                 gui_origin_set_out);
    remote_register_key_callback(KEY_NUMBER_DIRECTION, REMOTE_KEY_PRESS_DOWN,
                                 gui_origin_set_direction);
    while (1) {

        /* 打原点 */
        triangle_draw_clean(coonrdingates_offset_data.x * 20,
                            coonrdingates_offset_data.y * 20,
                            coonrdingates_offset_data.angle, 0xD892);
        /* 等待选择 */
        if (origin_set_data == ORIGIN_SET_OUT) {
            coonrdingates_offset_data.flag = 0x77; /* 置标志位 */
            at24cxx_write(&at24c02_handle, COONRDINGATES_ADJ_ADDR,
                          (uint8_t *)&coonrdingates_offset_data,
                          sizeof(coonrdingates_offset_data));
            lv_obj_del(set_origin_remain_txt);
            remote_unregister_key_callback(KEY_NUMBER_CHOOSE_LAST,
                                           REMOTE_KEY_PRESS_DOWN);
            remote_unregister_key_callback(KEY_NUMBER_CHOOSE_NEXT,
                                           REMOTE_KEY_PRESS_DOWN);
            remote_unregister_key_callback(KEY_NUMBER_EXIT,
                                           REMOTE_KEY_PRESS_DOWN);
            remote_unregister_key_callback(KEY_NUMBER_DIRECTION,
                                           REMOTE_KEY_PRESS_DOWN);
            return;
        }
        /* 选择下一个原点 */
        if (origin_set_data == ORIGIN_SET_NEXT) {
            origin_index++;
            if (origin_index > (ORIGIN_POINT_SIZE - 1)) {
                origin_index = 0;
            }
            coonrdingates_offset_data.x = origin_point[origin_index].x;
            coonrdingates_offset_data.y = origin_point[origin_index].y;
        }
        /* 选择上一个原点 */
        if (origin_set_data == ORIGIN_SET_LAST) {
            origin_index--;
            if (origin_index < 0) {
                origin_index = (ORIGIN_POINT_SIZE - 1);
            }
            coonrdingates_offset_data.x = origin_point[origin_index].x;
            coonrdingates_offset_data.y = origin_point[origin_index].y;
        }
        /* 选择该原点下的启动方向 */
        if (origin_set_data == ORIGIN_SET_DIRECTION) {
            coonrdingates_offset_data.angle += 90;
            if (coonrdingates_offset_data.angle > 270) {
                coonrdingates_offset_data.angle = 0;
            }
        }
        origin_set_data = 0;
        xQueueReceive(origin_queue, &origin_set_data, 1);
        vTaskDelay(100);
    }
}

/**************************  画点部分 *****************************/

/**
 * @brief 画点函数 坐标为屏幕原始坐标系
 *
 * @param x 全场定位x坐标
 * @param y 全场定位y坐标
 * @note 函数通过COORD_SIZE调整画点大小。
 */
static void point_draw(int16_t x, int16_t y, uint16_t color) {

    int16_t pixel_x = x / 20 - (COORD_SIZE - 1) / 2; /* 像素位置 */
    int16_t pixel_y = y / 20 + (COORD_SIZE - 1) / 2;

    for (int i = 0; i < (COORD_SIZE * COORD_SIZE); i++) {
        int16_t x_out = pixel_x + (int16_t)(i % COORD_SIZE);
        int16_t y_out = pixel_y - (int16_t)(i / COORD_SIZE);
        point_limit(799, 479, &x_out, &y_out);
        if (x_out == NULL || y_out == NULL) {
            continue;
        }
        lcd_draw_point(x_out, y_out, color);
    }
}

/**
 * @brief 以正方形显示轨迹原点(不含yaw角)
 *
 * @param x 全场定位x坐标
 * @param y 全场定位y坐标
 */
void point_draw_clean(int16_t x, int16_t y, uint32_t color) {
    static point_t point_last[COORD_SIZE * COORD_SIZE]; /* 上一个点 */
    /* 还原上一个点的数据 */
    for (int i = 0; i < (COORD_SIZE * COORD_SIZE); i++) {
        point_limit(799, 479, &point_last[i].x, &point_last[i].y);
        if ((point_last[i].x == NULL) || (point_last[i].y == NULL)) {
            continue; /* 跳出此次循环 */
        }
        lcd_draw_point(point_last[i].x, point_last[i].y, point_last[i].color);
    }
    /* 存储上一个点的数据,得到25个像素点*/
    for (int i = 0; i < (COORD_SIZE * COORD_SIZE); i++) {
        point_last[i].x =
            (x / 20 - (COORD_SIZE - 1) / 2) + (int16_t)(i % COORD_SIZE);
        point_last[i].y =
            (y / 20 + (COORD_SIZE - 1) / 2) - (int16_t)(i / COORD_SIZE);
        point_last[i].color = lcd_read_point(point_last[i].x, point_last[i].y);
    }
    /* 设置当前点的颜色 */
    point_draw(x, y, color);
}

/**
 * @brief 用三角形显示轨迹原点
 * 
 * @param x 全场定位x坐标
 * @param y 全场定位y坐标
 * @param angle 全场定位yaw角
 * @param color 颜色 RGB565
 * @note 函数通过COORD_SIZE调整点位大小，点位大小直接影响刷新速度，
 *       点位太大会有时候刷新不及时会出现白屏或其他现象，画下一个点
 *       位之前会将上一个点位自动清除。
 */
void triangle_draw_clean(int16_t x, int16_t y, int16_t angle, uint16_t color) {
    int16_t origin_x = x / 20;
    int16_t origin_y = y / 20;
    if (origin_x < 0 || origin_y < 0) {
        return;
    }
    static point_t
        point_last[((COORD_SIZE + 2) * (COORD_SIZE + 2))]; /* 上一个点 */
    /* 还原上一个点的数据 */
    for (int i = 0; i < ((COORD_SIZE + 2) * (COORD_SIZE + 2)); i++) {

        point_limit(799, 479, &point_last[i].x, &point_last[i].y);
        if ((point_last[i].x == NULL) || (point_last[i].y == NULL)) {
            continue; /* 跳出此次循环 */
        }
        lcd_draw_point(point_last[i].x, point_last[i].y, point_last[i].color);
    }
    /* 存储上一个点的数据,得到像素点*/
    for (int i = 0; i < ((COORD_SIZE + 2) * (COORD_SIZE + 2)); i++) {
        point_last[i].x =
            (x / 20 - (COORD_SIZE + 1) / 2) + (int16_t)(i % (COORD_SIZE + 2));
        point_last[i].y =
            (y / 20 + (COORD_SIZE + 1) / 2) - (int16_t)(i / (COORD_SIZE + 2));
        point_last[i].color = lcd_read_point(point_last[i].x, point_last[i].y);
    }
    /* 画三角形 */
    int16_t point_top_x =
        origin_x - ((COORD_SIZE + 1) / 2) * sinf(DEG2RAD(angle));
    int16_t point_top_y =
        origin_y - ((COORD_SIZE + 1) / 2) * cosf(DEG2RAD(angle));
    int16_t point_left_x =
        origin_x - ((COORD_SIZE + 1) / 2) * sinf(DEG2RAD(45 - angle));
    int16_t point_left_y =
        origin_y + ((COORD_SIZE + 1) / 2) * cosf(DEG2RAD(45 - angle));
    int16_t point_right_x =
        origin_x + ((COORD_SIZE + 1) / 2) * cosf(DEG2RAD(45 - angle));
    int16_t point_right_y =
        origin_y + ((COORD_SIZE + 1) / 2) * sinf(DEG2RAD(45 - angle));

    int16_t point_middler_x = origin_x - 4 * cosf(DEG2RAD(angle));
    int16_t point_middler_y = origin_y + 4 * sinf(DEG2RAD(angle));
    int16_t point_middlel_x = origin_x + 4 * cosf(DEG2RAD(angle));
    int16_t point_middlel_y = origin_y - 4 * sinf(DEG2RAD(angle));

    lcd_draw_triangle(point_top_x, point_top_y, point_left_x, point_left_y,
                      point_right_x, point_right_y, color);
    lcd_draw_triangle(point_top_x, point_top_y, point_middler_x,
                      point_middler_y, point_middlel_x, point_middlel_y,
                      0xfe19);
}

/**
 * @brief 设置顶原点之后的显示函数
 *
 * @param x 全场定位x坐标
 * @param y 全场定位y坐标
 * 
 * @param color 颜色RGB565格式
 * @note 在定原点之后坐标系更改，之后底盘行进过程要使用此函数来打点
 */
void origin_point_draw(int16_t x, int16_t y, int16_t angle, uint16_t color) {
    switch (coonrdingates_offset_data.angle) {
        case 0: /* 向上，y轴取反 */
#if COORD_SHAPE
            triangle_draw_clean(coonrdingates_offset_data.x * 20 + x,
                                coonrdingates_offset_data.y * 20 - y, angle,
                                color);
#else
            point_draw_clean(coonrdingates_offset_data.x * 20 + x,
                             coonrdingates_offset_data.y * 20 - y, color);
#endif
            break;
        case 90: /* 向左，x轴y轴交换并取反 */
#if COORD_SHAPE
            triangle_draw_clean(coonrdingates_offset_data.x * 20 - y,
                                coonrdingates_offset_data.y * 20 - x, angle,
                                color);
#else
            point_draw_clean(coonrdingates_offset_data.x * 20 - y,
                             coonrdingates_offset_data.y * 20 - x, color);
#endif
            break;
        case 180: /* 向下，x轴取反 */
#if COORD_SHAPE
            triangle_draw_clean(coonrdingates_offset_data.x * 20 - x,
                                coonrdingates_offset_data.y * 20 + y, angle,
                                color);

#else
            point_draw_clean(coonrdingates_offset_data.x * 20 - x,
                             coonrdingates_offset_data.y * 20 + y, color);
#endif
            break;
        case 270: /* 向右，x轴y轴交换 */
#if COORD_SHAPE
            triangle_draw_clean(coonrdingates_offset_data.x * 20 + y,
                                coonrdingates_offset_data.y * 20 + x, angle,
                                color);
#else
            point_draw_clean(coonrdingates_offset_data.x * 20 + y,
                             coonrdingates_offset_data.y * 20 + x, color);
#endif
            break;
        default: /* 没设置原点 */
#if COORD_SHAPE
            triangle_draw_clean(coonrdingates_offset_data.x * 20 + x,
                                coonrdingates_offset_data.y * 20 + y, angle,
                                color);
#else
            point_draw_clean(coonrdingates_offset_data.x * 20 + x,
                             coonrdingates_offset_data.y * 20 + y, color);
#endif
            break;
    }
}

/**
 * @brief 画三角形
 * 
 * @param x0 
 * @param y0 
 * @param x1 起点x
 * @param y1 起点y
 * @param x2 终点x
 * @param y2 终点y
 * @param color 颜色
 * @note 以Z轴倾斜着打线。
 */
void lcd_draw_triangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,
                       uint16_t x2, uint16_t y2, uint16_t color) {
    uint16_t xm = 0, ym = 0;
    uint16_t step = 0;

    lcd_draw_line(x0, y0, x1, y1, color); /* 第一条直线 */
    lcd_draw_line(x0, y0, x2, y2, color); /* 第二条直线 */

    if (x2 < x1) /* 如果起点在终点左边，起点终点互换位置，确保从左到右划线 */
    {
        xm = x1;
        x1 = x2;
        x2 = xm;

        ym = y1;
        y1 = y2;
        y2 = ym;
    }
    xm = x1; /* 起点在终点右边 */
    ym = y1;
    lcd_draw_point_limt(xm, ym, 800, 480, color); /* 画起点 */

    if (y2 >= y1) /* 如果斜率为正 */
    {
        step = (y2 - y1) + (x2 - x1); /* 需要移动的总步数 */
        while (step--) {
            /* 如果当前点与终点连线的斜率大于起点与终点的斜率，就减小当前斜率 */
            if ((y2 - ym) * (x2 - x1) > (y2 - y1) * (x2 - xm)) {
                ym++;
            } else {
                xm++;
            }
            lcd_draw_point_limt(xm, ym, 800, 480, color);
            lcd_draw_line(x0, y0, xm, ym, color);
        }
    } else /* 斜率为负将斜率比较取反，判断谁更小 */
    {
        step = (y1 - y2) + (x2 - x1); /* 总步数 */
        while (step--) {
            if ((y2 - ym) * (x2 - x1) < (y2 - y1) * (x2 - xm)) {
                ym--;
            } else {
                xm++;
            }
            lcd_draw_point_limt(xm, ym, 800, 480, color);
            lcd_draw_line(x0, y0, xm, ym, color);
        }
    }
}