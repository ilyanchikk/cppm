#include "dbform.h"
#include "ui_dbform.h"

dbform::dbform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbform)
{
    ui->setupUi(this);
    this->setWindowTitle("Ошибка");
    ui->pB_close->setText("OK");



}

dbform::~dbform()
{
    delete ui;
}

void dbform::debugInfo(QString text) {
    ui->label->setText(text);
    return;
}

void dbform::on_pB_close_clicked()
{
    this->close();
}

