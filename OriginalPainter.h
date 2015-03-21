#ifndef _QSKETCHER_ORIGINALPAINTER_H_
#define _QSKETCHER_ORIGINALPAINTER_H_

#include <QWidget>
#include <QImage>
#include <memory>

class OriginalPainter : public QWidget {
public:
    explicit OriginalPainter(QImage& img, QWidget *parrent=0);
    virtual ~OriginalPainter();
    void paintEvent(QPaintEvent *event);
private:
    QImage& image_;
    int imageX_;
    int imageY_;
};

#endif //_QSKETCHER_ORIGINALPAINTER_H_
