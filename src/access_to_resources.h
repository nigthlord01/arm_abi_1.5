#ifndef ACCESS_TO_RESOURCES_H
#define ACCESS_TO_RESOURCES_H

#include <QWidget>
#include <QMainWindow>
//#include "mand_seiting.h"

namespace Ui {
class access_to_resources;
}

class access_to_resources : public QMainWindow
{
    Q_OBJECT

public:
    explicit access_to_resources(QString mtxt, QWidget *parent = 0);
    ~access_to_resources();

private slots:
    //void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    Ui::access_to_resources *ui;
    QString mtxt_1;

};

#endif // ACCESS_TO_RESOURCES_H
