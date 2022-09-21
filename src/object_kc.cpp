#include "object_kc.h"
#include "ui_object_kc.h"
#include <QSqlQuery>
#include <QDebug>

Object_KC::Object_KC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Object_KC)
{
    ui->setupUi(this);




//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("../data/abi.db");

//    if (!db.open()){
//        qDebug()<<db.lastError().databaseText();
//        return;
//    };

//    QString qstr =QString ("SELECT Имя устройства (IP), описание FROM %1").arg("devices");
//    QSqlQuery query (Myquery(qstr));
    QSqlQuery query;
         query.exec("SELECT name FROM devices");
    int c = ui->tableWidget->columnCount();
    while (query.next()) {
        j=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(j);
        QSqlRecord rec = query.record();
        if(rec.count()!=c)
        {
            qDebug()<<"err count";
            break;
        }
        for (int i = 0; i< rec.count();i++){

            QString str = query.value(i).toString();
            // qDebug()<<str;//<< rec.fieldName(i);;
            ui->tableWidget->setItem(j,i,new QTableWidgetItem(str));
            }
    }

//    QTableWidgetItem *temp = new QTableWidgetItem;
//    temp->setCheckState(Qt::Unchecked);
//    for (int i=0; i<ui->tableWidget->rowCount(); i++)
//    {
//        ui->tableWidget->setItem(i,0,temp);
//    }

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//     ui->tableWidget->resizeColumnsToContents ();
}

Object_KC::~Object_KC()
{
    delete ui;
}
