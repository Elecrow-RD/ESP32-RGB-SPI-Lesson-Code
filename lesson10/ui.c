// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: Print

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label7;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label8;
void ui_event_Slider2(lv_event_t * e);
lv_obj_t * ui_Slider2;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Button3;
lv_obj_t * ui_Button4;
lv_obj_t * ui_Screen2;
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
lv_obj_t * ui_Label6;
void ui_event_Button6(lv_event_t * e);
lv_obj_t * ui_Button6;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Roller1;
lv_obj_t * ui_Switch2;
lv_obj_t * ui_Switch1;
lv_obj_t * ui_Label11;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Label10;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_[5] = {&ui_img_1_png, &ui_img_2_png, &ui_img_5_png, &ui_img_16_png, &ui_img_17_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Slider2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_Label2, target, "", "%");
    }
}
void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0xA5ABB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button2, 56);
    lv_obj_set_height(ui_Button2, 123);
    lv_obj_set_x(ui_Button2, -192);
    lv_obj_set_y(ui_Button2, -77);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0x878080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_Button2);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "PRINT");
    lv_obj_set_style_text_font(ui_Label7, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button1, 56);
    lv_obj_set_height(ui_Button1, 128);
    lv_obj_set_x(ui_Button1, -193);
    lv_obj_set_y(ui_Button1, 75);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x878080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "SETTING");
    lv_obj_set_style_text_font(ui_Label8, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Slider2 = lv_slider_create(ui_Screen1);
    lv_obj_set_width(ui_Slider2, 125);
    lv_obj_set_height(ui_Slider2, 233);
    lv_obj_set_x(ui_Slider2, -65);
    lv_obj_set_y(ui_Slider2, -2);
    lv_obj_set_align(ui_Slider2, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_Slider2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Slider2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Slider2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider2, &ui_img_5_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider2, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 111, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Slider2, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Slider2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Slider2);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 0);
    lv_obj_set_y(ui_Label2, 77);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "23%");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xE2F90F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Label2, lv_color_hex(0x418F1C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Label2, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 170);
    lv_obj_set_height(ui_Panel2, 81);
    lv_obj_set_x(ui_Panel2, 120);
    lv_obj_set_y(ui_Panel2, -63);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x474444), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, -38);
    lv_obj_set_y(ui_Label3, -17);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Printing Time");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFDFAFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, 41);
    lv_obj_set_y(ui_Label1, -16);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Temp");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFDFAFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 42);
    lv_obj_set_y(ui_Label4, 20);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "195°");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0xFDFAFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, -41);
    lv_obj_set_y(ui_Label5, 20);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "10:52");
    lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0xFDFAFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button3, 62);
    lv_obj_set_height(ui_Button3, 67);
    lv_obj_set_x(ui_Button3, 163);
    lv_obj_set_y(ui_Button3, 83);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button3, &ui_img_17_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button4 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button4, 62);
    lv_obj_set_height(ui_Button4, 67);
    lv_obj_set_x(ui_Button4, 76);
    lv_obj_set_y(ui_Button4, 85);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button4, &ui_img_16_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Button4, lv_color_hex(0xDA9595), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Button4, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Button4, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_x(ui_Button4, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_y(ui_Button4, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Slider2, ui_event_Slider2, LV_EVENT_ALL, NULL);

}
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0xA5ABB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button5 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button5, 56);
    lv_obj_set_height(ui_Button5, 123);
    lv_obj_set_x(ui_Button5, -192);
    lv_obj_set_y(ui_Button5, -77);
    lv_obj_set_align(ui_Button5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button5, lv_color_hex(0x878080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_Button5);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "PRINT");
    lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button6 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button6, 56);
    lv_obj_set_height(ui_Button6, 128);
    lv_obj_set_x(ui_Button6, -193);
    lv_obj_set_y(ui_Button6, 75);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x878080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_Button6);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "SETTING");
    lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel3, 72);
    lv_obj_set_height(ui_Panel3, 103);
    lv_obj_set_x(ui_Panel3, -38);
    lv_obj_set_y(ui_Panel3, -52);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0xA19595), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller2 = lv_roller_create(ui_Panel3);
    lv_roller_set_options(ui_Roller2, "230\n220\n210\n200\n190\n180\n170", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller2, 100);
    lv_obj_set_width(ui_Roller2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Roller2, lv_color_hex(0xA19595), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Roller2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel1, 72);
    lv_obj_set_height(ui_Panel1, 103);
    lv_obj_set_x(ui_Panel1, 70);
    lv_obj_set_y(ui_Panel1, -52);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xA19595), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller1 = lv_roller_create(ui_Panel1);
    lv_roller_set_options(ui_Roller1, "PLA\nPETC\nABS", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_Roller1, 100);
    lv_obj_set_width(ui_Roller1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Roller1, lv_color_hex(0xA19595), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Roller1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Switch2 = lv_switch_create(ui_Screen2);
    lv_obj_set_width(ui_Switch2, 50);
    lv_obj_set_height(ui_Switch2, 25);
    lv_obj_set_x(ui_Switch2, -43);
    lv_obj_set_y(ui_Switch2, 91);
    lv_obj_set_align(ui_Switch2, LV_ALIGN_CENTER);

    ui_Switch1 = lv_switch_create(ui_Screen2);
    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);
    lv_obj_set_x(ui_Switch1, 80);
    lv_obj_set_y(ui_Switch1, 90);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);

    ui_Label11 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, -46);
    lv_obj_set_y(ui_Label11, 13);
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "TEMP");

    ui_Label12 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, 73);
    lv_obj_set_y(ui_Label12, 13);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "materials");

    ui_Label13 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, -42);
    lv_obj_set_y(ui_Label13, 116);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "FAN 1");

    ui_Label10 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, 80);
    lv_obj_set_y(ui_Label10, 116);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "FAN 2");

    lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
