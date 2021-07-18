#include "qpixmapitem.h"

QpixmapItem::QpixmapItem(const QString &fileName,QGraphicsScene* scence)
{
    pixmap.load(fileName);
    scence->addItem(this);
}
QRectF  QpixmapItem::boundingRect() const
{
  return QRectF(-pixmap.width()/2,-pixmap.height(),pixmap.width(),pixmap.height());
}
void QpixmapItem::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget)
{
  painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}
