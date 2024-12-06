#include <QImage>
#include <QDebug>

#include <fstream>

#include "imageopener.h"

ImageOpener::ImageOpener() {}

void ImageOpener::openPBM(QString filePath) {
    
    qDebug() << filePath.toStdString();

    std::ifstream file(filePath.toStdString());
    std::string header, comment, dimensions; 

    std::getline(file, header);
    std::getline(file, comment);
    std::getline(file, dimensions);
   
    short splitPosition = dimensions.find(' ');
    short width = std::stoi(dimensions.substr(0, splitPosition));
    short height = std::stoi(dimensions.substr(splitPosition, dimensions.length() - splitPosition));

    image = new QImage(width, height, QImage::Format_Mono);
    
    int x = 0;
    int y = 0;
    std::string line; 

    while ( std::getline(file, line) ) {
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

QImage* ImageOpener::getQImage() {
    return image;
}

ImageOpener::~ImageOpener() {}
