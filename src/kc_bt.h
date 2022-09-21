#ifndef KC_BT_H
#define KC_BT_H

#include <QWidget>

namespace Ui {
class kc_bt;
}

class kc_bt : public QWidget
{
    Q_OBJECT

public:
    explicit kc_bt(QString str, QWidget *parent = 0);
    ~kc_bt();

private:
    Ui::kc_bt *ui;
};

#endif // KC_BT_H
