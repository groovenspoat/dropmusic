#include "login.h"
#include <QApplication>
#include<QSqlDatabase>

QSqlDatabase db;
int main(int argc, char *argv[])
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dropmusic");
    db.setUserName("root");
    db.setPassword("grooven");


    QApplication a(argc, argv);
    login w;
    w.show();

    return a.exec();
}
