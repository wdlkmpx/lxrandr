/*
 * Copyright (C) 2020, GPL2
 *
 * gtkcompat.c is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#include "gtkcompat.h"

/* ================================================== */
/*                   GTK < 3.0                        */
/* ================================================== */

#if ! GTK_CHECK_VERSION (3, 0, 0)

GtkWidget *
gtk_box_new (GtkOrientation orientation, gint spacing)
{
	// the HOMOGENEOUS property defaults to FALSE
	// add this to make it TRUE
	//   gtk_box_set_homogeneous (GTK_BOX(hbox), TRUE);
	if (orientation == GTK_ORIENTATION_HORIZONTAL) {
		return gtk_hbox_new (FALSE, spacing);
	}
	if (orientation == GTK_ORIENTATION_VERTICAL) {
		return gtk_vbox_new (FALSE, spacing);
	}
	return NULL;
}

GtkWidget *
gtk_button_box_new (GtkOrientation orientation)
{
	if (orientation == GTK_ORIENTATION_HORIZONTAL) {
		return gtk_hbutton_box_new ();
	}
	if (orientation == GTK_ORIENTATION_VERTICAL) {
		return gtk_vbutton_box_new ();
	}
	return NULL;
}

GtkWidget *
gtk_scale_new (GtkOrientation orientation, GtkAdjustment *adjustment)
{
	if (orientation == GTK_ORIENTATION_HORIZONTAL) {
		return gtk_hscale_new (adjustment);
	}
	if (orientation == GTK_ORIENTATION_VERTICAL) {
		return gtk_vscale_new (adjustment);
	}
	return NULL;
}

GtkWidget *
gtk_scale_new_with_range (GtkOrientation orientation,
                          gdouble min,
                          gdouble max,
                          gdouble step)
{
	if (orientation == GTK_ORIENTATION_HORIZONTAL) {
		return gtk_hscale_new_with_range (min, max, step);
	}
	if (orientation == GTK_ORIENTATION_VERTICAL) {
		return gtk_vscale_new_with_range (min, max, step);
	}
	return NULL;
}

GtkWidget *
gtk_separator_new (GtkOrientation orientation)
{
	if (orientation == GTK_ORIENTATION_HORIZONTAL) {
		return gtk_hseparator_new ();
	}
	if (orientation == GTK_ORIENTATION_VERTICAL) {
		return gtk_vseparator_new ();
	}
	return NULL;
}

GtkWidget *
gtk_scrollbar_new (GtkOrientation orientation, GtkAdjustment *adjustment)
{
	if (orientation == GTK_ORIENTATION_HORIZONTAL) {
		return gtk_hscrollbar_new (adjustment);
	}
	if (orientation == GTK_ORIENTATION_VERTICAL) {
		return gtk_vscrollbar_new (adjustment);
	}
	return NULL;
}

GtkWidget *
gtk_paned_new (GtkOrientation orientation)
{
	if (orientation == GTK_ORIENTATION_HORIZONTAL) {
		return gtk_hpaned_new ();
	}
	if (orientation == GTK_ORIENTATION_VERTICAL) {
		return gtk_vpaned_new ();
	}
	return NULL;
}

#endif


/* ================================================== */
/*                   GTK < 2.24                       */
/* ================================================== */

#if ! (GTK_CHECK_VERSION (2, 24, 0))
#endif

/* ================================================== */
/*                   GTK <= 2.14                      */
/* ================================================== */

#if (GTK_MAJOR_VERSION == 2 && GTK_MINOR_VERSION <= 14)

GtkWidget *
gtk_dialog_get_action_area (GtkDialog *dialog)
{
	return (dialog->action_area);
}

GtkWidget *
gtk_dialog_get_content_area (GtkDialog *dialog)
{
	return (dialog->vbox);
}

GdkWindow *
gtk_widget_get_window (GtkWidget *widget)
{
	return (widget->window);
}

#endif

