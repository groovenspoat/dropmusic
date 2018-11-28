#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "login.h"
#include<iostream>
#include"functions.h"
namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:


    void on_bt_register_clicked();

    void on_bt_cancel_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
