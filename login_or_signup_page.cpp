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
#include "iomanip"
#include "QSqlError"
#include "QRegularExpression"
using namespace std;

QString cap="";
int Player_number;
Login_or_SignUp_page::Login_or_SignUp_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_or_SignUp_page)
{
    ui->setupUi(this);



    ui->lineEdit_7->setValidator(new QIntValidator);
    ui->lineEdit_5->setValidator(new QIntValidator);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);

    time_t t;
    srand((unsigned)time(&t));
    QString captcha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for(int i=0;i<8;i++){
        cap.push_back(captcha[rand() % 62]);
    }
    ui->label_4->setText(cap);



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
    QString LoginUsernameTxt = ui->lineEdit->text();
    QString LoginPassTxt = ui->lineEdit_2->text();
    QString LoginPhoneTxt = ui->lineEdit_13->text();


    int invalidCount= 0;
    invalidCount += validate_username(LoginUsernameTxt, ui->Error_label_of_username);
    invalidCount += validate_password(LoginPassTxt, ui->Error_label_of_Password);
    invalidCount += validate_phone(LoginPhoneTxt, ui->Error_label_of_phone_2);

       if(invalidCount==3){
           QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");


            database.setDatabaseName("e:\\schema2.db");

            database.setUserName("Username");
            database.setPassword("Password");

            if (!database.open()) {
                // handle error
            }

            QSqlQuery query(database);

             QString sql = QString("SELECT * FROM Player WHERE Username='%1' AND Password='%2' AND Phone='%3'").arg(LoginUsernameTxt, LoginPassTxt, LoginPhoneTxt);
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
    if((input_text.length()-3) < 11 && input_text!=""){
        targetLable->setText("invalid phone!");
        return false;
    }
    if(input_text==""){

        targetLable->setText("this field not be empty");
        return false;
    }
    targetLable->setText("");
    return true;
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
    targetLable->setText("");
    return true;

}


void Login_or_SignUp_page::on_SignUp_of_Signup_clicked()
{
    QString SignUpUsernameTxt = ui->lineEdit_3->text();
    QString SignUpPasswordTxt = ui->lineEdit_4->text();
    QString SignUpPhoneTxt = ui->lineEdit_5->text();
    QString SignUpEmailTxt = ui->lineEdit_6->text();
    QString SignUpInventoryTxt = ui->lineEdit_7->text();
    QString SignUpCaptchatxt = ui->lineEdit_9->text();


       int invalidCount= 0;
       invalidCount += validate_username(SignUpUsernameTxt, ui->Error_label_of_username_Signup);
       invalidCount += validate_password(SignUpPasswordTxt, ui->Error_label_of_password_Signup);
       invalidCount += validate_phone(SignUpPhoneTxt, ui->Error_label_of_phone_signup);
       invalidCount += validate_email(SignUpEmailTxt, ui->Error_label_of_Email);
       invalidCount += validate2_email(SignUpEmailTxt, ui->Error_label_of_Email);
       invalidCount += validate_Inventory(SignUpInventoryTxt, ui->Error_label_of_inventory);
       invalidCount += validate_Captcha(SignUpCaptchatxt, ui->Error_label_of_Captcha);

       if(invalidCount == 7){
          int p=1;
          QSqlQuery dbInstance;
          QString query = "INSERT INTO Player (Username, Password, Phone, Email, Inventory, Player_number) VALUES (:Username, :Password, :Phone, :Email, :Inventory, :Player_number)";
          dbInstance.prepare(query);
          dbInstance.bindValue(":Username", SignUpUsernameTxt);
          dbInstance.bindValue(":Password", SignUpPasswordTxt);
          dbInstance.bindValue(":Phone", SignUpPhoneTxt);
          dbInstance.bindValue(":Email", SignUpEmailTxt);
          dbInstance.bindValue(":Inventory", SignUpInventoryTxt);
          dbInstance.bindValue(":Player_number", Player_number);


          if(!dbInstance.exec()){
              p=0;
              QRegularExpression re("UNIQUE constraint failed: (\\w+\\.\\w+)");
              QString errorMessage = dbInstance.lastError().text();
              QRegularExpressionMatch match = re.match(errorMessage);
              if (match.hasMatch()) {
                 QString playerLasterror = match.captured(1);
                 QMessageBox::warning(this," ","the eroor with "+playerLasterror+"","set another username!");
              }


            //  ui->lineEdit_14->setText(dbInstance.lastError().text());

          }
          if(p==1){
              QMessageBox::information(this,"The end", "wellcome noobe sag", "Gg");
                int a=Player_number++;

              QSqlQuery q;
              QString query = QString("UPDATE Player SET Player_number = %1 WHERE Username = %2").arg((QString::number(a)),SignUpUsernameTxt);
              q.exec(query);

          }
       }



       //    if(invalidCount == 4){
       //       int p=1;
       //       QSqlQuery dbInstance;
       //       QString query = "INSERT INTO user (username, password, phone) VALUES (:username, :password, :phone)";
       //       dbInstance.prepare(query);
       //       dbInstance.bindValue(":username", signUpUsernameTxt);
       //       dbInstance.bindValue(":password", signUpPassTxt);
       //       dbInstance.bindValue(":phone", signUpPhoneTxt);

       //       if(!dbInstance.exec()){
       //           p=0;
       //        //   ui->lineEdit_7->setText(dbInstance.lastError().text());
       //           QMessageBox::warning(this," ","This username has already exist","set another username!");
       //       }
       //       if(p==1){
       //           QMessageBox::information(this,"The end", "wellcome noobe sag", "Gg");
       //       }
       //    }

}


void Login_or_SignUp_page::on_lineEdit_3_textChanged(const QString &arg1)
{
    validate_username(arg1, ui->Error_label_of_username_Signup);
}


void Login_or_SignUp_page::on_lineEdit_4_textChanged(const QString &arg1)
{
    validate_password(arg1, ui->Error_label_of_password_Signup);
}

bool Login_or_SignUp_page::validate_Inventory(QString input_text, QLabel *targetLable)
{
    if(input_text==""){
        targetLable->setText("this field not be empty");
        return false;
    }
    if(input_text=="0"){
        targetLable->setText("Your inventory can not be 0");
        return false;
    }
    targetLable->setText("");
    return true;
}



void Login_or_SignUp_page::on_lineEdit_7_textChanged(const QString &arg1)
{
    validate_Inventory(arg1, ui->Error_label_of_inventory);
}

bool Login_or_SignUp_page::validate_Captcha(QString input_text, QLabel *targetLable)
{

    if(input_text!=cap && input_text!=""){
        targetLable->setText("invalid captcha");
        return false;
    }
    if(input_text==""){

        targetLable->setText("this field not be empty");
        return false;
    }
    if(input_text==cap){
        targetLable->setText("");
        return true;
    }
    return true;
}


void Login_or_SignUp_page::on_pushButton_2_clicked()
{
    if(ui->lineEdit_2->echoMode() == QLineEdit::Password){
        ui->pushButton_2->setStyleSheet("border-image: url(:/EchomoodPassword.image/C:/Users/i/Downloads/eye.image.png);");
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }else{
        ui->pushButton_2->setStyleSheet("border-image: url(:/EchomoodPassword.image/C:/Users/i/Downloads/eye.image2.png);");
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}


void Login_or_SignUp_page::on_pushButton_3_clicked()
{
    if(ui->lineEdit_4->echoMode() == QLineEdit::Password){
        ui->pushButton_3->setStyleSheet("border-image: url(:/EchomoodPassword.image/C:/Users/i/Downloads/eye.image.png);");
        ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
    }else{
        ui->pushButton_3->setStyleSheet("border-image: url(:/EchomoodPassword.image/C:/Users/i/Downloads/eye.image2.png);");
        ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    }
}


void Login_or_SignUp_page::on_pushButton_clicked()
{
    cap = "";
    time_t t;
    srand((unsigned)time(&t));
    QString captcha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for(int i=0;i<8;i++){
        cap.push_back(captcha[rand() % 62]);
    }
    ui->label_4->setText(cap);
}


void Login_or_SignUp_page::on_lineEdit_6_textChanged(const QString &arg1)
{
    validate_email(arg1, ui->Error_label_of_Email);
}

bool Login_or_SignUp_page::validate2_email(QString input_text, QLabel *targetLable)
{

    if (endsWith(input_text, "@gmail.com")  || endsWith(input_text, "@email.com") || endsWith(input_text, "@mail.um.ac")) {

        targetLable->setText("");
        qDebug() << "endesh okeye";
        return true;
    }else if(input_text!=""){


        QMessageBox::warning(this," ","Your email must end with one of the three characters : 1)@gmail.com 2)@email.com 3)@mail.um.ac","try again!");
        return false;
    }

    return true;
}

