#include "originalsketcher.h"
#include <QDebug>

OriginalSketcher::OriginalSketcher(QWidget *parent)
    :BaseSketcher(parent){
}

void OriginalSketcher::sketch(const QImage &img, int){
    BaseSketcher::sketch(img, 0);
    for (int i=0; i<img.height(); ++i){
        for (int j=0; j<img.width(); ++j){
            points_.push_back(qMakePair(QPoint(j,i), img.pixel(j,i) ));
        }
    }
}

OriginalSketcher::~OriginalSketcher(){

}

void OriginalSketcher::sketchStep(){
    if (sketchIsOver_){
        qDebug()<<"Bad!";
        return;
    }
    qDebug()<<"All is ok!";
    foreach (auto point, points_) {
        innerImage_.setPixel(point.first.x(), point.first.y(), point.second);
    }
    repaint();
    sketchIsOver_=true;
    emit sketchIsOver();

}
