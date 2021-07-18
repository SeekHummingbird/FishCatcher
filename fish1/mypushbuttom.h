#ifndef MYPUSHBUTTOM_H
#define MYPUSHBUTTOM_H

#include <QPushButton>

class MyPushButtom : public QPushButton
{
    Q_OBJECT
public:
    MyPushButtom(QString normalImg,QString pressImg="");
    QString normalPath;
    QString pressPath;
    void returnBtnclick();//自定义槽函数
signals:

public slots:
};

#endif // MYPUSHBUTTOM_H
