#include "login_or_signup_page.h"
#include "ui_login_or_signup_page.h"

Login_or_SignUp_page::Login_or_SignUp_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_or_SignUp_page)
{
    ui->setupUi(this);
}

Login_or_SignUp_page::~Login_or_SignUp_page()
{
    delete ui;
}
