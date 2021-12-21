#include "dialog.h"
#include "ui_dialog.h"
#include <QMovie>
#include <QMediaPlayer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QMovie *mv1 = new QMovie(":/images/load.gif");
    ui->label->setGeometry(157,120,60,60);
    ui->label->setMovie(mv1);
    ui->label->setScaledContents(true);
    mv1->start();
    QObject::connect(ui->btn_p,SIGNAL(clicked()),this,SLOT(on_btn_p_clicked()));
}

Dialog::~Dialog()
{
    delete player;
       player = nullptr;
    delete ui;
}

void Dialog::on_btn_p_clicked()
{
    if(ui->label->height()>=300){
        QMovie *mv2 = new QMovie(":/images/cake.gif");
        ui->label->setMovie(mv2);
        ui->label->setScaledContents(true);
        mv2->start();
        player = new QMediaPlayer;
        player->setMedia(QUrl::fromEncoded("qrc:/sing/song.mp3"));
        player->setVolume(50);
        player->play();


    }
    else{
        int x = ui->label->x();
        int y = ui->label->y();
        int h = ui->label->height();
        int w = ui ->label->width();
        ui->label->setGeometry(x-5,y-5,h+10,w+10);
    }
}
