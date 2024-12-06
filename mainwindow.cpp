#include <QtWidgets>

#include "mainwindow.h"
#include "menubarhandler.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *window = new QWidget;
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout;

    menuBarHandler = new MenuBarHandler(this);
    statusBar()->showMessage(tr("Welcome to QTGimp!"));

    QImage *image = new QImage(3, 3, QImage::Format_Mono);

    image->setPixel(0, 0, 0);
    image->setPixel(1, 0, 1);
    image->setPixel(2, 0, 1);
    image->setPixel(0, 1, 0);
    image->setPixel(1, 1, 1);
    image->setPixel(2, 1, 1);
    image->setPixel(0, 2, 0);
    image->setPixel(1, 2, 0);
    image->setPixel(2, 2, 0);

    QPixmap pixmap = QPixmap::fromImage(*image);

    QGraphicsScene *scene = new QGraphicsScene;

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);

    scene->addItem(pixmapItem);

    QGraphicsView *view = new QGraphicsView(scene);

    layout->addWidget(view);
    window->setLayout(layout);

    //General window settings

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
}

MainWindow::~MainWindow() {
    delete menuBarHandler;
}
