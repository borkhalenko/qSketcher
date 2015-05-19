#ifndef LINEARSKETCHER_H
#define LINEARSKETCHER_H
#include "baseSketcher.h"

class LinearSketcher : public BaseSketcher{
    Q_OBJECT
public:
    LinearSketcher(QWidget* parent=0);
    ~LinearSketcher();
    virtual void sketch(const QImage &img, int interval);
};
#endif // LINEARSKETCHER_H
