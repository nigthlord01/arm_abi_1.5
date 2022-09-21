#ifndef CHPASS_H
#define CHPASS_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class chpass;

}

class chpass : public QMainWindow
{

    Q_OBJECT

public:
    explicit chpass(QString R_1, QWidget *parent);
    ~chpass();

private slots:
    void on_pb_NewPass_clicked();

    void on_pb_AddToFile_clicked();

    void on_pb_print_clicked();

private:
    void buck_Chifr();
    void chif();
    void buck();
    Ui::chpass *ui;
    QString rnd,R_1,item_ ;
};

#endif // CHPASS_H
