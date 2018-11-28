#ifndef EDITOR_ADD_ARTIST_H
#define EDITOR_ADD_ARTIST_H

#include <QDialog>

namespace Ui {
class editor_add_artist;
}

class editor_add_artist : public QDialog
{
    Q_OBJECT

public:
    explicit editor_add_artist(QWidget *parent = nullptr);
    ~editor_add_artist();

private slots:
    void on_bt_add_artist_clicked();

    void on_bt_upload_photo_clicked();

private:
    Ui::editor_add_artist *ui;
};

#endif // EDITOR_ADD_ARTIST_H
