#ifndef UTILS_IMAGE_HANLDER_H
#define UTILS_IMAGE_HANLDER_H

#include <QImage>

class ImageHandler
{
    public:
    ImageHandler();
    ~ImageHandler();

    static QImage* openPortableAnyMap(QString filePath);

    static void invertColor(QImage *image);
    static void desaturate(QImage *image, uint8_t percent);
    static void brighten(QImage *image, uint8_t tilt);
};

#endif // UTILS_IMAGE_HANLDER_H
