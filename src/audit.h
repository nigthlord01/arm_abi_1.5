#ifndef AUDIT_H
#define AUDIT_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class Audit;
}

class Audit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Audit(QString mtxt, QWidget *parent = 0);
    ~Audit();

private slots:
    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    Ui::Audit *ui;
    QString rtxt_1;
};

#endif // AUDIT_H
