#include "image_handler.h"
#include "utils/bezier.h"

#include <QImage>
#include <QDebug>
#include <fstream>

ImageHandler::ImageHandler() {}

using std::ifstream, std::string;
QImage* ImageHandler::openPortableAnyMap(QString filePath) 
{
    QImage *image;

    ifstream file(filePath.toStdString());
    string header, comment, dimensions; 

    getline(file, header);
    getline(file, comment);
    getline(file, dimensions);
   
    short splitPosition = dimensions.find(' ');
    short width = std::stoi(dimensions.substr(0, splitPosition));
    short height = std::stoi(dimensions.substr(splitPosition, dimensions.length() - splitPosition));
    
    if(header == "P1") {
        image = new QImage(width, height, QImage::Format_Mono);
        
        char currentChar; 

        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; ) {
                file.get(currentChar);
                
                if(currentChar - '0' >= 0) { 
                    image->setPixel(x, y, (currentChar - '1') * -1); // If I did currentChar - '0' then the colors would be inverted
                    x++;
                }
            }
        }
    }
    else if(header == "P2") {
        image = new QImage(width, height, QImage::Format_RGB888); // I tried Format_Grayscale8 but it appeared weirdly dark so I'll just stick to RGB888 for now

        std::string line;
        
        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; x++ ) {
                std::getline(file, line);
                int byte = std::stoi(line);
                image->setPixel(x, y, qRgb(byte, byte, byte));
            }
        }
    }
    else if(header == "P3") {
        image = new QImage(width, height, QImage::Format_RGB888);

        std::string line;

        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; x++ ) {
                short bytes[3] = { 0, 0, 0 };
                for( int i = 0; i < 3; i++ ) {
                    std::getline(file, line);
                    bytes[i] = std::stoi(line);
                }
                image->setPixel(x, y, qRgb(bytes[1], bytes[2], bytes[0]));
            }
        }
    }
    //BINARY
    else if(header == "P4") {
        image = new QImage(width, height, QImage::Format_Mono);
        
        char byte;

        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; ) {
                file.get(byte);
                for (int i = 7; i >= 0; --i) {
                    bool bit = (byte >> i) & 1;
                    image->setPixel(x, y, !bit);
                    x++;
                }
            }
        }
    }
    else if(header == "P5") {
        image = new QImage(width, height, QImage::Format_RGB888);
         
        char byte;
        
        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; x++ ) {
                file.get(byte);
                image->setPixel(x, y, qRgb(byte, byte, byte));
            }
        }
    }
    else if(header == "P6") {
        image = new QImage(width, height, QImage::Format_RGB888);  
        
        char rgb[3] = {0, 0, 0};

        for( int y = 0; y < height; y++ ) {
            for( int x = 0; x < width; x++ ) {
                for( int i = 0; i < 3; i++ ) file.get(rgb[i]);
                image->setPixel(x, y, qRgb(rgb[1], rgb[2], rgb[0]));
            }
        }
    }

    return image;
}

void ImageHandler::invertColor(QImage *image) {
    QImage::Format imageFormat = image->format();

    if(imageFormat == QImage::Format_RGB888) {
        for( int y = 0; y < image->height(); y++ ) {
            for( int x = 0; x < image->width(); x++ ) {
                QColor color = image->pixelColor(x, y);
                image->setPixelColor(x, y, qRgb(255 - color.red(), 255 - color.green(), 255 - color.blue()));
            }
        }
    }
    else if(imageFormat == QImage::Format_Mono) {
        for( int y = 0; y < image->height(); y++ ) {
            for( int x = 0; x < image->width(); x++ ) {
                bool color = image->pixelColor(x, y).red();
                image->setPixel(x, y, !color);
            }
        }
    }
}

void ImageHandler::brighten(QImage *image, uint8_t tilt) {
    QImage::Format imageFormat = image->format();

    if(imageFormat != QImage::Format_RGB888) return;
    
    uint8_t* bezier_values = Bezier::get_bezier_values(uint8_t(255), tilt);
    
    for( int y = 0; y < image->height(); y++ ) {
        for( int x = 0; x < image->width(); x++ ) {
            QColor rgb = image->pixelColor(x, y);
            image->setPixelColor(x, y, qRgb(bezier_values[rgb.red()], bezier_values[rgb.green()], bezier_values[rgb.blue()]));
        }
    }
}

void ImageHandler::desaturate(QImage *image, uint8_t percent) {
    QImage::Format imageFormat = image->format();

    if(imageFormat != QImage::Format_RGB888) return;

    for( int y = 0; y < image->height(); y++ ) {
        for( int x = 0; x < image->width(); x++ ) {
            QColor rgb = image->pixelColor(x, y);
            uint8_t r, g, b;
            r = rgb.red();
            g = rgb.green();
            b = rgb.blue();
            uint8_t average = (r + g + b) / 3;
            image->setPixelColor(x, y, qRgb(rgb.red(), rgb.green(), rgb.blue()));
        }
    }
}

ImageHandler::~ImageHandler() {}
