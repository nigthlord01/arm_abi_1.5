#ifndef USER_BT_H
#define USER_BT_H
#include <QWidget>

namespace Ui {
class user_bt;
class abi;
}

class user_bt : public QWidget
{
    Q_OBJECT

public:
    explicit user_bt(QString mtxt, QWidget *parent = 0);
    ~user_bt();
signals:
    void on_pushButton_2_clicked();

private slots:
    void on_Chabt_clicked();

private:
    Ui::user_bt *ui;
    Ui::abi *abi_1;
    QString rtxt;

};


#endif // USER_BT_H
