#include "editor_add_artist.h"
#include "ui_editor_add_artist.h"
#include "functions.h"
#include <QDateEdit>
editor_add_artist::editor_add_artist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editor_add_artist)
{
    ui->setupUi(this);
}

editor_add_artist::~editor_add_artist()
{
    delete ui;
}

void editor_add_artist::on_bt_add_artist_clicked()
{
    QDate birthdate;
    QString biography = ui->ln_biografia->toPlainText();
    birthdate = ui->dt_birthdate->date();
    QString link;
    functions func;
    func.INSERT_MUSICIAN_COMPOSITOR(ui->ln_name->text(),ui->ln_surname->text(),birthdate, biography ,link, ui->rb_musician, ui->rd_compositor, ui->ln_instrument->text());
}

void editor_add_artist::on_bt_upload_photo_clicked()
{

}
