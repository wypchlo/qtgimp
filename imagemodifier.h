#ifndef IMAGEMODIFIER_H
#define IMAGEMODIFIER_H

#include <QtWidgets>

class ImageModifier
{
public:
    ImageModifier();
    ~ImageModifier();

    static void invertColor(QImage *image);

private:
    QImage *image;
};

#endif // IMAGEMODIFIER_H
