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

int score=10;

Chicken * ch1; Sheep * sheep1; Cow * cow1;  Wheat * wheat1;  Barley * barley1;

Gamepage::Gamepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamepage)
{
    ui->setupUi(this);

    Move_the_product_of_Animals_and_seeds_pushButton();

    Hide_the_product_of_Animals_and_seeds_pushButton();

    Hide_Timer_labels();

    Hide_Start_pushbuttuns();

    Hide_Cancel_pushbuttons();

    Hide_Farms();

    setMinimumSize(1908,978);
    setMaximumSize(1908,978);

    ui->groupBox->hide();

    ui->decrease_point_label->hide();

    ui->label_Score->setText( "Score :" + QString::number(score));

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

    ch->pushButton->setObjectName("Chicken");

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
               Get_info();
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



}

void Gamepage::on_Sheep_pushButton_clicked()
{
    Sheep * sheep = new Sheep(ui->Animals_verticalLayout);

    sheep->pushButton->setObjectName("Sheep");

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
}

void Gamepage::on_Cow_pushButton_clicked()
{
    Cow * cow = new Cow(ui->Animals_verticalLayout);

    cow->pushButton->setObjectName("Cow");

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
}

void Gamepage::on_Wheat_pushButton_clicked()
{
    Wheat * wheat = new Wheat(ui->Seeds_verticalLayout);

    wheat->pushButton->setObjectName("Wheat");

    connect(wheat->pushButton, &QPushButton::clicked, this, [this, wheat](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

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

              button->setText("home");
              button->setMinimumSize(60,40);
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
}

void Gamepage::on_Barley_pushButton_clicked()
{
    Barley * barley = new Barley(ui->Seeds_verticalLayout);

    barley->pushButton->setObjectName("Barley");

    connect(barley->pushButton, &QPushButton::clicked, this, [this, barley](){ QMessageBox msgBox;
        msgBox.setText("chicken""<ul>""<li>""@gmail.com""</li>" "<li>""@email.com""</li>" "<li>""@mail.um.ac""</li>""</ul>");
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowSystemMenuHint);

        msgBox.setWindowTitle("Transfer to ...");

        // Set the icon
        msgBox.setWindowIcon(QIcon("C:/Users/i/Downloads/iran.png"));

        msgBox.setIconPixmap(QPixmap("C:/Users/i/Downloads/iran.png"));

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

              button->setText("home");
              button->setMinimumSize(60,40);
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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
               if(check(pos)==false){

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
        QObject::connect(&msgBox, &QMessageBox::finished, [&](int result){
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
        if(F1_Having_Farmer==1 && F1_Having_Animals_or_Seeds==1){

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
        if(F2_Having_Farmer==1 && F2_Having_Animals_or_Seeds==1){

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
        if(F3_Having_Farmer==1 && F3_Having_Animals_or_Seeds==1){

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
        if(F4_Having_Farmer==1 && F4_Having_Animals_or_Seeds==1){

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
        if(F5_Having_Farmer==1 && F5_Having_Animals_or_Seeds==1){

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
        if(F6_Having_Farmer==1 && F6_Having_Animals_or_Seeds==1){

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
        if(F7_Having_Farmer==1 && F7_Having_Animals_or_Seeds==1){

            ui->Start_2->show();
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
        if(F8_Having_Farmer==1 && F8_Having_Animals_or_Seeds==1){

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
        if(F9_Having_Farmer==1 && F9_Having_Animals_or_Seeds==1){

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
        if(F10_Having_Farmer==1 && F10_Having_Animals_or_Seeds==1){

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
        if(F11_Having_Farmer==1 && F11_Having_Animals_or_Seeds==1){

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
        if(F12_Having_Farmer==1 && F12_Having_Animals_or_Seeds==1){

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
        if(F13_Having_Farmer==1 && F13_Having_Animals_or_Seeds==1){

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
        if(F14_Having_Farmer==1 && F14_Having_Animals_or_Seeds==1){

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
        if(F15_Having_Farmer==1 && F15_Having_Animals_or_Seeds==1){

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
        if(F16_Having_Farmer==1 && F16_Having_Animals_or_Seeds==1){

            ui->Start_16->show();
        }else if(F16_Having_Farmer==1 && F16_Having_Animals_or_Seeds==0){

            ui->Start_16->hide();
        }
    }
}

QPushButton * Gamepage::check2(QPoint pos)
{
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
       for (QPushButton* button : buttons) {
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

       } else if (buttonAtPos->objectName() == "Sheep") {
           F1_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos->objectName() == "Cow") {
           F1_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos->objectName() == "Wheat") {
           F1_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos->objectName() == "Barley") {
           F1_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos2->objectName() == "Sheep") {
           F2_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos2->objectName() == "Cow") {
           F2_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos2->objectName() == "Wheat") {
           F2_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos2->objectName() == "Barley") {
           F2_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos3->objectName() == "Sheep") {
           F3_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos3->objectName() == "Cow") {
           F3_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos3->objectName() == "Wheat") {
           F3_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos3->objectName() == "Barley") {
           F3_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos4->objectName() == "Sheep") {
           F4_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos4->objectName() == "Cow") {
           F4_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos4->objectName() == "Wheat") {
           F4_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos4->objectName() == "Barley") {
           F4_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos5->objectName() == "Sheep") {
           F5_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos5->objectName() == "Cow") {
           F5_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos5->objectName() == "Wheat") {
           F5_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos5->objectName() == "Barley") {
           F5_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos6->objectName() == "Sheep") {
           F6_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos6->objectName() == "Cow") {
           F6_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos6->objectName() == "Wheat") {
           F6_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos6->objectName() == "Barley") {
           F6_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos7->objectName() == "Sheep") {
           F7_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos7->objectName() == "Cow") {
           F7_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos7->objectName() == "Wheat") {
           F7_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos7->objectName() == "Barley") {
           F7_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos8->objectName() == "Sheep") {
           F8_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos8->objectName() == "Cow") {
           F8_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos8->objectName() == "Wheat") {
           F8_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos8->objectName() == "Barley") {
           F8_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos9->objectName() == "Sheep") {
           F9_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos9->objectName() == "Cow") {
           F9_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos9->objectName() == "Wheat") {
           F9_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos9->objectName() == "Barley") {
           F9_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos10->objectName() == "Sheep") {
           F10_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos10->objectName() == "Cow") {
           F10_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos10->objectName() == "Wheat") {
           F10_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos10->objectName() == "Barley") {
           F10_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos11->objectName() == "Sheep") {
           F11_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos11->objectName() == "Cow") {
           F11_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos11->objectName() == "Wheat") {
           F11_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos11->objectName() == "Barley") {
           F11_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos12->objectName() == "Sheep") {
           F12_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos12->objectName() == "Cow") {
           F12_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos12->objectName() == "Wheat") {
           F12_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos12->objectName() == "Barley") {
           F12_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos13->objectName() == "Sheep") {
           F13_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos13->objectName() == "Cow") {
           F13_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos13->objectName() == "Wheat") {
           F13_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos13->objectName() == "Barley") {
           F13_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos14->objectName() == "Sheep") {
           F14_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos14->objectName() == "Cow") {
           F14_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos14->objectName() == "Wheat") {
           F14_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos14->objectName() == "Barley") {
           F14_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos15->objectName() == "Sheep") {
           F15_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos15->objectName() == "Cow") {
           F15_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos15->objectName() == "Wheat") {
           F15_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos15->objectName() == "Barley") {
           F15_Which_Of_Animals_or_Seeds=5;

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

       } else if (buttonAtPos16->objectName() == "Sheep") {
           F16_Which_Of_Animals_or_Seeds=2;

       } else if (buttonAtPos16->objectName() == "Cow") {
           F16_Which_Of_Animals_or_Seeds=3;

       } else if (buttonAtPos16->objectName() == "Wheat") {
           F16_Which_Of_Animals_or_Seeds=4;

       } else if (buttonAtPos16->objectName() == "Barley") {
           F16_Which_Of_Animals_or_Seeds=5;

       }
    }else if(buttonAtPos16 == nullptr){

        F16_Which_Of_Animals_or_Seeds=0;
        F16_Having_Animals_or_Seeds=0;
    }

    check_our_farm_have_farmer_or_not();

}

void Gamepage::on_Start_clicked()
{
    ui->Start->hide();
    ui->Cancel->show();
    ui->timer_label->show();

    QPoint Pos(150, 180);

    QPoint Pos2(210, 160);

    ch1 = new Chicken(ui->verticalLayout);
    sheep1 = new Sheep(ui->verticalLayout);
    cow1 = new Cow(ui->verticalLayout);
    wheat1 = new Wheat(ui->verticalLayout);
    barley1 = new Barley(ui->verticalLayout);

    QPushButton* buttonAtPos = this->check2(Pos);
    QPushButton* buttonAtPos2 = this->check2(Pos2);
    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {
           ch1->SetTimerLabel(ui->timer_label);
           ch1->Set_Product_Pushbutton(ui->the_product_of_chicken_pushButton);
           ch1->Set_Cancel_Pushbutton(ui->Cancel);
           ch1->Set_Start_Pushbutton(ui->Start);
           ch1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           ch1->Set_Farmer_Pushbutton(buttonAtPos2);
           ch1->Set_decrease_label(ui->decrease_point_label);
           ch1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Sheep") {
           sheep1->SetTimerLabel(ui->timer_label);
           sheep1->Set_Product_Pushbutton(ui->the_product_of_sheep_pushButton);
           sheep1->Set_Cancel_Pushbutton(ui->Cancel);
           sheep1->Set_Start_Pushbutton(ui->Start);
           sheep1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           sheep1->Set_Farmer_Pushbutton(buttonAtPos2);
           sheep1->Set_decrease_label(ui->decrease_point_label);
           sheep1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Cow") {
           cow1->SetTimerLabel(ui->timer_label);
           cow1->Set_Product_Pushbutton(ui->the_product_of_cow_pushButton);
           cow1->Set_Cancel_Pushbutton(ui->Cancel);
           cow1->Set_Start_Pushbutton(ui->Start);
           cow1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           cow1->Set_Farmer_Pushbutton(buttonAtPos2);
           cow1->Set_decrease_label(ui->decrease_point_label);
           cow1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Wheat") {
           wheat1->SetTimerLabel(ui->timer_label);
           wheat1->Set_Product_Pushbutton(ui->the_product_of_wheat_pushButton);
           wheat1->Set_Cancel_Pushbutton(ui->Cancel);
           wheat1->Set_Start_Pushbutton(ui->Start);
           wheat1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           wheat1->Set_Farmer_Pushbutton(buttonAtPos2);
           wheat1->Set_decrease_label(ui->decrease_point_label);
           wheat1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       } else if (buttonAtPos->objectName() == "Barley") {
           barley1->SetTimerLabel(ui->timer_label);
           barley1->Set_Product_Pushbutton(ui->the_product_of_barley_pushButton);
           barley1->Set_Cancel_Pushbutton(ui->Cancel);
           barley1->Set_Start_Pushbutton(ui->Start);
           barley1->Set_Animals_or_Seeds_Pushbutton(buttonAtPos);
           barley1->Set_Farmer_Pushbutton(buttonAtPos2);
           barley1->Set_decrease_label(ui->decrease_point_label);
           barley1->TurnTimerOn();
           buttonAtPos->setEnabled(false);

       }
    }
    buttonAtPos2->setEnabled(false);

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

    ui->Cancel->hide();
    ui->Start->show();

    ui->timer_label->hide();

    QPoint Pos(150, 180);


    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

       if (buttonAtPos->objectName() == "Chicken") {

           buttonAtPos->setEnabled(true);

           ch1->Stop_animation();
           ch1->Timer_Stop();
           ch1->Timer2_Stop();

       } else if (buttonAtPos->objectName() == "Sheep") {

           buttonAtPos->setEnabled(true);

           sheep1->Stop_animation();
           sheep1->Timer_Stop();
           sheep1->Timer2_Stop();

       } else if (buttonAtPos->objectName() == "Cow") {

           buttonAtPos->setEnabled(true);

           cow1->Stop_animation();
           cow1->Timer_Stop();
           cow1->Timer2_Stop();

       } else if (buttonAtPos->objectName() == "Wheat") {

           buttonAtPos->setEnabled(true);

           wheat1->Stop_animation();
           wheat1->Timer_Stop();
           wheat1->Timer2_Stop();

       } else if (buttonAtPos->objectName() == "Barley") {

           buttonAtPos->setEnabled(true);

           barley1->Stop_animation();
           barley1->Timer_Stop();
           barley1->Timer2_Stop();

       }
    }

    clearLayout(ui->verticalLayout);
}

void Gamepage::on_the_product_of_chicken_pushButton_clicked()
{
    score = score + (ch1->Product_Collection_Point);
    ui->label_Score->setText( "Score :" + QString::number(score));
    ui->the_product_of_chicken_pushButton->hide();
    ch1->Timer2_Stop();
    ui->Start->show();
    ui->decrease_point_label->hide();
}

void Gamepage::on_the_product_of_sheep_pushButton_clicked()
{
    score = score + (sheep1->Product_Collection_Point);
    ui->label_Score->setText( "Score :" + QString::number(score));
    ui->the_product_of_sheep_pushButton->hide();
    sheep1->Timer2_Stop();
    ui->Start->show();
    ui->decrease_point_label->hide();
}

void Gamepage::on_the_product_of_cow_pushButton_clicked()
{
    score = score + (cow1->Product_Collection_Point);
    ui->label_Score->setText( "Score :" + QString::number(score));
    ui->the_product_of_cow_pushButton->hide();
    cow1->Timer2_Stop();
    ui->Start->show();
    ui->decrease_point_label->hide();
}

void Gamepage::on_the_product_of_wheat_pushButton_clicked()
{
    score = score + (wheat1->Product_Collection_Point);
    ui->label_Score->setText( "Score :" + QString::number(score));
    ui->the_product_of_wheat_pushButton->hide();
    wheat1->Timer2_Stop();
    ui->Start->show();

    QPoint Pos(150, 180);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

        if (buttonAtPos->objectName() == "Wheat") {

            delete  buttonAtPos;

            Get_info();
        }
    }
    ui->decrease_point_label->hide();
}

void Gamepage::on_the_product_of_barley_pushButton_clicked()
{
    score = score + (barley1->Product_Collection_Point);
    ui->label_Score->setText( "Score :" + QString::number(score));
    ui->the_product_of_barley_pushButton->hide();
    barley1->Timer2_Stop();
    ui->Start->show();

    QPoint Pos(150, 180);

    QPushButton* buttonAtPos = this->check2(Pos);

    if (buttonAtPos != nullptr) {

         if (buttonAtPos->objectName() == "Barley") {

            delete  buttonAtPos;

             Get_info();
         }
    }
    ui->decrease_point_label->hide();
}

void Gamepage::Move_the_product_of_Animals_and_seeds_pushButton()
{
    ui->the_product_of_sheep_pushButton->move(160, 140);
    ui->the_product_of_cow_pushButton->move(160, 140);
    ui->the_product_of_wheat_pushButton->move(160, 140);
    ui->the_product_of_barley_pushButton->move(160, 140);

    ui->the_product_of_sheep_pushButton_2->move(550, 140);
    ui->the_product_of_cow_pushButton_2->move(550, 140);
    ui->the_product_of_wheat_pushButton_2->move(550, 140);
    ui->the_product_of_barley_pushButton_2->move(550, 140);

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

