#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <QDialog>

namespace Ui {
class Authenticator;
}

class Authenticator : public QDialog
{
    Q_OBJECT

public:
    explicit Authenticator(QWidget *parent = 0);
    ~Authenticator();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Authenticator *ui;
};

#endif // AUTHENTICATOR_H
