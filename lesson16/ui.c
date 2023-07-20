// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

int login_flag = 0;
///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_Screen1;
lv_obj_t* ui_TEM;
lv_obj_t* ui_HUM;
lv_obj_t* ui_UV;
lv_obj_t* ui_AIR;
lv_obj_t* ui_FIRE;
lv_obj_t* ui_LABLE1;
lv_obj_t* ui_YEAR;
lv_obj_t* ui_HOUR;
lv_obj_t* ui_MIN;
lv_obj_t* ui_MON;
lv_obj_t* ui_DAY;
lv_obj_t* ui_MON2;
lv_obj_t* ui_WEEK;
lv_obj_t* ui_MON1;
// lv_obj_t * ui_Screen4;

lv_obj_t* ui_A;
lv_obj_t* ui_B;
lv_obj_t* ui_E1;
lv_obj_t* ui_C;
lv_obj_t* ui_D;
lv_obj_t* ui_E2;
lv_obj_t* ui_N1;
lv_obj_t* ui_N2;

void ui_event_Image2(lv_event_t* e);
lv_obj_t* ui_Image2;
void ui_event_Screen2(lv_event_t* e);
lv_obj_t* ui_Screen2;

void ui_event_Screen3(lv_event_t* e);
lv_obj_t* ui_Screen3;
void ui_event_account(lv_event_t* e);
lv_obj_t* ui_account;
void ui_event_password(lv_event_t* e);
lv_obj_t* ui_password;
lv_obj_t* ui_NAME;
lv_obj_t* ui_PASSWORD;
void ui_event_connect(lv_event_t* e);
lv_obj_t* ui_connect;
lv_obj_t* ui_Label10;
lv_obj_t* ui_LOGIN;
lv_obj_t* ui_Keyboard1;
lv_obj_t* ui_Keyboard2;
lv_obj_t* ui_Panel1;
void ui_event_Button2(lv_event_t* e);
lv_obj_t* ui_Button2;
lv_obj_t* ui_Label3;
lv_obj_t* ui_Label6;
lv_obj_t* ui_tip;
lv_obj_t* ui_Label8;

void ui_event_Screen4(lv_event_t* e);
lv_obj_t* ui_Screen4;
void ui_event_account1(lv_event_t* e);
lv_obj_t* ui_account1;
void ui_event_password1(lv_event_t* e);
lv_obj_t* ui_password1;
lv_obj_t* ui_NAME1;
lv_obj_t* ui_PASSWORD1;
void ui_event_connect1(lv_event_t* e);
lv_obj_t* ui_connect1;
lv_obj_t* ui_Label2;
lv_obj_t* ui_LOGIN1;
lv_obj_t* ui_Keyboard3;
lv_obj_t* ui_Keyboard4;
void ui_event_Image3(lv_event_t* e);
lv_obj_t* ui_Image3;
lv_obj_t* ui_Panel2;
void ui_event_Button1(lv_event_t* e);
lv_obj_t* ui_Button1;
lv_obj_t* ui_Label4;
lv_obj_t* ui_Label5;
lv_obj_t* ui_tip2;
lv_obj_t* ui_Label9;
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Image3(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        login_flag = 1;
    }
}
void ui_event_Image2(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen4, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        login_flag = 0;
    }
}
void ui_event_Screen2(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 500);
    }
}
void ui_event_Screen3(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_account(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_password(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_connect(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        login_flag = 1;
    }
}
void ui_event_Screen4(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_account1(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_password1(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_connect1(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        login_flag = 2;
    }
}
void ui_event_Button2(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Panel1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_connect, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Button1(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_connect1, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Panel2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Screen1, &ui_img_home8_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TEM = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_TEM, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TEM, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TEM, 118);
    lv_obj_set_y(ui_TEM, -71);
    lv_obj_set_align(ui_TEM, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TEM, "30");
    lv_obj_set_style_text_font(ui_TEM, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HUM = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_HUM, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HUM, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HUM, 42);
    lv_obj_set_y(ui_HUM, 39);
    lv_obj_set_align(ui_HUM, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HUM, "100");
    lv_obj_set_style_text_font(ui_HUM, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UV = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_UV, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_UV, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_UV, 179);
    lv_obj_set_y(ui_UV, 38);
    lv_obj_set_align(ui_UV, LV_ALIGN_CENTER);
    lv_label_set_text(ui_UV, "0.1");
    lv_obj_set_style_text_font(ui_UV, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AIR = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_AIR, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AIR, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AIR, 44);
    lv_obj_set_y(ui_AIR, 104);
    lv_obj_set_align(ui_AIR, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AIR, "46");
    lv_obj_set_style_text_font(ui_AIR, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FIRE = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_FIRE, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_FIRE, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_FIRE, 183);
    lv_obj_set_y(ui_FIRE, 97);
    lv_obj_set_align(ui_FIRE, LV_ALIGN_CENTER);
    lv_label_set_text(ui_FIRE, "ABnormal");
    lv_obj_set_style_text_font(ui_FIRE, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LABLE1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_LABLE1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LABLE1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LABLE1, -132);
    lv_obj_set_y(ui_LABLE1, -55);
    lv_obj_set_align(ui_LABLE1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LABLE1, ":");
    lv_obj_set_style_text_font(ui_LABLE1, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_YEAR = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_YEAR, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_YEAR, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_YEAR, -162);
    lv_obj_set_y(ui_YEAR, 9);
    lv_obj_set_align(ui_YEAR, LV_ALIGN_CENTER);
    lv_label_set_text(ui_YEAR, "2023");
    lv_obj_set_style_text_font(ui_YEAR, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HOUR = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_HOUR, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HOUR, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HOUR, -176);
    lv_obj_set_y(ui_HOUR, -55);
    lv_obj_set_align(ui_HOUR, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HOUR, "13");
    lv_obj_set_style_text_font(ui_HOUR, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MIN = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_MIN, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MIN, LV_SIZE_CONTENT);    /// 3
    lv_obj_set_x(ui_MIN, -84);
    lv_obj_set_y(ui_MIN, -55);
    lv_obj_set_align(ui_MIN, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MIN, "14");
    lv_obj_set_style_text_font(ui_MIN, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MON = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_MON, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MON, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MON, -123);
    lv_obj_set_y(ui_MON, 9);
    lv_obj_set_align(ui_MON, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MON, "12");
    lv_obj_set_style_text_font(ui_MON, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DAY = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_DAY, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DAY, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DAY, -93);
    lv_obj_set_y(ui_DAY, 9);
    lv_obj_set_align(ui_DAY, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DAY, "30");
    lv_obj_set_style_text_font(ui_DAY, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MON2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_MON2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MON2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MON2, -106);
    lv_obj_set_y(ui_MON2, 9);
    lv_obj_set_align(ui_MON2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MON2, "/");
    lv_obj_set_style_text_font(ui_MON2, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WEEK = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_WEEK, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WEEK, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_WEEK, -132);
    lv_obj_set_y(ui_WEEK, 47);
    lv_obj_set_align(ui_WEEK, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WEEK, "Wednesday");
    lv_obj_set_style_text_font(ui_WEEK, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MON1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_MON1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MON1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MON1, -138);
    lv_obj_set_y(ui_MON1, 9);
    lv_obj_set_align(ui_MON1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MON1, "/");
    lv_obj_set_style_text_font(ui_MON1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_A = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_A, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_A, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_A, -132);
    lv_obj_set_y(ui_A, 90);
    lv_obj_set_align(ui_A, LV_ALIGN_CENTER);
    lv_label_set_text(ui_A, "��");

    ui_B = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_B, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_B, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_B, -94);
    lv_obj_set_y(ui_B, 90);
    lv_obj_set_align(ui_B, LV_ALIGN_CENTER);
    lv_label_set_text(ui_B, "E");

    ui_E1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_E1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_E1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_E1, -150);
    lv_obj_set_y(ui_E1, 90);
    lv_obj_set_align(ui_E1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_E1, "00");

    ui_C = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_C, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_C, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_C, -132);
    lv_obj_set_y(ui_C, 112);
    lv_obj_set_align(ui_C, LV_ALIGN_CENTER);
    lv_label_set_text(ui_C, "��");

    ui_D = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_D, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_D, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_D, -94);
    lv_obj_set_y(ui_D, 112);
    lv_obj_set_align(ui_D, LV_ALIGN_CENTER);
    lv_label_set_text(ui_D, "N");

    ui_E2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_E2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_E2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_E2, -114);
    lv_obj_set_y(ui_E2, 90);
    lv_obj_set_align(ui_E2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_E2, "00");

    ui_N1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_N1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_N1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_N1, -150);
    lv_obj_set_y(ui_N1, 112);
    lv_obj_set_align(ui_N1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_N1, "00");

    ui_N2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_N2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_N2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_N2, -114);
    lv_obj_set_y(ui_N2, 112);
    lv_obj_set_align(ui_N2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_N2, "00");

    ui_Image2 = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Image2, &ui_img_wifi5_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 40
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 40
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Image2, ui_event_Image2, LV_EVENT_ALL, NULL);
}
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Screen2, &ui_img_elecrow_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    //lv_obj_add_event_cb(ui_Screen2, ui_event_Screen2, LV_EVENT_ALL, NULL);

}
void ui_Screen3_screen_init(void)
{
    ui_Screen3 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_account = lv_textarea_create(ui_Screen3);
    lv_obj_set_width(ui_account, 206);
    lv_obj_set_height(ui_account, 44);
    lv_obj_set_x(ui_account, 72);
    lv_obj_set_y(ui_account, -37);
    lv_obj_set_align(ui_account, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_account, 128);
    lv_textarea_set_placeholder_text(ui_account, "name");
    lv_textarea_set_text(ui_account, "elecrow888");

    ui_password = lv_textarea_create(ui_Screen3);
    lv_obj_set_width(ui_password, 206);
    lv_obj_set_height(ui_password, 44);
    lv_obj_set_x(ui_password, 72);
    lv_obj_set_y(ui_password, 23);
    lv_obj_set_align(ui_password, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_password, 128);
    lv_textarea_set_placeholder_text(ui_password, "password");
    lv_textarea_set_text(ui_password, "elecrow2014");

    ui_NAME = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_NAME, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NAME, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_NAME, -97);
    lv_obj_set_y(ui_NAME, -36);
    lv_obj_set_align(ui_NAME, LV_ALIGN_CENTER);
    lv_label_set_text(ui_NAME, "WIFI Name:");
    lv_obj_set_style_text_font(ui_NAME, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PASSWORD = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_PASSWORD, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PASSWORD, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PASSWORD, -114);
    lv_obj_set_y(ui_PASSWORD, 24);
    lv_obj_set_align(ui_PASSWORD, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PASSWORD, "WIFI Password:");
    lv_obj_set_style_text_font(ui_PASSWORD, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_connect = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_connect, 111);
    lv_obj_set_height(ui_connect, 41);
    lv_obj_set_x(ui_connect, 0);
    lv_obj_set_y(ui_connect, 85);
    lv_obj_set_align(ui_connect, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_connect, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_connect, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_connect, lv_color_hex(0xE5B71D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_connect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Label10 = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, 0);
    lv_obj_set_y(ui_Label10, -124);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "Log in");
    lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LOGIN = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_LOGIN, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LOGIN, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LOGIN, 0);
    lv_obj_set_y(ui_LOGIN, 86);
    lv_obj_set_align(ui_LOGIN, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LOGIN, "login");
    lv_obj_set_style_text_color(ui_LOGIN, lv_color_hex(0xFDFDFD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LOGIN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LOGIN, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Keyboard1 = lv_keyboard_create(ui_Screen3);
    lv_obj_set_width(ui_Keyboard1, 477);
    lv_obj_set_height(ui_Keyboard1, 121);
    lv_obj_set_x(ui_Keyboard1, 0);
    lv_obj_set_y(ui_Keyboard1, 96);
    lv_obj_set_align(ui_Keyboard1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_Keyboard2 = lv_keyboard_create(ui_Screen3);
    lv_obj_set_width(ui_Keyboard2, 477);
    lv_obj_set_height(ui_Keyboard2, 121);
    lv_obj_set_x(ui_Keyboard2, 0);
    lv_obj_set_y(ui_Keyboard2, 96);
    lv_obj_set_align(ui_Keyboard2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_Panel1 = lv_obj_create(ui_Screen3);
    lv_obj_set_width(ui_Panel1, 205);
    lv_obj_set_height(ui_Panel1, 76);
    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, -6);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Panel1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button2 = lv_btn_create(ui_Panel1);
    lv_obj_set_width(ui_Button2, 64);
    lv_obj_set_height(ui_Button2, 26);
    lv_obj_set_x(ui_Button2, -1);
    lv_obj_set_y(ui_Button2, 22);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label3 = lv_label_create(ui_Button2);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, -1);
    lv_obj_set_y(ui_Label3, 1);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Close");

    ui_Label6 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, 1);
    lv_obj_set_y(ui_Label6, -9);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "WIFI connection failed!");

    ui_tip = lv_obj_create(ui_Screen3);
    lv_obj_set_width(ui_tip, 205);
    lv_obj_set_height(ui_tip, 76);
    lv_obj_set_x(ui_tip, 0);
    lv_obj_set_y(ui_tip, -6);
    lv_obj_set_align(ui_tip, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_tip, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_tip, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label8 = lv_label_create(ui_tip);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "Fetching weather...");

    lv_obj_add_event_cb(ui_account, ui_event_account, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_password, ui_event_password, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_connect, ui_event_connect, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_Keyboard1, ui_account);
    lv_keyboard_set_textarea(ui_Keyboard2, ui_password);
    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen3, ui_event_Screen3, LV_EVENT_ALL, NULL);

}

void ui_Screen4_screen_init(void)
{
    ui_Screen4 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_account1 = lv_textarea_create(ui_Screen4);
    lv_obj_set_width(ui_account1, 206);
    lv_obj_set_height(ui_account1, 44);
    lv_obj_set_x(ui_account1, 72);
    lv_obj_set_y(ui_account1, -37);
    lv_obj_set_align(ui_account1, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_account1, 128);
    lv_textarea_set_placeholder_text(ui_account1, "name");

    ui_password1 = lv_textarea_create(ui_Screen4);
    lv_obj_set_width(ui_password1, 206);
    lv_obj_set_height(ui_password1, 44);
    lv_obj_set_x(ui_password1, 72);
    lv_obj_set_y(ui_password1, 23);
    lv_obj_set_align(ui_password1, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_password1, 128);
    lv_textarea_set_placeholder_text(ui_password1, "password");

    ui_NAME1 = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_NAME1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NAME1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_NAME1, -97);
    lv_obj_set_y(ui_NAME1, -36);
    lv_obj_set_align(ui_NAME1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_NAME1, "WIFI Name:");
    lv_obj_set_style_text_font(ui_NAME1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PASSWORD1 = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_PASSWORD1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PASSWORD1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PASSWORD1, -114);
    lv_obj_set_y(ui_PASSWORD1, 24);
    lv_obj_set_align(ui_PASSWORD1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PASSWORD1, "WIFI Password:");
    lv_obj_set_style_text_font(ui_PASSWORD1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_connect1 = lv_btn_create(ui_Screen4);
    lv_obj_set_width(ui_connect1, 111);
    lv_obj_set_height(ui_connect1, 41);
    lv_obj_set_x(ui_connect1, 0);
    lv_obj_set_y(ui_connect1, 85);
    lv_obj_set_align(ui_connect1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_connect1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_connect1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_connect1, lv_color_hex(0xE5B71D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_connect1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Label2 = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 0);
    lv_obj_set_y(ui_Label2, -124);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Log in");
    lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LOGIN1 = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_LOGIN1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LOGIN1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LOGIN1, 0);
    lv_obj_set_y(ui_LOGIN1, 86);
    lv_obj_set_align(ui_LOGIN1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LOGIN1, "login");
    lv_obj_set_style_text_color(ui_LOGIN1, lv_color_hex(0xFDFDFD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LOGIN1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LOGIN1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Keyboard3 = lv_keyboard_create(ui_Screen4);
    lv_obj_set_width(ui_Keyboard3, 477);
    lv_obj_set_height(ui_Keyboard3, 121);
    lv_obj_set_x(ui_Keyboard3, 0);
    lv_obj_set_y(ui_Keyboard3, 96);
    lv_obj_set_align(ui_Keyboard3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Keyboard3, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_Keyboard4 = lv_keyboard_create(ui_Screen4);
    lv_obj_set_width(ui_Keyboard4, 477);
    lv_obj_set_height(ui_Keyboard4, 121);
    lv_obj_set_x(ui_Keyboard4, 0);
    lv_obj_set_y(ui_Keyboard4, 96);
    lv_obj_set_align(ui_Keyboard4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Keyboard4, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_Image3 = lv_img_create(ui_Screen4);
    lv_img_set_src(ui_Image3, &ui_img_back2_png);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 40
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 40
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Image3, ui_event_Image3, LV_EVENT_ALL, NULL);

    ui_Panel2 = lv_obj_create(ui_Screen4);
    lv_obj_set_width(ui_Panel2, 205);
    lv_obj_set_height(ui_Panel2, 76);
    lv_obj_set_x(ui_Panel2, 0);
    lv_obj_set_y(ui_Panel2, -6);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Panel2, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button1 = lv_btn_create(ui_Panel2);
    lv_obj_set_width(ui_Button1, 64);
    lv_obj_set_height(ui_Button1, 26);
    lv_obj_set_x(ui_Button1, -1);
    lv_obj_set_y(ui_Button1, 22);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label4 = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, -1);
    lv_obj_set_y(ui_Label4, 1);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Close");

    ui_Label5 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, 1);
    lv_obj_set_y(ui_Label5, -9);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "WIFI connection failed!");

    ui_tip2 = lv_obj_create(ui_Screen4);
    lv_obj_set_width(ui_tip2, 205);
    lv_obj_set_height(ui_tip2, 76);
    lv_obj_set_x(ui_tip2, 0);
    lv_obj_set_y(ui_tip2, -6);
    lv_obj_set_align(ui_tip2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_tip2, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_tip2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label9 = lv_label_create(ui_tip2);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "Fetching weather...");

    lv_obj_add_event_cb(ui_account1, ui_event_account1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_password1, ui_event_password1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_connect1, ui_event_connect1, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_Keyboard3, ui_account1);
    lv_keyboard_set_textarea(ui_Keyboard4, ui_password1);
    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen4, ui_event_Screen4, LV_EVENT_ALL, NULL);

}
void ui_init(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
        false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    ui_Screen3_screen_init();
    ui_Screen4_screen_init();
    lv_disp_load_scr(ui_Screen2);
}
