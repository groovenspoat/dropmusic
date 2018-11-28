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
    QString SEARCH_COMPOSITOR(QString);
    QString SEARCH_BAND(QString);
    QString SEARCH_ALBUM(QString);
    QString SEARCH_MUSICIAN(QString);
    QString INSERT_MUSICIEN_BAND();
};


#endif // PREPAREDSTATEMENTS_H
