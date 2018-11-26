#ifndef PREPAREDSTATEMENTS_H
#define PREPAREDSTATEMENTS_H

#include<QString>
#include<QDate>

class PreparedStatements
{
public:
    PreparedStatements();
    QString INSERT_USER();
    QString SELECT_USER_USERNAME();
    QString SELECT_EDITOR();
    QString INSERT_ARTIST();
    QString INSERT_COMPOSITOR();
    QString INSERT_MUSICIEN();
    QString INSERT_BAND();
    QString INSERT_ALBUM();
    QString SEARCH_ARTIST();
    QString SEARCH_COMPOSITOR();
    QString SEARCH_BAND();
    QString SEARCH_ALBUM();
    QString SEARCH_MUSICIAN(QString);
};


#endif // PREPAREDSTATEMENTS_H
