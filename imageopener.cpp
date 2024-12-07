#include <QImage>
#include <QDebug>

#include <fstream>

#include "imageopener.h"

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
        
        int x = 0;
        int y = 0;
        std::string line; 

        while(std::getline(file, line)) {
            for(int i = 0; i < line.length(); i++) {
                if(x >= width) {
                    x = 0;
                    y++;
                }
                image->setPixel(x, y, (line[i] - 49) * -1 );
                x++;
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
}

QImage* ImageOpener::getQImage() {
    return image;
}

ImageOpener::~ImageOpener() {}
