#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    __stopwatch = new Stopwatch(this);
    ui->setupUi(this);

    ui->pB_start->setText("Старт");
    ui->pB_start->setCheckable(true);
    ui->pB_reset->setText("Сброс");
    ui->pB_circle->setText("Круг");
    ui->pB_circle->setEnabled(false);
    ui->label_time->setText("00:00:00:00");
    ui->label_time->setAlignment(Qt::AlignCenter);
     connect(__stopwatch, &Stopwatch::sig_timeUpdated, this, &MainWindow::slotUpdateDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_start_clicked()
{
   if(ui->pB_start->isChecked() == true)
   {
        ui->pB_start->setText("Стоп");
        ui->pB_circle->setEnabled(true);
       __stopwatch->startTimer();

    }
   else {
         __stopwatch->stopTimer();
        ui->pB_start->setText("Старт");
        ui->label_time->setText("00:00:00:00");
        ui->pB_circle->setEnabled(false);
   }
}


void MainWindow::on_pB_circle_clicked()
{
     ui->tB_log->append(__stopwatch->convertTime());
     __stopwatch->resetTimer();
}


void MainWindow::on_pB_reset_clicked()
{
    __stopwatch->stopTimer();
    ui->tB_log->clear();
    ui->label_time->setText("00:00:00:00");
    ui->pB_start->setChecked(false);
    ui->pB_start->setText("Старт");
    ui->pB_circle->setEnabled(false);
}

void MainWindow::slotUpdateDisplay()
{
    ui->label_time->setText(__stopwatch->convertTime());
}

