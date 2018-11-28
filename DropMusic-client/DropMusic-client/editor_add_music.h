#ifndef EDITOR_ADD_MUSIC_H
#define EDITOR_ADD_MUSIC_H

#include <QDialog>

namespace Ui {
class editor_add_music;
}

class editor_add_music : public QDialog
{
    Q_OBJECT

public:
    explicit editor_add_music(QWidget *parent = nullptr);
    ~editor_add_music();

private slots:


    void on_bt_artist_search_clicked();

    void on_bt_compositor_search_clicked();

    void on_album_search_clicked();

private:
    Ui::editor_add_music *ui;
};

#endif // EDITOR_ADD_MUSIC_H
