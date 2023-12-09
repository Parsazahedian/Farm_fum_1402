#ifndef LOGIN_OR_SIGNUP_PAGE_H
#define LOGIN_OR_SIGNUP_PAGE_H

#include <QMainWindow>

namespace Ui {
class Login_or_SignUp_page;
}

class Login_or_SignUp_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login_or_SignUp_page(QWidget *parent = nullptr);
    ~Login_or_SignUp_page();

private:
    Ui::Login_or_SignUp_page *ui;
};

#endif // LOGIN_OR_SIGNUP_PAGE_H
