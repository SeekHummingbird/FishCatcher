#include "qfish3.h"

QFish3::QFish3(const QString &fileName, QGraphicsScene *scence):QpixmapItem(fileName,scence)
{
         setPos(-qrand()%800,qrand()%500);
}
void QFish3::paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget)
{
    char filename[50]="0";
    static int i=2;
    if(i==5)
    {
        i=1;
    }
    sprintf(filename,"img/f5.png",i++);
    pixmap.load(filename);
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}

void QFish3::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=800)
    {
        setPos(-qrand()%800,qrand()%500);
    }

    int speed1=qrand()%10;
     int speed2=qrand()%10-5;
    this->setPos(mapToScene(speed1,speed2));
}

void QFish3::fish_death()
{
    setPos(-qrand()%800,qrand()%500);//在原位置消失，再从随机位置开始游起
}





