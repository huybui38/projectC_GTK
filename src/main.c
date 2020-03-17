#include <gtk/gtk.h>
#include "authenticator.h"
#include "edit_user.h"
#include "json.h"
#include <unistd.h>
typedef struct
{
    //window
    GtkWidget *w_wMsg_box;
    GtkWidget *w_wShopping;
    GtkWidget *w_wMain;
    GtkWidget *w_wLogin;
    GtkWidget *w_wRegister;
    GtkWidget *w_wCustomer;
    GtkWidget *w_wSeller;
    GtkWidget *w_wAdmin;
    GtkWidget *w_wChangePassword;
    GtkWidget *w_wChangeInfo;

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

    //element for w_changePassword
    GtkWidget *w_wChangePassword_txtCurrentPasswordChange;
    GtkWidget *w_wChangePassword_txtNewPasswordChange;
    GtkWidget *w_wChangePassword_txtReNewPasswordChange;

    //element for w_customer
    GtkWidget *w_wCustomer_lbtNameCustomer;

    //element for w_changeInfo
    GtkWidget *w_wChangeInfo_txtAddressChangeInfo;
    GtkWidget *w_wChangeInfo_txtFullNameChangeInfo;

    //elemnt for w_shopping
    GtkWidget *w_wShopping_cbxCategoryShopping;
    GtkWidget *w_wShopping_btnRegisterShopping;
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
int turnBack = -1;
int turnBack_2 = -1;
int isClickedMsg = 0;
User currentUser;

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

    widgets->w_wMsg_box = GTK_WIDGET(gtk_builder_get_object(builder, "window_msg_box"));
    widgets->w_wShopping = GTK_WIDGET(gtk_builder_get_object(builder, "window_shopping"));
    widgets->w_wMain = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    widgets->w_wLogin = GTK_WIDGET(gtk_builder_get_object(builder, "window_login"));
    widgets->w_wRegister = GTK_WIDGET(gtk_builder_get_object(builder, "window_register"));
    widgets->w_wSeller = GTK_WIDGET(gtk_builder_get_object(builder, "window_seller"));
    widgets->w_wAdmin = GTK_WIDGET(gtk_builder_get_object(builder, "window_admin"));
    widgets->w_wCustomer = GTK_WIDGET(gtk_builder_get_object(builder, "window_customer"));
    widgets->w_wChangePassword = GTK_WIDGET(gtk_builder_get_object(builder, "window_changePassword"));
    widgets->w_wChangeInfo = GTK_WIDGET(gtk_builder_get_object(builder, "window_changeInfo"));

    // Get element pointer for w_login
    widgets->w_wLogin_txtUserLogin = GTK_WIDGET(gtk_builder_get_object(builder, "txtUserLogin"));
    widgets->w_wLogin_txtPassLogin = GTK_WIDGET(gtk_builder_get_object(builder, "txtPassLogin"));

    // Get element pointer for w_customer
    widgets->w_wCustomer_lbtNameCustomer = GTK_WIDGET(gtk_builder_get_object(builder, "lbtNameCustomer"));

    // Get element pointer for w_register
    widgets->w_wRegister_txtUserRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtUserRegister"));
    widgets->w_wRegister_txtFullNameRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtFullNameRegister"));
    widgets->w_wRegister_txtPasswordRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtPasswordRegister"));
    widgets->w_wRegister_txtRepasswordRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtRepasswordRegister"));
    widgets->w_wRegister_txtAddressRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtAddressRegister"));
    widgets->w_wRegister_cbxTypeRegister = GTK_WIDGET(gtk_builder_get_object(builder, "cbxTypeRegister"));

    // Get element pointer for w_changePassword
    widgets->w_wChangePassword_txtCurrentPasswordChange = GTK_WIDGET(gtk_builder_get_object(builder, "txtCurrentPasswordChange"));
    widgets->w_wChangePassword_txtNewPasswordChange = GTK_WIDGET(gtk_builder_get_object(builder, "txtNewPasswordChange"));
    widgets->w_wChangePassword_txtReNewPasswordChange = GTK_WIDGET(gtk_builder_get_object(builder, "txtReNewPasswordChange"));

    //get element pointer for w_changeInfo
    widgets->w_wChangeInfo_txtAddressChangeInfo = GTK_WIDGET(gtk_builder_get_object(builder, "txtAddressChangeInfo"));
    widgets->w_wChangeInfo_txtFullNameChangeInfo = GTK_WIDGET(gtk_builder_get_object(builder, "txtFullNameChangeInfo"));

    // Get element pointer for w_shopping
    widgets->w_wShopping_cbxCategoryShopping = GTK_WIDGET(gtk_builder_get_object(builder, "cbxCategoryShopping"));
    widgets->w_wShopping_btnRegisterShopping = GTK_WIDGET(gtk_builder_get_object(builder, "btnRegisterShopping"));
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
// #region utils

void resetShopping(app_widgets *app_wdgts)
{
    gtk_combo_box_text_remove_all(app_wdgts->w_wShopping_cbxCategoryShopping);
    gtk_widget_set_sensitive(app_wdgts->w_wShopping_btnRegisterShopping, TRUE);
}
void logoutUser()
{
    currentUser.id = 0;
    currentUser.name[0] = '\0';
    currentUser.address[0] = '\0';
    currentUser.password[0] = '\0';
    currentUser.phoneNum[0] = '\0';
    currentUser.userName[0] = '\0';
    currentUser.name[0] = '\0';
    currentUser.name[0] = '\0';
    currentUser.balance = 0;
    currentUser.role = 0;
}
void reset()
{
    turnBack_2 = -1;
    turnBack = -1;
}
void show_msg(app_widgets *app_wdgts, gchar *msg)
{
    isClickedMsg = 0;
    gtk_message_dialog_format_secondary_text(app_wdgts->w_wMsg_box, msg);
    gtk_widget_show(app_wdgts->w_wMsg_box);
}
void on_window_msg_box_response(GtkDialog *dialog, gint response_id, app_widgets *app_wdgts)
{
    isClickedMsg = 1;
    gtk_widget_hide(dialog);
}
void setTurnBackWindow(int id)
{
    turnBack_2 = turnBack;
    turnBack = id;
}
void on_window_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{

    gtk_widget_hide(widget);
    switch (turnBack)
    {
    case 1:
        gtk_widget_show(app_wdgts->w_wMain);
        break;
    case 2:
        gtk_widget_show(app_wdgts->w_wShopping);
        break;
    case 3:
        gtk_widget_show(app_wdgts->w_wLogin);
        break;
    case 4:
        gtk_widget_show(app_wdgts->w_wRegister);
        break;
    case 5:
        gtk_widget_show(app_wdgts->w_wCustomer);
        break;
    case 6:
        gtk_widget_show(app_wdgts->w_wSeller);
        break;
    case 7:
        gtk_widget_show(app_wdgts->w_wAdmin);
        break;
    default:
        break;
    }
    // g_print("%d", turnBack);
    turnBack = turnBack_2;
    return TRUE;
}

// #endregion

// #region Handle event window_main
void on_btn_shopping(GtkButton *button, app_widgets *app_wdgts)
{
    //show window_shopping; hide window_main
    setTurnBackWindow(1);
    gtk_widget_show(app_wdgts->w_wShopping);
    gtk_widget_hide(app_wdgts->w_wMain);
}
void on_btnShowLogin_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    setTurnBackWindow(1);
    if (currentUser.id == 0)
    {
        gtk_widget_show(app_wdgts->w_wLogin);
        gtk_widget_hide(app_wdgts->w_wMain);
    }
    else
    {
        switch (currentUser.role)
        {
        case 1:
            gtk_widget_show(app_wdgts->w_wCustomer);
            break;
        case 2:
            gtk_widget_show(app_wdgts->w_wSeller);
            break;
        case 3:
            gtk_widget_show(app_wdgts->w_wAdmin);
            break;
        default:
            break;
        }
        gtk_widget_hide(app_wdgts->w_wMain);
    }
}
// #endregion
// #region Handle event window_login

void on_btn_click_login_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gchar *txtUserLogin = 0;
    gchar *txtPassLogin = 0;
    txtUserLogin = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wLogin_txtUserLogin));
    txtPassLogin = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wLogin_txtPassLogin));

    int flag = getLogin(txtUserLogin, txtPassLogin);
    // g_print("%d", flag);
    switch (flag)
    {
    case -1:
        show_msg(app_wdgts, "Sai tài khoản hoặc mật khẩu!");
        break;
    case 1:
        currentUser = getUser(txtUserLogin);
        // g_print("%s", user.password);
        setTurnBackWindow(1);
        gtk_widget_hide(app_wdgts->w_wLogin);
        gtk_widget_show(app_wdgts->w_wCustomer);
        break;
    case 2:
        currentUser = getUser(txtUserLogin);
        setTurnBackWindow(1);
        gtk_widget_hide(app_wdgts->w_wLogin);
        gtk_widget_show(app_wdgts->w_wSeller);
        break;
    case 3:
        currentUser = getUser(txtUserLogin);
        setTurnBackWindow(1);
        gtk_widget_hide(app_wdgts->w_wLogin);
        gtk_widget_show(app_wdgts->w_wAdmin);
        break;
    default:
        break;
    }
}
void btn_register_login_clicked_cb(GtkButton *button, app_widgets *app_wdgts)
{
    setTurnBackWindow(3);
    gtk_widget_hide(app_wdgts->w_wLogin);
    gtk_widget_show(app_wdgts->w_wRegister);
}

// #endregion
// #region Handle event window_shopping

void on_btnRegisterShopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wRegister);
}
void on_btnTurnBackShopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wShopping, NULL, app_wdgts);
}
void on_cbxCategoryShopping_changed(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *selectedCate;
    selectedCate = gtk_combo_box_get_active_id(widget);
    if (selectedCate != NULL)
    {
        g_print("\n%s", selectedCate);
    }
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

void showBoxGoods(int boxID, Goods goods, app_widgets *app_wdgts)
{
    setBoxShoppingSensitive(boxID, TRUE, app_wdgts);
    gchar *goodsName;
    gchar goodsPrice[20];
    switch (boxID)
    {
    case 1:
        if (goods.discount != 0)
        {
            goodsName = goods.name;
            sprintf(goodsPrice, "%d", goods.price);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice1Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, goodsPrice);
        }
        else
        {
            goodsName = goods.name;
            sprintf(goodsPrice, "%d", goods.price);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice1Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem1Shopping, goodsName);
        break;
    default:
        break;
    }
}
void on_window_shopping_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    resetShopping(app_wdgts);
    // load category
    if (currentUser.id != 0)
    {
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_btnRegisterShopping, FALSE);
    }
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
    showBoxGoods(1, listGoods[0], app_wdgts);
}
// #endregion
// #region Handle event window_register

void on_btn_signup_register_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gchar *txtUserRegister = 0;
    gchar *txtFullNameRegister = 0;
    gchar *txtPasswordRegister = 0;
    gchar *txtRepasswordRegister = 0;
    gchar *txtAddressRegister = 0;
    gchar *cbxTypeRegister = 0;
    int type = 0;
    txtUserRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtUserRegister));
    txtFullNameRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtFullNameRegister));
    txtPasswordRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtPasswordRegister));
    txtRepasswordRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtRepasswordRegister));
    txtAddressRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtAddressRegister));
    cbxTypeRegister = gtk_combo_box_get_active_id(app_wdgts->w_wRegister_cbxTypeRegister);
    type = atoi(cbxTypeRegister);
    int flag = getRegister(txtUserRegister, txtFullNameRegister, txtPasswordRegister, txtRepasswordRegister, txtAddressRegister, type);
    g_print("\n%d", type);
    // g_print("%d", type);
    show_msg(app_wdgts, cbxTypeRegister);
}
void on_btnTurnBackRegister_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wRegister, NULL, app_wdgts);
}
// #endregion
// #region Handle event window_customer
void on_btnTurnBackCustomer_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wCustomer, NULL, app_wdgts);
}
void on_btnChangeInfoCustomer_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_wChangeInfo);
}
void on_window_customer_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar joinedStr[100];
    strcat(joinedStr, "Xin chào ");
    strcat(joinedStr, currentUser.name);
    strcat(joinedStr, " !      Số dư: ");
    strcat(joinedStr, "300.000");
    // g_print("%s", joinedStr);
    // g_print("%s", );
    gtk_label_set_text(app_wdgts->w_wCustomer_lbtNameCustomer, joinedStr);
}
void on_btnChangePassWordCustomer_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_wChangePassword);
}
void on_btnShoppingCustomer_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    setTurnBackWindow(5);
    // gtk_widget_hide(app_wdgts->w_wCustomer);
    gtk_widget_show(app_wdgts->w_wShopping);
}
void btnLogoutCustomer_clicked_cb(GtkButton *button, app_widgets *app_wdgts)
{
    logoutUser();
    gtk_widget_hide(app_wdgts->w_wCustomer);
    gtk_widget_show(app_wdgts->w_wMain);
    reset();
}

// #endregion
// #region Handle event window_changePassword
gboolean on_window_changePassword_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_entry_set_text(app_wdgts->w_wChangePassword_txtCurrentPasswordChange, "");
    gtk_entry_set_text(app_wdgts->w_wChangePassword_txtNewPasswordChange, "");
    gtk_entry_set_text(app_wdgts->w_wChangePassword_txtReNewPasswordChange, "");
    gtk_widget_grab_focus(app_wdgts->w_wChangePassword_txtCurrentPasswordChange);
    gtk_widget_hide(app_wdgts->w_wChangePassword);
    return TRUE;
}
void on_btnClickChangePassword_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gchar *txtCurrentPassword = 0;
    gchar *txtNewPassword = 0;
    gchar *txtReNewPassword = 0;
    txtCurrentPassword = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangePassword_txtCurrentPasswordChange));
    txtNewPassword = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangePassword_txtNewPasswordChange));
    txtReNewPassword = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangePassword_txtReNewPasswordChange));

    if (txtNewPassword[0] == '\0' || txtReNewPassword[0] == '\0' || txtCurrentPassword[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ!");
    }
    else if (strcmp(txtCurrentPassword, currentUser.password) != 0)
    {
        show_msg(app_wdgts, "Mật khẩu nhập hiện tại không chính xác!");
    }
    else if (strcmp(txtNewPassword, txtReNewPassword) != 0)
    {
        show_msg(app_wdgts, "Mật khẩu nhập lại không chính xác!");
    }
    else
    {
        //do change pass
        changePassword(currentUser.id, txtNewPassword);
        currentUser = getUser(currentUser.userName);
        show_msg(app_wdgts, "Đổi mật khẩu thành công!");
        gtk_widget_hide(app_wdgts->w_wChangePassword);
    }
}
// #endregion
// #regionHandle event window_changeInfo
void on_window_changeInfo_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_entry_set_text(app_wdgts->w_wChangeInfo_txtAddressChangeInfo, "");
    gtk_entry_set_text(app_wdgts->w_wChangeInfo_txtFullNameChangeInfo, "");
    // gtk_entry_set_text(app_wdgts->w_wChangePassword_txtReNewPasswordChange, "");
    gtk_widget_grab_focus(app_wdgts->w_wChangeInfo_txtAddressChangeInfo);
    gtk_widget_hide(app_wdgts->w_wChangeInfo);
    return TRUE;
}
void on_window_changeInfo_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_entry_set_text(app_wdgts->w_wChangeInfo_txtAddressChangeInfo, currentUser.address);
    gtk_entry_set_text(app_wdgts->w_wChangeInfo_txtFullNameChangeInfo, currentUser.name);
}
void on_btnClickUpdateChangeInfo_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtAddress = 0;
    gchar *txtFullName = 0;
    txtAddress = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangeInfo_txtAddressChangeInfo));
    txtFullName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangeInfo_txtFullNameChangeInfo));
    if (txtFullName[0] == '\0' || txtAddress == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ thông tin!");
    }
    else
    {
        changeInformation(currentUser.id, txtFullName, txtAddress);
        currentUser = getUser(currentUser.userName);
        show_msg(app_wdgts, "Cập nhập thành công!");
        gtk_widget_hide(app_wdgts->w_wChangeInfo);
    }
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
