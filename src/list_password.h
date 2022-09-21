#ifndef LIST_PASSWORD_H
#define LIST_PASSWORD_H

#include <QWidget>
//#include <QPrintDialog>
#include <QPrinter>

namespace Ui {
class list_password;
}

class list_password : public QWidget
{
    Q_OBJECT

public:
    explicit list_password( QString pass,QWidget *parent = 0);
    ~list_password();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::list_password *ui;
    QString pass;
    };

#endif // LIST_PASSWORD_H
