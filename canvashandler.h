#ifndef CANVASHANDLER_H
#define CANVASHANDLER_H

#include <QtWidgets>

class MainWindow;

class CanvasHandler : public QObject
{
    Q_OBJECT

public:
    CanvasHandler(QVBoxLayout *layout);
    ~CanvasHandler();

    void openFile(QUrl filePath);

    void imageColorInvertion();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *pixmapItem;
    QPixmap pixmap;
    QImage *image;
};

#endif // CANVASHANDLER_H
