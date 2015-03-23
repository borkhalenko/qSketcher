#include "BaseSketcher.h"
#include <iostream>

BaseSketcher::BaseSketcher(QWidget *parent)
        : QWidget(parent)
        , timeInterval_(5){
    innerImage_=QImage();
    innerImage_.fill(Qt::white);
    timer_=new QTimer(this);
}

BaseSketcher::~BaseSketcher() {

}

void BaseSketcher::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    if (!innerImage_.isNull())
        painter.drawImage(getStartPoint().x(), getStartPoint().y(), innerImage_);
}

QPoint& BaseSketcher::getStartPoint() {
    if (startPoint_.isNull()){
        startPoint_.setX((this->width()-innerImage_.width())/2);
        startPoint_.setY((this->height()-innerImage_.height())/2);
    }
    return startPoint_;
}

//void BaseSketcher::sketchStep() {
////    if (sketchIsOver_)
////        return;
////    int x=points_.at(currentPixel_).first.x();
////    int y=points_.at(currentPixel_).first.y();
////    QRgb color=points_.at(currentPixel_).second;
////    innerImage_.setPixel(x, y, color);
////    if (++currentPixel_>=points_.size()){
////        sketchIsOver_=true;
////        emit sketchIsOver();
////    }
//    repaint();
//}

void BaseSketcher::sketch(const QImage& img, int interval) {
    timeInterval_=interval;
    innerImage_=QImage(img.size(), img.format());
    innerImage_.fill(Qt::white);
    sketchIsOver_=false;
    connect(timer_, SIGNAL(timeout()), SLOT(sketchStep()));
    connect(this, SIGNAL(sketchIsOver()), timer_, SLOT(stop()));
    timer_->start(timeInterval_);
}
