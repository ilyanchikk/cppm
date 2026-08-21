#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "qobject.h"
#include <QSqlDatabase>

class dbManager: public QObject {
    Q_OBJECT
public:
    dbManager();
    ~dbManager();

    void connectDB(const QString& iniPath);
    void disconnectDB();
    void createTables();
    void saveInDb(const QHash<QString, int>& frequencies, const QString& file);
    void clearTables();
    bool isOpen();

signals:
    void dbConnected();
    void dbDisconnected();
    void dbInfo(QString text);

private:
    QSqlDatabase db;
    int wordId;
    int docId;

};

#endif // DBMANAGER_H
