#ifndef AUDIT_SETTINGS_H
#define AUDIT_SETTINGS_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class audit_settings;
}

class audit_settings : public QWidget
{
    Q_OBJECT

public:
    explicit audit_settings(QWidget *parent = 0);
    ~audit_settings();

private:
    Ui::audit_settings *ui;
};

#endif // AUDIT_SETTINGS_H
