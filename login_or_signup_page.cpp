#include "login_or_signup_page.h"
#include "ui_login_or_signup_page.h"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "QRegExpValidator"
#include "QMessageBox"
#include "QStringList"
#include "QIcon"
#include "iostream"
#include "QString"
#include "cstring"
using namespace std;

Login_or_SignUp_page::Login_or_SignUp_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_or_SignUp_page)
{
    ui->setupUi(this);

    QStringList list;
    list<<"Choose" << " Iran"<<" United States"<<" United Kingdom"<<" France"<<" Germany"<<" Italy"<<" Ukraine"<<" Russia";
    ui->comboBox_2->addItem(list.at(0));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/iran.image.png"), list.at(1));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/Usa.image.png"), list.at(2));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/Uk.image.jpg"), list.at(3));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/france.image.png"), list.at(4));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/germany.image.png"), list.at(5));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/italy.image.jpg"), list.at(6));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/Ukraine.image.png"), list.at(7));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/russia.image.jpg"), list.at(8));
    ui->comboBox->addItem(list.at(0));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/iran.image.png"), list.at(1));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/Usa.image.png"), list.at(2));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/Uk.image.jpg"), list.at(3));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/france.image.png"), list.at(4));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/germany.image.png"), list.at(5));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/italy.image.jpg"), list.at(6));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/Ukraine.image.png"), list.at(7));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/russia.image.jpg"), list.at(8));


    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\schema2.db");
    database.open();
}

Login_or_SignUp_page::~Login_or_SignUp_page()
{
    delete ui;
}

bool Login_or_SignUp_page::endsWith(const QString &fullString, const QString &ending)
{
    if (fullString.length() < ending.length()) {
           return false;
       }
       return equal(ending.rbegin(), ending.rend(), fullString.rbegin());
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


void Login_or_SignUp_page::on_Login_of_LoginGroupbox_clicked()
{
    QString signUpUsernameTxt = ui->lineEdit->text();
    QString signUpPassTxt = ui->lineEdit_2->text();
    QString signUpPhoneTxt = ui->lineEdit_13->text();


    int invalidCount= 0;
    invalidCount += validate_username(signUpUsernameTxt, ui->Error_label_of_username);
    invalidCount += validate_password(signUpPassTxt, ui->Error_label_of_Password);
    invalidCount += validate_phone(signUpPhoneTxt, ui->Error_label_of_phone_2);

       if(invalidCount==3){
           QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");


            database.setDatabaseName("e:\\schema2.db");

            database.setUserName("Username");
            database.setPassword("Password");

            if (!database.open()) {
                // handle error
            }

            QSqlQuery query(database);

             QString sql = QString("SELECT * FROM Player WHERE Username='%1' AND Password='%2' AND Phone='%3'").arg(signUpUsernameTxt, signUpPassTxt, signUpPhoneTxt);
             query.exec(sql);

             if (query.next()) {
                   // username and password exist in the database
                 QMessageBox::information(this,"The end", "wellcome noobe sag", "Gg");
             } else {
                   // username and password do not exist in the database
                 QMessageBox::warning(this," ","This username or password or phone not exist","try again!");
             }

       }
}


void Login_or_SignUp_page::on_comboBox_2_activated(int index)
{
    switch (index) {

    case 0:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\Y\\o\\u\\r\\ \\C\\o\\u\\n\\t\\r\\y\\?");

        break;

    case 1:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\9\\8-000-000-0000");

        break;

    case 2:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\1-000-000-0000");


        break;

    case 3:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\4\\4-000-000-0000");

        break;

    case 4:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\3\\3-000-000-0000");

        break;

    case 5:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\4\\9-000-000-0000");

        break;

    case 6:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\3\\9-000-000-0000");

        break;

    case 7:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\3\\8\\0-000-000-0000");

        break;

    case 8:

        ui->lineEdit_13->setInputMask(" ");
        ui->lineEdit_13->setInputMask("\\+\\7-000-000-0000");

        break;
    }
}


void Login_or_SignUp_page::on_comboBox_activated(int index)
{
    switch (index) {

    case 0:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\Y\\o\\u\\r\\ \\C\\o\\u\\n\\t\\r\\y\\?");

        break;

    case 1:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\9\\8-000-000-0000");

        break;

    case 2:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\1-000-000-0000");


        break;

    case 3:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\4\\4-000-000-0000");

        break;

    case 4:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\3\\3-000-000-0000");

        break;

    case 5:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\4\\9-000-000-0000");

        break;

    case 6:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\3\\9-000-000-0000");

        break;

    case 7:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\3\\8\\0-000-000-0000");

        break;

    case 8:

        ui->lineEdit_5->setInputMask(" ");
        ui->lineEdit_5->setInputMask("\\+\\7-000-000-0000");

        break;
    }
}

bool Login_or_SignUp_page::validate_phone(QString input_text, QLabel *targetLable)
{
    if((input_text.length()-3) < 11){
        targetLable->setText("invalid phone!");
        return false;
    } else {
        targetLable->setText("");
        return true;
    }
}


void Login_or_SignUp_page::on_lineEdit_13_textChanged(const QString &arg1)
{
    validate_phone(arg1, ui->Error_label_of_phone_2);
}

bool Login_or_SignUp_page::validate_email(QString input_text, QLabel *targetLable)
{
    QRegExp emailRegex("[a-zA-Z0-9@.]+");

    if(input_text==""){
        targetLable->setText("this field not be empty");
        return false;
    }
    if(input_text=="@gmail.com" || input_text=="@email.com" || input_text=="@mail.um.ac"){
        targetLable->setText("use correct email");
        return false;
    }
    if(!emailRegex.exactMatch(input_text)){
        targetLable->setText("invalid character!");
        return false;
    }
    if (endsWith(input_text, "@gmail.com")  || endsWith(input_text, "@email.com") || endsWith(input_text, "@mail.um.ac")) {

        targetLable->setText("");
        qDebug() << "alsdm;amds";
        return true;
    }else{

        targetLable->setText("");
        QMessageBox::warning(this," ","Your email must end with one of the three characters : 1)@gmail.com 2)@email.com 3)@mail.um.ac","try again!");
        return false;
    }
}


void Login_or_SignUp_page::on_SignUp_of_Signup_clicked()
{
       validate_email(ui->lineEdit_6->text(), ui->Error_label_of_Email);
}

