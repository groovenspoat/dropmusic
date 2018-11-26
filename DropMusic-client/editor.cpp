#include "editor.h"
#include "ui_editor.h"
#include "dropmusic.h"
#include "editor_add_music.h"
#include "editor_add_artist.h"
#include "editor_add_band.h"
Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}


void Editor::on_bt_add_Music_clicked()
{
    editor_add_music addmusicdialog;
    addmusicdialog.setModal(true);
    addmusicdialog.exec();
}



void Editor::on_bt_add_musician_compositor_clicked()
{
    editor_add_artist addartistdialog;
    addartistdialog.setModal(true);
    addartistdialog.exec();
}

void Editor::on_bt_add_Album_clicked()
{
    editor_add_artist addartistdialog;
    addartistdialog.setModal(true);
    addartistdialog.exec();
}

void Editor::on_bt_add_band_clicked()
{
    editor_add_band addbanddialog;
    addbanddialog.setModal(true);
    addbanddialog.exec();


}
