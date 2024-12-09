#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtWidgets>

class MainWindow;

class Canvas : public QObject
{
    Q_OBJECT

public:
    Canvas(QVBoxLayout *layout);
    ~Canvas();

    void openFile(QUrl filePath);

    void imageColorInvertion();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *pixmapItem;
    QPixmap pixmap;
    QImage *image;
};

#endif // UI_CANVAS_H
