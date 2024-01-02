#include "wheat.h"
#include "QDebug"

Wheat::Wheat(QVBoxLayout* BaseLayout)
{
    pushButton = new QPushButton("Wheat");
    QSize buttonSize(50, 50);
    pushButton->setFixedSize(buttonSize);
    Product_production_time = 25;
    Product_Collection_Point = 3;
    Purchase_price= 2;
    Product_Collection_Delay_time = 12;
    BaseLayout->addWidget(pushButton);
}
