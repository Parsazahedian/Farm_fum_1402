#include "gamepage.h"
#include "ui_gamepage.h"

Gamepage::Gamepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamepage)
{
    ui->setupUi(this);

    setMinimumSize(1908,978);
    setMaximumSize(1908,978);
}

Gamepage::~Gamepage()
{
    delete ui;
}
