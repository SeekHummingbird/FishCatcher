#include "rulewidget.h"

rulewidget::rulewidget(QWidget *parent) : QWidget(parent)
{
    //backgroundSound->setLoops(-1);//无限循环
    //backgroundSound->play();//播放背景音乐

    //this->parent=parent;
    this->setFixedSize(803,600);//设置窗口大小
    this->setWindowTitle("捕鱼达人");//设置窗口标题
    this->setWindowIcon(QIcon("img/Fish_Icon.png"));//设置窗口图标
    this->setAutoFillBackground(true);

    QPalette palette;//调色板
    //palette.setColor(QPalette::Background,Qt::blue);//背景设为蓝色

    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/rule.png")));//笔刷
    this->setPalette(palette);

    this->returnbtn= new QPushButton(this);//添加按钮
    this->returnbtn->setIcon(QIcon("img/back.png"));
    this->returnbtn->setIconSize(QSize(120,52));
    returnbtn->move(this->width()*0.83,this->height()*0.78 );
    this->returnbtn->setFlat(true);

    returnbtn->setFocusPolicy(Qt::NoFocus);

    this->connect(returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnclick()));

}

void rulewidget::returnbtnclick()
{
    //backgroundSound->stop();

    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效
    this->hide();
}
