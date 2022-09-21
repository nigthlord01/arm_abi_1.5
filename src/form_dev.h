#ifndef FORM_DEV_H
#define FORM_DEV_H
//#include "abi.h"
#include <QWidget>

namespace Ui {
class form_dev;
}

class form_dev : public QWidget
{
    Q_OBJECT

public:
    explicit form_dev(QString mtxt, QWidget *parent = 0);
    ~form_dev();

private slots:
    void on_bt_ares_clicked();
    void on_bt_audres_clicked();

private:
    Ui::form_dev *ui;
    QString rtxt;
signals:
};

#endif // FORM_DEV_H
