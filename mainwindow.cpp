#include <QtWidgets/qmessagebox.h>
#include <QHBoxLayout>
#include <QtWidgets/qfiledialog.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OriginalPainter.h"
#include "BaseSketcher.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui_(new Ui::MainWindow){
    ui_->setupUi(this);
    image_= QImage(":/img/rec/some_img2.png");
    mainWidget_=new OriginalPainter(image_, this);
    this->setCentralWidget(mainWidget_);
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
        mainWidget_=new OriginalPainter(image_, this);
        this->setCentralWidget(mainWidget_);
        //this->resize(mainWidget_->size());
    }
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About Sketcher"),
            tr("<p>The <b>Sketcher</b> program can sketch the image "
                    "and show animate process.</p>"));
}

void MainWindow::play() {
    if (!image_.isNull()) {
        delete mainWidget_;
        mainWidget_=new BaseSketcher(image_, this);
        this->setCentralWidget(mainWidget_);
        //this->resize(mainWidget_->size());
    }
}

void MainWindow::pause() {

}
