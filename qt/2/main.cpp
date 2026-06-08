#include <QCoreApplication>
#include <QLocalSocket>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
QLocalSocket soket1;
QSqlDatabase DB;
soket1.abort();
DB.close();

    return a.exec();
}
