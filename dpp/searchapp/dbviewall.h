#ifndef DBVIEWALL_H
#define DBVIEWALL_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class dbviewall;
}

class dbviewall : public QDialog
{
    Q_OBJECT

public:
    explicit dbviewall(QWidget *parent = nullptr);
    ~dbviewall();
public slots:
   void buildTable();
private:
    Ui::dbviewall *ui;
    QSqlQueryModel *__model;
};

#endif // DBVIEWALL_H
