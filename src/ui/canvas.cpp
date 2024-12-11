#include "canvas.h"

#include<cstdint>
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

void Canvas::imageDesaturation(uint8_t percent) {
    ImageHandler::desaturate(image, percent);
    pixmap = QPixmap::fromImage(*image);
    pixmapItem->setPixmap(pixmap);
}

void Canvas::imageDesaturationPreview(uint8_t percent) {
    QImage previewImage = image->copy();
    ImageHandler::desaturate(&previewImage, percent);
    pixmap = QPixmap::fromImage(previewImage);
    pixmapItem->setPixmap(pixmap);
}

void Canvas::imageBrightness(int8_t tilt) {
    ImageHandler::brighten(image, tilt);
    pixmap = QPixmap::fromImage(*image);
    pixmapItem->setPixmap(pixmap);
}

void Canvas::imageBrightnessPreview(int8_t tilt) {
    QImage previewImage = image->copy();
    ImageHandler::brighten(&previewImage, tilt);
    pixmap = QPixmap::fromImage(previewImage);
    pixmapItem->setPixmap(pixmap);
}

Canvas::~Canvas() {

}
