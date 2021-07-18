#include "widget.h"
#include"gamewidget.h"
 #include "rulewidget.h"
#include <QApplication>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //rulewidget w;

    w.show();


    return a.exec();
}
