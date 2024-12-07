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
