#ifndef ABI_H
#define ABI_H

#include <QMainWindow>
#include "list_password.h"
#include <QTime>
#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>

namespace Ui {
class abi;
class user_bt;
}

class abi : public QMainWindow
{
    Q_OBJECT

public:
    explicit abi(QWidget *parent = 0);
    ~abi();
    //QTimer * timer_up ;
    //QTimer * timer_del ;
    QString fileName;
    void randwar(int i);
    void randtest(int i);
    void randchan(int i);
    void delay(int ton);
    int i,j,time, pr, _rowcount;
    QSqlDatabase db;
    QSqlQuery Myquery(QString str);



private slots:

    void on_pb_StartControl_clicked();

    void on_pb_StartAntivirus_clicked();

    //void on_tableWidget_3_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_pushButton_clicked();

    void on_pb_CreateBackupALD_clicked();

    void on_pb_StartTestSZI_clicked();

    void on_pb_ClearMagazine_clicked();

    void on_pb_ArchiveCurrentMagazin_clicked();

//    void on_tableWidget_3_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_le_SearchDevice_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

public slots:
    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow,int previousColumn);
    void setText_block();
    void on_pb_Update_clicked();
    void on_obzor_clicked();
    void on_bt_Unlock_clicked();
    void on_bt_PasswordCheck_clicked();
    void on_pb_ClearZI_clicked();
    void on_tableWidget_2_currentCellChanged(int currentRow, int currentColumn, int previousRow);
    void on_tableWidget_3_currentCellChanged(int currentRow, int currentColumn, int previousRow);


private:
     QString st;
    QString str;
    //QSqlda

    Ui::abi *ui;
};

#endif // ABI_H
