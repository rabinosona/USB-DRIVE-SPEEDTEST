#include "mainw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainw w;
    w.show();

    return a.exec();
}
