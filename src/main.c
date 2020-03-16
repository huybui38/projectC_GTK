#include <gtk/gtk.h>
#include "get_data.h"
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
    GtkWidget *w_wShopping_box1Shopping;
    GtkWidget *w_wShopping_box2Shopping;
    GtkWidget *w_wShopping_box3Shopping;
    GtkWidget *w_wShopping_box4Shopping;
    GtkWidget *w_wShopping_box5Shopping;
    GtkWidget *w_wShopping_box6Shopping;
    GtkWidget *w_wShopping_box7Shopping;
    GtkWidget *w_wShopping_box8Shopping;
    GtkWidget *w_wShopping_box9Shopping;
    GtkWidget *w_wShopping_box10Shopping;
    GtkWidget *w_wShopping_box11Shopping;
    GtkWidget *w_wShopping_box12Shopping;
    GtkWidget *w_wShopping_lblSalePrice1Shopping;
    GtkWidget *w_wShopping_lblSalePrice2Shopping;
    GtkWidget *w_wShopping_lblSalePrice3Shopping;
    GtkWidget *w_wShopping_lblSalePrice4Shopping;
    GtkWidget *w_wShopping_lblSalePrice5Shopping;
    GtkWidget *w_wShopping_lblSalePrice6Shopping;
    GtkWidget *w_wShopping_lblSalePrice7Shopping;
    GtkWidget *w_wShopping_lblSalePrice8Shopping;
    GtkWidget *w_wShopping_lblSalePrice9Shopping;
    GtkWidget *w_wShopping_lblSalePrice10Shopping;
    GtkWidget *w_wShopping_lblSalePrice11Shopping;
    GtkWidget *w_wShopping_lblSalePrice12Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice1Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice2Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice3Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice4Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice5Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice6Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice7Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice8Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice9Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice10Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice11Shopping;
    GtkWidget *w_wShopping_lblOriginalPrice12Shopping;
    GtkWidget *w_wShopping_txtItem1Shopping;
    GtkWidget *w_wShopping_txtItem2Shopping;
    GtkWidget *w_wShopping_txtItem3Shopping;
    GtkWidget *w_wShopping_txtItem4Shopping;
    GtkWidget *w_wShopping_txtItem5Shopping;
    GtkWidget *w_wShopping_txtItem6Shopping;
    GtkWidget *w_wShopping_txtItem7Shopping;
    GtkWidget *w_wShopping_txtItem8Shopping;
    GtkWidget *w_wShopping_txtItem9Shopping;
    GtkWidget *w_wShopping_txtItem10Shopping;
    GtkWidget *w_wShopping_txtItem11Shopping;
    GtkWidget *w_wShopping_txtItem12Shopping;

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
    widgets->w_wShopping_box1Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box1Shopping"));
    widgets->w_wShopping_box2Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box2Shopping"));
    widgets->w_wShopping_box3Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box3Shopping"));
    widgets->w_wShopping_box4Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box4Shopping"));
    widgets->w_wShopping_box5Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box5Shopping"));
    widgets->w_wShopping_box6Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box6Shopping"));
    widgets->w_wShopping_box7Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box7Shopping"));
    widgets->w_wShopping_box8Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box8Shopping"));
    widgets->w_wShopping_box9Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box9Shopping"));
    widgets->w_wShopping_box10Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box10Shopping"));
    widgets->w_wShopping_box11Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box11Shopping"));
    widgets->w_wShopping_box12Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "box12Shopping"));
    widgets->w_wShopping_lblSalePrice1Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice1Shopping"));
    widgets->w_wShopping_lblSalePrice2Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice2Shopping"));
    widgets->w_wShopping_lblSalePrice3Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice3Shopping"));
    widgets->w_wShopping_lblSalePrice4Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice4Shopping"));
    widgets->w_wShopping_lblSalePrice5Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice5Shopping"));
    widgets->w_wShopping_lblSalePrice6Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice6Shopping"));
    widgets->w_wShopping_lblSalePrice7Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice7Shopping"));
    widgets->w_wShopping_lblSalePrice8Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice8Shopping"));
    widgets->w_wShopping_lblSalePrice9Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice9Shopping"));
    widgets->w_wShopping_lblSalePrice10Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice10Shopping"));
    widgets->w_wShopping_lblSalePrice11Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice11Shopping"));
    widgets->w_wShopping_lblSalePrice12Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice12Shopping"));
    widgets->w_wShopping_lblSalePrice12Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblSalePrice12Shopping"));
    widgets->w_wShopping_lblOriginalPrice1Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice1Shopping"));
    widgets->w_wShopping_lblOriginalPrice2Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice2Shopping"));
    widgets->w_wShopping_lblOriginalPrice3Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice3Shopping"));
    widgets->w_wShopping_lblOriginalPrice4Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice4Shopping"));
    widgets->w_wShopping_lblOriginalPrice5Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice5Shopping"));
    widgets->w_wShopping_lblOriginalPrice6Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice6Shopping"));
    widgets->w_wShopping_lblOriginalPrice7Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice7Shopping"));
    widgets->w_wShopping_lblOriginalPrice8Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice8Shopping"));
    widgets->w_wShopping_lblOriginalPrice9Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice9Shopping"));
    widgets->w_wShopping_lblOriginalPrice10Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice10Shopping"));
    widgets->w_wShopping_lblOriginalPrice11Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice11Shopping"));
    widgets->w_wShopping_lblOriginalPrice12Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblOriginalPrice12Shopping"));
    widgets->w_wShopping_txtItem1Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem1Shopping"));
    widgets->w_wShopping_txtItem2Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem2Shopping"));
    widgets->w_wShopping_txtItem3Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem3Shopping"));
    widgets->w_wShopping_txtItem4Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem4Shopping"));
    widgets->w_wShopping_txtItem5Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem5Shopping"));
    widgets->w_wShopping_txtItem6Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem6Shopping"));
    widgets->w_wShopping_txtItem7Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem7Shopping"));
    widgets->w_wShopping_txtItem8Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem8Shopping"));
    widgets->w_wShopping_txtItem9Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem9Shopping"));
    widgets->w_wShopping_txtItem10Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem10Shopping"));
    widgets->w_wShopping_txtItem11Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem11Shopping"));
    widgets->w_wShopping_txtItem12Shopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtItem12Shopping"));

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
    int flag = getLogin(txtUserLogin, txtPassLogin);
    switch (flag)
    {
    case -1:
        show_msg(app_wdgts, "Sai tài khoản hoặc mật khẩu!");
        break;

    default:
        break;
    }
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
void setBoxShoppingSensitive(int boxID, gboolean visible, app_widgets *app_wdgts)
{
    switch (boxID)
    {
    case 1:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box1Shopping, visible);
        break;
    case 2:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box2Shopping, visible);
        break;
    case 3:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box3Shopping, visible);
        break;
    case 4:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box4Shopping, visible);
        break;
    case 5:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box5Shopping, visible);
        break;
    case 6:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box6Shopping, visible);
        break;
    case 7:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box7Shopping, visible);
        break;
    case 8:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box8Shopping, visible);
        break;
    case 9:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box9Shopping, visible);
        break;
    case 10:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box10Shopping, visible);
        break;
    case 11:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box11Shopping, visible);
        break;
    case 12:
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_box12Shopping, visible);
        break;
    default:
        break;
    }
}
void on_window_shopping_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    // load category
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

    //load goods
    Goods *listGoods;
    size_t lengthGoods = 0;
    listGoods = getAllGoods(&lengthGoods);
    for (size_t i = 1; i < 13; i++)
    {
        setBoxShoppingSensitive(i, FALSE, app_wdgts);
    }
    setBoxShoppingSensitive(1, TRUE, app_wdgts);
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