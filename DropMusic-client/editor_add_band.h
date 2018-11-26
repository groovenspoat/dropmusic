#ifndef EDITOR_ADD_BAND_H
#define EDITOR_ADD_BAND_H

#include <QDialog>

namespace Ui {
class editor_add_band;
}

class editor_add_band : public QDialog
{
    Q_OBJECT

public:
    explicit editor_add_band(QWidget *parent = nullptr);
    ~editor_add_band();

private slots:
    void on_pb_add_band_clicked();

    void on_pb_add_musicien_clicked();

    void on_pb_search_clicked();

    void on_pb_add_clicked(const QModelIndex &index);

    void on_tb_search_musicien_doubleClicked(const QModelIndex &index);

private:
    Ui::editor_add_band *ui;
};

#endif // EDITOR_ADD_BAND_H
