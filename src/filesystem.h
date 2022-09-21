#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class FileSystem;
}

class FileSystem : public QWidget
{
    Q_OBJECT

public:
    explicit FileSystem(QWidget *parent = 0);
    ~FileSystem();

private slots:

    void on_treeView_expanded(const QModelIndex &index);

    void on_treeView_entered(const QModelIndex &index);

  //  void on_treeView_iconSizeChanged(const QSize &size);

    void on_treeView_activated(const QModelIndex &index);

    void on_treeView_pressed(const QModelIndex &index);

private:
    Ui::FileSystem *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
};

#endif // FILESYSTEM_H
