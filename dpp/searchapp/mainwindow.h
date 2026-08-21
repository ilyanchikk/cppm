#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbform.h"
#include "dbManager.h"
#include "dbviewall.h"
#include <QDialog>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void getSignalSearch();
private slots:
    void on_pB_openBD_clicked();
    void openState();
    void closedState();
    void on_pb_view_clicked();
    void buildTableSearch();
    void on_pB_search_clicked();

private:
    Ui::MainWindow *ui;
    dbform *__dbform;
    dbManager *__db;
    QString inipath;
    dbviewall *__dbviewall;
    QSqlQueryModel *__modelSe;

};
#endif // MAINWINDOW_H
