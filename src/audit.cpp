#include "audit.h"
#include "ui_audit.h"
#include "audit_settings.h"

Audit::Audit(QString mtxt, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Audit)
{
    ui->setupUi(this);
    rtxt_1 = mtxt;
    ui->label->setText("Аудит ресурсов " + rtxt_1);
}

Audit::~Audit()
{
    delete ui;
}

void Audit::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    if (currentColumn==1) {
        audit_settings *as = new audit_settings( );
        as->show();
    }
}
