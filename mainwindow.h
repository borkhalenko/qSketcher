//
// Created by borkhalenko on 17.03.15.
//
#ifndef _QSKETCHER_MAINWINDOW_H_
#define _QSKETCHER_MAINWINDOW_H_

#include <QMainWindow>
#include <QImage>
#include <memory>
#include "baseSketcher.h"

namespace Ui{
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void open();
    void play();
    void pause();
    void about();
protected:
    virtual void resizeEvent(QResizeEvent *);
private:
    Ui::MainWindow *ui_;
    BaseSketcher *mainWidget_;
    QImage image_;
    const int maxImageHeight_;
    const int maxImageWidth_;
};

#endif //_QSKETCHER_MAINWINDOW_H_
