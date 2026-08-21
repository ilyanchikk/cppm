#ifndef LOGGER_H
#define LOGGER_H
#include <QTextStream>

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // LOGGER_H
