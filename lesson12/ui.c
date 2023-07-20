// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.3
// Project name: rgb1

#include "ui.h"
#include "ui_helpers.h"
int flag = 0;
///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel2;
void ui_event_red(lv_event_t * e);
lv_obj_t * ui_red;
void ui_event_blue(lv_event_t * e);
lv_obj_t * ui_blue;
void ui_event_orange(lv_event_t * e);
lv_obj_t * ui_orange;
void ui_event_yellow(lv_event_t * e);
lv_obj_t * ui_yellow;
void ui_event_green(lv_event_t * e);
lv_obj_t * ui_green;
lv_obj_t * ui_Label2;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_audio_wave_[1] = {&ui_img_audio_wave_1_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_red(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        flag = 1;
    }
}
void ui_event_blue(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        flag = 2;
    }
}
void ui_event_orange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        flag = 3;
    }
}
void ui_event_yellow(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        flag = 4;
    }
}
void ui_event_green(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        flag = 5;
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x827D7D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 387);
    lv_obj_set_height(ui_Panel2, 140);
    lv_obj_set_x(ui_Panel2, 3);
    lv_obj_set_y(ui_Panel2, 5);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_red = lv_img_create(ui_Panel2);
    lv_img_set_src(ui_red, &ui_img_red_png);
    lv_obj_set_width(ui_red, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_red, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_red, -142);
    lv_obj_set_y(ui_red, -23);
    lv_obj_set_align(ui_red, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_red, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_red, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_blue = lv_img_create(ui_Panel2);
    lv_img_set_src(ui_blue, &ui_img_blue_png);
    lv_obj_set_width(ui_blue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_blue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_blue, 145);
    lv_obj_set_y(ui_blue, -28);
    lv_obj_set_align(ui_blue, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_blue, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_blue, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_orange = lv_img_create(ui_Panel2);
    lv_img_set_src(ui_orange, &ui_img_orange_png);
    lv_obj_set_width(ui_orange, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_orange, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_orange, 8);
    lv_obj_set_y(ui_orange, -25);
    lv_obj_set_align(ui_orange, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_orange, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_orange, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_yellow = lv_img_create(ui_Panel2);
    lv_img_set_src(ui_yellow, &ui_img_yellow_png);
    lv_obj_set_width(ui_yellow, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_yellow, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_yellow, 87);
    lv_obj_set_y(ui_yellow, 31);
    lv_obj_set_align(ui_yellow, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_yellow, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_yellow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_green = lv_img_create(ui_Panel2);
    lv_img_set_src(ui_green, &ui_img_greend_png);
    lv_obj_set_width(ui_green, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_green, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_green, -67);
    lv_obj_set_y(ui_green, 32);
    lv_obj_set_align(ui_green, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_green, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_green, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -159);
    lv_obj_set_y(ui_Label2, -95);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "RGB LED control");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x18B3F9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_red, ui_event_red, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_blue, ui_event_blue, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_orange, ui_event_orange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_yellow, ui_event_yellow, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_green, ui_event_green, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}