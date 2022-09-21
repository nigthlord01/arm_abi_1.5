#include "abi.h"
#include "authenticator.h"
#include <QApplication>
#include <QTabWidget>
#include "filesystem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Authenticator w;

    abi w;
    //FileSystem w;
    w.show();



    return a.exec();
}
