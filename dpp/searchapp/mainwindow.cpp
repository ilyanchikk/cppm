#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbform.h"
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
ui->setupUi(this);
this->setWindowTitle("Программа поисковик");
inipath = "../config.ini";

QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
__dbform = new dbform();
__db = new dbManager;
__dbviewall = new dbviewall;
__modelSe = new QSqlQueryModel;

ui->pB_openBD->setCheckable(true);
ui->pB_openBD->setText("Подключиться");
ui->pB_search->setText("Поиск");
ui->pb_view->setText("Все записи");
if(!__db->isOpen()) {
  closedState();
}
QObject::connect(shortcut, &QShortcut::activated, ui->pB_search, &QPushButton::click);
QObject::connect(__db, &dbManager::dbConnected, this, &MainWindow::openState);
QObject::connect(__db, &dbManager::dbDisconnected, this, &MainWindow::closedState);
QObject::connect(__db, &dbManager::dbInfo, __dbform, &dbform::debugInfo);
QObject::connect(__db, &dbManager::dbConnected, __dbviewall, &dbviewall::buildTable);
QObject::connect(this, &MainWindow::getSignalSearch, this, &MainWindow::buildTableSearch);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_openBD_clicked()
{
    if(ui->pB_openBD->isChecked()) {
        __db->connectDB(inipath);
        if(!__db->isOpen()) {
            __dbform->show();
        }
    }
    else {
        __db->disconnectDB();
    }
}

void MainWindow::openState() {
    ui->pB_openBD->setText("Отключиться");
    ui->label->setText("Подключен к БД");
    ui->label->setStyleSheet("color:green");
    ui->pB_search->setEnabled(true);

    ui->pb_view->setEnabled(true);
    ui->lE_search->setEnabled(true);
}

void MainWindow::closedState() {
    ui->pB_openBD->setText("Подключиться");
    ui->label->setText("Отключен от БД");
    ui->label->setStyleSheet("color:red");
    ui->pB_search->setEnabled(false);
    ui->pb_view->setEnabled(false);
    ui->lE_search->setEnabled(false);
    ui->lE_search->clear();
    __modelSe->clear();
}

void MainWindow::on_pb_view_clicked()
{
    __dbviewall->show();
}


void MainWindow::on_pB_search_clicked()
{
    emit getSignalSearch();
}

void MainWindow::buildTableSearch() {
    QString text = ui->lE_search->text();
    QStringList wordList = text.split(" ", Qt::SkipEmptyParts);
    QStringList placeholders;
    for (int i = 0; i < wordList.size(); ++i) {
        placeholders << "?";
    }
    QString queryString = QString("SELECT d.path, SUM(wd.frequency) AS relevance FROM words_documents wd JOIN words w ON w.id = wd.word_id JOIN documents d ON d.id = wd.document_id WHERE w.word IN (%1) GROUP BY d.id  order by relevance desc LIMIT 10;").arg(placeholders.join(", "));
    QSqlQuery querySe;
    querySe.prepare(queryString);
    foreach (const QString &item, wordList) {
        querySe.addBindValue(item);
    }
    if(text.isEmpty()){
        QMessageBox::StandardButton emptySe;
        emptySe = QMessageBox::warning(
            this,
            "Внимание",
            "Введен пустой запрос, введите данные в поле поиска",
            QMessageBox::Ok
        );
        return;
    }
    querySe.exec();
   if(!querySe.next()) {
       ui->lE_search->clear();
        QMessageBox::StandardButton emptyQu;
        emptyQu = QMessageBox::warning(
            this,
            "Внимание",
            "Результаты отсутствуют, повторите поиск с другими словами",
            QMessageBox::Ok
        );
        return;
    }
    else {
    __modelSe->setQuery(std::move(querySe));

    // Устанавливаем заголовки столбцов
    __modelSe->setHeaderData(0, Qt::Horizontal, tr("Файл"));
    __modelSe->setHeaderData(1, Qt::Horizontal, tr("Релевантность"));

    // Привязываем модель к QTableView
     ui->tableView_2->setModel(__modelSe);
     ui->tableView_2->resizeColumnsToContents();
     ui->tableView_2->resizeRowsToContents();
    }
}

