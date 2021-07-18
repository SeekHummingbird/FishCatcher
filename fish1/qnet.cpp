#include "qnet.h"
#include"easyview.h"
#include "commonview.h"
#include "hardview.h"

QNet::QNet(const QString &fileName,QGraphicsScene* scence):QpixmapItem(fileName,scence)
{

}

void QNet::advance(int phase)
{
    if(this->collidingItems().count()>0)
     {
          QList<QGraphicsItem*>list=this->collidingItems();
          QList<QGraphicsItem*>::Iterator i;
          QFish* fish;
          i=list.begin();
          while (i!=list.end())
          {
              fish=(QFish*)(*i);
              fish->fish_death();
              //fish->hide();//鱼会越变越少
              //delete fish;//会报错
              Easyview::Score+=10;
              Commonview::Score+=10;
              Hardview::Score+=10;
              i++;
          }

     }

    this->hide();
    delete this;
}
