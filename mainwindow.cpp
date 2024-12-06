#include <QtWidgets>

#include "mainwindow.h"
#include "menubarhandler.h"
#include "canvashandler.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *window = new QWidget;
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout;

    menuBarHandler = new MenuBarHandler(this);
    connect(menuBarHandler->openFile, &QAction::triggered, this, &MainWindow::openFile);

    statusBar()->showMessage(tr("Welcome to QTGimp!"));

    CanvasHandler *canvasHandler = new CanvasHandler(layout);
    canvasHandler->openPBM();

    window->setLayout(layout);

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
}

void MainWindow::openFile() {    
    QFileDialog *fileDialog = new QFileDialog(this); 
    fileDialog->setDirectory(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    fileDialog->setNameFilter("Image Files (*.pbm *.pgm *.ppm)");
    fileDialog->setWindowTitle(tr("Open File"));

    QUrl filePath = fileDialog->getOpenFileUrl();
    setWindowTitle(filePath.toString());
}

MainWindow::~MainWindow() {
    delete menuBarHandler;
}
