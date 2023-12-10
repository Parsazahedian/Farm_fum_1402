#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlDatabase"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "login_or_signup_page.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << qRound(234.34);

    ui->lineEdit->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\schema2.db");
    database.open();


    QSqlQuery query;
    query.exec("SELECT * FROM ResumeGame");

    if (query.next()) {
       int isGameStarted = query.value("isStarted").toInt();
        qDebug() << "cos sher" << isGameStarted;

        if(isGameStarted==0){

            ui->pushButton_3->show();
            ui->lineEdit->show();

        }else if(isGameStarted==1){


            qDebug() << "aaaaaaa";
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

}


void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "Go into game page";
}


void MainWindow::on_pushButton_3_clicked()
{
    Login_or_SignUp_page *k = new Login_or_SignUp_page;
    k->show();
}

