#include <QtWidgets>

#include "imageopener.h"
#include "imagemodifier.h"
#include "canvashandler.h"

CanvasHandler::CanvasHandler(QVBoxLayout *layout) {
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    pixmapItem = new QGraphicsPixmapItem;
    image = new QImage;
    //view->scale(10, 10);

    layout->addWidget(view);
}

void CanvasHandler::openFile(QUrl filePath) {
    pixmapItem->clearFocus();
    scene->removeItem(pixmapItem);

    ImageOpener *imageOpener = new ImageOpener;
    imageOpener->openAsciiPortableAnyMap(filePath.toLocalFile());
    
    image = imageOpener->getQImage();
    pixmap = QPixmap::fromImage(*image);
    pixmapItem = new QGraphicsPixmapItem(pixmap);

    scene->addItem(pixmapItem);

    scene->update();
}

void CanvasHandler::imageColorInvertion() {
    ImageModifier::invertColor(image);
    pixmap = QPixmap::fromImage(*image);
    pixmapItem->setPixmap(pixmap);
}

CanvasHandler::~CanvasHandler() {

}
