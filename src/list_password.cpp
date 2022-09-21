#include "list_password.h"
#include "ui_list_password.h"
#include "QPlainTextEdit"
#include <QPrinter>
#include <QPrintDialog>

list_password::list_password(QString pass,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_password)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText(pass);
}

list_password::~list_password()
{
    delete ui;
}

void list_password::on_pushButton_clicked()
{

    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle("Печать списка паролей");
    if(dialog.exec() == QDialog::Accepted)
    {
        ui->plainTextEdit->print(&printer);
    }

}

void list_password::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();

}
