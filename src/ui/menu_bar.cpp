#include "menu_bar.h"

#include <QtWidgets>
#include "ui/main_window.h"

MenuBar::MenuBar(MainWindow *_mainWindow) {
    mainWindow = _mainWindow;
    menuBar = mainWindow->menuBar();

    createActions();
    createMenus();
}


void MenuBar::createActions() {
    // FILE

    openFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), tr("Open"), this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Open an existing file"));
    connect(openFileAction, &QAction::triggered, this, &MenuBar::openFile);

    saveFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), tr("Save"), this);
    saveFileAction->setShortcut(QKeySequence::Save);
    saveFileAction->setStatusTip(tr("Save the file to disk"));

    // FILTERS

    desaturationAction = new QAction(tr("Desaturation"), this);
    desaturationAction->setStatusTip(tr("Image color desaturation"));

    colorInvertionAction = new QAction(tr("Color invertion"), this);
    colorInvertionAction->setStatusTip(tr("Image color invertion"));
    connect(colorInvertionAction, &QAction::triggered, this, &MenuBar::imageColorInvertion);
}

void MenuBar::imageColorInvertion() {
    mainWindow->canvasUi->imageColorInvertion();
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

    filtersMenu = menuBar->addMenu(tr("Filters"));
    filtersMenu->addAction(desaturationAction);
    filtersMenu->addAction(colorInvertionAction);
}

MenuBar::~MenuBar() {

}
