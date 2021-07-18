#ifndef QBULLET_H
#define QBULLET_H

#include<qpixmapitem.h>
#include<math.h>
#include<QtGui>
#include<QDebug>
#include<qnet.h>
#include<QGraphicsScene>

class QBullet:public QpixmapItem
{
public:
    QBullet(const QString &fileName,QGraphicsScene* scence,qreal angle);
    void advance(int phase);
    void docolliding();
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget);
private:
    QGraphicsScene* scence;
};

#endif // QBULLET_H
