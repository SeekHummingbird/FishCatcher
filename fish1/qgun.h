#ifndef QGUN_H
#define QGUN_H

#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QRectF>
#include<qpixmapitem.h>
#include"qpixmapitem.h"
#include<QString>
#include<QGraphicsScene>

class QGun: public QpixmapItem
{
public:
    QGun(const QString &fileName,QGraphicsScene* scence);

    void gunSkinChange();
};

#endif // QGUN_H
