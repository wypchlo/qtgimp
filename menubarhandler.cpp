#include <QtWidgets>

#include "menubarhandler.h"
#include "mainwindow.h"

MenuBarHandler::MenuBarHandler(MainWindow *mainWindow) {
    menuBar = mainWindow->menuBar();

    createActions();
    createMenus();
}


void MenuBarHandler::createActions() {
    openFile = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), tr("Open"), this);
    openFile->setShortcuts(QKeySequence::Open);
    openFile->setStatusTip(tr("Open an existing file"));

    saveFile = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), tr("Save"), this);
    saveFile->setShortcuts(QKeySequence::Save);
    saveFile->setStatusTip(tr("Save the file to disk"));
}

void MenuBarHandler::createMenus() {
    fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);
}

MenuBarHandler::~MenuBarHandler() {

}
