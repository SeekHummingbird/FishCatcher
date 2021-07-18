#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>
#include<QIcon>
#include<QBrush>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include "rulewidget.h"
//#include "widget.h"
#include <QSound>

class setwidget : public QWidget
{
    Q_OBJECT
public:
    explicit setwidget(QWidget *parent = nullptr);

    static int difficultyChosen;

private:
    QLabel* label;
    QLabel* dif_label;

    QPushButton* musicbtn;
    QPushButton* difficultybtn;
    QPushButton* returnbtn;
    QVBoxLayout* vboxlayout;

    QWidget *parent;

    QSound* backgroundSound = new QSound("music/menu.wav",this);//设置背景音乐

public slots:
    void musicbtnclick();
    void difficultybtnclick();
    void returnbtnclick();
};

#endif // SETWIDGET_H
