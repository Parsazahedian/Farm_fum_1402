#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QMainWindow>

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
};

#endif // GAMEPAGE_H
