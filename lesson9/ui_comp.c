// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: chart


#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

uint32_t LV_EVENT_GET_COMP_CHILD;

typedef struct {
    uint32_t child_idx;
    lv_obj_t * child;
} ui_comp_get_child_t;

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx)
{
    ui_comp_get_child_t info;
    info.child = NULL;
    info.child_idx = child_idx;
    lv_event_send(comp, LV_EVENT_GET_COMP_CHILD, &info);
    return info.child;
}

void get_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    ui_comp_get_child_t * info = lv_event_get_param(e);
    info->child = c[info->child_idx];
}

void del_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    lv_mem_free(c);
}


// COMPONENT Button2

lv_obj_t * ui_Button2_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Button2;
    cui_Button2 = lv_btn_create(comp_parent);
    lv_obj_set_width(cui_Button2, 100);
    lv_obj_set_height(cui_Button2, 50);
    lv_obj_set_x(cui_Button2, 4);
    lv_obj_set_y(cui_Button2, 32);
    lv_obj_set_align(cui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BUTTON2_NUM);
    children[UI_COMP_BUTTON2_BUTTON2] = cui_Button2;
    lv_obj_add_event_cb(cui_Button2, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Button2, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Button2_create_hook(cui_Button2);
    return cui_Button2;
}

