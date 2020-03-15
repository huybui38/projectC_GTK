#include <gtk/gtk.h>

#include "json.h"
#include <unistd.h>
typedef struct
{
    //window
    GtkWidget *w_wShopping;
    GtkWidget *w_wMain;
    GtkWidget *w_wLogin;
    GtkWidget *w_wRegister;
    GtkWidget *w_wMsg_box;

    //element for w_login
    GtkWidget *w_wLogin_txtUserLogin;
    GtkWidget *w_wLogin_txtPassLogin;

    //element for w_register
    GtkWidget *w_wRegister_txtUserRegister;
    GtkWidget *w_wRegister_txtFullNameRegister;
    GtkWidget *w_wRegister_txtPasswordRegister;
    GtkWidget *w_wRegister_txtRepasswordRegister;
    GtkWidget *w_wRegister_txtAddressRegister;
    GtkWidget *w_wRegister_cbxTypeRegister;

    //elemnt for w_shopping
    GtkWidget *w_wShopping_cbxCategoryShopping;
    GtkWidget *w_wShopping_txtNameShopping;
    GtkWidget *w_wShopping_cbxSortShopping;

} app_widgets;

// #region main
int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;
    gtk_init(&argc, &argv);
    app_widgets *widgets = g_slice_new(app_widgets);
    builder = gtk_builder_new_from_file("glade/window_main.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    // Get window's pointer
    widgets->w_wShopping = GTK_WIDGET(gtk_builder_get_object(builder, "window_shopping"));
    widgets->w_wMain = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    widgets->w_wLogin = GTK_WIDGET(gtk_builder_get_object(builder, "window_login"));
    widgets->w_wRegister = GTK_WIDGET(gtk_builder_get_object(builder, "window_register"));
    widgets->w_wMsg_box = GTK_WIDGET(gtk_builder_get_object(builder, "window_msg_box"));

    // Get element pointer for w_login
    widgets->w_wLogin_txtUserLogin = GTK_WIDGET(gtk_builder_get_object(builder, "txtUserLogin"));
    widgets->w_wLogin_txtPassLogin = GTK_WIDGET(gtk_builder_get_object(builder, "txtPassLogin"));

    // Get element pointer for w_register
    widgets->w_wRegister_txtUserRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtUserRegister"));
    widgets->w_wRegister_txtFullNameRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtFullNameRegister"));
    widgets->w_wRegister_txtPasswordRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtPasswordRegister"));
    widgets->w_wRegister_txtRepasswordRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtRepasswordRegister"));
    widgets->w_wRegister_txtAddressRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtAddressRegister"));
    widgets->w_wRegister_cbxTypeRegister = GTK_WIDGET(gtk_builder_get_object(builder, "cbxTypeRegister"));

    // Get element pointer for w_shopping
    widgets->w_wShopping_cbxCategoryShopping = GTK_WIDGET(gtk_builder_get_object(builder, "cbxCategoryShopping"));
    widgets->w_wShopping_txtNameShopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtNameShopping"));
    widgets->w_wShopping_cbxSortShopping = GTK_WIDGET(gtk_builder_get_object(builder, "cbxSortShopping"));

    //
    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    g_slice_free(app_widgets, widgets);
    return 0;
}
// #endregion
// #region Handle event window_main
void on_btn_shopping(GtkButton *button, app_widgets *app_wdgts)
{
    //show window_shopping; hide window_main
    gtk_widget_show(app_wdgts->w_wShopping);
    gtk_widget_hide(app_wdgts->w_wMain);
}
void on_btnShowLogin_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    //show window_shopping; hide window_main
    gtk_widget_show(app_wdgts->w_wLogin);
    gtk_widget_hide(app_wdgts->w_wMain);
}
// #endregion
// #region Handle event window_login
gboolean on_window_login_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_widget_hide(app_wdgts->w_wLogin);
    gtk_widget_show(app_wdgts->w_wMain);
    return TRUE;
}
void on_btn_click_login_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gchar *txtUserLogin = 0;
    gchar *txtPassLogin = 0;
    txtUserLogin = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wLogin_txtUserLogin));
    txtPassLogin = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wLogin_txtPassLogin));
    g_print("%s", txtUserLogin);
}
void btn_register_login_clicked_cb(GtkButton *button, app_widgets *app_wdgts)
{
    gtk_widget_hide(app_wdgts->w_wLogin);
    gtk_widget_show(app_wdgts->w_wRegister);
}

// #endregion
// #region Handle event window_shopping
gboolean on_window_shopping_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wMain);
    return TRUE;
}
void on_cbxCategoryShopping_changed(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *selectedCate;
    selectedCate = gtk_combo_box_get_active_id(widget);
    g_print("%s", selectedCate);
}
void on_cbxSortShopping_changed(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *selectedSort;
    selectedSort = gtk_combo_box_get_active_id(widget);
}
void on_window_shopping_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    Category *listCate;
    size_t lengthCate = 0;
    char tempStr[4];
    listCate = getCategory(&lengthCate);
    for (size_t i = 0; i < lengthCate; i++)
    {
        sprintf(tempStr, "%d", (listCate + i)->id);
        gtk_combo_box_text_insert(app_wdgts->w_wShopping_cbxCategoryShopping, i, tempStr, (listCate + i)->name);
    }
    gtk_combo_box_set_active(app_wdgts->w_wShopping_cbxCategoryShopping, 0);
}
// #endregion
// #region Handle event window_register
gboolean on_window_register_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_widget_hide(app_wdgts->w_wRegister);
    gtk_widget_show(app_wdgts->w_wLogin);
    return TRUE;
}
void on_btn_signup_register_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gchar *txtUserRegister = 0;
    gchar *txtFullNameRegister = 0;
    gchar *txtPasswordRegister = 0;
    gchar *txtRepasswordRegister = 0;
    gchar *txtAddressRegister = 0;
    gchar *cbxTypeRegister = 0;
    txtUserRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtUserRegister));
    txtFullNameRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtFullNameRegister));
    txtPasswordRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtPasswordRegister));
    txtRepasswordRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtRepasswordRegister));
    txtAddressRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtAddressRegister));
    cbxTypeRegister = gtk_combo_box_text_get_active_text(app_wdgts->w_wRegister_cbxTypeRegister);
    show_msg(app_wdgts, cbxTypeRegister);
}
// #endregion
//Handle event window_ManageGoods
//Handle event window_seller
//Handle event window_ads
//Handle event window_report
//Handle event window_cart

// called when window is closed
void on_window_destroy()
{
    gtk_main_quit();
}

//
// #region utils

void show_msg(app_widgets *app_wdgts, gchar *msg)
{
    gtk_message_dialog_format_secondary_text(app_wdgts->w_wMsg_box, msg);
    gtk_widget_show(app_wdgts->w_wMsg_box);
}
void on_window_msg_box_response(GtkDialog *dialog, gint response_id, app_widgets *app_wdgts)
{
    gtk_widget_hide(dialog);
}
// #endregion