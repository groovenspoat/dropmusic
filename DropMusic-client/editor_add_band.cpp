#include "editor_add_band.h"
#include "ui_editor_add_band.h"
#include "functions.h"
#include "editor_add_artist.h"
#include "QSqlQueryModel"

editor_add_band::editor_add_band(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editor_add_band)
{
    ui->setupUi(this);
    on_pb_search_clicked();


}

editor_add_band::~editor_add_band()
{
    delete ui;
}

void editor_add_band::on_pb_add_band_clicked()
{
   functions func;
    QString foto ="";
    QDate birthdate;
    QString biography = ui->ln_biography->toPlainText();
    birthdate = ui->dt_birthday->date();
    func.INSERT_BAND(ui->ln_firstname->text(),ui->ln_idk->text(),birthdate,biography,foto);

}

void editor_add_band::on_pb_add_musicien_clicked()
{
    editor_add_artist addartistdialog;
    addartistdialog.setModal(true);
    addartistdialog.exec();
}

void editor_add_band::on_pb_search_clicked()
{
    functions func;
    QSqlQueryModel *search_result= nullptr;
    search_result = func.SEARCH_MUSICIENS(ui->ln_search->text());
    ui->tb_search_musicien->setModel(search_result);
    ui->tb_search_musicien->resizeColumnsToContents();
    ui->tb_search_musicien->resizeRowsToContents();
}



void editor_add_band::on_pb_add_clicked(const QModelIndex &index)
{
    ui->tb_search_musicien->setCurrentIndex (index);
    int row = index.row();
    int id = ui->tb_search_musicien->model()->data(ui->tb_search_musicien->model()->index(row,0)).toInt();
    QString name = ui->tb_search_musicien->model()->data(ui->tb_search_musicien->model()->index(row,1)).toString();
    qDebug() << id << name;
    int r = ui->tb_selected_musicians->rowCount()-1;
    ui->tb_selected_musicians->setItem(r,0,new QTableWidgetItem(id));
    ui->tb_selected_musicians->setItem(r,1,new QTableWidgetItem(name));

            /*->model()->insertColumn(0);
    ui->tb_selected_musicien->model()->insertColumn(1);
    //ui->tb_selected_musicien->

    //tableWidget->setItem( r, c, new QTableWidgetItem(stringData(r,c)));
*/
}


void editor_add_band::on_tb_search_musicien_doubleClicked(const QModelIndex &index)
{
   ui->tb_search_musicien->setCurrentIndex (index);
   qDebug() << "Index: " << index;
   int r = index.row();
   int c = index.column ();
   qDebug() << "Row: " << r;
   qDebug() << "Column: " << c;
}



















