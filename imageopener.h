#include <QImage>

class ImageOpener
{
public:
    ImageOpener();
    ~ImageOpener();

    void openPBM(QString filePath);
    QImage* getQImage();

private:
    QImage *image;
};
