#ifndef QPIXMAPITEM_H
#define QPIXMAPITEM_H

#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QRectF>
#include<QPainter>
#include<QString>
#include<QGraphicsScene>

class QpixmapItem:public QGraphicsItem
{
public:
    QpixmapItem(const QString &fileName,QGraphicsScene* scence);
    virtual QRectF boundingRect() const;
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget);
protected:
    QPixmap pixmap;
};

#endif // QPIXMAPITEM_H
