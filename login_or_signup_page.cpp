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

Login_or_SignUp_page::Login_or_SignUp_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_or_SignUp_page)
{
    ui->setupUi(this);

    QStringList list;
    list<< " Iran"<<" United States"<<" United Kingdom"<<" France"<<" Germany"<<" Italy"<<" Ukraine"<<" Russia";
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/iran.image.png"), list.at(0));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/Usa.image.png"), list.at(1));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/Uk.image.jpg"), list.at(2));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/france.image.png"), list.at(3));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/germany.image.png"), list.at(4));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/italy.image.jpg"), list.at(5));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/Ukraine.image.png"), list.at(6));
    ui->comboBox_2->addItem(QIcon("C:/Users/i/Downloads/russia.image.jpg"), list.at(7));

    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/iran.image.png"), list.at(0));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/Usa.image.png"), list.at(1));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/Uk.image.jpg"), list.at(2));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/france.image.png"), list.at(3));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/germany.image.png"), list.at(4));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/italy.image.jpg"), list.at(5));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/Ukraine.image.png"), list.at(6));
    ui->comboBox->addItem(QIcon("C:/Users/i/Downloads/russia.image.jpg"), list.at(7));


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


void Login_or_SignUp_page::on_Login_of_LoginGroupbox_clicked()
{
    QString signUpUsernameTxt = ui->lineEdit->text();
    QString signUpPassTxt = ui->lineEdit_2->text();


    int invalidCount= 0;
    invalidCount += validate_username(signUpUsernameTxt, ui->Error_label_of_username);
    invalidCount += validate_password(signUpPassTxt, ui->Error_label_of_Password);

       if(invalidCount==2){
           QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");


            database.setDatabaseName("e:\\schema2.db");
            database.setUserName("Username");
            database.setPassword("Password");

            if (!database.open()) {
                // handle error
            }

            QSqlQuery query(database);

             QString sql = QString("SELECT * FROM Player WHERE Username='%1' AND Password='%2'").arg(signUpUsernameTxt, signUpPassTxt);
             query.exec(sql);

             if (query.next()) {
                   // username and password exist in the database
                 QMessageBox::information(this,"The end", "wellcome noobe sag", "Gg");
             } else {
                   // username and password do not exist in the database
                 QMessageBox::warning(this," ","This username or password not exist","try again!");
             }

       }
}

