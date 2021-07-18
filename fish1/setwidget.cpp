#include "setwidget.h"
#include "widget.h"

int setwidget::difficultyChosen = 1;

setwidget::setwidget(QWidget *parent) : QWidget(parent)
{
    //backgroundSound->setLoops(-1);//无限循环
    //backgroundSound->play();//播放背景音乐

    this->parent=parent;
    this->setFixedSize(800,533);//设置窗口大小
    this->setWindowTitle("捕鱼达人");//设置窗口标题
    this->setWindowIcon(QIcon("img/Fish_Icon.png"));//设置窗口图标
    this->setAutoFillBackground(true);

    QPalette palette;//调色板
    //palette.setColor(QPalette::Background,Qt::blue);//背景设为蓝色

    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/1.png")));//笔刷
    this->setPalette(palette);

    label= new QLabel(this);//标签初始化
    label->setPixmap(QPixmap("img/music.png"));

    musicbtn = new QPushButton(this);//添加按钮
    musicbtn->setIcon(QIcon("img/switch_on.png"));
    musicbtn->setIconSize(QSize(190,74));
    musicbtn->setFlat(true);
    musicbtn->setFocusPolicy(Qt::NoFocus);

    dif_label = new QLabel(this);
    dif_label->setPixmap(QPixmap("img/difficulty.png"));

    difficultybtn= new QPushButton(this);//添加按钮
    //difficultybtn->setIcon(QIcon("img/easy.png"));
    if(difficultyChosen == 1)
    {
        difficultybtn->setIcon(QIcon("img/easy.png"));
    }
    else if(difficultyChosen == 2)
    {
        difficultybtn->setIcon(QIcon("img/normal.png"));
    }
    else
    {
        difficultybtn->setIcon(QIcon("img/hard.png"));
    }
    difficultybtn->setIconSize(QSize(120,52));
    difficultybtn->setFlat(true);
    difficultybtn->setFocusPolicy(Qt::NoFocus);

    this->returnbtn= new QPushButton(this);//添加按钮
    this->returnbtn->setIcon(QIcon("img/back.png"));
    this->returnbtn->setIconSize(QSize(120,52));
    this->returnbtn->setFlat(true);
    returnbtn->setFocusPolicy(Qt::NoFocus);

    //创建垂直布局对象
    this->vboxlayout=new QVBoxLayout(this);
    this->vboxlayout->addWidget(label);
    this->vboxlayout->addWidget(musicbtn);
    this->vboxlayout->addWidget(dif_label);
    this->vboxlayout->addWidget(difficultybtn);
    this->vboxlayout->addWidget(returnbtn);
    this->vboxlayout->setAlignment(Qt::AlignCenter);

    this->connect(returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnclick()));
    this->connect(musicbtn,SIGNAL(clicked()),this,SLOT(musicbtnclick()));
    this->connect(difficultybtn,SIGNAL(clicked()),this,SLOT(difficultybtnclick()));
}

void setwidget::musicbtnclick()
{
    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效

    static bool musicOn = true;
    musicOn = !musicOn;

    if(musicOn)
    {
        musicbtn->setIcon(QIcon("img/switch_on.png"));

        //backgroundSound->play();
        Widget::backgroundSound->play();
    }
    else
    {
        musicbtn->setIcon(QIcon("img/switch_off.png"));

        //backgroundSound->stop();
        Widget::backgroundSound->stop();
    }
}

void setwidget::difficultybtnclick()
{
    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效

    difficultyChosen++;
    if(difficultyChosen>3) difficultyChosen=1;

    if(difficultyChosen == 1)
    {
        difficultybtn->setIcon(QIcon("img/easy.png"));
    }
    else if(difficultyChosen == 2)
    {
        difficultybtn->setIcon(QIcon("img/normal.png"));
    }
    else
    {
        difficultybtn->setIcon(QIcon("img/hard.png"));
    }

}

void setwidget::returnbtnclick()
{
    //backgroundSound->stop();

    this->hide();
    QSound* clickSound = new QSound("music/click.wav",this);//设置音效
    clickSound->play();//播放音效
}
