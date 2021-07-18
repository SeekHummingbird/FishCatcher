#include "qbullet.h"
#include"easyview.h"

QBullet::QBullet(const QString &fileName,QGraphicsScene* scence,qreal angle):QpixmapItem(fileName,scence)
{
    this->scence=scence;

    qreal dx,dy;
    qreal rad;
    rad=angle*3.1415926/180;
    dx=88*cos(rad);
    dy=88*sin(rad);

    this->setPos((scence->width()/2+dx),(scence->height()-dy));
    this->setRotation(90-angle);

}

void QBullet::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget)
{
  painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
  if(this->collidingItems().count()>0)
   {
       docolliding();

   }
}



void QBullet::advance(int phase)
{
    if(mapToScene(0,0).x()<=0||mapToScene(0,0).x()>=800||mapToScene(0,0).y()<=0)
    {
        delete this;
    }
    else
    {
        this->setPos(mapToScene(0,-20));
    }

}

void QBullet::docolliding()
{
    QNet* net=new QNet("img/net.png",this->scence);
    net->setPos(mapToScene(0,0));
    delete this;
//    Easyview::Score+=10;
}









