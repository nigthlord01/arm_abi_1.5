#include "filesystem.h"
#include "ui_filesystem.h"
#include "QDebug"

FileSystem::FileSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileSystem)
{
    ui->setupUi(this);

    QString sPath = "~/.../.../";
    dirmodel = new QFileSystemModel(this);
     dirmodel->setRootPath(sPath);
     ui->treeView->setModel(dirmodel);
     ui->treeView->setColumnWidth(0,300);
    ui->treeView->expandAll();
//          ui->treeView->currentIndex();

}

FileSystem::~FileSystem()
{
    delete ui;
}



void FileSystem::on_treeView_expanded(const QModelIndex &index)
{

//    qDebug()<<ui->treeView->currentIndex();
   // qDebug()<< ui->treeView->rootIndex();

        //qDebug()<< ui->treeView->;
//    if (index.isValid()){

//        qDebug()<< ui->treeView->model()->rowCount();}
        qDebug()<< index.row();
}


void FileSystem::on_treeView_entered(const QModelIndex &index)
{
    //qDebug()<< ui->treeView->model()->rowCount(index);
}

void FileSystem::on_treeView_activated(const QModelIndex &index)
{
//    qDebug()<< index.row();
}

void FileSystem::on_treeView_pressed(const QModelIndex &index)
{
    qDebug()<< index.row();
}
