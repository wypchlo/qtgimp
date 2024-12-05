#include <QtWidgets>
#include <QMainWindow>

#include "mainmenubarhandler.h"
#include "mainwindow.h"

MainMenuBarHandler::MainMenuBarHandler(MainWindow *mainWindow) {
    QMenuBar *menuBar = QMainWindow::menuBar();
    menuBar->addMenu(tr("File"));
}

MainMenuBarHandler::~MainMenuBarHandler() {

}
