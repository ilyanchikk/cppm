#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>
#include <QElapsedTimer>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    void startTimer();
    void stopTimer();
    void resetTimer();
    QString convertTime();

signals:
    void sig_timeUpdated();

private slots:
    void updateTimer();

private:

    QTimer *timer;
    QElapsedTimer *elapsedTimer;
    qint64 m_accumulatedTime;
};

#endif
