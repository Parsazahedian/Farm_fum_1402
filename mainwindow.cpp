#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlDatabase"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "login_or_signup_page.h"
#include "QIntValidator"

extern MainWindow* mainWindowPtr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->lineEdit->setValidator(new QIntValidator);

    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\schema2.db");
    database.open();

    QSqlQuery query;
    query.exec("SELECT * FROM ResumeGame");
    if (query.next()) {
       int isGameStarted = query.value("isStarted").toInt();
        qDebug() << "Resume game" << isGameStarted;

        if(isGameStarted==0){

            ui->pushButton_3->show();
            ui->lineEdit->show();

        }else if(isGameStarted==1){

            qDebug() << "az ghabl thabtnam karde";
            ui->pushButton_2->show();
            ui->pushButton->show();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton_3->show();
    ui->lineEdit->show();
    QString a="0";
    QSqlQuery q;
    q.exec("UPDATE ResumeGame SET isStarted = '"+a+"' ");
    ui->pushButton_2->hide();
    ui->pushButton->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "Go into game page";
    mainWindowPtr->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text()==""){

        ui->label->setText("this field not be empty");

    }else if(ui->lineEdit->text()=="0"){

        ui->label->setText("this field not be 0");

    }else if(ui->lineEdit->text()!="" && ui->lineEdit->text()!="0"){

        ui->label->setText("");

        QString Number_of_player = ui->lineEdit->text();

        QSqlQuery q;
        q.exec("UPDATE UserInput SET Number_of_players = '"+Number_of_player+"' ");

        Login_or_SignUp_page *k = new Login_or_SignUp_page;
        k->setWindowTitle("Registration");
        k->show();
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 == ""){

        ui->label->setText("this field not be empty");

    }else if(arg1 == "0"){

        ui->label->setText("this field not be 0");

    }else{

        ui->label->setText("");
    }
}

