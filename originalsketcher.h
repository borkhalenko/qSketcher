#ifndef ORIGINALSKETCHER_H
#define ORIGINALSKETCHER_H
#include <BaseSketcher.h>

class OriginalSketcher : public BaseSketcher{
Q_OBJECT
public:
    OriginalSketcher(const QImage &img, QWidget *parent=0);
    virtual void sketch(const QImage &img, int interval);
    ~OriginalSketcher();
protected slots:
    void sketchStep();
};

#endif // ORIGINALSKETCHER_H
