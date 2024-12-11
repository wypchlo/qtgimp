#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtWidgets>
#include <cstdint>

class MainWindow;

class Canvas : public QObject
{
    Q_OBJECT

public:
    Canvas(QVBoxLayout *layout);
    ~Canvas();

    void openFile(QUrl filePath);

    void imageColorInvertion();
    void imageDesaturation();
    void imageBrightness(int8_t tilt);
    void imageBrightnessPreview(int8_t tilt);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *pixmapItem;
    QPixmap pixmap;
    QImage *image;
};

#endif // UI_CANVAS_H
