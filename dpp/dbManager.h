#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class dbManager {
public:
    dbManager();
    ~dbManager();

    void connectDB(const QString& iniPath);
    void createTables();
    void saveInDb(const QHash<QString, int>& frequencies, const QString& file);
    void clearTables();

private:
    QSqlDatabase db;
    int wordId;
    int docId;

};

#endif // DBMANAGER_H
