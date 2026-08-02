#include <QCoreApplication>
#include <QDebug>
#include <QSqlError>
#include <QThread>
#include "dbManager.h"
#include "searcherFiles.h"
#include "textHandler.h"





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
dbManager db; //создаем экземпляр класса работы с БД
db.connectDB("config.ini"); //загружаем файл конфигурации и запускаем тестовое соединение к БД
db.clearTables(); //очистить таблицы
db.createTables(); // создаем таблицы в БД(в готовой, пока без содания самой БД)
searcherFiles fe; // создаем экземпляр класса поиска каталогов
fe.loadConfig("config.ini"); // загружаем конфигурацию
//qDebug() << fe.foundFiles(fe.getPath(),fe.getExtention()); //для теста работы функций
const QStringList files = fe.foundFiles(fe.getPath(),fe.getExtention()); // записываем пути файлов которые нашли

textHandler testText; // создаем экземпляр класса обработки файлов
for(const QString& file : files) { //циклом открываем, читаем и записываем в qhash все файлы
    const QHash<QString, int> frequencies = testText.wordCount(testText.readTextFile(file),fe.getMinEl(), fe.getMaxEl()); // результат обработки файла
    //qDebug() << frequencies; //для теста работы функций
    db.saveInDb(frequencies, file); // сохраняем в БД
}

    return a.exec();
}
