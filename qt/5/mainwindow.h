#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Stopwatch;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_start_clicked();

    void on_pB_circle_clicked();

    void on_pB_reset_clicked();
    void slotUpdateDisplay();

private:
    Ui::MainWindow *ui;
    Stopwatch *__stopwatch;

};
#endif // MAINWINDOW_H
