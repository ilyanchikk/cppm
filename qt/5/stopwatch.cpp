#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject(parent)
{
    timer = new QTimer(this);
    elapsedTimer = new QElapsedTimer();
    m_accumulatedTime = 0;
    connect(timer, &QTimer::timeout, this, &Stopwatch::updateTimer);

}
Stopwatch::~Stopwatch()
{

}
void Stopwatch::updateTimer()
{
     emit sig_timeUpdated();
}

void Stopwatch::stopTimer()
{
    timer->stop();
}

void Stopwatch::resetTimer()
{
   elapsedTimer->restart();
}

void Stopwatch::startTimer()
{
    timer->start();
    elapsedTimer->start();
}

QString Stopwatch::convertTime()
{
    qint64 totalMSecs = m_accumulatedTime + elapsedTimer->elapsed();

    // Переводим миллисекунды в часы, минуты, секунды
    int hours = totalMSecs / 3600000;
    int minutes = (totalMSecs % 3600000) / 60000;
    int seconds = (totalMSecs % 60000) / 1000;
    int msecs = totalMSecs % 1000;

    // Форматируем строку (например: 01:23:45.678)
    QString text = QString("%1:%2:%3.%4")
        .arg(hours, 2, 10, QChar('0'))
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'))
        .arg(msecs, 3, 10, QChar('0'));
    return text;
}
