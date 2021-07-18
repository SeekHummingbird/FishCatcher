#ifndef QFISH2_H
#define QFISH2_H
#include<qpixmapitem.h>
#include<QtGui>
#include<QGraphicsScene>

class QFish2:public QpixmapItem
{
public:
    QFish2(const QString &fileName,QGraphicsScene* scence);
    void advance(int phase);
   void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget);
    void fish_death();
};


#endif // QFISH2_H
