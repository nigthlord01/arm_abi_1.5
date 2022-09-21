#include "authenticator.h"
#include "ui_authenticator.h"
#include "abi.h"
#include <QApplication>
#include <QTabWidget>
#include <QMessageBox>


Authenticator::Authenticator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authenticator)
{
    ui->setupUi(this);
}

Authenticator::~Authenticator()
{
    delete ui;
}

void Authenticator::on_pushButton_clicked()
{
    if ((ui->lineEdit->text () == "admin") & (ui->lineEdit_2->text () == "admin" ))
    {
        abi *cp = new abi ();
        cp->show ();

    }
    else {
        QMessageBox::warning(this, "Warning","Errow password");
        ui->lineEdit->clear ();
        ui->lineEdit_2->clear ();

    }
}

void Authenticator::on_pushButton_2_clicked()
{
    QWidget::close();
}
