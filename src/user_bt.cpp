#include "user_bt.h"
#include "ui_user_bt.h"
#include <QDebug>
#include "chpass.h"
#include "ui_chpass.h"


user_bt::user_bt(QString mtxt, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_bt)
{
    ui->setupUi(this);
    rtxt = mtxt;
    ui->label->setText (rtxt);
}

user_bt::~user_bt()
{
    delete ui;
}


void user_bt::on_Chabt_clicked()
{
    chpass *cp = new chpass(rtxt, this);
    cp->show ();
}

