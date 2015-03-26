#include "smartlinearsketcher.h"
#include <QDebug>

SmartLinearSketcher::SmartLinearSketcher(QWidget *parent): BaseSketcher(parent){
    currentPixel_=0;
}

SmartLinearSketcher::~SmartLinearSketcher(){

}

void SmartLinearSketcher::sketch(const QImage &img, int interval){
    for (int i=0; i<img.height(); ++i){
        for (int j=0; j<img.width(); ++j){
            QColor color=img.pixel(j,i);
            int c=0.3*color.red()+0.59*color.green()+0.11*color.blue();
//            if (color.alpha()==255 && c==0){
//                c=255;
//            }
            if (c<254){
                points_.push_back(qMakePair(QPoint(j,i), QColor(c,c,c).rgb() ));
            }
        }
    }
    BaseSketcher::sketch(img, interval);
}
