#include "linearsketcher.h"

LinearSketcher::LinearSketcher(QWidget *parent)
    : BaseSketcher(parent)
    , currentPixel_(0){

}

LinearSketcher::~LinearSketcher(){

}

void LinearSketcher::sketch(const QImage &img, int interval){
    for (int i=0; i<img.height(); ++i){
        for (int j=0; j<img.width(); ++j){
            points_.push_back(qMakePair(QPoint(j,i), img.pixel(j,i) ));
        }
    }
    BaseSketcher::sketch(img, interval);
}

void LinearSketcher::sketchStep(){
    if (++currentPixel_ < points_.size()){
        int x=points_.at(currentPixel_).first.x();
        int y=points_.at(currentPixel_).first.y();
        QRgb color=points_.at(currentPixel_).second;
        innerImage_.setPixel(x, y, color);
    }
    else{
        sketchIsOver_=true;
        emit sketchIsOver();
    }
    repaint();
}
