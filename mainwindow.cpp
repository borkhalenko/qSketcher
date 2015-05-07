#include <QtWidgets/qmessagebox.h>
#include <QHBoxLayout>
#include <QtWidgets/qfiledialog.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "originalsketcher.h"
#include "linearsketcher.h"
#include "smartlinearsketcher.h"
#include "levelbasedsketcher.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui_(new Ui::MainWindow){
    ui_->setupUi(this);
    image_= QImage(":/img/rec/some_img2.png");
    mainWidget_=new OriginalSketcher(this);
    this->setCentralWidget(mainWidget_);
    //TODO: ? What should I do, when some of delivered classes
    // must have overrided functions with different arguments?
    mainWidget_->sketch(image_, 0);
}

MainWindow::~MainWindow(){
    delete ui_;
}

void MainWindow::open() {
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        image_ = QImage(fileName);
        if (image_.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                    tr("Cannot load %1.").arg(fileName));
            return;
        }
        delete mainWidget_;
        this->resize(this->size()-mainWidget_->size()+image_.size());
        mainWidget_=new OriginalSketcher(this);
        mainWidget_->sketch(image_, 0);
        this->setCentralWidget(mainWidget_);
        //this->resize(mainWidget_->size());
    }
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About Sketcher"),
            tr("<p>The <b>Sketcher</b> program can sketch the image "
               "and show animate process.</p>"));
}

void MainWindow::resizeEvent(QResizeEvent *){

    //mainWidget_->repaint();
}

void MainWindow::play() {
    if (!image_.isNull()) {
        qDebug()<<"I'm in play()";
        delete mainWidget_;
        mainWidget_=new LevelBasedSketcher(this);
        mainWidget_->sketch(image_, 15);
        this->setCentralWidget(mainWidget_); //?
    }
}

void MainWindow::pause() {
   mainWidget_->changeState(true);
}
