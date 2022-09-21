#include "access_to_resources.h"
#include "ui_access_to_resources.h"
#include "mand_seiting.h"

access_to_resources::access_to_resources(QString mtxt, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::access_to_resources)
{
    ui->setupUi(this);
    mtxt_1= mtxt;
    ui->label->setText("Права доступа к ресурсам " + mtxt_1);

}

access_to_resources::~access_to_resources()
{
    delete ui;
}

/*void access_to_resources::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    if (ui->tableWidget->currentColumn() == 2)
    {

    }
}
*/

void access_to_resources::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    if (currentColumn==1) {
        mand_seiting *ms = new mand_seiting();
        ms->show();
    }
}
