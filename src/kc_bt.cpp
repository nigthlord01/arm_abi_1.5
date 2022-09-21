#include "kc_bt.h"
#include "ui_kc_bt.h"

kc_bt::kc_bt(QString str, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kc_bt)
{
    ui->setupUi(this);
    ui->label->setText(str);
}

kc_bt::~kc_bt()
{
    delete ui;
}
