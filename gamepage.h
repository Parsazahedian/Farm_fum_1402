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

private:
    Ui::Gamepage *ui;
};

#endif // GAMEPAGE_H
