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
};

#endif // UTILS_IMAGE_HANLDER_H
