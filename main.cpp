#include "simplenotepad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleNotepad w;
    w.show();

    return a.exec();
}
