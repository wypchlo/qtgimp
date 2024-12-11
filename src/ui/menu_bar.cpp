#include "menu_bar.h"

#include <QtWidgets>
#include <QPushButton>
#include "ui/main_window.h"

MenuBar::MenuBar(MainWindow *_mainWindow) {
    mainWindow = _mainWindow;
    menuBar = mainWindow->menuBar();

    createActions();
    createMenus();
}


void MenuBar::createActions() {
    openFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), tr("Open"), this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Open an existing file"));
    connect(openFileAction, &QAction::triggered, this, &MenuBar::openFile);

    saveFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), tr("Save"), this);
    saveFileAction->setShortcut(QKeySequence::Save);
    saveFileAction->setStatusTip(tr("Save the file to disk"));


    desaturationAction = new QAction(tr("Desaturation"), this);
    desaturationAction->setStatusTip(tr("Image color desaturation"));
    connect(desaturationAction, &QAction::triggered, this, &MenuBar::imageDesaturation);

    colorInvertionAction = new QAction(tr("Color invertion"), this);
    colorInvertionAction->setStatusTip(tr("Image color invertion"));
    connect(colorInvertionAction, &QAction::triggered, this, &MenuBar::imageColorInvertion);

    brightnessAction = new QAction(tr("Brightness"), this);
    brightnessAction->setStatusTip(tr("Change image brightness"));
    connect(brightnessAction, &QAction::triggered, this, &MenuBar::imageBrightness);
}

void MenuBar::imageColorInvertion() { mainWindow->canvasUi->imageColorInvertion(); }
void MenuBar::imageDesaturation() { mainWindow->canvasUi->imageDesaturation(); }
void MenuBar::imageBrightness() {
    QDialog *dialog = new QDialog();
    QVBoxLayout *layout = new QVBoxLayout(); 

    QHBoxLayout *tiltLayout = new QHBoxLayout();
    QSlider *tiltSlider = new QSlider(Qt::Horizontal, dialog); 
    QLabel *tiltLabel = new QLabel(tr("Tilt: "));

    tiltSlider->setRange(0, 30); 
    tiltLayout->addWidget(tiltLabel);
    tiltLayout->addWidget(tiltSlider);
    
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    QPushButton *confirm = new QPushButton(tr("Confirm"), dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"), dialog);
    
    buttonsLayout->addWidget(confirm);
    buttonsLayout->addWidget(cancel);
    
    layout->addLayout(tiltLayout);
    layout->addLayout(buttonsLayout);

    dialog->setLayout(layout);
    dialog->setWindowTitle(tr("Brighten image"));
    dialog->show();
    
    connect(tiltSlider, &QSlider::valueChanged, [=]() {
        mainWindow->canvasUi->imageBrightnessPreview(tiltSlider->value());
    });
    
    connect(confirm, &QPushButton::pressed, [=]() {
        mainWindow->canvasUi->imageBrightness(tiltSlider->value());
        dialog->hide();
    });

    connect(cancel, &QPushButton::pressed, [=]() {
        mainWindow->canvasUi->imageBrightness(0);
        dialog->hide();
    });
}

void MenuBar::imageMath() {
    
}

void MenuBar::openFile() {
    QFileDialog *fileDialog = new QFileDialog(mainWindow); 
    fileDialog->setDirectory(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    fileDialog->setNameFilter(tr("Portable AnyMap Files (*.pbm *.pgm *.ppm)"));
    fileDialog->setWindowTitle(tr("Open File"));
    
    QUrl fileUrl = fileDialog->getOpenFileUrl();
    if(fileUrl.isEmpty()) return;
    mainWindow->canvasUi->openFile(fileUrl);
}

void MenuBar::createMenus() {
    fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);

    modifiersMenu = menuBar->addMenu(tr("Modifiers"));
    modifiersMenu->addAction(desaturationAction);
    modifiersMenu->addAction(colorInvertionAction);
    modifiersMenu->addAction(brightnessAction);

    imageMathSubmenu = modifiersMenu->addMenu(tr("Image math"));
}

MenuBar::~MenuBar() {

}
