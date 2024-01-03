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

//          if (i == 1 || i == 5) {
//                 button->setEnabled(false);
//             }

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
                   ch->pushButton->move(500, 100);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 2:
                   // Perform action for Button 2
                   ch->pushButton->move(400, 100);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 3:
                   // Perform action for Button 2
                   ch->pushButton->move(300, 100);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 4:
                   // Perform action for Button 2
                   ch->pushButton->move(200, 100);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 5:
                   // Perform action for Button 2
                   ch->pushButton->move(500, 200);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 6:
                   // Perform action for Button 2
                   ch->pushButton->move(500, 600);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 7:
                   // Perform action for Button 2
                   ch->pushButton->move(500, 600);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 8:
                   // Perform action for Button 2
                   ch->pushButton->move(550, 160);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 9:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 10:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 11:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 12:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 13:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 14:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 15:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 16:
                   // Perform action for Button 2
                   ch->pushButton->move(480, 410);
                   ch->pushButton->setParent(this);
                   ch->pushButton->show();

                   break;
               case 17:
                   //add to verticall layout

                   ui->Animals_verticalLayout->addWidget(ch->pushButton);

                   break;
               case 18:
                   // Perform action for Button 2
                   ui->Animals_verticalLayout->removeWidget(ch->pushButton);
                   delete ch->pushButton;
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

//          if (i == 1 || i == 5) {
//                 button->setEnabled(false);
//             }

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
                   sheep->pushButton->move(500, 100);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 2:
                   // Perform action for Button 2
                   sheep->pushButton->move(400, 100);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 3:
                   // Perform action for Button 2
                   sheep->pushButton->move(300, 100);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 4:
                   // Perform action for Button 2
                   sheep->pushButton->move(200, 100);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 5:
                   // Perform action for Button 2
                   sheep->pushButton->move(500, 200);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 6:
                   // Perform action for Button 2
                   sheep->pushButton->move(500, 600);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 7:
                   // Perform action for Button 2
                   sheep->pushButton->move(500, 600);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 8:
                   // Perform action for Button 2
                   sheep->pushButton->move(550, 160);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 9:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 10:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 11:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 12:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 13:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 14:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 15:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 16:
                   // Perform action for Button 2
                   sheep->pushButton->move(480, 410);
                   sheep->pushButton->setParent(this);
                   sheep->pushButton->show();

                   break;
               case 17:
                   //add to verticall layout

                   ui->Animals_verticalLayout->addWidget(sheep->pushButton);

                   break;
               case 18:
                   // Perform action for Button 2
                   ui->Animals_verticalLayout->removeWidget(sheep->pushButton);
                   delete sheep->pushButton;
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

//          if (i == 1 || i == 5) {
//                 button->setEnabled(false);
//             }

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
                   cow->pushButton->move(500, 100);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 2:
                   // Perform action for Button 2
                   cow->pushButton->move(400, 100);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 3:
                   // Perform action for Button 2
                   cow->pushButton->move(300, 100);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 4:
                   // Perform action for Button 2
                   cow->pushButton->move(200, 100);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 5:
                   // Perform action for Button 2
                   cow->pushButton->move(500, 200);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 6:
                   // Perform action for Button 2
                   cow->pushButton->move(500, 600);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 7:
                   // Perform action for Button 2
                   cow->pushButton->move(500, 600);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 8:
                   // Perform action for Button 2
                   cow->pushButton->move(550, 160);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 9:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 10:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 11:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 12:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 13:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 14:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 15:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 16:
                   // Perform action for Button 2
                   cow->pushButton->move(480, 410);
                   cow->pushButton->setParent(this);
                   cow->pushButton->show();

                   break;
               case 17:
                   //add to verticall layout

                   ui->Animals_verticalLayout->addWidget(cow->pushButton);

                   break;
               case 18:
                   // Perform action for Button 2
                   ui->Animals_verticalLayout->removeWidget(cow->pushButton);
                   delete cow->pushButton;
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

//          if (i == 1 || i == 5) {
//                 button->setEnabled(false);
//             }

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
                   wheat->pushButton->move(500, 100);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 2:
                   // Perform action for Button 2
                   wheat->pushButton->move(400, 100);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 3:
                   // Perform action for Button 2
                   wheat->pushButton->move(300, 100);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 4:
                   // Perform action for Button 2
                   wheat->pushButton->move(200, 100);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 5:
                   // Perform action for Button 2
                   wheat->pushButton->move(500, 200);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 6:
                   // Perform action for Button 2
                   wheat->pushButton->move(500, 600);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 7:
                   // Perform action for Button 2
                   wheat->pushButton->move(500, 600);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 8:
                   // Perform action for Button 2
                   wheat->pushButton->move(550, 160);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 9:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 10:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 11:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 12:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 13:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 14:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 15:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 16:
                   // Perform action for Button 2
                   wheat->pushButton->move(480, 410);
                   wheat->pushButton->setParent(this);
                   wheat->pushButton->show();

                   break;
               case 17:
                   //add to verticall layout

                   ui->Seeds_verticalLayout->addWidget(wheat->pushButton);

                   break;
               case 18:
                   // Perform action for Button 2
                   ui->Seeds_verticalLayout->removeWidget(wheat->pushButton);
                   delete wheat->pushButton;
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

//          if (i == 1 || i == 5) {
//                 button->setEnabled(false);
//             }

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
                   barley->pushButton->move(500, 100);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 2:
                   // Perform action for Button 2
                   barley->pushButton->move(400, 100);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 3:
                   // Perform action for Button 2
                   barley->pushButton->move(300, 100);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 4:
                   // Perform action for Button 2
                   barley->pushButton->move(200, 100);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 5:
                   // Perform action for Button 2
                   barley->pushButton->move(500, 200);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 6:
                   // Perform action for Button 2
                   barley->pushButton->move(500, 600);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 7:
                   // Perform action for Button 2
                   barley->pushButton->move(500, 600);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 8:
                   // Perform action for Button 2
                   barley->pushButton->move(550, 160);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 9:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 10:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 11:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 12:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 13:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 14:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 15:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 16:
                   // Perform action for Button 2
                   barley->pushButton->move(480, 410);
                   barley->pushButton->setParent(this);
                   barley->pushButton->show();

                   break;
               case 17:
                   //add to verticall layout

                   ui->Seeds_verticalLayout->addWidget(barley->pushButton);

                   break;
               case 18:
                   // Perform action for Button 2
                   ui->Seeds_verticalLayout->removeWidget(barley->pushButton);
                   delete barley->pushButton;
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

//          if (i == 1 || i == 5) {
//                 button->setEnabled(false);
//             }

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
                   farmer->pushButton->move(500, 100);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 2:
                   // Perform action for Button 2
                   farmer->pushButton->move(400, 100);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 3:
                   // Perform action for Button 2
                   farmer->pushButton->move(300, 100);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 4:
                   // Perform action for Button 2
                   farmer->pushButton->move(200, 100);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 5:
                   // Perform action for Button 2
                   farmer->pushButton->move(500, 200);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 6:
                   // Perform action for Button 2
                   farmer->pushButton->move(500, 600);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 7:
                   // Perform action for Button 2
                   farmer->pushButton->move(500, 600);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 8:
                   // Perform action for Button 2
                   farmer->pushButton->move(550, 160);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 9:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 10:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 11:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 12:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 13:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 14:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 15:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
                   farmer->pushButton->setParent(this);
                   farmer->pushButton->show();

                   break;
               case 16:
                   // Perform action for Button 2
                   farmer->pushButton->move(480, 410);
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

