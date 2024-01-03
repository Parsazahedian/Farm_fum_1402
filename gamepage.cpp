#include "gamepage.h"
#include "ui_gamepage.h"
#include "QDebug"
#include "chicken.h"
#include "sheep.h"
#include "cow.h"
#include "wheat.h"
#include "barley.h"
#include "farmer.h"

Gamepage::Gamepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamepage)
{
    ui->setupUi(this);

    setMinimumSize(1908,978);
    setMaximumSize(1908,978);

    ui->groupBox->hide();
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
}


void Gamepage::on_Sheep_pushButton_clicked()
{
    Sheep * sheep = new Sheep(ui->Animals_verticalLayout);
}


void Gamepage::on_Cow_pushButton_clicked()
{
    Cow * cow = new Cow(ui->Animals_verticalLayout);
}


void Gamepage::on_Wheat_pushButton_clicked()
{
    Wheat * wheat = new Wheat(ui->Seeds_verticalLayout);
}


void Gamepage::on_Barley_pushButton_clicked()
{
    Barley * barley = new Barley(ui->Seeds_verticalLayout);
}


void Gamepage::on_Farmer_pushButton_clicked()
{
    Farmer * farmer = new Farmer(ui->Farmer_verticalLayout);
}

