#include <QtWidgets>

#include "imageopener.h"
#include "canvashandler.h"

CanvasHandler::CanvasHandler(QVBoxLayout *layout) {
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    //view->scale(10, 10);

    layout->addWidget(view);
}

void CanvasHandler::openFile(QUrl filePath) {
    ImageOpener *imageOpener = new ImageOpener;
    imageOpener->openAsciiPortableAnyMap(filePath.toLocalFile());
    
    QPixmap pixmap = QPixmap::fromImage(*imageOpener->getQImage());
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);

    scene->addItem(pixmapItem);
}

CanvasHandler::~CanvasHandler() {

}
