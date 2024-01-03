#include "gamepage.h"
#include "ui_gamepage.h"
#include "QDebug"

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

void Gamepage::on_pushButton_clicked()
{
    if(ui->groupBox->isVisible()){

        ui->groupBox->hide();
        qDebug() << "hideee";
    }else
    if(ui->groupBox->isHidden()){

        ui->groupBox->show();
        qDebug() << "showww";
    }
}

