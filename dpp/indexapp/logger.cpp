#include <QFile>
#include <QDateTime>
#include <QMutex>
#include "logger.h"

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    static QMutex mutex;
    QMutexLocker locker(&mutex); // Защита от записи из разных потоков

    QFile file("log.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream stream(&file);
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");

        QString level;
        switch (type) {
            case QtDebugMsg:    level = "DBG"; break;
            case QtInfoMsg:     level = "INF"; break;
            case QtWarningMsg:  level = "WRN"; break;
            case QtCriticalMsg: level = "CRT"; break;
            case QtFatalMsg:    level = "FTL"; break;
        }

        stream << "[" << time << "] [" << level << "] " << msg << "\n";
    }
}
