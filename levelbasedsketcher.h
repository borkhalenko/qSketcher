#ifndef LEVELBASEDSKETCHER_H
#define LEVELBASEDSKETCHER_H
#include "BaseSketcher.h"

void sortPoints(QVector<BaseSketcher::tQPointPair>& points);

class LevelBasedSketcher : public BaseSketcher{
    Q_OBJECT
public:
    LevelBasedSketcher(QWidget* parent=0);
    virtual ~LevelBasedSketcher();
    virtual void sketch(const QImage &img, int interval);
private:
    static const int numOfLevels_=5;
    int levelCurrentPoint_[numOfLevels_]={0};
    int levels_[numOfLevels_+1] = {0, 150, 180, 210, 220, 232};
    QVector<QVector<tQPointPair> > levelPoints_;
};

#endif // LEVELBASEDSKETCHER_H
