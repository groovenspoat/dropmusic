#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

private slots:


    void on_bt_add_Music_clicked();



    void on_bt_add_musician_compositor_clicked();

    void on_bt_add_Album_clicked();

    void on_bt_add_band_clicked();

private:
    Ui::Editor *ui;
};

#endif // EDITOR_H
