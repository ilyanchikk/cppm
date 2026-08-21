#include "dbviewall.h"
#include "ui_dbviewall.h"

#include <QTableView>

dbviewall::dbviewall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbviewall)
{
    ui->setupUi(this);
    this->setWindowTitle("Просмотр всех записей");
    __model = new QSqlQueryModel(this);

}

dbviewall::~dbviewall()
{
    delete ui;
}

void dbviewall::buildTable() {
    __model->setQuery("SELECT d.path,w.word,wd.frequency FROM documents d JOIN words_documents wd ON d.id = wd.document_id JOIN words w ON w.id = wd.word_id order by d.path;");


    // Устанавливаем заголовки столбцов (по желанию)
    __model->setHeaderData(0, Qt::Horizontal, tr("Путь"));
    __model->setHeaderData(1, Qt::Horizontal, tr("Слово"));
    __model->setHeaderData(2, Qt::Horizontal, tr("Количество повторений"));


    // Привязываем модель к QTableView
     ui->tV_all->setModel(__model);
     ui->tV_all->resizeColumnsToContents();
     ui->tV_all->resizeRowsToContents();

}
