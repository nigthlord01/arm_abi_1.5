#include "form_dev.h"
#include "ui_form_dev.h"
#include <QDebug>
#include "access_to_resources.h"
#include "audit.h"

form_dev::form_dev(QString mtxt, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dev)
{
    ui->setupUi(this);
    rtxt = mtxt;
    ui->Info->setText (rtxt);
}

form_dev::~form_dev()
{
    delete ui;
}

void form_dev::on_bt_ares_clicked()
{
    access_to_resources *cp = new access_to_resources(rtxt, this);
    cp->show ();
    //QString fileName = QFileDialog::getOpenFileName(this,
    //QString::fromUtf8("OpenFile"),
    //QDir::currentPath(),
    //"Base (*.txt);;All files (*.*)");
    //qDebug()<< "111";
    //emit sigFocusOut();
     //ui->Info->setText(QString::number(col_)+"+"+QString::number(row_));
}


void form_dev::on_bt_audres_clicked()
{
    Audit *au = new Audit(rtxt,this);
    au->show();
}
