#include <QtWidgets>

#include "menubarhandler.h"
#include "mainwindow.h"

MenuBarHandler::MenuBarHandler(MainWindow *_mainWindow) {
    mainWindow = _mainWindow;
    menuBar = mainWindow->menuBar();

    createActions();
    createMenus();
}


void MenuBarHandler::createActions() {
    // FILE

    openFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), tr("Open"), this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Open an existing file"));
    connect(openFileAction, &QAction::triggered, this, &MenuBarHandler::openFile);

    saveFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), tr("Save"), this);
    saveFileAction->setShortcut(QKeySequence::Save);
    saveFileAction->setStatusTip(tr("Save the file to disk"));

    // FILTERS

    desaturationAction = new QAction(tr("Desaturation"), this);
    desaturationAction->setStatusTip(tr("Image color desaturation"));

    colorInvertionAction = new QAction(tr("Color invertion"), this);
    colorInvertionAction->setStatusTip(tr("Image color invertion"));
    connect(colorInvertionAction, &QAction::triggered, this, &MenuBarHandler::imageColorInvertion);
}

void MenuBarHandler::imageColorInvertion() {
    mainWindow->canvasHandler->imageColorInvertion();
}

void MenuBarHandler::openFile() {
    QFileDialog *fileDialog = new QFileDialog(mainWindow); 
    fileDialog->setDirectory(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    fileDialog->setNameFilter(tr("Portable AnyMap Files (*.pbm *.pgm *.ppm)"));
    fileDialog->setWindowTitle(tr("Open File"));
    
    QUrl fileUrl = fileDialog->getOpenFileUrl();
    if(fileUrl.isEmpty()) return;
    mainWindow->canvasHandler->openFile(fileUrl);
}

void MenuBarHandler::createMenus() {
    fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);

    filtersMenu = menuBar->addMenu(tr("Filters"));
    filtersMenu->addAction(desaturationAction);
    filtersMenu->addAction(colorInvertionAction);
}

MenuBarHandler::~MenuBarHandler() {

}
