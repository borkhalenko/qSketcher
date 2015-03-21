//
// Created by borkhalenko on 17.03.15.
//
#ifndef _QSKETCHER_MAINWINDOW_H_
#define _QSKETCHER_MAINWINDOW_H_

#include <QMainWindow>
#include <QImage>
#include <memory>

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
private:
    Ui::MainWindow *ui_;
    QWidget *mainWidget_;
    QImage image_;
};

#endif //_QSKETCHER_MAINWINDOW_H_
