#ifndef _QSKETCHER_BASESKETCHER_H_
#define _QSKETCHER_BASESKETCHER_H_

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class BaseSketcher : public QWidget {
Q_OBJECT
public:
    explicit BaseSketcher(QWidget *parent=0);
    ~BaseSketcher();
    virtual void paintEvent(QPaintEvent* event);
    virtual void sketch(const QImage& img, int interval);
signals:
    void sketchIsOver();
protected:
    QImage innerImage_;
    QVector<QPair<QPoint, QRgb > > points_;
    bool sketchIsOver_;
    QTimer* timer_;
protected slots:
    virtual void sketchStep() = 0;
private:
    QPoint& getStartPoint();
    QPoint startPoint_;
    //int currentPixel_;
    int timeInterval_;
};

#endif //_QSKETCHER_BASESKETCHER_H_
