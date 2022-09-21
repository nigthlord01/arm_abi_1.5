#ifndef OBJECT_ANTI_H
#define OBJECT_ANTI_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class Object_Anti;
}

class Object_Anti : public QMainWindow
{
    Q_OBJECT

public:
    explicit Object_Anti(QString str, QString str_1, QString str_2, QWidget *parent = 0);
    QString str;
    ~Object_Anti();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Object_Anti *ui;
};

#endif // OBJECT_ANTI_H
