#include <QImage>
#include <QDebug>

#include <fstream>

#include "image_opener.h"

ImageOpener::ImageOpener() {
    image = new QImage(0, 0, QImage::Format_Mono);
}

void ImageOpener::openAsciiPortableAnyMap(QString filePath) 
{
    std::ifstream file(filePath.toStdString());
    std::string header, comment, dimensions; 

    std::getline(file, header);
    std::getline(file, comment);
    std::getline(file, dimensions);
   
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
}

QImage* ImageOpener::getQImage() {
    return image;
}

ImageOpener::~ImageOpener() {}
