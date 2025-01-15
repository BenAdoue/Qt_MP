#include "motionplanning.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MotionPlanning w;
    w.show();
    return a.exec();
}
