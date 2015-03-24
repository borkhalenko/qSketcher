#ifndef LINEARSKETCHER_H
#define LINEARSKETCHER_H
#include "BaseSketcher.h"

class LinearSketcher: public BaseSketcher{
    Q_OBJECT
public:
    LinearSketcher(QWidget *parent=0);
    virtual ~LinearSketcher();
    virtual void sketch(const QImage &img, int interval);
protected slots:
    void sketchStep();    
};

#endif // LINEARSKETCHER_H
