#include <QCoreApplication>
#include <QDebug>
#include <QSqlError>
#include <QThread>
#include "dbManager.h"
#include "searcherFiles.h"
#include "textHandler.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInstallMessageHandler(messageHandler);

dbManager db; //создаем экземпляр класса работы с БД
QString inipath = "../config.ini";
db.connectDB(inipath); //загружаем файл конфигурации и запускаем тестовое соединение к БД
if (!db.isOpen()) {
    return 1;
}
db.clearTables(); //очистить таблицы
db.createTables(); // создаем таблицы в БД
searcherFiles fe; // создаем экземпляр класса поиска каталогов
fe.loadConfig(inipath); // загружаем конфигурацию
const QStringList files = fe.foundFiles(fe.getPath(),fe.getExtention()); // записываем пути файлов которые нашли
textHandler testText; // создаем экземпляр класса обработки файлов
for(const QString& file : files) { //циклом открываем, читаем и записываем в qhash все файлы
    const QHash<QString, int> frequencies = testText.wordCount(testText.readTextFile(file),fe.getMinEl(), fe.getMaxEl()); // результат обработки файла
    db.saveInDb(frequencies, file); // сохраняем в БД
}

    return a.exec();
}
