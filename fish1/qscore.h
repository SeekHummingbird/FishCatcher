#ifndef QSCORE_H
#define QSCORE_H

#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QRectF>
#include<qpixmapitem.h>
#include"qpixmapitem.h"
#include<QString>
#include<QGraphicsScene>

class Qscore:public QpixmapItem
{
public:
    Qscore(const QString &fileName,QGraphicsScene* scence);
};

#endif // QSCORE_H
