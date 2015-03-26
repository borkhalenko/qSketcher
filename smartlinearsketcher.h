#ifndef SMARTLINEARSKETCHER_H
#define SMARTLINEARSKETCHER_H
#include "BaseSketcher.h"

class SmartLinearSketcher : public BaseSketcher{
    Q_OBJECT
public:
    SmartLinearSketcher(QWidget* parent=0);
    ~SmartLinearSketcher();
    virtual void sketch(const QImage &img, int interval);
protected slots:
    void sketchStep();

};
#endif // SMARTLINEARSKETCHER_H
