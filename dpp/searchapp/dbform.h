#ifndef DBFORM_H
#define DBFORM_H

#include <QDialog>

namespace Ui {
class dbform;
}

class dbform : public QDialog
{
    Q_OBJECT

public:
    explicit dbform(QWidget *parent = nullptr);
    ~dbform();

public slots:
void debugInfo(QString text);

private slots:
void on_pB_close_clicked();

private:
    Ui::dbform *ui;
};

#endif // DBFORM_H
