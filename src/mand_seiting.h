#ifndef MAND_SEITING_H
#define MAND_SEITING_H

#include <QWidget>

namespace Ui {
class mand_seiting;
}

class mand_seiting : public QWidget
{
    Q_OBJECT

public:
    explicit mand_seiting(QWidget *parent = 0);
    ~mand_seiting();

private:
    Ui::mand_seiting *ui;
};

#endif // MAND_SEITING_H
