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
    saveFile = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), tr("Save"), this);
}

void MenuBarHandler::createMenus() {
    fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);
}

MenuBarHandler::~MenuBarHandler() {

}
