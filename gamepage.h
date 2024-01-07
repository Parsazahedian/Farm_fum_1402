#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QMainWindow>
#include "QPushButton"
#include "QLayoutItem"
#include "QLayout"
#include "animals.h"
#include "chicken.h"
#include "sheep.h"
#include "cow.h"
#include "wheat.h"
#include "barley.h"

extern Chicken * ch1; extern Sheep * sheep1; extern Cow * cow1; extern Wheat * wheat1; extern Barley * barley1;

namespace Ui {
class Gamepage;
}

class Gamepage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gamepage(QWidget *parent = nullptr);
    ~Gamepage();

private slots:
    void on_Shop_pushButton_clicked();

    void on_Chicken_pushButton_clicked();

    void on_Sheep_pushButton_clicked();

    void on_Cow_pushButton_clicked();

    void on_Wheat_pushButton_clicked();

    void on_Barley_pushButton_clicked();

    void on_Farmer_pushButton_clicked();

    void on_New_farm_pushButton_clicked();

    bool check(QPoint pos);

    void check_our_farm_have_farmer_or_not();

    QPushButton * check2(QPoint pos);

    void Get_info();

    void on_Start_clicked();

    void clearLayout(QLayout *layout);

    void on_Cancel_clicked();

    void on_the_product_of_chicken_pushButton_clicked();

    void on_the_product_of_sheep_pushButton_clicked();

    void on_the_product_of_cow_pushButton_clicked();

    void on_the_product_of_wheat_pushButton_clicked();

    void on_the_product_of_barley_pushButton_clicked();

private:
    Ui::Gamepage *ui;

    int F1_Having_Farmer=0, F1_Having_Animals_or_Seeds=0;
    int F2_Having_Farmer=0, F2_Having_Animals_or_Seeds=0;
    int F3_Having_Farmer=0, F3_Having_Animals_or_Seeds=0;
    int F4_Having_Farmer=0, F4_Having_Animals_or_Seeds=0;
    int F5_Having_Farmer=0, F5_Having_Animals_or_Seeds=0;
    int F6_Having_Farmer=0, F6_Having_Animals_or_Seeds=0;
    int F7_Having_Farmer=0, F7_Having_Animals_or_Seeds=0;
    int F8_Having_Farmer=0, F8_Having_Animals_or_Seeds=0;
    int F9_Having_Farmer=0, F9_Having_Animals_or_Seeds=0;
    int F10_Having_Farmer=0, F10_Having_Animals_or_Seeds=0;
    int F11_Having_Farmer=0, F11_Having_Animals_or_Seeds=0;
    int F12_Having_Farmer=0, F12_Having_Animals_or_Seeds=0;
    int F13_Having_Farmer=0, F13_Having_Animals_or_Seeds=0;
    int F14_Having_Farmer=0, F14_Having_Animals_or_Seeds=0;
    int F15_Having_Farmer=0, F15_Having_Animals_or_Seeds=0;
    int F16_Having_Farmer=0, F16_Having_Animals_or_Seeds=0;

    //Fn_Which_Of_Animals_or_Seeds=0 -> home or kill
    //Fn_Which_Of_Animals_or_Seeds=1 -> chicken
    //Fn_Which_Of_Animals_or_Seeds=2 -> sheep
    //Fn_Which_Of_Animals_or_Seeds=3 -> cow
    //Fn_Which_Of_Animals_or_Seeds=4 -> wheat
    //Fn_Which_Of_Animals_or_Seeds=5 -> barley
    int F1_Which_Of_Animals_or_Seeds=0;
    int F2_Which_Of_Animals_or_Seeds=0;
    int F3_Which_Of_Animals_or_Seeds=0;
    int F4_Which_Of_Animals_or_Seeds=0;
    int F5_Which_Of_Animals_or_Seeds=0;
    int F6_Which_Of_Animals_or_Seeds=0;
    int F7_Which_Of_Animals_or_Seeds=0;
    int F8_Which_Of_Animals_or_Seeds=0;
    int F9_Which_Of_Animals_or_Seeds=0;
    int F10_Which_Of_Animals_or_Seeds=0;
    int F11_Which_Of_Animals_or_Seeds=0;
    int F12_Which_Of_Animals_or_Seeds=0;
    int F13_Which_Of_Animals_or_Seeds=0;
    int F14_Which_Of_Animals_or_Seeds=0;
    int F15_Which_Of_Animals_or_Seeds=0;
    int F16_Which_Of_Animals_or_Seeds=0;

};

#endif // GAMEPAGE_H
