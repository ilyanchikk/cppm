#include "dbManager.h"
#include "qsqlerror.h"
#include <QFileInfo>
#include <QSettings>
#include <QSqlQuery>

dbManager::dbManager() {

}
dbManager::~dbManager() {
    if(db.isOpen()) {
        db.close(); //Закрыть соединение с БД если оно закрыто при уничтожении объекта
    }
}
void dbManager::connectDB(const QString& iniPath) {

    if(!QFileInfo::exists(iniPath)) {
        qDebug() << "Ошибка! Файл не найден";

    }
    else {
   QSettings settings(iniPath, QSettings::IniFormat);
   settings.beginGroup("database");
     QString host     = settings.value("host", "localhost").toString();    // адрес
     int     port     = settings.value("port", 5432).toInt();              // порт
     QString dbName   = settings.value("dbname", "test").toString();       // имя базы данных
     QString user     = settings.value("user").toString();                 // имя пользователя
     QString password = settings.value("password").toString();             // пароль
     settings.endGroup();

     db = QSqlDatabase::addDatabase("QPSQL");
     db.setHostName(host);
     db.setPort(port);
     db.setDatabaseName(dbName);
     db.setUserName(user);
     db.setPassword(password);

     if (!db.open()) {     // пытаемся открыть соединение по заданным параметрам
             qDebug() << "Не удается открыть соединение с БД";
         }
     else {
         qDebug() << "Открыто соединение с БД";
     }
    }


}
void dbManager::createTables() {
    if (!db.isOpen()) {     // проверка открытия БД
          qDebug() <<  "Соединение с БД не открыто, создание таблиц невозможно";
      }
    else {
        QSqlQuery query(db);

        const QString createDoc =
            "CREATE TABLE IF NOT EXISTS documents ("
            "    id  SERIAL PRIMARY KEY,"
            "    path TEXT NOT NULL UNIQUE"
            ")";

        const QString createWords =
            "CREATE TABLE IF NOT EXISTS words ("
            "    id   SERIAL PRIMARY KEY,"
            "    word TEXT NOT NULL"
            ")";

        const QString createWordsDoc =     // связь многие ко многим
            "CREATE TABLE IF NOT EXISTS words_documents ("
            "    word_id     INTEGER NOT NULL REFERENCES words(id),"
            "    document_id INTEGER NOT NULL REFERENCES documents(id),"
            "    frequency   INTEGER NOT NULL,"
            "    PRIMARY KEY (word_id, document_id)"     // составной ключ
            ")";
        if (!query.exec(createDoc)) {
            qDebug() << "Ошибка создания таблицы documents";
           }
        qDebug() << "Создана таблица documents";
        if (!query.exec(createWords)) {
            qDebug() << "Ошибка создания таблицы words";
           }
        qDebug() << "Создана таблица words";
        if (!query.exec(createWordsDoc)) {
            qDebug() << "Ошибка создания таблицы words_documents";
           }
        qDebug() << "Создана таблица words_documents";
    }
}

void dbManager::saveInDb(const QHash<QString, int>& frequencies, const QString& file)
{ 
    QSqlQuery querySaveDoc(db);                                                        //Запрос на сохранение в таблицу documents
    querySaveDoc.prepare("INSERT INTO documents (path) VALUES (:path)");

    QSqlQuery querySaveWord(db);                                                       //Запрос на сохранение в таблицу words
    querySaveWord.prepare("INSERT INTO words (word) VALUES (:key)");

    QSqlQuery queryGetWordId(db);                                                      //Запрос на получение id_word после выполнения запроса querySaveWord
    queryGetWordId.prepare("SELECT id FROM words WHERE word = :key");

    QSqlQuery queryGetDocId(db);                                                       //Запрос на получение id_documents после выполнения запроса querySaveDoc
    queryGetDocId.prepare("SELECT id FROM documents WHERE path = :path");

    QSqlQuery querySaveWordDoc(db);                                                    //Запрос на сохранение в таблицу words_documents идентификаторов и количества повторений
    querySaveWordDoc.prepare("INSERT INTO words_documents (word_id, document_id, frequency) VALUES (:wordId, :documentId, :frequency)");



    querySaveDoc.bindValue(":path", file);
    if(!querySaveDoc.exec()) {
        qDebug()<< "Ошибка записи в таблицу documents: " <<querySaveDoc.lastError();
    }

    auto w = frequencies.constBegin();
    while (w != frequencies.constEnd()) {
        querySaveWord.bindValue(":key", w.key());
        if(!querySaveWord.exec()) {
            qDebug()<< "Ошибка записи в таблицу words: " <<querySaveWord.lastError();
        }

        queryGetWordId.bindValue(":key", w.key());
        if(queryGetWordId.exec() && queryGetWordId.next()) {
            wordId = queryGetWordId.value(0).toInt();
        }

        queryGetDocId.bindValue(":path", file);
        if(queryGetDocId.exec() && queryGetDocId.next()) {
            docId = queryGetDocId.value(0).toInt();
        }

        querySaveWordDoc.bindValue(":wordId", wordId);
        querySaveWordDoc.bindValue(":documentId", docId);
        querySaveWordDoc.bindValue(":frequency", w.value());
        querySaveWordDoc.exec();


        ++w;
    }
   qDebug() << QString("Произведена запись в таблицы файла %1").arg(file);
}

void dbManager::clearTables() { //очистка всех таблиц
    QSqlQuery clear(db);
    if(!clear.exec("DROP TABLE IF EXISTS words_documents, words, documents")){
    qDebug() << clear.lastError();
    }
    qDebug() << "Произведена очистка таблиц";
}
