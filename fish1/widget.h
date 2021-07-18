#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QIcon>
#include<QBrush>
#include<QLabel>
#include<QPushButton>
#include<QMessageBox>
#include<QVBoxLayout>
#include "easyview.h"
#include "commonview.h"
#include "hardview.h"
#include "rulewidget.h"
#include "setwidget.h"
#include <QSound>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    rulewidget* w1;
    setwidget *w2;

    static QSound *backgroundSound;

private:
    QLabel* label;
    QPushButton* startbtn;
    QPushButton* setbtn;
    QPushButton* helpbtn;
    QPushButton* quitbtn;
    QVBoxLayout* vboxlayout;

    Easyview* easyview;
    Commonview* commonview;
    Hardview* hardview;

public slots:
    void startbtnclick();//自定义槽函数
    void quitbtnclick();
    void helpbtnclick();
    void setbtnclick();

};



#endif // WIDGET_H
