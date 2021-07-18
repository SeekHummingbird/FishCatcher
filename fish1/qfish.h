#ifndef QFISH_H
#define QFISH_H
#include<qpixmapitem.h>
#include<QtGui>
#include<QGraphicsScene>

class QFish:public QpixmapItem
{
public:
    QFish(const QString &fileName,QGraphicsScene* scence);
    void advance(int phase);
   void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget);
    void fish_death();
};

#endif // QFISH_H
