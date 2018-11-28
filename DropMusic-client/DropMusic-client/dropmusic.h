#ifndef DROPMUSIC_H
#define DROPMUSIC_H

#include <QMainWindow>

namespace Ui {
class DropMusic;
}

class DropMusic : public QMainWindow
{
    Q_OBJECT

public:
    explicit DropMusic(QWidget *parent = nullptr);
    ~DropMusic();

private slots:
    void on_bt_Editor_clicked();

private:
    Ui::DropMusic *ui;
};

#endif // DROPMUSIC_H
