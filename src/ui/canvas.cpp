#include "canvas.h"

#include <QtWidgets>
#include "utils/image_handler.h"

Canvas::Canvas(QVBoxLayout *layout) {
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    pixmapItem = new QGraphicsPixmapItem;
    image = new QImage;
    //view->scale(10, 10);

    layout->addWidget(view);
}

void Canvas::openFile(QUrl filePath) {
    pixmapItem->clearFocus();
    scene->removeItem(pixmapItem);

    image = ImageHandler::openPortableAnyMap(filePath.toLocalFile());

    pixmap = QPixmap::fromImage(*image);
    pixmapItem = new QGraphicsPixmapItem(pixmap);

    scene->addItem(pixmapItem);
    scene->update();
}

void Canvas::imageColorInvertion() {
    ImageHandler::invertColor(image);
    pixmap = QPixmap::fromImage(*image);
    pixmapItem->setPixmap(pixmap);
}

Canvas::~Canvas() {

}
