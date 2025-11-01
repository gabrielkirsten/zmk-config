/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr.h>
#include <zmk/widgets/battery_status.h>
#include <zmk/widgets/layer_status.h>
#include <zmk/widgets/output_status.h>
#include <zmk/widgets/wpm_status.h>
#include <zmk/display/status_screen.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
static struct zmk_widget_battery_status battery_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
static struct zmk_widget_output_status output_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
static struct zmk_widget_layer_status layer_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_WPM_STATUS)
static struct zmk_widget_wpm_status wpm_status_widget;
#endif

lv_style_t style;

static void set_style(lv_obj_t *widget) {
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_black());
    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_border_width(&style, 0);
    lv_obj_add_style(widget, &style, LV_PART_MAIN);
}

zmk_widget_status_screen();

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
zmk_widget_init(widget_battery_status, &battery_status_widget);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
zmk_widget_init(widget_output_status, &output_status_widget);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
zmk_widget_init(widget_layer_status, &layer_status_widget);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_WPM_STATUS)
zmk_widget_init(widget_wpm_status, &wpm_status_widget);
#endif

