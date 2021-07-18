#ifndef RULEWIDGET_H
#define RULEWIDGET_H

#include <QWidget>
#include<QIcon>
#include<QBrush>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include <QSound>

class rulewidget : public QWidget
{
    Q_OBJECT
public:
    explicit rulewidget(QWidget *parent = nullptr);

private:
     QPushButton* returnbtn;

     QSound* backgroundSound = new QSound("music/menu.wav",this);//设置背景音乐

public slots:
     void returnbtnclick();//自定义槽函数
};

#endif // RULEWIDGET_H
