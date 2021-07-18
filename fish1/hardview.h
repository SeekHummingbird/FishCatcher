#ifndef HARDVIEW_H
#define HARDVIEW_H

#include<QGraphicsView>
#include<QIcon>
#include<QBrush>
#include<QGraphicsScene>
#include<QResizeEvent>
#include"qgun.h"
#include"qfish2.h"
#include<QTimer>
#include<QMouseEvent>
#include<QPoint>
#include<QLine>
#include<QLineF>
#include<QDebug>
#include"qbullet.h"
#include <QSound>
#include<QPushButton>
#include "mypushbuttom.h"
#include "qscore.h"
#include<QLabel>
#include"qfish.h"
#include"qfish3.h"

class Hardview:public QGraphicsView
{
    Q_OBJECT
public:
    Hardview();
    void resizeEvent(QResizeEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    static int Score;
private:
    QGraphicsScene*  hardscence;
    QGun* gun;
    Qscore* score;
    QFish* fish1;
    QFish* fish2;
    QFish* fish3;
    QFish* fish4;
    QFish* fish5;
    QFish2* fish6;
    QFish2* fish7;
    QFish2* fish8;
    QFish2* fish9;
    QFish3* fish10;
    QTimer* timer;
    QLabel *label;
    QSound* backgroundSound = new QSound("music/background3.wav",this);//设置背景音乐

public slots:
 void returnBtnclick();//自定义槽函数

};

#endif // HARDVIEW_H
