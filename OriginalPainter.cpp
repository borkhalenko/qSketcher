#include <QtGui/qevent.h>
#include <QtWidgets/qwidget.h>
#include <QtGui/qpainter.h>
#include "OriginalPainter.h"
#include <QDebug>

OriginalPainter::OriginalPainter(QImage& img, QWidget *parrent)
        : QWidget(parrent)
        , image_(img) {
    qDebug()<<"OriginalPainter constructor...";
}

OriginalPainter::~OriginalPainter() {

}

void OriginalPainter::paintEvent(QPaintEvent *event) {
    imageX_=(this->width()-image_.width())/2;;
    imageY_=(this->height()-image_.height())/2;
    QPainter painter(this);
    if (!image_.isNull()) {
        painter.drawImage(imageX_, imageY_, image_);
    }
}
