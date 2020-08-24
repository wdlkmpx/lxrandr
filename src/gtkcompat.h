/*
 * Copyright (C) 2020, GPL2
 *
 * gtkcompat.h is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#ifndef __GTKCOMPAT_H
#define __GTKCOMPAT_H

#include <gtk/gtk.h>
#include <stdio.h>
#if !defined(GDK_a) || !defined(GDK_KEY_a)
#include <gdk/gdkkeysyms.h>
#endif

// GTK < 3.0
#if ! GTK_CHECK_VERSION (3, 0, 0)
GtkWidget *gtk_box_new (GtkOrientation orientation, gint spacing) ;
GtkWidget *gtk_button_box_new (GtkOrientation orientation);
GtkWidget *gtk_scale_new (GtkOrientation orientation, GtkAdjustment *adjustment);
GtkWidget *gtk_scale_new_with_range (GtkOrientation orientation, gdouble min, gdouble max, gdouble step);
GtkWidget *gtk_separator_new (GtkOrientation orientation);
GtkWidget *gtk_scrollbar_new (GtkOrientation orientation, GtkAdjustment *adjustment);
GtkWidget *gtk_paned_new (GtkOrientation orientation);
#endif


// GTK < 2.24
#if ! GTK_CHECK_VERSION (2, 24, 0)
typedef struct _GtkComboBox GtkComboBoxText;
#define GTK_COMBO_BOX_TEXT(x) GTK_COMBO_BOX(x)
#define GTK_TYPE_COMBO_BOX_TEXT(x) GTK_TYPE_COMBO_BOX(x)
#define gtk_combo_box_text_new() gtk_combo_box_new_text()
#define gtk_combo_box_text_append_text(combo,text) gtk_combo_box_append_text(combo,text)
#define gtk_combo_box_text_insert_text(combox,pos,text) gtk_combo_box_insert_text(combox,pos,text)
#define gtk_combo_box_text_prepend_text(combo,text) gtk_combo_box_prepend_text(combo,text)
#define gtk_combo_box_text_remove(combo,pos) gtk_combo_box_remove_text(combo,pos)
#define gtk_combo_box_text_get_active_text(combo) gtk_combo_box_get_active_text(combo)
#endif


// GTK <= 2.14
#if (GTK_MAJOR_VERSION == 2 && GTK_MINOR_VERSION <= 14)
GtkWidget * gtk_dialog_get_action_area (GtkDialog *dialog);
GtkWidget * gtk_dialog_get_content_area (GtkDialog *dialog);
GdkWindow * gtk_widget_get_window (GtkWidget *widget);
#endif

// KEYS
#ifndef GDK_KEY_a
#	define GDK_KEY_Control_R GDK_Control_R
#	define GDK_KEY_Control_L GDK_Control_L
#	define GDK_KEY_Shift_R GDK_Shift_R
#	define GDK_KEY_Shift_L GDK_Shift_L
#	define GDK_KEY_Alt_R GDK_Alt_R
#	define GDK_KEY_Alt_L GDK_Alt_L
#	define GDK_KEY_Tab GDK_Tab
#	define GDK_KEY_Up GDK_Up
#	define GDK_KEY_space GDK_space
#	define GDK_KEY_Down GDK_Down
#	define GDK_KEY_Return GDK_Return
#	define GDK_KEY_exclam GDK_exclam
#	define GDK_KEY_R GDK_R
#	define GDK_KEY_r GDK_r
#	define GDK_KEY_S GDK_S
#	define GDK_KEY_s GDK_s
#	define GDK_KEY_BackSpace GDK_BackSpace
#	define GDK_KEY_Home GDK_Home
#	define GDK_KEY_End GDK_End
#	define GDK_KEY_Escape GDK_Escape
#	define GDK_KEY_G GDK_G
#	define GDK_KEY_g GDK_g
#	define GDK_KEY_E GDK_E
#	define GDK_KEY_e GDK_e
#endif

#endif
