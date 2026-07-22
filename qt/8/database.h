#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>


#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtSql>
#else
#include <QtSql/QtSql>
#endif

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

#define NUM_DATA_FOR_CONNECT_TO_DB 5


enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};


enum requestType{

    requestAllFilms = 1,  // Все фильмы - QSqlTableModel
    requestComedy   = 2,  // Комедии - QSqlQueryModel
    requestHorrors  = 3   // Ужасы - QSqlQueryModel

};



class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    // Методы управления соединением
    void AddDataBase(QString m_driver, QString m_nameDB = "");
    void ConnectToDataBase(QVector<QString> m_dataForConnect);
    void DisconnectFromDataBase(QString m_nameDb = "");


    void RequestToDB(int m_requestType);


    QSqlError GetLastError(void);


signals:

    void sig_SendDataFromDB(QSqlQueryModel* m_model, int m_typeRequest);


    void sig_SendStatusConnection(bool m_status);



private:

    QSqlDatabase* __dataBase;

    QSqlTableModel* __tableModel;
    QSqlQueryModel* __queryModel;

};

#endif
