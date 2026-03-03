#include <QApplication>
#include <leds.h>
#include <mainwindow.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.init_elemenets_GUI();
    w.show();
    return a.exec();
}
