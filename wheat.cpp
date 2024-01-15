#include "wheat.h"
#include "QDebug"

Wheat::Wheat(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton();
    QSize buttonSize(50, 50);
    pushButton->setFixedSize(buttonSize);
    pushButton->setStyleSheet("border-image: url(C:/Users/i/Downloads/wheat (1).png);");
    Product_production_time = 25;
    Product_Collection_Point = 3;
    Purchase_price= 2;
    Product_Collection_Delay_time = 12;
    BaseLayout->addWidget(pushButton);
}
