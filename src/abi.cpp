#include "abi.h"
#include "ui_abi.h"
#include <QFileDialog>
#include <QTableWidget>
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QPlainTextEdit>
#include <QMessageBox>
#include "user_bt.h"
#include "kc_bt.h"
#include "form_dev.h"
#include "object_anti.h"
#include "settings.h"
#include "object_kc.h"
#include <QDateTime>
#include <QDate>
#include <QSqlQuery>
#include "QMessageBox"

abi::abi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::abi)
{
    ui->setupUi(this);
    QDateTime dateTime = QDateTime::currentDateTime ();
    ui->dateTimeEdit_from->setDateTime(dateTime);
    dateTime =  QDateTime::currentDateTime ().addDays(365);
    ui->dateTimeEdit_to->setDateTime(dateTime);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../data/abi.db");

    if (!db.open()){
        qDebug()<<db.lastError().databaseText();
        return;
    };

    QString qstr =QString ("SELECT * FROM %1").arg("users");
    QSqlQuery query(Myquery(qstr));
    int c = ui->tableWidget_2->columnCount();
    while (query.next()) {
        j=ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(j);
        QSqlRecord rec = query.record();
        if(rec.count()!=c)
        {
            qDebug()<<"err count users";
            break;
        }
        for (int i = 0; i< rec.count();i++){

            QString str = query.value(i).toString();
            // qDebug()<<str;//<< rec.fieldName(i);;
            ui->tableWidget_2->setItem(j,i,new QTableWidgetItem(str));
            if (QString("Статус") == rec.fieldName(i)){
                if (ui->tableWidget_2->item(j,i)->text()=="Активен"){
                    ui->tableWidget_2->item(j, i)->setTextColor(QColor(21, 116, 36));

                }
                if (  ui->tableWidget_2->item(j,i)->text()=="Заблокирован"){
                    ui->tableWidget_2->item (j,i)->setTextColor(QColor(155, 0, 0));}
            }
        }

    }
    qstr =QString ("SELECT name, date FROM %1").arg("devices");
    //    QSqlQuery query;
    query =Myquery(qstr);
    //    c = ui->tableWidget->columnCount();
    while (query.next()) {
        j=ui->tableWidget->rowCount();
        _rowcount=ui->tableWidget->rowCount()+1;
        ui->tableWidget->insertRow(j);
        QSqlRecord rec = query.record();
        for (int i = 0; i< rec.count();i++){
            QString str = query.value(i).toString();
            //qDebug()<<str;// << rec.fieldName(i);
            ui->tableWidget->setItem(j,i,new QTableWidgetItem(str));
            ui->tableWidget->hide();


        }


    }

    qstr =QString ("SELECT * FROM %1").arg("control");
    query =Myquery(qstr);
    c = ui->tableWidget_3->columnCount();

    while (query.next()) {
        j=ui->tableWidget_3->rowCount();
        ui->tableWidget_3->insertRow(j);

        QSqlRecord rec = query.record();
        if(rec.count()!=c)
        {
            qDebug()<<"err count control";
            break;
        }
        for (int i = 0; i< rec.count();i++){

            QString str = query.value(i).toString();
            ui->tableWidget_3->setItem(j,i,new QTableWidgetItem(str));
            if (QString("Дата и время проведения КЦ, результат") == rec.fieldName(i))
                if (0<=str.indexOf(" не "))
                {
                    ui->tableWidget_3->item(j, i)->setTextColor(QColor(21, 116, 36));

                }else{
                    ui->tableWidget_3->item (j,i)->setTextColor(QColor(155, 0, 0));
                }


        }


    }



    qstr =QString ("SELECT * FROM %1").arg("antivirus");
    query =Myquery(qstr);
    c = ui->tableWidget_4->columnCount();
    while (query.next()) {
        j=ui->tableWidget_4->rowCount();
        ui->tableWidget_4->insertRow(j);
        QSqlRecord rec = query.record();
        if(rec.count()!=c)
        {
            qDebug()<<"err count antivirus";
            break;
        }
        for (int i = 0; i< rec.count();i++){

            QString str = query.value(i).toString();
            ui->tableWidget_4->setItem(j,i,new QTableWidgetItem(str));

            if (QString("Дата и время проведения проверки, результат") == rec.fieldName(i))
                if (0<=str.indexOf(" не "))
                {
                    ui->tableWidget_4->item(j, i)->setTextColor(QColor(21, 116, 36));

                }else{
                    ui->tableWidget_4->item (j,i)->setTextColor(QColor(155, 0, 0));
                }
        }
    }


    qstr =QString ("SELECT * FROM %1").arg("testing");
    query =Myquery(qstr);
    c = ui->tableWidget_5->columnCount();
    while (query.next()) {
        j=ui->tableWidget_5->rowCount();
        ui->tableWidget_5->insertRow(j);
        QSqlRecord rec = query.record();
        if(rec.count()!=c)
        {
            qDebug()<<"err count testing";
            break;
        }
        for (int i = 0; i< rec.count();i++){
            QString str = query.value(i).toString();
            ui->tableWidget_5->setItem(j,i,new QTableWidgetItem(str));
        }
    }

    qstr =QString ("SELECT * FROM %1").arg("backup");
    query =Myquery(qstr);
    c = ui->tableWidget_6->columnCount();
    while (query.next()) {
        j=ui->tableWidget_6->rowCount();
        ui->tableWidget_6->insertRow(j);
        QSqlRecord rec = query.record();
        if(rec.count()!=c)
        {
            qDebug()<<"err count backup";
            break;
        }
        for (int i = 0; i< rec.count();i++){
            QString str = query.value(i).toString();
            //qDebug()<<str;//<< rec.fieldName(i);;
            ui->tableWidget_6->setItem(j,i,new QTableWidgetItem(str));
        }
    }



    qstr =QString ("SELECT * FROM %1").arg("magazines");
    query =Myquery(qstr);
    c = ui->tableWidget_7->columnCount();
    while (query.next()) {
        j=ui->tableWidget_7->rowCount();
        ui->tableWidget_7->insertRow(j);
        QSqlRecord rec = query.record();
        if(rec.count()!=c)
        {
            qDebug()<<"err count magazines";
            break;
        }
        for (int i = 0; i< rec.count();i++){

            QString str = query.value(i).toString();
            // qDebug()<<str;//<< rec.fieldName(i);;
            ui->tableWidget_7->setItem(j,i,new QTableWidgetItem(str));
        }
    }
    ui->tableWidget->resizeColumnsToContents ();
    ui->tableWidget_2->resizeColumnsToContents ();
    ui->tableWidget_3->resizeColumnsToContents ();
    ui->tableWidget_4->resizeColumnsToContents ();
    ui->tableWidget_5->resizeColumnsToContents ();
    ui->tableWidget_6->resizeColumnsToContents ();
    ui->tableWidget_7->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


QSqlQuery abi::Myquery(QString str)
{

    QSqlQuery qquery;
    qquery.prepare(str);
    if(!qquery.exec())
        qDebug()<< str <<" "<< qquery.lastError().databaseText();

    return qquery;

}

abi::~abi()
{
    delete ui;
}



void abi::on_obzor_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "*.txt ;;All files (*.*)");
    ui->lb_SelectStatus->setText(str);

}

void abi::on_bt_Unlock_clicked()
{
    time = 1;
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++)
    {
        for (int j=0; j< ui->tableWidget_2->columnCount(); j++)

            if (ui->tableWidget_2->item(i,j)->text()=="Заблокирован") {
                delay(time);
                ui->tableWidget_2->setItem(i,j,new QTableWidgetItem("Активен"));
                ui->tableWidget_2->item(i, j)->setTextColor(QColor(21, 116, 36));
            }
    }
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Все пользователи разблокированы"));
    qDebug()<<query.exec();
}

void abi::on_bt_PasswordCheck_clicked()
{
    QFile passwords("../tmp/passwords.txt");

    if  (passwords.open(QFile::ReadOnly))
    {
        str = passwords.readAll();
        list_password *lp = new list_password(str);
        lp->show();

    }
}

void abi::on_pb_Update_clicked()
{
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Производится обновление кеша"));
    qDebug()<<query.exec();
    ui->pb_Update->setEnabled (false);
    ui->lb_Select_ZI->setText ("Обновление базы");
    time = 2;
    delay (time);

    QMessageBox msgBox;
    QString s = QString("%1 %2 %3").arg("Кеш обновлён. Добавлено").arg(_rowcount).arg("устройства. Ошибок 8");
    msgBox.setGeometry(40, 50, 500, 500);
    msgBox.setWindowTitle("Кеш");
    msgBox.setText(s);
    msgBox.setStyleSheet("background-color: rgb(255,251,173)");
    msgBox.exec();

    ui->verticalSpacer->changeSize(0,0,QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->tableWidget->show();
    for (i=0;i<ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(date_time.toString()+"\n\nУстройство готово к работе"));
        ui->tableWidget->item(i, 1)->setTextColor(QColor(21, 116, 36));
    }
    //    ui->verticalSpacer->changeSize(0,0,QSizePolicy::Minimum, QSizePolicy::Minimum);

    ui->lb_Select_ZI->setText ("База обновлена");
    delay (time);
    ui->lb_Select_ZI->setText ("Выбор файла со списком стираемой ЗИ");
    ui->pb_Update->setEnabled (true);
    //QDateTime date_time = QDateTime::currentDateTime ();

    date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg(s));
    qDebug()<<query.exec();
}

void abi::delay(int ton)
{
    int Tin = ton;
    QTime dieTime= QTime::currentTime().addSecs(Tin);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

void abi::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int  previousColumn)
{
    if(currentRow == previousRow ){
        ui->tableWidget->item(previousRow,0)->setTextColor(QColor("Black"));
        ui->tableWidget->removeCellWidget(previousRow,0);

    }

    if (currentColumn == 0 )
    {
        QTableWidgetItem *twi =ui->tableWidget->item (currentRow,0);
        QString str =twi->text();
        ui->tableWidget->item(currentRow, currentColumn)->setTextColor(QColor("White"));
        form_dev *fd = new form_dev(str,this);
        ui->tableWidget->setCellWidget(currentRow,0,fd);
        // ui->tableWidget->resizeColumnsToContents ();
        ui->tableWidget->resizeRowToContents(currentRow);
    }
    if (previousRow!=-1){
        ui->tableWidget->item(previousRow,0)->setTextColor(QColor("Black"));
        ui->tableWidget->removeCellWidget(previousRow,0);
    }
}

void abi::on_pb_ClearZI_clicked()
{
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Производится Удаление ЗИ"));
    qDebug()<<query.exec();
    ui->pb_ClearZI->setEnabled (false);
    ui->Delete->setText ("Удаление базы");
    time = 2;
    ui->Delete->setText ("Файл удален");
    delay (time);
    ui->Delete->setText ("");
    ui->pb_ClearZI->setEnabled (true);
    date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Удаление ЗИ произведено"));
    qDebug()<<query.exec();

}

void abi::on_tableWidget_2_currentCellChanged(int currentRow, int currentColumn, int previousRow)
{
    if(currentRow == previousRow){
        ui->tableWidget_2->item(previousRow,0)->setTextColor(QColor("Black"));
        ui->tableWidget_2->removeCellWidget(previousRow,0);

    }
    if (currentColumn == 0)
    {
        QTableWidgetItem *twi =ui->tableWidget_2->item (currentRow,0);
        QString str =twi->text();
        ui->tableWidget_2->item(currentRow, currentColumn)->setTextColor(QColor("White"));
        user_bt *ub = new user_bt(str,this);
        j = ui->tableWidget_2->currentRow();
        ui->tableWidget_2->setCellWidget(currentRow,0,ub);


        //        ui->tableWidget_2->resizeColumnsToContents ();
        //        ui->tableWidget_2->setVisible(false);
        //        ui->tableWidget_2->setVisible(true);
        //       ui->tableWidget_2->resizeColumnToContents (0);
        //       ui->tableWidget_2->resizeEvent(1);
        //        ui->tableWidget_2->setItem(0,1,new QTableWidgetItem("asdasdasdddsfdsfssssdassdasdasdasdasd"));
        //      ui->tableWidget_2->
        //      ui->tableWidget_2->resize();

        //      ui->tableWidget_2->resi
        //         ui->tableWidget_2->resizeColumnToContents (0);
        //       ui->tableWidget_2->resizeColumnToContents (1);
        //       ui->tableWidget_2->resizeColumnToContents (2);
        //       ui->tableWidget_2->resizeColumnToContents (3);

        //       ui->tableWidget_2->resi

        ui->tableWidget_2->resizeRowToContents(currentRow);
        ui->tableWidget_2->resizeColumnToContents(0);

        connect(ub, SIGNAL(on_pushButton_2_clicked()),this, SLOT(setText_block()));
    }
    if (previousRow!=-1){
        ui->tableWidget_2->item(previousRow,0)->setTextColor(QColor("Black"));
        ui->tableWidget_2->removeCellWidget(previousRow,0);
    }

}

void abi:: setText_block()
{
    time = 1;
    if (ui->tableWidget_2->item(j,3)->text()=="Активен") {
        delay (time);
        ui->tableWidget_2->item(j,3)->setText("Заблокирован");
        ui->tableWidget_2->item (j,3)->setTextColor(QColor(155, 0, 0));
    }
}


void abi::on_tableWidget_3_currentCellChanged(int currentRow, int currentColumn, int previousRow)
{
    if(currentRow == previousRow){
        ui->tableWidget_3->item(previousRow,0)->setTextColor(QColor("Black"));
        ui->tableWidget_3->removeCellWidget(previousRow,0);

    }
    if (currentColumn == 0)
    {
        QTableWidgetItem *twi =ui->tableWidget_3->item (currentRow,0);
        QString str =twi->text();
        kc_bt *kb = new kc_bt(str,this);
        ui->tableWidget_3->item(currentRow, currentColumn)->setTextColor(QColor("White"));

        j = ui->tableWidget_3->currentRow();
        ui->tableWidget_3->setCellWidget(currentRow,0,kb);
        //        ui->tableWidget_3->resizeColumnsToContents ();
        ui->tableWidget_3->resizeRowToContents(currentRow);



    }
    if (previousRow!=-1){
        ui->tableWidget_3->item(previousRow,0)->setTextColor(QColor("Black"));
        ui->tableWidget_3->removeCellWidget(previousRow,0);
    }
}

void abi::on_pb_StartControl_clicked()
{
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Запущена проверка КЦ"));
    qDebug()<<query.exec();
    ui->tableWidget_3->setEnabled(false);
    ui->pb_StartControl->setEnabled (false);
    ui->tableWidget_3->setEnabled(true);
    Object_KC *ob_kc = new Object_KC();
    ob_kc->show();
    ui->lb_KC->setText ("выполняется сканирование");
    time = 2;
    delay (time);
    query.prepare(QString("DELETE FROM control "));
    qDebug()<<query.exec();
    for (i = 0;i<ui->tableWidget_3->rowCount();i++){
        randchan(i);
        query.prepare(QString("INSERT INTO control('Имя устройства (IP), описание','Дата и время проведения КЦ, результат')" "VALUES('%1','%2')").arg(ui->tableWidget_3->item(i,0)->text()).arg(ui->tableWidget_3->item(i,1)->text()));
        qDebug()<<query.exec();
    }

    ui->lb_KC->setText ("успешно");
    delay (time);
    ui->lb_KC->setText ("");
    ui->pb_StartControl->setEnabled (true);
    ui->tableWidget_3->setEnabled(true);

    if (!db.open()){
        qDebug()<<db.lastError().databaseText();
        return;
    };
    date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Завершена проверка КЦ"));
    qDebug()<<query.exec();
}
void abi::randwar(int i)    // ui->comboBox->addItem(date_time.toString());
{

    QDateTime date_time = QDateTime::currentDateTime ();
    QString TF = QString::number(qrand()%(1 - 100)) ;
    if ((TF.toInt() % 2) == 0)
    {
        ui->tableWidget_4->setItem(i,1,new QTableWidgetItem(date_time.toString()+"\n\nугроз не обнаружено"));
        ui->tableWidget_4->item(i, 1)->setTextColor(QColor(21, 116, 36));
    }
    else
    {
        QString st= date_time.toString()+"\n\nобнаружено "+TF+" угроз";
        ui->tableWidget_4->setItem(i,1,new QTableWidgetItem(st));
        ui->tableWidget_4->item (i,1)->setTextColor(QColor(155, 0, 0));
    }


}
void abi::randchan(int i)
{
    st = "";    QDateTime date_time = QDateTime::currentDateTime ();
    QString TF = QString::number(qrand()%(1 - 3 )) ;
    if ((TF.toInt() % 2) == 0)
    {
        st=date_time.toString()+ "\n\nизменений не обнаружено";
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(st));
        ui->tableWidget_3->item(i, 1)->setTextColor(QColor(21, 116, 36));

    }
    else
    {

        st=date_time.toString()+"\n\nобнаружено "+TF+" изменений";
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(st));
        ui->tableWidget_3->item (i,1)->setTextColor(QColor(155, 0, 0));


    }

}

void abi::randtest(int i)
{

    QDateTime date_time = QDateTime::currentDateTime ();
    QString TF = QString::number(qrand()%(1 - 20)) ;
    if ((TF.toInt() % 2) == 0) {
        ui->tableWidget_5->setItem(i,1,new QTableWidgetItem(date_time.toString()+QString::number(i)+"\n\nошибок не обнаружено"));
        ui->tableWidget_5->item(i, 1)->setTextColor(QColor(21, 116, 36));
    }
    else {
        QString st= date_time.toString()+"\n\nобнаружено "+TF+" Ошибок";
        ui->tableWidget_5->setItem(i,1,new QTableWidgetItem(st));
        ui->tableWidget_5->item (i,1)->setTextColor(QColor(155, 0, 0));
    }


}
void abi::on_pb_StartAntivirus_clicked()
{
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Запущена Антивирусная проверка"));
    qDebug()<<query.exec();
    ui->pb_StartAntivirus->setEnabled (false);
    ui->lb_anti->setText ("выполняется сканирование");
    time = 2;
    delay (time);
    query.prepare(QString("DELETE FROM antivirus"));
    qDebug()<<query.exec();
    for (i = 0;i<ui->tableWidget_4->rowCount();i++){
        //   qDebug()<<QString::number(i)<<"i";
        randwar(i);
        query.prepare(QString("INSERT INTO antivirus('Имя устройства (IP), описание','Дата и время проведения проверки, результат')" "VALUES('%1','%2')").arg(ui->tableWidget_4->item(i,0)->text()).arg(ui->tableWidget_4->item(i,1)->text()));
        qDebug()<<query.exec();
    }
    ui->lb_anti->setText ("успешно");
    delay (time);
    ui->lb_anti->setText ("");
    ui->pb_StartAntivirus->setEnabled (true);
    date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Завершена Антивирусная проверка"));
    qDebug()<<query.exec();
}


void abi::on_pushButton_clicked()
{
    settings *set = new settings();
    set->show();
}

void abi::on_pb_CreateBackupALD_clicked()
{
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    if (!db.open()){
        qDebug()<<db.lastError().databaseText();
        return;
    };
    QDate date = QDate::currentDate();
    //QDateTime date_time = QDateTime::currentDateTime ();
    QString s = "/var/backups/ald/ald_backup_"+date.toString()+".tar";
    s = s.split(" ").join("_");
    i=ui->tableWidget_6->rowCount();
    ui->tableWidget_6->insertRow(i);
    date_time = QDateTime::currentDateTime ();

    ui->tableWidget_6->setItem(i,0,new QTableWidgetItem(date_time.toString()));
    ui->tableWidget_6->setItem(i,1, new QTableWidgetItem("1 Мб"));


    ui->tableWidget_6->setItem(i,2, new QTableWidgetItem(s));
    //ui->tableWidget_6->resizeColumnsToContents ();
    query.prepare(QString("INSERT INTO backup('Дата и время создания резервной копии','Размер','Путь к файлу','pic')" "VALUES('%1','%2','%3',NULL)").arg(date_time.toString()).arg("1 Мб").arg(s));
    date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Создана резервная копия ALD"));
    qDebug()<<query.exec();
}


void abi::on_pb_StartTestSZI_clicked()
{
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Запущена проверка СЗИ"));
    qDebug()<<query.exec();
    ui->pb_StartTestSZI->setEnabled (false);
    time = 2;
    ui->lb_SCI->setText ("выполняется сканирование");
    delay (time);
    for (i = 0;i<ui->tableWidget_5->rowCount();i++){
        //qDebug()<<QString::number(i)<<"i";
        randtest(i);
    }
    ui->lb_SCI->setText ("успешно");
    delay (time);
    ui->lb_SCI->setText ("");
    ui->pb_StartTestSZI->setEnabled (true);
    date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Запущена проверка СЗИ"));
    qDebug()<<query.exec();
}

void abi::on_pb_ClearMagazine_clicked()
{
    while(ui->tableWidget_7->rowCount()!=0)
    {
        ui->tableWidget_7->removeRow(0);
        QSqlQuery query;
        query.prepare(QString("DELETE FROM magazines"));
        QString error = query.lastError().text();
        if (query.exec())
            qDebug() << "DELETE ok";
        else
            qDebug() << error;
    }
    QSqlQuery query;
    QDateTime date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Журнал очищен"));
    qDebug()<<query.exec();
}


void abi::on_pb_ArchiveCurrentMagazin_clicked()
{
    if (!db.open()){
        qDebug()<<db.lastError().databaseText();
        return;
    };
    QDateTime date_time = QDateTime::currentDateTime ();
    QSqlQuery query;
    QString str_1 = "/var/ossec/logs/alerts/2022/Oct/ossec-alerts-06.log.125049.gz";
    query.prepare(QString("INSERT INTO magazines('Дата и время создания архива','Размер','Путь к файлу (на сервере OSSEC - abi.test.ru)')" "VALUES('%1','%2','%3')").arg(date_time.toString()).arg("174 байта").arg(str_1));
    j = ui->tableWidget_7->rowCount();
    ui->tableWidget_7->insertRow(j);
    ui->tableWidget_7->setItem(j,0,new QTableWidgetItem(date_time.toString()));
    ui->tableWidget_7->setItem(j,1,new QTableWidgetItem("174 байт"));
    ui->tableWidget_7->setItem(j,2,new QTableWidgetItem(str_1));
    qDebug()<<query.exec();
    date_time = QDateTime::currentDateTime ();
    query.prepare(QString("INSERT INTO jornal('Время','Действие')" "VALUES('%1','%2')").arg(date_time.toString()).arg("Журнал Архивирован"));
    qDebug()<<query.exec();
}


void abi::on_le_SearchDevice_textChanged(const QString &arg1)
{

}

void abi::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setGeometry(40, 50, 500, 500);
    msgBox.setWindowTitle("Журнал");
    QString qstr =QString ("SELECT * FROM %1").arg("jornal");
    QSqlQuery query(Myquery(qstr));
    //int c = ui->tableWidget_2->columnCount();
    while (query.next()) {
        QSqlRecord rec = query.record();

        for (int i = rec.count(); i>rec.count()-10 ;i--){

            fileName = query.value(i).toString();
            qDebug() << rec.count();


//            // qDebug()<<str;//<< rec.fieldName(i);;
//            ui->tableWidget_2->setItem(j,i,new QTableWidgetItem(str));
//            if (QString("Статус") == rec.fieldName(i)){
//                if (ui->tableWidget_2->item(j,i)->text()=="Активен"){
//                    ui->tableWidget_2->item(j, i)->setTextColor(QColor(21, 116, 36));

//                }
//                if (  ui->tableWidget_2->item(j,i)->text()=="Заблокирован"){
//                    ui->tableWidget_2->item (j,i)->setTextColor(QColor(155, 0, 0));}
//            }
        }

    }
//    QString s = QString("%1 %2 %3").arg("Кеш обновлён. Добавлено").arg(_rowcount).arg("устройства. Ошибок 0");
    msgBox.setText(fileName);
//    msgBox.setStyleSheet("background-color: rgb(255,251,173)");
msgBox.exec();


}
