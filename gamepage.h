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
#include "QSqlDatabase"
#include "QMediaPlayer"

extern Chicken * ch1; extern Sheep * sheep1; extern Cow * cow1; extern Wheat * wheat1; extern Barley * barley1;
extern Chicken * ch2; extern Sheep * sheep2; extern Cow * cow2; extern Wheat * wheat2; extern Barley * barley2;
extern Chicken * ch3; extern Sheep * sheep3; extern Cow * cow3; extern Wheat * wheat3; extern Barley * barley3;
extern Chicken * ch4; extern Sheep * sheep4; extern Cow * cow4; extern Wheat * wheat4; extern Barley * barley4;
extern Chicken * ch5; extern Sheep * sheep5; extern Cow * cow5; extern Wheat * wheat5; extern Barley * barley5;
extern Chicken * ch6; extern Sheep * sheep6; extern Cow * cow6; extern Wheat * wheat6; extern Barley * barley6;
extern Chicken * ch7; extern Sheep * sheep7; extern Cow * cow7; extern Wheat * wheat7; extern Barley * barley7;
extern Chicken * ch8; extern Sheep * sheep8; extern Cow * cow8; extern Wheat * wheat8; extern Barley * barley8;
extern Chicken * ch9; extern Sheep * sheep9; extern Cow * cow9; extern Wheat * wheat9; extern Barley * barley9;
extern Chicken * ch10; extern Sheep * sheep10; extern Cow * cow10; extern Wheat * wheat10; extern Barley * barley10;
extern Chicken * ch11; extern Sheep * sheep11; extern Cow * cow11; extern Wheat * wheat11; extern Barley * barley11;
extern Chicken * ch12; extern Sheep * sheep12; extern Cow * cow12; extern Wheat * wheat12; extern Barley * barley12;
extern Chicken * ch13; extern Sheep * sheep13; extern Cow * cow13; extern Wheat * wheat13; extern Barley * barley13;
extern Chicken * ch14; extern Sheep * sheep14; extern Cow * cow14; extern Wheat * wheat14; extern Barley * barley14;
extern Chicken * ch15; extern Sheep * sheep15; extern Cow * cow15; extern Wheat * wheat15; extern Barley * barley15;
extern Chicken * ch16; extern Sheep * sheep16; extern Cow * cow16; extern Wheat * wheat16; extern Barley * barley16;

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

    void Timer();

    void Timer_2();

    void For_Repeated();

    void setCursorForAllButtons(QWidget *widget);

    void Set_window_to_the_default();

    void Delete_all_created_pushbuttos(QWidget* parent, const QString& name);

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

    void clearLayout(QLayout *layout);

    void Move_the_product_of_Animals_and_seeds_pushButton();

    void Hide_the_product_of_Animals_and_seeds_pushButton();

    void Hide_label_of_timers();

    void Hide_Timer_labels();

    void Hide_Start_pushbuttuns();

    void Hide_Cancel_pushbuttons();

    void Hide_Farms();

    void Hide_Feilds_number_label();

    void Hide_decrease_label();

    void Default_farmer();

    void on_Start_clicked();
    void on_Cancel_clicked();
    void on_the_product_of_chicken_pushButton_clicked();
    void on_the_product_of_sheep_pushButton_clicked();
    void on_the_product_of_cow_pushButton_clicked();
    void on_the_product_of_wheat_pushButton_clicked();
    void on_the_product_of_barley_pushButton_clicked();

    void on_Start_2_clicked();
    void on_Cancel_2_clicked();
    void on_the_product_of_chicken_pushButton_2_clicked();
    void on_the_product_of_sheep_pushButton_2_clicked();
    void on_the_product_of_cow_pushButton_2_clicked();
    void on_the_product_of_wheat_pushButton_2_clicked();
    void on_the_product_of_barley_pushButton_2_clicked();

    void on_Start_3_clicked();
    void on_Cancel_3_clicked();
    void on_the_product_of_chicken_pushButton_3_clicked();
    void on_the_product_of_sheep_pushButton_3_clicked();
    void on_the_product_of_cow_pushButton_3_clicked();
    void on_the_product_of_wheat_pushButton_3_clicked();
    void on_the_product_of_barley_pushButton_3_clicked();

    void on_Start_4_clicked();
    void on_Cancel_4_clicked();
    void on_the_product_of_chicken_pushButton_4_clicked();
    void on_the_product_of_sheep_pushButton_4_clicked();
    void on_the_product_of_cow_pushButton_4_clicked();
    void on_the_product_of_wheat_pushButton_4_clicked();
    void on_the_product_of_barley_pushButton_4_clicked();

    void on_Start_5_clicked();
    void on_Cancel_5_clicked();
    void on_the_product_of_chicken_pushButton_5_clicked();
    void on_the_product_of_sheep_pushButton_5_clicked();
    void on_the_product_of_cow_pushButton_5_clicked();
    void on_the_product_of_wheat_pushButton_5_clicked();
    void on_the_product_of_barley_pushButton_5_clicked();

    void on_Start_6_clicked();
    void on_Cancel_6_clicked();
    void on_the_product_of_chicken_pushButton_6_clicked();
    void on_the_product_of_sheep_pushButton_6_clicked();
    void on_the_product_of_cow_pushButton_6_clicked();
    void on_the_product_of_wheat_pushButton_6_clicked();
    void on_the_product_of_barley_pushButton_6_clicked();

    void on_Start_7_clicked();
    void on_Cancel_7_clicked();
    void on_the_product_of_chicken_pushButton_7_clicked();
    void on_the_product_of_sheep_pushButton_7_clicked();
    void on_the_product_of_cow_pushButton_7_clicked();
    void on_the_product_of_wheat_pushButton_7_clicked();
    void on_the_product_of_barley_pushButton_7_clicked();

    void on_Start_8_clicked();
    void on_Cancel_8_clicked();
    void on_the_product_of_chicken_pushButton_8_clicked();
    void on_the_product_of_sheep_pushButton_8_clicked();
    void on_the_product_of_cow_pushButton_8_clicked();
    void on_the_product_of_wheat_pushButton_8_clicked();
    void on_the_product_of_barley_pushButton_8_clicked();

    void on_Start_9_clicked();
    void on_Cancel_9_clicked();
    void on_the_product_of_chicken_pushButton_9_clicked();
    void on_the_product_of_sheep_pushButton_9_clicked();
    void on_the_product_of_cow_pushButton_9_clicked();
    void on_the_product_of_wheat_pushButton_9_clicked();
    void on_the_product_of_barley_pushButton_9_clicked();

    void on_Start_10_clicked();
    void on_Cancel_10_clicked();
    void on_the_product_of_chicken_pushButton_10_clicked();
    void on_the_product_of_sheep_pushButton_10_clicked();
    void on_the_product_of_cow_pushButton_10_clicked();
    void on_the_product_of_wheat_pushButton_10_clicked();
    void on_the_product_of_barley_pushButton_10_clicked();

    void on_Start_11_clicked();
    void on_Cancel_11_clicked();
    void on_the_product_of_chicken_pushButton_11_clicked();
    void on_the_product_of_sheep_pushButton_11_clicked();
    void on_the_product_of_cow_pushButton_11_clicked();
    void on_the_product_of_wheat_pushButton_11_clicked();
    void on_the_product_of_barley_pushButton_11_clicked();

    void on_Start_12_clicked();
    void on_Cancel_12_clicked();
    void on_the_product_of_chicken_pushButton_12_clicked();
    void on_the_product_of_sheep_pushButton_12_clicked();
    void on_the_product_of_cow_pushButton_12_clicked();
    void on_the_product_of_wheat_pushButton_12_clicked();
    void on_the_product_of_barley_pushButton_12_clicked();

    void on_Start_13_clicked();
    void on_Cancel_13_clicked();
    void on_the_product_of_chicken_pushButton_13_clicked();
    void on_the_product_of_sheep_pushButton_13_clicked();
    void on_the_product_of_cow_pushButton_13_clicked();
    void on_the_product_of_wheat_pushButton_13_clicked();
    void on_the_product_of_barley_pushButton_13_clicked();

    void on_Start_14_clicked();
    void on_Cancel_14_clicked();
    void on_the_product_of_chicken_pushButton_14_clicked();
    void on_the_product_of_sheep_pushButton_14_clicked();
    void on_the_product_of_cow_pushButton_14_clicked();
    void on_the_product_of_wheat_pushButton_14_clicked();
    void on_the_product_of_barley_pushButton_14_clicked();

    void on_Start_15_clicked();
    void on_Cancel_15_clicked();
    void on_the_product_of_chicken_pushButton_15_clicked();
    void on_the_product_of_sheep_pushButton_15_clicked();
    void on_the_product_of_cow_pushButton_15_clicked();
    void on_the_product_of_wheat_pushButton_15_clicked();
    void on_the_product_of_barley_pushButton_15_clicked();

    void on_Start_16_clicked();
    void on_Cancel_16_clicked();
    void on_the_product_of_chicken_pushButton_16_clicked();
    void on_the_product_of_sheep_pushButton_16_clicked();
    void on_the_product_of_cow_pushButton_16_clicked();
    void on_the_product_of_wheat_pushButton_16_clicked();
    void on_the_product_of_barley_pushButton_16_clicked();

private:
    Ui::Gamepage *ui;

    QSqlDatabase database;

    //Fn_Which_Of_Animals_or_Seeds=0 -> home or kill
    //Fn_Which_Of_Animals_or_Seeds=1 -> chicken
    //Fn_Which_Of_Animals_or_Seeds=2 -> sheep
    //Fn_Which_Of_Animals_or_Seeds=3 -> cow
    //Fn_Which_Of_Animals_or_Seeds=4 -> wheat
    //Fn_Which_Of_Animals_or_Seeds=5 -> barley
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

    QMediaPlayer * backmusic_chicken;
    QMediaPlayer * backmusic_sheep;
    QMediaPlayer * backmusic_cow;
    QMediaPlayer * backmusic_Farmer;
    QMediaPlayer * backmusic_Seeds;
    QMediaPlayer * backmusic_NewFarm;
    QMediaPlayer * backmusic_Base;
    QMediaPlayer * backmusic_Base_2;
    QMediaPlayer * backmusic_Result;
};

#endif // GAMEPAGE_H
