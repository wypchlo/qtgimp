#ifndef IMAGEOPENER_H
#define IMAGEOPENER_H

#include <QImage>

class ImageOpener
{
public:
    ImageOpener();
    ~ImageOpener();

    void openAsciiPortableAnyMap(QString filePath);
    QImage* getQImage();

private:
    QImage *image;
};

#endif // IMAGEOPENER_H
