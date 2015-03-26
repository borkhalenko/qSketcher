#include "linearsketcher.h"
#include <QDebug>

LinearSketcher::LinearSketcher(QWidget *parent)
    : BaseSketcher(parent){
    currentPixel_=0;
}

LinearSketcher::~LinearSketcher(){

}

void LinearSketcher::sketch(const QImage &img, int interval){
    for (int i=0; i<img.height(); ++i){
        for (int j=0; j<img.width(); ++j){
            QColor currentColor=img.pixel(j,i);
            int currentGray=qGray(currentColor.rgb());
            if (currentGray<70)
                points_.push_back(qMakePair(QPoint(j,i), img.pixel(j,i) ));
        }
    }
    BaseSketcher::sketch(img, interval);
}
