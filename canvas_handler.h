#pragma once

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
