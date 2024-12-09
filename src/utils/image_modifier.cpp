#include <QImage>

#include "image_modifier.h"

ImageModifier::ImageModifier() {

}

void ImageModifier::invertColor(QImage *image) {
    QImage::Format imageFormat = image->format();
    int width = image->width();
    int height = image->height();

    if(imageFormat == QImage::Format_RGB888) {
        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; x++ ) {
                QColor color = image->pixelColor(x, y);
                image->setPixelColor(x, y, qRgb(255 - color.red(), 255 - color.green(), 255 - color.blue()));
            }
        }
    }
    else if(imageFormat == QImage::Format_Mono) {
        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; x++ ) {
                bool color = image->pixelColor(x, y).red();
                image->setPixel(x, y, !color);
            }
        }
    }
}

ImageModifier::~ImageModifier() {

}
