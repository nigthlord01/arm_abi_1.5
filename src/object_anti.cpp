#include "object_anti.h"
#include "ui_object_anti.h"

Object_Anti::Object_Anti(QString str, QString str_1, QString str_2 , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Object_Anti)
{

    ui->setupUi(this);
    ui->tableWidget->item(0,0)->setText(str);
    ui->tableWidget->item(1,0)->setText(str_1);
    ui->tableWidget->item(2,0)->setText(str_2);
}

Object_Anti::~Object_Anti()
{
    delete ui;
}

void Object_Anti::on_pushButton_clicked()
{
    int i = 0;
    while (i<=2)
    {
         ui->tableWidget->item(i,0)->setCheckState(Qt::Checked);
         i+=1;
    }
}

void Object_Anti::on_pushButton_2_clicked()
{
    int i = 0;
    while (i<=2)
    {
         ui->tableWidget->item(i,0)->setCheckState(Qt::Unchecked);
         i+=1;
    }
}
