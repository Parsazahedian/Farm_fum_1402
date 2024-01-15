#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlDatabase"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "login_or_signup_page.h"
#include "QIntValidator"
#include "QSequentialAnimationGroup"
#include "QPropertyAnimation"
#include "gamepage.h"
#include "QMessageBox"

extern int score;
extern QTimer* Timer_for_timer_label;
extern MainWindow* mainWindowPtr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label_2, "geometry", this);
    animation1->setStartValue(QRect(170, -100, ui->label_2->geometry().width(), ui->label_2->geometry().height()));
    animation1->setEndValue(QRect(170, 10, ui->label_2->geometry().width(), ui->label_2->geometry().height()));
    animation1->setEasingCurve(QEasingCurve::Type::Linear);
    animation1->setDuration(2000);
    animation1->start();

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->pushButton_3, "geometry", this);
    animation2->setStartValue(QRect(250, -1200, ui->pushButton_3->geometry().width(), ui->pushButton_3->geometry().height()));
    animation2->setEndValue(QRect(250, 390, ui->pushButton_3->geometry().width(), ui->pushButton_3->geometry().height()));
    animation2->setEasingCurve(QEasingCurve::Type::InOutBounce);
    animation2->setDuration(5000);
    animation2->start();

    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->pushButton_2, "geometry", this);
    animation3->setStartValue(QRect(-1000, 220, ui->pushButton_2->geometry().width(), ui->pushButton_2->geometry().height()));
    animation3->setEndValue(QRect(130, 220, ui->pushButton_2->geometry().width(), ui->pushButton_2->geometry().height()));
    animation3->setEasingCurve(QEasingCurve::Type::InOutBounce);
    animation3->setDuration(5000);
    animation3->start();

    QPropertyAnimation *animation4 = new QPropertyAnimation(ui->pushButton, "geometry", this);
    animation4->setStartValue(QRect(1311, 220, ui->pushButton->geometry().width(), ui->pushButton->geometry().height()));
    animation4->setEndValue(QRect(329, 220, ui->pushButton->geometry().width(), ui->pushButton->geometry().height()));
    animation4->setEasingCurve(QEasingCurve::Type::InOutBounce);
    animation4->setDuration(5000);
    animation4->start();

    QPropertyAnimation *animation5 = new QPropertyAnimation(ui->lineEdit, "geometry", this);
    animation5->setStartValue(QRect(260, -1400, ui->lineEdit->geometry().width(), ui->lineEdit->geometry().height()));
    animation5->setEndValue(QRect(260, 330, ui->lineEdit->geometry().width(), ui->lineEdit->geometry().height()));
    animation5->setEasingCurve(QEasingCurve::Type::InOutBounce);
    animation5->setDuration(5000);
    animation5->start();

    QPixmap bkgnd("C:/Users/i/Downloads/back4.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    backmusic1 = new QMediaPlayer();
    backmusic1->setMedia(QUrl("C:/Users/i/Downloads/music_dave_miles_movement_003.mp3"));
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

        if(isGameStarted==0){

            ui->pushButton_3->show();
            ui->lineEdit->show();

        }else if(isGameStarted==1){

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
    QSqlQuery query_3;
    query_3.exec("DELETE FROM Game_Players");

    QString a="0";
    QSqlQuery q;
    q.exec("UPDATE ResumeGame SET isStarted = '"+a+"' ");
    ui->pushButton_2->hide();
    ui->pushButton->hide();
}

void MainWindow::on_pushButton_2_clicked()
{

    Gamepage *p = new Gamepage;
    p->setWindowTitle("Farm Managment");
    p->setWindowIcon(QIcon("C:/Users/i/Downloads/businessman_3331911.png"));
    p->show();
    backmusic1->stop();
    mainWindowPtr->close();

    QSqlQuery b;
    b.exec("SELECT Username FROM Game_Players WHERE Number = '"+QString::number(1)+"' ");
    QString s;
    if(b.first()){

        s = b.value(0).toString();
    }

    QMessageBox msgBox(p);
    msgBox.setWindowTitle("Wellcome");
    msgBox.setText(""+s+" Are You Ready to Start?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
       Timer_for_timer_label->start(1000);
    }

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
        k->setWindowIcon(QIcon("C:/Users/i/Downloads/businessman_3331911.png"));
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

