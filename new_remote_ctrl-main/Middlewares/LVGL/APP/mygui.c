/**
 * @file mygui.c
 * @author ash
 * @brief gui程序
 * @version 0.1
 * @date 2025-03-10
 * 
 */

#include <string.h>

#include "key/key.h"
#include "lcd/lcd.h"
#include "mygui.h"

objects_t objects; /* 部件结构体 */

/**
 * @brief 创建一个22号字体的中文字体标签部件
 * 
 * @param str 标签文本
 * @param parent 父对象
 * @param offset_x 相对于父对象的坐标偏移
 * @param offset_y 
 * @param color 字体颜色
 * @note    要在初始界面显示的文字建议在选项卡界面一块创建，
 *          
 * @return lv_obj_t* 
 */
lv_obj_t *create_Fontlable(lv_simhei_t lv_simhei_size, const char *str,
                           lv_obj_t *parent, int16_t offset_x, int16_t offset_y,
                           uint32_t color) {
    lv_obj_t *lable = lv_label_create(parent);
    switch (lv_simhei_size) {
        case LV_SIMHEI_12:
            lv_obj_set_style_text_font(lable, &simhei_12, 0);
            break;
        case LV_SIMHEI_16:
            lv_obj_set_style_text_font(lable, &simhei_16, 0);
            break;
        case LV_SIMHEI_22:
            lv_obj_set_style_text_font(lable, &simhei_22, 0);
            break;
        default:
            return NULL; /* 选择字体错误直接退出 */
            break;
    }
    lv_label_set_text(lable, str);
    lv_obj_align(lable, LV_ALIGN_CENTER, offset_x, offset_y);
    lv_obj_set_style_text_color(lable, lv_color_hex(color), LV_STATE_DEFAULT);
    return lable;
}

/**
 * @brief 创建屏幕对象部件
 * @note 在这里创建以lv_src_act为父对象的部件。
 * @note 字体按照80个像素计算，同时速度和位置以m为单位，角度以°为单位。
 */
void create_messagelable(void) {
    /* 背景 */
    lv_obj_t *box_back = lv_obj_create(objects.tab_1);
    lv_obj_set_size(box_back, 745, 75);
    lv_obj_align(box_back, LV_ALIGN_TOP_RIGHT, 20, -18);
    lv_obj_set_style_bg_color(box_back, lv_color_hex(0x4bf0b3),
                              LV_STATE_DEFAULT);
    /* 摇杆部件 */
    objects.lvble_rs_l_const = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(objects.lvble_rs_l_const, &simhei_12, 0);
    lv_label_set_text(objects.lvble_rs_l_const, "左\n摇\n杆");
    lv_obj_align(objects.lvble_rs_l_const, LV_ALIGN_TOP_LEFT, 60, 0);

    objects.lvble_rs_r_const = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(objects.lvble_rs_r_const, &simhei_12, 0);
    lv_label_set_text(objects.lvble_rs_r_const, "右\n摇\n杆");
    lv_obj_align(objects.lvble_rs_r_const, LV_ALIGN_TOP_LEFT, 650, 0);

    objects.lvbar_rs_l_x = lv_bar_create(lv_scr_act());
    lv_obj_set_size(objects.lvbar_rs_l_x, 120, 25);
    lv_obj_align(objects.lvbar_rs_l_x, LV_ALIGN_TOP_LEFT, 90, 7);
    lv_bar_set_range(objects.lvbar_rs_l_x, -20, 19);
    lv_obj_set_style_bg_color(objects.lvbar_rs_l_x, lv_color_hex(0x5345),
                              LV_PART_MAIN); /* 背景 */
    lv_obj_set_style_bg_color(objects.lvbar_rs_l_x, lv_color_hex(0xFFFE),
                              LV_PART_INDICATOR); /* 指示器 */

    objects.lvbar_rs_l_y = lv_bar_create(lv_scr_act());
    lv_obj_set_size(objects.lvbar_rs_l_y, 120, 25);
    lv_obj_align(objects.lvbar_rs_l_y, LV_ALIGN_TOP_LEFT, 90, 40);
    lv_bar_set_range(objects.lvbar_rs_l_y, -20, 19);
    lv_obj_set_style_bg_color(objects.lvbar_rs_l_y, lv_color_hex(0x5345),
                              LV_PART_MAIN); /* 背景 */
    lv_obj_set_style_bg_color(objects.lvbar_rs_l_y, lv_color_hex(0xFFFE),
                              LV_PART_INDICATOR); /* 指示器 */

    objects.lvbar_rs_r_x = lv_bar_create(lv_scr_act());
    lv_obj_set_size(objects.lvbar_rs_r_x, 120, 25);
    lv_obj_align(objects.lvbar_rs_r_x, LV_ALIGN_TOP_LEFT, 677, 7);
    lv_bar_set_range(objects.lvbar_rs_r_x, -20, 19);
    lv_obj_set_style_bg_color(objects.lvbar_rs_r_x, lv_color_hex(0x5345),
                              LV_PART_MAIN); /* 背景 */
    lv_obj_set_style_bg_color(objects.lvbar_rs_r_x, lv_color_hex(0xFFFE),
                              LV_PART_INDICATOR); /* 指示器 */

    objects.lvbar_rs_r_y = lv_bar_create(lv_scr_act());
    lv_obj_set_size(objects.lvbar_rs_r_y, 120, 25);
    lv_obj_align(objects.lvbar_rs_r_y, LV_ALIGN_TOP_LEFT, 677, 40);
    lv_bar_set_range(objects.lvbar_rs_r_y, -20, 19);
    lv_obj_set_style_bg_color(objects.lvbar_rs_r_y, lv_color_hex(0x5345),
                              LV_PART_MAIN); /* 背景 */
    lv_obj_set_style_bg_color(objects.lvbar_rs_r_y, lv_color_hex(0xFFFE),
                              LV_PART_INDICATOR); /* 指示器 */

    objects.lvble_rs_l_x = lv_label_create(objects.lvbar_rs_l_x);
    lv_label_set_text_fmt(objects.lvble_rs_l_x, "0");
    lv_obj_align(objects.lvble_rs_l_x, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(objects.lvble_rs_l_x, &lv_font_montserrat_18,
                               LV_STATE_DEFAULT);

    objects.lvble_rs_l_y = lv_label_create(objects.lvbar_rs_l_y);
    lv_label_set_text_fmt(objects.lvble_rs_l_y, "0");
    lv_obj_align(objects.lvble_rs_l_y, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(objects.lvble_rs_l_y, &lv_font_montserrat_18,
                               LV_STATE_DEFAULT);

    objects.lvble_rs_r_x = lv_label_create(objects.lvbar_rs_r_x);
    lv_label_set_text_fmt(objects.lvble_rs_r_x, "0");
    lv_obj_align(objects.lvble_rs_r_x, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(objects.lvble_rs_r_x, &lv_font_montserrat_18,
                               LV_STATE_DEFAULT);

    objects.lvble_rs_r_y = lv_label_create(objects.lvbar_rs_r_y);
    lv_label_set_text_fmt(objects.lvble_rs_r_y, "0");
    lv_obj_align(objects.lvble_rs_r_y, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(objects.lvble_rs_r_y, &lv_font_montserrat_18,
                               LV_STATE_DEFAULT);

    /* 角度标签部件 */
    objects.lvble_angle_const = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(objects.lvble_angle_const, &simhei_12, 0);
    lv_label_set_text(objects.lvble_angle_const, "yaw角= ");
    lv_obj_align(objects.lvble_angle_const, LV_ALIGN_TOP_LEFT, 220, 40);

    objects.lvble_angle_number = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(objects.lvble_angle_number, "%d °", 0);
    lv_obj_set_style_text_font(objects.lvble_angle_number,
                               &lv_font_montserrat_22, LV_STATE_DEFAULT);
    lv_obj_align(objects.lvble_angle_number, LV_ALIGN_TOP_LEFT, 300, 42);

    /* 位置标签部件 */
    objects.lvble_p_const = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(objects.lvble_p_const, &simhei_12, 0);
    lv_label_set_text(objects.lvble_p_const, "位置");
    lv_obj_align(objects.lvble_p_const, LV_ALIGN_TOP_LEFT, 220, 15);

    objects.lvble_p_x = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(objects.lvble_p_x, "x = %.1f cm", 0.0f);
    lv_obj_set_style_text_font(objects.lvble_p_x, &lv_font_montserrat_22,
                               LV_STATE_DEFAULT);
    lv_obj_align(objects.lvble_p_x, LV_ALIGN_TOP_LEFT, 270, 15);
    objects.lvble_p_y = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(objects.lvble_p_y, "y = %.1f cm", 0.0f);
    lv_obj_set_style_text_font(objects.lvble_p_y, &lv_font_montserrat_22,
                               LV_STATE_DEFAULT);
    lv_obj_align(objects.lvble_p_y, LV_ALIGN_TOP_LEFT, 420, 15);

    /* 电量监测标签 */
    objects.lvble_battery = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(objects.lvble_battery, &lv_font_montserrat_26,
                               LV_STATE_DEFAULT);
    lv_label_set_text(objects.lvble_battery, LV_SYMBOL_BATTERY_EMPTY);
    lv_obj_align(objects.lvble_battery, LV_ALIGN_TOP_LEFT, 570, 8);

    /* NRF部件 */
    objects.lvble_nrfsignal = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(objects.lvble_nrfsignal, &my_fontawesom_signal,
                               LV_STATE_DEFAULT);
    lv_label_set_text(objects.lvble_nrfsignal, MY_SYMBOL_NOLINK);
    lv_obj_align(objects.lvble_nrfsignal, LV_ALIGN_TOP_LEFT, 570, 40);
    lv_obj_add_flag(objects.lvble_nrfsignal, LV_OBJ_FLAG_HIDDEN); /* 隐藏部件 */

    /* 按键部件 */
    objects.lvble_key_const =
        create_Fontlable(LV_SIMHEI_16, "按键", lv_scr_act(), 80, -180, BLACK);
    objects.lvble_key_number = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(objects.lvble_key_number, "0");
    lv_obj_set_style_text_font(objects.lvble_key_number, &lv_font_montserrat_28,
                               LV_STATE_DEFAULT);
    lv_obj_align(objects.lvble_key_number, LV_ALIGN_TOP_LEFT, 520, 46);
}

/**
 * @brief Create a 选项卡部件
 * 
 * @note 底盘选项卡编号是 0 抛射选项卡编号是 1
 * @note 在这里创建每个选项卡特有的部件
 */
void create_tabview(void) {
    objects.tabview = lv_tabview_create(lv_scr_act(), LV_DIR_LEFT, 49);
    lv_obj_set_style_text_font(objects.tabview, &simhei_22, 0);
    /* 添加选项卡 */
    objects.tab_1 =
        lv_tabview_add_tab(objects.tabview, "底盘"); /* 添加选项卡0 */
    objects.tab_2 =
        lv_tabview_add_tab(objects.tabview, "抛射"); /* 添加选项卡1 */

    /* 添加选项卡内容 */
    objects.images_backgrand = lv_img_create(objects.tab_1);
    lv_img_set_src(objects.images_backgrand, "0:/images/img_tes_2.bin");
    lv_obj_align(objects.images_backgrand, LV_ALIGN_RIGHT_MID, 20, 38);
    create_messagelable();

    /* 自瞄图标字库显示 */
    objects.lvble_auto_focus = lv_label_create(objects.images_backgrand);
    lv_obj_set_style_text_font(objects.lvble_auto_focus, &lv_font_montserrat_26,
                               LV_STATE_DEFAULT);
    lv_label_set_text(objects.lvble_auto_focus, LV_SYMBOL_EYE_CLOSE);
    lv_obj_align(objects.lvble_auto_focus, LV_ALIGN_CENTER, 345, -180);

    /* 坐标系标签 */
    objects.lvble_coordinate_world = lv_label_create(objects.images_backgrand);
    lv_obj_set_style_text_font(objects.lvble_coordinate_world,
                               &my_fontawesom_world, LV_STATE_DEFAULT);
    lv_label_set_text(objects.lvble_coordinate_world, MY_SYMBOL_WORLD);
    lv_obj_align(objects.lvble_coordinate_world, LV_ALIGN_CENTER, 300, -180);
    lv_obj_add_flag(objects.lvble_coordinate_world, LV_OBJ_FLAG_HIDDEN);

    objects.lvble_coordinate_itself = lv_label_create(objects.images_backgrand);
    lv_obj_set_style_text_font(objects.lvble_coordinate_itself,
                               &my_fontawesom_itself, LV_STATE_DEFAULT);
    lv_label_set_text(objects.lvble_coordinate_itself, MY_SYMBOL_ITSELF);
    lv_obj_align(objects.lvble_coordinate_itself, LV_ALIGN_CENTER, 300, -180);

    lv_obj_t *box_back = lv_obj_create(objects.tab_2);
    lv_obj_set_size(box_back, 745, 75);
    lv_obj_align(box_back, LV_ALIGN_TOP_RIGHT, 20, -18);
    lv_obj_set_style_bg_color(box_back, lv_color_hex(0xffeaea),
                              LV_STATE_DEFAULT);

    lv_obj_t *box_real = lv_obj_create(objects.tab_2);
    lv_obj_set_size(box_real, 350, 380);
    lv_obj_align(box_real, LV_ALIGN_BOTTOM_MID, -185, 0);

    lv_obj_t *box_measure = lv_obj_create(objects.tab_2);
    lv_obj_set_size(box_measure, 350, 380);
    lv_obj_align(box_measure, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_tabview_set_act(objects.tabview, 0, LV_ANIM_OFF);
}
