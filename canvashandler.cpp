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
    QFileInfo *fileInfo = new QFileInfo(filePath.toString());    
    QString fileType = fileInfo->suffix();

    if(fileType == "pbm") {
        ImageOpener *imageOpener = new ImageOpener;
        imageOpener->openPBM(filePath.toLocalFile());
        
        QPixmap pixmap = QPixmap::fromImage(*imageOpener->getQImage());

        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);

        scene->addItem(pixmapItem);   
    }
}

CanvasHandler::~CanvasHandler() {

}
