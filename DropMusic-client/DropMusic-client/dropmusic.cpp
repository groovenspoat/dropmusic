#include "dropmusic.h"
#include "ui_dropmusic.h"
#include "functions.h"
#include "editor.h"
#include <QString>
extern QString username;
DropMusic::DropMusic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DropMusic)
{

    ui->setupUi(this);
}

DropMusic::~DropMusic()
{
    delete ui;
}

void DropMusic::on_bt_Editor_clicked()
{
    functions func;

    if(func.CHECK_EDITOR_RIGHTS(username))
    {
        ui->lb_Debug->setText("Bem vindo, " + username + ".");
        Editor *editor_interface=nullptr;
        editor_interface=new Editor;
        editor_interface->show();
        close();
    }
    else
    {
        ui->lb_Debug->setText("Falha no direito de editor");
    }

}
