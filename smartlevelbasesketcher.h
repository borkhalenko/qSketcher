#ifndef SMARTLEVELBASEDSKETCHER_H
#define SMARTLEVELBASEDSKETCHER_H
#include "baseSketcher.h"

void sortPoints(QVector<BaseSketcher::tQPointPair>& points);

class SmartLevelBasedSketcher : public BaseSketcher{
    Q_OBJECT
public:
    SmartLevelBasedSketcher(QWidget* parent=0);
    virtual ~SmartLevelBasedSketcher();
    virtual void sketch(const QImage &img, int interval);
private:
    static const int numOfLevels_=5;
    int levelCurrentPoint_[numOfLevels_]={0};
    int levels_[numOfLevels_+1] = {0, 150, 180, 210, 220, 232};
    QVector<QVector<tQPointPair> > levelPoints_;
};

#endif // SMARTLEVELBASEDSKETCHER_H
