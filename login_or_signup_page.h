#ifndef LOGIN_OR_SIGNUP_PAGE_H
#define LOGIN_OR_SIGNUP_PAGE_H

#include <QMainWindow>
#include "QLabel"
#include "mainwindow.h"
#include "QMediaPlayer"

namespace Ui {
class Login_or_SignUp_page;
}

class Login_or_SignUp_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login_or_SignUp_page(QWidget *parent = nullptr);
    ~Login_or_SignUp_page();

    bool endsWith(const QString &fullString, const QString &ending);

    void closeMainWindow();

    QMediaPlayer* Successful_login_or_SignUp;

private slots:

    bool validate_username(QString input_text, QLabel* targetLable);

    bool validate_password(QString input_text, QLabel* targetLable);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_Login_of_LoginGroupbox_clicked();

    void on_comboBox_2_activated(int index);

    void on_comboBox_activated(int index);

    bool validate_phone(QString input_text, QLabel* targetLable);

    bool validate_email(QString input_text, QLabel* targetLable);

    void on_SignUp_of_Signup_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    bool validate_Inventory(QString input_text, QLabel* targetLable);

    void on_lineEdit_7_textChanged(const QString &arg1);

    bool validate_Captcha(QString input_text, QLabel* targetLable);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_6_textChanged(const QString &arg1);

    bool validate2_email(QString input_text, QLabel* targetLable);

    void on_pushButton_4_clicked();

    void on_signUp_of_LoginGroupbox_clicked();

    void on_lineEdit_13_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_9_textChanged(const QString &arg1);

private:
    Ui::Login_or_SignUp_page *ui;
};

#endif // LOGIN_OR_SIGNUP_PAGE_H
