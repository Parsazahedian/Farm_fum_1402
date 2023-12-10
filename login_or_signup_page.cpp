#include "login_or_signup_page.h"
#include "ui_login_or_signup_page.h"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "QRegExpValidator"


Login_or_SignUp_page::Login_or_SignUp_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_or_SignUp_page)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\schema2.db");
    database.open();
}

Login_or_SignUp_page::~Login_or_SignUp_page()
{
    delete ui;
}

bool Login_or_SignUp_page::validate_username(QString input_text, QLabel *targetLable)
{

    if(input_text==""){
        targetLable->setText("this field not be empty");
        return false;
    }
    targetLable->setText("");
    return true;
}

bool Login_or_SignUp_page::validate_password(QString input_text, QLabel *targetLable)
{
    QRegExp passwordRegex("[a-zA-Z0-9]+");

    if(input_text==""){
        targetLable->setText("this field not be empty");
        return false;
    }
    if(!passwordRegex.exactMatch(input_text)){
        targetLable->setText("invalid character!");
        return false;
    }
    targetLable->setText("");
    return true;
}

void Login_or_SignUp_page::on_lineEdit_textChanged(const QString &arg1)
{
    validate_username(arg1, ui->Error_label_of_username);
}

void Login_or_SignUp_page::on_lineEdit_2_textChanged(const QString &arg1)
{
    validate_password(arg1, ui->Error_label_of_Password);
}

