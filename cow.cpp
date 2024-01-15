#include "cow.h"

Cow::Cow(QVBoxLayout *BaseLayout)
{
    pushButton = new QPushButton();
    QSize buttonSize(50, 50);
    pushButton->setFixedSize(buttonSize);
    pushButton->setStyleSheet("border-image: url(C:/Users/i/Downloads/cow.png);");
    Product_production_time = 20;
    Price_of_meat = 6;
    Product_Collection_Point = 5;
    Purchase_price = 7;
    Product_Collection_Delay_time = 3;
    BaseLayout->addWidget(pushButton);
}
