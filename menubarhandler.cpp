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
    openFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), tr("Open"), this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Open an existing file"));
    connect(openFileAction, &QAction::triggered, this, &MenuBarHandler::openFile);

    saveFileAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), tr("Save"), this);
    saveFileAction->setShortcut(QKeySequence::Save);
    saveFileAction->setStatusTip(tr("Save the file to disk"));
}

void MenuBarHandler::openFile() {
    QFileDialog *fileDialog = new QFileDialog(mainWindow); 
    fileDialog->setDirectory(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    fileDialog->setNameFilter(tr("Portable AnyMap Files (*.pbm *.pgm *.ppm)"));
    fileDialog->setWindowTitle(tr("Open File"));

    mainWindow->canvasHandler->openFile(fileDialog->getOpenFileUrl());
}

void MenuBarHandler::createMenus() {
    fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);
}

MenuBarHandler::~MenuBarHandler() {

}
