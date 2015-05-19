#ifndef _QSKETCHER_BASESKETCHER_H_
#define _QSKETCHER_BASESKETCHER_H_

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class BaseSketcher : public QWidget {
Q_OBJECT
public:
    //TODO: need to change tQPointPair in delivered classes, where is possible.
    typedef QPair<QPoint, QRgb> tQPointPair;
    explicit BaseSketcher(QWidget *parent=0);
    ~BaseSketcher();
    virtual void paintEvent(QPaintEvent* event);
    virtual void sketch(const QImage& img, int interval);
    virtual void changeState();
signals:
    void sketchIsOver();
protected:
    QImage innerImage_;
    QVector<tQPointPair> points_;
    bool sketchIsOver_;
    bool sketchIsPaused_;
    int currentPixel_;
    QTimer* timer_;
protected slots:
    virtual void sketchStep();

private:
    QPoint& getStartPoint();
    QPoint startPoint_;
    //int currentPixel_;
    int timeInterval_;
    QImage imgPencil_;
};

#endif //_QSKETCHER_BASESKETCHER_H_
