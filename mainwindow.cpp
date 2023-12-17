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

    QPixmap bkgnd("C:/Users/i/Downloads/back4.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    backmusic1 = new QMediaPlayer();
    backmusic1->setMedia(QUrl("C:/Users/i/Downloads/music_biiansu_nona_biiansu_longs_cinematic_drones_textures_020.mp3"));
    backmusic1->play();

    setMinimumSize(638,600);
    setMaximumSize(638,600);
    ui->lineEdit->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->lineEdit->setValidator(new QIntValidator);

    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\schema2.db");
    database.open();

    QSqlQuery query_4;
    query_4.exec("DELETE FROM Prevnt_repetition_in_Login");

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
    qDebug() << "vorod be edame bazi ghabli";
    mainWindowPtr->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text()==""){

        ui->label->setText("This field not be empty!");

    }else if(ui->lineEdit->text()=="0"){

        ui->label->setText("This field Can not be 0 !");

    }else if(ui->lineEdit->text()!="" && ui->lineEdit->text()!="0"){

        ui->label->setText("");

        QString Number_of_player = ui->lineEdit->text();

        QSqlQuery q;
        q.exec("UPDATE UserInput SET Number_of_players = '"+Number_of_player+"' ");

        Login_or_SignUp_page *k = new Login_or_SignUp_page;
        k->setWindowTitle("Registration");
        k->show();
        this->close();
        backmusic1->stop();

    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 == ""){

        ui->label->setText("This field not be empty!");

    }else if(arg1 == "0"){

        ui->label->setText("This field Can not be 0 !");

    }else{

        ui->label->setText("");
    }
}

