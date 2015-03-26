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
        return;
    }
    sketchIsOver_=true;
    emit sketchIsOver();
    repaint();

}
