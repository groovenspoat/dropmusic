#include "ui_editor_add_music.h"
#include"editor_add_music.h"
#include "functions.h"

editor_add_music::editor_add_music(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editor_add_music)
{
    ui->setupUi(this);
}

editor_add_music::~editor_add_music()
{
    delete ui;
}


void editor_add_music::on_bt_artist_search_clicked()
{

}

void editor_add_music::on_bt_compositor_search_clicked()
{

}

void editor_add_music::on_album_search_clicked()
{

}
