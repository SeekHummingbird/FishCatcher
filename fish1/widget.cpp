#include "widget.h"

QSound* Widget::backgroundSound = new QSound("music/menu.wav"); //设置背景音乐

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    backgroundSound->setLoops(-1);//无限循环
    backgroundSound->play();//播放背景音乐


    this->setFixedSize(800,533);//设置窗口大小
    this->setWindowTitle("捕鱼达人");//设置窗口标题
    this->setWindowIcon(QIcon("img/Fish_Icon.png"));//设置窗口图标

    QPalette palette;//调色板
    //palette.setColor(QPalette::Background,Qt::blue);//背景设为蓝色

    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/1.png")));//笔刷
    this->setPalette(palette);

    this->label= new QLabel(this);//标签初始化
    label->setPixmap(QPixmap("img/2.png"));

    this->startbtn= new QPushButton(this);//添加按钮
    this->startbtn->setIcon(QIcon("img/start.png"));
    this->startbtn->setIconSize(QSize(220,56));
    this->startbtn->setFlat(true);
    startbtn->setFocusPolicy(Qt::NoFocus);

    this->setbtn= new QPushButton(this);//添加按钮
    this->setbtn->setIcon(QIcon("img/set.png"));
    this->setbtn->setIconSize(QSize(180,56));
    this->setbtn->setFlat(true);
    setbtn->setFocusPolicy(Qt::NoFocus);

    this->helpbtn= new QPushButton(this);//添加按钮
    this->helpbtn->setIcon(QIcon("img/help.png"));
    this->helpbtn->setIconSize(QSize(140,50));
    this->helpbtn->setFlat(true);
    helpbtn->setFocusPolicy(Qt::NoFocus);

    this->quitbtn= new QPushButton(this);//添加按钮
    this->quitbtn->setIcon(QIcon("img/exit.png"));
    this->quitbtn->setIconSize(QSize(60,32));
    this->quitbtn->setFlat(true);
    quitbtn->setFocusPolicy(Qt::NoFocus);

    //创建垂直布局对象
    this->vboxlayout=new QVBoxLayout(this);
    this->vboxlayout->addWidget(label);
    this->vboxlayout->addWidget(startbtn);
    this->vboxlayout->addWidget(setbtn);
    this->vboxlayout->addWidget(helpbtn);
    this->vboxlayout->addWidget(quitbtn);
    this->vboxlayout->setAlignment(Qt::AlignCenter);

    //信号和槽关联
    this->connect(startbtn,SIGNAL(clicked()),this,SLOT(startbtnclick()));
    this->connect(helpbtn,SIGNAL(clicked()),this,SLOT(helpbtnclick()));
    this->connect(quitbtn,SIGNAL(clicked()),this,SLOT(quitbtnclick()));
    this->connect(setbtn,SIGNAL(clicked()),this,SLOT(setbtnclick()));
}

Widget::~Widget()
{

}

void Widget::startbtnclick()
{
    backgroundSound->stop();

    /*
    w= new gamewidget(this);
    w->show();
    */

    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效

    hide();

    if(setwidget::difficultyChosen == 1)
    {
        easyview= new Easyview;
        easyview->show();
    }
    else if(setwidget::difficultyChosen == 2)
    {
        commonview= new Commonview;
        commonview->show();
    }
    else
    {
        hardview= new Hardview;
        hardview->show();
    }

}
void Widget::helpbtnclick()
{
    //backgroundSound->stop();

    w1= new rulewidget(this);
    w1->show();

    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效
}
void Widget::quitbtnclick()
{
    //backgroundSound->stop();
    if(QMessageBox::Yes==QMessageBox::question(this,"提示","已按退出按钮，你确定要退出吗？",QMessageBox::Yes|QMessageBox::No))
    {
        this->close();
    }
    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效
}
void Widget::setbtnclick()
{
   //backgroundSound->stop();

    w2= new setwidget(this);
    w2->show();

    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效
}








