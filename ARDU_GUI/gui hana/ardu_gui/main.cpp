#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
   // w.setFixedSize(434,122);
    w.setWindowTitle("HAN CAR STATS");
    w.show();

    return a.exec();
}
