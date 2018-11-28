#include "preparedstatements.h"
#include <QCryptographicHash>


PreparedStatements::PreparedStatements()
{

}

QString PreparedStatements::INSERT_USER(){

    QString INSERT_USER_Query = "INSERT INTO user (username, identification, birth) VALUES ( :username, :password , :birthdate )";
    return(INSERT_USER_Query);
}

QString PreparedStatements::SELECT_USER_USERNAME()
{
    QString SELECT_USER_USERNAME_Query = "SELECT * FROM user WHERE UPPER(username) = UPPER(:username)";
    return(SELECT_USER_USERNAME_Query);
}

QString PreparedStatements::SELECT_EDITOR()
{
    QString SELECT_EDITOR_Query = "SELECT * FROM editor WHERE UPPER(user_username) = UPPER(:username)";
    return(SELECT_EDITOR_Query);
}

QString PreparedStatements::INSERT_ARTIST()
{
    QString INSERT_ARTIST_Query = "INSERT INTO artist (firstname, surname, birthday, biography, photography_url) VALUES (:firstname, :surname, :birthday, :biography, :photography_url)";
    return(INSERT_ARTIST_Query);
}

QString PreparedStatements::INSERT_MUSICIEN()
{
    QString INSERT_MUSICIEN_Query = "INSERT INTO musicien (artist_id) VALUES (:artist_id, :instrument)";
    return (INSERT_MUSICIEN_Query);
}

QString PreparedStatements::INSERT_BAND()
{
    QString INSERT_MUSICIEN_Query = "INSERT INTO band (artist_id) VALUES (:artist_id)";
    return (INSERT_MUSICIEN_Query);
}

QString PreparedStatements::INSERT_COMPOSITOR()
{
    QString INSERT_COMPOSITOR_Query = "INSERT INTO compositor (artist_id, instrument) VALUES (:artist_id)";
    return (INSERT_COMPOSITOR_Query);
}

QString PreparedStatements::SEARCH_COMPOSITOR(QString line_search)
{
    QString SEARCH_COMPOSITOR_Query = "SELECT ID, concat((a.firstname),' ' , (a.surname)) as Compositor, birthday FROM ( SELECT DISTINCT * FROM artist WHERE id IN (SELECT artist_id FROM compositor))a where concat(UPPER(a.firstname),' ' , UPPER(a.surname)) like UPPER('%"+line_search+"%')";
    return(SEARCH_COMPOSITOR_Query);
}

QString PreparedStatements::SEARCH_BAND(QString line_search)
{
    QString SEARCH_BAND_Query = "SELECT ID, a.firstname as Banda, birthday FROM ( SELECT DISTINCT * FROM artist WHERE id IN (SELECT artist_id FROM band))a where UPPER(a.firstname) like UPPER('%"+line_search+"%')";
    return(SEARCH_BAND_Query);
}

QString PreparedStatements::SEARCH_MUSICIAN(QString line_search)
{

    QString SEARCH_MUSICIAN_Query = "SELECT ID, concat((a.firstname),' ' , (a.surname)) as Musico , birthday from (   SELECT DISTINCT * FROM artist WHERE id IN (SELECT artist_id FROM musician))a where concat(UPPER(a.firstname),' ' , UPPER(a.surname)) like UPPER('%"+line_search+"%')";
    return(SEARCH_MUSICIAN_Query);
}

QString PreparedStatements::INSERT_MUSICIEN_BAND()
{
    QString INSERT_MUSICIEN_BAND_Query = "INSERT INTO musician_band (musician_artist_id, band_artist_id) VALUES (:musician_artist_id, :band_artist_id)";
    return (INSERT_MUSICIEN_BAND_Query);
}


