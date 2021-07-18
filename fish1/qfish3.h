#ifndef QFISH3_H
#define QFISH3_H
#include<qpixmapitem.h>
#include<QtGui>
#include<QGraphicsScene>

class QFish3:public QpixmapItem
{
public:
    QFish3(const QString &fileName,QGraphicsScene* scence);
    void advance(int phase);
   void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget);
    void fish_death();

};

#endif // QFISH3_H
