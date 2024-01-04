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

Gamepage::Gamepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamepage)
{
    ui->setupUi(this);

    setMinimumSize(1908,978);
    setMaximumSize(1908,978);

    ui->groupBox->hide();

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

    qDebug()<< F1_Having_Animals_or_Seeds;

}

Gamepage::~Gamepage()
{
    delete ui;
}

void Gamepage::on_Shop_pushButton_clicked()
{
    if(ui->groupBox->isVisible()){

        ui->groupBox->hide();

    }else if(ui->groupBox->isHidden()){

        ui->groupBox->show();
    }
}


void Gamepage::on_Chicken_pushButton_clicked()
{


    Chicken * ch = new Chicken(ui->Animals_verticalLayout);

    connect(ch->pushButton, &QPushButton::clicked, this, [this, ch](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

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
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F1_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if((i==2 && ui->label_2->isHidden())){

               button->setEnabled(false);

           }else if(i==2 && ui->label_2->isVisible()){

               QPoint pos(540, 180);

               if(check(pos)==true){

                   qDebug()<<"F2 khalie";
                   F2_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   qDebug()<<"F2 poree";
                   F2_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==3 && ui->label_3->isHidden()){

               button->setEnabled(false);

           }else if(i==3 && ui->label_3->isVisible()){

               QPoint pos(1260, 180);

               if(check(pos)==true){

                   F3_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F3_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==4 && ui->label_4->isHidden()){

               button->setEnabled(false);

           }else if(i==4 && ui->label_4->isVisible()){

               QPoint pos(1650, 180);

               if(check(pos)==true){

                   F4_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F4_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==5 && ui->label_5->isHidden()){

               button->setEnabled(false);

           }else if(i==5 && ui->label_5->isVisible()){

               QPoint pos(150, 410);

               if(check(pos)==true){

                   F5_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F5_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==6 && ui->label_6->isHidden()){

               button->setEnabled(false);

           }else if(i==6 && ui->label_6->isVisible()){

               QPoint pos(540, 410);

               if(check(pos)==true){

                   F6_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F6_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==7 && ui->label_7->isHidden()){

               button->setEnabled(false);

           }else if(i==7 && ui->label_7->isVisible()){

               QPoint pos(1260, 410);

               if(check(pos)==true){

                   F7_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F7_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==8 && ui->label_8->isHidden()){

               button->setEnabled(false);

           }else if(i==8 && ui->label_8->isVisible()){

               QPoint pos(1650, 410);

               if(check(pos)==true){

                   F8_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F8_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==9 && ui->label_9->isHidden()){

               button->setEnabled(false);

           }else if(i==9 && ui->label_9->isVisible()){

               QPoint pos(150, 640);

               if(check(pos)==true){

                   F9_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F9_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==10 && ui->label_10->isHidden()){

               button->setEnabled(false);

           }else if(i==10 && ui->label_10->isVisible()){

               QPoint pos(540, 640);

               if(check(pos)==true){

                   F10_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F10_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==11 && ui->label_11->isHidden()){

               button->setEnabled(false);

           }else if(i==11 && ui->label_11->isVisible()){

               QPoint pos(1260, 640);

               if(check(pos)==true){

                   F11_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F11_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==12 && ui->label_12->isHidden()){

               button->setEnabled(false);

           }else if(i==12 && ui->label_12->isVisible()){

               QPoint pos(1650, 640);

               if(check(pos)==true){

                   F12_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F12_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==13 && ui->label_13->isHidden()){

               button->setEnabled(false);

           }else if(i==13 && ui->label_13->isVisible()){

               QPoint pos(150, 870);

               if(check(pos)==true){

                   F13_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F13_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==14 && ui->label_14->isHidden()){

               button->setEnabled(false);

           }else if(i==14 && ui->label_14->isVisible()){

               QPoint pos(540, 870);

               if(check(pos)==true){

                   F14_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F14_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==15 && ui->label_15->isHidden()){

               button->setEnabled(false);

           }else if(i==15 && ui->label_15->isVisible()){

               QPoint pos(1260, 870);

               if(check(pos)==true){

                   F15_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F15_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==16 && ui->label_16->isHidden()){

               button->setEnabled(false);

           }else if(i==16 && ui->label_16->isVisible()){

               QPoint pos(1650, 870);

               if(check(pos)==true){

                   F16_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F16_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

          if(i==17){

              button->setText("home");
              button->setMinimumSize(60,40);
          }

          if(i==18){

           button->setMinimumSize(50,40);
              button->setText("Kill");
          }
        }
    // clazy:exclude:connect-3arg-lambda
        QObject::connect(&msgBox, &QMessageBox::finished, [&](int result){
           QAbstractButton* clickedButton = msgBox.clickedButton();
           if (clickedButton) {
               int buttonNumber = buttonMap[clickedButton];

               switch(buttonNumber) {
               case 1:

                   if(F1_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(150, 180);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F1_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 2:

                   if(F2_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(540, 180);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F2_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 3:

                   if(F3_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1260, 180);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F3_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 4:

                   if(F4_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1650, 180);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F4_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 5:

                   if(F5_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(150, 410);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F5_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 6:

                   if(F6_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(540, 410);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F6_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 7:

                   if(F7_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1260, 410);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F7_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 8:

                   if(F8_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1650, 410);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F8_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 9:

                   if(F9_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(150, 640);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F9_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 10:

                   if(F10_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(540, 640);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F10_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 11:

                   if(F11_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1260, 640);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F11_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 12:

                   if(F12_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1650, 640);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F12_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 13:

                   if(F13_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(150, 870);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F13_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 14:

                   if(F14_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(540, 870);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F14_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 15:

                   if(F15_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1260, 870);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F15_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 16:

                   if(F16_Having_Animals_or_Seeds==0){

                       ch->pushButton->move(1650, 870);
                       ch->pushButton->setParent(this);
                       ch->pushButton->show();
                       F16_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 17:
                   //add to verticall layout
                   ui->Animals_verticalLayout->addWidget(ch->pushButton);

                   break;
               case 18:
                   // remove pushbutton
                   ui->Animals_verticalLayout->removeWidget(ch->pushButton);
                   delete ch->pushButton;
                   break;

               default:
                   break;
               }
           }

        });

        msgBox.exec();

       });
}


void Gamepage::on_Sheep_pushButton_clicked()
{
    Sheep * sheep = new Sheep(ui->Animals_verticalLayout);

    connect(sheep->pushButton, &QPushButton::clicked, this, [this, sheep](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

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
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F1_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if((i==2 && ui->label_2->isHidden())){

               button->setEnabled(false);

           }else if(i==2 && ui->label_2->isVisible()){

               QPoint pos(540, 180);

               if(check(pos)==true){

                   qDebug()<<"F2 khalie";
                   F2_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   qDebug()<<"F2 poree";
                   F2_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==3 && ui->label_3->isHidden()){

               button->setEnabled(false);

           }else if(i==3 && ui->label_3->isVisible()){

               QPoint pos(1260, 180);

               if(check(pos)==true){

                   F3_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F3_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==4 && ui->label_4->isHidden()){

               button->setEnabled(false);

           }else if(i==4 && ui->label_4->isVisible()){

               QPoint pos(1650, 180);

               if(check(pos)==true){

                   F4_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F4_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==5 && ui->label_5->isHidden()){

               button->setEnabled(false);

           }else if(i==5 && ui->label_5->isVisible()){

               QPoint pos(150, 410);

               if(check(pos)==true){

                   F5_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F5_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==6 && ui->label_6->isHidden()){

               button->setEnabled(false);

           }else if(i==6 && ui->label_6->isVisible()){

               QPoint pos(540, 410);

               if(check(pos)==true){

                   F6_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F6_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==7 && ui->label_7->isHidden()){

               button->setEnabled(false);

           }else if(i==7 && ui->label_7->isVisible()){

               QPoint pos(1260, 410);

               if(check(pos)==true){

                   F7_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F7_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==8 && ui->label_8->isHidden()){

               button->setEnabled(false);

           }else if(i==8 && ui->label_8->isVisible()){

               QPoint pos(1650, 410);

               if(check(pos)==true){

                   F8_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F8_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==9 && ui->label_9->isHidden()){

               button->setEnabled(false);

           }else if(i==9 && ui->label_9->isVisible()){

               QPoint pos(150, 640);

               if(check(pos)==true){

                   F9_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F9_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==10 && ui->label_10->isHidden()){

               button->setEnabled(false);

           }else if(i==10 && ui->label_10->isVisible()){

               QPoint pos(540, 640);

               if(check(pos)==true){

                   F10_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F10_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==11 && ui->label_11->isHidden()){

               button->setEnabled(false);

           }else if(i==11 && ui->label_11->isVisible()){

               QPoint pos(1260, 640);

               if(check(pos)==true){

                   F11_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F11_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==12 && ui->label_12->isHidden()){

               button->setEnabled(false);

           }else if(i==12 && ui->label_12->isVisible()){

               QPoint pos(1650, 640);

               if(check(pos)==true){

                   F12_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F12_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==13 && ui->label_13->isHidden()){

               button->setEnabled(false);

           }else if(i==13 && ui->label_13->isVisible()){

               QPoint pos(150, 870);

               if(check(pos)==true){

                   F13_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F13_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==14 && ui->label_14->isHidden()){

               button->setEnabled(false);

           }else if(i==14 && ui->label_14->isVisible()){

               QPoint pos(540, 870);

               if(check(pos)==true){

                   F14_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F14_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==15 && ui->label_15->isHidden()){

               button->setEnabled(false);

           }else if(i==15 && ui->label_15->isVisible()){

               QPoint pos(1260, 870);

               if(check(pos)==true){

                   F15_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F15_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==16 && ui->label_16->isHidden()){

               button->setEnabled(false);

           }else if(i==16 && ui->label_16->isVisible()){

               QPoint pos(1650, 870);

               if(check(pos)==true){

                   F16_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F16_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

          if(i==17){

              button->setText("home");
              button->setMinimumSize(60,40);
          }

          if(i==18){

           button->setMinimumSize(50,40);
              button->setText("Kill");
          }
        }
    // clazy:exclude:connect-3arg-lambda
        QObject::connect(&msgBox, &QMessageBox::finished, [&](int result){
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
                   }

                   break;
               case 2:

                   if(F2_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(540, 180);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F2_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 3:

                   if(F3_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1260, 180);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F3_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 4:

                   if(F4_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1650, 180);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F4_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 5:

                   if(F5_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(150, 410);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F5_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 6:

                   if(F6_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(540, 410);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F6_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 7:

                   if(F7_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1260, 410);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F7_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 8:

                   if(F8_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1650, 410);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F8_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 9:

                   if(F9_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(150, 640);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F9_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 10:

                   if(F10_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(540, 640);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F10_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 11:

                   if(F11_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1260, 640);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F11_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 12:

                   if(F12_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1650, 640);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F12_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 13:

                   if(F13_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(150, 870);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F13_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 14:

                   if(F14_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(540, 870);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F14_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 15:

                   if(F15_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1260, 870);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F15_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 16:

                   if(F16_Having_Animals_or_Seeds==0){

                       sheep->pushButton->move(1650, 870);
                       sheep->pushButton->setParent(this);
                       sheep->pushButton->show();
                       F16_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 17:
                   //add to verticall layout
                   ui->Animals_verticalLayout->addWidget(sheep->pushButton);

                   break;
               case 18:
                   // remove pushbutton
                   ui->Animals_verticalLayout->removeWidget(sheep->pushButton);
                   delete sheep->pushButton;
                   break;

               default:
                   break;
               }
           }

        });

        msgBox.exec();

       });
}


void Gamepage::on_Cow_pushButton_clicked()
{
    Cow * cow = new Cow(ui->Animals_verticalLayout);

    connect(cow->pushButton, &QPushButton::clicked, this, [this, cow](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

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
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F1_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if((i==2 && ui->label_2->isHidden())){

               button->setEnabled(false);

           }else if(i==2 && ui->label_2->isVisible()){

               QPoint pos(540, 180);

               if(check(pos)==true){

                   qDebug()<<"F2 khalie";
                   F2_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   qDebug()<<"F2 poree";
                   F2_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==3 && ui->label_3->isHidden()){

               button->setEnabled(false);

           }else if(i==3 && ui->label_3->isVisible()){

               QPoint pos(1260, 180);

               if(check(pos)==true){

                   F3_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F3_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==4 && ui->label_4->isHidden()){

               button->setEnabled(false);

           }else if(i==4 && ui->label_4->isVisible()){

               QPoint pos(1650, 180);

               if(check(pos)==true){

                   F4_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F4_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==5 && ui->label_5->isHidden()){

               button->setEnabled(false);

           }else if(i==5 && ui->label_5->isVisible()){

               QPoint pos(150, 410);

               if(check(pos)==true){

                   F5_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F5_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==6 && ui->label_6->isHidden()){

               button->setEnabled(false);

           }else if(i==6 && ui->label_6->isVisible()){

               QPoint pos(540, 410);

               if(check(pos)==true){

                   F6_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F6_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==7 && ui->label_7->isHidden()){

               button->setEnabled(false);

           }else if(i==7 && ui->label_7->isVisible()){

               QPoint pos(1260, 410);

               if(check(pos)==true){

                   F7_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F7_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==8 && ui->label_8->isHidden()){

               button->setEnabled(false);

           }else if(i==8 && ui->label_8->isVisible()){

               QPoint pos(1650, 410);

               if(check(pos)==true){

                   F8_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F8_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==9 && ui->label_9->isHidden()){

               button->setEnabled(false);

           }else if(i==9 && ui->label_9->isVisible()){

               QPoint pos(150, 640);

               if(check(pos)==true){

                   F9_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F9_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==10 && ui->label_10->isHidden()){

               button->setEnabled(false);

           }else if(i==10 && ui->label_10->isVisible()){

               QPoint pos(540, 640);

               if(check(pos)==true){

                   F10_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F10_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==11 && ui->label_11->isHidden()){

               button->setEnabled(false);

           }else if(i==11 && ui->label_11->isVisible()){

               QPoint pos(1260, 640);

               if(check(pos)==true){

                   F11_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F11_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==12 && ui->label_12->isHidden()){

               button->setEnabled(false);

           }else if(i==12 && ui->label_12->isVisible()){

               QPoint pos(1650, 640);

               if(check(pos)==true){

                   F12_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F12_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==13 && ui->label_13->isHidden()){

               button->setEnabled(false);

           }else if(i==13 && ui->label_13->isVisible()){

               QPoint pos(150, 870);

               if(check(pos)==true){

                   F13_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F13_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==14 && ui->label_14->isHidden()){

               button->setEnabled(false);

           }else if(i==14 && ui->label_14->isVisible()){

               QPoint pos(540, 870);

               if(check(pos)==true){

                   F14_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F14_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==15 && ui->label_15->isHidden()){

               button->setEnabled(false);

           }else if(i==15 && ui->label_15->isVisible()){

               QPoint pos(1260, 870);

               if(check(pos)==true){

                   F15_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F15_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==16 && ui->label_16->isHidden()){

               button->setEnabled(false);

           }else if(i==16 && ui->label_16->isVisible()){

               QPoint pos(1650, 870);

               if(check(pos)==true){

                   F16_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F16_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

          if(i==17){

              button->setText("home");
              button->setMinimumSize(60,40);
          }

          if(i==18){

           button->setMinimumSize(50,40);
              button->setText("Kill");
          }
        }
    // clazy:exclude:connect-3arg-lambda
        QObject::connect(&msgBox, &QMessageBox::finished, [&](int result){
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
                   }

                   break;
               case 2:

                   if(F2_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(540, 180);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F2_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 3:

                   if(F3_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1260, 180);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F3_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 4:

                   if(F4_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1650, 180);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F4_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 5:

                   if(F5_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(150, 410);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F5_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 6:

                   if(F6_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(540, 410);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F6_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 7:

                   if(F7_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1260, 410);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F7_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 8:

                   if(F8_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1650, 410);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F8_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 9:

                   if(F9_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(150, 640);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F9_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 10:

                   if(F10_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(540, 640);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F10_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 11:

                   if(F11_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1260, 640);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F11_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 12:

                   if(F12_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1650, 640);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F12_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 13:

                   if(F13_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(150, 870);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F13_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 14:

                   if(F14_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(540, 870);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F14_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 15:

                   if(F15_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1260, 870);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F15_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 16:

                   if(F16_Having_Animals_or_Seeds==0){

                       cow->pushButton->move(1650, 870);
                       cow->pushButton->setParent(this);
                       cow->pushButton->show();
                       F16_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 17:
                   //add to verticall layout
                   ui->Animals_verticalLayout->addWidget(cow->pushButton);

                   break;
               case 18:
                   // remove pushbutton
                   ui->Animals_verticalLayout->removeWidget(cow->pushButton);
                   delete cow->pushButton;
                   break;

               default:
                   break;
               }
           }

        });

        msgBox.exec();

       });
}


void Gamepage::on_Wheat_pushButton_clicked()
{
    Wheat * wheat = new Wheat(ui->Seeds_verticalLayout);

    connect(wheat->pushButton, &QPushButton::clicked, this, [this, wheat](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

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
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F1_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if((i==2 && ui->label_2->isHidden())){

               button->setEnabled(false);

           }else if(i==2 && ui->label_2->isVisible()){

               QPoint pos(540, 180);

               if(check(pos)==true){

                   qDebug()<<"F2 khalie";
                   F2_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   qDebug()<<"F2 poree";
                   F2_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==3 && ui->label_3->isHidden()){

               button->setEnabled(false);

           }else if(i==3 && ui->label_3->isVisible()){

               QPoint pos(1260, 180);

               if(check(pos)==true){

                   F3_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F3_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==4 && ui->label_4->isHidden()){

               button->setEnabled(false);

           }else if(i==4 && ui->label_4->isVisible()){

               QPoint pos(1650, 180);

               if(check(pos)==true){

                   F4_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F4_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==5 && ui->label_5->isHidden()){

               button->setEnabled(false);

           }else if(i==5 && ui->label_5->isVisible()){

               QPoint pos(150, 410);

               if(check(pos)==true){

                   F5_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F5_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==6 && ui->label_6->isHidden()){

               button->setEnabled(false);

           }else if(i==6 && ui->label_6->isVisible()){

               QPoint pos(540, 410);

               if(check(pos)==true){

                   F6_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F6_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==7 && ui->label_7->isHidden()){

               button->setEnabled(false);

           }else if(i==7 && ui->label_7->isVisible()){

               QPoint pos(1260, 410);

               if(check(pos)==true){

                   F7_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F7_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==8 && ui->label_8->isHidden()){

               button->setEnabled(false);

           }else if(i==8 && ui->label_8->isVisible()){

               QPoint pos(1650, 410);

               if(check(pos)==true){

                   F8_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F8_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==9 && ui->label_9->isHidden()){

               button->setEnabled(false);

           }else if(i==9 && ui->label_9->isVisible()){

               QPoint pos(150, 640);

               if(check(pos)==true){

                   F9_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F9_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==10 && ui->label_10->isHidden()){

               button->setEnabled(false);

           }else if(i==10 && ui->label_10->isVisible()){

               QPoint pos(540, 640);

               if(check(pos)==true){

                   F10_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F10_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==11 && ui->label_11->isHidden()){

               button->setEnabled(false);

           }else if(i==11 && ui->label_11->isVisible()){

               QPoint pos(1260, 640);

               if(check(pos)==true){

                   F11_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F11_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==12 && ui->label_12->isHidden()){

               button->setEnabled(false);

           }else if(i==12 && ui->label_12->isVisible()){

               QPoint pos(1650, 640);

               if(check(pos)==true){

                   F12_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F12_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==13 && ui->label_13->isHidden()){

               button->setEnabled(false);

           }else if(i==13 && ui->label_13->isVisible()){

               QPoint pos(150, 870);

               if(check(pos)==true){

                   F13_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F13_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==14 && ui->label_14->isHidden()){

               button->setEnabled(false);

           }else if(i==14 && ui->label_14->isVisible()){

               QPoint pos(540, 870);

               if(check(pos)==true){

                   F14_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F14_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==15 && ui->label_15->isHidden()){

               button->setEnabled(false);

           }else if(i==15 && ui->label_15->isVisible()){

               QPoint pos(1260, 870);

               if(check(pos)==true){

                   F15_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F15_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==16 && ui->label_16->isHidden()){

               button->setEnabled(false);

           }else if(i==16 && ui->label_16->isVisible()){

               QPoint pos(1650, 870);

               if(check(pos)==true){

                   F16_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F16_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

          if(i==17){

              button->setText("home");
              button->setMinimumSize(60,40);
          }

          if(i==18){

           button->setMinimumSize(50,40);
              button->setText("Kill");
          }
        }
    // clazy:exclude:connect-3arg-lambda
        QObject::connect(&msgBox, &QMessageBox::finished, [&](int result){
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
                   }

                   break;
               case 2:

                   if(F2_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(540, 180);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F2_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 3:

                   if(F3_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1260, 180);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F3_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 4:

                   if(F4_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1650, 180);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F4_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 5:

                   if(F5_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(150, 410);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F5_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 6:

                   if(F6_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(540, 410);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F6_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 7:

                   if(F7_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1260, 410);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F7_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 8:

                   if(F8_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1650, 410);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F8_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 9:

                   if(F9_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(150, 640);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F9_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 10:

                   if(F10_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(540, 640);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F10_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 11:

                   if(F11_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1260, 640);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F11_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 12:

                   if(F12_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1650, 640);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F12_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 13:

                   if(F13_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(150, 870);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F13_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 14:

                   if(F14_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(540, 870);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F14_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 15:

                   if(F15_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1260, 870);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F15_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 16:

                   if(F16_Having_Animals_or_Seeds==0){

                       wheat->pushButton->move(1650, 870);
                       wheat->pushButton->setParent(this);
                       wheat->pushButton->show();
                       F16_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 17:
                   //add to verticall layout
                   ui->Seeds_verticalLayout->addWidget(wheat->pushButton);

                   break;
               case 18:
                   // remove pushbutton
                   ui->Seeds_verticalLayout->removeWidget(wheat->pushButton);
                   delete wheat->pushButton;
                   break;

               default:
                   break;
               }
           }

        });

        msgBox.exec();

       });
}


void Gamepage::on_Barley_pushButton_clicked()
{
    Barley * barley = new Barley(ui->Seeds_verticalLayout);

    connect(barley->pushButton, &QPushButton::clicked, this, [this, barley](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

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
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F1_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if((i==2 && ui->label_2->isHidden())){

               button->setEnabled(false);

           }else if(i==2 && ui->label_2->isVisible()){

               QPoint pos(540, 180);

               if(check(pos)==true){

                   qDebug()<<"F2 khalie";
                   F2_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   qDebug()<<"F2 poree";
                   F2_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==3 && ui->label_3->isHidden()){

               button->setEnabled(false);

           }else if(i==3 && ui->label_3->isVisible()){

               QPoint pos(1260, 180);

               if(check(pos)==true){

                   F3_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F3_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==4 && ui->label_4->isHidden()){

               button->setEnabled(false);

           }else if(i==4 && ui->label_4->isVisible()){

               QPoint pos(1650, 180);

               if(check(pos)==true){

                   F4_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F4_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==5 && ui->label_5->isHidden()){

               button->setEnabled(false);

           }else if(i==5 && ui->label_5->isVisible()){

               QPoint pos(150, 410);

               if(check(pos)==true){

                   F5_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F5_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==6 && ui->label_6->isHidden()){

               button->setEnabled(false);

           }else if(i==6 && ui->label_6->isVisible()){

               QPoint pos(540, 410);

               if(check(pos)==true){

                   F6_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F6_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==7 && ui->label_7->isHidden()){

               button->setEnabled(false);

           }else if(i==7 && ui->label_7->isVisible()){

               QPoint pos(1260, 410);

               if(check(pos)==true){

                   F7_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F7_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==8 && ui->label_8->isHidden()){

               button->setEnabled(false);

           }else if(i==8 && ui->label_8->isVisible()){

               QPoint pos(1650, 410);

               if(check(pos)==true){

                   F8_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F8_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==9 && ui->label_9->isHidden()){

               button->setEnabled(false);

           }else if(i==9 && ui->label_9->isVisible()){

               QPoint pos(150, 640);

               if(check(pos)==true){

                   F9_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F9_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==10 && ui->label_10->isHidden()){

               button->setEnabled(false);

           }else if(i==10 && ui->label_10->isVisible()){

               QPoint pos(540, 640);

               if(check(pos)==true){

                   F10_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F10_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==11 && ui->label_11->isHidden()){

               button->setEnabled(false);

           }else if(i==11 && ui->label_11->isVisible()){

               QPoint pos(1260, 640);

               if(check(pos)==true){

                   F11_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F11_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==12 && ui->label_12->isHidden()){

               button->setEnabled(false);

           }else if(i==12 && ui->label_12->isVisible()){

               QPoint pos(1650, 640);

               if(check(pos)==true){

                   F12_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F12_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==13 && ui->label_13->isHidden()){

               button->setEnabled(false);

           }else if(i==13 && ui->label_13->isVisible()){

               QPoint pos(150, 870);

               if(check(pos)==true){

                   F13_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F13_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==14 && ui->label_14->isHidden()){

               button->setEnabled(false);

           }else if(i==14 && ui->label_14->isVisible()){

               QPoint pos(540, 870);

               if(check(pos)==true){

                   F14_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F14_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==15 && ui->label_15->isHidden()){

               button->setEnabled(false);

           }else if(i==15 && ui->label_15->isVisible()){

               QPoint pos(1260, 870);

               if(check(pos)==true){

                   F15_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F15_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

           if(i==16 && ui->label_16->isHidden()){

               button->setEnabled(false);

           }else if(i==16 && ui->label_16->isVisible()){

               QPoint pos(1650, 870);

               if(check(pos)==true){

                   F16_Having_Animals_or_Seeds=0;
                   button->setEnabled(true);
               }
               if(check(pos)==false){

                   F16_Having_Animals_or_Seeds=1;
                   button->setEnabled(false);
               }
           }

          if(i==17){

              button->setText("home");
              button->setMinimumSize(60,40);
          }

          if(i==18){

           button->setMinimumSize(50,40);
              button->setText("Kill");
          }
        }
    // clazy:exclude:connect-3arg-lambda
        QObject::connect(&msgBox, &QMessageBox::finished, [&](int result){
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
                   }

                   break;
               case 2:

                   if(F2_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(540, 180);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F2_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 3:

                   if(F3_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1260, 180);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F3_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 4:

                   if(F4_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1650, 180);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F4_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 5:

                   if(F5_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(150, 410);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F5_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 6:

                   if(F6_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(540, 410);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F6_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 7:

                   if(F7_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1260, 410);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F7_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 8:

                   if(F8_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1650, 410);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F8_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 9:

                   if(F9_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(150, 640);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F9_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 10:

                   if(F10_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(540, 640);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F10_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 11:

                   if(F11_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1260, 640);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F11_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 12:

                   if(F12_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1650, 640);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F12_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 13:

                   if(F13_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(150, 870);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F13_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 14:

                   if(F14_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(540, 870);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F14_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 15:

                   if(F15_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1260, 870);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F15_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 16:

                   if(F16_Having_Animals_or_Seeds==0){

                       barley->pushButton->move(1650, 870);
                       barley->pushButton->setParent(this);
                       barley->pushButton->show();
                       F16_Having_Animals_or_Seeds=1;
                   }

                   break;
               case 17:
                   //add to verticall layout
                   ui->Seeds_verticalLayout->addWidget(barley->pushButton);

                   break;
               case 18:
                   // remove pushbutton
                   ui->Seeds_verticalLayout->removeWidget(barley->pushButton);
                   delete barley->pushButton;
                   break;

               default:
                   break;
               }
           }

        });

        msgBox.exec();

       });
}


void Gamepage::on_Farmer_pushButton_clicked()
{
    Farmer * farmer = new Farmer(ui->Farmer_verticalLayout);

    connect(farmer->pushButton, &QPushButton::clicked, this, [this, farmer](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

        // Add custom buttons
        QHash<QAbstractButton*, int> buttonMap;
        for (int i = 1; i <= 18; ++i) {
          QPushButton* button = new QPushButton(QString("%1").arg(i));
          msgBox.addButton(button, i == 18 ? QMessageBox::RejectRole : QMessageBox::AcceptRole);
          buttonMap[button] = i;

        //  button->setMinimumSize(56, 40);
           button->setMinimumSize(40, 40);

           if(i==2 && ui->label_2->isHidden()){

               button->setEnabled(false);
           }
           if(i==3 && ui->label_3->isHidden()){

               button->setEnabled(false);
           }
           if(i==4 && ui->label_4->isHidden()){

               button->setEnabled(false);
           }
           if(i==5 && ui->label_5->isHidden()){

               button->setEnabled(false);
           }
           if(i==6 && ui->label_6->isHidden()){

               button->setEnabled(false);
           }
           if(i==7 && ui->label_7->isHidden()){

               button->setEnabled(false);
           }
           if(i==8 && ui->label_8->isHidden()){

               button->setEnabled(false);
           }
           if(i==9 && ui->label_9->isHidden()){

               button->setEnabled(false);
           }
           if(i==10 && ui->label_10->isHidden()){

               button->setEnabled(false);
           }
           if(i==11 && ui->label_11->isHidden()){

               button->setEnabled(false);
           }
           if(i==12 && ui->label_12->isHidden()){

               button->setEnabled(false);
           }
           if(i==13 && ui->label_13->isHidden()){

               button->setEnabled(false);
           }
           if(i==14 && ui->label_14->isHidden()){

               button->setEnabled(false);
           }
           if(i==15 && ui->label_15->isHidden()){

               button->setEnabled(false);
           }
           if(i==16 && ui->label_16->isHidden()){

               button->setEnabled(false);
           }

          if(i==17){

              button->setText("home");
              button->setMinimumSize(60,40);
          }
          if(i==18){

           button->setMinimumSize(50,40);
              button->setText("Kill");
          }
        }
    // clazy:exclude:connect-3arg-lambda
        QObject::connect(&msgBox, &QMessageBox::finished, [&](int result){
           QAbstractButton* clickedButton = msgBox.clickedButton();
           if (clickedButton) {
               int buttonNumber = buttonMap[clickedButton];
               qDebug() << "Clicked button: " << buttonNumber;
               qDebug() << result;

               switch(buttonNumber) {
               case 1:

                   // Perform action for Button 1
                   farmer->pushButton->move(210, 160);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 2:
                   // Perform action for Button 2
                   farmer->pushButton->move(600, 160);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 3:
                   // Perform action for Button 2
                   farmer->pushButton->move(1320, 160);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 4:
                   // Perform action for Button 2
                   farmer->pushButton->move(1710, 160);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 5:
                   // Perform action for Button 2
                   farmer->pushButton->move(210, 390);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 6:
                   // Perform action for Button 2
                   farmer->pushButton->move(600, 390);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 7:
                   // Perform action for Button 2
                   farmer->pushButton->move(1320, 390);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 8:
                   // Perform action for Button 2
                   farmer->pushButton->move(1710, 390);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 9:
                   // Perform action for Button 2
                   farmer->pushButton->move(210, 620);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 10:
                   // Perform action for Button 2
                   farmer->pushButton->move(600, 620);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 11:
                   // Perform action for Button 2
                   farmer->pushButton->move(1320, 620);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 12:
                   // Perform action for Button 2
                   farmer->pushButton->move(1710, 620);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 13:
                   // Perform action for Button 2
                   farmer->pushButton->move(210, 850);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 14:
                   // Perform action for Button 2
                   farmer->pushButton->move(600, 850);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 15:
                   // Perform action for Button 2
                   farmer->pushButton->move(1320, 850);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 16:
                   // Perform action for Button 2
                   farmer->pushButton->move(1710, 850);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 17:
                   //add to verticall layout

                   ui->Farmer_verticalLayout->addWidget(farmer->pushButton);

                   break;
               case 18:
                   // Perform action for Button 2
                   ui->Farmer_verticalLayout->removeWidget(farmer->pushButton);
                   delete farmer->pushButton;
                   break;
               // ... and so on for other buttons
               default:
                   break;
               }
           }
        });

        msgBox.exec();

       });
}


void Gamepage::on_New_farm_pushButton_clicked()
{
    if(ui->label_2->isHidden()){

        ui->label_2->show();

    }else if(ui->label_2->isVisible() && ui->label_3->isHidden()){

        ui->label_3->show();

    }else if(ui->label_3->isVisible() && ui->label_4->isHidden()){

        ui->label_4->show();

    }else if(ui->label_4->isVisible() && ui->label_5->isHidden()){

        ui->label_5->show();

    }else if(ui->label_5->isVisible() && ui->label_6->isHidden()){

        ui->label_6->show();

    }else if(ui->label_6->isVisible() && ui->label_7->isHidden()){

        ui->label_7->show();

    }else if(ui->label_7->isVisible() && ui->label_8->isHidden()){

        ui->label_8->show();

    }else if(ui->label_8->isVisible() && ui->label_9->isHidden()){

        ui->label_9->show();

    }else if(ui->label_9->isVisible() && ui->label_10->isHidden()){

        ui->label_10->show();

    }else if(ui->label_10->isVisible() && ui->label_11->isHidden()){

        ui->label_11->show();

    }else if(ui->label_11->isVisible() && ui->label_12->isHidden()){

        ui->label_12->show();

    }else if(ui->label_12->isVisible() && ui->label_13->isHidden()){

        ui->label_13->show();

    }else if(ui->label_13->isVisible() && ui->label_14->isHidden()){

        ui->label_14->show();

    }else if(ui->label_14->isVisible() && ui->label_15->isHidden()){

        ui->label_15->show();

    }else if(ui->label_15->isVisible() && ui->label_16->isHidden()){

        ui->label_16->show();
    }
}

bool Gamepage::check(QPoint pos)
{
    QList<QPushButton*> buttons =  this->findChildren<QPushButton*>();
    for (QPushButton* button : buttons) {
       if (button->geometry().contains(pos)) {
           // Perform your action here va hast
           return false;
       }
    }

    return true;
}

