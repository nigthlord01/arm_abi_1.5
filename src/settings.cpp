#include "settings.h"
#include "ui_settings.h"
#include <QDateTime>
#include <QTimeZone>

settings::settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    QDateTime date_time = QDateTime::currentDateTime ();
    ui->comboBox->addItem(date_time.toString());
    date_time = QDateTime::currentDateTime().toTimeSpec(Qt::OffsetFromUTC);
    QString date_zone = date_time.toString(Qt::RFC2822Date);
    ui->comboBox->addItem(date_zone);

    QList<QByteArray> ids = QTimeZone::availableTimeZoneIds();
    foreach (QByteArray id, ids) {
    ui->comboBox_2->addItem(id);}
//    dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
//    dateTimeEdit2->setDisplayFormat("yyyy/MM/dd HH-mm-ss");
//    dateEdit->setDisplayFormat("yyyy.M.d");
//    timeEdit->setDisplayFormat("H:mm");
    //https://russianblogs.com/article/42771250233/
}

settings::~settings()
{
    delete ui;
}
