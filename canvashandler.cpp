#include <QtWidgets>

#include "canvashandler.h"

CanvasHandler::CanvasHandler(QVBoxLayout *layout) {
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    view->scale(10, 10);

    layout->addWidget(view);
}

void CanvasHandler::openPBM() {
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

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);

    scene->addItem(pixmapItem);
}

CanvasHandler::~CanvasHandler() {

}
