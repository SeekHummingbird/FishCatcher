#include "mypushbuttom.h"
#include<QDebug>

 MyPushButtom::MyPushButtom(QString normalImg,QString pressImg )//参数1 正常显示图片路径 参数2 按下后切换图片路径（参数2可不设置）
 {
     this->normalPath=normalImg;
     this->pressPath=pressImg;

     //创建QPixmap对象
     QPixmap pix;
     bool ret = pix.load(normalPath);
     if(!ret)
     {
         QString str = QString("图标加载失败，失败的路径是：1！").arg(this->normalPath);
         qDebug()<<str;
     }
     //设置按钮固定尺寸
      this->setFixedSize(pix.width(),pix.height());
      //设置不规则样式
      this->setStyleSheet("QPushButton(border:0px;)");
      //设置图标
      this->setIcon(pix);
      //设置图标大小
      this->setIconSize(QSize(pix.width(),pix.height()));
 }

void MyPushButtom::returnBtnclick()
{

}
