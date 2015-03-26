#include "originalsketcher.h"
#include <QDebug>

OriginalSketcher::OriginalSketcher(QWidget *parent)
    :BaseSketcher(parent){
}

void OriginalSketcher::sketch(const QImage &img, int){
    BaseSketcher::sketch(img, 0);
    innerImage_=QImage(img);
}

OriginalSketcher::~OriginalSketcher(){

}

void OriginalSketcher::sketchStep(){
    if (sketchIsOver_){
        qDebug()<<"Bad!";
        return;
    }
    qDebug()<<"All is ok!";
//    foreach (auto point, points_) {
//        innerImage_.setPixel(point.first.x(), point.first.y(), point.second);
//    }
    sketchIsOver_=true;
    emit sketchIsOver();
    repaint();

}
