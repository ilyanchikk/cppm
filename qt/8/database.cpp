#include "database.h"

DataBase::DataBase(QObject *m_parent)
    : QObject{m_parent}
{

    __dataBase = new QSqlDatabase();
    __tableModel = nullptr;
    __queryModel = nullptr;
}

DataBase::~DataBase()
{
    delete __dataBase;
}


void DataBase::AddDataBase(QString m_driver, QString m_nameDB)
{
    *__dataBase = QSqlDatabase::addDatabase(m_driver, m_nameDB);
}


void DataBase::ConnectToDataBase(QVector<QString> m_data)
{
    __dataBase->setHostName(m_data[hostName]);
    __dataBase->setDatabaseName(m_data[dbName]);
    __dataBase->setUserName(m_data[login]);
    __dataBase->setPassword(m_data[pass]);
    __dataBase->setPort(m_data[port].toInt());


    bool status = __dataBase->open();


    emit sig_SendStatusConnection(status);
}

// Закрытие соединения с БД
void DataBase::DisconnectFromDataBase(QString m_nameDb)
{
    *__dataBase = QSqlDatabase::database(m_nameDb);
    __dataBase->close();
}


void DataBase::RequestToDB(int m_requestType)
{
    QSqlDatabase db = QSqlDatabase::database(DB_NAME);

    // Если соединения нет — выходим
    if (!db.isOpen()) {
        return;
    }

    switch(m_requestType) {


    case requestAllFilms: {
        if (__tableModel != nullptr) {
            delete __tableModel;
        }
        __tableModel = new QSqlTableModel(this, db);
        __tableModel->setTable("film");
        __tableModel->select();



        __tableModel->setHeaderData(1, Qt::Horizontal, "Название фильма");
        __tableModel->setHeaderData(2, Qt::Horizontal, "Описание фильма");

        // Отправка готовой модели в GUI
        emit sig_SendDataFromDB(__tableModel, requestAllFilms);
        break;
    }


    case requestComedy: {
        if (__queryModel != nullptr) {
            delete __queryModel;
        }
        __queryModel = new QSqlQueryModel(this);


        QString query = "SELECT f.title, f.description "
                        "FROM film f "
                        "JOIN film_category fc ON f.film_id = fc.film_id "
                        "JOIN category c ON c.category_id = fc.category_id "
                        "WHERE c.name = 'Comedy'";

        __queryModel->setQuery(query, db);
        __queryModel->setHeaderData(0, Qt::Horizontal, "Название фильма");
        __queryModel->setHeaderData(1, Qt::Horizontal, "Описание фильма");

        emit sig_SendDataFromDB(__queryModel, requestComedy);
        break;
    }


    case requestHorrors: {
        if (__queryModel != nullptr) {
            delete __queryModel;
        }
        __queryModel = new QSqlQueryModel(this);

        QString query = "SELECT f.title, f.description "
                        "FROM film f "
                        "JOIN film_category fc ON f.film_id = fc.film_id "
                        "JOIN category c ON c.category_id = fc.category_id "
                        "WHERE c.name = 'Horror'";

        __queryModel->setQuery(query, db);
        __queryModel->setHeaderData(0, Qt::Horizontal, "Название фильма");
        __queryModel->setHeaderData(1, Qt::Horizontal, "Описание фильма");

        emit sig_SendDataFromDB(__queryModel, requestHorrors);
        break;
    }

    default:
        break;
    }
}


QSqlError DataBase::GetLastError()
{
    return __dataBase->lastError();
}
