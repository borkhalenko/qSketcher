#include "originalsketcher.h"
#include <QDebug>

OriginalSketcher::OriginalSketcher(const QImage &img, QWidget *parent)
    :BaseSketcher(img, parent){
}

void OriginalSketcher::sketch(const QImage &img, int){
    BaseSketcher::sketch(img, 0);
    sketchIsOver_=false;                //This can't be there!!!
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
    sketchIsOver_=true;
    emit sketchIsOver();
    repaint();
}
