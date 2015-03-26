#include "levelbasedsketcher.h"
#include <qmath.h>
#include <utility> // std::swap
#include <QDebug>

LevelBasedSketcher::LevelBasedSketcher(QWidget *parent)
    : BaseSketcher(parent)
    , levelPoints_(numOfLevels_){
}

LevelBasedSketcher::~LevelBasedSketcher(){

}

void LevelBasedSketcher::sketch(const QImage &img, int interval){
    int imgHeight=img.height();
    int imgWidth=img.width();
    int c=0;
    for (int h=0; h<imgHeight; ++h){
        for (int w=0; w<imgWidth; ++w){
            QColor color=img.pixel(w,h);
            c=0.3*color.red()+0.59*color.green()+0.11*color.blue();
            for (int i=0; i<numOfLevels_; ++i){
                if (c>=levels_[i] && c<levels_[i+1]){ //??? <=
                    //if I use levelPoints_.at(i), I get compile error:
                    //error: passing 'const QVector<>' as 'this' argument of 'void QVector<T>::push_back(const T&)  discards qualifiers [-fpermissive]
                    //because QVector::at (despite std::vector) return only const referencez
                    levelPoints_[i].push_back(qMakePair(QPoint(w,h), QColor(c,c,c).rgb() ));
                    break;
                }
            }
        }
    }
    qDebug()<<"levelPoints_ is filled";
    for (int i=0; i<numOfLevels_; ++i){
        sortPoints(levelPoints_[i]);
        points_<<levelPoints_[i];
    }
    qDebug()<<"levelPoints_ is sorted";
    BaseSketcher::sketch(img, interval);
}

// Sorting algorithm. It works like selection sort...
void sortPoints(QVector<BaseSketcher::tQPointPair> &points){
    qDebug()<<"Vector size:"<<points.size();
    auto endPoint=points.end();
    for(auto i=points.begin(); i!=endPoint-1; ++i){
        auto closer=i+1;
        int destinationToCloser=qSqrt(qPow(qAbs(closer->first.x()-i->first.x()), 2.0) + qPow(qAbs(closer->first.y()-i->first.y()), 2.0));
        for (auto j=closer+1; j!=endPoint; ++j){
            int tmpDestination=qSqrt(qPow(qAbs(i->first.x()-j->first.x()), 2.0) + qPow(qAbs(i->first.y()-j->first.y()), 2.0));
            if (tmpDestination<destinationToCloser){
                destinationToCloser=tmpDestination;
                closer=j;
            }
        }
        if (closer!=i+1){
            std::swap(*(i+1), *closer);
        }
    }
}
