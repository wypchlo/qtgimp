#include <QtWidgets>

#include "mainwindow.h"
#include "menubarhandler.h"
#include "canvashandler.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *window = new QWidget;
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout;

    statusBar()->showMessage(tr("Welcome to QTGimp!"));

    menuBarHandler = new MenuBarHandler(this);
    canvasHandler = new CanvasHandler(layout);

    window->setLayout(layout);

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
}

MainWindow::~MainWindow() {
    delete menuBarHandler;
}
