#ifndef COMMONVIEW_H
#define COMMONVIEW_H

#include<QGraphicsView>
#include<QIcon>
#include<QBrush>
#include<QGraphicsScene>
#include<QResizeEvent>
#include"qgun.h"
#include"qfish.h"
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
#include<QString>
#include "qscore.h"
#include<QLabel>
#include"qfish2.h"

//#include "widget.h"


class Commonview:public QGraphicsView
{
    Q_OBJECT
public:
    Commonview();
    void resizeEvent(QResizeEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    static int Score;
private:
    QGraphicsScene*  commonscence;
    QGun* gun;
    Qscore* score;
    QFish* fish1;
    QFish* fish2;
    QFish* fish3;
    QFish* fish4;
    QFish* fish5;
    QFish* fish6;
    QFish* fish7;
    QFish2* fish8;
    QFish2* fish9;
    QFish2* fish10;
    QTimer* timer;
    QLabel *label;
    QSound* backgroundSound = new QSound("music/background2.wav",this);//设置背景音乐


public slots:
 void returnBtnclick();//自定义槽函数


};

#endif // EASYVIEW_H
