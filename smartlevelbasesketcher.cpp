#include "smartlevelbasesketcher.h"

SmartLevelBasedSketcher::SmartLevelBasedSketcher(QWidget *parent)
    : BaseSketcher(parent)
    , levelPoints_(numOfLevels_){
}

void SmartLevelBasedSketcher::sketch(const QImage &img, int interval){
    BaseSketcher::sketch(img, interval);
}

SmartLevelBasedSketcher::~SmartLevelBasedSketcher(){}
