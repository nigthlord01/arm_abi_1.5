#include "mand_seiting.h"
#include "ui_mand_seiting.h"

mand_seiting::mand_seiting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mand_seiting)
{
    ui->setupUi(this);
}

mand_seiting::~mand_seiting()
{
    delete ui;
}
