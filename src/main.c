#include <gtk/gtk.h>
#include "authenticator.h"
#include "edit_user.h"
#include "edit_goods.h"
#include "shopping_cart.h"
#include "json.h"
#include <time.h>
#include <unistd.h>
#include "ads.h"
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
    GtkWidget *w_wPurchaseHistory;
    GtkWidget *w_wManageGoods;
    GtkWidget *w_wAddMoney;
    GtkWidget *w_wCategory;
    GtkWidget *w_wAds;
    GtkWidget *w_wCart;
    GtkWidget *w_wReport;

    //element for w_category
    GtkWidget *w_wCategory_txtNameCategory;
    GtkWidget *w_wCategory_cbxCategory;

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
    GtkWidget *w_wRegister_txtPhoneNumberRegister;

    //element for w_changePassword
    GtkWidget *w_wChangePassword_txtCurrentPasswordChange;
    GtkWidget *w_wChangePassword_txtNewPasswordChange;
    GtkWidget *w_wChangePassword_txtReNewPasswordChange;

    //element for w_customer
    GtkWidget *w_wCustomer_lbtNameCustomer;

    //element for w_mangaGoods
    GtkWidget *w_wManageGoods_lblNameManageGoods;
    GtkWidget *w_wManageGoods_btnTurnBackManageGoods;
    GtkWidget *w_wManageGoods_txtNameCreateMangaGoods;
    GtkWidget *w_wManageGoods_txtPriceCreateMangaGoods;
    GtkWidget *w_wManageGoods_cbxCategoryAddManageGoods;
    GtkWidget *w_wManageGoods_txtIdEditMangaGoods;
    GtkWidget *w_wManageGoods_txtNameEditMangaGoods;
    GtkWidget *w_wManageGoods_txtPriceEditMangaGoods;
    GtkWidget *w_wManageGoods_cbxCategoryEditManageGoods;
    GtkWidget *w_wManageGoods_txtIdDeleteMangaGoods;
    GtkWidget *w_wManageGoods_txtIdUpdateMangaGoods;
    GtkWidget *w_wManageGoods_txtDiscountUpdateMangaGoods;
    GtkTextBuffer *w_wManageGoods_txtListManageGoods;

    //element for w_report
    GtkWidget *w_wReport_startCalendarReport;
    GtkWidget *w_wReport_endCalendarReport;
    GtkTextBuffer *w_wReport_txtDoanhThuReport;

    //element for w_ads
    GtkWidget *w_wAds_lblMoneyAds;
    GtkWidget *w_wAds_txtGoodsIDAds;
    GtkWidget *w_wAds_cbxPositionAds;
    GtkWidget *w_wAds_txtMoneyAds;
    GtkWidget *w_wAds_txtBudgetAds;
    GtkWidget *w_wAds_lblNameAds;
    GtkTextBuffer *w_wAds_txtListGoodsAds;

    //element for w_seller
    GtkWidget *w_wCustomer_lbtNameSeller;

    //element for w_cart
    GtkWidget *w_wCart_lblNameCart;
    GtkWidget *w_wCart_btnLoginCart;
    GtkWidget *w_wCart_txtNameCart;
    GtkWidget *w_wCart_lblBtnLoginCart;
    GtkWidget *w_wCart_txtAddressCart;
    GtkWidget *w_wCart_txtPhoneNumberCart;
    GtkWidget *w_wCart_txtDeleteIDCart;
    GtkWidget *w_wCart_isCODCart;
    GtkWidget *w_wCart_isCashCart;
    GtkTextBuffer *w_wCart_txtListCart;
    GtkWidget *w_wCart_txtCouponCart;

    //element for w_admin
    GtkWidget *w_wAdmin_lblNameAdmin;

    //element for w_addMoney
    GtkWidget *w_wAddMoney_txtUserNameAddMoney;
    GtkWidget *w_wAddMoney_txtCashAddMoney;

    //element for w_purchaseHistory
    GtkTextBuffer *w_wPurchaseHistory_txtPurchaseHistory;

    //element for w_changeInfo
    GtkWidget *w_wChangeInfo_txtAddressChangeInfo;
    GtkWidget *w_wChangeInfo_txtFullNameChangeInfo;
    GtkWidget *w_wChangeInfo_txtPhoneNumberChangeInfo;

    //elemnt for w_shopping
    GtkWidget *w_wShopping_cbxCategoryShopping;
    GtkWidget *w_wShopping_btnRegisterShopping;
    GtkWidget *w_wShopping_txtNameShopping;
    GtkWidget *w_wShopping_btnNextShopping;
    GtkWidget *w_wShopping_btnBackShopping;
    GtkWidget *w_wShopping_cbxSortShopping;
    GtkWidget *w_wShopping_lblPaymentShopping;
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
int turnBack_3 = -1;
int turnBack_4 = -1;
int turnBack_5 = -1;
int turnBack_6 = -1;
int isClickedMsg = 0;
int currentPageShopping = 1;
int lengthListCart = 1;
int listStatusAds[3][2];
Goods *listCart;
gboolean isSearchByWords = FALSE;
gboolean isTurnBackShopping = FALSE;
gboolean isTurnBackCart = FALSE;
User currentUser;
int minMoneyAds = 2000;
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
    widgets->w_wPurchaseHistory = GTK_WIDGET(gtk_builder_get_object(builder, "window_purchaseHistory"));
    widgets->w_wAddMoney = GTK_WIDGET(gtk_builder_get_object(builder, "window_addMoney"));
    widgets->w_wCategory = GTK_WIDGET(gtk_builder_get_object(builder, "window_category"));
    widgets->w_wManageGoods = GTK_WIDGET(gtk_builder_get_object(builder, "window_manageGoods"));
    widgets->w_wCart = GTK_WIDGET(gtk_builder_get_object(builder, "window_cart"));
    widgets->w_wAds = GTK_WIDGET(gtk_builder_get_object(builder, "window_ads"));
    widgets->w_wReport = GTK_WIDGET(gtk_builder_get_object(builder, "window_report"));

    // Get element pointer for w_admin lblNameAdmin

    widgets->w_wAdmin_lblNameAdmin = GTK_WIDGET(gtk_builder_get_object(builder, "lblNameAdmin"));
    // Get element pointer for w_report
    widgets->w_wReport_startCalendarReport = GTK_WIDGET(gtk_builder_get_object(builder, "startCalendarReport"));
    widgets->w_wReport_endCalendarReport = GTK_WIDGET(gtk_builder_get_object(builder, "endCalendarReport"));
    widgets->w_wReport_txtDoanhThuReport = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txtDoanhThuReport"));

    // Get element pointer for w_login
    widgets->w_wLogin_txtUserLogin = GTK_WIDGET(gtk_builder_get_object(builder, "txtUserLogin"));
    widgets->w_wLogin_txtPassLogin = GTK_WIDGET(gtk_builder_get_object(builder, "txtPassLogin"));

    // Get element pointer for w_PurchaseHistory
    widgets->w_wPurchaseHistory_txtPurchaseHistory = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txtPurchaseHistory"));

    // Get element pointer for w_customer
    widgets->w_wCustomer_lbtNameCustomer = GTK_WIDGET(gtk_builder_get_object(builder, "lbtNameCustomer"));

    // Get element pointer for w_cart
    widgets->w_wCart_lblNameCart = GTK_WIDGET(gtk_builder_get_object(builder, "lblNameCart"));
    widgets->w_wCart_lblBtnLoginCart = GTK_WIDGET(gtk_builder_get_object(builder, "lblBtnLoginCart"));
    widgets->w_wCart_btnLoginCart = GTK_WIDGET(gtk_builder_get_object(builder, "btnLoginCart"));
    widgets->w_wCart_txtNameCart = GTK_WIDGET(gtk_builder_get_object(builder, "txtNameCart"));
    widgets->w_wCart_txtAddressCart = GTK_WIDGET(gtk_builder_get_object(builder, "txtAddressCart"));
    widgets->w_wCart_txtPhoneNumberCart = GTK_WIDGET(gtk_builder_get_object(builder, "txtPhoneNumberCart"));
    widgets->w_wCart_txtDeleteIDCart = GTK_WIDGET(gtk_builder_get_object(builder, "txtDeleteIDCart"));
    widgets->w_wCart_isCODCart = GTK_WIDGET(gtk_builder_get_object(builder, "isCODCart"));
    widgets->w_wCart_isCashCart = GTK_WIDGET(gtk_builder_get_object(builder, "isCashCart"));
    widgets->w_wCart_txtCouponCart = GTK_WIDGET(gtk_builder_get_object(builder, "txtCouponCart"));
    widgets->w_wCart_txtListCart = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txtListCart"));

    // Get element pointer for w_seller
    widgets->w_wCustomer_lbtNameSeller = GTK_WIDGET(gtk_builder_get_object(builder, "lbtNameSeller"));

    // Get element pointer for w_ads
    widgets->w_wAds_cbxPositionAds = GTK_WIDGET(gtk_builder_get_object(builder, "cbxPositionAds"));
    widgets->w_wAds_txtListGoodsAds = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txtListGoodsAds"));
    widgets->w_wAds_lblNameAds = GTK_WIDGET(gtk_builder_get_object(builder, "lblNameAds"));
    widgets->w_wAds_txtMoneyAds = GTK_WIDGET(gtk_builder_get_object(builder, "txtMoneyAds"));
    widgets->w_wAds_txtBudgetAds = GTK_WIDGET(gtk_builder_get_object(builder, "txtBudgetAds"));
    widgets->w_wAds_txtGoodsIDAds = GTK_WIDGET(gtk_builder_get_object(builder, "txtGoodsIDAds"));
    widgets->w_wAds_lblMoneyAds = GTK_WIDGET(gtk_builder_get_object(builder, "lblMoneyAds"));

    // Get element pointer for w_register
    widgets->w_wRegister_txtUserRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtUserRegister"));
    widgets->w_wRegister_txtFullNameRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtFullNameRegister"));
    widgets->w_wRegister_txtPasswordRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtPasswordRegister"));
    widgets->w_wRegister_txtRepasswordRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtRepasswordRegister"));
    widgets->w_wRegister_txtAddressRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtAddressRegister"));
    widgets->w_wRegister_cbxTypeRegister = GTK_WIDGET(gtk_builder_get_object(builder, "cbxTypeRegister"));
    widgets->w_wRegister_txtPhoneNumberRegister = GTK_WIDGET(gtk_builder_get_object(builder, "txtPhoneNumberRegister"));

    // Get element pointer for w_changePassword
    widgets->w_wChangePassword_txtCurrentPasswordChange = GTK_WIDGET(gtk_builder_get_object(builder, "txtCurrentPasswordChange"));
    widgets->w_wChangePassword_txtNewPasswordChange = GTK_WIDGET(gtk_builder_get_object(builder, "txtNewPasswordChange"));
    widgets->w_wChangePassword_txtReNewPasswordChange = GTK_WIDGET(gtk_builder_get_object(builder, "txtReNewPasswordChange"));

    //get element pointer for w_addMoney
    widgets->w_wAddMoney_txtCashAddMoney = GTK_WIDGET(gtk_builder_get_object(builder, "txtCashAddMoney"));
    widgets->w_wAddMoney_txtUserNameAddMoney = GTK_WIDGET(gtk_builder_get_object(builder, "txtUserNameAddMoney"));

    //get element pointer for w_category
    widgets->w_wCategory_txtNameCategory = GTK_WIDGET(gtk_builder_get_object(builder, "txtNameCategory"));
    widgets->w_wCategory_cbxCategory = GTK_WIDGET(gtk_builder_get_object(builder, "cbxCategory"));

    //get element pointer for w_changeInfo
    widgets->w_wChangeInfo_txtAddressChangeInfo = GTK_WIDGET(gtk_builder_get_object(builder, "txtAddressChangeInfo"));
    widgets->w_wChangeInfo_txtFullNameChangeInfo = GTK_WIDGET(gtk_builder_get_object(builder, "txtFullNameChangeInfo"));
    widgets->w_wChangeInfo_txtPhoneNumberChangeInfo = GTK_WIDGET(gtk_builder_get_object(builder, "txtPhoneNumberChangeInfo"));

    //get element pointer for w_manageGoods
    widgets->w_wManageGoods_lblNameManageGoods = GTK_WIDGET(gtk_builder_get_object(builder, "lblNameManageGoods"));
    widgets->w_wManageGoods_btnTurnBackManageGoods = GTK_WIDGET(gtk_builder_get_object(builder, "btnTurnBackManageGoods"));
    widgets->w_wManageGoods_txtNameCreateMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtNameCreateMangaGoods"));
    widgets->w_wManageGoods_txtPriceCreateMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtPriceCreateMangaGoods"));
    widgets->w_wManageGoods_cbxCategoryAddManageGoods = GTK_WIDGET(gtk_builder_get_object(builder, "cbxCategoryAddManageGoods"));
    widgets->w_wManageGoods_txtIdEditMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtIdEditMangaGoods"));
    widgets->w_wManageGoods_txtNameEditMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtNameEditMangaGoods"));
    widgets->w_wManageGoods_txtPriceEditMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtPriceEditMangaGoods"));
    widgets->w_wManageGoods_cbxCategoryEditManageGoods = GTK_WIDGET(gtk_builder_get_object(builder, "cbxCategoryEditManageGoods"));
    widgets->w_wManageGoods_txtIdDeleteMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtIdDeleteMangaGoods"));
    widgets->w_wManageGoods_txtIdUpdateMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtIdUpdateMangaGoods"));
    widgets->w_wManageGoods_txtDiscountUpdateMangaGoods = GTK_WIDGET(gtk_builder_get_object(builder, "txtDiscountUpdateMangaGoods"));
    widgets->w_wManageGoods_txtListManageGoods = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txtListManageGoods"));

    // Get element pointer for w_shopping
    widgets->w_wShopping_cbxCategoryShopping = GTK_WIDGET(gtk_builder_get_object(builder, "cbxCategoryShopping"));
    widgets->w_wShopping_btnRegisterShopping = GTK_WIDGET(gtk_builder_get_object(builder, "btnRegisterShopping"));
    widgets->w_wShopping_txtNameShopping = GTK_WIDGET(gtk_builder_get_object(builder, "txtNameShopping"));
    widgets->w_wShopping_btnNextShopping = GTK_WIDGET(gtk_builder_get_object(builder, "btnNextShopping"));
    widgets->w_wShopping_btnBackShopping = GTK_WIDGET(gtk_builder_get_object(builder, "btnBackShopping"));
    widgets->w_wShopping_cbxSortShopping = GTK_WIDGET(gtk_builder_get_object(builder, "cbxSortShopping"));
    widgets->w_wShopping_lblPaymentShopping = GTK_WIDGET(gtk_builder_get_object(builder, "lblPaymentShopping"));
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
    listCart = (Goods *)malloc(lengthListCart * sizeof(Goods));
    //
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "src/style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    g_slice_free(app_widgets, widgets);
    return 0;
}
// #endregion
// #region utils
int randomNumber(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}
AdsItem getAdsItemByID(int goodsID)
{
    int length = -1;
    AdsItem *list = getAllAdsItem(&length);
    for (int i = 0; i < length; i++)
    {
        if (list[i].goodID == goodsID)
            return list[i];
    }
}
void descSortArray(int a[], int n)
{
    int tg;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
}

int getRandom(ItemRandom *data, int length)
{
    int total = 0;
    int distribution[length];
    for (int i = 0; i < length; i++)
    {
        total += data[i].weight;
        distribution[i] = total;
    }
    int rand = randomNumber(0, total - 1);
    for (int i = 0; i < length; i++)
    {
        if (rand < distribution[i])
        {
            return i;
            break;
        }
    }
    return -1;
}
void randomAds(int count, ItemRandom *arrRandom, int lengthArr, int result[])
{
    for (int i = 0; i < count; i++)
    {
        if (!lengthArr)
            break;
        result[i] = getRandom(arrRandom, lengthArr);
    }
}
Goods getSelectedGoods(int position, app_widgets *app_wdgts)
{
    Goods *listGoods;
    int lengthGoods = 0;
    int canNext = 0;
    gchar *selectedCate;
    gchar *selectedSort;
    selectedCate = gtk_combo_box_get_active_id(app_wdgts->w_wShopping_cbxCategoryShopping);
    selectedSort = gtk_combo_box_get_active_id(app_wdgts->w_wShopping_cbxSortShopping);
    int numberAdsItem = 0;
    for (int i = 0; i < 3; i++)
    {
        if (listStatusAds[i][0])
            numberAdsItem += 1;
    }
    if (position >= 1 && position <= 3 && listStatusAds[position - 1][0])
    {
        return getGoodsByID(listStatusAds[position - 1][1]);
    }
    if (isSearchByWords)
    {
        gchar *txtName;
        txtName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wShopping_txtNameShopping));
        listGoods = getGoodsByName(txtName, atoi(selectedCate), 12 - numberAdsItem, currentPageShopping, &canNext, &lengthGoods, atoi(selectedSort));
    }
    else
    {
        listGoods = getGoods(atoi(selectedCate), 12 - numberAdsItem, currentPageShopping, &canNext, &lengthGoods, atoi(selectedSort));
    }
    return listGoods[position - 1 - numberAdsItem];
    // if (position <= lengthGoods)
    //     return listGoods[position - 1 - numberAdsItem];
    // else
    // {
    //     g_print("error getSelectedGoods pos: %d leng: %d \n", position, lengthGoods);
    //     return;
    // }
}
void addCart(int position, app_widgets *app_wdgts)
{

    Goods currentGoods = getSelectedGoods(position, app_wdgts);
    if (position >= 1 && position <= 3)
    {
        if (listStatusAds[position - 1][0])
        {
            // g_print("processing\n");
            AdsItem item = getAdsItemByID(currentGoods.id);
            if (item.budget - item.money <= 0)
            {
                // g_print("processing ownerID %d goodsID %s\n", currentGoods.ownerID, currentGoods.name);
                listStatusAds[position - 1][0] = 0;
                deleteAdsItem(currentGoods.ownerID, currentGoods.id);
            }
            else
            {
                // g_print("processing2\n");
                updateAdsItem(currentGoods.ownerID, currentGoods.id, item.budget - item.money);
            }
        }
    }
    listCart[lengthListCart - 1] = currentGoods;
    lengthListCart++;
    listCart = (Goods *)realloc(listCart, lengthListCart * sizeof(Goods));
    gchar sizeCart[20];
    sprintf(sizeCart, "%d", lengthListCart - 1);
    gchar temp[40];
    strcpy(temp, "Thanh Toán (");
    strcat(temp, sizeCart);
    strcat(temp, ")");
    gtk_label_set_text(app_wdgts->w_wShopping_lblPaymentShopping, temp);
}
void resetShopping(app_widgets *app_wdgts)
{
    gtk_combo_box_text_remove_all(app_wdgts->w_wShopping_cbxCategoryShopping);
    gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wShopping_txtNameShopping), "");
    isSearchByWords = FALSE;
    gtk_widget_set_sensitive(app_wdgts->w_wShopping_btnRegisterShopping, TRUE);
    currentPageShopping = 1;
}
void resetManage(app_widgets *app_wdgts)
{
    gtk_combo_box_text_remove_all(app_wdgts->w_wManageGoods_cbxCategoryAddManageGoods);
    gtk_combo_box_text_remove_all(app_wdgts->w_wManageGoods_cbxCategoryEditManageGoods);
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
void reloadBoxManage(app_widgets *app_wdgts)
{
    //reload box goods
    gtk_text_buffer_set_text(app_wdgts->w_wManageGoods_txtListManageGoods, "", -1);
    int length = -1;
    Goods *listGoods;
    char tempName[30];
    strcpy(tempName, "Xin chào ");
    strcat(tempName, currentUser.name);
    strcat(tempName, "! ");
    gtk_label_set_text(app_wdgts->w_wManageGoods_lblNameManageGoods, tempName);
    listGoods = getGoodsByOwnerID(currentUser.id, &length);
    if (length > 0)
    {
        GtkTextIter iter;
        long totalMoney = 0;
        gchar temp[9999];
        for (int i = 0; i < length; i++)
        {
            strcpy(temp, "------ID:");
            char tempID[20];
            sprintf(tempID, "%d", listGoods[i].id);
            strcat(temp, tempID);
            strcat(temp, "---------\n");
            strcat(temp, "Tên SP:");
            strcat(temp, listGoods[i].name);
            strcat(temp, "\nGiá:");
            strcat(temp, formatNumber(listGoods[i].price));
            strcat(temp, "\nDiscount:");
            sprintf(tempID, "%d", listGoods[i].discount);
            strcat(temp, tempID);
            //todo load cate
            strcat(temp, "\nLoại SP:");
            strcat(temp, getNameCategory(listGoods[i].categoryID));
            strcat(temp, "\n");
            gtk_text_buffer_get_start_iter(app_wdgts->w_wManageGoods_txtListManageGoods, &iter);
            gtk_text_buffer_insert(app_wdgts->w_wManageGoods_txtListManageGoods, &iter, temp, -1);
        }
    }
    ///
}
void reloadBoxCart(app_widgets *app_wdgts)
{
    //reload list box
    gtk_text_buffer_set_text(app_wdgts->w_wCart_txtListCart, "", -1);
    GtkTextIter iter;
    int length = 0;
    long totalMoney = 0;
    gchar temp[9999];
    for (int i = 0; i < lengthListCart - 1; i++)
    {
        strcpy(temp, "------ID:");
        char tempID[20];
        sprintf(tempID, "%d", listCart[i].id);
        strcat(temp, tempID);
        strcat(temp, "------");
        strcat(temp, listCart[i].name);
        strcat(temp, "------");
        strcat(temp, "\n");
        strcat(temp, "Giá: ");
        strcat(temp, formatNumber(listCart[i].price * (100 - listCart[i].discount) / 100));
        strcat(temp, "\n");
        totalMoney += listCart[i].price * (100 - listCart[i].discount) / 100;
        gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
        gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
    }
    strcpy(temp, "Tổng số tiền:");
    strcat(temp, formatNumber(totalMoney));
    strcat(temp, "\n");
    Coupon coupon;
    coupon = getCoupon(currentUser.id == 0 ? -1 : currentUser.id);
    if (coupon.ownerID != NULL)
    {
        strcat(temp, "Mã giảm giá ");
        strcat(temp, coupon.couponName);
        gchar strDiscount[10];
        sprintf(strDiscount, "%d", coupon.discount);
        strcat(temp, " được giảm ");
        strcat(temp, strDiscount);
        strcat(temp, " % \n");
        strcat(temp, "Số tiền phải thanh toán:");
        strcat(temp, formatNumber(totalMoney * (100 - coupon.discount) / 100));
        strcat(temp, "\n");
    }
    gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
    gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
}
void reset()
{
    turnBack_6 = -1;
    turnBack_5 = -1;
    turnBack_4 = -1;
    turnBack_3 = -1;
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
    turnBack_6 = turnBack_5;
    turnBack_5 = turnBack_4;
    turnBack_4 = turnBack_3;
    turnBack_3 = turnBack_2;
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
    case 8:
        gtk_widget_show(app_wdgts->w_wCart);
        break;
    default:
        break;
    }
    // g_print("%d", turnBack);
    turnBack = turnBack_2;
    turnBack_2 = turnBack_3;
    turnBack_3 = turnBack_4;
    turnBack_4 = turnBack_5;
    turnBack_5 = turnBack_6;
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
        if (isTurnBackCart)
        {
            isTurnBackCart = FALSE;
            on_window_delete_event(app_wdgts->w_wLogin, NULL, app_wdgts);
        }
        else
        {
            setTurnBackWindow(1);
            gtk_widget_hide(app_wdgts->w_wLogin);
            gtk_widget_show(app_wdgts->w_wCustomer);
        }
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
    isTurnBackShopping = TRUE;
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wRegister);
}
void on_btnPayShopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    if (lengthListCart == 1)
    {
        show_msg(app_wdgts, "Giỏ hàng rỗng, khổng thể thanh toán");
    }
    else
    {
        setTurnBackWindow(2);
        gtk_widget_hide(app_wdgts->w_wShopping);
        gtk_widget_show(app_wdgts->w_wCart);
    }
}
void on_btnTurnBackShopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wShopping, NULL, app_wdgts);
}
void on_btnSelect1Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(1, app_wdgts);
}
void on_btnSelect2Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(2, app_wdgts);
}
void on_btnSelect3Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(3, app_wdgts);
}
void on_btnSelect4Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(4, app_wdgts);
}
void on_btnSelect5Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(5, app_wdgts);
}
void on_btnSelect6Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(6, app_wdgts);
}
void on_btnSelect7Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(7, app_wdgts);
}
void on_btnSelect8Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(8, app_wdgts);
}
void on_btnSelect9Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(9, app_wdgts);
}
void on_btnSelect10Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(10, app_wdgts);
}
void on_btnSelect11Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(11, app_wdgts);
}
void on_btnSelect12Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(12, app_wdgts);
}
void on_btnPayNow1Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(1, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow2Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(2, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow3Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(3, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow4Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(4, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow5Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(5, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow6Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(6, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow7Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(7, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow8Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(8, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow9Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(9, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow10Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(10, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow11Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(11, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}
void on_btnPayNow12Shopping_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    addCart(12, app_wdgts);
    setTurnBackWindow(2);
    gtk_widget_hide(app_wdgts->w_wShopping);
    gtk_widget_show(app_wdgts->w_wCart);
}

void on_cbxCategoryShopping_changed(GtkWidget *widget, app_widgets *app_wdgts)
{
    //check type Search
    gchar *txtName;
    txtName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wShopping_txtNameShopping));
    if (txtName == NULL || txtName[0] == '\0')
    {
        isSearchByWords = FALSE;
    }
    else
    {
        isSearchByWords = TRUE;
    }
    //
    gchar *selectedCate;
    selectedCate = gtk_combo_box_get_active_id(widget);
    if (selectedCate != NULL)
    {
        currentPageShopping = 1;
        showPageDataShopping(1, app_wdgts);
    }
}
void on_cbxSortShopping_changed(GtkWidget *widget, app_widgets *app_wdgts)
{
    //check type Search
    gchar *txtName;
    txtName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wShopping_txtNameShopping));
    if (txtName == NULL || txtName[0] == '\0')
    {
        isSearchByWords = FALSE;
    }
    else
    {
        isSearchByWords = TRUE;
    }
    //
    gchar *selectedSort;
    selectedSort = gtk_combo_box_get_active_id(widget);
    if (selectedSort != NULL)
    {
        currentPageShopping = 1;
        showPageDataShopping(1, app_wdgts);
    }
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

void showBoxGoods(int boxID, Goods goods, app_widgets *app_wdgts, int isAds)
{
    setBoxShoppingSensitive(boxID, TRUE, app_wdgts);
    gchar *goodsName;
    gchar goodsPrice[20];
    //
    //style for original
    PangoAttribute *strike = pango_attr_strikethrough_new(TRUE);
    PangoAttrList *listAttrOriginal = pango_attr_list_new();
    pango_attr_list_insert(listAttrOriginal, strike);

    //style for sale
    PangoAttribute *foreGround = pango_attr_foreground_new(65535, 0, 0);
    PangoFontDescription *pangoFont = pango_font_description_new();
    pango_font_description_set_absolute_size(pangoFont, 25 * PANGO_SCALE);
    PangoAttribute *fontDesc = pango_attr_font_desc_new(pangoFont);
    PangoAttrList *listAttrSale = pango_attr_list_new();
    pango_attr_list_ref(listAttrSale);
    pango_attr_list_insert(listAttrSale, foreGround);
    pango_attr_list_insert(listAttrSale, fontDesc);
    //style for ads
    PangoAttribute *foreGroundAds = pango_attr_foreground_new(65535, 0, 0);
    PangoFontDescription *pangoFontAds = pango_font_description_new();
    pango_font_description_set_absolute_size(pangoFontAds, 18 * PANGO_SCALE);
    PangoAttribute *fontDescAds = pango_attr_font_desc_new(pangoFontAds);
    PangoAttrList *listAttrAds = pango_attr_list_new();
    pango_attr_list_ref(listAttrAds);
    pango_attr_list_insert(listAttrAds, foreGroundAds);
    pango_attr_list_insert(listAttrAds, fontDescAds);

    //reset
    PangoAttribute *foreGroundReset = pango_attr_foreground_new(77 * 256, 80 * 256, 89 * 256);
    PangoFontDescription *pangoFontReset = pango_font_description_new();
    pango_font_description_set_absolute_size(pangoFontReset, 18 * PANGO_SCALE);
    PangoAttribute *fontDescReset = pango_attr_font_desc_new(pangoFontReset);
    PangoAttrList *listAttrReset = pango_attr_list_new();
    pango_attr_list_ref(listAttrReset);
    pango_attr_list_insert(listAttrReset, foreGroundReset);
    pango_attr_list_insert(listAttrReset, fontDescReset);
    switch (boxID)
    {
    case 1:

        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice1Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_txtItem1Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice1Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice1Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice1Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice1Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, goodsPrice);
        }
        if (isAds)
        {
            strcpy(goodsName, goods.name);
            strcat(goodsName, "(QC)");
            gtk_label_set_attributes(app_wdgts->w_wShopping_txtItem1Shopping, listAttrAds);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem1Shopping, goodsName);
        break;
    case 2:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice2Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_txtItem2Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice2Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice2Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice2Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice2Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, goodsPrice);
        }
        if (isAds)
        {
            strcpy(goodsName, goods.name);
            strcat(goodsName, "(QC)");
            gtk_label_set_attributes(app_wdgts->w_wShopping_txtItem2Shopping, listAttrAds);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem2Shopping, goodsName);
        break;
    case 3:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice3Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_txtItem3Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice3Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice3Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice3Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice3Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, goodsPrice);
        }
        if (isAds)
        {
            strcpy(goodsName, goods.name);
            strcat(goodsName, "(QC)");
            gtk_label_set_attributes(app_wdgts->w_wShopping_txtItem3Shopping, listAttrAds);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem3Shopping, goodsName);
        break;
    case 4:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice4Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice4Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice4Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice4Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice4Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem4Shopping, goodsName);
        break;
    case 5:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice5Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice5Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice5Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice5Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice5Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem5Shopping, goodsName);
        break;
    case 6:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice6Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice6Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice6Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice6Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice6Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem6Shopping, goodsName);
        break;
    case 7:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice7Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice7Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice7Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice7Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice7Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem7Shopping, goodsName);
        break;
    case 8:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice8Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice8Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice8Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice8Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice8Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem8Shopping, goodsName);
        break;
    case 9:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice9Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice9Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice9Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice9Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice9Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem9Shopping, goodsName);
        break;
    case 10:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice10Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice10Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice10Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice10Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice10Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem10Shopping, goodsName);
        break;
    case 11:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice11Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice11Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice11Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice11Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice11Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem11Shopping, goodsName);
        break;
    case 12:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice12Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, listAttrReset);
        if (goods.discount != 0)
        {
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, listAttrOriginal);
            gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice12Shopping, listAttrSale);
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice12Shopping, TRUE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, goodsPrice);
            gtk_label_set_text(app_wdgts->w_wShopping_lblSalePrice12Shopping, formatNumber(goods.price * (100 - goods.discount) / 100));
        }
        else
        {
            goodsName = goods.name;
            strcpy(goodsPrice, formatNumber(goods.price));
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice12Shopping, FALSE);
            gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, TRUE);
            gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, goodsPrice);
        }
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem12Shopping, goodsName);
        break;
    default:
        break;
    }
}

void showPageDataShopping(int page, app_widgets *app_wdgts)
{
    for (int i = 1; i < 13; i++)
    {
        resetFormatBoxShopping(i, app_wdgts);
        setBoxShoppingSensitive(i, FALSE, app_wdgts);
    }
    Goods *listGoods;
    int lengthGoods = 0;
    int canNext = 0;
    int numberOfItemCanShow = 0;
    listStatusAds[0][0] = 0;
    listStatusAds[1][0] = 0;
    listStatusAds[2][0] = 0;
    listStatusAds[0][1] = 0;
    listStatusAds[1][1] = 0;
    listStatusAds[2][1] = 0;
    gchar *selectedCate;
    gchar *selectedSort;
    selectedCate = gtk_combo_box_get_active_id(app_wdgts->w_wShopping_cbxCategoryShopping);
    selectedSort = gtk_combo_box_get_active_id(app_wdgts->w_wShopping_cbxSortShopping);
    if (isSearchByWords)
    {
        gchar *txtName;
        txtName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wShopping_txtNameShopping));
        listGoods = getGoodsByName(txtName, atoi(selectedCate), 12, page, &canNext, &lengthGoods, atoi(selectedSort));
    }
    else
    {
        //process ads
        deleteAdsItemBudget(minMoneyAds * 0.6);
        int length = -1;

        AdsItem *listAdsItem = getAllAdsItem(&length);
        if (length > 0)
        {
            srand((int)time(0));
            ItemRandom listRandom[length];
            for (int i = 0; i < length; i++)
            {
                listRandom[i].goodsID = listAdsItem[i].goodID;
                if (listAdsItem[i].money >= listAdsItem[i].budget)
                {
                    listRandom[i].weight = listAdsItem[i].money;
                    listRandom[i].weight += getGoodsSaleCount(listAdsItem[i].ownerID, listAdsItem[i].goodID) * 10;
                }
                else
                {
                    listRandom[i].weight = listAdsItem[i].budget;
                }
            }
            int count = 100;
            int result[count];
            randomAds(count, listRandom, length, result);
            int frequency[length];
            for (int i = 0; i < length; i++)
            {
                frequency[i] = 0;
            }
            for (int i = 0; i < count; i++)
            {
                frequency[result[i]] += 1;
            }
            // for (int i = 0; i < length; i++)
            // {
            //     g_print("So lan xuat hien cua goodsID %d la: %d\n", listRandom[i].goodsID, frequency[i]);
            // }

            int listItemCanShow[3] = {0, 0, 0};
            int max[3] = {0, 0, 0};

            for (int i = 0; i < length; i++)
            {
                if (frequency[i] > max[0])
                {
                    max[0] = frequency[i];
                    listItemCanShow[0] = i;
                }
                else if (frequency[i] <= max[0] && frequency[i] > max[1])
                {
                    max[1] = frequency[i];
                    listItemCanShow[1] = i;
                }
                else if (frequency[i] <= max[1] && frequency[i] > max[2])
                {
                    max[2] = frequency[i];
                    listItemCanShow[2] = i;
                }
                if (frequency[i] != 0)
                    numberOfItemCanShow += 1;
            }
            numberOfItemCanShow = numberOfItemCanShow > 3 ? 3 : numberOfItemCanShow;
            for (int i = 0; i < numberOfItemCanShow; i++)
            {
                listStatusAds[i][0] = 1;
                listStatusAds[i][1] = listRandom[listItemCanShow[i]].goodsID;
                // g_print("goods show: %s\n", getGoodsByID(listRandom[listItemCanShow[i]].goodsID).name);
                showBoxGoods(i + 1, getGoodsByID(listRandom[listItemCanShow[i]].goodsID), app_wdgts, 1);
            }
        }
        //
        listGoods = getGoods(atoi(selectedCate), 12 - numberOfItemCanShow, page, &canNext, &lengthGoods, atoi(selectedSort));
    }

    if (canNext == 1)
    {
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_btnNextShopping, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_btnNextShopping, FALSE);
    }
    if (page != 1)
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_btnBackShopping, TRUE);
    else
        gtk_widget_set_sensitive(app_wdgts->w_wShopping_btnBackShopping, FALSE);
    //limit length per page
    if (lengthGoods > 12)
        lengthGoods = 12;
    // for (int i = 0; i < lengthGoods; i++)
    // {
    //     g_print("ID:%d => Ten san pham: %s => Gia: %d => category: %d \n", listGoods[i].id, listGoods[i].name, listGoods[i].price, listGoods[i].categoryID);
    // }

    for (int i = numberOfItemCanShow; i < lengthGoods + numberOfItemCanShow; i++)
    {
        showBoxGoods(i + 1, listGoods[i - numberOfItemCanShow], app_wdgts, 0);
    }
}
void on_btnNextShopping_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    currentPageShopping = currentPageShopping + 1;
    showPageDataShopping(currentPageShopping, app_wdgts);
}

void on_btnBackShopping_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    currentPageShopping = currentPageShopping - 1;
    showPageDataShopping(currentPageShopping, app_wdgts);
}

void resetFormatBoxShopping(int position, app_widgets *app_wdgts)
{
    //reset style
    PangoAttribute *foreGroundReset = pango_attr_foreground_new(0, 0, 0);
    PangoFontDescription *pangoFontReset = pango_font_description_new();
    pango_font_description_set_absolute_size(pangoFontReset, 18 * PANGO_SCALE);
    PangoAttribute *fontDescReset = pango_attr_font_desc_new(pangoFontReset);
    PangoAttrList *listAttrReset = pango_attr_list_new();
    pango_attr_list_ref(listAttrReset);
    pango_attr_list_insert(listAttrReset, foreGroundReset);
    pango_attr_list_insert(listAttrReset, fontDescReset);
    switch (position)
    {
    case 1:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice1Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice1Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice1Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem1Shopping, "");
        break;
    case 2:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice2Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice2Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice2Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem2Shopping, "");
        break;
    case 3:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice3Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice3Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice3Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem3Shopping, "");
        break;
    case 4:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice4Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice4Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice4Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem4Shopping, "");
        break;
    case 5:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice5Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice5Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice5Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem5Shopping, "");
        break;
    case 6:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice6Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice6Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice6Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem6Shopping, "");
        break;
    case 7:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice7Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice7Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice7Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem7Shopping, "");
        break;
    case 8:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice8Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice8Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice8Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem8Shopping, "");
        break;
    case 9:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice9Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice9Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice9Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem9Shopping, "");
        break;
    case 10:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice10Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice10Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice10Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem10Shopping, "");
        break;
    case 11:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice11Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice11Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice11Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem11Shopping, "");
        break;
    case 12:
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblSalePrice12Shopping, listAttrReset);
        gtk_label_set_attributes(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, listAttrReset);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblSalePrice12Shopping, FALSE);
        gtk_widget_set_visible(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, TRUE);
        gtk_label_set_text(app_wdgts->w_wShopping_lblOriginalPrice12Shopping, "");
        gtk_label_set_text(app_wdgts->w_wShopping_txtItem12Shopping, "");
        break;

    default:
        break;
    }
}
void on_btnSearchShopping_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    //check type Search
    gchar *txtName;
    txtName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wShopping_txtNameShopping));
    if (txtName == NULL || txtName[0] == '\0')
    {
        isSearchByWords = FALSE;
    }
    else
    {
        isSearchByWords = TRUE;
    }
    showPageDataShopping(1, app_wdgts);
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
    int lengthCate = 0;
    char tempStr[4];
    listCate = getCategory(&lengthCate);
    gtk_combo_box_text_insert(app_wdgts->w_wShopping_cbxCategoryShopping, 0, "0", "Tất cả");
    for (int i = 0; i < lengthCate; i++)
    {
        sprintf(tempStr, "%d", (listCate + i)->id);
        gtk_combo_box_text_insert(app_wdgts->w_wShopping_cbxCategoryShopping, i + 1, tempStr, (listCate + i)->name);
    }
    gtk_combo_box_set_active(app_wdgts->w_wShopping_cbxCategoryShopping, 0);

    // listGoods = getAllGoods(&lengthGoods);
    //load goods
    Goods *listGoods;
    int lengthGoods = 0;
    int canNext = 0;

    listGoods = getGoods(listCate[0].id, 12, 1, &canNext, &lengthGoods, 1);
    // g_print("can Next: %d\n", canNext);
    // for (int i = 0; i < lengthGoods; i++)
    // {
    //     g_print("ID:%d => Ten san pham: %s => Gia: %d => category: %d \n", listGoods[i].id, listGoods[i].name, listGoods[i].price, listGoods[i].categoryID);
    // }
    //
    showPageDataShopping(1, app_wdgts);
}
// #endregion
// #region Handle event window_register
void on_btn_signup_register_key_press_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    on_btn_signup_register_clicked(widget, app_wdgts);
}
void on_btn_signup_register_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gchar *txtUserRegister = 0;

    gchar *txtPasswordRegister = 0;
    gchar *txtRepasswordRegister = 0;
    gchar *cbxTypeRegister = 0;
    gchar *txtPhoneNumberRegister = 0;
    int type = 0;
    txtUserRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtUserRegister));
    gchar *txtFullNameRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtFullNameRegister));
    txtPasswordRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtPasswordRegister));
    txtRepasswordRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtRepasswordRegister));
    gchar *txtAddressRegister = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wRegister_txtAddressRegister));
    cbxTypeRegister = gtk_combo_box_get_active_id(app_wdgts->w_wRegister_cbxTypeRegister);
    txtPhoneNumberRegister = gtk_entry_get_text(app_wdgts->w_wRegister_txtPhoneNumberRegister);
    type = atoi(cbxTypeRegister);
    if (txtUserRegister[0] == '\0' || txtFullNameRegister[0] == '\0' || txtPasswordRegister[0] == '\0' || txtRepasswordRegister[0] == '\0' || txtAddressRegister[0] == '\0' || txtPhoneNumberRegister[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ!");
        return;
    }
    int flag = getRegister(txtUserRegister, txtFullNameRegister, txtPasswordRegister, txtRepasswordRegister, txtAddressRegister, txtPhoneNumberRegister, type);
    switch (flag)
    {
    case 1:
        switch (type)
        {
        case 1:
            //reset register
            gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wRegister_txtUserRegister), "");
            gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wRegister_txtFullNameRegister), "");
            gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wRegister_txtPasswordRegister), "");
            gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wRegister_txtRepasswordRegister), "");
            gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wRegister_txtAddressRegister), "");
            gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wRegister_txtPhoneNumberRegister), "");
            //
            currentUser = getUser(txtUserRegister);
            if (isTurnBackShopping)
            {
                on_window_delete_event(app_wdgts->w_wRegister, NULL, app_wdgts);
                isTurnBackShopping = FALSE;
            }
            else if (isTurnBackCart)
            {
                turnBack = 2;
                turnBack_2 = 1;
                turnBack_3 = -1;
                turnBack_4 = -1;
                turnBack_5 = -1;
                turnBack_6 = -1;
                gtk_widget_show(app_wdgts->w_wCart);
                gtk_widget_hide(app_wdgts->w_wRegister);
                isTurnBackCart = FALSE;
            }
            else
            {
                setTurnBackWindow(1);
                gtk_widget_hide(app_wdgts->w_wRegister);
                gtk_widget_show(app_wdgts->w_wCustomer);
            }

            break;
        case 2:
            currentUser = getUser(txtUserRegister);
            setTurnBackWindow(1);
            gtk_widget_hide(app_wdgts->w_wRegister);
            gtk_widget_show(app_wdgts->w_wSeller);
            break;
        default:
            break;
        }
        break;
    case 2:
        show_msg(app_wdgts, "Loại tài khoản không hợp lệ");
        break;
    case 3:
        show_msg(app_wdgts, "Địa chỉ không hợp lệ");
        break;
    case 4:
        show_msg(app_wdgts, "Mật khảu nhập lại không đúng");
        break;
    case 5:
        show_msg(app_wdgts, "Mật khẩu không hợp lệ");
        break;
    case 6:
        show_msg(app_wdgts, "Họ và tên không hợp lệ");
        break;
    case 7:
        show_msg(app_wdgts, "Tài khoản không hợp lệ (chỉ chứa các kí tự từ A->Z,a->z,0->9)");
        break;
    case 8:
        show_msg(app_wdgts, "Tài khoản đã tồn tại");
        break;
    case 9:
        show_msg(app_wdgts, "Số điện thoại không hợp lệ");
        break;
    default:
        break;
    }
}
void on_btnTurnBackRegister_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wRegister, NULL, app_wdgts);
}
// #endregion
// #region Handle event window_customer
void on_btnViewPurchaseHistoryCustomer_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_wPurchaseHistory);
}

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
    strcat(joinedStr, formatNumber(currentUser.balance));
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
    gtk_widget_hide(app_wdgts->w_wCustomer);
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
        int flag = changePassword(currentUser.id, txtNewPassword);
        switch (flag)
        {
        case 2:
            //id khong ton tai
            show_msg(app_wdgts, "Lỗi hệ thống!");
            break;
        case 1:
            currentUser = getUser(currentUser.userName);
            show_msg(app_wdgts, "Đổi mật khẩu thành công!");
            gtk_widget_hide(app_wdgts->w_wChangePassword);
            break;
        case 3:
            show_msg(app_wdgts, "Mật khẩu mới phải từ 3->15 kí tự!");
        default:
            break;
        }
    }
}
// #endregion
// #region Handle event window_changeInfo
gboolean on_window_changeInfo_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
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
    gtk_entry_set_text(app_wdgts->w_wChangeInfo_txtPhoneNumberChangeInfo, currentUser.phoneNum);
}
void on_btnClickUpdateChangeInfo_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtAddress = 0;
    gchar *txtFullName = 0;
    gchar *txtPhoneNumber = 0;
    txtAddress = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangeInfo_txtAddressChangeInfo));
    txtFullName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangeInfo_txtFullNameChangeInfo));
    txtPhoneNumber = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wChangeInfo_txtPhoneNumberChangeInfo));
    if (txtFullName[0] == '\0' || txtAddress == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ thông tin!");
    }
    else
    {
        // g_print("%s=%s=%s", txtFullName, txtAddress, txtPhoneNumber);
        int flag = changeInformation(currentUser.id, txtFullName, txtAddress, txtPhoneNumber);
        switch (flag)
        {
        case 1:
            currentUser = getUser(currentUser.userName);
            show_msg(app_wdgts, "Cập nhật thành công!");
            gtk_widget_hide(app_wdgts->w_wChangeInfo);
            break;
        case 2:
            //id khong ton tai
            show_msg(app_wdgts, "Lỗi hệ thống!");
            break;
        case 3:
            show_msg(app_wdgts, "Tên mới không hợp lệ!");
            break;
        case 4:
            show_msg(app_wdgts, "Địa chỉ không hợp lệ!");
            break;
        case 5:
            show_msg(app_wdgts, "Số điện thoại không hợp lệ!");
            break;
        default:
            break;
        }
    }
}
// #endregion
// #region Handle event window_seller
void on_btnReportSeller_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    setTurnBackWindow(6);
    gtk_widget_show(app_wdgts->w_wReport);
    gtk_widget_hide(app_wdgts->w_wSeller);
}
void on_btnTurnBackSeller_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wSeller, NULL, app_wdgts);
}
void on_btnAdsSeller_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    setTurnBackWindow(6);
    gtk_widget_show(app_wdgts->w_wAds);
    gtk_widget_hide(app_wdgts->w_wSeller);
}
void on_btnManageGoodsSeller_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_wManageGoods);
}
void on_window_seller_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar joinedStr[100];
    strcat(joinedStr, "Xin chào ");
    strcat(joinedStr, currentUser.name);
    strcat(joinedStr, " !      Số dư: ");
    strcat(joinedStr, formatNumber(currentUser.balance));
    gtk_label_set_text(app_wdgts->w_wCustomer_lbtNameSeller, joinedStr);
}
void on_btnLogoutSeller_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    logoutUser();
    gtk_widget_hide(app_wdgts->w_wSeller);
    gtk_widget_show(app_wdgts->w_wMain);
    reset();
}

// #endregion
// #region Handle event window_purchaseHistory
gboolean on_window_purchaseHistory_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    // gtk_entry_set_text(app_wdgts->w_wChangePassword_txtCurrentPasswordChange, "");
    gtk_widget_hide(app_wdgts->w_wPurchaseHistory);
    return TRUE;
}
void on_window_purchaseHistory_activate_default(GtkWindow *window, app_widgets *app_wdgts)
{
    // g_print("in");
}
void on_window_purchaseHistory_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_text_buffer_set_text(app_wdgts->w_wPurchaseHistory_txtPurchaseHistory, "", -1);
    PurchaseHistory *listPurchase;
    GtkTextIter iter;
    int length = 0;
    listPurchase = getPurchaseHistory(currentUser.userName, &length);
    gchar temp[9999];
    struct tm lt;
    for (int i = 0; i < length; i++)
    {
        strcpy(temp, "---------");
        strcat(temp, listPurchase[i].name);
        strcat(temp, "------");
        strcat(temp, listPurchase[i].phone);
        strcat(temp, "------");
        strcat(temp, listPurchase[i].address);
        strcat(temp, "------");
        strcat(temp, listPurchase[i].purchaseType);
        strcat(temp, "-----");
        gchar timeStr[80];
        lt = *localtime(&listPurchase[i].time);
        strftime(timeStr, sizeof(timeStr), "%a %Y-%m-%d %H:%M:%S", &lt);
        strcat(temp, timeStr);
        strcat(temp, "-----");
        strcat(temp, "\n");
        for (int j = 0; j < listPurchase[i].sizeListGoods; j++)
        {
            strcat(temp, "\t*");
            strcat(temp, listPurchase[i].listGoods[j]);
            strcat(temp, "\n");
        }
        strcat(temp, "Tổng số tiền: ");
        strcat(temp, formatNumber(listPurchase[i].totalPrice));
        strcat(temp, "\n");
        gtk_text_buffer_get_start_iter(app_wdgts->w_wPurchaseHistory_txtPurchaseHistory, &iter);
        gtk_text_buffer_insert(app_wdgts->w_wPurchaseHistory_txtPurchaseHistory, &iter, temp, -1);
    }

    // gtk_text_buffer_get_start_iter(app_wdgts->w_wPurchaseHistory_txtPurchaseHistory, &iter);
    // gtk_text_buffer_insert(app_wdgts->w_wPurchaseHistory_txtPurchaseHistory, &iter, temp, -1);
    // gtk_text_iter_free(&iter);
}
// #endregion
// #region Handle event window_ManageGoods
gboolean on_window_manageGoods_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtDiscountUpdateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdDeleteMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdEditMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdUpdateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtNameCreateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtNameEditMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtPriceCreateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtPriceEditMangaGoods, "");
    gtk_widget_hide(app_wdgts->w_wManageGoods);
    return TRUE;
}

void on_btnTurnBackManageGoods_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtDiscountUpdateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdDeleteMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdEditMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdUpdateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtNameCreateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtNameEditMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtPriceCreateMangaGoods, "");
    gtk_entry_set_text(app_wdgts->w_wManageGoods_txtPriceEditMangaGoods, "");
    gtk_widget_hide(app_wdgts->w_wManageGoods);
}
void on_btnAddManageGoods_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtNameCreate;
    gchar *txtPriceCreate;
    gchar *txtCategoryID;
    long price;
    int categoryID;
    txtCategoryID = gtk_combo_box_get_active_id(app_wdgts->w_wManageGoods_cbxCategoryAddManageGoods);
    txtNameCreate = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wManageGoods_txtNameCreateMangaGoods));
    txtPriceCreate = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wManageGoods_txtPriceCreateMangaGoods));
    price = atoi(txtPriceCreate);
    categoryID = atoi(txtCategoryID);
    if (price == 0)
    {
        show_msg(app_wdgts, "Vui lòng nhập giá tiền hợp lệ!!");
        return;
    }
    int flag = addGoodsToFile(txtNameCreate, price, categoryID, currentUser.id);
    switch (flag)
    {
    case 1:
        show_msg(app_wdgts, "Thêm thành công!");
        gtk_entry_set_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtNameCreateMangaGoods)), "");
        gtk_entry_set_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtPriceCreateMangaGoods)), "");
        reloadBoxManage(app_wdgts);
        break;
    case 2:
        show_msg(app_wdgts, "Tên món hàng không hợp lệ! Tên hàng phải từ 6 tới 120 ký tự, chỉ được chứa chữ, số, khoảng cách và các ký tự ,.()-");
        break;
    case 3:
        show_msg(app_wdgts, "Giá không hợp lệ!");
        break;
    case 4:
        show_msg(app_wdgts, "Category không tồn tại!");
        break;
    default:
        break;
    }
}
void on_btnEditManageGoods_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtIDGoods;
    gchar *txtName;
    gchar *txtPrice;
    gchar *txtCategoryID;
    txtCategoryID = gtk_combo_box_get_active_id(app_wdgts->w_wManageGoods_cbxCategoryEditManageGoods);
    txtIDGoods = gtk_entry_get_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtIdEditMangaGoods)));
    txtPrice = gtk_entry_get_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtPriceEditMangaGoods)));
    txtName = gtk_entry_get_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtNameEditMangaGoods)));

    if (txtIDGoods[0] == '\0' || txtPrice[0] == '\0' || txtName[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ!");
        return;
    }
    if (!isValidNumber(txtIDGoods) || !isValidNumber(txtPrice))
    {
        show_msg(app_wdgts, "Vui lòng nhập một số hợp lệ!!");
        return;
    }
    if (!isYourGoods(atoi(txtIDGoods), currentUser.id))
    {
        show_msg(app_wdgts, "ID không hợp lệ!");
        return;
    }
    int flag = editGoodsToFile(atoi(txtIDGoods), txtName, atol(txtPrice), atoi(txtCategoryID));
    switch (flag)
    {
    case 1:
        show_msg(app_wdgts, "Sửa thành công!!");
        gtk_entry_set_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtIdEditMangaGoods)), "");
        gtk_entry_set_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtPriceEditMangaGoods)), "");
        gtk_entry_set_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtNameEditMangaGoods)), "");
        reloadBoxManage(app_wdgts);
        break;
    case 2:
        show_msg(app_wdgts, "ID món hàng không tồn tại!");
        break;
    case 3:
        show_msg(app_wdgts, "Tên món hàng không hợp lệ! Tên hàng phải từ 6 tới 120 ký tự, chỉ được chứa chữ, số, khoảng cách và các ký tự ,.()-");
        break;
    case 4:
        show_msg(app_wdgts, "Giá tiền không hợp lệ!!");
        break;
    case 5:
        show_msg(app_wdgts, "Loại hàng hóa lỗi!!");
        break;

    default:
        break;
    }
}
void on_btnUpdateManageGoods_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtIDGoods;
    gchar *txtDiscount;
    int idGoods;
    int discount;

    txtIDGoods = gtk_entry_get_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtIdUpdateMangaGoods)));
    txtDiscount = gtk_entry_get_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtDiscountUpdateMangaGoods)));
    if (txtIDGoods[0] == '\0' || txtDiscount[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ!!");
        return;
    }
    if (!isValidNumber(txtIDGoods) || !isValidNumber(txtDiscount))
    {
        show_msg(app_wdgts, "Vui lòng nhập một số hợp lệ!!");
        return;
    }
    idGoods = atoi(txtIDGoods);
    discount = atoi(txtDiscount);

    if (idGoods == 0)
    {
        show_msg(app_wdgts, "ID vật phẩm không tồn tại");
        return;
    }
    int flag = changeDiscount(idGoods, discount);
    switch (flag)
    {
    case 1:
        show_msg(app_wdgts, "Cập nhật thành công");
        reloadBoxManage(app_wdgts);
        gtk_entry_set_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtIdUpdateMangaGoods)), "");
        gtk_entry_set_text(GTK_ENTRY((app_wdgts->w_wManageGoods_txtDiscountUpdateMangaGoods)), "");
        break;
    case 2:
        show_msg(app_wdgts, "ID vật phẩm không tồn tại");
        break;
    case 3:
        show_msg(app_wdgts, "%% giảm giá không hợp lệ");
        break;

    default:
        break;
    }
}
void on_btnDeleteManageGoods_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtGoodsID = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wManageGoods_txtIdDeleteMangaGoods));
    if (txtGoodsID[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập ID cần xóa!!");
        return;
    }
    // g_print("goodsID : %s\n", txtGoodsID);
    if (!isYourGoods(atoi(txtGoodsID), currentUser.id))
    {
        show_msg(app_wdgts, "ID không hợp lệ!!");
        return;
    }
    int length = -1;
    deleteGoods(atoi(txtGoodsID), &length);
    show_msg(app_wdgts, "Xóa thành công!!");
    reloadBoxManage(app_wdgts);
}
void on_window_manageGoods_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    resetManage(app_wdgts);
    Category *listCate;
    int lengthCate = 0;
    char tempStr[4];

    listCate = getCategory(&lengthCate);
    for (int i = 0; i < lengthCate; i++)
    {
        sprintf(tempStr, "%d", (listCate + i)->id);
        gtk_combo_box_text_insert(app_wdgts->w_wManageGoods_cbxCategoryAddManageGoods, i, tempStr, (listCate + i)->name);
        gtk_combo_box_text_insert(app_wdgts->w_wManageGoods_cbxCategoryEditManageGoods, i, tempStr, (listCate + i)->name);
    }
    gtk_combo_box_set_active(app_wdgts->w_wManageGoods_cbxCategoryAddManageGoods, 0);
    gtk_combo_box_set_active(app_wdgts->w_wManageGoods_cbxCategoryEditManageGoods, 0);
    ////
    reloadBoxManage(app_wdgts);
}
// #endregion
// #region Handle event window_admin
void on_window_admin_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar joinedStr[100];
    strcat(joinedStr, "Xin chào ");
    strcat(joinedStr, currentUser.name);
    strcat(joinedStr, " !");
    gtk_label_set_text(app_wdgts->w_wAdmin_lblNameAdmin, joinedStr);
}
void on_btnAddMoneyAdmin_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_wAddMoney);
}
void on_btnTurnBackAdmin_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wAdmin, NULL, app_wdgts);
}
void on_btnEditCategoryAdmin_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_wCategory);
}
void on_btnLogOutAdmin_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    logoutUser();
    gtk_widget_hide(app_wdgts->w_wAdmin);
    gtk_widget_show(app_wdgts->w_wMain);
    reset();
}
// #endregion
// #region Handle event window_addMoney
gboolean on_window_addMoney_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtDiscountUpdateMangaGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdDeleteMangaGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdEditMangaGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtIdUpdateMangaGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtListManageGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtNameCreateMangaGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtNameEditMangaGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtPriceCreateMangaGoods, "");
    // gtk_entry_set_text(app_wdgts->w_wManageGoods_txtPriceEditMangaGoods, "");
    gtk_widget_hide(app_wdgts->w_wAddMoney);
    return TRUE;
}
void on_btnUpdateAddMoney_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtCash = 0;
    gchar *txtUserName = 0;
    txtCash = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wAddMoney_txtCashAddMoney));
    txtUserName = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wAddMoney_txtUserNameAddMoney));
    int flag = addMoney(txtUserName, txtCash);
    switch (flag)
    {
    case 1:
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wAddMoney_txtCashAddMoney), "");
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wAddMoney_txtUserNameAddMoney), "");
        show_msg(app_wdgts, "Cập nhật thành công");
        break;
    case 2:
        show_msg(app_wdgts, "Tên tài khoản không hợp lệ");
        break;
    case 3:
        show_msg(app_wdgts, "Số tiền không hợp lệ");
        break;
    case 4:
        show_msg(app_wdgts, "Tên tài khoản không tồn tại");
        break;

    default:
        break;
    }
}
// #endregion
// #region Handle event window_category

void on_btnAddCategory_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtNameCategory = 0;
    txtNameCategory = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wCategory_txtNameCategory));
    if (txtNameCategory[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ");
    }
    else
    {
        int flag = addCategoryToFile(txtNameCategory);
        switch (flag)
        {
        case 1:
            //reset
            gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCategory_txtNameCategory), "");
            gtk_combo_box_text_remove_all(app_wdgts->w_wCategory_cbxCategory);
            Category *listCate;
            int lengthCate = 0;
            char tempStr[4];
            listCate = getCategory(&lengthCate);
            for (int i = 0; i < lengthCate; i++)
            {
                sprintf(tempStr, "%d", (listCate + i)->id);
                gtk_combo_box_text_insert(app_wdgts->w_wCategory_cbxCategory, i, tempStr, (listCate + i)->name);
            }
            gtk_combo_box_set_active(app_wdgts->w_wCategory_cbxCategory, 0);
            show_msg(app_wdgts, "Thêm thành công !!");
            break;
        case 2:
            show_msg(app_wdgts, "Tên hàng hóa không hợp lệ! Tên chỉ được chứa chữ số và khoảng cách (2 - 100 ký tự)");
            break;
        default:
            break;
        }
    }
}
gboolean on_window_category_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_widget_hide(app_wdgts->w_wCategory);
}
void on_btnDeleteCategory_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    // gtk_widget_show(app_wdgts->w_wAddMoney);
    gchar *selectedName;
    gchar *selectedID;
    selectedName = gtk_combo_box_text_get_active_text(app_wdgts->w_wCategory_cbxCategory);
    selectedID = gtk_combo_box_get_active_id(app_wdgts->w_wCategory_cbxCategory);
    int lengthCate;
    Category *listCate;
    //set temp lengthCate, i dont need get listGoods after deleted
    deleteGoodsByCate(atoi(selectedID), &lengthCate);
    char tempStr[4];
    listCate = deleteCategory(selectedName, &lengthCate);

    show_msg(app_wdgts, "Xóa thành công!!!");
    gtk_combo_box_text_remove_all(app_wdgts->w_wCategory_cbxCategory);
    for (int i = 0; i < lengthCate; i++)
    {
        sprintf(tempStr, "%d", (listCate + i)->id);
        gtk_combo_box_text_insert(app_wdgts->w_wCategory_cbxCategory, i, tempStr, (listCate + i)->name);
    }
    gtk_combo_box_set_active(app_wdgts->w_wCategory_cbxCategory, 0);
}
void on_window_category_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_combo_box_text_remove_all(app_wdgts->w_wCategory_cbxCategory);
    Category *listCate;
    int lengthCate = 0;
    char tempStr[4];
    listCate = getCategory(&lengthCate);
    for (int i = 0; i < lengthCate; i++)
    {
        sprintf(tempStr, "%d", (listCate + i)->id);
        gtk_combo_box_text_insert(app_wdgts->w_wCategory_cbxCategory, i, tempStr, (listCate + i)->name);
    }
    gtk_combo_box_set_active(app_wdgts->w_wCategory_cbxCategory, 0);
}
// #endregion
// #region Handle event window_cart
gboolean on_window_cart_delete_event(GtkWidget *widget, GdkEvent *event, app_widgets *app_wdgts)
{
    gtk_widget_hide(app_wdgts->w_wCart);
    return TRUE;
}

void on_btnPayCart_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *txtAddressCart = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wCart_txtAddressCart));
    gchar *txtNameCart = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wCart_txtNameCart));
    gchar *txtPhoneNumber = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wCart_txtPhoneNumberCart));
    gchar *txtCoupon = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wCart_txtCouponCart));
    int method = gtk_toggle_button_get_active(app_wdgts->w_wCart_isCODCart) ? 1 : 2;
    int userID = currentUser.id != 0 ? currentUser.id : -1;
    int flag = -1;
    if (txtPhoneNumber[0] == '\0' || txtNameCart[0] == '\0' || txtAddressCart[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ thông tin!");
        return;
    }
    if (txtCoupon[0] == '\0')
        flag = processCart(txtNameCart, txtAddressCart, txtPhoneNumber, method, listCart, lengthListCart - 1, userID, "-1");
    else
        flag = processCart(txtNameCart, txtAddressCart, txtPhoneNumber, method, listCart, lengthListCart - 1, userID, txtCoupon);
    if (lengthListCart == 1)
    {
        show_msg(app_wdgts, "Giỏ hàng rỗng!!");
        return;
    }
    switch (flag)
    {
    case 1:
        show_msg(app_wdgts, "Thành công!!");
        //

        if (currentUser.id != 0)
        {
            long totalCash = 0;
            for (int i = 0; i < lengthListCart - 1; i++)
            {
                totalCash += listCart[i].price;
            }
            if (totalCash <= 50000)
                addCoupon(currentUser.id, 5, "COUPON5");
            else if (totalCash <= 150000)
                addCoupon(currentUser.id, 10, "COUPON10");
            else if (totalCash <= 350000)
                addCoupon(currentUser.id, 15, "COUPON15");
            else if (totalCash <= 1000000)
                addCoupon(currentUser.id, 20, "COUPON20");
            else
                addCoupon(currentUser.id, 30, "COUPON30");
        }
        //
        if (method == 2)
        {
            currentUser = getUser(currentUser.userName);
            gchar tempLabelBalance[100];
            strcpy(tempLabelBalance, "Số dư:");
            strcat(tempLabelBalance, formatNumber(currentUser.balance));
            gtk_label_set_text(app_wdgts->w_wCart_lblBtnLoginCart, tempLabelBalance);
            gchar joinedStr[100];
            strcat(joinedStr, "Xin chào ");
            strcat(joinedStr, currentUser.name);
            strcat(joinedStr, " !      Số dư: ");
            strcat(joinedStr, formatNumber(currentUser.balance));
            gtk_label_set_text(app_wdgts->w_wCustomer_lbtNameCustomer, joinedStr);
        }
        lengthListCart = 1;
        //reload box
        gtk_text_buffer_set_text(app_wdgts->w_wCart_txtListCart, "", -1);
        GtkTextIter iter;
        int length = 0;
        long totalMoney = 0;
        gchar temp[9999];
        for (int i = 0; i < lengthListCart - 1; i++)
        {
            strcpy(temp, "------ID:");
            char tempID[20];
            sprintf(tempID, "%d", listCart[i].id);
            strcat(temp, tempID);
            strcat(temp, "------");
            strcat(temp, listCart[i].name);
            strcat(temp, "------");
            strcat(temp, "\n");
            strcat(temp, "Giá: ");
            strcat(temp, formatNumber(listCart[i].price * (100 - listCart[i].discount) / 100));
            strcat(temp, "\n");
            totalMoney += listCart[i].price * (100 - listCart[i].discount) / 100;
            gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
            gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
        }
        strcpy(temp, "Tổng số tiền:");
        strcat(temp, formatNumber(totalMoney));
        strcat(temp, "\n");
        gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
        gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
        //reset btn Thanh Toan
        gchar sizeCart[20];
        sprintf(sizeCart, "%d", lengthListCart - 1);
        gchar tempBtn[40];
        strcpy(tempBtn, "Thanh Toán (");
        strcat(tempBtn, sizeCart);
        strcat(tempBtn, ")");
        gtk_label_set_text(app_wdgts->w_wShopping_lblPaymentShopping, tempBtn);
        //
        break;
    case 2:
        show_msg(app_wdgts, "Tên không hợp lệ!!");
        break;
    case 3:
        show_msg(app_wdgts, "Địa chỉ không hợp lệ!!");
        break;
    case 4:
        show_msg(app_wdgts, "Số điện thoại không hợp lệ!!");
        break;
    case 5:
        show_msg(app_wdgts, "Coupon không hợp lệ!!");
        break;
    case 6:
        show_msg(app_wdgts, "Số dư không đủ để thực hiện giao dịch!!");
        break;
    default:
        break;
    }
}
void on_btnCouponCart_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    Coupon coupon;
    coupon = getCoupon(currentUser.id == 0 ? -1 : currentUser.id);
    if (coupon.ownerID == NULL)
    {
        show_msg(app_wdgts, "Không có mã giảm giá nào phù hợp với bạn");
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtCouponCart), "");
        reloadBoxCart(app_wdgts);
    }
    else
    {
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtCouponCart), coupon.couponName);
        reloadBoxCart(app_wdgts);
    }
}
void on_btnDeleteItemCart_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    gchar *str_goodsID = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wCart_txtDeleteIDCart));
    gchar *txtCoupon = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wCart_txtCouponCart));
    int i = 0;
    gboolean isValidNumber = TRUE;
    while (str_goodsID[i] != '\0')
    {
        if (!isNum(str_goodsID[i]))
        {
            isValidNumber = FALSE;
            break;
        }
        i++;
    }
    if (isValidNumber)
    {
        int isValidID = 0;
        for (int i = 0; i < lengthListCart - 1; i++)
        {
            if (listCart[i].id == atoi(str_goodsID))
            {
                isValidID = 1;
                break;
            }
        }
        if (!isValidID)
        {
            show_msg(app_wdgts, "Vui lòng nhập ID hợp lệ!");
            return;
        }

        //real length
        int tempLength = lengthListCart - 1;
        removeElementCart(listCart, &tempLength, atoi(str_goodsID));
        lengthListCart = tempLength + 1;
        if (txtCoupon[0] == '\0')
        {
            //reload box
            gtk_text_buffer_set_text(app_wdgts->w_wCart_txtListCart, "", -1);
            GtkTextIter iter;
            int length = 0;
            long totalMoney = 0;
            gchar temp[9999];
            for (int i = 0; i < lengthListCart - 1; i++)
            {
                strcpy(temp, "------ID:");
                char tempID[20];
                sprintf(tempID, "%d", listCart[i].id);
                strcat(temp, tempID);
                strcat(temp, "------");
                strcat(temp, listCart[i].name);
                strcat(temp, "------");
                strcat(temp, "\n");
                strcat(temp, "Giá: ");
                strcat(temp, formatNumber(listCart[i].price * (100 - listCart[i].discount) / 100));
                strcat(temp, "\n");
                totalMoney += listCart[i].price * (100 - listCart[i].discount) / 100;
                gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
                gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
            }
            strcpy(temp, "Tổng số tiền:");
            strcat(temp, formatNumber(totalMoney));
            strcat(temp, "\n");
            gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
            gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
        }
        else
        {
            reloadBoxCart(app_wdgts);
        }

        //reset btn Thanh Toan
        gchar sizeCart[20];
        sprintf(sizeCart, "%d", lengthListCart - 1);
        gchar tempBtn[40];
        strcpy(tempBtn, "Thanh Toán (");
        strcat(tempBtn, sizeCart);
        strcat(tempBtn, ")");
        gtk_label_set_text(app_wdgts->w_wShopping_lblPaymentShopping, tempBtn);

        //
        // gtk_entry_set_text(app_wdgts->w_wCart_txtCouponCart, "");
        show_msg(app_wdgts, "Xóa 1 vật phẩm ra khỏi giỏ thành công!");
    }
    else
    {
        show_msg(app_wdgts, "ID phải là một số!");
    }
}

void on_btnCancelCart_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    lengthListCart = 1;
    //reset btn Thanh Toan
    gchar sizeCart[20];
    sprintf(sizeCart, "%d", lengthListCart - 1);
    gchar tempBtn[40];
    strcpy(tempBtn, "Thanh Toán (");
    strcat(tempBtn, sizeCart);
    strcat(tempBtn, ")");
    gtk_label_set_text(app_wdgts->w_wShopping_lblPaymentShopping, tempBtn);
    on_window_delete_event(app_wdgts->w_wCart, NULL, app_wdgts);
    //
}
void on_btnLoginCart_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    setTurnBackWindow(8);
    isTurnBackCart = TRUE;
    gtk_widget_hide(app_wdgts->w_wCart);
    gtk_widget_show(app_wdgts->w_wLogin);
}
void on_window_cart_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_text_buffer_set_text(app_wdgts->w_wCart_txtListCart, "", -1);
    gtk_entry_set_text(app_wdgts->w_wCart_txtCouponCart, "");
    gtk_toggle_button_set_active(app_wdgts->w_wCart_isCODCart, TRUE);
    if (currentUser.id == 0)
    {
        gtk_widget_set_sensitive(app_wdgts->w_wCart_btnLoginCart, TRUE);
        gtk_widget_set_sensitive(app_wdgts->w_wCart_isCashCart, FALSE);
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtAddressCart), "");
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtNameCart), "");
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtPhoneNumberCart), "");
        gtk_label_set_text(app_wdgts->w_wCart_lblNameCart, "Xin chào Khách!!");
        gtk_label_set_text(app_wdgts->w_wCart_lblBtnLoginCart, "Đăng nhập ngay để lưu thông tin cho lần sau!");
    }
    else
    {
        gchar tempLabelName[100];
        gchar tempLabelBalance[100];
        strcpy(tempLabelName, "Xin chào: ");
        strcat(tempLabelName, currentUser.name);
        strcat(tempLabelName, " !");
        strcpy(tempLabelBalance, "Số dư:");
        strcat(tempLabelBalance, formatNumber(currentUser.balance));
        gtk_widget_set_sensitive(app_wdgts->w_wCart_btnLoginCart, FALSE);
        gtk_widget_set_sensitive(app_wdgts->w_wCart_isCashCart, TRUE);
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtAddressCart), currentUser.address);
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtNameCart), currentUser.name);
        gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtPhoneNumberCart), currentUser.phoneNum);
        gtk_label_set_text(app_wdgts->w_wCart_lblNameCart, tempLabelName);
        gtk_label_set_text(app_wdgts->w_wCart_lblBtnLoginCart, tempLabelBalance);
    }
    gtk_entry_set_text(GTK_ENTRY(app_wdgts->w_wCart_txtDeleteIDCart), "Nhập ID món hàng cần xóa");
    ///
    //reload box
    gtk_text_buffer_set_text(app_wdgts->w_wCart_txtListCart, "", -1);
    GtkTextIter iter;
    int length = 0;
    long totalMoney = 0;
    gchar temp[9999];
    for (int i = 0; i < lengthListCart - 1; i++)
    {
        strcpy(temp, "------ID:");
        char tempID[20];
        sprintf(tempID, "%d", listCart[i].id);
        strcat(temp, tempID);
        strcat(temp, "------");
        strcat(temp, listCart[i].name);
        strcat(temp, "------");
        strcat(temp, "\n");
        strcat(temp, "Giá: ");
        strcat(temp, formatNumber(listCart[i].price * (100 - listCart[i].discount) / 100));
        strcat(temp, "\n");
        totalMoney += listCart[i].price * (100 - listCart[i].discount) / 100;
        gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
        gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
    }
    strcpy(temp, "Tổng số tiền:");
    strcat(temp, formatNumber(totalMoney));
    strcat(temp, "\n");
    gtk_text_buffer_get_start_iter(app_wdgts->w_wCart_txtListCart, &iter);
    gtk_text_buffer_insert(app_wdgts->w_wCart_txtListCart, &iter, temp, -1);
    ///
}
// #endregion
// #region Handle event window_ads
void on_window_ads_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    //reload box goods
    gtk_text_buffer_set_text(app_wdgts->w_wAds_txtListGoodsAds, "", -1);
    int length = -1;
    Goods *listGoods;
    char tempName[30];
    strcpy(tempName, "Xin chào ");
    strcat(tempName, currentUser.name);
    strcat(tempName, " !");
    long defaultMoney = getAverageMoney();
    if (defaultMoney < minMoneyAds)
        defaultMoney = minMoneyAds;
    gtk_label_set_text(app_wdgts->w_wAds_lblMoneyAds, formatNumber(defaultMoney));
    gtk_label_set_text(app_wdgts->w_wAds_lblNameAds, tempName);
    listGoods = getGoodsByOwnerID(currentUser.id, &length);
    if (length > 0)
    {
        GtkTextIter iter;
        long totalMoney = 0;
        gchar temp[9999];
        for (int i = 0; i < length; i++)
        {
            strcpy(temp, "------ID:");
            char tempID[20];
            sprintf(tempID, "%d", listGoods[i].id);
            strcat(temp, tempID);
            strcat(temp, "---------\n");
            strcat(temp, "Tên SP:");
            strcat(temp, listGoods[i].name);
            strcat(temp, "\nGiá:");
            strcat(temp, formatNumber(listGoods[i].price));
            strcat(temp, "\nDiscount:");
            sprintf(tempID, "%d", listGoods[i].discount);
            strcat(temp, tempID);
            //todo load cate
            strcat(temp, "\nLoại SP:");
            strcat(temp, getNameCategory(listGoods[i].categoryID));
            strcat(temp, "\n");
            gtk_text_buffer_get_start_iter(app_wdgts->w_wAds_txtListGoodsAds, &iter);
            gtk_text_buffer_insert(app_wdgts->w_wAds_txtListGoodsAds, &iter, temp, -1);
        }
    }
    ///
}
void on_btnAddAds_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gchar *txtGoodsID = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wAds_txtGoodsIDAds));
    gchar *txtMoneyAds = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wAds_txtMoneyAds));
    gchar *txtBudgetAds = gtk_entry_get_text(GTK_ENTRY(app_wdgts->w_wAds_txtBudgetAds));

    if (txtGoodsID[0] == '\0' || txtMoneyAds[0] == '\0' || txtBudgetAds[0] == '\0')
    {
        show_msg(app_wdgts, "Vui lòng nhập đầy đủ!!");
        return;
    }
    if (!isValidNumber(txtGoodsID) || !isValidNumber(txtMoneyAds) || !isValidNumber(txtBudgetAds))
    {
        show_msg(app_wdgts, "Vui lòng nhập một số hợp lệ!!");
        return;
    }
    int length = -1, isExistItem = 0;
    int goodsID = atoi(txtGoodsID);
    AdsItem *listItem = getAllAdsItem(&length);

    for (int i = 0; i < length; i++)
    {
        if (listItem[i].goodID == goodsID && listItem[i].ownerID == currentUser.id)
        {
            isExistItem = 1;
            break;
        }
    }
    if (isExistItem == 1)
    {
        show_msg(app_wdgts, "Bạn đã chạy quảng cáo cho sản phẩm này, vui lòng đợi kết thúc!!");
        return;
    }
    if (atoi(txtMoneyAds) < minMoneyAds)
    {
        show_msg(app_wdgts, "Giá thầu quá thấp, vui lòng điều chỉnh lại!!");
        return;
    }
    int flag = addAds(currentUser.id, goodsID, atol(txtBudgetAds), atol(txtMoneyAds));
    switch (flag)
    {
    case 1:
        show_msg(app_wdgts, "Thêm thành công!!");
        break;
    case 2:
        show_msg(app_wdgts, "ID sản phẩm không hợp lệ hoặc không thuộc về bạn!!");
        break;
    case 4:
        show_msg(app_wdgts, "Ngân sách phải lớn hơn giá thầu!!");
        break;
    case 3:
        show_msg(app_wdgts, "Giá thầu phải lớn hơn 0!!");
        break;
    default:
        break;
    }
}
void on_btnTurnBackAds_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wAds, NULL, app_wdgts);
}
// #endregion Handle event window_report
// #region Handle event window_report
void on_btnTurnBackReport_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{
    on_window_delete_event(app_wdgts->w_wReport, NULL, app_wdgts);
}
void on_btnFilterReport_clicked(GtkWidget *widget, app_widgets *app_wdgts)
{

    gtk_text_buffer_set_text(app_wdgts->w_wReport_txtDoanhThuReport, "", -1);
    struct tm startTimeStruct;
    struct tm endTimeStruct;
    time_t startTimestamp;
    time_t endTimestamp;
    guint startYear;
    guint startMonth;
    guint startDay;
    guint endYear;
    guint endMonth;
    guint endDay;
    gtk_calendar_get_date(app_wdgts->w_wReport_startCalendarReport, &startYear, &startMonth, &startDay);
    gtk_calendar_get_date(app_wdgts->w_wReport_endCalendarReport, &endYear, &endMonth, &endDay);

    startMonth += 1; //gtkCalendar month start at 0
    endMonth += 1;   //gtkCalendar month start at 0
    gchar startStr[20];
    gchar endStr[20];
    sprintf(startStr, "%d-%d-%d 00:00:00", startYear, startMonth, startDay);
    sprintf(endStr, "%d-%d-%d 00:00:00", endYear, endMonth, endDay);
    if (strptime(startStr, "%Y-%m-%e %H:%M:%S", &startTimeStruct) != NULL)
    {
        startTimestamp = mktime(&startTimeStruct);
    }
    if (strptime(endStr, "%Y-%m-%e %H:%M:%S", &endTimeStruct) != NULL)
    {
        endTimestamp = mktime(&endTimeStruct);
    }
    int length = -1;
    SalesHistory *list = getSalesHistoryByTime(currentUser.userName, &length, startTimestamp, endTimestamp);
    GtkTextIter iter;
    gchar temp[9999];
    long totalMoney = 0;
    for (int i = 0; i < length; i++)
    {
        totalMoney += list[i].price;
        strcpy(temp, "------ID:");
        char tempID[20];
        sprintf(tempID, "%d", list[i].goodsId);
        strcat(temp, tempID);
        strcat(temp, "---------\n");
        strcat(temp, "Tên SP:");
        strcat(temp, list[i].name);
        strcat(temp, "\nGiá:");
        strcat(temp, formatNumber(list[i].price));
        strcat(temp, "\nLoại sản phẩm:");
        strcat(temp, getNameCategory(list[i].categoryID));
        strcat(temp, "\n");
        gtk_text_buffer_get_start_iter(app_wdgts->w_wReport_txtDoanhThuReport, &iter);
        gtk_text_buffer_insert(app_wdgts->w_wReport_txtDoanhThuReport, &iter, temp, -1);
    }
    strcpy(temp, "Tổng doanh thu: ");
    strcat(temp, formatNumber(totalMoney));
    strcat(temp, "\n");
    gtk_text_buffer_get_start_iter(app_wdgts->w_wReport_txtDoanhThuReport, &iter);
    gtk_text_buffer_insert(app_wdgts->w_wReport_txtDoanhThuReport, &iter, temp, -1);
}
void on_window_report_show(GtkWidget *widget, app_widgets *app_wdgts)
{
    gtk_text_buffer_set_text(app_wdgts->w_wReport_txtDoanhThuReport, "", -1);
}
// #endregion

// called when window is closed
void on_window_destroy()
{
    gtk_main_quit();
}