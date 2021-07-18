#ifndef QNET_H
#define QNET_H

#include"qpixmapitem.h"
#include<QGraphicsItem>
#include"qfish.h"

class QNet: public QpixmapItem
{

public:
    QNet(const QString &fileName,QGraphicsScene* scence);
    void advance(int phase);
};

#endif // QNET_H
