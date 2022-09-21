#include "audit_settings.h"
#include "ui_audit_settings.h"

audit_settings::audit_settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::audit_settings)
{
    ui->setupUi(this);
}

audit_settings::~audit_settings()
{
    delete ui;
}
