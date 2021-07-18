#include "hardview.h"
#include "widget.h"


Hardview::Hardview()
{
    backgroundSound->setLoops(-1);//无限循环
    backgroundSound->play();//播放背景音乐


    MyPushButtom* returnBtn=new MyPushButtom("img/back.png");
    returnBtn->setParent(this);
    returnBtn->move(this->width()*1.06,this->height() );
    returnBtn->setFlat(true);
    returnBtn->setFocusPolicy(Qt::NoFocus);

    this->connect(returnBtn,SIGNAL(clicked()),this,SLOT(returnBtnclick() ));


    this->resize(800,533);//设置窗口大小
    this->setWindowTitle("捕鱼达人");//设置窗口标题
    this->setWindowIcon(QIcon("img/Fish_Icon.png"));//设置窗口图标
    this->setAutoFillBackground(true);

    this-> setMouseTracking(true);//让鼠标移动生效

    this->setBackgroundBrush(QBrush(QPixmap("img/hardsea.png")));

     hardscence=new QGraphicsScene;
     hardscence->setSceneRect(0,0,this->width()-2,this->height()-2);
    this->setScene( hardscence);

     score=new Qscore("img/score.png",hardscence);
     score->setPos(this->width()-91 , 85);

     //绘制大炮并增加到场景中
    gun=new QGun("img/gun0.png", hardscence);
    gun->setPos(this->width()/2,this->height());
    //easyscence->addItem(gun);

    fish1=new QFish("img/shark_r1.png", hardscence);
    //fish1->setPos(-130,50);
    //easyscence->addItem(fish1);

    fish2=new QFish("img/shark_r1.png", hardscence);
    //fish2->setPos(-50,150);
    //easyscence->addItem(fish2);

    fish3=new QFish("img/shark_r1.png", hardscence);
    //fish3->setPos(-100,250);
    //easyscence->addItem(fish3);

    fish4=new QFish("img/shark_r1.png", hardscence);
    //fish4->setPos(-80,350);
    //easyscence->addItem(fish4);

    fish5=new QFish("img/shark_r1.jpg", hardscence);
    //fish5->setPos(150,350);
    //easyscence->addItem(fish5);

    fish6=new QFish2("img/f_r1.jpg", hardscence);
    //fish5->setPos(150,350);
    //easyscence->addItem(fish5);

    fish7=new QFish2("img/f_r1.jpg", hardscence);
    //fish5->setPos(150,350);
    //easyscence->addItem(fish5);

    fish8=new QFish2("img/f_r1.jpg", hardscence);
    //fish5->setPos(150,350);
    //easyscence->addItem(fish5);

    fish9=new QFish2("img/f_r1.jpg", hardscence);
    //fish5->setPos(150,350);
    //easyscence->addItem(fish5);

    fish10=new QFish3("img/f5.png", hardscence);
    //fish5->setPos(150,350);
    //easyscence->addItem(fish5);


    //定时器
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()), hardscence,SLOT(advance()));
    timer->start(20);

    this->label=new QLabel(this);
    label->setParent(this);
    QFont font;
    font.setFamily("宋体");
    font.setPointSize(10);
    setStyleSheet( " color:white; " );
    label->setFont(font);
    label->setText(QString("分数：%1").arg(Score));
    label->setGeometry(668,-8,200,100);
}

int  Hardview::Score=0;

void Hardview::resizeEvent(QResizeEvent* event)
{
    this->setBackgroundBrush(QBrush(QPixmap("img/hardsea.png").scaled(event->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

}

 void Hardview::mouseMoveEvent(QMouseEvent* event)
 {
     QPoint p;
     p=event->pos();
     //画线
     QLine line(this->width()/2,this->height(),p.x(),p.y());
     QLineF linef(line);
     gun->setRotation(90-linef.angle() );

     //qDebug("angle:%f\n",90-linef.angle());
 }

 void Hardview::mousePressEvent(QMouseEvent* event)
 {     
     if(event->button() == Qt::LeftButton)
     {
         QSound* clickSound = new QSound("music/biu.wav",this);//设置音效
         clickSound->play();//播放音效
         QPoint p=event->pos();
         QLineF linef(this->width()/2,this->height(),p.x(),p.y());
         QBullet* bullet= new QBullet("img/B5.png", hardscence,linef.angle());

         label->setText(QString("得分：%1").arg(Score));
         //bullet->setPos(this->width()/2,this->height());
         //bullet->setRotation(90-linef.angle() );
     }
     else
     {
        gun->gunSkinChange();

        QSound* clickSound = new QSound("music/gunSkinChange.wav",this);//设置音效
        clickSound->play();//播放音效
     }
 }

 void Hardview::returnBtnclick()
 {
     backgroundSound->stop();
     this->close();
     QSound* clickSound = new QSound("music/click.wav",this);//设置音效
     clickSound->play();//播放音效
     Widget* w2;
     w2= new Widget();
     w2->show();

 }






