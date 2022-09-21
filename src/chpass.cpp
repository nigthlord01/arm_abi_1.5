#include "chpass.h"
#include "ui_chpass.h"
#include <QTextBrowser>
#include <QDebug>
#include <QPrintDialog>
#include <QPrinter>
#include <QMessageBox>

chpass::chpass(QString R_1, QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::chpass)
{
    ui->setupUi(this);
    ui->text_number->text() = "";
    item_ = R_1;
    ui->lb_user->setText(R_1);

}

chpass::~chpass()
{
    delete ui;
}

void chpass::on_pb_NewPass_clicked()
{
/*
    int num = ui->text_number->text().toInt();
    rnd = "";
    ui->text_Password->setText(QString(item_ + ": "));
    if (ui->check_b->isChecked() & ui->check_num->isChecked())
    {
        if ((num % 2) == 0){
        for (int i=0; i< (num/2); i++)
        {
            rnd =rnd + QString(QChar('A' + char(qrand() % ('Z' - 'A'))) + QString::number(qrand()%(1 - 9)) );
        }
        ui->text_Password->append(QString(rnd));
        }
        else {
            for (int i=0; i< (num/2); i++)
            {
                rnd = rnd + QString(QChar('A' + char(qrand() % ('Z' - 'A'))) + QString::number(qrand()%(1 - 9)) );
            }
            rnd= rnd + QString::number(qrand()%(1 - 9));
            ui->text_Password->append(QString(rnd));}}
    else if (ui->check_num->isChecked()){
        for (int i=0; i<num; i++)
        {
            rnd = rnd+QString::number(qrand()%(1 - 9) );
        }
            ui->text_Password->append(QString(rnd));
    }
    else if (ui->check_b->isChecked()){
        for (int i=0; i<num; i++)
        {
            rnd = rnd+QString(QChar('A' + char(qrand() % ('Z' - 'A'))) );
        }
            ui->text_Password->append(QString(rnd));
    }
    else {
         ui->text_Password->clear();
         QMessageBox::warning(this, "Warning","Errow password");

    }*/
   /* int num = ui->text_number->text().toInt();
    ui->check_b->isch
    switch (ui->check_b->isChecked() , ui->check_num->isChecked()){

    case (1 , 1):
        ui->text_Password->setText(QString(item_ + ": "));
        if ((num % 2) == 0){
        for (int i=0; i< (num/2); i++)
        {
            rnd =rnd + QString(QChar('A' + char(qrand() % ('Z' - 'A'))) + QString::number(qrand()%(1 - 9)) );
        }
        ui->text_Password->append(QString(rnd));
        }
        else {
            for (int i=0; i< (num/2); i++)
            {
                rnd = rnd + QString(QChar('A' + char(qrand() % ('Z' - 'A'))) + QString::number(qrand()%(1 - 9)) );
            }
            rnd= rnd + QString::number(qrand()%(1 - 9));
            ui->text_Password->append(QString(rnd));}
            break;
    case (0 , 1):
        ui->text_Password->setText(QString(item_ + ": "));
        for (int i=0; i<num; i++)
        {
            rnd = rnd+QString::number(qrand()%(1 - 9) );
        }
            ui->text_Password->append(QString(rnd));
    break;
      case (1 , 0) :
        ui->text_Password->setText(QString(item_ + ": "));
        for (int i=0; i<num; i++)
        {
            rnd = rnd+QString(QChar('A' + char(qrand() % ('Z' - 'A'))) );
        }
            ui->text_Password->append(QString(rnd));
    break;
      case (0 , 0):
        QMessageBox::warning(this, "Warning","Errow password");
}*/
rnd = "";
if (ui->text_number->text() != ""){
    if (ui->check_b->isChecked() & ui->check_num->isChecked()){
        buck_Chifr();
    }
    else if (ui->check_b->isChecked()){
        buck();
    }
    else if (ui->check_num->isChecked()){
        chif();
    }
    else{
         QMessageBox::warning(this, "Warning","Errow chekbox password");
    }
}
else{
    QMessageBox::warning(this, "Warning","Errow number password ");
}
 }
void chpass:: buck()
{
    int num = ui->text_number->text().toInt();
    ui->text_Password->setText(QString(item_ + ": "));
    for (int i=0; i<num; i++)
    {

//        int rnd1 = qrand();
//        int rnd2 = qrand();
//        if (rnd1 == qMax(rnd1, rnd2))


        rnd = rnd+QString(QChar('A' + char(qrand() % ('Z' - 'A'))) );
    }
        ui->text_Password->append(QString(rnd));

}

void chpass:: chif()
{
    int num = ui->text_number->text().toInt();
    ui->text_Password->setText(QString(item_ + ": "));
    for (int i=0; i<num; i++)
    {
        rnd = rnd+QString::number(qrand()%(1 - 9) );
    }
        ui->text_Password->append(QString(rnd));
}

void chpass:: buck_Chifr()
{
    int num = ui->text_number->text().toInt();
    ui->text_Password->setText(QString(item_ + ": "));
    if ((num % 2) == 0){
    for (int i=0; i< (num/2); i++)
    {
        rnd =rnd + QString(QChar('A' + char(qrand() % ('Z' - 'A'))) + QString::number(qrand()%(1 - 9)) );
    }
    ui->text_Password->append(QString(rnd));
    }
    else {
        for (int i=0; i< (num/2); i++)
        {
            rnd = rnd + QString(QChar('A' + char(qrand() % ('Z' - 'A'))) + QString::number(qrand()%(1 - 9)) );
        }
        rnd= rnd + QString::number(qrand()%(1 - 9));
        ui->text_Password->append(QString(rnd));}
}




void chpass::on_pb_AddToFile_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle("Печать пароля");
    if(dialog.exec() == QDialog::Accepted)
    {
        ui->text_Password->print(&printer);
}
}
void chpass::on_pb_print_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle("Печать пароля");
    if(dialog.exec() == QDialog::Accepted)
    {
        ui->text_Password->print(&printer);
}}
