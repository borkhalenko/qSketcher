#ifndef ORIGINALSKETCHER_H
#define ORIGINALSKETCHER_H
#include "baseSketcher.h"

class OriginalSketcher : public BaseSketcher{
Q_OBJECT
public:
    OriginalSketcher(QWidget *parent=0);
    virtual ~OriginalSketcher();
    virtual void sketch(const QImage &img, int interval);
protected slots:
    void sketchStep();
};

#endif // ORIGINALSKETCHER_H
