#ifndef CANVASHANDLER_H
#define CANVASHANDLER_H

#include <QtWidgets>
#include "mainwindow.h"

class CanvasHandler : public QObject
{
    Q_OBJECT

public:
    CanvasHandler(QVBoxLayout *layout);
    ~CanvasHandler();

    void openPBM();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // CANVASHANDLER_H
