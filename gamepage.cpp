#include "gamepage.h"
#include "ui_gamepage.h"
#include "QDebug"
#include "chicken.h"
#include "sheep.h"
#include "cow.h"
#include "wheat.h"
#include "barley.h"
#include "farmer.h"
#include "QMessageBox"
#include "animals.h"
#include "seeds.h"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QThread"
#include "QSqlError"
#include "QSortFilterProxyModel"

QTimer* Timer_for_timer_label;
QTimer* Timer_for_timer_label_2;

int Number_of_Players;

int player_number=1;

int score=10, number_of_farmers=1, number_of_Free_farmers=1;

Chicken * ch1; Sheep * sheep1; Cow * cow1;  Wheat * wheat1;  Barley * barley1;
Chicken * ch2; Sheep * sheep2; Cow * cow2;  Wheat * wheat2;  Barley * barley2;
Chicken * ch3; Sheep * sheep3; Cow * cow3;  Wheat * wheat3;  Barley * barley3;
Chicken * ch4; Sheep * sheep4; Cow * cow4;  Wheat * wheat4;  Barley * barley4;
Chicken * ch5; Sheep * sheep5; Cow * cow5;  Wheat * wheat5;  Barley * barley5;
Chicken * ch6; Sheep * sheep6; Cow * cow6;  Wheat * wheat6;  Barley * barley6;
Chicken * ch7; Sheep * sheep7; Cow * cow7;  Wheat * wheat7;  Barley * barley7;
Chicken * ch8; Sheep * sheep8; Cow * cow8;  Wheat * wheat8;  Barley * barley8;
Chicken * ch9; Sheep * sheep9; Cow * cow9;  Wheat * wheat9;  Barley * barley9;
Chicken * ch10; Sheep * sheep10; Cow * cow10;  Wheat * wheat10;  Barley * barley10;
Chicken * ch11; Sheep * sheep11; Cow * cow11;  Wheat * wheat11;  Barley * barley11;
Chicken * ch12; Sheep * sheep12; Cow * cow12;  Wheat * wheat12;  Barley * barley12;
Chicken * ch13; Sheep * sheep13; Cow * cow13;  Wheat * wheat13;  Barley * barley13;
Chicken * ch14; Sheep * sheep14; Cow * cow14;  Wheat * wheat14;  Barley * barley14;
Chicken * ch15; Sheep * sheep15; Cow * cow15;  Wheat * wheat15;  Barley * barley15;
Chicken * ch16; Sheep * sheep16; Cow * cow16;  Wheat * wheat16;  Barley * barley16;

QPushButton* buttonAtPos2_ch1;QPushButton* buttonAtPos2_ch2;QPushButton* buttonAtPos2_ch3;QPushButton* buttonAtPos2_ch4;QPushButton* buttonAtPos2_ch5;QPushButton* buttonAtPos2_ch6;QPushButton* buttonAtPos2_ch7;QPushButton* buttonAtPos2_ch8;QPushButton* buttonAtPos2_ch9;QPushButton* buttonAtPos2_ch10;QPushButton* buttonAtPos2_ch11;QPushButton* buttonAtPos2_ch12;QPushButton* buttonAtPos2_ch13;QPushButton* buttonAtPos2_ch14;QPushButton* buttonAtPos2_ch15;QPushButton* buttonAtPos2_ch16;
QPushButton* buttonAtPos2_Sheep1;QPushButton* buttonAtPos2_Sheep2;QPushButton* buttonAtPos2_Sheep3;QPushButton* buttonAtPos2_Sheep4;QPushButton* buttonAtPos2_Sheep5;QPushButton* buttonAtPos2_Sheep6;QPushButton* buttonAtPos2_Sheep7;QPushButton* buttonAtPos2_Sheep8;QPushButton* buttonAtPos2_Sheep9;QPushButton* buttonAtPos2_Sheep10;QPushButton* buttonAtPos2_Sheep11;QPushButton* buttonAtPos2_Sheep12;QPushButton* buttonAtPos2_Sheep13;QPushButton* buttonAtPos2_Sheep14;QPushButton* buttonAtPos2_Sheep15;QPushButton* buttonAtPos2_Sheep16;
QPushButton* buttonAtPos2_cow1;QPushButton* buttonAtPos2_cow2;QPushButton* buttonAtPos2_cow3;QPushButton* buttonAtPos2_cow4;QPushButton* buttonAtPos2_cow5;QPushButton* buttonAtPos2_cow6;QPushButton* buttonAtPos2_cow7;QPushButton* buttonAtPos2_cow8;QPushButton* buttonAtPos2_cow9;QPushButton* buttonAtPos2_cow10;QPushButton* buttonAtPos2_cow11;QPushButton* buttonAtPos2_cow12;QPushButton* buttonAtPos2_cow13;QPushButton* buttonAtPos2_cow14;QPushButton* buttonAtPos2_cow15;QPushButton* buttonAtPos2_cow16;
QPushButton* buttonAtPos2_wheat1;QPushButton* buttonAtPos2_wheat2;QPushButton* buttonAtPos2_wheat3;QPushButton* buttonAtPos2_wheat4;QPushButton* buttonAtPos2_wheat5;QPushButton* buttonAtPos2_wheat6;QPushButton* buttonAtPos2_wheat7;QPushButton* buttonAtPos2_wheat8;QPushButton* buttonAtPos2_wheat9;QPushButton* buttonAtPos2_wheat10;QPushButton* buttonAtPos2_wheat11;QPushButton* buttonAtPos2_wheat12;QPushButton* buttonAtPos2_wheat13;QPushButton* buttonAtPos2_wheat14;QPushButton* buttonAtPos2_wheat15;QPushButton* buttonAtPos2_wheat16;
QPushButton* buttonAtPos2_barley1;QPushButton* buttonAtPos2_barley2;QPushButton* buttonAtPos2_barley3;QPushButton* buttonAtPos2_barley4;QPushButton* buttonAtPos2_barley5;QPushButton* buttonAtPos2_barley6;QPushButton* buttonAtPos2_barley7;QPushButton* buttonAtPos2_barley8;QPushButton* buttonAtPos2_barley9;QPushButton* buttonAtPos2_barley10;QPushButton* buttonAtPos2_barley11;QPushButton* buttonAtPos2_barley12;QPushButton* buttonAtPos2_barley13;QPushButton* buttonAtPos2_barley14;QPushButton* buttonAtPos2_barley15;QPushButton* buttonAtPos2_barley16;
QPropertyAnimation *animation1;QPropertyAnimation *animation2;QPropertyAnimation *animation3;QPropertyAnimation *animation4;QPropertyAnimation *animation5;QPropertyAnimation *animation6;QPropertyAnimation *animation7;QPropertyAnimation *animation8;QPropertyAnimation *animation9;QPropertyAnimation *animation10;QPropertyAnimation *animation11;QPropertyAnimation *animation12;QPropertyAnimation *animation13;QPropertyAnimation *animation14;QPropertyAnimation *animation15;QPropertyAnimation *animation16;

Gamepage::Gamepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamepage)
{
    ui->setupUi(this);

    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\schema2.db");
    database.open();

    QSqlQuery query;
    query.exec("SELECT * FROM UserInput");
    if (query.next()) {
    Number_of_Players = query.value("Number_of_players").toInt();
    }

    Move_the_product_of_Animals_and_seeds_pushButton();

    Hide_the_product_of_Animals_and_seeds_pushButton();

    Hide_Timer_labels();

    Hide_Start_pushbuttuns();

    Hide_Feilds_number_label();

    Hide_Cancel_pushbuttons();

    Hide_Farms();

   // ui->centralwidget->setStyleSheet("background-color: rgb(255, 255, 255);");

    Hide_label_of_timers();

    Default_farmer();

    setCursorForAllButtons(this);

    setMinimumSize(1908,987);
    setMaximumSize(1908,987);

    ui->groupBox->hide();

    ui->Results->hide();

    Hide_decrease_label();

    qDebug()<<"Number_Of_Players = "<<Number_of_Players;

    ui->label_Time->setText("3:00");

    ui->label_Score->setText( "Score : " + QString::number(score));

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Timer_for_timer_label = new QTimer(this);
    connect(Timer_for_timer_label, &QTimer::timeout, this, &Gamepage::Timer);

}

Gamepage::~Gamepage()
{
    delete ui;
    delete Timer_for_timer_label_2;
}

void Gamepage::setCursorForAllButtons(QWidget *widget) {
   QList<QPushButton*> buttons = widget->findChildren<QPushButton*>();
   for (auto *child : qAsConst(buttons)) {
       child->setCursor(QCursor(Qt::PointingHandCursor));
   }

   QList<QWidget*> childrenWidgets = widget->findChildren<QWidget*>();
   for (auto *child : qAsConst(childrenWidgets)) {
       setCursorForAllButtons(child);
   }
}

void Gamepage::on_Shop_pushButton_clicked()
{
    if(ui->groupBox->isVisible()){

        ui->groupBox->hide();

    }else if(ui->groupBox->isHidden()){

        ui->groupBox->show();
    }
}

void Gamepage::Timer()
{
   static int remainingTime = 180; // Start at 3 minutes

   if (remainingTime > 0) {
       --remainingTime;
       int minutes = remainingTime / 60;
       int seconds = remainingTime % 60;

       if (remainingTime == 10) {
                ui->label_Time->setStyleSheet("QLabel { color: red; }");
            }

       ui->label_Time->setText(QString("%1:%2").arg(minutes, 1, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
   } else {
       Timer_for_timer_label->stop();
       ui->label_Time->setStyleSheet("QLabel { color: Black; }");
       ui->label_Time->setStyleSheet("background-color: rgb(255, 255, 255);");
       QSqlQuery b;
       b.exec("SELECT Username FROM Game_Players WHERE Number = '"+QString::number(player_number)+"' ");
       player_number++;
       QString username;
       if(b.first()){

           username = b.value(0).toString();
       }

       Get_info();
       QMessageBox::information(this, "Point",""+username+" your score = "+QString::number(score)+" ");

       QSqlQuery query;
           query.prepare("UPDATE Game_Players SET Score = :score WHERE Username = :username");
           query.bindValue(":score", score);
           query.bindValue(":username", username);
           if(!query.exec()){
               qDebug() << query.lastError().text();
           }

       Set_window_to_the_default();

       Number_of_Players--;

       if(Number_of_Players==0){

           qDebug()<<"finished";
           QSqlQueryModel* model = new QSqlQueryModel(this);
           QSqlQuery* query = new QSqlQuery(database);;
           query->prepare("SELECT Username, Score FROM Game_Players ORDER BY Score DESC");
           query->exec();
           model->setQuery(*query);
           QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel(this);
           proxyModel->setSourceModel(model);
           proxyModel->sort(1, Qt::DescendingOrder);
           ui->tableView->setModel(proxyModel);
           ui->Results->show();
           QPropertyAnimation *animation1 = new QPropertyAnimation(ui->Results, "geometry", this);
           animation1->setStartValue(QRect(613, -800, ui->Results->geometry().width(), ui->Results->geometry().height()));
           animation1->setEndValue(QRect(613, 70, ui->Results->geometry().width(), ui->Results->geometry().height()));
           animation1->setEasingCurve(QEasingCurve::Type::InOutBounce);
           animation1->setDuration(5000);
           animation1->start();

           QSqlQuery query_3;
           query_3.exec("DELETE FROM Game_Players");

           QString z="0";
           QSqlQuery q;
           q.exec("UPDATE ResumeGame SET isStarted = '"+z+"' ");

           Set_window_to_the_default();
           ui->Results->show();

       }else{

           Set_window_to_the_default();
           For_Repeated();

       }

   }
}

void Gamepage::Timer_2()
{
    static int remainingTime = 180; // Start at 3 minutes

    if (remainingTime > 0) {
        --remainingTime;
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;

        if (remainingTime == 10) {
                 ui->label_Time->setStyleSheet("QLabel { color: red; }");
             }

        ui->label_Time->setText(QString("%1:%2").arg(minutes, 1, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    } else {
        Timer_for_timer_label_2->stop();
        ui->label_Time->setStyleSheet("QLabel { color: Black; }");
        ui->label_Time->setStyleSheet("background-color: rgb(255, 255, 255);");
        remainingTime = 180;
        QSqlQuery v;
        v.exec("SELECT Username FROM Game_Players WHERE Number = '"+QString::number(player_number)+"' ");
        player_number++;
        QString Username;
        if(v.first()){

            Username = v.value(0).toString();
        }
        Get_info();
        QMessageBox::information(this, "Point",""+Username+" your score = "+QString::number(score)+" ");

        QSqlQuery query;
            query.prepare("UPDATE Game_Players SET Score = :score WHERE Username = :username");
            query.bindValue(":score", score);
            query.bindValue(":username", Username);
            if(!query.exec()){
                qDebug() << query.lastError().text();
            }

        Set_window_to_the_default();
        if(Number_of_Players==0){

            qDebug()<<"finished";
            QSqlQueryModel* model = new QSqlQueryModel(this);
            QSqlQuery* query = new QSqlQuery(database);;
            query->prepare("SELECT Username, Score FROM Game_Players ORDER BY Score DESC");
            query->exec();
            model->setQuery(*query);
            QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel(this);
            proxyModel->setSourceModel(model);
            proxyModel->sort(1, Qt::DescendingOrder);
            ui->tableView->setModel(proxyModel);
            ui->Results->show();
            QPropertyAnimation *animation1 = new QPropertyAnimation(ui->Results, "geometry", this);
            animation1->setStartValue(QRect(613, -800, ui->Results->geometry().width(), ui->Results->geometry().height()));
            animation1->setEndValue(QRect(613, 80, ui->Results->geometry().width(), ui->Results->geometry().height()));
            animation1->setEasingCurve(QEasingCurve::Type::InOutBounce);
            animation1->setDuration(5000);
            animation1->start();

            QSqlQuery query_3;
            query_3.exec("DELETE FROM Game_Players");

            QString z="0";
            QSqlQuery q;
            q.exec("UPDATE ResumeGame SET isStarted = '"+z+"' ");

            Set_window_to_the_default();
            ui->Results->show();

        }else{

            Set_window_to_the_default();
            For_Repeated();

        }
    }
}

void Gamepage::For_Repeated()
{
    if(Number_of_Players > 0){

        QSqlQuery v;
        v.exec("SELECT Username FROM Game_Players WHERE Number = '"+QString::number(player_number)+"' ");
        QString Username;
        if(v.first()){

            Username = v.value(0).toString();
        }

        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Wellcome");
        msgBox.setText(""+Username+" Are You Ready to Start?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        int ret = msgBox.exec();

           if (ret == QMessageBox::Yes) {
               if (!Timer_for_timer_label_2) {
                   Timer_for_timer_label_2 = new QTimer(this);
                   connect(Timer_for_timer_label_2, &QTimer::timeout, this, &Gamepage::Timer_2);
               }
               Timer_for_timer_label_2->start(1000);
           }
           Number_of_Players--;
       }

}

void Gamepage::Delete_all_created_pushbuttos(QWidget* parent, const QString& name)
{
    QList<QPushButton*> buttons = parent->findChildren<QPushButton*>(name);
       foreach(QPushButton* button, buttons) {
           button->deleteLater();

       }
}

void Gamepage::on_Chicken_pushButton_clicked()
{

    Chicken * chicken = new Chicken(ui->verticalLayout_2);

    if(score >= chicken->Purchase_price){

        score = score - chicken->Purchase_price;

        ui->label_Score->setText( "Score : " + QString::number(score));

        Chicken * ch = new Chicken(ui->Animals_verticalLayout);

        ch->pushButton->setObjectName("Chicken");

        connect(ch->pushButton, &QPushButton::clicked, this, [this, ch](){ QMessageBox msgBox;
            msgBox.setText("Chicken""<ul>""<li>""Purchase price = 3""</li>" "<li>""Price of meat = 2""</li>" "<li>""Product Collection Point = 3""</li>" "<li>""Product production time = 20""</li>" "<li>""Product Collection Delay Time = every 5 second decrease 1 point from product""</li>""</ul>");
            msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

            msgBox.setWindowTitle("Transfer to ...");

            // Set the icon
            msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/Grass2.jpg"));

            msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/hen.png"));


            // Add custom buttons
            QHash<QAbstractButton*, int> buttonMap;
            for (int i = 1; i <= 18; ++i) {
              QPushButton* button = new QPushButton(QString("%1").arg(i));
              msgBox.addButton(button, i == 18 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
              buttonMap[button] = i;

              setCursorForAllButtons(this);
            //  button->setMinimumSize(56, 40);
               button->setMinimumSize(40, 40);

               if(i==1){

                   QPoint pos(150, 180);

                   if(check(pos)==true){

                       F1_Having_Animals_or_Seeds=0;
                       F1_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F1_Having_Animals_or_Seeds=1;
                       F1_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if((i==2 && ui->label_2->isHidden())){

                   button->setEnabled(false);

               }else if(i==2 && ui->label_2->isVisible()){

                   QPoint pos(540, 180);

                   if(check(pos)==true){

                       F2_Having_Animals_or_Seeds=0;
                       F2_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F2_Having_Animals_or_Seeds=1;
                       F2_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==3 && ui->label_3->isHidden()){

                   button->setEnabled(false);

               }else if(i==3 && ui->label_3->isVisible()){

                   QPoint pos(1260, 180);

                   if(check(pos)==true){

                       F3_Having_Animals_or_Seeds=0;
                       F3_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F3_Having_Animals_or_Seeds=1;
                       F3_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==4 && ui->label_4->isHidden()){

                   button->setEnabled(false);

               }else if(i==4 && ui->label_4->isVisible()){

                   QPoint pos(1650, 180);

                   if(check(pos)==true){

                       F4_Having_Animals_or_Seeds=0;
                       F4_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F4_Having_Animals_or_Seeds=1;
                       F4_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==5 && ui->label_5->isHidden()){

                   button->setEnabled(false);

               }else if(i==5 && ui->label_5->isVisible()){

                   QPoint pos(150, 410);

                   if(check(pos)==true){

                       F5_Having_Animals_or_Seeds=0;
                       F5_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F5_Having_Animals_or_Seeds=1;
                       F5_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==6 && ui->label_6->isHidden()){

                   button->setEnabled(false);

               }else if(i==6 && ui->label_6->isVisible()){

                   QPoint pos(540, 410);

                   if(check(pos)==true){

                       F6_Having_Animals_or_Seeds=0;
                       F6_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F6_Having_Animals_or_Seeds=1;
                       F6_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==7 && ui->label_7->isHidden()){

                   button->setEnabled(false);

               }else if(i==7 && ui->label_7->isVisible()){

                   QPoint pos(1260, 410);

                   if(check(pos)==true){

                       F7_Having_Animals_or_Seeds=0;
                       F7_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F7_Having_Animals_or_Seeds=1;
                       F7_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==8 && ui->label_8->isHidden()){

                   button->setEnabled(false);

               }else if(i==8 && ui->label_8->isVisible()){

                   QPoint pos(1650, 410);

                   if(check(pos)==true){

                       F8_Having_Animals_or_Seeds=0;
                       F8_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F8_Having_Animals_or_Seeds=1;
                       F8_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==9 && ui->label_9->isHidden()){

                   button->setEnabled(false);

               }else if(i==9 && ui->label_9->isVisible()){

                   QPoint pos(150, 640);

                   if(check(pos)==true){

                       F9_Having_Animals_or_Seeds=0;
                       F9_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F9_Having_Animals_or_Seeds=1;
                       F9_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==10 && ui->label_10->isHidden()){

                   button->setEnabled(false);

               }else if(i==10 && ui->label_10->isVisible()){

                   QPoint pos(540, 640);

                   if(check(pos)==true){

                       F10_Having_Animals_or_Seeds=0;
                       F10_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F10_Having_Animals_or_Seeds=1;
                       F10_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==11 && ui->label_11->isHidden()){

                   button->setEnabled(false);

               }else if(i==11 && ui->label_11->isVisible()){

                   QPoint pos(1260, 640);

                   if(check(pos)==true){

                       F11_Having_Animals_or_Seeds=0;
                       F11_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F11_Having_Animals_or_Seeds=1;
                       F11_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==12 && ui->label_12->isHidden()){

                   button->setEnabled(false);

               }else if(i==12 && ui->label_12->isVisible()){

                   QPoint pos(1650, 640);

                   if(check(pos)==true){

                       F12_Having_Animals_or_Seeds=0;
                       F12_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F12_Having_Animals_or_Seeds=1;
                       F12_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==13 && ui->label_13->isHidden()){

                   button->setEnabled(false);

               }else if(i==13 && ui->label_13->isVisible()){

                   QPoint pos(150, 870);

                   if(check(pos)==true){

                       F13_Having_Animals_or_Seeds=0;
                       F13_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F13_Having_Animals_or_Seeds=1;
                       F13_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==14 && ui->label_14->isHidden()){

                   button->setEnabled(false);

               }else if(i==14 && ui->label_14->isVisible()){

                   QPoint pos(540, 870);

                   if(check(pos)==true){

                       F14_Having_Animals_or_Seeds=0;
                       F14_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F14_Having_Animals_or_Seeds=1;
                       F14_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==15 && ui->label_15->isHidden()){

                   button->setEnabled(false);

               }else if(i==15 && ui->label_15->isVisible()){

                   QPoint pos(1260, 870);

                   if(check(pos)==true){

                       F15_Having_Animals_or_Seeds=0;
                       F15_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F15_Having_Animals_or_Seeds=1;
                       F15_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

               if(i==16 && ui->label_16->isHidden()){

                   button->setEnabled(false);

               }else if(i==16 && ui->label_16->isVisible()){

                   QPoint pos(1650, 870);

                   if(check(pos)==true){

                       F16_Having_Animals_or_Seeds=0;
                       F16_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F16_Having_Animals_or_Seeds=1;
                       F16_Which_Of_Animals_or_Seeds=1;
                       button->setEnabled(false);
                   }
               }

              if(i==17){

                  button->setText("Home");
                  button->setMinimumSize(60,40);
                  button->setStyleSheet("color:  rgb(255, 197, 62);font-weight: bold;");
              }

              if(i==18){

               button->setMinimumSize(50,40);
                  button->setText("Kill");
                  button->setStyleSheet("color: rgb(255, 0, 0);font-weight: bold;");
              }
            }

        // clazy:exclude:connect-3arg-lambda
            QObject *context = this;
            QObject::connect(&msgBox, &QMessageBox::finished, context,[&](){

               QAbstractButton* clickedButton = msgBox.clickedButton();

               if (clickedButton) {

                   int buttonNumber = buttonMap[clickedButton];

                   switch(buttonNumber) {

                   case 1:

                       if(F1_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(150, 180);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F1_Which_Of_Animals_or_Seeds=1;
                           F1_Having_Animals_or_Seeds=1;
                       }

                       Get_info();


                       break;
                   case 2:

                       if(F2_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(540, 180);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F2_Which_Of_Animals_or_Seeds=1;
                           F2_Having_Animals_or_Seeds=1;
                       }

                       Get_info();


                       break;
                   case 3:

                       if(F3_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1260, 180);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F3_Which_Of_Animals_or_Seeds=1;
                           F3_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 4:

                       if(F4_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1650, 180);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F4_Which_Of_Animals_or_Seeds=1;
                           F4_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 5:

                       if(F5_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(150, 410);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F5_Which_Of_Animals_or_Seeds=1;
                           F5_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 6:

                       if(F6_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(540, 410);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F6_Which_Of_Animals_or_Seeds=1;
                           F6_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 7:

                       if(F7_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1260, 410);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F7_Which_Of_Animals_or_Seeds=1;
                           F7_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 8:

                       if(F8_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1650, 410);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F8_Which_Of_Animals_or_Seeds=1;
                           F8_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 9:

                       if(F9_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(150, 640);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F9_Which_Of_Animals_or_Seeds=1;
                           F9_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 10:

                       if(F10_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(540, 640);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F10_Which_Of_Animals_or_Seeds=1;
                           F10_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 11:

                       if(F11_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1260, 640);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F11_Which_Of_Animals_or_Seeds=1;
                           F11_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 12:

                       if(F12_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1650, 640);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F12_Which_Of_Animals_or_Seeds=1;
                           F12_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 13:

                       if(F13_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(150, 870);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F13_Which_Of_Animals_or_Seeds=1;
                           F13_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 14:

                       if(F14_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(540, 870);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F14_Which_Of_Animals_or_Seeds=1;
                           F14_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 15:

                       if(F15_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1260, 870);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F15_Which_Of_Animals_or_Seeds=1;
                           F15_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 16:

                       if(F16_Having_Animals_or_Seeds==0){

                           ch->pushButton->move(1650, 870);
                           ch->pushButton->setParent(this);
                           ch->pushButton->show();
                           F16_Which_Of_Animals_or_Seeds=1;
                           F16_Having_Animals_or_Seeds=1;
                       }

                       Get_info();

                       break;
                   case 17:
                       //add to verticall layout
                       ch->pushButton->move(2000, 10);
                       ui->Animals_verticalLayout->addWidget(ch->pushButton);

                       Get_info();

                       break;
                   case 18:
                       // remove pushbutton
                       score = score + ch->Price_of_meat;
                       ui->label_Score->setText( "Score : " + QString::number(score));
                       ui->Animals_verticalLayout->removeWidget(ch->pushButton);
                       delete ch->pushButton;

                       Get_info();

                       break;

                   default:
                       Get_info();
                       break;
                   }
               }
            });

            msgBox.exec();

           });

    }else{

        clearLayout(ui->verticalLayout_2);

        QMessageBox::warning(this, "Sorry", "You do not have enough Gold to buy this item!");
    }
    delete chicken;

    clearLayout(ui->verticalLayout_2);
    Get_info();

    setCursorForAllButtons(this);
}

void Gamepage::on_Sheep_pushButton_clicked()
{
    Sheep * sh = new Sheep(ui->verticalLayout_2);

    if(score >= sh->Purchase_price){

        score = score - sh->Purchase_price;

        ui->label_Score->setText( "Score : " + QString::number(score));

        Sheep * sheep = new Sheep(ui->Animals_verticalLayout);

        sheep->pushButton->setObjectName("Sheep");

        connect(sheep->pushButton, &QPushButton::clicked, this, [this, sheep](){ QMessageBox msgBox;
            msgBox.setText("Sheep""<ul>""<li>""Purchase price = 5""</li>" "<li>""Price of meat = 4""</li>" "<li>""Product Collection Point = 3""</li>" "<li>""Product production time = 15""</li>" "<li>""Product Collection Delay Time = every 4 second decrease 1 point from product""</li>""</ul>");
            msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

            msgBox.setWindowTitle("Transfer to ...");

            // Set the icon
            msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/Grass2.jpg"));

            msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/sheep.png"));

            // Add custom buttons
            QHash<QAbstractButton*, int> buttonMap;
            for (int i = 1; i <= 18; ++i) {
              QPushButton* button = new QPushButton(QString("%1").arg(i));
              msgBox.addButton(button, i == 18 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
              buttonMap[button] = i;

            //  button->setMinimumSize(56, 40);
               button->setMinimumSize(40, 40);

               if(i==1){

                   QPoint pos(150, 180);

                   if(check(pos)==true){

                       F1_Having_Animals_or_Seeds=0;
                       F1_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F1_Having_Animals_or_Seeds=1;
                       F1_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if((i==2 && ui->label_2->isHidden())){

                   button->setEnabled(false);

               }else if(i==2 && ui->label_2->isVisible()){

                   QPoint pos(540, 180);

                   if(check(pos)==true){

                       F2_Having_Animals_or_Seeds=0;
                       F2_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){


                       F2_Having_Animals_or_Seeds=1;
                       F2_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==3 && ui->label_3->isHidden()){

                   button->setEnabled(false);

               }else if(i==3 && ui->label_3->isVisible()){

                   QPoint pos(1260, 180);

                   if(check(pos)==true){

                       F3_Having_Animals_or_Seeds=0;
                       F3_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F3_Having_Animals_or_Seeds=1;
                       F3_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==4 && ui->label_4->isHidden()){

                   button->setEnabled(false);

               }else if(i==4 && ui->label_4->isVisible()){

                   QPoint pos(1650, 180);

                   if(check(pos)==true){

                       F4_Having_Animals_or_Seeds=0;
                       F4_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F4_Having_Animals_or_Seeds=1;
                       F4_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==5 && ui->label_5->isHidden()){

                   button->setEnabled(false);

               }else if(i==5 && ui->label_5->isVisible()){

                   QPoint pos(150, 410);

                   if(check(pos)==true){

                       F5_Having_Animals_or_Seeds=0;
                       F5_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F5_Having_Animals_or_Seeds=1;
                       F5_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==6 && ui->label_6->isHidden()){

                   button->setEnabled(false);

               }else if(i==6 && ui->label_6->isVisible()){

                   QPoint pos(540, 410);

                   if(check(pos)==true){

                       F6_Having_Animals_or_Seeds=0;
                       F6_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F6_Having_Animals_or_Seeds=1;
                       F6_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==7 && ui->label_7->isHidden()){

                   button->setEnabled(false);

               }else if(i==7 && ui->label_7->isVisible()){

                   QPoint pos(1260, 410);

                   if(check(pos)==true){

                       F7_Having_Animals_or_Seeds=0;
                       F7_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F7_Having_Animals_or_Seeds=1;
                       F7_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==8 && ui->label_8->isHidden()){

                   button->setEnabled(false);

               }else if(i==8 && ui->label_8->isVisible()){

                   QPoint pos(1650, 410);

                   if(check(pos)==true){

                       F8_Having_Animals_or_Seeds=0;
                       F8_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F8_Having_Animals_or_Seeds=1;
                       F8_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==9 && ui->label_9->isHidden()){

                   button->setEnabled(false);

               }else if(i==9 && ui->label_9->isVisible()){

                   QPoint pos(150, 640);

                   if(check(pos)==true){

                       F9_Having_Animals_or_Seeds=0;
                       F9_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F9_Having_Animals_or_Seeds=1;
                       F9_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==10 && ui->label_10->isHidden()){

                   button->setEnabled(false);

               }else if(i==10 && ui->label_10->isVisible()){

                   QPoint pos(540, 640);

                   if(check(pos)==true){

                       F10_Having_Animals_or_Seeds=0;
                       F10_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F10_Having_Animals_or_Seeds=1;
                       F10_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==11 && ui->label_11->isHidden()){

                   button->setEnabled(false);

               }else if(i==11 && ui->label_11->isVisible()){

                   QPoint pos(1260, 640);

                   if(check(pos)==true){

                       F11_Having_Animals_or_Seeds=0;
                       F11_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F11_Having_Animals_or_Seeds=1;
                       F11_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==12 && ui->label_12->isHidden()){

                   button->setEnabled(false);

               }else if(i==12 && ui->label_12->isVisible()){

                   QPoint pos(1650, 640);

                   if(check(pos)==true){

                       F12_Having_Animals_or_Seeds=0;
                       F12_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F12_Having_Animals_or_Seeds=1;
                       F12_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==13 && ui->label_13->isHidden()){

                   button->setEnabled(false);

               }else if(i==13 && ui->label_13->isVisible()){

                   QPoint pos(150, 870);

                   if(check(pos)==true){

                       F13_Having_Animals_or_Seeds=0;
                       F13_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F13_Having_Animals_or_Seeds=1;
                       F13_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==14 && ui->label_14->isHidden()){

                   button->setEnabled(false);

               }else if(i==14 && ui->label_14->isVisible()){

                   QPoint pos(540, 870);

                   if(check(pos)==true){

                       F14_Having_Animals_or_Seeds=0;
                       F14_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F14_Having_Animals_or_Seeds=1;
                       F14_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==15 && ui->label_15->isHidden()){

                   button->setEnabled(false);

               }else if(i==15 && ui->label_15->isVisible()){

                   QPoint pos(1260, 870);

                   if(check(pos)==true){

                       F15_Having_Animals_or_Seeds=0;
                       F15_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F15_Having_Animals_or_Seeds=1;
                       F15_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

               if(i==16 && ui->label_16->isHidden()){

                   button->setEnabled(false);

               }else if(i==16 && ui->label_16->isVisible()){

                   QPoint pos(1650, 870);

                   if(check(pos)==true){

                       F16_Having_Animals_or_Seeds=0;
                       F16_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F16_Having_Animals_or_Seeds=1;
                       F16_Which_Of_Animals_or_Seeds=2;
                       button->setEnabled(false);
                   }
               }

              if(i==17){

                  button->setText("Home");
                  button->setMinimumSize(60,40);
                  button->setStyleSheet("color:  rgb(255, 197, 62);font-weight: bold;");
              }

              if(i==18){

               button->setMinimumSize(50,40);
                  button->setText("Kill");
                  button->setStyleSheet("color: rgb(255, 0, 0);font-weight: bold;");
              }
            }
        // clazy:exclude:connect-3arg-lambda
            QObject *context = this;
            QObject::connect(&msgBox, &QMessageBox::finished, context,[&](){
               QAbstractButton* clickedButton = msgBox.clickedButton();
               if (clickedButton) {
                   int buttonNumber = buttonMap[clickedButton];

                   switch(buttonNumber) {
                   case 1:

                       if(F1_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(150, 180);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F1_Having_Animals_or_Seeds=1;
                           F1_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 2:

                       if(F2_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(540, 180);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F2_Having_Animals_or_Seeds=1;
                           F2_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 3:

                       if(F3_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1260, 180);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F3_Having_Animals_or_Seeds=1;
                           F3_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 4:

                       if(F4_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1650, 180);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F4_Having_Animals_or_Seeds=1;
                           F4_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 5:

                       if(F5_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(150, 410);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F5_Having_Animals_or_Seeds=1;
                           F5_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 6:

                       if(F6_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(540, 410);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F6_Having_Animals_or_Seeds=1;
                           F6_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 7:

                       if(F7_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1260, 410);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F7_Having_Animals_or_Seeds=1;
                           F7_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 8:

                       if(F8_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1650, 410);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F8_Having_Animals_or_Seeds=1;
                           F8_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 9:

                       if(F9_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(150, 640);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F9_Having_Animals_or_Seeds=1;
                           F9_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 10:

                       if(F10_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(540, 640);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F10_Having_Animals_or_Seeds=1;
                           F10_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 11:

                       if(F11_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1260, 640);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F11_Having_Animals_or_Seeds=1;
                           F11_Which_Of_Animals_or_Seeds=2;
                       }

                       break;
                   case 12:

                       if(F12_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1650, 640);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F12_Having_Animals_or_Seeds=1;
                           F12_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 13:

                       if(F13_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(150, 870);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F13_Having_Animals_or_Seeds=1;
                           F13_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 14:

                       if(F14_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(540, 870);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F14_Having_Animals_or_Seeds=1;
                           F14_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 15:

                       if(F15_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1260, 870);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F15_Having_Animals_or_Seeds=1;
                           F15_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 16:

                       if(F16_Having_Animals_or_Seeds==0){

                           sheep->pushButton->move(1650, 870);
                           sheep->pushButton->setParent(this);
                           sheep->pushButton->show();
                           F16_Having_Animals_or_Seeds=1;
                           F16_Which_Of_Animals_or_Seeds=2;
                       }

                       Get_info();

                       break;
                   case 17:
                       //add to verticall layout
                       sheep->pushButton->move(2000, 10);
                       ui->Animals_verticalLayout->addWidget(sheep->pushButton);

                       Get_info();

                       break;
                   case 18:
                       // remove pushbutton
                       score = score + sheep->Price_of_meat;
                       ui->label_Score->setText( "Score : " + QString::number(score));
                       ui->Animals_verticalLayout->removeWidget(sheep->pushButton);
                       delete sheep->pushButton;

                       Get_info();
                       break;

                   default:
                       Get_info();
                       break;
                   }
               }

            });

            msgBox.exec();

           });
    }else{

        clearLayout(ui->verticalLayout_2);
        QMessageBox::warning(this, "Sorry", "You do not have enough Gold to buy this item!");
    }

    delete sh;
    clearLayout(ui->verticalLayout_2);
    Get_info();

    setCursorForAllButtons(this);
}

void Gamepage::on_Cow_pushButton_clicked()
{
    Cow * co = new Cow(ui->verticalLayout_2);

    if(score >= co->Purchase_price){

        score = score - co->Purchase_price;

        ui->label_Score->setText( "Score : " + QString::number(score));

        Cow * cow = new Cow(ui->Animals_verticalLayout);

        cow->pushButton->setObjectName("Cow");

        connect(cow->pushButton, &QPushButton::clicked, this, [this, cow](){ QMessageBox msgBox;
            msgBox.setText("Cow""<ul>""<li>""Purchase price = 7""</li>" "<li>""Price of meat = 6""</li>" "<li>""Product Collection Point = 5""</li>" "<li>""Product production time = 20""</li>" "<li>""Product Collection Delay Time = every 3 second decrease 1 point from product""</li>""</ul>");
            msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

            msgBox.setWindowTitle("Transfer to ...");

            // Set the icon
            msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/Grass2.jpg"));

            msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/cow.png"));

            // Add custom buttons
            QHash<QAbstractButton*, int> buttonMap;
            for (int i = 1; i <= 18; ++i) {
              QPushButton* button = new QPushButton(QString("%1").arg(i));
              msgBox.addButton(button, i == 18 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
              buttonMap[button] = i;

            //  button->setMinimumSize(56, 40);
               button->setMinimumSize(40, 40);

               if(i==1){

                   QPoint pos(150, 180);

                   if(check(pos)==true){

                       F1_Having_Animals_or_Seeds=0;
                       F1_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F1_Having_Animals_or_Seeds=1;
                       F1_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if((i==2 && ui->label_2->isHidden())){

                   button->setEnabled(false);

               }else if(i==2 && ui->label_2->isVisible()){

                   QPoint pos(540, 180);

                   if(check(pos)==true){

                       F2_Having_Animals_or_Seeds=0;
                       F2_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F2_Having_Animals_or_Seeds=1;
                       F2_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==3 && ui->label_3->isHidden()){

                   button->setEnabled(false);

               }else if(i==3 && ui->label_3->isVisible()){

                   QPoint pos(1260, 180);

                   if(check(pos)==true){

                       F3_Having_Animals_or_Seeds=0;
                       F3_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F3_Having_Animals_or_Seeds=1;
                       F3_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==4 && ui->label_4->isHidden()){

                   button->setEnabled(false);

               }else if(i==4 && ui->label_4->isVisible()){

                   QPoint pos(1650, 180);

                   if(check(pos)==true){

                       F4_Having_Animals_or_Seeds=0;
                       F4_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F4_Having_Animals_or_Seeds=1;
                       F4_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==5 && ui->label_5->isHidden()){

                   button->setEnabled(false);

               }else if(i==5 && ui->label_5->isVisible()){

                   QPoint pos(150, 410);

                   if(check(pos)==true){

                       F5_Having_Animals_or_Seeds=0;
                       F5_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F5_Having_Animals_or_Seeds=1;
                       F5_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==6 && ui->label_6->isHidden()){

                   button->setEnabled(false);

               }else if(i==6 && ui->label_6->isVisible()){

                   QPoint pos(540, 410);

                   if(check(pos)==true){

                       F6_Having_Animals_or_Seeds=0;
                       F6_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F6_Having_Animals_or_Seeds=1;
                       F6_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==7 && ui->label_7->isHidden()){

                   button->setEnabled(false);

               }else if(i==7 && ui->label_7->isVisible()){

                   QPoint pos(1260, 410);

                   if(check(pos)==true){

                       F7_Having_Animals_or_Seeds=0;
                       F7_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F7_Having_Animals_or_Seeds=1;
                       F7_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==8 && ui->label_8->isHidden()){

                   button->setEnabled(false);

               }else if(i==8 && ui->label_8->isVisible()){

                   QPoint pos(1650, 410);

                   if(check(pos)==true){

                       F8_Having_Animals_or_Seeds=0;
                       F8_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F8_Having_Animals_or_Seeds=1;
                       F8_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==9 && ui->label_9->isHidden()){

                   button->setEnabled(false);

               }else if(i==9 && ui->label_9->isVisible()){

                   QPoint pos(150, 640);

                   if(check(pos)==true){

                       F9_Having_Animals_or_Seeds=0;
                       F9_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F9_Having_Animals_or_Seeds=1;
                       F9_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==10 && ui->label_10->isHidden()){

                   button->setEnabled(false);

               }else if(i==10 && ui->label_10->isVisible()){

                   QPoint pos(540, 640);

                   if(check(pos)==true){

                       F10_Having_Animals_or_Seeds=0;
                       F10_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F10_Having_Animals_or_Seeds=1;
                       F10_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==11 && ui->label_11->isHidden()){

                   button->setEnabled(false);

               }else if(i==11 && ui->label_11->isVisible()){

                   QPoint pos(1260, 640);

                   if(check(pos)==true){

                       F11_Having_Animals_or_Seeds=0;
                       F11_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F11_Having_Animals_or_Seeds=1;
                       F11_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==12 && ui->label_12->isHidden()){

                   button->setEnabled(false);

               }else if(i==12 && ui->label_12->isVisible()){

                   QPoint pos(1650, 640);

                   if(check(pos)==true){

                       F12_Having_Animals_or_Seeds=0;
                       F12_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F12_Having_Animals_or_Seeds=1;
                       F12_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==13 && ui->label_13->isHidden()){

                   button->setEnabled(false);

               }else if(i==13 && ui->label_13->isVisible()){

                   QPoint pos(150, 870);

                   if(check(pos)==true){

                       F13_Having_Animals_or_Seeds=0;
                       F13_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F13_Having_Animals_or_Seeds=1;
                       F13_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==14 && ui->label_14->isHidden()){

                   button->setEnabled(false);

               }else if(i==14 && ui->label_14->isVisible()){

                   QPoint pos(540, 870);

                   if(check(pos)==true){

                       F14_Having_Animals_or_Seeds=0;
                       F14_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F14_Having_Animals_or_Seeds=1;
                       F14_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==15 && ui->label_15->isHidden()){

                   button->setEnabled(false);

               }else if(i==15 && ui->label_15->isVisible()){

                   QPoint pos(1260, 870);

                   if(check(pos)==true){

                       F15_Having_Animals_or_Seeds=0;
                       F15_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F15_Having_Animals_or_Seeds=1;
                       F15_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

               if(i==16 && ui->label_16->isHidden()){

                   button->setEnabled(false);

               }else if(i==16 && ui->label_16->isVisible()){

                   QPoint pos(1650, 870);

                   if(check(pos)==true){

                       F16_Having_Animals_or_Seeds=0;
                       F16_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F16_Having_Animals_or_Seeds=1;
                       F16_Which_Of_Animals_or_Seeds=3;
                       button->setEnabled(false);
                   }
               }

              if(i==17){

                  button->setText("Home");
                  button->setMinimumSize(60,40);
                  button->setStyleSheet("color:  rgb(255, 197, 62);font-weight: bold;");
              }

              if(i==18){

               button->setMinimumSize(50,40);
                  button->setText("Kill");
                  button->setStyleSheet("color: rgb(255, 0, 0);font-weight: bold;");
              }
            }
        // clazy:exclude:connect-3arg-lambda
            QObject *context = this;
            QObject::connect(&msgBox, &QMessageBox::finished, context,[&](){

               QAbstractButton* clickedButton = msgBox.clickedButton();
               if (clickedButton) {
                   int buttonNumber = buttonMap[clickedButton];

                   switch(buttonNumber) {
                   case 1:

                       if(F1_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(150, 180);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F1_Having_Animals_or_Seeds=1;
                           F1_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 2:

                       if(F2_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(540, 180);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F2_Having_Animals_or_Seeds=1;
                           F2_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 3:

                       if(F3_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1260, 180);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F3_Having_Animals_or_Seeds=1;
                           F3_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 4:

                       if(F4_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1650, 180);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F4_Having_Animals_or_Seeds=1;
                           F4_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 5:

                       if(F5_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(150, 410);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F5_Having_Animals_or_Seeds=1;
                           F5_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 6:

                       if(F6_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(540, 410);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F6_Having_Animals_or_Seeds=1;
                           F6_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 7:

                       if(F7_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1260, 410);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F7_Having_Animals_or_Seeds=1;
                           F7_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 8:

                       if(F8_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1650, 410);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F8_Having_Animals_or_Seeds=1;
                           F8_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 9:

                       if(F9_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(150, 640);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F9_Having_Animals_or_Seeds=1;
                           F9_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 10:

                       if(F10_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(540, 640);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F10_Having_Animals_or_Seeds=1;
                           F10_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 11:

                       if(F11_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1260, 640);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F11_Having_Animals_or_Seeds=1;
                           F11_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 12:

                       if(F12_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1650, 640);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F12_Having_Animals_or_Seeds=1;
                           F12_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 13:

                       if(F13_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(150, 870);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F13_Having_Animals_or_Seeds=1;
                           F13_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 14:

                       if(F14_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(540, 870);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F14_Having_Animals_or_Seeds=1;
                           F14_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 15:

                       if(F15_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1260, 870);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F15_Having_Animals_or_Seeds=1;
                           F15_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 16:

                       if(F16_Having_Animals_or_Seeds==0){

                           cow->pushButton->move(1650, 870);
                           cow->pushButton->setParent(this);
                           cow->pushButton->show();
                           F16_Having_Animals_or_Seeds=1;
                           F16_Which_Of_Animals_or_Seeds=3;
                       }

                       Get_info();

                       break;
                   case 17:
                       //add to verticall layout
                       cow->pushButton->move(2000, 10);
                       ui->Animals_verticalLayout->addWidget(cow->pushButton);

                       Get_info();

                       break;
                   case 18:
                       // remove pushbutton
                       score = score + cow->Price_of_meat;
                       ui->label_Score->setText( "Score : " + QString::number(score));
                       ui->Animals_verticalLayout->removeWidget(cow->pushButton);
                       delete cow->pushButton;

                       Get_info();
                       break;

                   default:
                       Get_info();
                       break;
                   }
               }

            });

            msgBox.exec();

           });

    }else{

        clearLayout(ui->verticalLayout_2);
        QMessageBox::warning(this, "Sorry", "You do not have enough Gold to buy this item!");

    }

    delete co;
    clearLayout(ui->verticalLayout_2);
    Get_info();

    setCursorForAllButtons(this);
}

void Gamepage::on_Wheat_pushButton_clicked()
{

    Wheat * wh = new Wheat(ui->verticalLayout_2);

    if(score >= wh->Purchase_price){

        score = score - wh->Purchase_price;

        ui->label_Score->setText( "Score : " + QString::number(score));

        Wheat * wheat = new Wheat(ui->Seeds_verticalLayout);

        wheat->pushButton->setObjectName("Wheat");

        connect(wheat->pushButton, &QPushButton::clicked, this, [this, wheat](){ QMessageBox msgBox;
            msgBox.setText("Wheat""<ul>""<li>""Purchase price = 2""</li>" "<li>""Product Collection Point = 3""</li>" "<li>""Product production time = 25""</li>" "<li>""Product Collection Delay Time = every 12 second decrease 1 point from product""</li>""</ul>");
            msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

            msgBox.setWindowTitle("Transfer to ...");

            // Set the icon
            msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/Grass2.jpg"));

            msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/wheat (1).png"));

            // Add custom buttons
            QHash<QAbstractButton*, int> buttonMap;
            for (int i = 1; i <= 17; ++i) {
              QPushButton* button = new QPushButton(QString("%1").arg(i));
              msgBox.addButton(button, i == 17 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
              buttonMap[button] = i;

            //  button->setMinimumSize(56, 40);
               button->setMinimumSize(40, 40);

               if(i==1){

                   QPoint pos(150, 180);

                   if(check(pos)==true){

                       F1_Having_Animals_or_Seeds=0;
                       F1_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F1_Having_Animals_or_Seeds=1;
                       F1_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if((i==2 && ui->label_2->isHidden())){

                   button->setEnabled(false);

               }else if(i==2 && ui->label_2->isVisible()){

                   QPoint pos(540, 180);

                   if(check(pos)==true){

                       F2_Having_Animals_or_Seeds=0;
                       F2_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F2_Having_Animals_or_Seeds=1;
                       F2_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==3 && ui->label_3->isHidden()){

                   button->setEnabled(false);

               }else if(i==3 && ui->label_3->isVisible()){

                   QPoint pos(1260, 180);

                   if(check(pos)==true){

                       F3_Having_Animals_or_Seeds=0;
                       F3_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F3_Having_Animals_or_Seeds=1;
                       F3_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==4 && ui->label_4->isHidden()){

                   button->setEnabled(false);

               }else if(i==4 && ui->label_4->isVisible()){

                   QPoint pos(1650, 180);

                   if(check(pos)==true){

                       F4_Having_Animals_or_Seeds=0;
                       F4_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F4_Having_Animals_or_Seeds=1;
                       F4_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==5 && ui->label_5->isHidden()){

                   button->setEnabled(false);

               }else if(i==5 && ui->label_5->isVisible()){

                   QPoint pos(150, 410);

                   if(check(pos)==true){

                       F5_Having_Animals_or_Seeds=0;
                       F5_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F5_Having_Animals_or_Seeds=1;
                       F5_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==6 && ui->label_6->isHidden()){

                   button->setEnabled(false);

               }else if(i==6 && ui->label_6->isVisible()){

                   QPoint pos(540, 410);

                   if(check(pos)==true){

                       F6_Having_Animals_or_Seeds=0;
                       F6_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F6_Having_Animals_or_Seeds=1;
                       F6_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==7 && ui->label_7->isHidden()){

                   button->setEnabled(false);

               }else if(i==7 && ui->label_7->isVisible()){

                   QPoint pos(1260, 410);

                   if(check(pos)==true){

                       F7_Having_Animals_or_Seeds=0;
                       F7_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F7_Having_Animals_or_Seeds=1;
                       F7_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==8 && ui->label_8->isHidden()){

                   button->setEnabled(false);

               }else if(i==8 && ui->label_8->isVisible()){

                   QPoint pos(1650, 410);

                   if(check(pos)==true){

                       F8_Having_Animals_or_Seeds=0;
                       F8_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F8_Having_Animals_or_Seeds=1;
                       F8_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==9 && ui->label_9->isHidden()){

                   button->setEnabled(false);

               }else if(i==9 && ui->label_9->isVisible()){

                   QPoint pos(150, 640);

                   if(check(pos)==true){

                       F9_Having_Animals_or_Seeds=0;
                       F9_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F9_Having_Animals_or_Seeds=1;
                       F9_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==10 && ui->label_10->isHidden()){

                   button->setEnabled(false);

               }else if(i==10 && ui->label_10->isVisible()){

                   QPoint pos(540, 640);

                   if(check(pos)==true){

                       F10_Having_Animals_or_Seeds=0;
                       F10_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F10_Having_Animals_or_Seeds=1;
                       F10_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==11 && ui->label_11->isHidden()){

                   button->setEnabled(false);

               }else if(i==11 && ui->label_11->isVisible()){

                   QPoint pos(1260, 640);

                   if(check(pos)==true){

                       F11_Having_Animals_or_Seeds=0;
                       F11_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F11_Having_Animals_or_Seeds=1;
                       F11_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==12 && ui->label_12->isHidden()){

                   button->setEnabled(false);

               }else if(i==12 && ui->label_12->isVisible()){

                   QPoint pos(1650, 640);

                   if(check(pos)==true){

                       F12_Having_Animals_or_Seeds=0;
                       F12_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F12_Having_Animals_or_Seeds=1;
                       F12_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==13 && ui->label_13->isHidden()){

                   button->setEnabled(false);

               }else if(i==13 && ui->label_13->isVisible()){

                   QPoint pos(150, 870);

                   if(check(pos)==true){

                       F13_Having_Animals_or_Seeds=0;
                       F13_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F13_Having_Animals_or_Seeds=1;
                       F13_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==14 && ui->label_14->isHidden()){

                   button->setEnabled(false);

               }else if(i==14 && ui->label_14->isVisible()){

                   QPoint pos(540, 870);

                   if(check(pos)==true){

                       F14_Having_Animals_or_Seeds=0;
                       F14_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F14_Having_Animals_or_Seeds=1;
                       F14_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==15 && ui->label_15->isHidden()){

                   button->setEnabled(false);

               }else if(i==15 && ui->label_15->isVisible()){

                   QPoint pos(1260, 870);

                   if(check(pos)==true){

                       F15_Having_Animals_or_Seeds=0;
                       F15_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F15_Having_Animals_or_Seeds=1;
                       F15_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

               if(i==16 && ui->label_16->isHidden()){

                   button->setEnabled(false);

               }else if(i==16 && ui->label_16->isVisible()){

                   QPoint pos(1650, 870);

                   if(check(pos)==true){

                       F16_Having_Animals_or_Seeds=0;
                       F16_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F16_Having_Animals_or_Seeds=1;
                       F16_Which_Of_Animals_or_Seeds=4;
                       button->setEnabled(false);
                   }
               }

              if(i==17){

                  button->setText("Home");
                  button->setMinimumSize(60,40);
                  button->setStyleSheet("color:  rgb(255, 197, 62);font-weight: bold;");
              }

            }
        // clazy:exclude:connect-3arg-lambda
            QObject *context = this;
            QObject::connect(&msgBox, &QMessageBox::finished, context,[&](){
               QAbstractButton* clickedButton = msgBox.clickedButton();
               if (clickedButton) {
                   int buttonNumber = buttonMap[clickedButton];

                   switch(buttonNumber) {
                   case 1:

                       if(F1_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(150, 180);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F1_Having_Animals_or_Seeds=1;
                           F1_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 2:

                       if(F2_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(540, 180);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F2_Having_Animals_or_Seeds=1;
                           F2_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 3:

                       if(F3_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1260, 180);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F3_Having_Animals_or_Seeds=1;
                           F3_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 4:

                       if(F4_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1650, 180);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F4_Having_Animals_or_Seeds=1;
                           F4_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 5:

                       if(F5_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(150, 410);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F5_Having_Animals_or_Seeds=1;
                           F5_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 6:

                       if(F6_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(540, 410);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F6_Having_Animals_or_Seeds=1;
                           F6_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 7:

                       if(F7_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1260, 410);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F7_Having_Animals_or_Seeds=1;
                           F7_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 8:

                       if(F8_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1650, 410);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F8_Having_Animals_or_Seeds=1;
                           F8_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 9:

                       if(F9_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(150, 640);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F9_Having_Animals_or_Seeds=1;
                           F9_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 10:

                       if(F10_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(540, 640);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F10_Having_Animals_or_Seeds=1;
                           F10_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 11:

                       if(F11_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1260, 640);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F11_Having_Animals_or_Seeds=1;
                           F11_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 12:

                       if(F12_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1650, 640);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F12_Having_Animals_or_Seeds=1;
                           F12_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 13:

                       if(F13_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(150, 870);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F13_Having_Animals_or_Seeds=1;
                           F13_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 14:

                       if(F14_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(540, 870);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F14_Having_Animals_or_Seeds=1;
                           F14_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 15:

                       if(F15_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1260, 870);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F15_Having_Animals_or_Seeds=1;
                           F15_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 16:

                       if(F16_Having_Animals_or_Seeds==0){

                           wheat->pushButton->move(1650, 870);
                           wheat->pushButton->setParent(this);
                           wheat->pushButton->show();
                           F16_Having_Animals_or_Seeds=1;
                           F6_Which_Of_Animals_or_Seeds=4;
                       }

                       Get_info();

                       break;
                   case 17:
                       //add to verticall layout
                       wheat->pushButton->move(2000, 10);
                       ui->Seeds_verticalLayout->addWidget(wheat->pushButton);

                       Get_info();

                       break;

                   default:

                       Get_info();
                       break;
                   }
               }

            });

            msgBox.exec();

           });

    }else{

        clearLayout(ui->verticalLayout_2);
        QMessageBox::warning(this, "Sorry", "You do not have enough Gold to buy this item!");

    }

    delete wh;
    clearLayout(ui->verticalLayout_2);
    Get_info();

    setCursorForAllButtons(this);
}

void Gamepage::on_Barley_pushButton_clicked()
{
    Barley * br = new Barley(ui->verticalLayout_2);

    if(score >= br->Purchase_price){

        score = score - br->Purchase_price;

        ui->label_Score->setText( "Score : " + QString::number(score));

        Barley * barley = new Barley(ui->Seeds_verticalLayout);

        barley->pushButton->setObjectName("Barley");

        connect(barley->pushButton, &QPushButton::clicked, this, [this, barley](){ QMessageBox msgBox;
            msgBox.setText("Barley""<ul>""<li>""Purchase price = 2""</li>" "<li>""Product Collection Point = 2""</li>" "<li>""Product production time = 20""</li>" "<li>""Product Collection Delay Time = every 10 second decrease 1 point from product""</li>""</ul>");
            msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

            msgBox.setWindowTitle("Transfer to ...");

            // Set the icon
            msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/Grass2.jpg"));

            msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/barley.png"));

            // Add custom buttons
            QHash<QAbstractButton*, int> buttonMap;
            for (int i = 1; i <= 17; ++i) {
              QPushButton* button = new QPushButton(QString("%1").arg(i));
              msgBox.addButton(button, i == 17 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
              buttonMap[button] = i;

            //  button->setMinimumSize(56, 40);
               button->setMinimumSize(40, 40);

               if(i==1){

                   QPoint pos(150, 180);

                   if(check(pos)==true){

                       F1_Having_Animals_or_Seeds=0;
                       F1_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F1_Having_Animals_or_Seeds=1;
                       F1_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if((i==2 && ui->label_2->isHidden())){

                   button->setEnabled(false);

               }else if(i==2 && ui->label_2->isVisible()){

                   QPoint pos(540, 180);

                   if(check(pos)==true){


                       F2_Having_Animals_or_Seeds=0;
                       F2_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){


                       F2_Having_Animals_or_Seeds=1;
                       F2_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==3 && ui->label_3->isHidden()){

                   button->setEnabled(false);

               }else if(i==3 && ui->label_3->isVisible()){

                   QPoint pos(1260, 180);

                   if(check(pos)==true){

                       F3_Having_Animals_or_Seeds=0;
                       F3_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F3_Having_Animals_or_Seeds=1;
                       F3_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==4 && ui->label_4->isHidden()){

                   button->setEnabled(false);

               }else if(i==4 && ui->label_4->isVisible()){

                   QPoint pos(1650, 180);

                   if(check(pos)==true){

                       F4_Having_Animals_or_Seeds=0;
                       F4_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F4_Having_Animals_or_Seeds=1;
                       F4_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==5 && ui->label_5->isHidden()){

                   button->setEnabled(false);

               }else if(i==5 && ui->label_5->isVisible()){

                   QPoint pos(150, 410);

                   if(check(pos)==true){

                       F5_Having_Animals_or_Seeds=0;
                       F5_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F5_Having_Animals_or_Seeds=1;
                       F5_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==6 && ui->label_6->isHidden()){

                   button->setEnabled(false);

               }else if(i==6 && ui->label_6->isVisible()){

                   QPoint pos(540, 410);

                   if(check(pos)==true){

                       F6_Having_Animals_or_Seeds=0;
                       F6_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F6_Having_Animals_or_Seeds=1;
                       F6_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==7 && ui->label_7->isHidden()){

                   button->setEnabled(false);

               }else if(i==7 && ui->label_7->isVisible()){

                   QPoint pos(1260, 410);

                   if(check(pos)==true){

                       F7_Having_Animals_or_Seeds=0;
                       F7_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F7_Having_Animals_or_Seeds=1;
                       F7_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==8 && ui->label_8->isHidden()){

                   button->setEnabled(false);

               }else if(i==8 && ui->label_8->isVisible()){

                   QPoint pos(1650, 410);

                   if(check(pos)==true){

                       F8_Having_Animals_or_Seeds=0;
                       F8_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F8_Having_Animals_or_Seeds=1;
                       F8_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==9 && ui->label_9->isHidden()){

                   button->setEnabled(false);

               }else if(i==9 && ui->label_9->isVisible()){

                   QPoint pos(150, 640);

                   if(check(pos)==true){

                       F9_Having_Animals_or_Seeds=0;
                       F9_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F9_Having_Animals_or_Seeds=1;
                       F9_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==10 && ui->label_10->isHidden()){

                   button->setEnabled(false);

               }else if(i==10 && ui->label_10->isVisible()){

                   QPoint pos(540, 640);

                   if(check(pos)==true){

                       F10_Having_Animals_or_Seeds=0;
                       F10_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F10_Having_Animals_or_Seeds=1;
                       F10_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==11 && ui->label_11->isHidden()){

                   button->setEnabled(false);

               }else if(i==11 && ui->label_11->isVisible()){

                   QPoint pos(1260, 640);

                   if(check(pos)==true){

                       F11_Having_Animals_or_Seeds=0;
                       F11_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F11_Having_Animals_or_Seeds=1;
                       F11_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==12 && ui->label_12->isHidden()){

                   button->setEnabled(false);

               }else if(i==12 && ui->label_12->isVisible()){

                   QPoint pos(1650, 640);

                   if(check(pos)==true){

                       F12_Having_Animals_or_Seeds=0;
                       F12_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F12_Having_Animals_or_Seeds=1;
                       F12_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==13 && ui->label_13->isHidden()){

                   button->setEnabled(false);

               }else if(i==13 && ui->label_13->isVisible()){

                   QPoint pos(150, 870);

                   if(check(pos)==true){

                       F13_Having_Animals_or_Seeds=0;
                       F13_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F13_Having_Animals_or_Seeds=1;
                       F13_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==14 && ui->label_14->isHidden()){

                   button->setEnabled(false);

               }else if(i==14 && ui->label_14->isVisible()){

                   QPoint pos(540, 870);

                   if(check(pos)==true){

                       F14_Having_Animals_or_Seeds=0;
                       F14_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F14_Having_Animals_or_Seeds=1;
                       F14_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==15 && ui->label_15->isHidden()){

                   button->setEnabled(false);

               }else if(i==15 && ui->label_15->isVisible()){

                   QPoint pos(1260, 870);

                   if(check(pos)==true){

                       F15_Having_Animals_or_Seeds=0;
                       F15_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F15_Having_Animals_or_Seeds=1;
                       F15_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

               if(i==16 && ui->label_16->isHidden()){

                   button->setEnabled(false);

               }else if(i==16 && ui->label_16->isVisible()){

                   QPoint pos(1650, 870);

                   if(check(pos)==true){

                       F16_Having_Animals_or_Seeds=0;
                       F16_Which_Of_Animals_or_Seeds=0;
                       button->setEnabled(true);
                   }
                   if(check(pos)==false){

                       F16_Having_Animals_or_Seeds=1;
                       F16_Which_Of_Animals_or_Seeds=5;
                       button->setEnabled(false);
                   }
               }

              if(i==17){

                  button->setText("Home");
                  button->setMinimumSize(60,40);
                  button->setStyleSheet("color:  rgb(255, 197, 62);font-weight: bold;");
              }

            }
        // clazy:exclude:connect-3arg-lambda
            QObject *context = this;
            QObject::connect(&msgBox, &QMessageBox::finished, context,[&](){
               QAbstractButton* clickedButton = msgBox.clickedButton();
               if (clickedButton) {
                   int buttonNumber = buttonMap[clickedButton];

                   switch(buttonNumber) {
                   case 1:

                       if(F1_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(150, 180);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F1_Having_Animals_or_Seeds=1;
                           F1_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 2:

                       if(F2_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(540, 180);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F2_Having_Animals_or_Seeds=1;
                           F2_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 3:

                       if(F3_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1260, 180);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F3_Having_Animals_or_Seeds=1;
                           F3_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 4:

                       if(F4_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1650, 180);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F4_Having_Animals_or_Seeds=1;
                           F4_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 5:

                       if(F5_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(150, 410);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F5_Having_Animals_or_Seeds=1;
                           F5_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 6:

                       if(F6_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(540, 410);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F6_Having_Animals_or_Seeds=1;
                           F6_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 7:

                       if(F7_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1260, 410);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F7_Having_Animals_or_Seeds=1;
                           F7_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 8:

                       if(F8_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1650, 410);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F8_Having_Animals_or_Seeds=1;
                           F8_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 9:

                       if(F9_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(150, 640);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F9_Having_Animals_or_Seeds=1;
                           F9_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 10:

                       if(F10_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(540, 640);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F10_Having_Animals_or_Seeds=1;
                           F10_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 11:

                       if(F11_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1260, 640);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F11_Having_Animals_or_Seeds=1;
                           F11_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 12:

                       if(F12_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1650, 640);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F12_Having_Animals_or_Seeds=1;
                           F12_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 13:

                       if(F13_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(150, 870);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F13_Having_Animals_or_Seeds=1;
                           F13_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 14:

                       if(F14_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(540, 870);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F14_Having_Animals_or_Seeds=1;
                           F14_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 15:

                       if(F15_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1260, 870);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F15_Having_Animals_or_Seeds=1;
                           F15_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 16:

                       if(F16_Having_Animals_or_Seeds==0){

                           barley->pushButton->move(1650, 870);
                           barley->pushButton->setParent(this);
                           barley->pushButton->show();
                           F16_Having_Animals_or_Seeds=1;
                           F16_Which_Of_Animals_or_Seeds=5;
                       }

                       Get_info();

                       break;
                   case 17:
                       //add to verticall layout
                       barley->pushButton->move(2000, 10);
                       ui->Seeds_verticalLayout->addWidget(barley->pushButton);

                       Get_info();

                       break;

                   default:

                       Get_info();
                       break;
                   }
               }

            });

            msgBox.exec();

           });

    }else{

        clearLayout(ui->verticalLayout_2);
        QMessageBox::warning(this, "Sorry", "You do not have enough Gold to buy this item!");
    }


    delete br;
    clearLayout(ui->verticalLayout_2);
    Get_info();

    setCursorForAllButtons(this);
}

void Gamepage::on_Farmer_pushButton_clicked()
{

    Farmer * fr = new Farmer(ui->verticalLayout_2);

    if(score >= fr->Purchase_price){

        score = score - fr->Purchase_price;

        ui->label_Score->setText( "Score : " + QString::number(score));

        Farmer * farmer = new Farmer(ui->Farmer_verticalLayout);

        farmer->pushButton->setObjectName("Farmer");

        number_of_farmers++;

        number_of_Free_farmers++;

        ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

        connect(farmer->pushButton, &QPushButton::clicked, this, [this, farmer](){ QMessageBox msgBox;
            msgBox.setText("Farmer""<ul>""<li>""Purchase price = 5""</li>" "<li>""Farmer Status = Free""</li>" "</ul>");
            msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

            msgBox.setWindowTitle("Transfer to ...");

            // Set the icon
            msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/Grass2.jpg"));

            msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/farmer.png"));



            // Add custom buttons
            QHash<QAbstractButton*, int> buttonMap;
            for (int i = 1; i <= 17; ++i) {
              QPushButton* button = new QPushButton(QString("%1").arg(i));
              msgBox.addButton(button, i == 17 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
              buttonMap[button] = i;

            //  button->setMinimumSize(56, 40);
               button->setMinimumSize(40, 40);

               if(i==1){

                   QPoint pos(210, 160);

                   if(check(pos)==true){

                       F1_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel->isVisible())){

                       F1_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==2 && ui->label_2->isHidden()){

                   button->setEnabled(false);

               }else if(i==2 && ui->label_2->isVisible()){

                   QPoint pos(600, 160);

                   if(check(pos)==true){

                       F2_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_2->isVisible())) {

                       F2_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==3 && ui->label_3->isHidden()){

                   button->setEnabled(false);

               }else if(i==3 && ui->label_3->isVisible()){

                   QPoint pos(1320, 160);

                   if(check(pos)==true){

                       F3_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_3->isVisible())){

                       F3_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==4 && ui->label_4->isHidden()){

                   button->setEnabled(false);

               }else if(i==4 && ui->label_4->isVisible()){

                   QPoint pos(1710, 160);

                   if(check(pos)==true){

                       F4_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_4->isVisible())){

                       F4_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==5 && ui->label_5->isHidden()){

                   button->setEnabled(false);

               }else if(i==5 && ui->label_5->isVisible()){

                   QPoint pos(210, 390);

                   if(check(pos)==true){

                       F5_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_5->isVisible())){

                       F5_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==6 && ui->label_6->isHidden()){

                   button->setEnabled(false);

               }else if(i==6 && ui->label_6->isVisible()){

                   QPoint pos(600, 390);

                   if(check(pos)==true){

                       F6_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_6->isVisible())){

                       F6_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==7 && ui->label_7->isHidden()){

                   button->setEnabled(false);

               }else if(i==7 && ui->label_7->isVisible()){

                   QPoint pos(1320, 390);

                   if(check(pos)==true){

                       F7_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_7->isVisible())){

                       F7_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==8 && ui->label_8->isHidden()){

                   button->setEnabled(false);

               }else if(i==8 && ui->label_8->isVisible()){

                   QPoint pos(1710, 390);

                   if(check(pos)==true){

                       F8_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_8->isVisible())){

                       F8_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==9 && ui->label_9->isHidden()){

                   button->setEnabled(false);

               }else if(i==9 && ui->label_9->isVisible()){

                   QPoint pos(210, 620);

                   if(check(pos)==true){

                       F9_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_9->isVisible())){

                       F9_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==10 && ui->label_10->isHidden()){

                   button->setEnabled(false);

               }else if(i==10 && ui->label_10->isVisible()){

                   QPoint pos(600, 620);

                   if(check(pos)==true){

                       F10_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_10->isVisible())){

                       F10_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==11 && ui->label_11->isHidden()){

                   button->setEnabled(false);

               }else if(i==11 && ui->label_11->isVisible()){

                   QPoint pos(1320, 620);

                   if(check(pos)==true){

                       F11_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_11->isVisible())){

                       F11_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==12 && ui->label_12->isHidden()){

                   button->setEnabled(false);

               }else if(i==12 && ui->label_12->isVisible()){

                   QPoint pos(1710, 620);

                   if(check(pos)==true){

                       F12_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_12->isVisible())){

                       F12_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==13 && ui->label_13->isHidden()){

                   button->setEnabled(false);

               }else if(i==13 && ui->label_13->isVisible()){

                   QPoint pos(210, 850);

                   if(check(pos)==true){

                       F13_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_13->isVisible())){

                       F13_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==14 && ui->label_14->isHidden()){

                   button->setEnabled(false);

               }else if(i==14 && ui->label_14->isVisible()){

                   QPoint pos(600, 850);

                   if(check(pos)==true){

                       F14_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_14->isVisible())){

                       F14_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==15 && ui->label_15->isHidden()){

                   button->setEnabled(false);

               }else if(i==15 && ui->label_15->isVisible()){

                   QPoint pos(1320, 850);

                   if(check(pos)==true){

                       F15_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_15->isVisible())){

                       F15_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

               if(i==16 && ui->label_16->isHidden()){

                   button->setEnabled(false);

               }else if(i==16 && ui->label_16->isVisible()){

                   QPoint pos(1710, 850);

                   if(check(pos)==true){

                       F16_Having_Farmer=0;
                       button->setEnabled(true);
                   }
                   if((check(pos)==false) || (check(pos)==true && ui->Cancel_16->isVisible())){

                       F16_Having_Farmer=1;
                       button->setEnabled(false);
                   }
               }

              if(i==17){

                  button->setText("Home");
                  button->setMinimumSize(60,40);
                  button->setStyleSheet("color:  rgb(255, 197, 62);font-weight: bold;");

              }

            }
        // clazy:exclude:connect-3arg-lambda
            QObject *context = this;
            QObject::connect(&msgBox, &QMessageBox::finished, context,[&](){
               QAbstractButton* clickedButton = msgBox.clickedButton();
               if (clickedButton) {
                   int buttonNumber = buttonMap[clickedButton];

                   switch(buttonNumber) {

                   case 1:

                       if(F1_Having_Farmer==0){

                           farmer->pushButton->move(210, 160);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F1_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 2:

                       if(F2_Having_Farmer==0){

                           farmer->pushButton->move(600, 160);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F2_Having_Farmer=1;
                       }

                       Get_info();


                       break;
                   case 3:
                       // Perform action for Button 2

                       if(F3_Having_Farmer==0){

                           farmer->pushButton->move(1320, 160);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F3_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 4:
                       // Perform action for Button 2

                       if(F4_Having_Farmer==0){

                           farmer->pushButton->move(1710, 160);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F4_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 5:
                       // Perform action for Button 2

                       if(F5_Having_Farmer==0){

                           farmer->pushButton->move(210, 390);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F5_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 6:
                       // Perform action for Button 2

                       if(F6_Having_Farmer==0){

                           farmer->pushButton->move(600, 390);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F6_Having_Farmer=1;
                       }

                       Get_info();


                       break;
                   case 7:
                       // Perform action for Button 2

                       if(F7_Having_Farmer==0){

                           farmer->pushButton->move(1320, 390);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F7_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 8:
                       // Perform action for Button 2

                       if(F8_Having_Farmer==0){

                           farmer->pushButton->move(1710, 390);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F8_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 9:
                       // Perform action for Button 2

                       if(F9_Having_Farmer==0){

                           farmer->pushButton->move(210, 620);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F9_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 10:
                       // Perform action for Button 2

                       if(F10_Having_Farmer==0){

                           farmer->pushButton->move(600, 620);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F10_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 11:
                       // Perform action for Button 2

                       if(F11_Having_Farmer==0){

                           farmer->pushButton->move(1320, 620);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F11_Having_Farmer=1;
                       }
                       Get_info();

                       break;
                   case 12:
                       // Perform action for Button 2

                       if(F12_Having_Farmer==0){

                           farmer->pushButton->move(1710, 620);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F12_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 13:
                       // Perform action for Button 2

                       if(F13_Having_Farmer==0){

                           farmer->pushButton->move(210, 850);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F13_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 14:
                       // Perform action for Button 2

                       if(F14_Having_Farmer==0){

                           farmer->pushButton->move(600, 850);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F14_Having_Farmer=1;
                       }

                       Get_info();

                       break;
                   case 15:
                       // Perform action for Button 2

                       if(F15_Having_Farmer==0){

                           farmer->pushButton->move(1320, 850);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F15_Having_Farmer=1;
                       }

                       Get_info();


                       break;
                   case 16:
                       // Perform action for Button 2

                       if(F16_Having_Farmer==0){

                           farmer->pushButton->move(1710, 850);
                           farmer->pushButton->setParent(this);
                           farmer->pushButton->show();
                           F16_Having_Farmer=1;
                       }

                       Get_info();



                       break;
                   case 17:
                       //add to verticall layout
                       farmer->pushButton->move(2000, 10);

                       ui->Farmer_verticalLayout->addWidget(farmer->pushButton);

                       Get_info();

                       break;

                   default:
                       Get_info();
                       break;
                   }
               }

            });

            msgBox.exec();

           });

    }else{

        clearLayout(ui->verticalLayout_2);
        QMessageBox::warning(this, "Sorry", "You do not have enough Gold to buy this item!");
    }

    delete fr;
    clearLayout(ui->verticalLayout_2);
    Get_info();

    setCursorForAllButtons(this);
}

void Gamepage::on_New_farm_pushButton_clicked()
{

    if(ui->label_16->isVisible()){

        QMessageBox::information(this, "full", "addaddsad");

    }else{

        if(score >= 3){

            score = score - 3;

            ui->label_Score->setText( "Score : " + QString::number(score));

            if(ui->label_2->isHidden()){

                ui->label_2->show();
                ui->Feild_2->show();

            }else if(ui->label_2->isVisible() && ui->label_3->isHidden()){

                ui->label_3->show();
                ui->Feild_3->show();

            }else if(ui->label_3->isVisible() && ui->label_4->isHidden()){

                ui->label_4->show();
                ui->Feild_4->show();

            }else if(ui->label_4->isVisible() && ui->label_5->isHidden()){

                ui->label_5->show();
                ui->Feild_5->show();

            }else if(ui->label_5->isVisible() && ui->label_6->isHidden()){

                ui->label_6->show();
                ui->Feild_6->show();

            }else if(ui->label_6->isVisible() && ui->label_7->isHidden()){

                ui->label_7->show();
                ui->Feild_7->show();

            }else if(ui->label_7->isVisible() && ui->label_8->isHidden()){

                ui->label_8->show();
                ui->Feild_8->show();

            }else if(ui->label_8->isVisible() && ui->label_9->isHidden()){

                ui->label_9->show();
                ui->Feild_9->show();

            }else if(ui->label_9->isVisible() && ui->label_10->isHidden()){

                ui->label_10->show();
                ui->Feild_10->show();

            }else if(ui->label_10->isVisible() && ui->label_11->isHidden()){

                ui->label_11->show();
                ui->Feild_11->show();

            }else if(ui->label_11->isVisible() && ui->label_12->isHidden()){

                ui->label_12->show();
                ui->Feild_12->show();

            }else if(ui->label_12->isVisible() && ui->label_13->isHidden()){

                ui->label_13->show();
                ui->Feild_13->show();

            }else if(ui->label_13->isVisible() && ui->label_14->isHidden()){

                ui->label_14->show();
                ui->Feild_14->show();

            }else if(ui->label_14->isVisible() && ui->label_15->isHidden()){

                ui->label_15->show();
                ui->Feild_15->show();

            }else if(ui->label_15->isVisible() && ui->label_16->isHidden()){

                ui->label_16->show();
                ui->Feild_16->show();
            }

            Get_info();
        }else{

            clearLayout(ui->verticalLayout_2);
            QMessageBox::warning(this, "Sorry", "You do not have enough Gold to buy this item!");
            Get_info();
        }
        Get_info();
    }

    clearLayout(ui->verticalLayout_2);
    Get_info();
}

bool Gamepage::check(QPoint pos)
{
    QList<QPushButton*> buttons =  this->findChildren<QPushButton*>();
    for (QList<QPushButton*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
         QPushButton* button = *it;
       if (button->geometry().contains(pos)) {
           // Perform your action here va hast
           return false;
       }
    }

    return true;
}

void Gamepage::check_our_farm_have_farmer_or_not()
{

    QPoint pos1(210, 160);

    if(check(pos1)==true){

        F1_Having_Farmer=0;

        if((F1_Having_Farmer==0 && F1_Having_Animals_or_Seeds==0) || (F1_Having_Farmer==0 && F1_Having_Animals_or_Seeds==1)){

            ui->Start->hide();
        }

    }
    if(check(pos1)==false){

        F1_Having_Farmer=1;
        if(F1_Having_Farmer==1 && F1_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton->isHidden()  && ui->the_product_of_sheep_pushButton->isHidden()  && ui->the_product_of_cow_pushButton->isHidden()  && ui->the_product_of_wheat_pushButton->isHidden()  && ui->the_product_of_barley_pushButton->isHidden() && ui->timer_label->isHidden()){

            ui->Start->show();
        }else if(F1_Having_Farmer==1 && F1_Having_Animals_or_Seeds==0){

            ui->Start->hide();
        }
    }

    QPoint pos2(600, 160);

    if(check(pos2)==true){

        F2_Having_Farmer=0;
        if((F2_Having_Farmer==0 && F2_Having_Animals_or_Seeds==0) || (F2_Having_Farmer==0 && F2_Having_Animals_or_Seeds==1)){

            ui->Start_2->hide();
        }
    }
    if(check(pos2)==false){

        F2_Having_Farmer=1;
        if(F2_Having_Farmer==1 && F2_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_2->isHidden()  && ui->the_product_of_sheep_pushButton_2->isHidden()  && ui->the_product_of_cow_pushButton_2->isHidden()  && ui->the_product_of_wheat_pushButton_2->isHidden()  && ui->the_product_of_barley_pushButton_2->isHidden() && ui->timer_label_2->isHidden()){

            ui->Start_2->show();
        }else if(F2_Having_Farmer==1 && F2_Having_Animals_or_Seeds==0){

            ui->Start_2->hide();
        }

    }

    QPoint pos3(1320, 160);

    if(check(pos3)==true){

        F3_Having_Farmer=0;
        if((F3_Having_Farmer==0 && F3_Having_Animals_or_Seeds==0) || (F3_Having_Farmer==0 && F3_Having_Animals_or_Seeds==1)){

            ui->Start_3->hide();
        }
    }
    if(check(pos3)==false){

        F3_Having_Farmer=1;
        if(F3_Having_Farmer==1 && F3_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_3->isHidden()  && ui->the_product_of_sheep_pushButton_3->isHidden()  && ui->the_product_of_cow_pushButton_3->isHidden()  && ui->the_product_of_wheat_pushButton_3->isHidden()  && ui->the_product_of_barley_pushButton_3->isHidden() && ui->timer_label_3->isHidden()){

            ui->Start_3->show();
        }else if(F3_Having_Farmer==1 && F3_Having_Animals_or_Seeds==0){

            ui->Start_3->hide();
        }
    }


    QPoint pos4(1710, 160);

    if(check(pos4)==true){

        F4_Having_Farmer=0;
        if((F4_Having_Farmer==0 && F4_Having_Animals_or_Seeds==0) || (F4_Having_Farmer==0 && F4_Having_Animals_or_Seeds==1)){

            ui->Start_4->hide();
        }
    }
    if(check(pos4)==false){

        F4_Having_Farmer=1;
        if(F4_Having_Farmer==1 && F4_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_4->isHidden()  && ui->the_product_of_sheep_pushButton_4->isHidden()  && ui->the_product_of_cow_pushButton_4->isHidden()  && ui->the_product_of_wheat_pushButton_4->isHidden()  && ui->the_product_of_barley_pushButton_4->isHidden() && ui->timer_label_4->isHidden()){

            ui->Start_4->show();
        }else if(F4_Having_Farmer==1 && F4_Having_Animals_or_Seeds==0){

            ui->Start_4->hide();
        }
    }

    QPoint pos5(210, 390);

    if(check(pos5)==true){

        F5_Having_Farmer=0;
        if((F5_Having_Farmer==0 && F5_Having_Animals_or_Seeds==0) || (F5_Having_Farmer==0 && F5_Having_Animals_or_Seeds==1)){

            ui->Start_5->hide();
        }
    }
    if(check(pos5)==false){

        F5_Having_Farmer=1;
        if(F5_Having_Farmer==1 && F5_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_5->isHidden()  && ui->the_product_of_sheep_pushButton_5->isHidden()  && ui->the_product_of_cow_pushButton_5->isHidden()  && ui->the_product_of_wheat_pushButton_5->isHidden()  && ui->the_product_of_barley_pushButton_5->isHidden() && ui->timer_label_5->isHidden()){

            ui->Start_5->show();
        }else if(F5_Having_Farmer==1 && F5_Having_Animals_or_Seeds==0){

            ui->Start_5->hide();
        }
    }

    QPoint pos6(600, 390);

    if(check(pos6)==true){

        F6_Having_Farmer=0;
        if((F6_Having_Farmer==0 && F6_Having_Animals_or_Seeds==0) || (F6_Having_Farmer==0 && F6_Having_Animals_or_Seeds==1)){

            ui->Start_6->hide();
        }
    }
    if(check(pos6)==false){

        F6_Having_Farmer=1;
        if(F6_Having_Farmer==1 && F6_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_6->isHidden()  && ui->the_product_of_sheep_pushButton_6->isHidden()  && ui->the_product_of_cow_pushButton_6->isHidden()  && ui->the_product_of_wheat_pushButton_6->isHidden()  && ui->the_product_of_barley_pushButton_6->isHidden() && ui->timer_label_6->isHidden()){

            ui->Start_6->show();
        }else if(F6_Having_Farmer==1 && F6_Having_Animals_or_Seeds==0){

            ui->Start_6->hide();
        }
    }

    QPoint pos7(1320, 390);

    if(check(pos7)==true){

        F7_Having_Farmer=0;
        if((F7_Having_Farmer==0 && F7_Having_Animals_or_Seeds==0) || (F7_Having_Farmer==0 && F7_Having_Animals_or_Seeds==1)){

            ui->Start_7->hide();
        }
    }
    if(check(pos7)==false){

        F7_Having_Farmer=1;
        if(F7_Having_Farmer==1 && F7_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_7->isHidden()  && ui->the_product_of_sheep_pushButton_7->isHidden()  && ui->the_product_of_cow_pushButton_7->isHidden()  && ui->the_product_of_wheat_pushButton_7->isHidden()  && ui->the_product_of_barley_pushButton_7->isHidden() && ui->timer_label_7->isHidden()){

            ui->Start_7->show();
        }else if(F7_Having_Farmer==1 && F7_Having_Animals_or_Seeds==0){

            ui->Start_7->hide();
        }
    }

    QPoint pos8(1710, 390);

    if(check(pos8)==true){

        F8_Having_Farmer=0;
        if((F8_Having_Farmer==0 && F8_Having_Animals_or_Seeds==0) || (F8_Having_Farmer==0 && F8_Having_Animals_or_Seeds==1)){

            ui->Start_8->hide();
        }
    }
    if(check(pos8)==false){

        F8_Having_Farmer=1;
        if(F8_Having_Farmer==1 && F8_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_8->isHidden()  && ui->the_product_of_sheep_pushButton_8->isHidden()  && ui->the_product_of_cow_pushButton_8->isHidden()  && ui->the_product_of_wheat_pushButton_8->isHidden()  && ui->the_product_of_barley_pushButton_8->isHidden() && ui->timer_label_8->isHidden()){

            ui->Start_8->show();
        }else if(F8_Having_Farmer==1 && F8_Having_Animals_or_Seeds==0){

            ui->Start_8->hide();
        }
    }

    QPoint pos9(210, 620);

    if(check(pos9)==true){

        F9_Having_Farmer=0;
        if((F9_Having_Farmer==0 && F9_Having_Animals_or_Seeds==0) || (F9_Having_Farmer==0 && F9_Having_Animals_or_Seeds==1)){

            ui->Start_9->hide();
        }
    }
    if(check(pos9)==false){

        F9_Having_Farmer=1;
        if(F9_Having_Farmer==1 && F9_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_9->isHidden()  && ui->the_product_of_sheep_pushButton_9->isHidden()  && ui->the_product_of_cow_pushButton_9->isHidden()  && ui->the_product_of_wheat_pushButton_9->isHidden()  && ui->the_product_of_barley_pushButton_9->isHidden() && ui->timer_label_9->isHidden()){

            ui->Start_9->show();
        }else if(F9_Having_Farmer==1 && F9_Having_Animals_or_Seeds==0){

            ui->Start_9->hide();
        }
    }

    QPoint pos10(600, 620);

    if(check(pos10)==true){

        F10_Having_Farmer=0;
        if((F10_Having_Farmer==0 && F10_Having_Animals_or_Seeds==0) || (F10_Having_Farmer==0 && F10_Having_Animals_or_Seeds==1)){

            ui->Start_10->hide();
        }
    }
    if(check(pos10)==false){

        F10_Having_Farmer=1;
        if(F10_Having_Farmer==1 && F10_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_10->isHidden()  && ui->the_product_of_sheep_pushButton_10->isHidden()  && ui->the_product_of_cow_pushButton_10->isHidden()  && ui->the_product_of_wheat_pushButton_10->isHidden()  && ui->the_product_of_barley_pushButton_10->isHidden() && ui->timer_label_10->isHidden()){

            ui->Start_10->show();
        }else if(F10_Having_Farmer==1 && F10_Having_Animals_or_Seeds==0){

            ui->Start_10->hide();
        }
    }

    QPoint pos11(1320, 620);

    if(check(pos11)==true){

        F11_Having_Farmer=0;
        if((F11_Having_Farmer==0 && F11_Having_Animals_or_Seeds==0) || (F11_Having_Farmer==0 && F11_Having_Animals_or_Seeds==1)){

            ui->Start_11->hide();
        }
    }
    if(check(pos11)==false){

        F11_Having_Farmer=1;
        if(F11_Having_Farmer==1 && F11_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_11->isHidden()  && ui->the_product_of_sheep_pushButton_11->isHidden()  && ui->the_product_of_cow_pushButton_11->isHidden()  && ui->the_product_of_wheat_pushButton_11->isHidden()  && ui->the_product_of_barley_pushButton_11->isHidden() && ui->timer_label_11->isHidden()){

            ui->Start_11->show();
        }else if(F11_Having_Farmer==1 && F11_Having_Animals_or_Seeds==0){

            ui->Start_11->hide();
        }
    }

    QPoint pos12(1710, 620);

    if(check(pos12)==true){

        F12_Having_Farmer=0;
        if((F12_Having_Farmer==0 && F12_Having_Animals_or_Seeds==0) || (F12_Having_Farmer==0 && F12_Having_Animals_or_Seeds==1)){

            ui->Start_12->hide();
        }
    }
    if(check(pos12)==false){

        F12_Having_Farmer=1;
        if(F12_Having_Farmer==1 && F12_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_12->isHidden()  && ui->the_product_of_sheep_pushButton_12->isHidden()  && ui->the_product_of_cow_pushButton_12->isHidden()  && ui->the_product_of_wheat_pushButton_12->isHidden()  && ui->the_product_of_barley_pushButton_12->isHidden() && ui->timer_label_12->isHidden()){

            ui->Start_12->show();
        }else if(F12_Having_Farmer==1 && F12_Having_Animals_or_Seeds==0){

            ui->Start_12->hide();
        }
    }

    QPoint pos13(210, 850);

    if(check(pos13)==true){

        F13_Having_Farmer=0;
        if((F13_Having_Farmer==0 && F13_Having_Animals_or_Seeds==0) || (F13_Having_Farmer==0 && F13_Having_Animals_or_Seeds==1)){

            ui->Start_13->hide();
        }
    }
    if(check(pos13)==false){

        F13_Having_Farmer=1;
        if(F13_Having_Farmer==1 && F13_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_13->isHidden()  && ui->the_product_of_sheep_pushButton_13->isHidden()  && ui->the_product_of_cow_pushButton_13->isHidden()  && ui->the_product_of_wheat_pushButton_13->isHidden()  && ui->the_product_of_barley_pushButton_13->isHidden() && ui->timer_label_13->isHidden()){

            ui->Start_13->show();
        }else if(F13_Having_Farmer==1 && F13_Having_Animals_or_Seeds==0){

            ui->Start_13->hide();
        }
    }

    QPoint pos14(600, 850);

    if(check(pos14)==true){

        F14_Having_Farmer=0;
        if((F14_Having_Farmer==0 && F14_Having_Animals_or_Seeds==0) || (F14_Having_Farmer==0 && F14_Having_Animals_or_Seeds==1)){

            ui->Start_14->hide();
        }
    }
    if(check(pos14)==false){

        F14_Having_Farmer=1;
        if(F14_Having_Farmer==1 && F14_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_14->isHidden()  && ui->the_product_of_sheep_pushButton_14->isHidden()  && ui->the_product_of_cow_pushButton_14->isHidden()  && ui->the_product_of_wheat_pushButton_14->isHidden()  && ui->the_product_of_barley_pushButton_14->isHidden() && ui->timer_label_14->isHidden()){

            ui->Start_14->show();
        }else if(F14_Having_Farmer==1 && F14_Having_Animals_or_Seeds==0){

            ui->Start_14->hide();
        }
    }

    QPoint pos15(1320, 850);

    if(check(pos15)==true){

        F15_Having_Farmer=0;
        if((F15_Having_Farmer==0 && F15_Having_Animals_or_Seeds==0) || (F15_Having_Farmer==0 && F15_Having_Animals_or_Seeds==1)){

            ui->Start_15->hide();
        }
    }
    if(check(pos15)==false){

        F15_Having_Farmer=1;
        if(F15_Having_Farmer==1 && F15_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_15->isHidden()  && ui->the_product_of_sheep_pushButton_15->isHidden()  && ui->the_product_of_cow_pushButton_15->isHidden()  && ui->the_product_of_wheat_pushButton_15->isHidden()  && ui->the_product_of_barley_pushButton_15->isHidden() && ui->timer_label_15->isHidden()){

            ui->Start_15->show();
        }else if(F15_Having_Farmer==1 && F15_Having_Animals_or_Seeds==0){

            ui->Start_15->hide();
        }
    }

    QPoint pos16(1710, 850);

    if(check(pos16)==true){

        F16_Having_Farmer=0;
        if((F16_Having_Farmer==0 && F16_Having_Animals_or_Seeds==0) || (F16_Having_Farmer==0 && F16_Having_Animals_or_Seeds==1)){

            ui->Start_16->hide();
        }
    }
    if(check(pos16)==false){

        F16_Having_Farmer=1;
        if(F16_Having_Farmer==1 && F16_Having_Animals_or_Seeds==1 && ui->the_product_of_chicken_pushButton_16->isHidden()  && ui->the_product_of_sheep_pushButton_16->isHidden()  && ui->the_product_of_cow_pushButton_16->isHidden()  && ui->the_product_of_wheat_pushButton_16->isHidden()  && ui->the_product_of_barley_pushButton_16->isHidden() && ui->timer_label_16->isHidden()){

            ui->Start_16->show();
        }else if(F16_Having_Farmer==1 && F16_Having_Animals_or_Seeds==0){

            ui->Start_16->hide();
        }
    }

}

QPushButton * Gamepage::check2(QPoint pos)
{
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    QList<QPushButton*> constButtons = qAsConst(buttons);
       for (QPushButton* button : constButtons) {
           if (button->geometry().contains(pos)) {
               return button;
           }
       }
       return nullptr;
}

void Gamepage::Get_info()
{

    QPoint Pos(150, 180);

    QPushButton* buttonAtPos = this->check2(Pos);
    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           F1_Which_Of_Animals_or_Seeds=1;
           F1_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos->objectName() == "Sheep") {
           F1_Which_Of_Animals_or_Seeds=2;
           F1_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos->objectName() == "Cow") {
           F1_Which_Of_Animals_or_Seeds=3;
           F1_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos->objectName() == "Wheat") {
           F1_Which_Of_Animals_or_Seeds=4;
           F1_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos->objectName() == "Barley") {
           F1_Which_Of_Animals_or_Seeds=5;
           F1_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos == nullptr){

        F1_Which_Of_Animals_or_Seeds=0;
        F1_Having_Animals_or_Seeds=0;
    }

    QPoint Pos2(540, 180);

    QPushButton* buttonAtPos2 = this->check2(Pos2);
    if (buttonAtPos2 != nullptr) {

       if (buttonAtPos2->objectName() == "Chicken") {
           F2_Which_Of_Animals_or_Seeds=1;
           F2_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos2->objectName() == "Sheep") {
           F2_Which_Of_Animals_or_Seeds=2;
           F2_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos2->objectName() == "Cow") {
           F2_Which_Of_Animals_or_Seeds=3;
           F2_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos2->objectName() == "Wheat") {
           F2_Which_Of_Animals_or_Seeds=4;
           F2_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos2->objectName() == "Barley") {
           F2_Which_Of_Animals_or_Seeds=5;
           F2_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos2 == nullptr){

        F2_Which_Of_Animals_or_Seeds=0;
        F2_Having_Animals_or_Seeds=0;
    }

    QPoint Pos3(1260, 180);

    QPushButton* buttonAtPos3 = this->check2(Pos3);
    if (buttonAtPos3 != nullptr) {

       if (buttonAtPos3->objectName() == "Chicken") {
           F3_Which_Of_Animals_or_Seeds=1;
           F3_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos3->objectName() == "Sheep") {
           F3_Which_Of_Animals_or_Seeds=2;
           F3_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos3->objectName() == "Cow") {
           F3_Which_Of_Animals_or_Seeds=3;
           F3_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos3->objectName() == "Wheat") {
           F3_Which_Of_Animals_or_Seeds=4;
           F3_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos3->objectName() == "Barley") {
           F3_Which_Of_Animals_or_Seeds=5;
           F3_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos3 == nullptr){

        F3_Which_Of_Animals_or_Seeds=0;
        F3_Having_Animals_or_Seeds=0;
    }

    QPoint Pos4(1650, 180);

    QPushButton* buttonAtPos4 = this->check2(Pos4);
    if (buttonAtPos4 != nullptr) {

       if (buttonAtPos4->objectName() == "Chicken") {
           F4_Which_Of_Animals_or_Seeds=1;
           F4_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos4->objectName() == "Sheep") {
           F4_Which_Of_Animals_or_Seeds=2;
           F4_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos4->objectName() == "Cow") {
           F4_Which_Of_Animals_or_Seeds=3;
           F4_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos4->objectName() == "Wheat") {
           F4_Which_Of_Animals_or_Seeds=4;
           F4_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos4->objectName() == "Barley") {
           F4_Which_Of_Animals_or_Seeds=5;
           F4_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos4 == nullptr){

        F4_Which_Of_Animals_or_Seeds=0;
        F4_Having_Animals_or_Seeds=0;
    }

    QPoint Pos5(150, 410);

    QPushButton* buttonAtPos5 = this->check2(Pos5);
    if (buttonAtPos5 != nullptr) {

       if (buttonAtPos5->objectName() == "Chicken") {
           F5_Which_Of_Animals_or_Seeds=1;
           F5_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos5->objectName() == "Sheep") {
           F5_Which_Of_Animals_or_Seeds=2;
           F5_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos5->objectName() == "Cow") {
           F5_Which_Of_Animals_or_Seeds=3;
           F5_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos5->objectName() == "Wheat") {
           F5_Which_Of_Animals_or_Seeds=4;
           F5_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos5->objectName() == "Barley") {
           F5_Which_Of_Animals_or_Seeds=5;
           F5_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos5 == nullptr){

        F5_Which_Of_Animals_or_Seeds=0;
        F5_Having_Animals_or_Seeds=0;
    }

    QPoint Pos6(540, 410);

    QPushButton* buttonAtPos6 = this->check2(Pos6);
    if (buttonAtPos6 != nullptr) {

       if (buttonAtPos6->objectName() == "Chicken") {
           F6_Which_Of_Animals_or_Seeds=1;
           F6_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos6->objectName() == "Sheep") {
           F6_Which_Of_Animals_or_Seeds=2;
           F6_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos6->objectName() == "Cow") {
           F6_Which_Of_Animals_or_Seeds=3;
           F6_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos6->objectName() == "Wheat") {
           F6_Which_Of_Animals_or_Seeds=4;
           F6_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos6->objectName() == "Barley") {
           F6_Which_Of_Animals_or_Seeds=5;
           F6_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos6 == nullptr){

        F6_Which_Of_Animals_or_Seeds=0;
        F6_Having_Animals_or_Seeds=0;
    }

    QPoint Pos7(1260, 410);

    QPushButton* buttonAtPos7 = this->check2(Pos7);
    if (buttonAtPos7 != nullptr) {

       if (buttonAtPos7->objectName() == "Chicken") {
           F7_Which_Of_Animals_or_Seeds=1;
           F7_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos7->objectName() == "Sheep") {
           F7_Which_Of_Animals_or_Seeds=2;
           F7_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos7->objectName() == "Cow") {
           F7_Which_Of_Animals_or_Seeds=3;
           F7_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos7->objectName() == "Wheat") {
           F7_Which_Of_Animals_or_Seeds=4;
           F7_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos7->objectName() == "Barley") {
           F7_Which_Of_Animals_or_Seeds=5;
           F7_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos7 == nullptr){

        F7_Which_Of_Animals_or_Seeds=0;
        F7_Having_Animals_or_Seeds=0;
    }

    QPoint Pos8(1650, 410);

    QPushButton* buttonAtPos8 = this->check2(Pos8);
    if (buttonAtPos8 != nullptr) {

       if (buttonAtPos8->objectName() == "Chicken") {
           F8_Which_Of_Animals_or_Seeds=1;
           F8_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos8->objectName() == "Sheep") {
           F8_Which_Of_Animals_or_Seeds=2;
           F8_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos8->objectName() == "Cow") {
           F8_Which_Of_Animals_or_Seeds=3;
           F8_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos8->objectName() == "Wheat") {
           F8_Which_Of_Animals_or_Seeds=4;
           F8_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos8->objectName() == "Barley") {
           F8_Which_Of_Animals_or_Seeds=5;
           F8_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos8 == nullptr){

        F8_Which_Of_Animals_or_Seeds=0;
        F8_Having_Animals_or_Seeds=0;
    }

    QPoint Pos9(150, 640);

    QPushButton* buttonAtPos9 = this->check2(Pos9);
    if (buttonAtPos9 != nullptr) {

       if (buttonAtPos9->objectName() == "Chicken") {
           F9_Which_Of_Animals_or_Seeds=1;
           F9_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos9->objectName() == "Sheep") {
           F9_Which_Of_Animals_or_Seeds=2;
           F9_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos9->objectName() == "Cow") {
           F9_Which_Of_Animals_or_Seeds=3;
           F9_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos9->objectName() == "Wheat") {
           F9_Which_Of_Animals_or_Seeds=4;
           F9_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos9->objectName() == "Barley") {
           F9_Which_Of_Animals_or_Seeds=5;
           F9_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos9 == nullptr){

        F9_Which_Of_Animals_or_Seeds=0;
        F9_Having_Animals_or_Seeds=0;
    }

    QPoint Pos10(540, 640);

    QPushButton* buttonAtPos10 = this->check2(Pos10);
    if (buttonAtPos10 != nullptr) {

       if (buttonAtPos10->objectName() == "Chicken") {
           F10_Which_Of_Animals_or_Seeds=1;
           F10_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos10->objectName() == "Sheep") {
           F10_Which_Of_Animals_or_Seeds=2;
           F10_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos10->objectName() == "Cow") {
           F10_Which_Of_Animals_or_Seeds=3;
           F10_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos10->objectName() == "Wheat") {
           F10_Which_Of_Animals_or_Seeds=4;
           F10_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos10->objectName() == "Barley") {
           F10_Which_Of_Animals_or_Seeds=5;
           F10_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos10 == nullptr){

        F10_Which_Of_Animals_or_Seeds=0;
        F10_Having_Animals_or_Seeds=0;
    }

    QPoint Pos11(1260, 640);

    QPushButton* buttonAtPos11 = this->check2(Pos11);
    if (buttonAtPos11 != nullptr) {

       if (buttonAtPos11->objectName() == "Chicken") {
           F11_Which_Of_Animals_or_Seeds=1;
           F11_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos11->objectName() == "Sheep") {
           F11_Which_Of_Animals_or_Seeds=2;
           F11_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos11->objectName() == "Cow") {
           F11_Which_Of_Animals_or_Seeds=3;
           F11_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos11->objectName() == "Wheat") {
           F11_Which_Of_Animals_or_Seeds=4;
           F11_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos11->objectName() == "Barley") {
           F11_Which_Of_Animals_or_Seeds=5;
           F11_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos11 == nullptr){

        F11_Which_Of_Animals_or_Seeds=0;
        F11_Having_Animals_or_Seeds=0;
    }

    QPoint Pos12(1650, 640);

    QPushButton* buttonAtPos12 = this->check2(Pos12);
    if (buttonAtPos12 != nullptr) {

       if (buttonAtPos12->objectName() == "Chicken") {
           F12_Which_Of_Animals_or_Seeds=1;
           F12_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos12->objectName() == "Sheep") {
           F12_Which_Of_Animals_or_Seeds=2;
           F12_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos12->objectName() == "Cow") {
           F12_Which_Of_Animals_or_Seeds=3;
           F12_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos12->objectName() == "Wheat") {
           F12_Which_Of_Animals_or_Seeds=4;
           F12_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos12->objectName() == "Barley") {
           F12_Which_Of_Animals_or_Seeds=5;
           F12_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos12 == nullptr){

        F12_Which_Of_Animals_or_Seeds=0;
        F12_Having_Animals_or_Seeds=0;
    }

    QPoint Pos13(150, 870);

    QPushButton* buttonAtPos13 = this->check2(Pos13);
    if (buttonAtPos13 != nullptr) {

       if (buttonAtPos13->objectName() == "Chicken") {
           F13_Which_Of_Animals_or_Seeds=1;
           F13_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos13->objectName() == "Sheep") {
           F13_Which_Of_Animals_or_Seeds=2;
           F13_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos13->objectName() == "Cow") {
           F13_Which_Of_Animals_or_Seeds=3;
           F13_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos13->objectName() == "Wheat") {
           F13_Which_Of_Animals_or_Seeds=4;
           F13_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos13->objectName() == "Barley") {
           F13_Which_Of_Animals_or_Seeds=5;
           F13_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos13 == nullptr){

        F13_Which_Of_Animals_or_Seeds=0;
        F13_Having_Animals_or_Seeds=0;
    }

    QPoint Pos14(540, 870);

    QPushButton* buttonAtPos14 = this->check2(Pos14);
    if (buttonAtPos14 != nullptr) {

       if (buttonAtPos14->objectName() == "Chicken") {
           F14_Which_Of_Animals_or_Seeds=1;
           F14_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos14->objectName() == "Sheep") {
           F14_Which_Of_Animals_or_Seeds=2;
           F14_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos14->objectName() == "Cow") {
           F14_Which_Of_Animals_or_Seeds=3;
           F14_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos14->objectName() == "Wheat") {
           F14_Which_Of_Animals_or_Seeds=4;
           F14_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos14->objectName() == "Barley") {
           F14_Which_Of_Animals_or_Seeds=5;
           F14_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos14 == nullptr){

        F14_Which_Of_Animals_or_Seeds=0;
        F14_Having_Animals_or_Seeds=0;
    }

    QPoint Pos15(1260, 870);

    QPushButton* buttonAtPos15 = this->check2(Pos15);
    if (buttonAtPos15 != nullptr) {

       if (buttonAtPos15->objectName() == "Chicken") {
           F15_Which_Of_Animals_or_Seeds=1;
           F15_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos15->objectName() == "Sheep") {
           F15_Which_Of_Animals_or_Seeds=2;
           F15_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos15->objectName() == "Cow") {
           F15_Which_Of_Animals_or_Seeds=3;
           F15_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos15->objectName() == "Wheat") {
           F15_Which_Of_Animals_or_Seeds=4;
           F15_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos15->objectName() == "Barley") {
           F15_Which_Of_Animals_or_Seeds=5;
           F15_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos15 == nullptr){

        F15_Which_Of_Animals_or_Seeds=0;
        F15_Having_Animals_or_Seeds=0;
    }

    QPoint Pos16(1650, 870);

    QPushButton* buttonAtPos16 = this->check2(Pos16);
    if (buttonAtPos16 != nullptr) {

       if (buttonAtPos16->objectName() == "Chicken") {
           F16_Which_Of_Animals_or_Seeds=1;
           F16_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos16->objectName() == "Sheep") {
           F16_Which_Of_Animals_or_Seeds=2;
           F16_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos16->objectName() == "Cow") {
           F16_Which_Of_Animals_or_Seeds=3;
           F16_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos16->objectName() == "Wheat") {
           F16_Which_Of_Animals_or_Seeds=4;
           F16_Having_Animals_or_Seeds=1;

       } else if (buttonAtPos16->objectName() == "Barley") {
           F16_Which_Of_Animals_or_Seeds=5;
           F16_Having_Animals_or_Seeds=1;

       }
    }else if(buttonAtPos16 == nullptr){

        F16_Which_Of_Animals_or_Seeds=0;
        F16_Having_Animals_or_Seeds=0;
    }

check_our_farm_have_farmer_or_not();

}

void Gamepage::on_Start_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start->hide();
    ui->Cancel->show();
    ui->timer_label->show();
    ui->label_of_timer_1->show();

    QPoint Pos(150, 180);

    QPoint Pos2(210, 160);

    ch1 = new Chicken(ui->verticalLayout);
    sheep1 = new Sheep(ui->verticalLayout);
    cow1 = new Cow(ui->verticalLayout);
    wheat1 = new Wheat(ui->verticalLayout);
    barley1 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch1->SetTimerLabel(ui->timer_label);
           ch1->Set_label_of_timers(ui->label_of_timer_1);
           ch1->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton);
           ch1->Set_Cancel_Pushbutton(ui->Cancel);
           ch1->Set_Start_Pushbutton(ui->Start);
           ch1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch1 = this->check2(Pos2);
           ch1->Set_Farmer_Pushbutton(buttonAtPos2_ch1);
           ch1->Set_decrease_label(ui->decrease_point_label);
           ch1->decrease_label_position(170, 120);

           ch1->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch1->Farmer_pushbutton_position(210, 160);
           animation1 = new QPropertyAnimation(buttonAtPos2_ch1, "geometry", this);
           animation1->setStartValue(QRect(210, 160, buttonAtPos2_ch1->geometry().width(), buttonAtPos2_ch1->geometry().height()));
           animation1->setEndValue(QRect(330, 160, buttonAtPos2_ch1->geometry().width(), buttonAtPos2_ch1->geometry().height()));
           animation1->setEasingCurve(QEasingCurve::Type::Linear);
           animation1->setDuration(900);
           ch1->Set_Farmer_animation(animation1);

           ch1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep1->SetTimerLabel(ui->timer_label);
           sheep1->Set_label_of_timers(ui->label_of_timer_1);
           sheep1->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton);
           sheep1->Set_Cancel_Pushbutton(ui->Cancel);
           sheep1->Set_Start_Pushbutton(ui->Start);
           sheep1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep1 = this->check2(Pos2);
           sheep1->Set_Farmer_Pushbutton(buttonAtPos2_Sheep1);
           sheep1->Set_decrease_label(ui->decrease_point_label);          
           sheep1->decrease_label_position(170, 120);

           sheep1->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep1->Farmer_pushbutton_position(210, 160);
           animation1 = new QPropertyAnimation(buttonAtPos2_Sheep1, "geometry", this);
           animation1->setStartValue(QRect(210, 160, buttonAtPos2_Sheep1->geometry().width(), buttonAtPos2_Sheep1->geometry().height()));
           animation1->setEndValue(QRect(330, 160, buttonAtPos2_Sheep1->geometry().width(), buttonAtPos2_Sheep1->geometry().height()));
           animation1->setEasingCurve(QEasingCurve::Type::Linear);
           animation1->setDuration(900);
           sheep1->Set_Farmer_animation(animation1);

           sheep1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow1->SetTimerLabel(ui->timer_label);
           cow1->Set_label_of_timers(ui->label_of_timer_1);
           cow1->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton);
           cow1->Set_Cancel_Pushbutton(ui->Cancel);
           cow1->Set_Start_Pushbutton(ui->Start);
           cow1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow1 = this->check2(Pos2);
           cow1->Set_Farmer_Pushbutton(buttonAtPos2_cow1);
           cow1->Set_decrease_label(ui->decrease_point_label);
           cow1->decrease_label_position(170, 120);

           cow1->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow1->Farmer_pushbutton_position(210, 160);
           animation1 = new QPropertyAnimation(buttonAtPos2_cow1, "geometry", this);
           animation1->setStartValue(QRect(210, 160, buttonAtPos2_cow1->geometry().width(), buttonAtPos2_cow1->geometry().height()));
           animation1->setEndValue(QRect(330, 160, buttonAtPos2_cow1->geometry().width(), buttonAtPos2_cow1->geometry().height()));
           animation1->setEasingCurve(QEasingCurve::Type::Linear);
           animation1->setDuration(900);
           cow1->Set_Farmer_animation(animation1);

           cow1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat1->SetTimerLabel(ui->timer_label);
           wheat1->Set_label_of_timers(ui->label_of_timer_1);
           wheat1->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton);
           wheat1->Set_Cancel_Pushbutton(ui->Cancel);
           wheat1->Set_Start_Pushbutton(ui->Start);
           wheat1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat1 = this->check2(Pos2);
           wheat1->Set_Farmer_Pushbutton(buttonAtPos2_wheat1);
           wheat1->Set_decrease_label(ui->decrease_point_label);
           wheat1->decrease_label_position(170, 120);

           wheat1->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat1->Farmer_pushbutton_position(210, 160);
           animation1 = new QPropertyAnimation(buttonAtPos2_wheat1, "geometry", this);
           animation1->setStartValue(QRect(210, 160, buttonAtPos2_wheat1->geometry().width(), buttonAtPos2_wheat1->geometry().height()));
           animation1->setEndValue(QRect(330, 160, buttonAtPos2_wheat1->geometry().width(), buttonAtPos2_wheat1->geometry().height()));
           animation1->setEasingCurve(QEasingCurve::Type::Linear);
           animation1->setDuration(900);
           wheat1->Set_Farmer_animation(animation1);

           wheat1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley1->SetTimerLabel(ui->timer_label);
           barley1->Set_label_of_timers(ui->label_of_timer_1);
           barley1->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton);
           barley1->Set_Cancel_Pushbutton(ui->Cancel);
           barley1->Set_Start_Pushbutton(ui->Start);
           barley1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley1 = this->check2(Pos2);
           barley1->Set_Farmer_Pushbutton(buttonAtPos2_barley1);
           barley1->Set_decrease_label(ui->decrease_point_label);
           barley1->decrease_label_position(170, 120);

           barley1->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley1->Farmer_pushbutton_position(210, 160);
           animation1 = new QPropertyAnimation(buttonAtPos2_barley1, "geometry", this);
           animation1->setStartValue(QRect(210, 160, buttonAtPos2_barley1->geometry().width(), buttonAtPos2_barley1->geometry().height()));
           animation1->setEndValue(QRect(330, 160, buttonAtPos2_barley1->geometry().width(), buttonAtPos2_barley1->geometry().height()));
           animation1->setEasingCurve(QEasingCurve::Type::Linear);
           animation1->setDuration(900);
           barley1->Set_Farmer_animation(animation1);

           barley1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch1->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep1->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow1->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat1->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley1->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);

}

void Gamepage::clearLayout(QLayout *layout)
{
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}

void Gamepage::on_Cancel_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel->hide();
    ui->Start->show();

    ui->timer_label->hide();
    ui->label_of_timer_1->hide();

    QPoint Pos(150, 180);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch1->Set_Farmer_Pushbutton(buttonAtPos2_ch1);
           ch1->Farmer_pushbutton_position(210, 160);
           ch1->Set_Farmer_animation(animation1);

           ch1->Farmer_pushbutton_setenable();
           ch1->Timer_Stop();
           ch1->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep1->Set_Farmer_Pushbutton(buttonAtPos2_Sheep1);
           sheep1->Farmer_pushbutton_position(210, 160);
           sheep1->Set_Farmer_animation(animation1);

           sheep1->Farmer_pushbutton_setenable();
           sheep1->Timer_Stop();
           sheep1->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow1->Set_Farmer_Pushbutton(buttonAtPos2_cow1);
           cow1->Farmer_pushbutton_position(210, 160);
           cow1->Set_Farmer_animation(animation1);

           cow1->Farmer_pushbutton_setenable();
           cow1->Timer_Stop();
           cow1->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat1->Set_Farmer_Pushbutton(buttonAtPos2_wheat1);
           wheat1->Farmer_pushbutton_position(210, 160);
           wheat1->Set_Farmer_animation(animation1);

           wheat1->Farmer_pushbutton_setenable();
           wheat1->Timer_Stop();
           wheat1->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley1->Set_Farmer_Pushbutton(buttonAtPos2_barley1);
           barley1->Farmer_pushbutton_position(210, 160);
           barley1->Set_Farmer_animation(animation1);

           barley1->Farmer_pushbutton_setenable();
           barley1->Timer_Stop();
           barley1->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_clicked()
{
    if(number_of_Free_farmers >= 1){

        score = score + (ch1->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton->hide();
        ch1->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }

    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (sheep1->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton->hide();
        sheep1->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (cow1->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton->hide();
        cow1->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (wheat1->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton->hide();
        wheat1->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (barley1->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton->hide();
        barley1->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::Move_the_product_of_Animals_and_seeds_pushButton()
{

    ui->the_product_of_chicken_pushButton->move(160, 140);
    ui->the_product_of_sheep_pushButton->move(160, 140);
    ui->the_product_of_cow_pushButton->move(160, 140);
    ui->the_product_of_wheat_pushButton->move(160, 140);
    ui->the_product_of_barley_pushButton->move(160, 140);

    ui->the_product_of_chicken_pushButton_2->move(550, 140);
    ui->the_product_of_sheep_pushButton_2->move(550, 140);
    ui->the_product_of_cow_pushButton_2->move(550, 140);
    ui->the_product_of_wheat_pushButton_2->move(550, 140);
    ui->the_product_of_barley_pushButton_2->move(550, 140);

    ui->the_product_of_chicken_pushButton_3->move(1270, 140);
    ui->the_product_of_sheep_pushButton_3->move(1270, 140);
    ui->the_product_of_cow_pushButton_3->move(1270, 140);
    ui->the_product_of_wheat_pushButton_3->move(1270, 140);
    ui->the_product_of_barley_pushButton_3->move(1270, 140);

    ui->the_product_of_sheep_pushButton_4->move(1660, 140);
    ui->the_product_of_cow_pushButton_4->move(1660, 140);
    ui->the_product_of_wheat_pushButton_4->move(1660, 140);
    ui->the_product_of_barley_pushButton_4->move(1660, 140);

    ui->the_product_of_sheep_pushButton_5->move(160, 370);
    ui->the_product_of_cow_pushButton_5->move(160, 370);
    ui->the_product_of_wheat_pushButton_5->move(160, 370);
    ui->the_product_of_barley_pushButton_5->move(160, 370);

    ui->the_product_of_sheep_pushButton_6->move(550, 370);
    ui->the_product_of_cow_pushButton_6->move(550, 370);
    ui->the_product_of_wheat_pushButton_6->move(550, 370);
    ui->the_product_of_barley_pushButton_6->move(550, 370);

    ui->the_product_of_sheep_pushButton_7->move(1270, 370);
    ui->the_product_of_cow_pushButton_7->move(1270, 370);
    ui->the_product_of_wheat_pushButton_7->move(1270, 370);
    ui->the_product_of_barley_pushButton_7->move(1270, 370);

    ui->the_product_of_sheep_pushButton_8->move(1660, 370);
    ui->the_product_of_cow_pushButton_8->move(1660, 370);
    ui->the_product_of_wheat_pushButton_8->move(1660, 370);
    ui->the_product_of_barley_pushButton_8->move(1660, 370);

    ui->the_product_of_sheep_pushButton_9->move(160, 600);
    ui->the_product_of_cow_pushButton_9->move(160, 600);
    ui->the_product_of_wheat_pushButton_9->move(160, 600);
    ui->the_product_of_barley_pushButton_9->move(160, 600);

    ui->the_product_of_sheep_pushButton_10->move(550, 600);
    ui->the_product_of_cow_pushButton_10->move(550, 600);
    ui->the_product_of_wheat_pushButton_10->move(550, 600);
    ui->the_product_of_barley_pushButton_10->move(550, 600);

    ui->the_product_of_sheep_pushButton_11->move(1270, 600);
    ui->the_product_of_cow_pushButton_11->move(1270, 600);
    ui->the_product_of_wheat_pushButton_11->move(11270, 600);
    ui->the_product_of_barley_pushButton_11->move(1270, 600);

    ui->the_product_of_sheep_pushButton_12->move(1660, 600);
    ui->the_product_of_cow_pushButton_12->move(1660, 600);
    ui->the_product_of_wheat_pushButton_12->move(1660, 600);
    ui->the_product_of_barley_pushButton_12->move(1660, 600);

    ui->the_product_of_sheep_pushButton_13->move(160, 830);
    ui->the_product_of_cow_pushButton_13->move(160, 830);
    ui->the_product_of_wheat_pushButton_13->move(160, 830);
    ui->the_product_of_barley_pushButton_13->move(160, 830);

    ui->the_product_of_sheep_pushButton_14->move(550, 830);
    ui->the_product_of_cow_pushButton_14->move(550, 830);
    ui->the_product_of_wheat_pushButton_14->move(550, 830);
    ui->the_product_of_barley_pushButton_14->move(550, 830);

    ui->the_product_of_sheep_pushButton_15->move(1270, 830);
    ui->the_product_of_cow_pushButton_15->move(1270, 830);
    ui->the_product_of_wheat_pushButton_15->move(1270, 830);
    ui->the_product_of_barley_pushButton_15->move(1270, 830);

    ui->the_product_of_sheep_pushButton_16->move(1660, 830);
    ui->the_product_of_cow_pushButton_16->move(1660, 830);
    ui->the_product_of_wheat_pushButton_16->move(1660, 830);
    ui->the_product_of_barley_pushButton_16->move(1660, 830);
}

void Gamepage::Hide_the_product_of_Animals_and_seeds_pushButton()
{
    ui->the_product_of_chicken_pushButton->hide();
    ui->the_product_of_sheep_pushButton->hide();
    ui->the_product_of_cow_pushButton->hide();
    ui->the_product_of_wheat_pushButton->hide();
    ui->the_product_of_barley_pushButton->hide();

    ui->the_product_of_chicken_pushButton_2->hide();
    ui->the_product_of_sheep_pushButton_2->hide();
    ui->the_product_of_cow_pushButton_2->hide();
    ui->the_product_of_wheat_pushButton_2->hide();
    ui->the_product_of_barley_pushButton_2->hide();

    ui->the_product_of_chicken_pushButton_3->hide();
    ui->the_product_of_sheep_pushButton_3->hide();
    ui->the_product_of_cow_pushButton_3->hide();
    ui->the_product_of_wheat_pushButton_3->hide();
    ui->the_product_of_barley_pushButton_3->hide();

    ui->the_product_of_chicken_pushButton_4->hide();
    ui->the_product_of_sheep_pushButton_4->hide();
    ui->the_product_of_cow_pushButton_4->hide();
    ui->the_product_of_wheat_pushButton_4->hide();
    ui->the_product_of_barley_pushButton_4->hide();

    ui->the_product_of_chicken_pushButton_5->hide();
    ui->the_product_of_sheep_pushButton_5->hide();
    ui->the_product_of_cow_pushButton_5->hide();
    ui->the_product_of_wheat_pushButton_5->hide();
    ui->the_product_of_barley_pushButton_5->hide();

    ui->the_product_of_chicken_pushButton_6->hide();
    ui->the_product_of_sheep_pushButton_6->hide();
    ui->the_product_of_cow_pushButton_6->hide();
    ui->the_product_of_wheat_pushButton_6->hide();
    ui->the_product_of_barley_pushButton_6->hide();

    ui->the_product_of_chicken_pushButton_7->hide();
    ui->the_product_of_sheep_pushButton_7->hide();
    ui->the_product_of_cow_pushButton_7->hide();
    ui->the_product_of_wheat_pushButton_7->hide();
    ui->the_product_of_barley_pushButton_7->hide();

    ui->the_product_of_chicken_pushButton_8->hide();
    ui->the_product_of_sheep_pushButton_8->hide();
    ui->the_product_of_cow_pushButton_8->hide();
    ui->the_product_of_wheat_pushButton_8->hide();
    ui->the_product_of_barley_pushButton_8->hide();

    ui->the_product_of_chicken_pushButton_9->hide();
    ui->the_product_of_sheep_pushButton_9->hide();
    ui->the_product_of_cow_pushButton_9->hide();
    ui->the_product_of_wheat_pushButton_9->hide();
    ui->the_product_of_barley_pushButton_9->hide();

    ui->the_product_of_chicken_pushButton_10->hide();
    ui->the_product_of_sheep_pushButton_10->hide();
    ui->the_product_of_cow_pushButton_10->hide();
    ui->the_product_of_wheat_pushButton_10->hide();
    ui->the_product_of_barley_pushButton_10->hide();

    ui->the_product_of_chicken_pushButton_11->hide();
    ui->the_product_of_sheep_pushButton_11->hide();
    ui->the_product_of_cow_pushButton_11->hide();
    ui->the_product_of_wheat_pushButton_11->hide();
    ui->the_product_of_barley_pushButton_11->hide();

    ui->the_product_of_chicken_pushButton_12->hide();
    ui->the_product_of_sheep_pushButton_12->hide();
    ui->the_product_of_cow_pushButton_12->hide();
    ui->the_product_of_wheat_pushButton_12->hide();
    ui->the_product_of_barley_pushButton_12->hide();

    ui->the_product_of_chicken_pushButton_13->hide();
    ui->the_product_of_sheep_pushButton_13->hide();
    ui->the_product_of_cow_pushButton_13->hide();
    ui->the_product_of_wheat_pushButton_13->hide();
    ui->the_product_of_barley_pushButton_13->hide();

    ui->the_product_of_chicken_pushButton_14->hide();
    ui->the_product_of_sheep_pushButton_14->hide();
    ui->the_product_of_cow_pushButton_14->hide();
    ui->the_product_of_wheat_pushButton_14->hide();
    ui->the_product_of_barley_pushButton_14->hide();

    ui->the_product_of_chicken_pushButton_15->hide();
    ui->the_product_of_sheep_pushButton_15->hide();
    ui->the_product_of_cow_pushButton_15->hide();
    ui->the_product_of_wheat_pushButton_15->hide();
    ui->the_product_of_barley_pushButton_15->hide();

    ui->the_product_of_chicken_pushButton_16->hide();
    ui->the_product_of_sheep_pushButton_16->hide();
    ui->the_product_of_cow_pushButton_16->hide();
    ui->the_product_of_wheat_pushButton_16->hide();
    ui->the_product_of_barley_pushButton_16->hide();
}

void Gamepage::Hide_label_of_timers()
{
    ui->label_of_timer_1->hide();
    ui->label_of_timer_2->hide();
    ui->label_of_timer_3->hide();
    ui->label_of_timer_4->hide();
    ui->label_of_timer_5->hide();
    ui->label_of_timer_6->hide();
    ui->label_of_timer_7->hide();
    ui->label_of_timer_8->hide();
    ui->label_of_timer_9->hide();
    ui->label_of_timer_10->hide();
    ui->label_of_timer_11->hide();
    ui->label_of_timer_12->hide();
    ui->label_of_timer_13->hide();
    ui->label_of_timer_14->hide();
    ui->label_of_timer_15->hide();
    ui->label_of_timer_16->hide();
}

void Gamepage::Hide_Timer_labels()
{
    ui->timer_label->hide();
    ui->timer_label_2->hide();
    ui->timer_label_3->hide();
    ui->timer_label_4->hide();
    ui->timer_label_5->hide();
    ui->timer_label_6->hide();
    ui->timer_label_7->hide();
    ui->timer_label_8->hide();
    ui->timer_label_9->hide();
    ui->timer_label_10->hide();
    ui->timer_label_11->hide();
    ui->timer_label_12->hide();
    ui->timer_label_13->hide();
    ui->timer_label_14->hide();
    ui->timer_label_15->hide();
    ui->timer_label_16->hide();
}

void Gamepage::Hide_Start_pushbuttuns()
{
    ui->Start->hide();
    ui->Start_2->hide();
    ui->Start_3->hide();
    ui->Start_4->hide();
    ui->Start_5->hide();
    ui->Start_6->hide();
    ui->Start_7->hide();
    ui->Start_8->hide();
    ui->Start_9->hide();
    ui->Start_10->hide();
    ui->Start_11->hide();
    ui->Start_12->hide();
    ui->Start_13->hide();
    ui->Start_14->hide();
    ui->Start_15->hide();
    ui->Start_16->hide();
}

void Gamepage::Hide_Cancel_pushbuttons()
{
    ui->Cancel->hide();
    ui->Cancel_2->hide();
    ui->Cancel_3->hide();
    ui->Cancel_4->hide();
    ui->Cancel_5->hide();
    ui->Cancel_6->hide();
    ui->Cancel_7->hide();
    ui->Cancel_8->hide();
    ui->Cancel_9->hide();
    ui->Cancel_10->hide();
    ui->Cancel_11->hide();
    ui->Cancel_12->hide();
    ui->Cancel_13->hide();
    ui->Cancel_14->hide();
    ui->Cancel_15->hide();
    ui->Cancel_16->hide();
}

void Gamepage::Hide_Farms()
{
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
    ui->label_14->hide();
    ui->label_15->hide();
    ui->label_16->hide();

}

void Gamepage::Hide_Feilds_number_label()
{
    ui->Feild_2->hide();
    ui->Feild_3->hide();
    ui->Feild_4->hide();
    ui->Feild_5->hide();
    ui->Feild_6->hide();
    ui->Feild_7->hide();
    ui->Feild_8->hide();
    ui->Feild_9->hide();
    ui->Feild_10->hide();
    ui->Feild_11->hide();
    ui->Feild_12->hide();
    ui->Feild_13->hide();
    ui->Feild_14->hide();
    ui->Feild_15->hide();
    ui->Feild_16->hide();
}

void Gamepage::Hide_decrease_label()
{
    ui->decrease_point_label->hide();
    ui->decrease_point_label_2->hide();
    ui->decrease_point_label_3->hide();
    ui->decrease_point_label_4->hide();
    ui->decrease_point_label_5->hide();
    ui->decrease_point_label_6->hide();
    ui->decrease_point_label_7->hide();
    ui->decrease_point_label_8->hide();
    ui->decrease_point_label_9->hide();
    ui->decrease_point_label_10->hide();
    ui->decrease_point_label_11->hide();
    ui->decrease_point_label_12->hide();
    ui->decrease_point_label_13->hide();
    ui->decrease_point_label_14->hide();
    ui->decrease_point_label_15->hide();
    ui->decrease_point_label_16->hide();
}

void Gamepage::Default_farmer()
{
    Farmer * farmer = new Farmer(ui->Farmer_verticalLayout);

    farmer->pushButton->setObjectName("Farmer");

    connect(farmer->pushButton, &QPushButton::clicked, this, [this, farmer](){ QMessageBox msgBox;
        msgBox.setText("Farmer""<ul>""<li>""Purchase price = 5""</li>" "<li>""Farmer Status = Free""</li>" "</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/Grass2.jpg"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/farmer.png"));



        // Add custom buttons
        QHash<QAbstractButton*, int> buttonMap;
        for (int i = 1; i <= 17; ++i) {
          QPushButton* button = new QPushButton(QString("%1").arg(i));
          msgBox.addButton(button, i == 17 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
          buttonMap[button] = i;

        //  button->setMinimumSize(56, 40);
           button->setMinimumSize(40, 40);

           if(i==1){

               QPoint pos(210, 160);

               if(check(pos)==true){

                   F1_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel->isVisible())){

                   F1_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==2 && ui->label_2->isHidden()){

               button->setEnabled(false);

           }else if(i==2 && ui->label_2->isVisible()){

               QPoint pos(600, 160);

               if(check(pos)==true){

                   F2_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_2->isVisible())) {

                   F2_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==3 && ui->label_3->isHidden()){

               button->setEnabled(false);

           }else if(i==3 && ui->label_3->isVisible()){

               QPoint pos(1320, 160);

               if(check(pos)==true){

                   F3_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_3->isVisible())){

                   F3_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==4 && ui->label_4->isHidden()){

               button->setEnabled(false);

           }else if(i==4 && ui->label_4->isVisible()){

               QPoint pos(1710, 160);

               if(check(pos)==true){

                   F4_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_4->isVisible())){

                   F4_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==5 && ui->label_5->isHidden()){

               button->setEnabled(false);

           }else if(i==5 && ui->label_5->isVisible()){

               QPoint pos(210, 390);

               if(check(pos)==true){

                   F5_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_5->isVisible())){

                   F5_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==6 && ui->label_6->isHidden()){

               button->setEnabled(false);

           }else if(i==6 && ui->label_6->isVisible()){

               QPoint pos(600, 390);

               if(check(pos)==true){

                   F6_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_6->isVisible())){

                   F6_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==7 && ui->label_7->isHidden()){

               button->setEnabled(false);

           }else if(i==7 && ui->label_7->isVisible()){

               QPoint pos(1320, 390);

               if(check(pos)==true){

                   F7_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_7->isVisible())){

                   F7_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==8 && ui->label_8->isHidden()){

               button->setEnabled(false);

           }else if(i==8 && ui->label_8->isVisible()){

               QPoint pos(1710, 390);

               if(check(pos)==true){

                   F8_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_8->isVisible())){

                   F8_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==9 && ui->label_9->isHidden()){

               button->setEnabled(false);

           }else if(i==9 && ui->label_9->isVisible()){

               QPoint pos(210, 620);

               if(check(pos)==true){

                   F9_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_9->isVisible())){

                   F9_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==10 && ui->label_10->isHidden()){

               button->setEnabled(false);

           }else if(i==10 && ui->label_10->isVisible()){

               QPoint pos(600, 620);

               if(check(pos)==true){

                   F10_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_10->isVisible())){

                   F10_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==11 && ui->label_11->isHidden()){

               button->setEnabled(false);

           }else if(i==11 && ui->label_11->isVisible()){

               QPoint pos(1320, 620);

               if(check(pos)==true){

                   F11_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_11->isVisible())){

                   F11_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==12 && ui->label_12->isHidden()){

               button->setEnabled(false);

           }else if(i==12 && ui->label_12->isVisible()){

               QPoint pos(1710, 620);

               if(check(pos)==true){

                   F12_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_12->isVisible())){

                   F12_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==13 && ui->label_13->isHidden()){

               button->setEnabled(false);

           }else if(i==13 && ui->label_13->isVisible()){

               QPoint pos(210, 850);

               if(check(pos)==true){

                   F13_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_13->isVisible())){

                   F13_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==14 && ui->label_14->isHidden()){

               button->setEnabled(false);

           }else if(i==14 && ui->label_14->isVisible()){

               QPoint pos(600, 850);

               if(check(pos)==true){

                   F14_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_14->isVisible())){

                   F14_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==15 && ui->label_15->isHidden()){

               button->setEnabled(false);

           }else if(i==15 && ui->label_15->isVisible()){

               QPoint pos(1320, 850);

               if(check(pos)==true){

                   F15_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_15->isVisible())){

                   F15_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

           if(i==16 && ui->label_16->isHidden()){

               button->setEnabled(false);

           }else if(i==16 && ui->label_16->isVisible()){

               QPoint pos(1710, 850);

               if(check(pos)==true){

                   F16_Having_Farmer=0;
                   button->setEnabled(true);
               }
               if((check(pos)==false) || (check(pos)==true && ui->Cancel_16->isVisible())){

                   F16_Having_Farmer=1;
                   button->setEnabled(false);
               }
           }

          if(i==17){

              button->setText("home");
              button->setMinimumSize(60,40);

          }

        }
    // clazy:exclude:connect-3arg-lambda
        QObject *context = this;
        QObject::connect(&msgBox, &QMessageBox::finished, context,[&](){
           QAbstractButton* clickedButton = msgBox.clickedButton();
           if (clickedButton) {
               int buttonNumber = buttonMap[clickedButton];

               switch(buttonNumber) {

               case 1:

                   if(F1_Having_Farmer==0){

                       farmer->pushButton->move(210, 160);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F1_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 2:

                   if(F2_Having_Farmer==0){

                       farmer->pushButton->move(600, 160);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F2_Having_Farmer=1;
                   }

                   Get_info();


                   break;
               case 3:
                   // Perform action for Button 2

                   if(F3_Having_Farmer==0){

                       farmer->pushButton->move(1320, 160);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F3_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 4:
                   // Perform action for Button 2

                   if(F4_Having_Farmer==0){

                       farmer->pushButton->move(1710, 160);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F4_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 5:
                   // Perform action for Button 2

                   if(F5_Having_Farmer==0){

                       farmer->pushButton->move(210, 390);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F5_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 6:
                   // Perform action for Button 2

                   if(F6_Having_Farmer==0){

                       farmer->pushButton->move(600, 390);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F6_Having_Farmer=1;
                   }

                   Get_info();


                   break;
               case 7:
                   // Perform action for Button 2

                   if(F7_Having_Farmer==0){

                       farmer->pushButton->move(1320, 390);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F7_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 8:
                   // Perform action for Button 2

                   if(F8_Having_Farmer==0){

                       farmer->pushButton->move(1710, 390);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F8_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 9:
                   // Perform action for Button 2

                   if(F9_Having_Farmer==0){

                       farmer->pushButton->move(210, 620);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F9_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 10:
                   // Perform action for Button 2

                   if(F10_Having_Farmer==0){

                       farmer->pushButton->move(600, 620);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F10_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 11:
                   // Perform action for Button 2

                   if(F11_Having_Farmer==0){

                       farmer->pushButton->move(1320, 620);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F11_Having_Farmer=1;
                   }
                   Get_info();

                   break;
               case 12:
                   // Perform action for Button 2

                   if(F12_Having_Farmer==0){

                       farmer->pushButton->move(1710, 620);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F12_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 13:
                   // Perform action for Button 2

                   if(F13_Having_Farmer==0){

                       farmer->pushButton->move(210, 850);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F13_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 14:
                   // Perform action for Button 2

                   if(F14_Having_Farmer==0){

                       farmer->pushButton->move(600, 850);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F14_Having_Farmer=1;
                   }

                   Get_info();

                   break;
               case 15:
                   // Perform action for Button 2

                   if(F15_Having_Farmer==0){

                       farmer->pushButton->move(1320, 850);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F15_Having_Farmer=1;
                   }

                   Get_info();


                   break;
               case 16:
                   // Perform action for Button 2

                   if(F16_Having_Farmer==0){

                       farmer->pushButton->move(1710, 850);
                       farmer->pushButton->setParent(this);
                       farmer->pushButton->show();
                       F16_Having_Farmer=1;
                   }

                   Get_info();



                   break;
               case 17:
                   //add to verticall layout
                   farmer->pushButton->move(2000, 10);

                   ui->Farmer_verticalLayout->addWidget(farmer->pushButton);

                   Get_info();

                   break;

               default:
                   Get_info();
                   break;
               }
           }

        });

        msgBox.exec();

       });

}

void Gamepage::on_Start_2_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_2->hide();
    ui->Cancel_2->show();
    ui->timer_label_2->show();
    ui->label_of_timer_2->show();

    QPoint Pos(540, 180);

    QPoint Pos2(600, 160);

    ch2 = new Chicken(ui->verticalLayout);
    sheep2 = new Sheep(ui->verticalLayout);
    cow2 = new Cow(ui->verticalLayout);
    wheat2 = new Wheat(ui->verticalLayout);
    barley2 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch2->SetTimerLabel(ui->timer_label_2);
           ch2->Set_label_of_timers(ui->label_of_timer_2);
           ch2->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_2);
           ch2->Set_Cancel_Pushbutton(ui->Cancel_2);
           ch2->Set_Start_Pushbutton(ui->Start_2);
           ch2->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch2 = this->check2(Pos2);
           ch2->Set_Farmer_Pushbutton(buttonAtPos2_ch2);
           ch2->Set_decrease_label(ui->decrease_point_label_2);
           ch2->decrease_label_position(560, 120);

           ch2->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch2->Farmer_pushbutton_position(600, 160);
           animation2 = new QPropertyAnimation(buttonAtPos2_ch2, "geometry", this);
           animation2->setStartValue(QRect(600, 160, buttonAtPos2_ch2->geometry().width(), buttonAtPos2_ch2->geometry().height()));
           animation2->setEndValue(QRect(720, 160, buttonAtPos2_ch2->geometry().width(), buttonAtPos2_ch2->geometry().height()));
           animation2->setEasingCurve(QEasingCurve::Type::Linear);
           animation2->setDuration(900);
           ch2->Set_Farmer_animation(animation2);

           ch2->TurnTimerOn2();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep2->SetTimerLabel(ui->timer_label_2);
           sheep2->Set_label_of_timers(ui->label_of_timer_2);
           sheep2->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_2);
           sheep2->Set_Cancel_Pushbutton(ui->Cancel_2);
           sheep2->Set_Start_Pushbutton(ui->Start_2);
           sheep2->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep2 = this->check2(Pos2);
           sheep2->Set_Farmer_Pushbutton(buttonAtPos2_Sheep2);
           sheep2->Set_decrease_label(ui->decrease_point_label_2);
           sheep2->decrease_label_position(560, 120);

           sheep2->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep2->Farmer_pushbutton_position(600, 160);
           animation2 = new QPropertyAnimation(buttonAtPos2_Sheep2, "geometry", this);
           animation2->setStartValue(QRect(600, 160, buttonAtPos2_Sheep2->geometry().width(), buttonAtPos2_Sheep2->geometry().height()));
           animation2->setEndValue(QRect(720, 160, buttonAtPos2_Sheep2->geometry().width(), buttonAtPos2_Sheep2->geometry().height()));
           animation2->setEasingCurve(QEasingCurve::Type::Linear);
           animation2->setDuration(900);
           sheep2->Set_Farmer_animation(animation2);

           sheep2->TurnTimerOn2();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow2->SetTimerLabel(ui->timer_label_2);
           cow2->Set_label_of_timers(ui->label_of_timer_2);
           cow2->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_2);
           cow2->Set_Cancel_Pushbutton(ui->Cancel_2);
           cow2->Set_Start_Pushbutton(ui->Start_2);
           cow2->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow2 = this->check2(Pos2);
           cow2->Set_Farmer_Pushbutton(buttonAtPos2_cow2);
           cow2->Set_decrease_label(ui->decrease_point_label_2);
           cow2->decrease_label_position(560, 120);

           cow2->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow2->Farmer_pushbutton_position(600, 160);
           animation2 = new QPropertyAnimation(buttonAtPos2_cow2, "geometry", this);
           animation2->setStartValue(QRect(600, 160, buttonAtPos2_cow2->geometry().width(), buttonAtPos2_cow2->geometry().height()));
           animation2->setEndValue(QRect(720, 160, buttonAtPos2_cow2->geometry().width(), buttonAtPos2_cow2->geometry().height()));
           animation2->setEasingCurve(QEasingCurve::Type::Linear);
           animation2->setDuration(900);
           cow2->Set_Farmer_animation(animation2);


           cow2->TurnTimerOn2();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat2->SetTimerLabel(ui->timer_label_2);
           wheat2->Set_label_of_timers(ui->label_of_timer_2);
           wheat2->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_2);
           wheat2->Set_Cancel_Pushbutton(ui->Cancel_2);
           wheat2->Set_Start_Pushbutton(ui->Start_2);
           wheat2->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat2 = this->check2(Pos2);
           wheat2->Set_Farmer_Pushbutton(buttonAtPos2_wheat2);
           wheat2->Set_decrease_label(ui->decrease_point_label_2);
           wheat2->decrease_label_position(560, 120);

           wheat2->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat2->Farmer_pushbutton_position(600, 160);
           animation2 = new QPropertyAnimation(buttonAtPos2_wheat2, "geometry", this);
           animation2->setStartValue(QRect(600, 160, buttonAtPos2_wheat2->geometry().width(), buttonAtPos2_wheat2->geometry().height()));
           animation2->setEndValue(QRect(720, 160, buttonAtPos2_wheat2->geometry().width(), buttonAtPos2_wheat2->geometry().height()));
           animation2->setEasingCurve(QEasingCurve::Type::Linear);
           animation2->setDuration(900);
           wheat2->Set_Farmer_animation(animation2);

           wheat2->TurnTimerOn2();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley2->SetTimerLabel(ui->timer_label_2);
           barley2->Set_label_of_timers(ui->label_of_timer_2);
           barley2->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_2);
           barley2->Set_Cancel_Pushbutton(ui->Cancel_2);
           barley2->Set_Start_Pushbutton(ui->Start_2);
           barley2->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley2 = this->check2(Pos2);
           barley2->Set_Farmer_Pushbutton(buttonAtPos2_barley2);
           barley2->Set_decrease_label(ui->decrease_point_label_2);
           barley2->decrease_label_position(560, 120);

           barley2->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley2->Farmer_pushbutton_position(600, 160);
           animation2 = new QPropertyAnimation(buttonAtPos2_barley2, "geometry", this);
           animation2->setStartValue(QRect(600, 160, buttonAtPos2_barley2->geometry().width(), buttonAtPos2_barley2->geometry().height()));
           animation2->setEndValue(QRect(720, 160, buttonAtPos2_barley2->geometry().width(), buttonAtPos2_barley2->geometry().height()));
           animation2->setEasingCurve(QEasingCurve::Type::Linear);
           animation2->setDuration(900);
           barley2->Set_Farmer_animation(animation2);

           barley2->TurnTimerOn2();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch2->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep2->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow2->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat2->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley2->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_2_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_2->hide();
    ui->Start_2->show();

    ui->timer_label_2->hide();
    ui->label_of_timer_2->hide();

    QPoint Pos(540, 180);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch2->Set_Farmer_Pushbutton(buttonAtPos2_ch2);
           ch2->Farmer_pushbutton_position(600, 160);
           ch2->Set_Farmer_animation(animation2);

           ch2->Farmer_pushbutton_setenable2();
           ch2->Timer2_Stop();
           ch2->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep2->Set_Farmer_Pushbutton(buttonAtPos2_Sheep2);
           sheep2->Farmer_pushbutton_position(600, 160);
           sheep2->Set_Farmer_animation(animation2);

           sheep2->Farmer_pushbutton_setenable2();
           sheep2->Timer2_Stop();
           sheep2->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow2->Set_Farmer_Pushbutton(buttonAtPos2_cow2);
           cow2->Farmer_pushbutton_position(600, 160);
           cow2->Set_Farmer_animation(animation2);

           cow2->Farmer_pushbutton_setenable2();
           cow2->Timer2_Stop();
           cow2->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat2->Set_Farmer_Pushbutton(buttonAtPos2_wheat2);
           wheat2->Farmer_pushbutton_position(600, 160);
           wheat2->Set_Farmer_animation(animation2);

           wheat2->Farmer_pushbutton_setenable2();
           wheat2->Timer2_Stop();
           wheat2->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley2->Set_Farmer_Pushbutton(buttonAtPos2_barley2);
           barley2->Farmer_pushbutton_position(600, 160);
           barley2->Set_Farmer_animation(animation2);

           barley2->Farmer_pushbutton_setenable2();
           barley2->Timer2_Stop();
           barley2->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_2_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (ch2->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_2->hide();
        ch2->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_2->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_2_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep2->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_2->hide();
        sheep2->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_2->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_2_clicked()
{       
    if(number_of_Free_farmers >= 1){

        score = score + (cow2->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_2->hide();
        cow2->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_2->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_2_clicked()
{        
    if(number_of_Free_farmers >= 1){

        score = score + (wheat2->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_2->hide();
        wheat2->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_2->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_2_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (barley2->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_2->hide();
        barley2->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_2->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_3_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));


    ui->Start_3->hide();
    ui->Cancel_3->show();
    ui->timer_label_3->show();
    ui->label_of_timer_3->show();

    QPoint Pos(1260, 180);

    QPoint Pos2(1320, 160);

    ch3 = new Chicken(ui->verticalLayout);
    sheep3 = new Sheep(ui->verticalLayout);
    cow3 = new Cow(ui->verticalLayout);
    wheat3 = new Wheat(ui->verticalLayout);
    barley3 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch3->SetTimerLabel(ui->timer_label_3);
           ch3->Set_label_of_timers(ui->label_of_timer_3);
           ch3->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_3);
           ch3->Set_Cancel_Pushbutton(ui->Cancel_3);
           ch3->Set_Start_Pushbutton(ui->Start_3);
           ch3->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch3 = this->check2(Pos2);
           ch3->Set_Farmer_Pushbutton(buttonAtPos2_ch3);
           ch3->Set_decrease_label(ui->decrease_point_label_3);
           ch3->decrease_label_position(1280, 120);

           ch3->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch3->Farmer_pushbutton_position(1320, 160);
           animation3 = new QPropertyAnimation(buttonAtPos2_ch3, "geometry", this);
           animation3->setStartValue(QRect(1320, 160, buttonAtPos2_ch3->geometry().width(), buttonAtPos2_ch3->geometry().height()));
           animation3->setEndValue(QRect(1440, 160, buttonAtPos2_ch3->geometry().width(), buttonAtPos2_ch3->geometry().height()));
           animation3->setEasingCurve(QEasingCurve::Type::Linear);
           animation3->setDuration(900);
           ch3->Set_Farmer_animation(animation3);

           ch3->TurnTimerOn3();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep3->SetTimerLabel(ui->timer_label_3);
           sheep3->Set_label_of_timers(ui->label_of_timer_3);
           sheep3->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_3);
           sheep3->Set_Cancel_Pushbutton(ui->Cancel_3);
           sheep3->Set_Start_Pushbutton(ui->Start_3);
           sheep3->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep3 = this->check2(Pos2);
           sheep3->Set_Farmer_Pushbutton(buttonAtPos2_Sheep3);
           sheep3->Set_decrease_label(ui->decrease_point_label_3);
           sheep3->decrease_label_position(1280, 120);

           sheep3->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep3->Farmer_pushbutton_position(1320, 160);
           animation3 = new QPropertyAnimation(buttonAtPos2_Sheep3, "geometry", this);
           animation3->setStartValue(QRect(1320, 160, buttonAtPos2_Sheep3->geometry().width(), buttonAtPos2_Sheep3->geometry().height()));
           animation3->setEndValue(QRect(1440, 160, buttonAtPos2_Sheep3->geometry().width(), buttonAtPos2_Sheep3->geometry().height()));
           animation3->setEasingCurve(QEasingCurve::Type::Linear);
           animation3->setDuration(900);
           sheep3->Set_Farmer_animation(animation3);

           sheep3->TurnTimerOn3();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow3->SetTimerLabel(ui->timer_label_3);
           cow3->Set_label_of_timers(ui->label_of_timer_3);
           cow3->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_3);
           cow3->Set_Cancel_Pushbutton(ui->Cancel_3);
           cow3->Set_Start_Pushbutton(ui->Start_3);
           cow3->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow3 = this->check2(Pos2);
           cow3->Set_Farmer_Pushbutton(buttonAtPos2_cow3);
           cow3->Set_decrease_label(ui->decrease_point_label_3);
           cow3->decrease_label_position(1280, 120);

           cow3->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow3->Farmer_pushbutton_position(1320, 160);
           animation3 = new QPropertyAnimation(buttonAtPos2_cow3, "geometry", this);
           animation3->setStartValue(QRect(1320, 160, buttonAtPos2_cow3->geometry().width(), buttonAtPos2_cow3->geometry().height()));
           animation3->setEndValue(QRect(1440, 160, buttonAtPos2_cow3->geometry().width(), buttonAtPos2_cow3->geometry().height()));
           animation3->setEasingCurve(QEasingCurve::Type::Linear);
           animation3->setDuration(900);
           cow3->Set_Farmer_animation(animation3);

           cow3->TurnTimerOn3();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat3->SetTimerLabel(ui->timer_label_3);
           wheat3->Set_label_of_timers(ui->label_of_timer_3);
           wheat3->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_3);
           wheat3->Set_Cancel_Pushbutton(ui->Cancel_3);
           wheat3->Set_Start_Pushbutton(ui->Start_3);
           wheat3->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat3 = this->check2(Pos2);
           wheat3->Set_Farmer_Pushbutton(buttonAtPos2_wheat3);
           wheat3->Set_decrease_label(ui->decrease_point_label_3);
           wheat3->decrease_label_position(1280, 120);

           wheat3->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat3->Farmer_pushbutton_position(1320, 160);
           animation3 = new QPropertyAnimation(buttonAtPos2_wheat3, "geometry", this);
           animation3->setStartValue(QRect(1320, 160, buttonAtPos2_wheat3->geometry().width(), buttonAtPos2_wheat3->geometry().height()));
           animation3->setEndValue(QRect(1440, 160, buttonAtPos2_wheat3->geometry().width(), buttonAtPos2_wheat3->geometry().height()));
           animation3->setEasingCurve(QEasingCurve::Type::Linear);
           animation3->setDuration(900);
           wheat3->Set_Farmer_animation(animation3);

           wheat3->TurnTimerOn3();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley3->SetTimerLabel(ui->timer_label_3);
           barley3->Set_label_of_timers(ui->label_of_timer_3);
           barley3->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_3);
           barley3->Set_Cancel_Pushbutton(ui->Cancel_3);
           barley3->Set_Start_Pushbutton(ui->Start_3);
           barley3->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley3 = this->check2(Pos2);
           barley3->Set_Farmer_Pushbutton(buttonAtPos2_barley3);
           barley3->Set_decrease_label(ui->decrease_point_label_3);
           barley3->decrease_label_position(1280, 120);

           barley3->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley3->Farmer_pushbutton_position(1320, 160);
           animation3 = new QPropertyAnimation(buttonAtPos2_barley3, "geometry", this);
           animation3->setStartValue(QRect(1320, 160, buttonAtPos2_barley3->geometry().width(), buttonAtPos2_barley3->geometry().height()));
           animation3->setEndValue(QRect(1440, 160, buttonAtPos2_barley3->geometry().width(), buttonAtPos2_barley3->geometry().height()));
           animation3->setEasingCurve(QEasingCurve::Type::Linear);
           animation3->setDuration(900);
           barley3->Set_Farmer_animation(animation3);

           barley3->TurnTimerOn3();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch3->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep3->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow3->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat3->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley3->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_3_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_3->hide();
    ui->Start_3->show();

    ui->timer_label_3->hide();
    ui->label_of_timer_3->hide();

    QPoint Pos(1260, 180);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch3->Set_Farmer_Pushbutton(buttonAtPos2_ch3);
           ch3->Farmer_pushbutton_position(1320, 160);
           ch3->Set_Farmer_animation(animation3);

           ch3->Farmer_pushbutton_setenable3();
           ch3->Timer3_Stop();
           ch3->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep3->Set_Farmer_Pushbutton(buttonAtPos2_Sheep3);
           sheep3->Farmer_pushbutton_position(1320, 160);
           sheep3->Set_Farmer_animation(animation3);

           sheep3->Farmer_pushbutton_setenable3();
           sheep3->Timer3_Stop();
           sheep3->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow3->Set_Farmer_Pushbutton(buttonAtPos2_cow3);
           cow3->Farmer_pushbutton_position(1320, 160);
           cow3->Set_Farmer_animation(animation3);

           cow3->Farmer_pushbutton_setenable3();
           cow3->Timer3_Stop();
           cow3->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat3->Set_Farmer_Pushbutton(buttonAtPos2_wheat3);
           wheat3->Farmer_pushbutton_position(1320, 160);
           wheat3->Set_Farmer_animation(animation3);

           wheat3->Farmer_pushbutton_setenable3();
           wheat3->Timer3_Stop();
           wheat3->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley3->Set_Farmer_Pushbutton(buttonAtPos2_barley3);
           barley3->Farmer_pushbutton_position(1320, 160);
           barley3->Set_Farmer_animation(animation3);

           barley3->Farmer_pushbutton_setenable3();
           barley3->Timer3_Stop();
           barley3->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_3_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (ch3->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_3->hide();
        ch3->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_3->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_3_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep3->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_3->hide();
        sheep3->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_3->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_3_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (cow3->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_3->hide();
        cow3->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_3->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_3_clicked()
{ 
    if(number_of_Free_farmers >= 1){

        score = score + (wheat3->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_3->hide();
        wheat3->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_3->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_3_clicked()
{ 
    if(number_of_Free_farmers >= 1){

        score = score + (barley3->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_3->hide();
        barley3->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_3->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_4_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));


    ui->Start_4->hide();
    ui->Cancel_4->show();
    ui->timer_label_4->show();
    ui->label_of_timer_4->show();

    QPoint Pos(1650, 180);

    QPoint Pos2(1710, 160);

    ch4 = new Chicken(ui->verticalLayout);
    sheep4 = new Sheep(ui->verticalLayout);
    cow4 = new Cow(ui->verticalLayout);
    wheat4 = new Wheat(ui->verticalLayout);
    barley4 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch4->SetTimerLabel(ui->timer_label_4);
           ch4->Set_label_of_timers(ui->label_of_timer_4);
           ch4->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_4);
           ch4->Set_Cancel_Pushbutton(ui->Cancel_4);
           ch4->Set_Start_Pushbutton(ui->Start_4);
           ch4->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch4 = this->check2(Pos2);
           ch4->Set_Farmer_Pushbutton(buttonAtPos2_ch4);
           ch4->Set_decrease_label(ui->decrease_point_label_4);
           ch4->decrease_label_position(1670, 120);

           ch4->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch4->Farmer_pushbutton_position(1710, 160);
           animation4 = new QPropertyAnimation(buttonAtPos2_ch4, "geometry", this);
           animation4->setStartValue(QRect(1710, 160, buttonAtPos2_ch4->geometry().width(), buttonAtPos2_ch4->geometry().height()));
           animation4->setEndValue(QRect(1830, 160, buttonAtPos2_ch4->geometry().width(), buttonAtPos2_ch4->geometry().height()));
           animation4->setEasingCurve(QEasingCurve::Type::Linear);
           animation4->setDuration(900);
           ch4->Set_Farmer_animation(animation4);

           ch4->TurnTimerOn4();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep4->SetTimerLabel(ui->timer_label_4);
           sheep4->Set_label_of_timers(ui->label_of_timer_4);
           sheep4->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_4);
           sheep4->Set_Cancel_Pushbutton(ui->Cancel_4);
           sheep4->Set_Start_Pushbutton(ui->Start_4);
           sheep4->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep4 = this->check2(Pos2);
           sheep4->Set_Farmer_Pushbutton(buttonAtPos2_Sheep4);
           sheep4->Set_decrease_label(ui->decrease_point_label_4);
           sheep4->decrease_label_position(1670, 120);

           sheep4->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep4->Farmer_pushbutton_position(1710, 160);
           animation4 = new QPropertyAnimation(buttonAtPos2_Sheep4, "geometry", this);
           animation4->setStartValue(QRect(1710, 160, buttonAtPos2_Sheep4->geometry().width(), buttonAtPos2_Sheep4->geometry().height()));
           animation4->setEndValue(QRect(1830, 160, buttonAtPos2_Sheep4->geometry().width(), buttonAtPos2_Sheep4->geometry().height()));
           animation4->setEasingCurve(QEasingCurve::Type::Linear);
           animation4->setDuration(900);
           sheep4->Set_Farmer_animation(animation4);

           sheep4->TurnTimerOn4();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow4->SetTimerLabel(ui->timer_label_4);
           cow4->Set_label_of_timers(ui->label_of_timer_4);
           cow4->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_4);
           cow4->Set_Cancel_Pushbutton(ui->Cancel_4);
           cow4->Set_Start_Pushbutton(ui->Start_4);
           cow4->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow4 = this->check2(Pos2);
           cow4->Set_Farmer_Pushbutton(buttonAtPos2_cow3);
           cow4->Set_decrease_label(ui->decrease_point_label_4);
           cow4->decrease_label_position(1670, 120);

           cow4->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow4->Farmer_pushbutton_position(1710, 160);
           animation4 = new QPropertyAnimation(buttonAtPos2_cow4, "geometry", this);
           animation4->setStartValue(QRect(1710, 160, buttonAtPos2_cow4->geometry().width(), buttonAtPos2_cow4->geometry().height()));
           animation4->setEndValue(QRect(1830, 160, buttonAtPos2_cow4->geometry().width(), buttonAtPos2_cow4->geometry().height()));
           animation4->setEasingCurve(QEasingCurve::Type::Linear);
           animation4->setDuration(900);
           cow4->Set_Farmer_animation(animation4);

           cow4->TurnTimerOn4();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat4->SetTimerLabel(ui->timer_label_4);
           wheat4->Set_label_of_timers(ui->label_of_timer_4);
           wheat4->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_4);
           wheat4->Set_Cancel_Pushbutton(ui->Cancel_4);
           wheat4->Set_Start_Pushbutton(ui->Start_4);
           wheat4->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat4 = this->check2(Pos2);
           wheat4->Set_Farmer_Pushbutton(buttonAtPos2_wheat4);
           wheat4->Set_decrease_label(ui->decrease_point_label_4);
           wheat4->decrease_label_position(1670, 120);

           wheat4->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat4->Farmer_pushbutton_position(1710, 160);
           animation4 = new QPropertyAnimation(buttonAtPos2_wheat4, "geometry", this);
           animation4->setStartValue(QRect(1710, 160, buttonAtPos2_wheat4->geometry().width(), buttonAtPos2_wheat4->geometry().height()));
           animation4->setEndValue(QRect(1830, 160, buttonAtPos2_wheat4->geometry().width(), buttonAtPos2_wheat4->geometry().height()));
           animation4->setEasingCurve(QEasingCurve::Type::Linear);
           animation4->setDuration(900);
           wheat4->Set_Farmer_animation(animation4);

           wheat4->TurnTimerOn4();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley4->SetTimerLabel(ui->timer_label_4);
           barley4->Set_label_of_timers(ui->label_of_timer_4);
           barley4->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_4);
           barley4->Set_Cancel_Pushbutton(ui->Cancel_4);
           barley4->Set_Start_Pushbutton(ui->Start_4);
           barley4->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley4 = this->check2(Pos2);
           barley4->Set_Farmer_Pushbutton(buttonAtPos2_barley4);
           barley4->Set_decrease_label(ui->decrease_point_label_4);
           barley4->decrease_label_position(1670, 120);

           barley4->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley4->Farmer_pushbutton_position(1710, 160);
           animation4 = new QPropertyAnimation(buttonAtPos2_barley4, "geometry", this);
           animation4->setStartValue(QRect(1710, 160, buttonAtPos2_barley4->geometry().width(), buttonAtPos2_barley4->geometry().height()));
           animation4->setEndValue(QRect(1830, 160, buttonAtPos2_barley4->geometry().width(), buttonAtPos2_barley4->geometry().height()));
           animation4->setEasingCurve(QEasingCurve::Type::Linear);
           animation4->setDuration(900);
           barley4->Set_Farmer_animation(animation4);

           barley4->TurnTimerOn4();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch4->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep4->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow4->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat4->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley4->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_4_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_4->hide();
    ui->Start_4->show();

    ui->timer_label_4->hide();
    ui->label_of_timer_4->hide();

    QPoint Pos(1650, 180);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch4->Set_Farmer_Pushbutton(buttonAtPos2_ch4);
           ch4->Farmer_pushbutton_position(1710, 160);
           ch4->Set_Farmer_animation(animation4);

           ch4->Farmer_pushbutton_setenable4();
           ch4->Timer4_Stop();
           ch4->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep4->Set_Farmer_Pushbutton(buttonAtPos2_Sheep4);
           sheep4->Farmer_pushbutton_position(1710, 160);
           sheep4->Set_Farmer_animation(animation4);

           sheep4->Farmer_pushbutton_setenable4();
           sheep4->Timer4_Stop();
           sheep4->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow4->Set_Farmer_Pushbutton(buttonAtPos2_cow4);
           cow4->Farmer_pushbutton_position(1710, 160);
           cow4->Set_Farmer_animation(animation4);

           cow4->Farmer_pushbutton_setenable4();
           cow4->Timer4_Stop();
           cow4->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat4->Set_Farmer_Pushbutton(buttonAtPos2_wheat4);
           wheat4->Farmer_pushbutton_position(1710, 160);
           wheat4->Set_Farmer_animation(animation4);

           wheat4->Farmer_pushbutton_setenable4();
           wheat4->Timer4_Stop();
           wheat4->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley4->Set_Farmer_Pushbutton(buttonAtPos2_barley4);
           barley4->Farmer_pushbutton_position(1710, 160);
           barley4->Set_Farmer_animation(animation4);

           barley4->Farmer_pushbutton_setenable4();
           barley4->Timer4_Stop();
           barley4->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_4_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch4->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_4->hide();
        ch4->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_4->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_4_clicked()
{
    if(number_of_Free_farmers >= 1){

        score = score + (sheep4->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_4->hide();
        sheep4->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_4->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_4_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (cow4->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_4->hide();
        cow4->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_4->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_4_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (wheat4->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_4->hide();
        wheat4->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_4->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_4_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (barley4->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_4->hide();
        barley4->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_4->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_5_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));


    ui->Start_5->hide();
    ui->Cancel_5->show();
    ui->timer_label_5->show();
    ui->label_of_timer_5->show();

    QPoint Pos(150, 410);

    QPoint Pos2(210, 390);

    ch5 = new Chicken(ui->verticalLayout);
    sheep5 = new Sheep(ui->verticalLayout);
    cow5 = new Cow(ui->verticalLayout);
    wheat5 = new Wheat(ui->verticalLayout);
    barley5 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch5->SetTimerLabel(ui->timer_label_5);
           ch5->Set_label_of_timers(ui->label_of_timer_5);
           ch5->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_5);
           ch5->Set_Cancel_Pushbutton(ui->Cancel_5);
           ch5->Set_Start_Pushbutton(ui->Start_5);
           ch5->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch5 = this->check2(Pos2);
           ch5->Set_Farmer_Pushbutton(buttonAtPos2_ch5);
           ch5->Set_decrease_label(ui->decrease_point_label_5);
           ch5->decrease_label_position(170, 350);

           ch5->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch5->Farmer_pushbutton_position(210, 390);
           animation5 = new QPropertyAnimation(buttonAtPos2_ch5, "geometry", this);
           animation5->setStartValue(QRect(210, 390, buttonAtPos2_ch5->geometry().width(), buttonAtPos2_ch5->geometry().height()));
           animation5->setEndValue(QRect(330, 390, buttonAtPos2_ch5->geometry().width(), buttonAtPos2_ch5->geometry().height()));
           animation5->setEasingCurve(QEasingCurve::Type::Linear);
           animation5->setDuration(900);
           ch5->Set_Farmer_animation(animation5);

           ch5->TurnTimerOn5();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep5->SetTimerLabel(ui->timer_label_5);
           sheep5->Set_label_of_timers(ui->label_of_timer_5);
           sheep5->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_5);
           sheep5->Set_Cancel_Pushbutton(ui->Cancel_5);
           sheep5->Set_Start_Pushbutton(ui->Start_5);
           sheep5->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep5 = this->check2(Pos2);
           sheep5->Set_Farmer_Pushbutton(buttonAtPos2_Sheep5);
           sheep5->Set_decrease_label(ui->decrease_point_label_5);
           sheep5->decrease_label_position(170, 350);

           sheep5->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep5->Farmer_pushbutton_position(210, 390);
           animation5 = new QPropertyAnimation(buttonAtPos2_Sheep5, "geometry", this);
           animation5->setStartValue(QRect(210, 390, buttonAtPos2_Sheep5->geometry().width(), buttonAtPos2_Sheep5->geometry().height()));
           animation5->setEndValue(QRect(330, 390, buttonAtPos2_Sheep5->geometry().width(), buttonAtPos2_Sheep5->geometry().height()));
           animation5->setEasingCurve(QEasingCurve::Type::Linear);
           animation5->setDuration(900);
           sheep5->Set_Farmer_animation(animation5);

           sheep5->TurnTimerOn5();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow5->SetTimerLabel(ui->timer_label_5);
           cow5->Set_label_of_timers(ui->label_of_timer_5);
           cow5->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_5);
           cow5->Set_Cancel_Pushbutton(ui->Cancel_5);
           cow5->Set_Start_Pushbutton(ui->Start_5);
           cow5->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow5 = this->check2(Pos2);
           cow5->Set_Farmer_Pushbutton(buttonAtPos2_cow5);
           cow5->Set_decrease_label(ui->decrease_point_label_5);
           cow5->decrease_label_position(170, 350);

           cow5->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow5->Farmer_pushbutton_position(210, 390);
           animation5 = new QPropertyAnimation(buttonAtPos2_cow5, "geometry", this);
           animation5->setStartValue(QRect(210, 390, buttonAtPos2_cow5->geometry().width(), buttonAtPos2_cow5->geometry().height()));
           animation5->setEndValue(QRect(330, 390, buttonAtPos2_cow5->geometry().width(), buttonAtPos2_cow5->geometry().height()));
           animation5->setEasingCurve(QEasingCurve::Type::Linear);
           animation5->setDuration(900);
           cow5->Set_Farmer_animation(animation5);

           cow5->TurnTimerOn5();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat5->SetTimerLabel(ui->timer_label_5);
           wheat5->Set_label_of_timers(ui->label_of_timer_5);
           wheat5->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_5);
           wheat5->Set_Cancel_Pushbutton(ui->Cancel_5);
           wheat5->Set_Start_Pushbutton(ui->Start_5);
           wheat5->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat5 = this->check2(Pos2);
           wheat5->Set_Farmer_Pushbutton(buttonAtPos2_wheat5);
           wheat5->Set_decrease_label(ui->decrease_point_label_5);
           wheat5->decrease_label_position(170, 350);

           wheat5->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat5->Farmer_pushbutton_position(210, 390);
           animation5 = new QPropertyAnimation(buttonAtPos2_wheat5, "geometry", this);
           animation5->setStartValue(QRect(210, 390, buttonAtPos2_wheat5->geometry().width(), buttonAtPos2_wheat5->geometry().height()));
           animation5->setEndValue(QRect(330, 390, buttonAtPos2_wheat5->geometry().width(), buttonAtPos2_wheat5->geometry().height()));
           animation5->setEasingCurve(QEasingCurve::Type::Linear);
           animation5->setDuration(900);
           wheat5->Set_Farmer_animation(animation5);

           wheat5->TurnTimerOn5();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley5->SetTimerLabel(ui->timer_label_5);
           barley5->Set_label_of_timers(ui->label_of_timer_5);
           barley5->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_5);
           barley5->Set_Cancel_Pushbutton(ui->Cancel_5);
           barley5->Set_Start_Pushbutton(ui->Start_5);
           barley5->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley5 = this->check2(Pos2);
           barley5->Set_Farmer_Pushbutton(buttonAtPos2_barley5);
           barley5->Set_decrease_label(ui->decrease_point_label_5);
           barley5->decrease_label_position(170, 350);

           barley5->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley5->Farmer_pushbutton_position(210, 390);
           animation5 = new QPropertyAnimation(buttonAtPos2_barley5, "geometry", this);
           animation5->setStartValue(QRect(210, 390, buttonAtPos2_barley5->geometry().width(), buttonAtPos2_barley5->geometry().height()));
           animation5->setEndValue(QRect(330, 390, buttonAtPos2_barley5->geometry().width(), buttonAtPos2_barley5->geometry().height()));
           animation5->setEasingCurve(QEasingCurve::Type::Linear);
           animation5->setDuration(900);
           barley5->Set_Farmer_animation(animation5);

           barley5->TurnTimerOn5();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch5->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep5->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow5->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat5->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley5->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_5_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_5->hide();
    ui->Start_5->show();

    ui->timer_label_5->hide();
    ui->label_of_timer_5->hide();

    QPoint Pos(150, 410);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch5->Set_Farmer_Pushbutton(buttonAtPos2_ch5);
           ch5->Farmer_pushbutton_position(210, 390);
           ch5->Set_Farmer_animation(animation5);

           ch5->Farmer_pushbutton_setenable5();
           ch5->Timer5_Stop();
           ch5->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep5->Set_Farmer_Pushbutton(buttonAtPos2_Sheep5);
           sheep5->Farmer_pushbutton_position(210, 390);
           sheep5->Set_Farmer_animation(animation5);

           sheep5->Farmer_pushbutton_setenable5();
           sheep5->Timer5_Stop();
           sheep5->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow5->Set_Farmer_Pushbutton(buttonAtPos2_cow5);
           cow5->Farmer_pushbutton_position(210, 390);
           cow5->Set_Farmer_animation(animation5);

           cow5->Farmer_pushbutton_setenable5();
           cow5->Timer5_Stop();
           cow5->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat5->Set_Farmer_Pushbutton(buttonAtPos2_wheat5);
           wheat5->Farmer_pushbutton_position(210, 390);
           wheat5->Set_Farmer_animation(animation5);

           wheat5->Farmer_pushbutton_setenable5();
           wheat5->Timer5_Stop();
           wheat5->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley5->Set_Farmer_Pushbutton(buttonAtPos2_barley5);
           barley5->Farmer_pushbutton_position(210, 390);
           barley5->Set_Farmer_animation(animation5);

           barley5->Farmer_pushbutton_setenable5();
           barley5->Timer5_Stop();
           barley5->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_5_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch5->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_5->hide();
        ch5->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_5->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_5_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep5->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_5->hide();
        sheep5->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_5->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_5_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (cow5->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_5->hide();
        cow5->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_5->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_5_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (wheat5->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_5->hide();
        wheat5->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_5->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_5_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley5->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_5->hide();
        barley5->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_5->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_6_clicked()
{    
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_6->hide();
    ui->Cancel_6->show();
    ui->timer_label_6->show();
    ui->label_of_timer_6->show();

    QPoint Pos(540, 410);

    QPoint Pos2(600, 390);

    ch6 = new Chicken(ui->verticalLayout);
    sheep6 = new Sheep(ui->verticalLayout);
    cow6 = new Cow(ui->verticalLayout);
    wheat6 = new Wheat(ui->verticalLayout);
    barley6 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch6->SetTimerLabel(ui->timer_label_6);
           ch6->Set_label_of_timers(ui->label_of_timer_6);
           ch6->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_6);
           ch6->Set_Cancel_Pushbutton(ui->Cancel_6);
           ch6->Set_Start_Pushbutton(ui->Start_6);
           ch6->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch6 = this->check2(Pos2);
           ch6->Set_Farmer_Pushbutton(buttonAtPos2_ch6);
           ch6->Set_decrease_label(ui->decrease_point_label_6);
           ch6->decrease_label_position(560, 350);

           ch6->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch6->Farmer_pushbutton_position(600, 390);
           animation6 = new QPropertyAnimation(buttonAtPos2_ch6, "geometry", this);
           animation6->setStartValue(QRect(600, 390, buttonAtPos2_ch6->geometry().width(), buttonAtPos2_ch6->geometry().height()));
           animation6->setEndValue(QRect(720, 390, buttonAtPos2_ch6->geometry().width(), buttonAtPos2_ch6->geometry().height()));
           animation6->setEasingCurve(QEasingCurve::Type::Linear);
           animation6->setDuration(900);
           ch6->Set_Farmer_animation(animation6);

           ch6->TurnTimerOn6();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep6->SetTimerLabel(ui->timer_label_6);
           sheep6->Set_label_of_timers(ui->label_of_timer_6);
           sheep6->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_6);
           sheep6->Set_Cancel_Pushbutton(ui->Cancel_6);
           sheep6->Set_Start_Pushbutton(ui->Start_6);
           sheep6->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep6 = this->check2(Pos2);
           sheep6->Set_Farmer_Pushbutton(buttonAtPos2_Sheep6);
           sheep6->Set_decrease_label(ui->decrease_point_label_6);
           sheep6->decrease_label_position(560, 350);

           sheep6->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep6->Farmer_pushbutton_position(600, 390);
           animation6 = new QPropertyAnimation(buttonAtPos2_Sheep6, "geometry", this);
           animation6->setStartValue(QRect(600, 390, buttonAtPos2_Sheep6->geometry().width(), buttonAtPos2_Sheep6->geometry().height()));
           animation6->setEndValue(QRect(720, 390, buttonAtPos2_Sheep6->geometry().width(), buttonAtPos2_Sheep6->geometry().height()));
           animation6->setEasingCurve(QEasingCurve::Type::Linear);
           animation6->setDuration(900);
           sheep6->Set_Farmer_animation(animation6);

           sheep6->TurnTimerOn6();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow6->SetTimerLabel(ui->timer_label_6);
           cow6->Set_label_of_timers(ui->label_of_timer_6);
           cow6->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_6);
           cow6->Set_Cancel_Pushbutton(ui->Cancel_6);
           cow6->Set_Start_Pushbutton(ui->Start_6);
           cow6->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow6 = this->check2(Pos2);
           cow6->Set_Farmer_Pushbutton(buttonAtPos2_cow6);
           cow6->Set_decrease_label(ui->decrease_point_label_6);
           cow6->decrease_label_position(560, 350);

           cow6->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow6->Farmer_pushbutton_position(600, 390);
           animation6 = new QPropertyAnimation(buttonAtPos2_cow6, "geometry", this);
           animation6->setStartValue(QRect(600, 390, buttonAtPos2_cow6->geometry().width(), buttonAtPos2_cow6->geometry().height()));
           animation6->setEndValue(QRect(720, 390, buttonAtPos2_cow6->geometry().width(), buttonAtPos2_cow6->geometry().height()));
           animation6->setEasingCurve(QEasingCurve::Type::Linear);
           animation6->setDuration(900);
           cow6->Set_Farmer_animation(animation6);

           cow6->TurnTimerOn6();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat6->SetTimerLabel(ui->timer_label_6);
           wheat6->Set_label_of_timers(ui->label_of_timer_6);
           wheat6->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_6);
           wheat6->Set_Cancel_Pushbutton(ui->Cancel_6);
           wheat6->Set_Start_Pushbutton(ui->Start_6);
           wheat6->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat6 = this->check2(Pos2);
           wheat6->Set_Farmer_Pushbutton(buttonAtPos2_wheat6);
           wheat6->Set_decrease_label(ui->decrease_point_label_6);
           wheat6->decrease_label_position(560, 350);

           wheat6->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat6->Farmer_pushbutton_position(600, 390);
           animation6 = new QPropertyAnimation(buttonAtPos2_wheat6, "geometry", this);
           animation6->setStartValue(QRect(600, 390, buttonAtPos2_wheat6->geometry().width(), buttonAtPos2_wheat6->geometry().height()));
           animation6->setEndValue(QRect(720, 390, buttonAtPos2_wheat6->geometry().width(), buttonAtPos2_wheat6->geometry().height()));
           animation6->setEasingCurve(QEasingCurve::Type::Linear);
           animation6->setDuration(900);
           wheat6->Set_Farmer_animation(animation6);

           wheat6->TurnTimerOn6();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley6->SetTimerLabel(ui->timer_label_6);
           barley6->Set_label_of_timers(ui->label_of_timer_6);
           barley6->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_6);
           barley6->Set_Cancel_Pushbutton(ui->Cancel_6);
           barley6->Set_Start_Pushbutton(ui->Start_6);
           barley6->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley6 = this->check2(Pos2);
           barley6->Set_Farmer_Pushbutton(buttonAtPos2_barley6);
           barley6->Set_decrease_label(ui->decrease_point_label_6);
           barley6->decrease_label_position(560, 350);

           barley6->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley6->Farmer_pushbutton_position(600, 390);
           animation6 = new QPropertyAnimation(buttonAtPos2_barley6, "geometry", this);
           animation6->setStartValue(QRect(600, 390, buttonAtPos2_barley6->geometry().width(), buttonAtPos2_barley6->geometry().height()));
           animation6->setEndValue(QRect(720, 390, buttonAtPos2_barley6->geometry().width(), buttonAtPos2_barley6->geometry().height()));
           animation6->setEasingCurve(QEasingCurve::Type::Linear);
           animation6->setDuration(900);
           barley6->Set_Farmer_animation(animation6);

           barley6->TurnTimerOn6();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch6->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep6->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow6->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat6->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley6->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_6_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_6->hide();
    ui->Start_6->show();

    ui->timer_label_6->hide();
    ui->label_of_timer_6->hide();

    QPoint Pos(540, 410);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch6->Set_Farmer_Pushbutton(buttonAtPos2_ch6);
           ch6->Farmer_pushbutton_position(600, 390);
           ch6->Set_Farmer_animation(animation6);

           ch6->Farmer_pushbutton_setenable6();
           ch6->Timer6_Stop();
           ch6->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep6->Set_Farmer_Pushbutton(buttonAtPos2_Sheep6);
           sheep6->Farmer_pushbutton_position(600, 390);
           sheep6->Set_Farmer_animation(animation6);

           sheep6->Farmer_pushbutton_setenable6();
           sheep6->Timer6_Stop();
           sheep6->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow6->Set_Farmer_Pushbutton(buttonAtPos2_cow6);
           cow6->Farmer_pushbutton_position(600, 390);
           cow6->Set_Farmer_animation(animation6);

           cow6->Farmer_pushbutton_setenable6();
           cow6->Timer6_Stop();
           cow6->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat6->Set_Farmer_Pushbutton(buttonAtPos2_wheat6);
           wheat6->Farmer_pushbutton_position(600, 390);
           wheat6->Set_Farmer_animation(animation6);

           wheat6->Farmer_pushbutton_setenable6();
           wheat6->Timer6_Stop();
           wheat6->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley6->Set_Farmer_Pushbutton(buttonAtPos2_barley6);
           barley6->Farmer_pushbutton_position(600, 390);
           barley6->Set_Farmer_animation(animation6);

           barley6->Farmer_pushbutton_setenable6();
           barley6->Timer6_Stop();
           barley6->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_6_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (ch6->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_6->hide();
        ch6->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_6->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_6_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (sheep6->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_6->hide();
        sheep6->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_6->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_6_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (cow6->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_6->hide();
        cow6->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_6->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_6_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (wheat6->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_6->hide();
        wheat6->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_6->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_6_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley6->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_6->hide();
        barley6->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_6->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_7_clicked()
{

    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_7->hide();
    ui->Cancel_7->show();
    ui->timer_label_7->show();
    ui->label_of_timer_7->show();

    QPoint Pos(1260, 410);

    QPoint Pos2(1320, 390);

    ch7 = new Chicken(ui->verticalLayout);
    sheep7 = new Sheep(ui->verticalLayout);
    cow7 = new Cow(ui->verticalLayout);
    wheat7 = new Wheat(ui->verticalLayout);
    barley7 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch7->SetTimerLabel(ui->timer_label_7);
           ch7->Set_label_of_timers(ui->label_of_timer_7);
           ch7->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_7);
           ch7->Set_Cancel_Pushbutton(ui->Cancel_7);
           ch7->Set_Start_Pushbutton(ui->Start_7);
           ch7->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch7 = this->check2(Pos2);
           ch7->Set_Farmer_Pushbutton(buttonAtPos2_ch7);
           ch7->Set_decrease_label(ui->decrease_point_label_7);
           ch7->decrease_label_position(1280, 350);

           ch7->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch7->Farmer_pushbutton_position(1320, 390);
           animation7 = new QPropertyAnimation(buttonAtPos2_ch7, "geometry", this);
           animation7->setStartValue(QRect(1320, 390, buttonAtPos2_ch7->geometry().width(), buttonAtPos2_ch7->geometry().height()));
           animation7->setEndValue(QRect(1440, 390, buttonAtPos2_ch7->geometry().width(), buttonAtPos2_ch7->geometry().height()));
           animation7->setEasingCurve(QEasingCurve::Type::Linear);
           animation7->setDuration(900);
           ch7->Set_Farmer_animation(animation7);

           ch7->TurnTimerOn7();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep7->SetTimerLabel(ui->timer_label_7);
           sheep7->Set_label_of_timers(ui->label_of_timer_7);
           sheep7->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_7);
           sheep7->Set_Cancel_Pushbutton(ui->Cancel_7);
           sheep7->Set_Start_Pushbutton(ui->Start_7);
           sheep7->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep7 = this->check2(Pos2);
           sheep7->Set_Farmer_Pushbutton(buttonAtPos2_Sheep7);
           sheep7->Set_decrease_label(ui->decrease_point_label_7);
           sheep7->decrease_label_position(1280, 350);

           sheep7->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep7->Farmer_pushbutton_position(1320, 390);
           animation7 = new QPropertyAnimation(buttonAtPos2_Sheep7, "geometry", this);
           animation7->setStartValue(QRect(1320, 390, buttonAtPos2_Sheep7->geometry().width(), buttonAtPos2_Sheep7->geometry().height()));
           animation7->setEndValue(QRect(1440, 390, buttonAtPos2_Sheep7->geometry().width(), buttonAtPos2_Sheep7->geometry().height()));
           animation7->setEasingCurve(QEasingCurve::Type::Linear);
           animation7->setDuration(900);
           sheep7->Set_Farmer_animation(animation7);

           sheep7->TurnTimerOn7();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow7->SetTimerLabel(ui->timer_label_7);
           cow7->Set_label_of_timers(ui->label_of_timer_7);
           cow7->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_7);
           cow7->Set_Cancel_Pushbutton(ui->Cancel_7);
           cow7->Set_Start_Pushbutton(ui->Start_7);
           cow7->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow7 = this->check2(Pos2);
           cow7->Set_Farmer_Pushbutton(buttonAtPos2_cow7);
           cow7->Set_decrease_label(ui->decrease_point_label_7);
           cow7->decrease_label_position(560, 350);

           cow7->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow7->Farmer_pushbutton_position(1320, 390);
           animation7 = new QPropertyAnimation(buttonAtPos2_cow7, "geometry", this);
           animation7->setStartValue(QRect(1320, 390, buttonAtPos2_cow7->geometry().width(), buttonAtPos2_cow7->geometry().height()));
           animation7->setEndValue(QRect(1440, 390, buttonAtPos2_cow7->geometry().width(), buttonAtPos2_cow7->geometry().height()));
           animation7->setEasingCurve(QEasingCurve::Type::Linear);
           animation7->setDuration(900);
           cow7->Set_Farmer_animation(animation7);

           cow7->TurnTimerOn7();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat7->SetTimerLabel(ui->timer_label_7);
           wheat7->Set_label_of_timers(ui->label_of_timer_7);
           wheat7->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_7);
           wheat7->Set_Cancel_Pushbutton(ui->Cancel_7);
           wheat7->Set_Start_Pushbutton(ui->Start_7);
           wheat7->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat7 = this->check2(Pos2);
           wheat7->Set_Farmer_Pushbutton(buttonAtPos2_wheat7);
           wheat7->Set_decrease_label(ui->decrease_point_label_7);
           wheat7->decrease_label_position(1280, 350);

           wheat7->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat7->Farmer_pushbutton_position(1320, 390);
           animation7 = new QPropertyAnimation(buttonAtPos2_wheat7, "geometry", this);
           animation7->setStartValue(QRect(1320, 390, buttonAtPos2_wheat7->geometry().width(), buttonAtPos2_wheat7->geometry().height()));
           animation7->setEndValue(QRect(1440, 390, buttonAtPos2_wheat7->geometry().width(), buttonAtPos2_wheat7->geometry().height()));
           animation7->setEasingCurve(QEasingCurve::Type::Linear);
           animation7->setDuration(900);
           wheat7->Set_Farmer_animation(animation7);

           wheat7->TurnTimerOn7();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley7->SetTimerLabel(ui->timer_label_7);
           barley7->Set_label_of_timers(ui->label_of_timer_7);
           barley7->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_7);
           barley7->Set_Cancel_Pushbutton(ui->Cancel_7);
           barley7->Set_Start_Pushbutton(ui->Start_7);
           barley7->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley7 = this->check2(Pos2);
           barley7->Set_Farmer_Pushbutton(buttonAtPos2_barley7);
           barley7->Set_decrease_label(ui->decrease_point_label_7);
           barley7->decrease_label_position(1280, 350);

           barley7->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley7->Farmer_pushbutton_position(1320, 390);
           animation7 = new QPropertyAnimation(buttonAtPos2_barley7, "geometry", this);
           animation7->setStartValue(QRect(1320, 390, buttonAtPos2_barley7->geometry().width(), buttonAtPos2_barley7->geometry().height()));
           animation7->setEndValue(QRect(1440, 390, buttonAtPos2_barley7->geometry().width(), buttonAtPos2_barley7->geometry().height()));
           animation7->setEasingCurve(QEasingCurve::Type::Linear);
           animation7->setDuration(900);
           barley7->Set_Farmer_animation(animation7);

           barley7->TurnTimerOn7();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch7->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep7->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow7->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat7->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley7->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_7_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_7->hide();
    ui->Start_7->show();

    ui->timer_label_7->hide();
    ui->label_of_timer_7->hide();

    QPoint Pos(1260, 410);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch7->Set_Farmer_Pushbutton(buttonAtPos2_ch7);
           ch7->Farmer_pushbutton_position(1320, 390);
           ch7->Set_Farmer_animation(animation7);

           ch7->Farmer_pushbutton_setenable7();
           ch7->Timer7_Stop();
           ch7->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep7->Set_Farmer_Pushbutton(buttonAtPos2_Sheep7);
           sheep7->Farmer_pushbutton_position(1320, 390);
           sheep7->Set_Farmer_animation(animation7);

           sheep7->Farmer_pushbutton_setenable7();
           sheep7->Timer7_Stop();
           sheep7->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow7->Set_Farmer_Pushbutton(buttonAtPos2_cow7);
           cow7->Farmer_pushbutton_position(1320, 390);
           cow7->Set_Farmer_animation(animation7);

           cow7->Farmer_pushbutton_setenable7();
           cow7->Timer7_Stop();
           cow7->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat7->Set_Farmer_Pushbutton(buttonAtPos2_wheat7);
           wheat7->Farmer_pushbutton_position(1320, 390);
           wheat7->Set_Farmer_animation(animation7);

           wheat7->Farmer_pushbutton_setenable7();
           wheat7->Timer7_Stop();
           wheat7->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley7->Set_Farmer_Pushbutton(buttonAtPos2_barley7);
           barley7->Farmer_pushbutton_position(1320, 390);
           barley7->Set_Farmer_animation(animation7);

           barley7->Farmer_pushbutton_setenable7();
           barley7->Timer7_Stop();
           barley7->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_7_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch7->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_7->hide();
        ch7->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_7->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_7_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep7->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_7->hide();
        sheep7->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_7->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_7_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (cow7->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_7->hide();
        cow7->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_7->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_7_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (wheat7->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_7->hide();
        wheat7->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_7->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_7_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley7->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_7->hide();
        barley7->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_7->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_8_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));


    ui->Start_8->hide();
    ui->Cancel_8->show();
    ui->timer_label_8->show();
    ui->label_of_timer_8->show();

    QPoint Pos(1650, 410);

    QPoint Pos2(1710, 390);

    ch8 = new Chicken(ui->verticalLayout);
    sheep8 = new Sheep(ui->verticalLayout);
    cow8 = new Cow(ui->verticalLayout);
    wheat8 = new Wheat(ui->verticalLayout);
    barley8 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch8->SetTimerLabel(ui->timer_label_8);
           ch8->Set_label_of_timers(ui->label_of_timer_8);
           ch8->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_8);
           ch8->Set_Cancel_Pushbutton(ui->Cancel_8);
           ch8->Set_Start_Pushbutton(ui->Start_8);
           ch8->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch8 = this->check2(Pos2);
           ch8->Set_Farmer_Pushbutton(buttonAtPos2_ch8);
           ch8->Set_decrease_label(ui->decrease_point_label_8);
           ch8->decrease_label_position(1670, 350);

           ch8->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch8->Farmer_pushbutton_position(1710, 390);
           animation8 = new QPropertyAnimation(buttonAtPos2_ch8, "geometry", this);
           animation8->setStartValue(QRect(1710, 390, buttonAtPos2_ch8->geometry().width(), buttonAtPos2_ch8->geometry().height()));
           animation8->setEndValue(QRect(1830, 390, buttonAtPos2_ch8->geometry().width(), buttonAtPos2_ch8->geometry().height()));
           animation8->setEasingCurve(QEasingCurve::Type::Linear);
           animation8->setDuration(900);
           ch8->Set_Farmer_animation(animation8);

           ch8->TurnTimerOn8();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep8->SetTimerLabel(ui->timer_label_8);
           sheep8->Set_label_of_timers(ui->label_of_timer_8);
           sheep8->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_8);
           sheep8->Set_Cancel_Pushbutton(ui->Cancel_8);
           sheep8->Set_Start_Pushbutton(ui->Start_8);
           sheep8->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep8 = this->check2(Pos2);
           sheep8->Set_Farmer_Pushbutton(buttonAtPos2_Sheep8);
           sheep8->Set_decrease_label(ui->decrease_point_label_8);
           sheep8->decrease_label_position(1670, 350);

           sheep8->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep8->Farmer_pushbutton_position(1710, 390);
           animation8 = new QPropertyAnimation(buttonAtPos2_Sheep8, "geometry", this);
           animation8->setStartValue(QRect(1710, 390, buttonAtPos2_Sheep8->geometry().width(), buttonAtPos2_Sheep8->geometry().height()));
           animation8->setEndValue(QRect(1830, 390, buttonAtPos2_Sheep8->geometry().width(), buttonAtPos2_Sheep8->geometry().height()));
           animation8->setEasingCurve(QEasingCurve::Type::Linear);
           animation8->setDuration(900);
           sheep8->Set_Farmer_animation(animation8);

           sheep8->TurnTimerOn8();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow8->SetTimerLabel(ui->timer_label_8);
           cow8->Set_label_of_timers(ui->label_of_timer_8);
           cow8->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_8);
           cow8->Set_Cancel_Pushbutton(ui->Cancel_8);
           cow8->Set_Start_Pushbutton(ui->Start_8);
           cow8->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow8 = this->check2(Pos2);
           cow8->Set_Farmer_Pushbutton(buttonAtPos2_cow8);
           cow8->Set_decrease_label(ui->decrease_point_label_8);
           cow8->decrease_label_position(1670, 350);

           cow8->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow8->Farmer_pushbutton_position(1710, 390);
           animation8 = new QPropertyAnimation(buttonAtPos2_cow8, "geometry", this);
           animation8->setStartValue(QRect(1710, 390, buttonAtPos2_cow8->geometry().width(), buttonAtPos2_cow8->geometry().height()));
           animation8->setEndValue(QRect(1830, 390, buttonAtPos2_cow8->geometry().width(), buttonAtPos2_cow8->geometry().height()));
           animation8->setEasingCurve(QEasingCurve::Type::Linear);
           animation8->setDuration(900);
           cow8->Set_Farmer_animation(animation8);

           cow8->TurnTimerOn8();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat8->SetTimerLabel(ui->timer_label_8);
           wheat8->Set_label_of_timers(ui->label_of_timer_8);
           wheat8->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_8);
           wheat8->Set_Cancel_Pushbutton(ui->Cancel_8);
           wheat8->Set_Start_Pushbutton(ui->Start_8);
           wheat8->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat8 = this->check2(Pos2);
           wheat8->Set_Farmer_Pushbutton(buttonAtPos2_wheat8);
           wheat8->Set_decrease_label(ui->decrease_point_label_8);
           wheat8->decrease_label_position(1670, 350);

           wheat8->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat8->Farmer_pushbutton_position(1710, 390);
           animation8 = new QPropertyAnimation(buttonAtPos2_wheat8, "geometry", this);
           animation8->setStartValue(QRect(1710, 390, buttonAtPos2_wheat8->geometry().width(), buttonAtPos2_wheat8->geometry().height()));
           animation8->setEndValue(QRect(1830, 390, buttonAtPos2_wheat8->geometry().width(), buttonAtPos2_wheat8->geometry().height()));
           animation8->setEasingCurve(QEasingCurve::Type::Linear);
           animation8->setDuration(900);
           wheat8->Set_Farmer_animation(animation8);

           wheat8->TurnTimerOn8();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley8->SetTimerLabel(ui->timer_label_8);
           barley8->Set_label_of_timers(ui->label_of_timer_8);
           barley8->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_8);
           barley8->Set_Cancel_Pushbutton(ui->Cancel_8);
           barley8->Set_Start_Pushbutton(ui->Start_8);
           barley8->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley8 = this->check2(Pos2);
           barley8->Set_Farmer_Pushbutton(buttonAtPos2_barley8);
           barley8->Set_decrease_label(ui->decrease_point_label_8);
           barley8->decrease_label_position(1670, 350);

           barley8->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley8->Farmer_pushbutton_position(1710, 390);
           animation8 = new QPropertyAnimation(buttonAtPos2_barley8, "geometry", this);
           animation8->setStartValue(QRect(1710, 390, buttonAtPos2_barley8->geometry().width(), buttonAtPos2_barley8->geometry().height()));
           animation8->setEndValue(QRect(1830, 390, buttonAtPos2_barley8->geometry().width(), buttonAtPos2_barley8->geometry().height()));
           animation8->setEasingCurve(QEasingCurve::Type::Linear);
           animation8->setDuration(900);
           barley8->Set_Farmer_animation(animation8);

           barley8->TurnTimerOn8();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch8->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep8->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow8->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat8->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley8->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_8_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_8->hide();
    ui->Start_8->show();

    ui->timer_label_8->hide();
    ui->label_of_timer_8->hide();

    QPoint Pos(1650, 410);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch8->Set_Farmer_Pushbutton(buttonAtPos2_ch8);
           ch8->Farmer_pushbutton_position(1710, 390);
           ch8->Set_Farmer_animation(animation8);

           ch8->Farmer_pushbutton_setenable8();
           ch8->Timer8_Stop();
           ch8->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep8->Set_Farmer_Pushbutton(buttonAtPos2_Sheep8);
           sheep8->Farmer_pushbutton_position(1710, 390);
           sheep8->Set_Farmer_animation(animation8);

           sheep8->Farmer_pushbutton_setenable8();
           sheep8->Timer8_Stop();
           sheep8->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow8->Set_Farmer_Pushbutton(buttonAtPos2_cow8);
           cow8->Farmer_pushbutton_position(1710, 390);
           cow8->Set_Farmer_animation(animation8);

           cow8->Farmer_pushbutton_setenable8();
           cow8->Timer8_Stop();
           cow8->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat8->Set_Farmer_Pushbutton(buttonAtPos2_wheat8);
           wheat8->Farmer_pushbutton_position(1710, 390);
           wheat8->Set_Farmer_animation(animation8);

           wheat8->Farmer_pushbutton_setenable8();
           wheat8->Timer8_Stop();
           wheat8->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley8->Set_Farmer_Pushbutton(buttonAtPos2_barley8);
           barley8->Farmer_pushbutton_position(1710, 390);
           barley8->Set_Farmer_animation(animation8);

           barley8->Farmer_pushbutton_setenable8();
           barley8->Timer8_Stop();
           barley8->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_8_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch8->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_8->hide();
        ch8->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_8->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_8_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep8->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_8->hide();
        sheep8->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_8->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_8_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (cow8->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_8->hide();
        cow8->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_8->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_8_clicked()
{
    if(number_of_Free_farmers >= 1){

        score = score + (wheat8->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_8->hide();
        wheat8->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_8->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_8_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley8->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_8->hide();
        barley8->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_8->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_9_clicked()
{

    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_9->hide();
    ui->Cancel_9->show();
    ui->timer_label_9->show();
    ui->label_of_timer_9->show();

    QPoint Pos(150, 640);

    QPoint Pos2(210, 620);

    ch9 = new Chicken(ui->verticalLayout);
    sheep9 = new Sheep(ui->verticalLayout);
    cow9 = new Cow(ui->verticalLayout);
    wheat9 = new Wheat(ui->verticalLayout);
    barley9 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch9->SetTimerLabel(ui->timer_label_9);
           ch9->Set_label_of_timers(ui->label_of_timer_9);
           ch9->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_9);
           ch9->Set_Cancel_Pushbutton(ui->Cancel_9);
           ch9->Set_Start_Pushbutton(ui->Start_9);
           ch9->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch9 = this->check2(Pos2);
           ch9->Set_Farmer_Pushbutton(buttonAtPos2_ch9);
           ch9->Set_decrease_label(ui->decrease_point_label_9);
           ch9->decrease_label_position(170, 580);

           ch9->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch9->Farmer_pushbutton_position(210, 620);
           animation9 = new QPropertyAnimation(buttonAtPos2_ch9, "geometry", this);
           animation9->setStartValue(QRect(210, 620, buttonAtPos2_ch9->geometry().width(), buttonAtPos2_ch9->geometry().height()));
           animation9->setEndValue(QRect(330, 620, buttonAtPos2_ch9->geometry().width(), buttonAtPos2_ch9->geometry().height()));
           animation9->setEasingCurve(QEasingCurve::Type::Linear);
           animation9->setDuration(900);
           ch9->Set_Farmer_animation(animation9);

           ch9->TurnTimerOn9();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep9->SetTimerLabel(ui->timer_label_9);
           sheep9->Set_label_of_timers(ui->label_of_timer_9);
           sheep9->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_9);
           sheep9->Set_Cancel_Pushbutton(ui->Cancel_9);
           sheep9->Set_Start_Pushbutton(ui->Start_9);
           sheep9->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep9 = this->check2(Pos2);
           sheep9->Set_Farmer_Pushbutton(buttonAtPos2_Sheep9);
           sheep9->Set_decrease_label(ui->decrease_point_label_9);
           sheep9->decrease_label_position(170, 580);

           sheep9->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep9->Farmer_pushbutton_position(210, 620);
           animation9 = new QPropertyAnimation(buttonAtPos2_Sheep9, "geometry", this);
           animation9->setStartValue(QRect(210, 620, buttonAtPos2_Sheep9->geometry().width(), buttonAtPos2_Sheep9->geometry().height()));
           animation9->setEndValue(QRect(330, 620, buttonAtPos2_Sheep9->geometry().width(), buttonAtPos2_Sheep9->geometry().height()));
           animation9->setEasingCurve(QEasingCurve::Type::Linear);
           animation9->setDuration(900);
           sheep9->Set_Farmer_animation(animation9);

           sheep9->TurnTimerOn9();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow9->SetTimerLabel(ui->timer_label_9);
           cow9->Set_label_of_timers(ui->label_of_timer_9);
           cow9->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_9);
           cow9->Set_Cancel_Pushbutton(ui->Cancel_9);
           cow9->Set_Start_Pushbutton(ui->Start_9);
           cow9->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow9 = this->check2(Pos2);
           cow9->Set_Farmer_Pushbutton(buttonAtPos2_cow9);
           cow9->Set_decrease_label(ui->decrease_point_label_9);
           cow9->decrease_label_position(170, 580);

           cow9->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow9->Farmer_pushbutton_position(210, 620);
           animation9 = new QPropertyAnimation(buttonAtPos2_cow9, "geometry", this);
           animation9->setStartValue(QRect(210, 620, buttonAtPos2_cow9->geometry().width(), buttonAtPos2_cow9->geometry().height()));
           animation9->setEndValue(QRect(330, 620, buttonAtPos2_cow9->geometry().width(), buttonAtPos2_cow9->geometry().height()));
           animation9->setEasingCurve(QEasingCurve::Type::Linear);
           animation9->setDuration(900);
           cow9->Set_Farmer_animation(animation9);

           cow9->TurnTimerOn9();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat9->SetTimerLabel(ui->timer_label_9);
           wheat9->Set_label_of_timers(ui->label_of_timer_9);
           wheat9->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_9);
           wheat9->Set_Cancel_Pushbutton(ui->Cancel_9);
           wheat9->Set_Start_Pushbutton(ui->Start_9);
           wheat9->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat9 = this->check2(Pos2);
           wheat9->Set_Farmer_Pushbutton(buttonAtPos2_wheat9);
           wheat9->Set_decrease_label(ui->decrease_point_label_9);
           wheat9->decrease_label_position(170, 580);

           wheat9->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat9->Farmer_pushbutton_position(210, 620);
           animation9 = new QPropertyAnimation(buttonAtPos2_wheat9, "geometry", this);
           animation9->setStartValue(QRect(210, 620, buttonAtPos2_wheat9->geometry().width(), buttonAtPos2_wheat9->geometry().height()));
           animation9->setEndValue(QRect(330, 620, buttonAtPos2_wheat9->geometry().width(), buttonAtPos2_wheat9->geometry().height()));
           animation9->setEasingCurve(QEasingCurve::Type::Linear);
           animation9->setDuration(900);
           wheat9->Set_Farmer_animation(animation9);

           wheat9->TurnTimerOn9();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley9->SetTimerLabel(ui->timer_label_9);
           barley9->Set_label_of_timers(ui->label_of_timer_9);
           barley9->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_9);
           barley9->Set_Cancel_Pushbutton(ui->Cancel_9);
           barley9->Set_Start_Pushbutton(ui->Start_9);
           barley9->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley9 = this->check2(Pos2);
           barley9->Set_Farmer_Pushbutton(buttonAtPos2_barley9);
           barley9->Set_decrease_label(ui->decrease_point_label_9);
           barley9->decrease_label_position(170, 580);

           barley9->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley9->Farmer_pushbutton_position(210, 620);
           animation9 = new QPropertyAnimation(buttonAtPos2_barley9, "geometry", this);
           animation9->setStartValue(QRect(210, 620, buttonAtPos2_barley9->geometry().width(), buttonAtPos2_barley9->geometry().height()));
           animation9->setEndValue(QRect(330, 620, buttonAtPos2_barley9->geometry().width(), buttonAtPos2_barley9->geometry().height()));
           animation9->setEasingCurve(QEasingCurve::Type::Linear);
           animation9->setDuration(900);
           barley9->Set_Farmer_animation(animation9);

           barley9->TurnTimerOn9();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch9->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep9->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow9->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat9->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley9->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_9_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_9->hide();
    ui->Start_9->show();

    ui->timer_label_9->hide();
    ui->label_of_timer_9->hide();

    QPoint Pos(150, 640);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch9->Set_Farmer_Pushbutton(buttonAtPos2_ch9);
           ch9->Farmer_pushbutton_position(210, 620);
           ch9->Set_Farmer_animation(animation9);

           ch9->Farmer_pushbutton_setenable9();
           ch9->Timer9_Stop();
           ch9->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep9->Set_Farmer_Pushbutton(buttonAtPos2_Sheep9);
           sheep9->Farmer_pushbutton_position(210, 620);
           sheep9->Set_Farmer_animation(animation9);

           sheep9->Farmer_pushbutton_setenable9();
           sheep9->Timer9_Stop();
           sheep9->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow9->Set_Farmer_Pushbutton(buttonAtPos2_cow9);
           cow9->Farmer_pushbutton_position(210, 620);
           cow9->Set_Farmer_animation(animation9);

           cow9->Farmer_pushbutton_setenable9();
           cow9->Timer9_Stop();
           cow9->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat9->Set_Farmer_Pushbutton(buttonAtPos2_wheat9);
           wheat9->Farmer_pushbutton_position(210, 620);
           wheat9->Set_Farmer_animation(animation9);

           wheat9->Farmer_pushbutton_setenable9();
           wheat9->Timer9_Stop();
           wheat9->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley9->Set_Farmer_Pushbutton(buttonAtPos2_barley9);
           barley9->Farmer_pushbutton_position(210, 620);
           barley9->Set_Farmer_animation(animation9);

           barley9->Farmer_pushbutton_setenable9();
           barley9->Timer9_Stop();
           barley9->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_9_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch9->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_9->hide();
        ch9->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_9->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_9_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (sheep9->Product_Collection_Point);
        ui->label_Score->setText( "Score :" + QString::number(score));
        ui->the_product_of_sheep_pushButton_9->hide();
        sheep9->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_9->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_9_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (cow9->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_9->hide();
        cow9->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_9->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_9_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (wheat9->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_9->hide();
        wheat9->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_9->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_9_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley9->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_9->hide();
        barley9->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_9->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_10_clicked()
{

    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_10->hide();
    ui->Cancel_10->show();
    ui->timer_label_10->show();
    ui->label_of_timer_10->show();

    QPoint Pos(540, 640);

    QPoint Pos2(600, 620);

    ch10 = new Chicken(ui->verticalLayout);
    sheep10 = new Sheep(ui->verticalLayout);
    cow10 = new Cow(ui->verticalLayout);
    wheat10 = new Wheat(ui->verticalLayout);
    barley10 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch10->SetTimerLabel(ui->timer_label_10);
           ch10->Set_label_of_timers(ui->label_of_timer_10);
           ch10->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_10);
           ch10->Set_Cancel_Pushbutton(ui->Cancel_10);
           ch10->Set_Start_Pushbutton(ui->Start_10);
           ch10->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch10 = this->check2(Pos2);
           ch10->Set_Farmer_Pushbutton(buttonAtPos2_ch10);
           ch10->Set_decrease_label(ui->decrease_point_label_10);
           ch10->decrease_label_position(560, 580);

           ch10->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch10->Farmer_pushbutton_position(600, 620);
           animation10 = new QPropertyAnimation(buttonAtPos2_ch10, "geometry", this);
           animation10->setStartValue(QRect(600, 620, buttonAtPos2_ch10->geometry().width(), buttonAtPos2_ch10->geometry().height()));
           animation10->setEndValue(QRect(720, 620, buttonAtPos2_ch10->geometry().width(), buttonAtPos2_ch10->geometry().height()));
           animation10->setEasingCurve(QEasingCurve::Type::Linear);
           animation10->setDuration(900);
           ch10->Set_Farmer_animation(animation10);

           ch10->TurnTimerOn10();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep10->SetTimerLabel(ui->timer_label_10);
           sheep10->Set_label_of_timers(ui->label_of_timer_10);
           sheep10->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_10);
           sheep10->Set_Cancel_Pushbutton(ui->Cancel_10);
           sheep10->Set_Start_Pushbutton(ui->Start_10);
           sheep10->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep10 = this->check2(Pos2);
           sheep10->Set_Farmer_Pushbutton(buttonAtPos2_Sheep10);
           sheep10->Set_decrease_label(ui->decrease_point_label_10);
           sheep10->decrease_label_position(560, 580);

           sheep10->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep10->Farmer_pushbutton_position(600, 620);
           animation10 = new QPropertyAnimation(buttonAtPos2_Sheep10, "geometry", this);
           animation10->setStartValue(QRect(600, 620, buttonAtPos2_Sheep10->geometry().width(), buttonAtPos2_Sheep10->geometry().height()));
           animation10->setEndValue(QRect(720, 620, buttonAtPos2_Sheep10->geometry().width(), buttonAtPos2_Sheep10->geometry().height()));
           animation10->setEasingCurve(QEasingCurve::Type::Linear);
           animation10->setDuration(900);
           sheep10->Set_Farmer_animation(animation10);

           sheep10->TurnTimerOn10();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow10->SetTimerLabel(ui->timer_label_10);
           cow10->Set_label_of_timers(ui->label_of_timer_10);
           cow10->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_10);
           cow10->Set_Cancel_Pushbutton(ui->Cancel_10);
           cow10->Set_Start_Pushbutton(ui->Start_10);
           cow10->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow10 = this->check2(Pos2);
           cow10->Set_Farmer_Pushbutton(buttonAtPos2_cow10);
           cow10->Set_decrease_label(ui->decrease_point_label_10);
           cow10->decrease_label_position(560, 580);

           cow10->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow10->Farmer_pushbutton_position(600, 620);
           animation10 = new QPropertyAnimation(buttonAtPos2_cow10, "geometry", this);
           animation10->setStartValue(QRect(600, 620, buttonAtPos2_cow10->geometry().width(), buttonAtPos2_cow10->geometry().height()));
           animation10->setEndValue(QRect(720, 620, buttonAtPos2_cow10->geometry().width(), buttonAtPos2_cow10->geometry().height()));
           animation10->setEasingCurve(QEasingCurve::Type::Linear);
           animation10->setDuration(900);
           cow10->Set_Farmer_animation(animation10);

           cow10->TurnTimerOn10();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat10->SetTimerLabel(ui->timer_label_10);
           wheat10->Set_label_of_timers(ui->label_of_timer_10);
           wheat10->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_10);
           wheat10->Set_Cancel_Pushbutton(ui->Cancel_10);
           wheat10->Set_Start_Pushbutton(ui->Start_10);
           wheat10->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat10 = this->check2(Pos2);
           wheat10->Set_Farmer_Pushbutton(buttonAtPos2_wheat10);
           wheat10->Set_decrease_label(ui->decrease_point_label_10);
           wheat10->decrease_label_position(560, 580);

           wheat10->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat10->Farmer_pushbutton_position(600, 620);
           animation10 = new QPropertyAnimation(buttonAtPos2_wheat10, "geometry", this);
           animation10->setStartValue(QRect(600, 620, buttonAtPos2_wheat10->geometry().width(), buttonAtPos2_wheat10->geometry().height()));
           animation10->setEndValue(QRect(720, 620, buttonAtPos2_wheat10->geometry().width(), buttonAtPos2_wheat10->geometry().height()));
           animation10->setEasingCurve(QEasingCurve::Type::Linear);
           animation10->setDuration(900);
           wheat10->Set_Farmer_animation(animation10);

           wheat10->TurnTimerOn10();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley10->SetTimerLabel(ui->timer_label_10);
           barley10->Set_label_of_timers(ui->label_of_timer_10);
           barley10->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_10);
           barley10->Set_Cancel_Pushbutton(ui->Cancel_10);
           barley10->Set_Start_Pushbutton(ui->Start_10);
           barley10->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley10 = this->check2(Pos2);
           barley10->Set_Farmer_Pushbutton(buttonAtPos2_barley10);
           barley10->Set_decrease_label(ui->decrease_point_label_10);
           barley10->decrease_label_position(560, 580);

           barley10->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley10->Farmer_pushbutton_position(600, 620);
           animation10 = new QPropertyAnimation(buttonAtPos2_barley10, "geometry", this);
           animation10->setStartValue(QRect(600, 620, buttonAtPos2_barley10->geometry().width(), buttonAtPos2_barley10->geometry().height()));
           animation10->setEndValue(QRect(720, 620, buttonAtPos2_barley10->geometry().width(), buttonAtPos2_barley10->geometry().height()));
           animation10->setEasingCurve(QEasingCurve::Type::Linear);
           animation10->setDuration(900);
           barley10->Set_Farmer_animation(animation10);

           barley10->TurnTimerOn10();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch10->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep10->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow10->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat10->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley10->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_10_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_10->hide();
    ui->Start_10->show();

    ui->timer_label_10->hide();
    ui->label_of_timer_10->hide();

    QPoint Pos(540, 640);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch10->Set_Farmer_Pushbutton(buttonAtPos2_ch10);
           ch10->Farmer_pushbutton_position(600, 620);
           ch10->Set_Farmer_animation(animation10);

           ch10->Farmer_pushbutton_setenable10();
           ch10->Timer10_Stop();
           ch10->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep10->Set_Farmer_Pushbutton(buttonAtPos2_Sheep10);
           sheep10->Farmer_pushbutton_position(600, 620);
           sheep10->Set_Farmer_animation(animation10);

           sheep10->Farmer_pushbutton_setenable10();
           sheep10->Timer10_Stop();
           sheep10->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow10->Set_Farmer_Pushbutton(buttonAtPos2_cow10);
           cow10->Farmer_pushbutton_position(600, 620);
           cow10->Set_Farmer_animation(animation10);

           cow10->Farmer_pushbutton_setenable10();
           cow10->Timer10_Stop();
           cow10->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat10->Set_Farmer_Pushbutton(buttonAtPos2_wheat10);
           wheat10->Farmer_pushbutton_position(600, 620);
           wheat10->Set_Farmer_animation(animation10);

           wheat10->Farmer_pushbutton_setenable10();
           wheat10->Timer10_Stop();
           wheat10->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley10->Set_Farmer_Pushbutton(buttonAtPos2_barley10);
           barley10->Farmer_pushbutton_position(600, 620);
           barley10->Set_Farmer_animation(animation10);

           barley10->Farmer_pushbutton_setenable10();
           barley10->Timer10_Stop();
           barley10->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_10_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (ch10->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_10->hide();
        ch10->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_10->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_10_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep10->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_10->hide();
        sheep10->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_10->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_10_clicked()
{  
    if(number_of_Free_farmers >= 1){

        score = score + (cow10->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_10->hide();
        cow10->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_10->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_10_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (wheat10->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_10->hide();
        wheat10->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_10->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_10_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley10->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_10->hide();
        barley10->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_10->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_11_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_11->hide();
    ui->Cancel_11->show();
    ui->timer_label_11->show();
    ui->label_of_timer_11->show();

    QPoint Pos(1260, 640);

    QPoint Pos2(1320, 620);

    ch11 = new Chicken(ui->verticalLayout);
    sheep11 = new Sheep(ui->verticalLayout);
    cow11 = new Cow(ui->verticalLayout);
    wheat11 = new Wheat(ui->verticalLayout);
    barley11 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch11->SetTimerLabel(ui->timer_label_11);
           ch11->Set_label_of_timers(ui->label_of_timer_11);
           ch11->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_11);
           ch11->Set_Cancel_Pushbutton(ui->Cancel_11);
           ch11->Set_Start_Pushbutton(ui->Start_11);
           ch11->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch11 = this->check2(Pos2);
           ch11->Set_Farmer_Pushbutton(buttonAtPos2_ch11);
           ch11->Set_decrease_label(ui->decrease_point_label_11);
           ch11->decrease_label_position(1280, 580);

           ch11->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch11->Farmer_pushbutton_position(1320, 620);
           animation11 = new QPropertyAnimation(buttonAtPos2_ch11, "geometry", this);
           animation11->setStartValue(QRect(1320, 620, buttonAtPos2_ch11->geometry().width(), buttonAtPos2_ch11->geometry().height()));
           animation11->setEndValue(QRect(1440, 620, buttonAtPos2_ch11->geometry().width(), buttonAtPos2_ch11->geometry().height()));
           animation11->setEasingCurve(QEasingCurve::Type::Linear);
           animation11->setDuration(900);
           ch11->Set_Farmer_animation(animation11);

           ch11->TurnTimerOn11();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep11->SetTimerLabel(ui->timer_label_11);
           sheep11->Set_label_of_timers(ui->label_of_timer_11);
           sheep11->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_11);
           sheep11->Set_Cancel_Pushbutton(ui->Cancel_11);
           sheep11->Set_Start_Pushbutton(ui->Start_11);
           sheep11->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep11 = this->check2(Pos2);
           sheep11->Set_Farmer_Pushbutton(buttonAtPos2_Sheep11);
           sheep11->Set_decrease_label(ui->decrease_point_label_11);
           sheep11->decrease_label_position(1280, 580);

           sheep11->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep11->Farmer_pushbutton_position(1320, 620);
           animation11 = new QPropertyAnimation(buttonAtPos2_Sheep11, "geometry", this);
           animation11->setStartValue(QRect(1320, 620, buttonAtPos2_Sheep11->geometry().width(), buttonAtPos2_Sheep11->geometry().height()));
           animation11->setEndValue(QRect(1440, 620, buttonAtPos2_Sheep11->geometry().width(), buttonAtPos2_Sheep11->geometry().height()));
           animation11->setEasingCurve(QEasingCurve::Type::Linear);
           animation11->setDuration(900);
           sheep11->Set_Farmer_animation(animation11);

           sheep11->TurnTimerOn11();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow11->SetTimerLabel(ui->timer_label_11);
           cow11->Set_label_of_timers(ui->label_of_timer_11);
           cow11->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_11);
           cow11->Set_Cancel_Pushbutton(ui->Cancel_11);
           cow11->Set_Start_Pushbutton(ui->Start_11);
           cow11->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow11 = this->check2(Pos2);
           cow11->Set_Farmer_Pushbutton(buttonAtPos2_cow11);
           cow11->Set_decrease_label(ui->decrease_point_label_11);
           cow11->decrease_label_position(1280, 580);

           cow11->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow11->Farmer_pushbutton_position(1320, 620);
           animation11 = new QPropertyAnimation(buttonAtPos2_cow11, "geometry", this);
           animation11->setStartValue(QRect(1320, 620, buttonAtPos2_cow11->geometry().width(), buttonAtPos2_cow11->geometry().height()));
           animation11->setEndValue(QRect(1440, 620, buttonAtPos2_cow11->geometry().width(), buttonAtPos2_cow11->geometry().height()));
           animation11->setEasingCurve(QEasingCurve::Type::Linear);
           animation11->setDuration(900);
           cow11->Set_Farmer_animation(animation11);

           cow11->TurnTimerOn11();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat11->SetTimerLabel(ui->timer_label_11);
           wheat11->Set_label_of_timers(ui->label_of_timer_11);
           wheat11->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_11);
           wheat11->Set_Cancel_Pushbutton(ui->Cancel_11);
           wheat11->Set_Start_Pushbutton(ui->Start_11);
           wheat11->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat11 = this->check2(Pos2);
           wheat11->Set_Farmer_Pushbutton(buttonAtPos2_wheat11);
           wheat11->Set_decrease_label(ui->decrease_point_label_11);
           wheat11->decrease_label_position(1280, 580);

           wheat11->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat11->Farmer_pushbutton_position(1320, 620);
           animation11 = new QPropertyAnimation(buttonAtPos2_wheat11, "geometry", this);
           animation11->setStartValue(QRect(1320, 620, buttonAtPos2_wheat11->geometry().width(), buttonAtPos2_wheat11->geometry().height()));
           animation11->setEndValue(QRect(1440, 620, buttonAtPos2_wheat11->geometry().width(), buttonAtPos2_wheat11->geometry().height()));
           animation11->setEasingCurve(QEasingCurve::Type::Linear);
           animation11->setDuration(900);
           wheat11->Set_Farmer_animation(animation11);

           wheat11->TurnTimerOn11();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley11->SetTimerLabel(ui->timer_label_11);
           barley11->Set_label_of_timers(ui->label_of_timer_11);
           barley11->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_11);
           barley11->Set_Cancel_Pushbutton(ui->Cancel_11);
           barley11->Set_Start_Pushbutton(ui->Start_11);
           barley11->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley11 = this->check2(Pos2);
           barley11->Set_Farmer_Pushbutton(buttonAtPos2_barley11);
           barley11->Set_decrease_label(ui->decrease_point_label_11);
           barley11->decrease_label_position(1280, 580);

           barley11->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley11->Farmer_pushbutton_position(1320, 620);
           animation11 = new QPropertyAnimation(buttonAtPos2_barley11, "geometry", this);
           animation11->setStartValue(QRect(1320, 620, buttonAtPos2_barley11->geometry().width(), buttonAtPos2_barley11->geometry().height()));
           animation11->setEndValue(QRect(1440, 620, buttonAtPos2_barley11->geometry().width(), buttonAtPos2_barley11->geometry().height()));
           animation11->setEasingCurve(QEasingCurve::Type::Linear);
           animation11->setDuration(900);
           barley11->Set_Farmer_animation(animation11);

           barley11->TurnTimerOn11();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch11->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep11->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow11->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat11->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley11->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_11_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_11->hide();
    ui->Start_11->show();

    ui->timer_label_11->hide();
    ui->label_of_timer_11->hide();

    QPoint Pos(1260, 640);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch11->Set_Farmer_Pushbutton(buttonAtPos2_ch11);
           ch11->Farmer_pushbutton_position(1320, 620);
           ch11->Set_Farmer_animation(animation11);

           ch11->Farmer_pushbutton_setenable11();
           ch11->Timer11_Stop();
           ch11->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep11->Set_Farmer_Pushbutton(buttonAtPos2_Sheep11);
           sheep11->Farmer_pushbutton_position(1320, 620);
           sheep11->Set_Farmer_animation(animation11);

           sheep11->Farmer_pushbutton_setenable11();
           sheep11->Timer11_Stop();
           sheep11->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow11->Set_Farmer_Pushbutton(buttonAtPos2_cow11);
           cow11->Farmer_pushbutton_position(1320, 620);
           cow11->Set_Farmer_animation(animation11);

           cow11->Farmer_pushbutton_setenable11();
           cow11->Timer11_Stop();
           cow11->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat11->Set_Farmer_Pushbutton(buttonAtPos2_wheat11);
           wheat11->Farmer_pushbutton_position(1320, 620);
           wheat11->Set_Farmer_animation(animation11);

           wheat11->Farmer_pushbutton_setenable11();
           wheat11->Timer11_Stop();
           wheat11->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley11->Set_Farmer_Pushbutton(buttonAtPos2_barley11);
           barley11->Farmer_pushbutton_position(1320, 620);
           barley11->Set_Farmer_animation(animation11);

           barley11->Farmer_pushbutton_setenable11();
           barley11->Timer11_Stop();
           barley11->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_11_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (ch11->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_11->hide();
        ch11->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_11->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_11_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (sheep11->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_11->hide();
        sheep11->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_11->hide();

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_11_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (cow11->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_11->hide();
        cow11->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_11->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_11_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (wheat11->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_11->hide();
        wheat11->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_11->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_11_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley11->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_11->hide();
        barley11->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_11->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_12_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_12->hide();
    ui->Cancel_12->show();
    ui->timer_label_12->show();
    ui->label_of_timer_12->show();

    QPoint Pos(1650, 640);

    QPoint Pos2(1710, 620);

    ch12 = new Chicken(ui->verticalLayout);
    sheep12 = new Sheep(ui->verticalLayout);
    cow12 = new Cow(ui->verticalLayout);
    wheat12 = new Wheat(ui->verticalLayout);
    barley12 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch12->SetTimerLabel(ui->timer_label_12);
           ch12->Set_label_of_timers(ui->label_of_timer_12);
           ch12->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_12);
           ch12->Set_Cancel_Pushbutton(ui->Cancel_12);
           ch12->Set_Start_Pushbutton(ui->Start_12);
           ch12->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch12 = this->check2(Pos2);
           ch12->Set_Farmer_Pushbutton(buttonAtPos2_ch12);
           ch12->Set_decrease_label(ui->decrease_point_label_12);
           ch12->decrease_label_position(1670, 580);

           ch12->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch12->Farmer_pushbutton_position(1710, 620);
           animation12 = new QPropertyAnimation(buttonAtPos2_ch12, "geometry", this);
           animation12->setStartValue(QRect(1710, 620, buttonAtPos2_ch12->geometry().width(), buttonAtPos2_ch12->geometry().height()));
           animation12->setEndValue(QRect(1830, 620, buttonAtPos2_ch12->geometry().width(), buttonAtPos2_ch12->geometry().height()));
           animation12->setEasingCurve(QEasingCurve::Type::Linear);
           animation12->setDuration(900);
           ch12->Set_Farmer_animation(animation12);

           ch12->TurnTimerOn12();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep12->SetTimerLabel(ui->timer_label_12);
           sheep12->Set_label_of_timers(ui->label_of_timer_12);
           sheep12->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_12);
           sheep12->Set_Cancel_Pushbutton(ui->Cancel_12);
           sheep12->Set_Start_Pushbutton(ui->Start_12);
           sheep12->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep12 = this->check2(Pos2);
           sheep12->Set_Farmer_Pushbutton(buttonAtPos2_Sheep12);
           sheep12->Set_decrease_label(ui->decrease_point_label_12);
           sheep12->decrease_label_position(1670, 580);

           sheep12->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep12->Farmer_pushbutton_position(1710, 620);
           animation12 = new QPropertyAnimation(buttonAtPos2_Sheep12, "geometry", this);
           animation12->setStartValue(QRect(1710, 620, buttonAtPos2_Sheep12->geometry().width(), buttonAtPos2_Sheep12->geometry().height()));
           animation12->setEndValue(QRect(1830, 620, buttonAtPos2_Sheep12->geometry().width(), buttonAtPos2_Sheep12->geometry().height()));
           animation12->setEasingCurve(QEasingCurve::Type::Linear);
           animation12->setDuration(900);
           sheep12->Set_Farmer_animation(animation12);

           sheep12->TurnTimerOn12();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow12->SetTimerLabel(ui->timer_label_12);
           cow12->Set_label_of_timers(ui->label_of_timer_12);
           cow12->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_12);
           cow12->Set_Cancel_Pushbutton(ui->Cancel_12);
           cow12->Set_Start_Pushbutton(ui->Start_12);
           cow12->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow12 = this->check2(Pos2);
           cow12->Set_Farmer_Pushbutton(buttonAtPos2_cow12);
           cow12->Set_decrease_label(ui->decrease_point_label_12);
           cow12->decrease_label_position(1670, 580);

           cow12->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow12->Farmer_pushbutton_position(1710, 620);
           animation12 = new QPropertyAnimation(buttonAtPos2_cow12, "geometry", this);
           animation12->setStartValue(QRect(1710, 620, buttonAtPos2_cow12->geometry().width(), buttonAtPos2_cow12->geometry().height()));
           animation12->setEndValue(QRect(1830, 620, buttonAtPos2_cow12->geometry().width(), buttonAtPos2_cow12->geometry().height()));
           animation12->setEasingCurve(QEasingCurve::Type::Linear);
           animation12->setDuration(900);
           cow12->Set_Farmer_animation(animation12);

           cow12->TurnTimerOn12();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat12->SetTimerLabel(ui->timer_label_12);
           wheat12->Set_label_of_timers(ui->label_of_timer_12);
           wheat12->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_12);
           wheat12->Set_Cancel_Pushbutton(ui->Cancel_12);
           wheat12->Set_Start_Pushbutton(ui->Start_12);
           wheat12->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat12 = this->check2(Pos2);
           wheat12->Set_Farmer_Pushbutton(buttonAtPos2_wheat12);
           wheat12->Set_decrease_label(ui->decrease_point_label_12);
           wheat12->decrease_label_position(1670, 580);

           wheat12->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat12->Farmer_pushbutton_position(1710, 620);
           animation12 = new QPropertyAnimation(buttonAtPos2_wheat12, "geometry", this);
           animation12->setStartValue(QRect(1710, 620, buttonAtPos2_wheat12->geometry().width(), buttonAtPos2_wheat12->geometry().height()));
           animation12->setEndValue(QRect(1830, 620, buttonAtPos2_wheat12->geometry().width(), buttonAtPos2_wheat12->geometry().height()));
           animation12->setEasingCurve(QEasingCurve::Type::Linear);
           animation12->setDuration(900);
           wheat12->Set_Farmer_animation(animation12);

           wheat12->TurnTimerOn12();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley12->SetTimerLabel(ui->timer_label_12);
           barley12->Set_label_of_timers(ui->label_of_timer_12);
           barley12->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_12);
           barley12->Set_Cancel_Pushbutton(ui->Cancel_12);
           barley12->Set_Start_Pushbutton(ui->Start_12);
           barley12->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley12 = this->check2(Pos2);
           barley12->Set_Farmer_Pushbutton(buttonAtPos2_barley12);
           barley12->Set_decrease_label(ui->decrease_point_label_12);
           barley12->decrease_label_position(1670, 580);

           barley12->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley12->Farmer_pushbutton_position(1710, 620);
           animation12 = new QPropertyAnimation(buttonAtPos2_barley12, "geometry", this);
           animation12->setStartValue(QRect(1710, 620, buttonAtPos2_barley12->geometry().width(), buttonAtPos2_barley12->geometry().height()));
           animation12->setEndValue(QRect(1830, 620, buttonAtPos2_barley12->geometry().width(), buttonAtPos2_barley12->geometry().height()));
           animation12->setEasingCurve(QEasingCurve::Type::Linear);
           animation12->setDuration(900);
           barley12->Set_Farmer_animation(animation12);

           barley12->TurnTimerOn12();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch12->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep12->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow12->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat12->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley12->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_12_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_12->hide();
    ui->Start_12->show();

    ui->timer_label_12->hide();
    ui->label_of_timer_12->hide();

    QPoint Pos(1650, 640);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch12->Set_Farmer_Pushbutton(buttonAtPos2_ch12);
           ch12->Farmer_pushbutton_position(1710, 620);
           ch12->Set_Farmer_animation(animation12);

           ch12->Farmer_pushbutton_setenable12();
           ch12->Timer12_Stop();
           ch12->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep12->Set_Farmer_Pushbutton(buttonAtPos2_Sheep12);
           sheep12->Farmer_pushbutton_position(1710, 620);
           sheep12->Set_Farmer_animation(animation12);

           sheep12->Farmer_pushbutton_setenable12();
           sheep12->Timer12_Stop();
           sheep12->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow12->Set_Farmer_Pushbutton(buttonAtPos2_cow12);
           cow12->Farmer_pushbutton_position(1710, 620);
           cow12->Set_Farmer_animation(animation12);

           cow12->Farmer_pushbutton_setenable12();
           cow12->Timer12_Stop();
           cow12->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat12->Set_Farmer_Pushbutton(buttonAtPos2_wheat12);
           wheat12->Farmer_pushbutton_position(1710, 620);
           wheat12->Set_Farmer_animation(animation12);

           wheat12->Farmer_pushbutton_setenable12();
           wheat12->Timer12_Stop();
           wheat12->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley12->Set_Farmer_Pushbutton(buttonAtPos2_barley12);
           barley12->Farmer_pushbutton_position(1710, 620);
           barley12->Set_Farmer_animation(animation12);

           barley12->Farmer_pushbutton_setenable12();
           barley12->Timer12_Stop();
           barley12->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_12_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch12->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_12->hide();
        ch12->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_12->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_12_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (sheep12->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_12->hide();
        sheep12->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_12->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_12_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (cow12->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_12->hide();
        cow12->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_12->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_12_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (wheat12->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_12->hide();
        wheat12->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_12->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_12_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (barley12->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_12->hide();
        barley12->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_12->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_13_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_13->hide();
    ui->Cancel_13->show();
    ui->timer_label_13->show();
    ui->label_of_timer_13->show();

    QPoint Pos(150, 870);

    QPoint Pos2(210, 850);

    ch13 = new Chicken(ui->verticalLayout);
    sheep13 = new Sheep(ui->verticalLayout);
    cow13 = new Cow(ui->verticalLayout);
    wheat13 = new Wheat(ui->verticalLayout);
    barley13 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch13->SetTimerLabel(ui->timer_label_13);
           ch13->Set_label_of_timers(ui->label_of_timer_13);
           ch13->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_13);
           ch13->Set_Cancel_Pushbutton(ui->Cancel_13);
           ch13->Set_Start_Pushbutton(ui->Start_13);
           ch13->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch13 = this->check2(Pos2);
           ch13->Set_Farmer_Pushbutton(buttonAtPos2_ch13);
           ch13->Set_decrease_label(ui->decrease_point_label_13);
           ch13->decrease_label_position(170, 810);

           ch13->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch13->Farmer_pushbutton_position(210, 850);
           animation13 = new QPropertyAnimation(buttonAtPos2_ch13, "geometry", this);
           animation13->setStartValue(QRect(210, 850, buttonAtPos2_ch13->geometry().width(), buttonAtPos2_ch13->geometry().height()));
           animation13->setEndValue(QRect(330, 850, buttonAtPos2_ch13->geometry().width(), buttonAtPos2_ch13->geometry().height()));
           animation13->setEasingCurve(QEasingCurve::Type::Linear);
           animation13->setDuration(900);
           ch13->Set_Farmer_animation(animation13);

           ch13->TurnTimerOn13();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep13->SetTimerLabel(ui->timer_label_13);
           sheep13->Set_label_of_timers(ui->label_of_timer_13);
           sheep13->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_13);
           sheep13->Set_Cancel_Pushbutton(ui->Cancel_13);
           sheep13->Set_Start_Pushbutton(ui->Start_13);
           sheep13->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep13 = this->check2(Pos2);
           sheep13->Set_Farmer_Pushbutton(buttonAtPos2_Sheep13);
           sheep13->Set_decrease_label(ui->decrease_point_label_13);
           sheep13->decrease_label_position(170, 810);

           sheep13->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep13->Farmer_pushbutton_position(210, 850);
           animation13 = new QPropertyAnimation(buttonAtPos2_Sheep13, "geometry", this);
           animation13->setStartValue(QRect(210, 850, buttonAtPos2_Sheep13->geometry().width(), buttonAtPos2_Sheep13->geometry().height()));
           animation13->setEndValue(QRect(330, 850, buttonAtPos2_Sheep13->geometry().width(), buttonAtPos2_Sheep13->geometry().height()));
           animation13->setEasingCurve(QEasingCurve::Type::Linear);
           animation13->setDuration(900);
           sheep13->Set_Farmer_animation(animation13);

           sheep13->TurnTimerOn13();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow13->SetTimerLabel(ui->timer_label_13);
           cow13->Set_label_of_timers(ui->label_of_timer_13);
           cow13->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_13);
           cow13->Set_Cancel_Pushbutton(ui->Cancel_13);
           cow13->Set_Start_Pushbutton(ui->Start_13);
           cow13->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow13 = this->check2(Pos2);
           cow13->Set_Farmer_Pushbutton(buttonAtPos2_cow13);
           cow13->Set_decrease_label(ui->decrease_point_label_13);
           cow13->decrease_label_position(170, 810);

           cow13->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow13->Farmer_pushbutton_position(210, 850);
           animation13 = new QPropertyAnimation(buttonAtPos2_cow13, "geometry", this);
           animation13->setStartValue(QRect(210, 850, buttonAtPos2_cow13->geometry().width(), buttonAtPos2_cow13->geometry().height()));
           animation13->setEndValue(QRect(330, 850, buttonAtPos2_cow13->geometry().width(), buttonAtPos2_cow13->geometry().height()));
           animation13->setEasingCurve(QEasingCurve::Type::Linear);
           animation13->setDuration(900);
           cow13->Set_Farmer_animation(animation13);

           cow13->TurnTimerOn13();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat13->SetTimerLabel(ui->timer_label_13);
           wheat13->Set_label_of_timers(ui->label_of_timer_13);
           wheat13->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_13);
           wheat13->Set_Cancel_Pushbutton(ui->Cancel_13);
           wheat13->Set_Start_Pushbutton(ui->Start_13);
           wheat13->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat13 = this->check2(Pos2);
           wheat13->Set_Farmer_Pushbutton(buttonAtPos2_wheat13);
           wheat13->Set_decrease_label(ui->decrease_point_label_13);
           wheat13->decrease_label_position(170, 810);

           wheat13->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat13->Farmer_pushbutton_position(210, 850);
           animation13 = new QPropertyAnimation(buttonAtPos2_wheat13, "geometry", this);
           animation13->setStartValue(QRect(210, 850, buttonAtPos2_wheat13->geometry().width(), buttonAtPos2_wheat13->geometry().height()));
           animation13->setEndValue(QRect(330, 850, buttonAtPos2_wheat13->geometry().width(), buttonAtPos2_wheat13->geometry().height()));
           animation13->setEasingCurve(QEasingCurve::Type::Linear);
           animation13->setDuration(900);
           wheat13->Set_Farmer_animation(animation13);

           wheat13->TurnTimerOn13();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley13->SetTimerLabel(ui->timer_label_13);
           barley13->Set_label_of_timers(ui->label_of_timer_13);
           barley13->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_13);
           barley13->Set_Cancel_Pushbutton(ui->Cancel_13);
           barley13->Set_Start_Pushbutton(ui->Start_13);
           barley13->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley13 = this->check2(Pos2);
           barley13->Set_Farmer_Pushbutton(buttonAtPos2_barley13);
           barley13->Set_decrease_label(ui->decrease_point_label_13);
           barley13->decrease_label_position(170, 810);

           barley13->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley13->Farmer_pushbutton_position(210, 850);
           animation13 = new QPropertyAnimation(buttonAtPos2_barley13, "geometry", this);
           animation13->setStartValue(QRect(210, 850, buttonAtPos2_barley13->geometry().width(), buttonAtPos2_barley13->geometry().height()));
           animation13->setEndValue(QRect(330, 850, buttonAtPos2_barley13->geometry().width(), buttonAtPos2_barley13->geometry().height()));
           animation13->setEasingCurve(QEasingCurve::Type::Linear);
           animation13->setDuration(900);
           barley13->Set_Farmer_animation(animation13);

           barley13->TurnTimerOn13();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch13->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep13->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow13->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat13->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley13->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_13_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_13->hide();
    ui->Start_13->show();

    ui->timer_label_13->hide();
    ui->label_of_timer_13->hide();

    QPoint Pos(150, 870);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch13->Set_Farmer_Pushbutton(buttonAtPos2_ch13);
           ch13->Farmer_pushbutton_position(210, 850);
           ch13->Set_Farmer_animation(animation13);

           ch13->Farmer_pushbutton_setenable13();
           ch13->Timer13_Stop();
           ch13->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep13->Set_Farmer_Pushbutton(buttonAtPos2_Sheep13);
           sheep13->Farmer_pushbutton_position(210, 850);
           sheep13->Set_Farmer_animation(animation13);

           sheep13->Farmer_pushbutton_setenable13();
           sheep13->Timer13_Stop();
           sheep13->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow13->Set_Farmer_Pushbutton(buttonAtPos2_cow13);
           cow13->Farmer_pushbutton_position(210, 850);
           cow13->Set_Farmer_animation(animation13);

           cow13->Farmer_pushbutton_setenable13();
           cow13->Timer13_Stop();
           cow13->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat13->Set_Farmer_Pushbutton(buttonAtPos2_wheat13);
           wheat13->Farmer_pushbutton_position(210, 850);
           wheat13->Set_Farmer_animation(animation13);

           wheat13->Farmer_pushbutton_setenable13();
           wheat13->Timer13_Stop();
           wheat13->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley13->Set_Farmer_Pushbutton(buttonAtPos2_barley13);
           barley13->Farmer_pushbutton_position(210, 850);
           barley13->Set_Farmer_animation(animation13);

           barley13->Farmer_pushbutton_setenable13();
           barley13->Timer13_Stop();
           barley13->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_13_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch13->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_13->hide();
        ch13->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_13->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_13_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (sheep13->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_13->hide();
        sheep13->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_13->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_13_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (cow13->Product_Collection_Point);
        ui->label_Score->setText( "Score :" + QString::number(score));
        ui->the_product_of_cow_pushButton_13->hide();
        cow13->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_13->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_13_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (wheat13->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_13->hide();
        wheat13->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_13->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_13_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (barley13->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_13->hide();
        barley13->TimerDelay_Stop();
        Get_info();

        QPoint Pos(150, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_13->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_14_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_14->hide();
    ui->Cancel_14->show();
    ui->timer_label_14->show();
    ui->label_of_timer_14->show();

    QPoint Pos(540, 870);

    QPoint Pos2(600, 850);

    ch14 = new Chicken(ui->verticalLayout);
    sheep14 = new Sheep(ui->verticalLayout);
    cow14 = new Cow(ui->verticalLayout);
    wheat14 = new Wheat(ui->verticalLayout);
    barley14 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch14->SetTimerLabel(ui->timer_label_14);
           ch14->Set_label_of_timers(ui->label_of_timer_14);
           ch14->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_14);
           ch14->Set_Cancel_Pushbutton(ui->Cancel_14);
           ch14->Set_Start_Pushbutton(ui->Start_14);
           ch14->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch14 = this->check2(Pos2);
           ch14->Set_Farmer_Pushbutton(buttonAtPos2_ch14);
           ch14->Set_decrease_label(ui->decrease_point_label_14);
           ch14->decrease_label_position(560, 810);

           ch14->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch14->Farmer_pushbutton_position(600, 850);
           animation14 = new QPropertyAnimation(buttonAtPos2_ch14, "geometry", this);
           animation14->setStartValue(QRect(600, 850, buttonAtPos2_ch14->geometry().width(), buttonAtPos2_ch14->geometry().height()));
           animation14->setEndValue(QRect(720, 850, buttonAtPos2_ch14->geometry().width(), buttonAtPos2_ch14->geometry().height()));
           animation14->setEasingCurve(QEasingCurve::Type::Linear);
           animation14->setDuration(900);
           ch14->Set_Farmer_animation(animation14);

           ch14->TurnTimerOn14();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep14->SetTimerLabel(ui->timer_label_14);
           sheep14->Set_label_of_timers(ui->label_of_timer_14);
           sheep14->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_14);
           sheep14->Set_Cancel_Pushbutton(ui->Cancel_14);
           sheep14->Set_Start_Pushbutton(ui->Start_14);
           sheep14->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep14 = this->check2(Pos2);
           sheep14->Set_Farmer_Pushbutton(buttonAtPos2_Sheep14);
           sheep14->Set_decrease_label(ui->decrease_point_label_14);
           sheep14->decrease_label_position(560, 810);

           sheep14->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep14->Farmer_pushbutton_position(600, 850);
           animation14 = new QPropertyAnimation(buttonAtPos2_Sheep14, "geometry", this);
           animation14->setStartValue(QRect(600, 850, buttonAtPos2_Sheep14->geometry().width(), buttonAtPos2_Sheep14->geometry().height()));
           animation14->setEndValue(QRect(720, 850, buttonAtPos2_Sheep14->geometry().width(), buttonAtPos2_Sheep14->geometry().height()));
           animation14->setEasingCurve(QEasingCurve::Type::Linear);
           animation14->setDuration(900);
           sheep14->Set_Farmer_animation(animation14);

           sheep14->TurnTimerOn14();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow14->SetTimerLabel(ui->timer_label_14);
           cow14->Set_label_of_timers(ui->label_of_timer_14);
           cow14->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_14);
           cow14->Set_Cancel_Pushbutton(ui->Cancel_14);
           cow14->Set_Start_Pushbutton(ui->Start_14);
           cow14->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow14 = this->check2(Pos2);
           cow14->Set_Farmer_Pushbutton(buttonAtPos2_cow14);
           cow14->Set_decrease_label(ui->decrease_point_label_14);
           cow14->decrease_label_position(560, 810);

           cow14->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow14->Farmer_pushbutton_position(600, 850);
           animation14 = new QPropertyAnimation(buttonAtPos2_cow14, "geometry", this);
           animation14->setStartValue(QRect(600, 850, buttonAtPos2_cow14->geometry().width(), buttonAtPos2_cow14->geometry().height()));
           animation14->setEndValue(QRect(720, 850, buttonAtPos2_cow14->geometry().width(), buttonAtPos2_cow14->geometry().height()));
           animation14->setEasingCurve(QEasingCurve::Type::Linear);
           animation14->setDuration(900);
           cow14->Set_Farmer_animation(animation14);

           cow14->TurnTimerOn14();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat14->SetTimerLabel(ui->timer_label_14);
           wheat14->Set_label_of_timers(ui->label_of_timer_14);
           wheat14->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_14);
           wheat14->Set_Cancel_Pushbutton(ui->Cancel_14);
           wheat14->Set_Start_Pushbutton(ui->Start_14);
           wheat14->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat14 = this->check2(Pos2);
           wheat14->Set_Farmer_Pushbutton(buttonAtPos2_wheat14);
           wheat14->Set_decrease_label(ui->decrease_point_label_14);
           wheat14->decrease_label_position(560, 810);

           wheat14->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat14->Farmer_pushbutton_position(600, 850);
           animation14 = new QPropertyAnimation(buttonAtPos2_wheat14, "geometry", this);
           animation14->setStartValue(QRect(600, 850, buttonAtPos2_wheat14->geometry().width(), buttonAtPos2_wheat14->geometry().height()));
           animation14->setEndValue(QRect(720, 850, buttonAtPos2_wheat14->geometry().width(), buttonAtPos2_wheat14->geometry().height()));
           animation14->setEasingCurve(QEasingCurve::Type::Linear);
           animation14->setDuration(900);
           wheat14->Set_Farmer_animation(animation14);

           wheat14->TurnTimerOn14();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley14->SetTimerLabel(ui->timer_label_14);
           barley14->Set_label_of_timers(ui->label_of_timer_14);
           barley14->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_14);
           barley14->Set_Cancel_Pushbutton(ui->Cancel_14);
           barley14->Set_Start_Pushbutton(ui->Start_14);
           barley14->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley14 = this->check2(Pos2);
           barley14->Set_Farmer_Pushbutton(buttonAtPos2_barley14);
           barley14->Set_decrease_label(ui->decrease_point_label_14);
           barley14->decrease_label_position(560, 810);

           barley14->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley14->Farmer_pushbutton_position(600, 850);
           animation14 = new QPropertyAnimation(buttonAtPos2_barley14, "geometry", this);
           animation14->setStartValue(QRect(600, 850, buttonAtPos2_barley14->geometry().width(), buttonAtPos2_barley14->geometry().height()));
           animation14->setEndValue(QRect(720, 850, buttonAtPos2_barley14->geometry().width(), buttonAtPos2_barley14->geometry().height()));
           animation14->setEasingCurve(QEasingCurve::Type::Linear);
           animation14->setDuration(900);
           barley14->Set_Farmer_animation(animation14);

           barley14->TurnTimerOn14();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch14->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep14->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow14->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat14->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley14->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_14_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_14->hide();
    ui->Start_14->show();

    ui->timer_label_14->hide();
    ui->label_of_timer_14->hide();

    QPoint Pos(540, 870);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch14->Set_Farmer_Pushbutton(buttonAtPos2_ch14);
           ch14->Farmer_pushbutton_position(600, 850);
           ch14->Set_Farmer_animation(animation14);

           ch14->Farmer_pushbutton_setenable14();
           ch14->Timer14_Stop();
           ch14->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep14->Set_Farmer_Pushbutton(buttonAtPos2_Sheep14);
           sheep14->Farmer_pushbutton_position(600, 850);
           sheep14->Set_Farmer_animation(animation14);

           sheep14->Farmer_pushbutton_setenable14();
           sheep14->Timer14_Stop();
           sheep14->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow14->Set_Farmer_Pushbutton(buttonAtPos2_cow14);
           cow14->Farmer_pushbutton_position(210, 850);
           cow14->Set_Farmer_animation(animation14);

           cow14->Farmer_pushbutton_setenable14();
           cow14->Timer14_Stop();
           cow14->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat14->Set_Farmer_Pushbutton(buttonAtPos2_wheat14);
           wheat14->Farmer_pushbutton_position(600, 850);
           wheat14->Set_Farmer_animation(animation14);

           wheat14->Farmer_pushbutton_setenable14();
           wheat14->Timer14_Stop();
           wheat14->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley14->Set_Farmer_Pushbutton(buttonAtPos2_barley14);
           barley14->Farmer_pushbutton_position(600, 850);
           barley14->Set_Farmer_animation(animation14);

           barley14->Farmer_pushbutton_setenable14();
           barley14->Timer14_Stop();
           barley14->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_14_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch14->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_14->hide();
        ch14->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_14->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_14_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (sheep14->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_14->hide();
        sheep14->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_14->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_14_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (cow14->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_14->hide();
        cow14->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_14->hide();

    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_14_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (wheat14->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_14->hide();
        wheat14->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_14->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_14_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley14->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_14->hide();
        barley14->TimerDelay_Stop();
        Get_info();

        QPoint Pos(540, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_14->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_15_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_15->hide();
    ui->Cancel_15->show();
    ui->timer_label_15->show();
    ui->label_of_timer_15->show();

    QPoint Pos(1260, 870);

    QPoint Pos2(1320, 850);

    ch15 = new Chicken(ui->verticalLayout);
    sheep15 = new Sheep(ui->verticalLayout);
    cow15 = new Cow(ui->verticalLayout);
    wheat15 = new Wheat(ui->verticalLayout);
    barley15 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch15->SetTimerLabel(ui->timer_label_15);
           ch15->Set_label_of_timers(ui->label_of_timer_15);
           ch15->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_15);
           ch15->Set_Cancel_Pushbutton(ui->Cancel_15);
           ch15->Set_Start_Pushbutton(ui->Start_15);
           ch15->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch15 = this->check2(Pos2);
           ch15->Set_Farmer_Pushbutton(buttonAtPos2_ch15);
           ch15->Set_decrease_label(ui->decrease_point_label_15);
           ch15->decrease_label_position(1280, 810);

           ch15->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch15->Farmer_pushbutton_position(1320, 850);
           animation15 = new QPropertyAnimation(buttonAtPos2_ch15, "geometry", this);
           animation15->setStartValue(QRect(1320, 850, buttonAtPos2_ch15->geometry().width(), buttonAtPos2_ch15->geometry().height()));
           animation15->setEndValue(QRect(1440, 850, buttonAtPos2_ch15->geometry().width(), buttonAtPos2_ch15->geometry().height()));
           animation15->setEasingCurve(QEasingCurve::Type::Linear);
           animation15->setDuration(900);
           ch15->Set_Farmer_animation(animation15);

           ch15->TurnTimerOn15();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep15->SetTimerLabel(ui->timer_label_15);
           sheep15->Set_label_of_timers(ui->label_of_timer_15);
           sheep15->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_15);
           sheep15->Set_Cancel_Pushbutton(ui->Cancel_15);
           sheep15->Set_Start_Pushbutton(ui->Start_15);
           sheep15->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep15 = this->check2(Pos2);
           sheep15->Set_Farmer_Pushbutton(buttonAtPos2_Sheep15);
           sheep15->Set_decrease_label(ui->decrease_point_label_15);
           sheep15->decrease_label_position(1280, 810);

           sheep15->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep15->Farmer_pushbutton_position(1320, 850);
           animation15 = new QPropertyAnimation(buttonAtPos2_Sheep15, "geometry", this);
           animation15->setStartValue(QRect(1320, 850, buttonAtPos2_Sheep15->geometry().width(), buttonAtPos2_Sheep15->geometry().height()));
           animation15->setEndValue(QRect(1440, 850, buttonAtPos2_Sheep15->geometry().width(), buttonAtPos2_Sheep15->geometry().height()));
           animation15->setEasingCurve(QEasingCurve::Type::Linear);
           animation15->setDuration(900);
           sheep15->Set_Farmer_animation(animation15);

           sheep15->TurnTimerOn15();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow15->SetTimerLabel(ui->timer_label_15);
           cow15->Set_label_of_timers(ui->label_of_timer_15);
           cow15->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_15);
           cow15->Set_Cancel_Pushbutton(ui->Cancel_15);
           cow15->Set_Start_Pushbutton(ui->Start_15);
           cow15->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow15 = this->check2(Pos2);
           cow15->Set_Farmer_Pushbutton(buttonAtPos2_cow15);
           cow15->Set_decrease_label(ui->decrease_point_label_15);
           cow15->decrease_label_position(1280, 810);

           cow15->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow15->Farmer_pushbutton_position(1320, 850);
           animation15 = new QPropertyAnimation(buttonAtPos2_cow15, "geometry", this);
           animation15->setStartValue(QRect(1320, 850, buttonAtPos2_cow15->geometry().width(), buttonAtPos2_cow15->geometry().height()));
           animation15->setEndValue(QRect(1440, 850, buttonAtPos2_cow15->geometry().width(), buttonAtPos2_cow15->geometry().height()));
           animation15->setEasingCurve(QEasingCurve::Type::Linear);
           animation15->setDuration(900);
           cow15->Set_Farmer_animation(animation15);

           cow15->TurnTimerOn15();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat15->SetTimerLabel(ui->timer_label_15);
           wheat15->Set_label_of_timers(ui->label_of_timer_15);
           wheat15->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_15);
           wheat15->Set_Cancel_Pushbutton(ui->Cancel_15);
           wheat15->Set_Start_Pushbutton(ui->Start_15);
           wheat15->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat15 = this->check2(Pos2);
           wheat15->Set_Farmer_Pushbutton(buttonAtPos2_wheat15);
           wheat15->Set_decrease_label(ui->decrease_point_label_15);
           wheat15->decrease_label_position(1280, 810);

           wheat15->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat15->Farmer_pushbutton_position(1320, 850);
           animation15 = new QPropertyAnimation(buttonAtPos2_wheat15, "geometry", this);
           animation15->setStartValue(QRect(1320, 850, buttonAtPos2_wheat15->geometry().width(), buttonAtPos2_wheat15->geometry().height()));
           animation15->setEndValue(QRect(1440, 850, buttonAtPos2_wheat15->geometry().width(), buttonAtPos2_wheat15->geometry().height()));
           animation15->setEasingCurve(QEasingCurve::Type::Linear);
           animation15->setDuration(900);
           wheat15->Set_Farmer_animation(animation15);

           wheat15->TurnTimerOn15();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley15->SetTimerLabel(ui->timer_label_15);
           barley15->Set_label_of_timers(ui->label_of_timer_15);
           barley15->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_15);
           barley15->Set_Cancel_Pushbutton(ui->Cancel_15);
           barley15->Set_Start_Pushbutton(ui->Start_15);
           barley15->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley15 = this->check2(Pos2);
           barley15->Set_Farmer_Pushbutton(buttonAtPos2_barley15);
           barley15->Set_decrease_label(ui->decrease_point_label_15);
           barley15->decrease_label_position(1280, 810);

           barley15->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley15->Farmer_pushbutton_position(1320, 850);
           animation15 = new QPropertyAnimation(buttonAtPos2_barley15, "geometry", this);
           animation15->setStartValue(QRect(1320, 850, buttonAtPos2_barley15->geometry().width(), buttonAtPos2_barley15->geometry().height()));
           animation15->setEndValue(QRect(1440, 850, buttonAtPos2_barley15->geometry().width(), buttonAtPos2_barley15->geometry().height()));
           animation15->setEasingCurve(QEasingCurve::Type::Linear);
           animation15->setDuration(900);
           barley15->Set_Farmer_animation(animation15);

           barley15->TurnTimerOn15();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch15->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep15->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow15->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat15->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley15->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_15_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_15->hide();
    ui->Start_15->show();

    ui->timer_label_15->hide();
    ui->label_of_timer_15->hide();

    QPoint Pos(1260, 870);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch15->Set_Farmer_Pushbutton(buttonAtPos2_ch15);
           ch15->Farmer_pushbutton_position(1320, 850);
           ch15->Set_Farmer_animation(animation15);

           ch15->Farmer_pushbutton_setenable15();
           ch15->Timer15_Stop();
           ch15->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep15->Set_Farmer_Pushbutton(buttonAtPos2_Sheep15);
           sheep15->Farmer_pushbutton_position(1320, 850);
           sheep15->Set_Farmer_animation(animation15);

           sheep15->Farmer_pushbutton_setenable15();
           sheep15->Timer15_Stop();
           sheep15->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow15->Set_Farmer_Pushbutton(buttonAtPos2_cow15);
           cow15->Farmer_pushbutton_position(1320, 850);
           cow15->Set_Farmer_animation(animation15);

           cow15->Farmer_pushbutton_setenable15();
           cow15->Timer15_Stop();
           cow15->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat15->Set_Farmer_Pushbutton(buttonAtPos2_wheat15);
           wheat15->Farmer_pushbutton_position(1320, 850);
           wheat15->Set_Farmer_animation(animation15);

           wheat15->Farmer_pushbutton_setenable15();
           wheat15->Timer15_Stop();
           wheat15->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley15->Set_Farmer_Pushbutton(buttonAtPos2_barley15);
           barley15->Farmer_pushbutton_position(1320, 850);
           barley15->Set_Farmer_animation(animation15);

           barley15->Farmer_pushbutton_setenable15();
           barley15->Timer15_Stop();
           barley15->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_15_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch15->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_15->hide();
        ch15->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_15->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_15_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep15->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_15->hide();
        sheep15->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_15->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_15_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (cow15->Product_Collection_Point);
        ui->label_Score->setText( "Score :" + QString::number(score));
        ui->the_product_of_cow_pushButton_15->hide();
        cow15->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_15->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_15_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (wheat15->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_15->hide();
        wheat15->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_15->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_15_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley15->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_15->hide();
        barley15->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1260, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_15->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_Start_16_clicked()
{
    number_of_Free_farmers--;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->Start_16->hide();
    ui->Cancel_16->show();
    ui->timer_label_16->show();
    ui->label_of_timer_16->show();

    QPoint Pos(1650, 870);

    QPoint Pos2(1710, 850);

    ch16 = new Chicken(ui->verticalLayout);
    sheep16 = new Sheep(ui->verticalLayout);
    cow16 = new Cow(ui->verticalLayout);
    wheat16 = new Wheat(ui->verticalLayout);
    barley16 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch16->SetTimerLabel(ui->timer_label_16);
           ch16->Set_label_of_timers(ui->label_of_timer_16);
           ch16->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton_16);
           ch16->Set_Cancel_Pushbutton(ui->Cancel_16);
           ch16->Set_Start_Pushbutton(ui->Start_16);
           ch16->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_ch16 = this->check2(Pos2);
           ch16->Set_Farmer_Pushbutton(buttonAtPos2_ch16);
           ch16->Set_decrease_label(ui->decrease_point_label_16);
           ch16->decrease_label_position(1670, 810);

           ch16->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           ch16->Farmer_pushbutton_position(1710, 850);
           animation16 = new QPropertyAnimation(buttonAtPos2_ch16, "geometry", this);
           animation16->setStartValue(QRect(1710, 850, buttonAtPos2_ch16->geometry().width(), buttonAtPos2_ch16->geometry().height()));
           animation16->setEndValue(QRect(1830, 850, buttonAtPos2_ch16->geometry().width(), buttonAtPos2_ch16->geometry().height()));
           animation16->setEasingCurve(QEasingCurve::Type::Linear);
           animation16->setDuration(900);
           ch16->Set_Farmer_animation(animation16);

           ch16->TurnTimerOn16();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep16->SetTimerLabel(ui->timer_label_16);
           sheep16->Set_label_of_timers(ui->label_of_timer_16);
           sheep16->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton_16);
           sheep16->Set_Cancel_Pushbutton(ui->Cancel_16);
           sheep16->Set_Start_Pushbutton(ui->Start_16);
           sheep16->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_Sheep16 = this->check2(Pos2);
           sheep16->Set_Farmer_Pushbutton(buttonAtPos2_Sheep16);
           sheep16->Set_decrease_label(ui->decrease_point_label_16);
           sheep16->decrease_label_position(1670, 810);

           sheep16->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           sheep16->Farmer_pushbutton_position(1710, 850);
           animation16 = new QPropertyAnimation(buttonAtPos2_Sheep16, "geometry", this);
           animation16->setStartValue(QRect(1710, 850, buttonAtPos2_Sheep16->geometry().width(), buttonAtPos2_Sheep16->geometry().height()));
           animation16->setEndValue(QRect(1830, 850, buttonAtPos2_Sheep16->geometry().width(), buttonAtPos2_Sheep16->geometry().height()));
           animation16->setEasingCurve(QEasingCurve::Type::Linear);
           animation16->setDuration(900);
           sheep16->Set_Farmer_animation(animation16);

           sheep16->TurnTimerOn16();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow16->SetTimerLabel(ui->timer_label_16);
           cow16->Set_label_of_timers(ui->label_of_timer_16);
           cow16->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton_16);
           cow16->Set_Cancel_Pushbutton(ui->Cancel_16);
           cow16->Set_Start_Pushbutton(ui->Start_16);
           cow16->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_cow16 = this->check2(Pos2);
           cow16->Set_Farmer_Pushbutton(buttonAtPos2_cow16);
           cow16->Set_decrease_label(ui->decrease_point_label_16);
           cow16->decrease_label_position(1670, 810);

           cow16->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           cow16->Farmer_pushbutton_position(1710, 850);
           animation16 = new QPropertyAnimation(buttonAtPos2_cow16, "geometry", this);
           animation16->setStartValue(QRect(1710, 850, buttonAtPos2_cow16->geometry().width(), buttonAtPos2_cow16->geometry().height()));
           animation16->setEndValue(QRect(1830, 850, buttonAtPos2_cow16->geometry().width(), buttonAtPos2_cow16->geometry().height()));
           animation16->setEasingCurve(QEasingCurve::Type::Linear);
           animation16->setDuration(900);
           cow16->Set_Farmer_animation(animation16);

           cow16->TurnTimerOn16();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat16->SetTimerLabel(ui->timer_label_16);
           wheat16->Set_label_of_timers(ui->label_of_timer_16);
           wheat16->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton_16);
           wheat16->Set_Cancel_Pushbutton(ui->Cancel_16);
           wheat16->Set_Start_Pushbutton(ui->Start_16);
           wheat16->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_wheat16 = this->check2(Pos2);
           wheat16->Set_Farmer_Pushbutton(buttonAtPos2_wheat16);
           wheat16->Set_decrease_label(ui->decrease_point_label_16);
           wheat16->decrease_label_position(1670, 810);

           wheat16->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           wheat16->Farmer_pushbutton_position(1710, 850);
           animation16 = new QPropertyAnimation(buttonAtPos2_wheat16, "geometry", this);
           animation16->setStartValue(QRect(1710, 850, buttonAtPos2_wheat16->geometry().width(), buttonAtPos2_wheat16->geometry().height()));
           animation16->setEndValue(QRect(1830, 850, buttonAtPos2_wheat16->geometry().width(), buttonAtPos2_wheat16->geometry().height()));
           animation16->setEasingCurve(QEasingCurve::Type::Linear);
           animation16->setDuration(900);
           wheat16->Set_Farmer_animation(animation16);

           wheat16->TurnTimerOn16();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley16->SetTimerLabel(ui->timer_label_16);
           barley16->Set_label_of_timers(ui->label_of_timer_16);
           barley16->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton_16);
           barley16->Set_Cancel_Pushbutton(ui->Cancel_16);
           barley16->Set_Start_Pushbutton(ui->Start_16);
           barley16->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           buttonAtPos2_barley16 = this->check2(Pos2);
           barley16->Set_Farmer_Pushbutton(buttonAtPos2_barley16);
           barley16->Set_decrease_label(ui->decrease_point_label_16);
           barley16->decrease_label_position(1670, 810);

           barley16->Set_Farmer_status_Label(ui->number_of_Farmers_label);

           barley16->Farmer_pushbutton_position(1710, 850);
           animation16 = new QPropertyAnimation(buttonAtPos2_barley16, "geometry", this);
           animation16->setStartValue(QRect(1710, 850, buttonAtPos2_barley16->geometry().width(), buttonAtPos2_barley16->geometry().height()));
           animation16->setEndValue(QRect(1830, 850, buttonAtPos2_barley16->geometry().width(), buttonAtPos2_barley16->geometry().height()));
           animation16->setEasingCurve(QEasingCurve::Type::Linear);
           animation16->setDuration(900);
           barley16->Set_Farmer_animation(animation16);

           barley16->TurnTimerOn16();
           buttonAtPos->setEnabled(false);

       }
    }

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos2_ch16->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Sheep"){

           buttonAtPos2_Sheep16->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Cow"){

           buttonAtPos2_cow16->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Wheat"){

           buttonAtPos2_wheat16->setEnabled(false);

       }else if (buttonAtPos->objectName() == "Barley"){

           buttonAtPos2_barley16->setEnabled(false);
       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_Cancel_16_clicked()
{
    number_of_Free_farmers++;

    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    Get_info();

    ui->Cancel_16->hide();
    ui->Start_16->show();

    ui->timer_label_16->hide();
    ui->label_of_timer_16->hide();

    QPoint Pos(1650, 870);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch16->Set_Farmer_Pushbutton(buttonAtPos2_ch16);
           ch16->Farmer_pushbutton_position(1710, 850);
           ch16->Set_Farmer_animation(animation16);

           ch16->Farmer_pushbutton_setenable16();
           ch16->Timer16_Stop();
           ch16->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep16->Set_Farmer_Pushbutton(buttonAtPos2_Sheep16);
           sheep16->Farmer_pushbutton_position(1710, 850);
           sheep16->Set_Farmer_animation(animation16);

           sheep16->Farmer_pushbutton_setenable16();
           sheep16->Timer16_Stop();
           sheep16->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow16->Set_Farmer_Pushbutton(buttonAtPos2_cow16);
           cow16->Farmer_pushbutton_position(1710, 850);
           cow16->Set_Farmer_animation(animation16);

           cow16->Farmer_pushbutton_setenable16();
           cow16->Timer16_Stop();
           cow16->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat16->Set_Farmer_Pushbutton(buttonAtPos2_wheat16);
           wheat16->Farmer_pushbutton_position(1710, 850);
           wheat16->Set_Farmer_animation(animation16);

           wheat16->Farmer_pushbutton_setenable16();
           wheat16->Timer16_Stop();
           wheat16->TimerDelay_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley16->Set_Farmer_Pushbutton(buttonAtPos2_barley16);
           barley16->Farmer_pushbutton_position(1710, 850);
           barley16->Set_Farmer_animation(animation16);

           barley16->Farmer_pushbutton_setenable16();
           barley16->Timer16_Stop();
           barley16->TimerDelay_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_16_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (ch16->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_chicken_pushButton_16->hide();
        ch16->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_16->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_sheep_pushButton_16_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (sheep16->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_sheep_pushButton_16->hide();
        sheep16->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_16->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_cow_pushButton_16_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (cow16->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_cow_pushButton_16->hide();
        cow16->TimerDelay_Stop();
        Get_info();
        ui->decrease_point_label_16->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_wheat_pushButton_16_clicked()
{    
    if(number_of_Free_farmers >= 1){

        score = score + (wheat16->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_wheat_pushButton_16->hide();
        wheat16->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

            if (buttonAtPos->objectName() == "Wheat") {

                delete  buttonAtPos;

                Get_info();
            }
        }
        ui->decrease_point_label_16->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::on_the_product_of_barley_pushButton_16_clicked()
{   
    if(number_of_Free_farmers >= 1){

        score = score + (barley16->Product_Collection_Point);
        ui->label_Score->setText( "Score : " + QString::number(score));
        ui->the_product_of_barley_pushButton_16->hide();
        barley16->TimerDelay_Stop();
        Get_info();

        QPoint Pos(1650, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

             if (buttonAtPos->objectName() == "Barley") {

                delete  buttonAtPos;

                 Get_info();
             }
        }
        ui->decrease_point_label_16->hide();
    }else{

        QMessageBox::warning(this, "sdsad", "no free farmer to collect");
    }
    Get_info();
}

void Gamepage::Set_window_to_the_default()
{
    if(ui->Cancel->isVisible()){

        QPoint Pos(150, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch1->Set_Farmer_Pushbutton(buttonAtPos2_ch1);
               ch1->Farmer_pushbutton_position(210, 160);
               ch1->Set_Farmer_animation(animation1);

               ch1->Farmer_pushbutton_setenable();
               ch1->Timer_Stop();
               ch1->TimerDelay_Stop();
               delete buttonAtPos2_ch1;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep1->Set_Farmer_Pushbutton(buttonAtPos2_Sheep1);
               sheep1->Farmer_pushbutton_position(210, 160);
               sheep1->Set_Farmer_animation(animation1);

               sheep1->Farmer_pushbutton_setenable();
               sheep1->Timer_Stop();
               sheep1->TimerDelay_Stop();
               delete buttonAtPos2_Sheep1;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow1->Set_Farmer_Pushbutton(buttonAtPos2_cow1);
               cow1->Farmer_pushbutton_position(210, 160);
               cow1->Set_Farmer_animation(animation1);

               cow1->Farmer_pushbutton_setenable();
               cow1->Timer_Stop();
               cow1->TimerDelay_Stop();
               delete buttonAtPos2_cow1;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat1->Set_Farmer_Pushbutton(buttonAtPos2_wheat1);
               wheat1->Farmer_pushbutton_position(210, 160);
               wheat1->Set_Farmer_animation(animation1);

               wheat1->Farmer_pushbutton_setenable();
               wheat1->Timer_Stop();
               wheat1->TimerDelay_Stop();
               delete buttonAtPos2_wheat1;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley1->Set_Farmer_Pushbutton(buttonAtPos2_barley1);
               barley1->Farmer_pushbutton_position(210, 160);
               barley1->Set_Farmer_animation(animation1);

               barley1->Farmer_pushbutton_setenable();
               barley1->Timer_Stop();
               barley1->TimerDelay_Stop();
               delete buttonAtPos2_barley1;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton->isVisible()){

        ch1->TimerDelay_Stop();
        delete buttonAtPos2_ch1;
    }
    if(ui->the_product_of_sheep_pushButton->isVisible()){

        sheep1->TimerDelay_Stop();
        delete buttonAtPos2_Sheep1;
    }
    if(ui->the_product_of_cow_pushButton->isVisible()){

        cow1->TimerDelay_Stop();
        delete buttonAtPos2_cow1;
    }
    if(ui->the_product_of_wheat_pushButton->isVisible()){

        wheat1->TimerDelay_Stop();
        delete buttonAtPos2_wheat1;
    }
    if(ui->the_product_of_barley_pushButton->isVisible()){

        barley1->TimerDelay_Stop();
        delete buttonAtPos2_barley1;
    }

    if(ui->Cancel_2->isVisible()){

        QPoint Pos(540, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch2->Set_Farmer_Pushbutton(buttonAtPos2_ch2);
               ch2->Farmer_pushbutton_position(600, 160);
               ch2->Set_Farmer_animation(animation2);

               ch2->Farmer_pushbutton_setenable2();
               ch2->Timer2_Stop();
               ch2->TimerDelay_Stop();
               delete buttonAtPos2_ch2;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep2->Set_Farmer_Pushbutton(buttonAtPos2_Sheep2);
               sheep2->Farmer_pushbutton_position(600, 160);
               sheep2->Set_Farmer_animation(animation2);

               sheep2->Farmer_pushbutton_setenable2();
               sheep2->Timer2_Stop();
               sheep2->TimerDelay_Stop();
               delete buttonAtPos2_Sheep2;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow2->Set_Farmer_Pushbutton(buttonAtPos2_cow2);
               cow2->Farmer_pushbutton_position(600, 160);
               cow2->Set_Farmer_animation(animation2);

               cow2->Farmer_pushbutton_setenable2();
               cow2->Timer2_Stop();
               cow2->TimerDelay_Stop();
               delete buttonAtPos2_cow2;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat2->Set_Farmer_Pushbutton(buttonAtPos2_wheat2);
               wheat2->Farmer_pushbutton_position(600, 160);
               wheat2->Set_Farmer_animation(animation2);

               wheat2->Farmer_pushbutton_setenable2();
               wheat2->Timer2_Stop();
               wheat2->TimerDelay_Stop();
               delete buttonAtPos2_wheat2;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley2->Set_Farmer_Pushbutton(buttonAtPos2_barley2);
               barley2->Farmer_pushbutton_position(600, 160);
               barley2->Set_Farmer_animation(animation2);

               barley2->Farmer_pushbutton_setenable2();
               barley2->Timer2_Stop();
               barley2->TimerDelay_Stop();
               delete buttonAtPos2_barley2;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_2->isVisible()){

        ch2->TimerDelay_Stop();
        delete buttonAtPos2_ch2;
    }
    if(ui->the_product_of_sheep_pushButton_2->isVisible()){

        sheep2->TimerDelay_Stop();
        delete buttonAtPos2_Sheep2;
    }
    if(ui->the_product_of_cow_pushButton_2->isVisible()){

        cow2->TimerDelay_Stop();
        delete buttonAtPos2_cow2;
    }
    if(ui->the_product_of_wheat_pushButton_2->isVisible()){

        wheat2->TimerDelay_Stop();
        delete buttonAtPos2_wheat2;
    }
    if(ui->the_product_of_barley_pushButton_2->isVisible()){

        barley2->TimerDelay_Stop();
        delete buttonAtPos2_barley2;
    }

    if(ui->Cancel_3->isVisible()){

        QPoint Pos(1260, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch3->Set_Farmer_Pushbutton(buttonAtPos2_ch3);
               ch3->Farmer_pushbutton_position(1320, 160);
               ch3->Set_Farmer_animation(animation3);

               ch3->Farmer_pushbutton_setenable3();
               ch3->Timer3_Stop();
               ch3->TimerDelay_Stop();
               delete buttonAtPos2_ch3;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep3->Set_Farmer_Pushbutton(buttonAtPos2_Sheep3);
               sheep3->Farmer_pushbutton_position(1320, 160);
               sheep3->Set_Farmer_animation(animation3);

               sheep3->Farmer_pushbutton_setenable3();
               sheep3->Timer3_Stop();
               sheep3->TimerDelay_Stop();
               delete buttonAtPos2_Sheep3;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow3->Set_Farmer_Pushbutton(buttonAtPos2_cow3);
               cow3->Farmer_pushbutton_position(1320, 160);
               cow3->Set_Farmer_animation(animation3);

               cow3->Farmer_pushbutton_setenable3();
               cow3->Timer3_Stop();
               cow3->TimerDelay_Stop();
               delete buttonAtPos2_cow3;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat3->Set_Farmer_Pushbutton(buttonAtPos2_wheat3);
               wheat3->Farmer_pushbutton_position(1320, 160);
               wheat3->Set_Farmer_animation(animation3);

               wheat3->Farmer_pushbutton_setenable3();
               wheat3->Timer3_Stop();
               wheat3->TimerDelay_Stop();
               delete buttonAtPos2_wheat3;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley3->Set_Farmer_Pushbutton(buttonAtPos2_barley3);
               barley3->Farmer_pushbutton_position(1320, 160);
               barley3->Set_Farmer_animation(animation3);

               barley3->Farmer_pushbutton_setenable3();
               barley3->Timer3_Stop();
               barley3->TimerDelay_Stop();
               delete buttonAtPos2_barley3;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_3->isVisible()){

        ch3->TimerDelay_Stop();
        delete buttonAtPos2_ch3;
    }
    if(ui->the_product_of_sheep_pushButton_3->isVisible()){

        sheep3->TimerDelay_Stop();
        delete buttonAtPos2_Sheep3;
    }
    if(ui->the_product_of_cow_pushButton_3->isVisible()){

        cow3->TimerDelay_Stop();
        delete buttonAtPos2_cow3;
    }
    if(ui->the_product_of_wheat_pushButton_3->isVisible()){

        wheat3->TimerDelay_Stop();
        delete buttonAtPos2_wheat3;
    }
    if(ui->the_product_of_barley_pushButton_3->isVisible()){

        barley3->TimerDelay_Stop();
        delete buttonAtPos2_barley3;
    }

    if(ui->Cancel_4->isVisible()){

        QPoint Pos(1650, 180);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch4->Set_Farmer_Pushbutton(buttonAtPos2_ch4);
               ch4->Farmer_pushbutton_position(1710, 160);
               ch4->Set_Farmer_animation(animation4);

               ch4->Farmer_pushbutton_setenable4();
               ch4->Timer4_Stop();
               ch4->TimerDelay_Stop();
               delete buttonAtPos2_ch4;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep4->Set_Farmer_Pushbutton(buttonAtPos2_Sheep4);
               sheep4->Farmer_pushbutton_position(1710, 160);
               sheep4->Set_Farmer_animation(animation4);

               sheep4->Farmer_pushbutton_setenable4();
               sheep4->Timer4_Stop();
               sheep4->TimerDelay_Stop();
               delete buttonAtPos2_Sheep4;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow4->Set_Farmer_Pushbutton(buttonAtPos2_cow4);
               cow4->Farmer_pushbutton_position(1710, 160);
               cow4->Set_Farmer_animation(animation4);

               cow4->Farmer_pushbutton_setenable4();
               cow4->Timer4_Stop();
               cow4->TimerDelay_Stop();
               delete buttonAtPos2_cow4;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat4->Set_Farmer_Pushbutton(buttonAtPos2_wheat4);
               wheat4->Farmer_pushbutton_position(1710, 160);
               wheat4->Set_Farmer_animation(animation4);

               wheat4->Farmer_pushbutton_setenable4();
               wheat4->Timer4_Stop();
               wheat4->TimerDelay_Stop();
               delete buttonAtPos2_wheat4;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley4->Set_Farmer_Pushbutton(buttonAtPos2_barley4);
               barley4->Farmer_pushbutton_position(1710, 160);
               barley4->Set_Farmer_animation(animation4);

               barley4->Farmer_pushbutton_setenable4();
               barley4->Timer4_Stop();
               barley4->TimerDelay_Stop();
               delete buttonAtPos2_barley4;

           }
        }

    }
    if(ui->the_product_of_chicken_pushButton_4->isVisible()){

        ch4->TimerDelay_Stop();
        delete buttonAtPos2_ch4;
    }
    if(ui->the_product_of_sheep_pushButton_4->isVisible()){

        sheep4->TimerDelay_Stop();
        delete buttonAtPos2_Sheep4;
    }
    if(ui->the_product_of_cow_pushButton_4->isVisible()){

        cow4->TimerDelay_Stop();
        delete buttonAtPos2_cow4;
    }
    if(ui->the_product_of_wheat_pushButton_4->isVisible()){

        wheat4->TimerDelay_Stop();
        delete buttonAtPos2_wheat4;
    }
    if(ui->the_product_of_barley_pushButton_4->isVisible()){

        barley4->TimerDelay_Stop();
        delete buttonAtPos2_barley4;
    }

    if(ui->Cancel_5->isVisible()){

        QPoint Pos(150, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch5->Set_Farmer_Pushbutton(buttonAtPos2_ch5);
               ch5->Farmer_pushbutton_position(210, 390);
               ch5->Set_Farmer_animation(animation5);

               ch5->Farmer_pushbutton_setenable5();
               ch5->Timer5_Stop();
               ch5->TimerDelay_Stop();
               delete buttonAtPos2_ch5;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep5->Set_Farmer_Pushbutton(buttonAtPos2_Sheep5);
               sheep5->Farmer_pushbutton_position(210, 390);
               sheep5->Set_Farmer_animation(animation5);

               sheep5->Farmer_pushbutton_setenable5();
               sheep5->Timer5_Stop();
               sheep5->TimerDelay_Stop();
               delete buttonAtPos2_Sheep5;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow5->Set_Farmer_Pushbutton(buttonAtPos2_cow5);
               cow5->Farmer_pushbutton_position(210, 390);
               cow5->Set_Farmer_animation(animation5);

               cow5->Farmer_pushbutton_setenable5();
               cow5->Timer5_Stop();
               cow5->TimerDelay_Stop();
               delete buttonAtPos2_cow5;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat5->Set_Farmer_Pushbutton(buttonAtPos2_wheat5);
               wheat5->Farmer_pushbutton_position(210, 390);
               wheat5->Set_Farmer_animation(animation5);

               wheat5->Farmer_pushbutton_setenable5();
               wheat5->Timer5_Stop();
               wheat5->TimerDelay_Stop();
               delete buttonAtPos2_wheat5;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley5->Set_Farmer_Pushbutton(buttonAtPos2_barley5);
               barley5->Farmer_pushbutton_position(210, 390);
               barley5->Set_Farmer_animation(animation5);

               barley5->Farmer_pushbutton_setenable5();
               barley5->Timer5_Stop();
               barley5->TimerDelay_Stop();
               delete buttonAtPos2_barley5;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_5->isVisible()){

        ch5->TimerDelay_Stop();
        delete buttonAtPos2_ch5;
    }
    if(ui->the_product_of_sheep_pushButton_5->isVisible()){

        sheep5->TimerDelay_Stop();
        delete buttonAtPos2_Sheep5;
    }
    if(ui->the_product_of_cow_pushButton_5->isVisible()){

        cow5->TimerDelay_Stop();
        delete buttonAtPos2_cow5;
    }
    if(ui->the_product_of_wheat_pushButton_5->isVisible()){

        wheat5->TimerDelay_Stop();
        delete buttonAtPos2_wheat5;
    }
    if(ui->the_product_of_barley_pushButton_5->isVisible()){

        barley5->TimerDelay_Stop();
        delete buttonAtPos2_barley5;
    }

    if(ui->Cancel_6->isVisible()){

        QPoint Pos(540, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch6->Set_Farmer_Pushbutton(buttonAtPos2_ch6);
               ch6->Farmer_pushbutton_position(600, 390);
               ch6->Set_Farmer_animation(animation6);

               ch6->Farmer_pushbutton_setenable6();
               ch6->Timer6_Stop();
               ch6->TimerDelay_Stop();
               delete buttonAtPos2_ch6;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep6->Set_Farmer_Pushbutton(buttonAtPos2_Sheep6);
               sheep6->Farmer_pushbutton_position(600, 390);
               sheep6->Set_Farmer_animation(animation6);

               sheep6->Farmer_pushbutton_setenable6();
               sheep6->Timer6_Stop();
               sheep6->TimerDelay_Stop();
               delete buttonAtPos2_Sheep6;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow6->Set_Farmer_Pushbutton(buttonAtPos2_cow6);
               cow6->Farmer_pushbutton_position(600, 390);
               cow6->Set_Farmer_animation(animation6);

               cow6->Farmer_pushbutton_setenable6();
               cow6->Timer6_Stop();
               cow6->TimerDelay_Stop();
               delete buttonAtPos2_cow6;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat6->Set_Farmer_Pushbutton(buttonAtPos2_wheat6);
               wheat6->Farmer_pushbutton_position(600, 390);
               wheat6->Set_Farmer_animation(animation6);

               wheat6->Farmer_pushbutton_setenable6();
               wheat6->Timer6_Stop();
               wheat6->TimerDelay_Stop();
               delete buttonAtPos2_wheat6;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley6->Set_Farmer_Pushbutton(buttonAtPos2_barley6);
               barley6->Farmer_pushbutton_position(600, 390);
               barley6->Set_Farmer_animation(animation6);

               barley6->Farmer_pushbutton_setenable6();
               barley6->Timer6_Stop();
               barley6->TimerDelay_Stop();
               delete buttonAtPos2_barley6;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_6->isVisible()){

        ch6->TimerDelay_Stop();
        delete buttonAtPos2_ch6;
    }
    if(ui->the_product_of_sheep_pushButton_6->isVisible()){

        sheep6->TimerDelay_Stop();
        delete buttonAtPos2_Sheep6;
    }
    if(ui->the_product_of_cow_pushButton_6->isVisible()){

        cow6->TimerDelay_Stop();
        delete buttonAtPos2_cow6;
    }
    if(ui->the_product_of_wheat_pushButton_6->isVisible()){

        wheat6->TimerDelay_Stop();
        delete buttonAtPos2_wheat6;
    }
    if(ui->the_product_of_barley_pushButton_6->isVisible()){

        barley6->TimerDelay_Stop();
        delete buttonAtPos2_barley6;
    }

    if(ui->Cancel_7->isVisible()){

        QPoint Pos(1260, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch7->Set_Farmer_Pushbutton(buttonAtPos2_ch7);
               ch7->Farmer_pushbutton_position(1320, 390);
               ch7->Set_Farmer_animation(animation7);

               ch7->Farmer_pushbutton_setenable7();
               ch7->Timer7_Stop();
               ch7->TimerDelay_Stop();
               delete buttonAtPos2_ch7;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep7->Set_Farmer_Pushbutton(buttonAtPos2_Sheep7);
               sheep7->Farmer_pushbutton_position(1320, 390);
               sheep7->Set_Farmer_animation(animation7);

               sheep7->Farmer_pushbutton_setenable7();
               sheep7->Timer7_Stop();
               sheep7->TimerDelay_Stop();
               delete buttonAtPos2_Sheep7;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow7->Set_Farmer_Pushbutton(buttonAtPos2_cow7);
               cow7->Farmer_pushbutton_position(1320, 390);
               cow7->Set_Farmer_animation(animation7);

               cow7->Farmer_pushbutton_setenable7();
               cow7->Timer7_Stop();
               cow7->TimerDelay_Stop();
               delete buttonAtPos2_cow7;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat7->Set_Farmer_Pushbutton(buttonAtPos2_wheat7);
               wheat7->Farmer_pushbutton_position(1320, 390);
               wheat7->Set_Farmer_animation(animation7);

               wheat7->Farmer_pushbutton_setenable7();
               wheat7->Timer7_Stop();
               wheat7->TimerDelay_Stop();
               delete buttonAtPos2_wheat7;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley7->Set_Farmer_Pushbutton(buttonAtPos2_barley7);
               barley7->Farmer_pushbutton_position(1320, 390);
               barley7->Set_Farmer_animation(animation7);

               barley7->Farmer_pushbutton_setenable7();
               barley7->Timer7_Stop();
               barley7->TimerDelay_Stop();
               delete buttonAtPos2_barley7;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_7->isVisible()){

        ch7->TimerDelay_Stop();
        delete buttonAtPos2_ch7;
    }
    if(ui->the_product_of_sheep_pushButton_7->isVisible()){

        sheep7->TimerDelay_Stop();
        delete buttonAtPos2_Sheep7;
    }
    if(ui->the_product_of_cow_pushButton_7->isVisible()){

        cow7->TimerDelay_Stop();
        delete buttonAtPos2_cow7;
    }
    if(ui->the_product_of_wheat_pushButton_7->isVisible()){

        wheat7->TimerDelay_Stop();
        delete buttonAtPos2_wheat7;
    }
    if(ui->the_product_of_barley_pushButton_7->isVisible()){

        barley7->TimerDelay_Stop();
        delete buttonAtPos2_barley7;
    }

    if(ui->Cancel_8->isVisible()){

        QPoint Pos(1650, 410);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch8->Set_Farmer_Pushbutton(buttonAtPos2_ch8);
               ch8->Farmer_pushbutton_position(1710, 390);
               ch8->Set_Farmer_animation(animation8);

               ch8->Farmer_pushbutton_setenable8();
               ch8->Timer8_Stop();
               ch8->TimerDelay_Stop();
               delete buttonAtPos2_ch8;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep8->Set_Farmer_Pushbutton(buttonAtPos2_Sheep8);
               sheep8->Farmer_pushbutton_position(1710, 390);
               sheep8->Set_Farmer_animation(animation8);

               sheep8->Farmer_pushbutton_setenable8();
               sheep8->Timer8_Stop();
               sheep8->TimerDelay_Stop();
               delete buttonAtPos2_Sheep8;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow8->Set_Farmer_Pushbutton(buttonAtPos2_cow8);
               cow8->Farmer_pushbutton_position(1710, 390);
               cow8->Set_Farmer_animation(animation8);

               cow8->Farmer_pushbutton_setenable8();
               cow8->Timer8_Stop();
               cow8->TimerDelay_Stop();
               delete buttonAtPos2_cow8;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat8->Set_Farmer_Pushbutton(buttonAtPos2_wheat8);
               wheat8->Farmer_pushbutton_position(1710, 390);
               wheat8->Set_Farmer_animation(animation8);

               wheat8->Farmer_pushbutton_setenable8();
               wheat8->Timer8_Stop();
               wheat8->TimerDelay_Stop();
               delete buttonAtPos2_wheat8;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley8->Set_Farmer_Pushbutton(buttonAtPos2_barley8);
               barley8->Farmer_pushbutton_position(1710, 390);
               barley8->Set_Farmer_animation(animation8);

               barley8->Farmer_pushbutton_setenable8();
               barley8->Timer8_Stop();
               barley8->TimerDelay_Stop();
               delete buttonAtPos2_barley8;

           }
        }

    }
    if(ui->the_product_of_chicken_pushButton_8->isVisible()){

        ch8->TimerDelay_Stop();
        delete buttonAtPos2_ch8;
    }
    if(ui->the_product_of_sheep_pushButton_8->isVisible()){

        sheep8->TimerDelay_Stop();
        delete buttonAtPos2_Sheep8;
    }
    if(ui->the_product_of_cow_pushButton_8->isVisible()){

        cow8->TimerDelay_Stop();
        delete buttonAtPos2_cow8;
    }
    if(ui->the_product_of_wheat_pushButton_8->isVisible()){

        wheat8->TimerDelay_Stop();
        delete buttonAtPos2_wheat8;
    }
    if(ui->the_product_of_barley_pushButton_8->isVisible()){

        barley8->TimerDelay_Stop();
        delete buttonAtPos2_barley8;
    }

    if(ui->Cancel_9->isVisible()){

        QPoint Pos(150, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch9->Set_Farmer_Pushbutton(buttonAtPos2_ch9);
               ch9->Farmer_pushbutton_position(210, 620);
               ch9->Set_Farmer_animation(animation9);

               ch9->Farmer_pushbutton_setenable9();
               ch9->Timer9_Stop();
               ch9->TimerDelay_Stop();
               delete buttonAtPos2_ch9;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep9->Set_Farmer_Pushbutton(buttonAtPos2_Sheep9);
               sheep9->Farmer_pushbutton_position(210, 620);
               sheep9->Set_Farmer_animation(animation9);

               sheep9->Farmer_pushbutton_setenable9();
               sheep9->Timer9_Stop();
               sheep9->TimerDelay_Stop();
               delete buttonAtPos2_Sheep9;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow9->Set_Farmer_Pushbutton(buttonAtPos2_cow9);
               cow9->Farmer_pushbutton_position(210, 620);
               cow9->Set_Farmer_animation(animation9);

               cow9->Farmer_pushbutton_setenable9();
               cow9->Timer9_Stop();
               cow9->TimerDelay_Stop();
               delete buttonAtPos2_cow9;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat9->Set_Farmer_Pushbutton(buttonAtPos2_wheat9);
               wheat9->Farmer_pushbutton_position(210, 620);
               wheat9->Set_Farmer_animation(animation9);

               wheat9->Farmer_pushbutton_setenable9();
               wheat9->Timer9_Stop();
               wheat9->TimerDelay_Stop();
               delete buttonAtPos2_wheat9;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley9->Set_Farmer_Pushbutton(buttonAtPos2_barley9);
               barley9->Farmer_pushbutton_position(210, 620);
               barley9->Set_Farmer_animation(animation9);

               barley9->Farmer_pushbutton_setenable9();
               barley9->Timer9_Stop();
               barley9->TimerDelay_Stop();
               delete buttonAtPos2_barley9;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_9->isVisible()){

        ch9->TimerDelay_Stop();
        delete buttonAtPos2_ch9;
    }
    if(ui->the_product_of_sheep_pushButton_9->isVisible()){

        sheep9->TimerDelay_Stop();
        delete buttonAtPos2_Sheep9;
    }
    if(ui->the_product_of_cow_pushButton_9->isVisible()){

        cow9->TimerDelay_Stop();
        delete buttonAtPos2_cow9;
    }
    if(ui->the_product_of_wheat_pushButton_9->isVisible()){

        wheat9->TimerDelay_Stop();
        delete buttonAtPos2_wheat9;
    }
    if(ui->the_product_of_barley_pushButton_9->isVisible()){

        barley9->TimerDelay_Stop();
        delete buttonAtPos2_barley9;
    }

    if(ui->Cancel_10->isVisible()){

        QPoint Pos(540, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch10->Set_Farmer_Pushbutton(buttonAtPos2_ch10);
               ch10->Farmer_pushbutton_position(600, 620);
               ch10->Set_Farmer_animation(animation10);

               ch10->Farmer_pushbutton_setenable10();
               ch10->Timer10_Stop();
               ch10->TimerDelay_Stop();
               delete buttonAtPos2_ch10;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep10->Set_Farmer_Pushbutton(buttonAtPos2_Sheep10);
               sheep10->Farmer_pushbutton_position(600, 620);
               sheep10->Set_Farmer_animation(animation10);

               sheep10->Farmer_pushbutton_setenable10();
               sheep10->Timer10_Stop();
               sheep10->TimerDelay_Stop();
               delete buttonAtPos2_Sheep10;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow10->Set_Farmer_Pushbutton(buttonAtPos2_cow10);
               cow10->Farmer_pushbutton_position(600, 620);
               cow10->Set_Farmer_animation(animation10);

               cow10->Farmer_pushbutton_setenable10();
               cow10->Timer10_Stop();
               cow10->TimerDelay_Stop();
               delete buttonAtPos2_cow10;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat10->Set_Farmer_Pushbutton(buttonAtPos2_wheat10);
               wheat10->Farmer_pushbutton_position(600, 620);
               wheat10->Set_Farmer_animation(animation10);

               wheat10->Farmer_pushbutton_setenable10();
               wheat10->Timer10_Stop();
               wheat10->TimerDelay_Stop();
               delete buttonAtPos2_wheat10;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley10->Set_Farmer_Pushbutton(buttonAtPos2_barley10);
               barley10->Farmer_pushbutton_position(600, 620);
               barley10->Set_Farmer_animation(animation10);

               barley10->Farmer_pushbutton_setenable10();
               barley10->Timer10_Stop();
               barley10->TimerDelay_Stop();
               delete buttonAtPos2_barley10;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_10->isVisible()){

        ch10->TimerDelay_Stop();
        delete buttonAtPos2_ch10;
    }
    if(ui->the_product_of_sheep_pushButton_10->isVisible()){

        sheep10->TimerDelay_Stop();
        delete buttonAtPos2_Sheep10;
    }
    if(ui->the_product_of_cow_pushButton_10->isVisible()){

        cow10->TimerDelay_Stop();
        delete buttonAtPos2_cow10;
    }
    if(ui->the_product_of_wheat_pushButton_10->isVisible()){

        wheat10->TimerDelay_Stop();
        delete buttonAtPos2_wheat10;
    }
    if(ui->the_product_of_barley_pushButton_10->isVisible()){

        barley10->TimerDelay_Stop();
        delete buttonAtPos2_barley10;
    }

    if(ui->Cancel_11->isVisible()){

        QPoint Pos(1260, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch11->Set_Farmer_Pushbutton(buttonAtPos2_ch11);
               ch11->Farmer_pushbutton_position(1320, 620);
               ch11->Set_Farmer_animation(animation11);

               ch11->Farmer_pushbutton_setenable11();
               ch11->Timer11_Stop();
               ch11->TimerDelay_Stop();
               delete buttonAtPos2_ch11;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep11->Set_Farmer_Pushbutton(buttonAtPos2_Sheep11);
               sheep11->Farmer_pushbutton_position(1320, 620);
               sheep11->Set_Farmer_animation(animation11);

               sheep11->Farmer_pushbutton_setenable11();
               sheep11->Timer11_Stop();
               sheep11->TimerDelay_Stop();
               delete buttonAtPos2_Sheep11;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow11->Set_Farmer_Pushbutton(buttonAtPos2_cow11);
               cow11->Farmer_pushbutton_position(1320, 620);
               cow11->Set_Farmer_animation(animation11);

               cow11->Farmer_pushbutton_setenable11();
               cow11->Timer11_Stop();
               cow11->TimerDelay_Stop();
               delete buttonAtPos2_cow11;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat11->Set_Farmer_Pushbutton(buttonAtPos2_wheat11);
               wheat11->Farmer_pushbutton_position(1320, 620);
               wheat11->Set_Farmer_animation(animation11);

               wheat11->Farmer_pushbutton_setenable11();
               wheat11->Timer11_Stop();
               wheat11->TimerDelay_Stop();
               delete buttonAtPos2_wheat11;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley11->Set_Farmer_Pushbutton(buttonAtPos2_barley11);
               barley11->Farmer_pushbutton_position(1320, 620);
               barley11->Set_Farmer_animation(animation11);

               barley11->Farmer_pushbutton_setenable11();
               barley11->Timer11_Stop();
               barley11->TimerDelay_Stop();
               delete buttonAtPos2_barley11;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_11->isVisible()){

        ch11->TimerDelay_Stop();
        delete buttonAtPos2_ch11;
    }
    if(ui->the_product_of_sheep_pushButton_11->isVisible()){

        sheep11->TimerDelay_Stop();
        delete buttonAtPos2_Sheep11;
    }
    if(ui->the_product_of_cow_pushButton_11->isVisible()){

        cow11->TimerDelay_Stop();
        delete buttonAtPos2_cow11;
    }
    if(ui->the_product_of_wheat_pushButton_11->isVisible()){

        wheat11->TimerDelay_Stop();
        delete buttonAtPos2_wheat11;
    }
    if(ui->the_product_of_barley_pushButton_11->isVisible()){

        barley11->TimerDelay_Stop();
        delete buttonAtPos2_barley11;
    }

    if(ui->Cancel_12->isVisible()){

        QPoint Pos(1650, 640);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch12->Set_Farmer_Pushbutton(buttonAtPos2_ch12);
               ch12->Farmer_pushbutton_position(1710, 620);
               ch12->Set_Farmer_animation(animation12);

               ch12->Farmer_pushbutton_setenable12();
               ch12->Timer12_Stop();
               ch12->TimerDelay_Stop();
               delete buttonAtPos2_ch12;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep12->Set_Farmer_Pushbutton(buttonAtPos2_Sheep12);
               sheep12->Farmer_pushbutton_position(1710, 620);
               sheep12->Set_Farmer_animation(animation12);

               sheep12->Farmer_pushbutton_setenable12();
               sheep12->Timer12_Stop();
               sheep12->TimerDelay_Stop();
               delete buttonAtPos2_Sheep12;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow12->Set_Farmer_Pushbutton(buttonAtPos2_cow12);
               cow12->Farmer_pushbutton_position(1710, 620);
               cow12->Set_Farmer_animation(animation12);

               cow12->Farmer_pushbutton_setenable12();
               cow12->Timer12_Stop();
               cow12->TimerDelay_Stop();
               delete buttonAtPos2_cow12;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat12->Set_Farmer_Pushbutton(buttonAtPos2_wheat12);
               wheat12->Farmer_pushbutton_position(1710, 620);
               wheat12->Set_Farmer_animation(animation12);

               wheat12->Farmer_pushbutton_setenable12();
               wheat12->Timer12_Stop();
               wheat12->TimerDelay_Stop();
               delete buttonAtPos2_wheat12;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley12->Set_Farmer_Pushbutton(buttonAtPos2_barley12);
               barley12->Farmer_pushbutton_position(1710, 620);
               barley12->Set_Farmer_animation(animation12);

               barley12->Farmer_pushbutton_setenable12();
               barley12->Timer12_Stop();
               barley12->TimerDelay_Stop();
               delete buttonAtPos2_barley12;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_12->isVisible()){

        ch12->TimerDelay_Stop();
        delete buttonAtPos2_ch12;
    }
    if(ui->the_product_of_sheep_pushButton_12->isVisible()){

        sheep12->TimerDelay_Stop();
        delete buttonAtPos2_Sheep12;
    }
    if(ui->the_product_of_cow_pushButton_12->isVisible()){

        cow12->TimerDelay_Stop();
        delete buttonAtPos2_cow12;
    }
    if(ui->the_product_of_wheat_pushButton_12->isVisible()){

        wheat12->TimerDelay_Stop();
        delete buttonAtPos2_wheat12;
    }
    if(ui->the_product_of_barley_pushButton_12->isVisible()){

        barley12->TimerDelay_Stop();
        delete buttonAtPos2_barley12;
    }

    if(ui->Cancel_13->isVisible()){

        QPoint Pos(150, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch13->Set_Farmer_Pushbutton(buttonAtPos2_ch13);
               ch13->Farmer_pushbutton_position(210, 850);
               ch13->Set_Farmer_animation(animation13);

               ch13->Farmer_pushbutton_setenable13();
               ch13->Timer13_Stop();
               ch13->TimerDelay_Stop();
               delete buttonAtPos2_ch13;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep13->Set_Farmer_Pushbutton(buttonAtPos2_Sheep13);
               sheep13->Farmer_pushbutton_position(210, 850);
               sheep13->Set_Farmer_animation(animation13);

               sheep13->Farmer_pushbutton_setenable13();
               sheep13->Timer13_Stop();
               sheep13->TimerDelay_Stop();
               delete buttonAtPos2_Sheep13;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow13->Set_Farmer_Pushbutton(buttonAtPos2_cow13);
               cow13->Farmer_pushbutton_position(210, 850);
               cow13->Set_Farmer_animation(animation13);

               cow13->Farmer_pushbutton_setenable13();
               cow13->Timer13_Stop();
               cow13->TimerDelay_Stop();
               delete buttonAtPos2_cow13;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat13->Set_Farmer_Pushbutton(buttonAtPos2_wheat13);
               wheat13->Farmer_pushbutton_position(210, 850);
               wheat13->Set_Farmer_animation(animation13);

               wheat13->Farmer_pushbutton_setenable13();
               wheat13->Timer13_Stop();
               wheat13->TimerDelay_Stop();
               delete buttonAtPos2_wheat13;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley13->Set_Farmer_Pushbutton(buttonAtPos2_barley13);
               barley13->Farmer_pushbutton_position(210, 850);
               barley13->Set_Farmer_animation(animation13);

               barley13->Farmer_pushbutton_setenable13();
               barley13->Timer13_Stop();
               barley13->TimerDelay_Stop();
               delete buttonAtPos2_barley13;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_13->isVisible()){

        ch13->TimerDelay_Stop();
        delete buttonAtPos2_ch13;
    }
    if(ui->the_product_of_sheep_pushButton_13->isVisible()){

        sheep13->TimerDelay_Stop();
        delete buttonAtPos2_Sheep13;
    }
    if(ui->the_product_of_cow_pushButton_13->isVisible()){

        cow13->TimerDelay_Stop();
        delete buttonAtPos2_cow13;
    }
    if(ui->the_product_of_wheat_pushButton_13->isVisible()){

        wheat13->TimerDelay_Stop();
        delete buttonAtPos2_wheat13;
    }
    if(ui->the_product_of_barley_pushButton_13->isVisible()){

        barley13->TimerDelay_Stop();
        delete buttonAtPos2_barley13;
    }

    if(ui->Cancel_14->isVisible()){

        QPoint Pos(540, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch14->Set_Farmer_Pushbutton(buttonAtPos2_ch14);
               ch14->Farmer_pushbutton_position(600, 850);
               ch14->Set_Farmer_animation(animation14);

               ch14->Farmer_pushbutton_setenable14();
               ch14->Timer14_Stop();
               ch14->TimerDelay_Stop();
               delete buttonAtPos2_ch14;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep14->Set_Farmer_Pushbutton(buttonAtPos2_Sheep14);
               sheep14->Farmer_pushbutton_position(600, 850);
               sheep14->Set_Farmer_animation(animation14);

               sheep14->Farmer_pushbutton_setenable14();
               sheep14->Timer14_Stop();
               sheep14->TimerDelay_Stop();
               delete buttonAtPos2_Sheep14;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow14->Set_Farmer_Pushbutton(buttonAtPos2_cow14);
               cow14->Farmer_pushbutton_position(210, 850);
               cow14->Set_Farmer_animation(animation14);

               cow14->Farmer_pushbutton_setenable14();
               cow14->Timer14_Stop();
               cow14->TimerDelay_Stop();
               delete buttonAtPos2_cow14;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat14->Set_Farmer_Pushbutton(buttonAtPos2_wheat14);
               wheat14->Farmer_pushbutton_position(600, 850);
               wheat14->Set_Farmer_animation(animation14);

               wheat14->Farmer_pushbutton_setenable14();
               wheat14->Timer14_Stop();
               wheat14->TimerDelay_Stop();
               delete buttonAtPos2_wheat14;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley14->Set_Farmer_Pushbutton(buttonAtPos2_barley14);
               barley14->Farmer_pushbutton_position(600, 850);
               barley14->Set_Farmer_animation(animation14);

               barley14->Farmer_pushbutton_setenable14();
               barley14->Timer14_Stop();
               barley14->TimerDelay_Stop();
               delete buttonAtPos2_barley14;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_14->isVisible()){

        ch14->TimerDelay_Stop();
        delete buttonAtPos2_ch14;
    }
    if(ui->the_product_of_sheep_pushButton_14->isVisible()){

        sheep14->TimerDelay_Stop();
        delete buttonAtPos2_Sheep14;
    }
    if(ui->the_product_of_cow_pushButton_14->isVisible()){

        cow14->TimerDelay_Stop();
        delete buttonAtPos2_cow14;
    }
    if(ui->the_product_of_wheat_pushButton_14->isVisible()){

        wheat14->TimerDelay_Stop();
        delete buttonAtPos2_wheat14;
    }
    if(ui->the_product_of_barley_pushButton_14->isVisible()){

        barley14->TimerDelay_Stop();
        delete buttonAtPos2_barley14;
    }

    if(ui->Cancel_15->isVisible()){

        QPoint Pos(1260, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch15->Set_Farmer_Pushbutton(buttonAtPos2_ch15);
               ch15->Farmer_pushbutton_position(1320, 850);
               ch15->Set_Farmer_animation(animation15);

               ch15->Farmer_pushbutton_setenable15();
               ch15->Timer15_Stop();
               ch15->TimerDelay_Stop();
               delete buttonAtPos2_ch15;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep15->Set_Farmer_Pushbutton(buttonAtPos2_Sheep15);
               sheep15->Farmer_pushbutton_position(1320, 850);
               sheep15->Set_Farmer_animation(animation15);

               sheep15->Farmer_pushbutton_setenable15();
               sheep15->Timer15_Stop();
               sheep15->TimerDelay_Stop();
               delete buttonAtPos2_Sheep15;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow15->Set_Farmer_Pushbutton(buttonAtPos2_cow15);
               cow15->Farmer_pushbutton_position(1320, 850);
               cow15->Set_Farmer_animation(animation15);

               cow15->Farmer_pushbutton_setenable15();
               cow15->Timer15_Stop();
               cow15->TimerDelay_Stop();
               delete buttonAtPos2_cow15;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat15->Set_Farmer_Pushbutton(buttonAtPos2_wheat15);
               wheat15->Farmer_pushbutton_position(1320, 850);
               wheat15->Set_Farmer_animation(animation15);

               wheat15->Farmer_pushbutton_setenable15();
               wheat15->Timer15_Stop();
               wheat15->TimerDelay_Stop();
               delete buttonAtPos2_wheat15;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley15->Set_Farmer_Pushbutton(buttonAtPos2_barley15);
               barley15->Farmer_pushbutton_position(1320, 850);
               barley15->Set_Farmer_animation(animation15);

               barley15->Farmer_pushbutton_setenable15();
               barley15->Timer15_Stop();
               barley15->TimerDelay_Stop();
               delete buttonAtPos2_barley15;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_15->isVisible()){

        ch15->TimerDelay_Stop();
        delete buttonAtPos2_ch15;
    }
    if(ui->the_product_of_sheep_pushButton_15->isVisible()){

        sheep15->TimerDelay_Stop();
        delete buttonAtPos2_Sheep15;
    }
    if(ui->the_product_of_cow_pushButton_15->isVisible()){

        cow15->TimerDelay_Stop();
        delete buttonAtPos2_cow15;
    }
    if(ui->the_product_of_wheat_pushButton_15->isVisible()){

        wheat15->TimerDelay_Stop();
        delete buttonAtPos2_wheat15;
    }
    if(ui->the_product_of_barley_pushButton_15->isVisible()){

        barley15->TimerDelay_Stop();
        delete buttonAtPos2_barley15;
    }

    if(ui->Cancel_16->isVisible()){

        QPoint Pos(1650, 870);

        QPushButton* buttonAtPos = this->check2(Pos);

        if (buttonAtPos != nullptr) {

           if (buttonAtPos->objectName() == "Chicken") {

               buttonAtPos->setEnabled(true);

               ch16->Set_Farmer_Pushbutton(buttonAtPos2_ch16);
               ch16->Farmer_pushbutton_position(1710, 850);
               ch16->Set_Farmer_animation(animation16);

               ch16->Farmer_pushbutton_setenable16();
               ch16->Timer16_Stop();
               ch16->TimerDelay_Stop();
               delete buttonAtPos2_ch16;

           } else if (buttonAtPos->objectName() == "Sheep") {

               buttonAtPos->setEnabled(true);

               sheep16->Set_Farmer_Pushbutton(buttonAtPos2_Sheep16);
               sheep16->Farmer_pushbutton_position(1710, 850);
               sheep16->Set_Farmer_animation(animation16);

               sheep16->Farmer_pushbutton_setenable16();
               sheep16->Timer16_Stop();
               sheep16->TimerDelay_Stop();
               delete buttonAtPos2_Sheep16;

           } else if (buttonAtPos->objectName() == "Cow") {

               buttonAtPos->setEnabled(true);

               cow16->Set_Farmer_Pushbutton(buttonAtPos2_cow16);
               cow16->Farmer_pushbutton_position(1710, 850);
               cow16->Set_Farmer_animation(animation16);

               cow16->Farmer_pushbutton_setenable16();
               cow16->Timer16_Stop();
               cow16->TimerDelay_Stop();
               delete buttonAtPos2_cow16;

           } else if (buttonAtPos->objectName() == "Wheat") {

               buttonAtPos->setEnabled(true);

               wheat16->Set_Farmer_Pushbutton(buttonAtPos2_wheat16);
               wheat16->Farmer_pushbutton_position(1710, 850);
               wheat16->Set_Farmer_animation(animation16);

               wheat16->Farmer_pushbutton_setenable16();
               wheat16->Timer16_Stop();
               wheat16->TimerDelay_Stop();
               delete buttonAtPos2_wheat16;

           } else if (buttonAtPos->objectName() == "Barley") {

               buttonAtPos->setEnabled(true);

               barley16->Set_Farmer_Pushbutton(buttonAtPos2_barley16);
               barley16->Farmer_pushbutton_position(1710, 850);
               barley16->Set_Farmer_animation(animation16);

               barley16->Farmer_pushbutton_setenable16();
               barley16->Timer16_Stop();
               barley16->TimerDelay_Stop();
               delete buttonAtPos2_barley16;

           }
        }
    }
    if(ui->the_product_of_chicken_pushButton_16->isVisible()){

        ch16->TimerDelay_Stop();
        delete buttonAtPos2_ch16;
    }
    if(ui->the_product_of_sheep_pushButton_16->isVisible()){

        sheep16->TimerDelay_Stop();
        delete buttonAtPos2_Sheep16;
    }
    if(ui->the_product_of_cow_pushButton_16->isVisible()){

        cow16->TimerDelay_Stop();
        delete buttonAtPos2_cow16;
    }
    if(ui->the_product_of_wheat_pushButton_16->isVisible()){

        wheat16->TimerDelay_Stop();
        delete buttonAtPos2_wheat16;
    }
    if(ui->the_product_of_barley_pushButton_16->isVisible()){

        barley16->TimerDelay_Stop();
        delete buttonAtPos2_barley16;
    }



    Delete_all_created_pushbuttos(this, "Chicken");
    Delete_all_created_pushbuttos(this, "Sheep");
    Delete_all_created_pushbuttos(this, "Cow");
    Delete_all_created_pushbuttos(this, "Wheat");
    Delete_all_created_pushbuttos(this, "Barley");
    Delete_all_created_pushbuttos(this, "Farmer");

    Default_farmer();
    score =10;
    ui->label_Score->setText( "Score : " + QString::number(score));

    number_of_farmers=1;
    number_of_Free_farmers=1;
    ui->number_of_Farmers_label ->setText( QString::number(number_of_Free_farmers) + " / " + QString::number(number_of_farmers));

    ui->label_Time->setText("3:00");

    Move_the_product_of_Animals_and_seeds_pushButton();

    Hide_the_product_of_Animals_and_seeds_pushButton();

    Hide_Timer_labels();

    Hide_Start_pushbuttuns();

    Hide_Cancel_pushbuttons();

    Hide_Farms();

    Hide_Feilds_number_label();

    Hide_label_of_timers();

    ui->groupBox->hide();

    ui->Results->hide();

    Hide_decrease_label();

    setCursorForAllButtons(this);
    F1_Having_Farmer=0, F1_Having_Animals_or_Seeds=0;
    F2_Having_Farmer=0, F2_Having_Animals_or_Seeds=0;
    F3_Having_Farmer=0, F3_Having_Animals_or_Seeds=0;
    F4_Having_Farmer=0, F4_Having_Animals_or_Seeds=0;
    F5_Having_Farmer=0, F5_Having_Animals_or_Seeds=0;
    F6_Having_Farmer=0, F6_Having_Animals_or_Seeds=0;
    F7_Having_Farmer=0, F7_Having_Animals_or_Seeds=0;
    F8_Having_Farmer=0, F8_Having_Animals_or_Seeds=0;
    F9_Having_Farmer=0, F9_Having_Animals_or_Seeds=0;
    F10_Having_Farmer=0, F10_Having_Animals_or_Seeds=0;
    F11_Having_Farmer=0, F11_Having_Animals_or_Seeds=0;
    F12_Having_Farmer=0, F12_Having_Animals_or_Seeds=0;
    F13_Having_Farmer=0, F13_Having_Animals_or_Seeds=0;
    F14_Having_Farmer=0, F14_Having_Animals_or_Seeds=0;
    F15_Having_Farmer=0, F15_Having_Animals_or_Seeds=0;
    F16_Having_Farmer=0, F16_Having_Animals_or_Seeds=0;

    F1_Which_Of_Animals_or_Seeds=0;
    F2_Which_Of_Animals_or_Seeds=0;
    F3_Which_Of_Animals_or_Seeds=0;
    F4_Which_Of_Animals_or_Seeds=0;
    F5_Which_Of_Animals_or_Seeds=0;
    F6_Which_Of_Animals_or_Seeds=0;
    F7_Which_Of_Animals_or_Seeds=0;
    F8_Which_Of_Animals_or_Seeds=0;
    F9_Which_Of_Animals_or_Seeds=0;
    F10_Which_Of_Animals_or_Seeds=0;
    F11_Which_Of_Animals_or_Seeds=0;
    F12_Which_Of_Animals_or_Seeds=0;
    F13_Which_Of_Animals_or_Seeds=0;
    F14_Which_Of_Animals_or_Seeds=0;
    F15_Which_Of_Animals_or_Seeds=0;
    F16_Which_Of_Animals_or_Seeds=0;

    Get_info();
}
