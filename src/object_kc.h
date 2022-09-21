#ifndef OBJECT_KC_H
#define OBJECT_KC_H

#include <QWidget>
#include <QTime>
#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>

namespace Ui {
class Object_KC;
}

class Object_KC : public QWidget
{
    Q_OBJECT

public:
    explicit Object_KC(QWidget *parent = 0);
    QSqlDatabase db;
    QSqlQuery Myquery(QString str);
    int j;
    ~Object_KC();

private:
    Ui::Object_KC *ui;
        QString str;
};

#endif // OBJECT_KC_H
