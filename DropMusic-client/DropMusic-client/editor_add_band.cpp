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
    QStringList labels;
    labels << "ID"<<"Nome";
    ui->tb_selected_musicians->insertColumn(0);
    ui->tb_selected_musicians->insertColumn(1);
    ui->tb_selected_musicians->setHorizontalHeaderLabels(labels);
    ui->tb_selected_musicians->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tb_selected_musicians->hideColumn(0);


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
    int last_inserted = func.INSERT_BAND(ui->ln_firstname->text(),birthdate,biography,foto);
    if(last_inserted ==-1) return;
    func.INSERT_MUSICIAN_BAND(ui->tb_selected_musicians, last_inserted);

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
    ui->tb_search_musicien->hideColumn(0);
    ui->tb_search_musicien->sortByColumn(1);
}



void editor_add_band::on_pb_add_clicked()
{
}


void editor_add_band::on_tb_search_musicien_doubleClicked(const QModelIndex &index)
{
    ui->tb_search_musicien->setCurrentIndex (index);
    qDebug() << "Index: " << index;
    int r = index.row();
    int c = index.column ();
    qDebug() << "Row: " << r;
    qDebug() << "Column: " << c;

    QString id = ui->tb_search_musicien->model()->data(ui->tb_search_musicien->model()->index(r,0)).toString();
    QString name = ui->tb_search_musicien->model()->data(ui->tb_search_musicien->model()->index(r,1)).toString();
    qDebug() << id << name << r;
    int rows = ui->tb_selected_musicians->rowCount();
    ui->tb_selected_musicians->insertRow(rows);
    ui->tb_selected_musicians->setItem(rows,0, new QTableWidgetItem(id));
    ui->tb_selected_musicians->setItem(rows,1,new QTableWidgetItem(name));
}




void editor_add_band::on_tb_selected_musicians_doubleClicked(const QModelIndex &index)
{
    ui->tb_selected_musicians->removeRow(index.row());
}
