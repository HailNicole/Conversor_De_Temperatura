#include "conversor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Conversor w;
    w.show();
    return a.exec();
}
