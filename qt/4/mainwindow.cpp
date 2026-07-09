#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    count(0)
{
    ui->setupUi(this);

    //progress bar
    ui->pB_bar->setMaximum(100);
    ui->pB_bar->setMinimum(0);
    ui->pB_bar->setValue(0);
    ui->pushButton->setText("Вперед");
    ui->rB_doll->setText("Доллар");
    ui->rB_doll->setChecked(true);
    ui->rB_euro->setText("Евро");
    ui->pushButton->setCheckable(true);

    for(int i=1; i < 6; i++) {
    ui->cB_box->addItem(QString("Элемент %1").arg(i));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->pB_bar->value() == 100) {
        ui->pB_bar->setValue(0);
        count = 0;
    }
    else {
        count += 10;
        ui->pB_bar->setValue(count);
    }
}

