// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_TEM;
extern lv_obj_t * ui_HUM;
extern lv_obj_t * ui_UV;
extern lv_obj_t * ui_AIR;
extern lv_obj_t * ui_FIRE;
extern lv_obj_t * ui_LABLE1;
extern lv_obj_t * ui_YEAR;
extern lv_obj_t * ui_HOUR;
extern lv_obj_t * ui_MIN;
extern lv_obj_t * ui_MON;
extern lv_obj_t * ui_DAY;
extern lv_obj_t * ui_MON2;
extern lv_obj_t * ui_WEEK;
extern lv_obj_t * ui_MON1;
void ui_event_Screen2(lv_event_t * e);
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Screen3;
// extern lv_obj_t * ui_Screen4;
extern lv_obj_t * ui_A;
extern lv_obj_t * ui_B;
extern lv_obj_t * ui_E1;
extern lv_obj_t * ui_C;
extern lv_obj_t * ui_D;
extern lv_obj_t * ui_E2;
extern lv_obj_t * ui_N1;
extern lv_obj_t * ui_N2;
void ui_event_Image2(lv_event_t * e);
extern lv_obj_t * ui_Image2;
void ui_event_Screen2(lv_event_t * e);
extern lv_obj_t * ui_Screen2;
void ui_event_Screen3(lv_event_t * e);
extern lv_obj_t * ui_Screen3;
void ui_event_account(lv_event_t * e);
extern lv_obj_t * ui_account;
void ui_event_password(lv_event_t * e);
extern lv_obj_t * ui_password;
extern lv_obj_t * ui_NAME;
extern lv_obj_t * ui_PASSWORD;
void ui_event_connect(lv_event_t * e);
extern lv_obj_t * ui_connect;
extern lv_obj_t * ui_Label10;
extern lv_obj_t * ui_LOGIN;
extern lv_obj_t * ui_Keyboard1;
extern lv_obj_t * ui_Keyboard2;
extern lv_obj_t * ui_Panel1;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_tip;
extern lv_obj_t * ui_Label8;

void ui_event_Screen4(lv_event_t * e);
extern lv_obj_t * ui_Screen4;
void ui_event_account1(lv_event_t * e);
extern lv_obj_t * ui_account1;
void ui_event_password1(lv_event_t * e);
extern lv_obj_t * ui_password1;
extern lv_obj_t * ui_NAME1;
extern lv_obj_t * ui_PASSWORD1;
void ui_event_connect1(lv_event_t * e);
extern lv_obj_t * ui_connect1;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_LOGIN1;
extern lv_obj_t * ui_Keyboard3;
extern lv_obj_t * ui_Keyboard4;
void ui_event_Image3(lv_event_t * e);
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Panel2;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_tip2;
extern lv_obj_t * ui_Label9;

extern int login_flag;


LV_IMG_DECLARE(ui_img_home8_png);    // assets\home8.png
LV_IMG_DECLARE(ui_img_elecrow_png);    // assets\elecrow.png
LV_IMG_DECLARE(ui_img_wifi5_png); 
LV_IMG_DECLARE(ui_img_back2_png);    // assets\back2.png


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
