#ifndef _QSKETCHER_BASESKETCHER_H_
#define _QSKETCHER_BASESKETCHER_H_

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class BaseSketcher : public QWidget {
Q_OBJECT
public:
    explicit BaseSketcher(const QImage &img, QWidget *parent=0);
    ~BaseSketcher();
    void paintEvent(QPaintEvent* event);
signals:
    void sketchIsOver();
protected:
    virtual void fillSetOfPoints(const QImage& img);
    QImage innerImage_;
    QVector<QPair<QPoint, QRgb > > points_;
    int currentPixel_;
    bool sketchIsOver_;
protected slots:
    virtual void sketchStep();
private:
    QPoint& getStartPoint();
    QPoint startPoint_;
    int timeInterval_;
    QTimer* timer_;
};

#endif //_QSKETCHER_BASESKETCHER_H_
