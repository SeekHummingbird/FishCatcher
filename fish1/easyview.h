#ifndef EASYVIEW_H
#define EASYVIEW_H

#include<QGraphicsView>
#include<QIcon>
#include<QBrush>
#include<QGraphicsScene>
#include<QResizeEvent>
#include"qgun.h"
#include"qfish.h"
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
#include<QString>
#include<QLabel>
#include "qscore.h"
//#include "widget.h"
#include<qpixmapitem.h>
#include<QGraphicsScene>

class Easyview:public QGraphicsView
{
    Q_OBJECT
public:
    Easyview();
    void resizeEvent(QResizeEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget);
    static int Score;

private:
    QGraphicsScene* easyscence;
    QGun* gun;
    Qscore* score;
    QFish* fish1;
    QFish* fish2;
    QFish* fish3;
    QFish* fish4;
    QFish* fish5;
    QFish* fish6;
    QFish* fish7;
    QFish* fish8;
    QFish* fish9;
    QFish2* fish10;
    QTimer* timer;
    QLabel *label;
    QSound* backgroundSound = new QSound("music/background1.wav",this);//设置背景音乐


public slots:
 void returnBtnclick();//自定义槽函数
 void advance(int phase);

};

#endif // EASYVIEW_H
