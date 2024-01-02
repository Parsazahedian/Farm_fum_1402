#include "barley.h"

Barley::Barley(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton("Barley");
    QSize buttonSize(50, 50);
    pushButton->setFixedSize(buttonSize);
    Product_production_time = 20;
    Product_Collection_Point = 2;
    Purchase_price= 2;
    Product_Collection_Delay_time = 10;
    BaseLayout->addWidget(pushButton);
}
