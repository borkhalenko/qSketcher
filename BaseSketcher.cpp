#include "BaseSketcher.h"
#include <iostream>

BaseSketcher::BaseSketcher(const QImage &img, QWidget *parent)
        : QWidget(parent)
        , innerImage_(img.size(), img.format())
        , timeInterval_(1){
    currentPixel_=0;
    innerImage_.fill(Qt::white);
    fillSetOfPoints(img);
    timer_=new QTimer(this);
    connect(timer_, SIGNAL(timeout()), SLOT(sketchStep()));
    connect(this, SIGNAL(sketchIsOver()), timer_, SLOT(stop()));
    timer_->start(timeInterval_);
}

BaseSketcher::~BaseSketcher() {

}

void BaseSketcher::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(getStartPoint().x(), getStartPoint().y(), innerImage_);
 //  std::cerr<<"LinearPainter redrawing..."<<" x:"<<points_.at(currentPixel_).first.x()
 //           <<" y:"<<points_.at(currentPixel_).first.y()<<std::endl;
}

QPoint& BaseSketcher::getStartPoint() {
    if (startPoint_.isNull()){
        startPoint_.setX((this->width()-innerImage_.width())/2);
        startPoint_.setY((this->height()-innerImage_.height())/2);
    }
    return startPoint_;
}

void BaseSketcher::sketchStep() {
    if (sketchIsOver_)
        return;
    int x=points_.at(currentPixel_).first.x();
    int y=points_.at(currentPixel_).first.y();
    QRgb color=points_.at(currentPixel_).second;
    innerImage_.setPixel(x, y, color);
    if (++currentPixel_>=points_.size()){
        sketchIsOver_=true;
        emit sketchIsOver();
    }
    repaint();
}

void BaseSketcher::fillSetOfPoints(const QImage& img) {
    for (int i=0; i<innerImage_.height(); ++i){
        for (int j=0; j<innerImage_.width(); ++j){
            points_.push_back(qMakePair(QPoint(j,i), img.pixel(j,i) ));
        }
    }
}
