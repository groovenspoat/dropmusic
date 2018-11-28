#include "functions.h"

#include <QtSql>
#include <QSqlTableModel>
#include<QTableView>


bool functions::INSERT_USER(QString username, QString password, QDate date)
{
    PreparedStatements statement;
    int day, month, year;
    date.getDate(&year,&month,&day);
    QString qs_year,qs_month,qs_day;
    qs_year=QString::number(year);
    qs_month=QString::number(month);
    qs_day=QString::number(day);

    if(db.open()){
        qDebug() << "Opened!";
        QString SELECT_USER_USERNAME_Query = statement.SELECT_USER_USERNAME();

        QSqlQuery qry;
        qry.prepare(SELECT_USER_USERNAME_Query);
        qry.bindValue(":username", username);

        qry.exec();
        int counter=0;
        while(qry.next()){
            counter++;
        }
        if(counter ==0 ){

            QString INSERT_USER_Query = statement.INSERT_USER();
            QSqlQuery qry_2;
            qry_2.prepare(INSERT_USER_Query);
            qry_2.bindValue("username",username);
            qry_2.bindValue("password", password);
            qry_2.bindValue("date","'"+ qs_year+"-"+ qs_month +"-"+ qs_day + "'");
            qry_2.exec();
            qDebug()<<"USER REgistred  "<< INSERT_USER_Query;
        }
        db.close();
    }
    return false;
}
int functions::SELECT_USER_USERNAME(QString username)
{
    PreparedStatements statement;
    if(db.open())
    {
        QString SELECT_USER_USERNAME_Query = statement.SELECT_USER_USERNAME();
        QSqlQuery query;
        query.prepare(SELECT_USER_USERNAME_Query);
        query.bindValue(":username",username);
        query.exec();
        int counter=0;
        while (query.next())
        {
            counter++;
        }
        db.close();
        if(counter== 0)
        {
            return 0;
        }
        else if (counter == 1)
        {
            return 1;
        }
        else
        {
            return 2;
        }

    }
    return -1;
}
bool functions::LOGIN(QString username, QString password)
{
    PreparedStatements statement;

    if(db.open()){
        QSqlQuery query;
        query.prepare(statement.SELECT_USER_USERNAME());
        query.bindValue(":username",username);
        query.exec();

        while (query.next())
        {
            if(query.value(1).toString()==password)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        db.close();
        return false;
    };
    return false;

}
bool functions::CHECK_EDITOR_RIGHTS(QString username)
{
    PreparedStatements statement;

    if(db.open()){
        QSqlQuery query;
        query.prepare(statement.SELECT_EDITOR());
        query.bindValue(":username",username);
        query.exec();
        int counter = 0;
        while (query.next()) {
            counter++;
        }
        db.close();
        if (counter == 0) return false;
        else  if(counter ==1) return true;
    }

    return false;
}
bool functions::INSERT_MUSICIAN_COMPOSITOR(QString name, QString surname, QDate birthday, QString biography, QString photography_url, bool musicien, bool compositor, QString instrument)
{
    PreparedStatements statement;
    int day,month, year;
    birthday.getDate(&year,&month,&day);
    QString qs_year,qs_month,qs_day;
    qs_year=QString::number(year);
    qs_month=QString::number(month);
    qs_day=QString::number(day);
    QString qs_date = qs_year+"-"+ qs_month +"-"+ qs_day;
    if(db.open()){
        QSqlQuery query;
        query.prepare(statement.INSERT_ARTIST());
        query.bindValue(":firstname",name);
        query.bindValue(":surname",surname);
        query.bindValue(":birthday", qs_date);
        query.bindValue(":biography",biography);
        query.bindValue(":photography_url",photography_url);
        query.exec();

        int artist_id=0;
        artist_id=query .lastInsertId().toInt();
        qDebug() << artist_id;
        if(musicien)
        {
            QSqlQuery query;
            query.prepare(statement.INSERT_MUSICIEN());
            query.bindValue(":artist_id",artist_id);
            query.exec();
        }
        if(compositor)
        {
            QSqlQuery query;
            query.prepare(statement.INSERT_COMPOSITOR());
            query.bindValue(":artist_id",artist_id);
            query.bindValue(":instrument",instrument);
            query.exec();
        }
    }
    return false;
}
int functions::INSERT_BAND(QString firstname, QDate birthday, QString biography, QString photography_url)
{
    PreparedStatements statement;
    int day,month, year;
    birthday.getDate(&year,&month,&day);
    QString qs_year,qs_month,qs_day;
    qs_year=QString::number(year);
    qs_month=QString::number(month);
    qs_day=QString::number(day);
    QString qs_date = qs_year+"-"+ qs_month +"-"+ qs_day;
    if(db.open()){
        QSqlQuery query;
        query.prepare(statement.INSERT_ARTIST());
        query.bindValue(":firstname",firstname);
        query.bindValue(":surname", "(NULL)");
        query.bindValue(":birthday", qs_date);
        query.bindValue(":biography",biography);
        query.bindValue(":photography_url",photography_url);
        if(!query.exec()) return false;;

        int artist_id=0;
        artist_id=query .lastInsertId().toInt();
        QSqlQuery query_2;
        query_2.prepare(statement.INSERT_BAND());
        query_2.bindValue(":artist_id",artist_id);
        query_2.exec();
        return artist_id;


    };
    return -1;
}

QSqlQueryModel *functions::SEARCH_MUSICIENS(QString name)
{
    PreparedStatements statement;
    if(db.open()){
        musicien_search = new QSqlQueryModel;
        musicien_search->setQuery(statement.SEARCH_MUSICIAN(name));
    return (musicien_search);
    }
    else return (nullptr);
}

bool functions::INSERT_MUSICIAN_BAND(QTableWidget *selected_musicians, int band_artist_id)
{


    PreparedStatements statements;
    int rows = selected_musicians->rowCount();
    if(db.open()){
        for(int i=0; i<rows; i++)
        {
            int musician_artist_id = selected_musicians->item(i,0)->text().toInt();
            QSqlQuery query;
            query.prepare(statements.INSERT_MUSICIEN_BAND());
            query.bindValue(":band_artist_id", band_artist_id);
            query.bindValue(":musician_artist_id", musician_artist_id);
            query.exec();

        }
        db.close();
        return true;
    }
    return false;
}

functions::functions()
{

}
