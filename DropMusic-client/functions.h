#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include"preparedstatements.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QSqlQueryModel>

extern QSqlDatabase db;


class functions
{
private:
    QSqlQueryModel *musicien_search;
    QSqlQueryModel *compositor_search;
    QSqlQueryModel *band_search;
public:
    bool INSERT_USER(QString username, QString password, QDate date);

    int SELECT_USER_USERNAME(QString username);
    bool LOGIN(QString username, QString password);
    bool CHECK_EDITOR_RIGHTS(QString username);
    bool INSERT_MUSICIAN_COMPOSITOR(QString firstname, QString surname, QDate birthday, QString biography, QString photography_url, bool mucicien, bool compositor, QString instrument);
    bool INSERT_BAND(QString firstname, QString surname, QDate birthday, QString biography, QString photography_url);
    QSqlQueryModel *SEARCH_MUSICIENS(QString name);
    functions();
};

#endif // FUNCTIONS_H
