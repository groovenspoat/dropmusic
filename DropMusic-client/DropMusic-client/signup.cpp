#include "signup.h"
#include"functions.h"
#include "ui_signup.h"
#include<QString>
#include"preparedstatements.h"


signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}



void signup::on_bt_register_clicked()
{
    functions func;
    if(func.INSERT_USER(ui->username->text(),ui->password->text(),ui->birthdate->date()))
    {
      ui->lb_Debug->setText("Conta criada com sucesso.");
    }
    else
    {
        ui->lb_Debug->setText("Falha na criação do utilizador");
    }

}


void signup::on_bt_cancel_clicked()
{
    close();
}
