#include "BaseSketcher.h"
#include <iostream>
#include <QDebug>
BaseSketcher::BaseSketcher(QWidget *parent)
        : QWidget(parent){
    innerImage_=QImage();
    innerImage_.fill(Qt::white);
    imgPencil_=QImage(":/img/rec/pencil.png");
    timer_=new QTimer(this);
}

BaseSketcher::~BaseSketcher() {

}

void BaseSketcher::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    if (!innerImage_.isNull()){
        int startX=getStartPoint().x();
        int startY=getStartPoint().y();
        painter.drawImage(startX, startY, innerImage_);
        if (!sketchIsOver_ && currentPixel_ < points_.size()){
            painter.drawImage(points_.at(currentPixel_).first.x()+startX, points_.at(currentPixel_).first.y()+startY, imgPencil_);
        }
    }
}

QPoint& BaseSketcher::getStartPoint() {
    if (startPoint_.isNull()){
        startPoint_.setX((this->width()-innerImage_.width())/2);
        startPoint_.setY((this->height()-innerImage_.height())/2);
    }
    return startPoint_;
}

void BaseSketcher::sketchStep() {
    if (currentPixel_ < points_.size()){
        int x=points_.at(currentPixel_).first.x();
        int y=points_.at(currentPixel_).first.y();
        QRgb color=points_.at(currentPixel_).second;
        innerImage_.setPixel(x, y, color);
        currentPixel_++;
    }
    else{
        sketchIsOver_=true;
        emit sketchIsOver();
    }
    repaint();
}

void BaseSketcher::sketch(const QImage& img, int interval) {
    timeInterval_=interval;
    innerImage_=QImage(img.size(), img.format());
    innerImage_.fill(Qt::white);
    sketchIsOver_=false;
    connect(timer_, SIGNAL(timeout()), SLOT(sketchStep()));
    connect(this, SIGNAL(sketchIsOver()), timer_, SLOT(stop()));
    timer_->start(timeInterval_);
}

void BaseSketcher::changeState(bool state){
    sketchIsOver_=state;
}
