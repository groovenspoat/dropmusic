#include "login.h"
#include "ui_login.h"
#include"signup.h"
#include"dropmusic.h"

QString username="";
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);
    ui->ln_username->setText("groovenspoat");
    ui->ln_passwrd->setText("grooven");

}

login::~login()
{
    delete ui;
}


void login::on_bt_signup_clicked()
{
    signup sigupDialog;
    sigupDialog.setModal(true);
    sigupDialog.exec();
}

void login::on_bt_login_clicked()
{
    functions func;
    if(func.LOGIN(ui->ln_username->text(),ui->ln_passwrd->text())){
        username=ui->ln_username->text();
        ui->lb_status->setText("(+)Status: Login sucessfull");
        DropMusic *dropmusicapp=nullptr;
        dropmusicapp = new DropMusic;
        dropmusicapp->show();
        close();

    }
    else
    {
        ui->lb_status->setText("(+)Status: Wrong username or password");
    }
};
