#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *m_parent)
    : QMainWindow(m_parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lb_statusConnect->setStyleSheet("color:red");
    ui->pb_request->setEnabled(false);


    __dataDb = new DbData(this);
    __dataBase = new DataBase(this);
    __msg = new QMessageBox(this);
    __dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);


    __dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);


    connect(__dataDb, &DbData::sig_sendData, this, [&](QVector<QString> m_receivData){
        __dataForConnect = m_receivData;
    });


    connect(__dataBase, &DataBase::sig_SendDataFromDB,
            this, &MainWindow::ScreenDataFromDB);


    connect(__dataBase, &DataBase::sig_SendStatusConnection,
            this, &MainWindow::ReceiveStatusConnectionToDB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Открытие окна ввода данных для подключения
void MainWindow::on_act_addData_triggered()
{
    __dataDb->show();
}

// Обработка нажатия "Подключиться/Отключиться"
void MainWindow::on_act_connect_triggered()
{
    if (ui->lb_statusConnect->text() == "Отключено") {

        ui->lb_statusConnect->setText("Подключение");
        ui->lb_statusConnect->setStyleSheet("color:black");

        auto conn = [&]{ __dataBase->ConnectToDataBase(__dataForConnect); };
        QtConcurrent::run(conn);
    }
    else {

        __dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }
}


void MainWindow::on_pb_request_clicked()
{
    int currentIndex = ui->cb_category->currentIndex();
    int typeRequest;


    switch (currentIndex) {
    case 0:
        typeRequest = requestAllFilms;
        break;
    case 1:
        typeRequest = requestComedy;
        break;
    case 2:
        typeRequest = requestHorrors;
        break;
    default:
        typeRequest = requestAllFilms;
        break;
    }


    __dataBase->RequestToDB(typeRequest);
}

// Очистка отображаемой таблицы
void MainWindow::on_pb_clear_clicked()
{
    ui->tb_result->setModel(nullptr);
}

// Слот отображения полученных данных
void MainWindow::ScreenDataFromDB(QSqlQueryModel *m_model, int m_typeRequest)
{

    ui->tb_result->setModel(m_model);


    for (int i = 0; i < m_model->columnCount(); ++i) {
        ui->tb_result->showColumn(i);
    }


    if (m_typeRequest == requestAllFilms) {
        ui->tb_result->hideColumn(0);
        // Оставляем только title (1) и description (2), скрываем остальные
        for (int i = 3; i < m_model->columnCount(); ++i) {
            ui->tb_result->hideColumn(i);
        }
    }

    // Автоподстройка ширины столбцов
    ui->tb_result->resizeColumnsToContents();
    ui->tb_result->horizontalHeader()->setStretchLastSection(true);
}

// Слот обработки результата подключения
void MainWindow::ReceiveStatusConnectionToDB(bool m_status)
{
    if (m_status) {
        // Успех: меняем статус на зеленый, включаем кнопку запроса
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено к БД");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_request->setEnabled(true);
    }
    else {
        // Ошибка: отключаемся, выводим сообщение об ошибке, статус красный
        __dataBase->DisconnectFromDataBase(DB_NAME);
        __msg->setIcon(QMessageBox::Critical);
        __msg->setText(__dataBase->GetLastError().text());
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        __msg->exec();
    }
}
