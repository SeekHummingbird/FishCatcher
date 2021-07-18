#include "qgun.h"

QGun::QGun(const QString &fileName,QGraphicsScene* scence):QpixmapItem(fileName,scence)
{

}

void QGun::gunSkinChange()
{
    static int num = 1;

    QString fileName = QString("img/gun%1.png").arg(num);

    num++;
    if(num>3) num = 0;

    pixmap.load(fileName);
}

 /* QRectF QGun::boundingRect() const
{
    return QRectF(-pixmap.width()/2,-pixmap.height(),pixmap.width(),pixmap.height());
}
void QGun::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget)
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}*/
