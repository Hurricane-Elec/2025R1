/**
 * @file mygui.h
 * @author ash
 * @brief gui程序
 * @version 0.1
 * @date 2025-03-10
 * 
 */

#ifndef _MYGUI_H
#define _MYGUI_H

#include <lvgl/lvgl.h>

LV_FONT_DECLARE(simhei_22)  /* 字模高度48 */
LV_FONT_DECLARE(simhei_12) /* 字模高度27 */
LV_FONT_DECLARE(simhei_16) /* 字模高度35 */
LV_FONT_DECLARE(my_fontawesom_world)
LV_FONT_DECLARE(my_fontawesom_itself)
LV_FONT_DECLARE(my_fontawesom_signal)

#define MY_SYMBOL_WORLD     "\xef\x95\xbd"
#define MY_SYMBOL_ITSELF    "\xef\x80\x87"
#define MY_SYMBOL_NOLINK    "\xef\x84\xa7"

/* 部件结构体，将需要使用的部件添加进此结构体 */
typedef struct _objects_t {
    lv_obj_t *images_backgrand;
    lv_obj_t *lable_1;
    lv_obj_t *canvas_1;
    /* 摇杆部件 */
    lv_obj_t *lvble_rs_l_const;
    lv_obj_t *lvble_rs_r_const;
    lv_obj_t *lvble_rs_l_x;
    lv_obj_t *lvble_rs_l_y;
    lv_obj_t *lvble_rs_r_x;
    lv_obj_t *lvble_rs_r_y;

    lv_obj_t *lvbar_rs_r_x;
    lv_obj_t *lvbar_rs_r_y;
    lv_obj_t *lvbar_rs_l_x;
    lv_obj_t *lvbar_rs_l_y;
    /* 角度标签 */
    lv_obj_t *lvble_angle_const;
    lv_obj_t *lvble_angle_number;
    /* 位置标签 */
    lv_obj_t *lvble_p_const;
    lv_obj_t *lvble_p_x;
    lv_obj_t *lvble_p_y;
    /* 选项卡界面 */
    lv_obj_t *tab_1;
    lv_obj_t *tab_2;
    lv_obj_t *tabview;
    /* 原点开始提示标签 */
    lv_obj_t *remain_txt_1;
    lv_obj_t *remain_txt_2;
    /* 其他指示标签 */
    lv_obj_t *lvble_key_const;
    lv_obj_t *lvble_key_number;
    lv_obj_t *lvble_auto_focus;
    lv_obj_t *lvble_coordinate_world;
    lv_obj_t *lvble_coordinate_itself;
    lv_obj_t *lvble_battery;
    lv_obj_t *lvble_nrfsignal;
} objects_t;

/**
 * @brief 字体尺寸
 * 
 */
typedef enum {
    LV_SIMHEI_12 = 0x01,
    LV_SIMHEI_16,
    LV_SIMHEI_22
} lv_simhei_t;

extern objects_t objects;

lv_obj_t *create_Fontlable(lv_simhei_t lv_simhei_size, const char *str,
                           lv_obj_t *parent, int16_t offset_x, int16_t offset_y,
                           uint32_t color);
void create_messagelable(void);
void create_tabview(void);

#endif // !_MUGUI_H
