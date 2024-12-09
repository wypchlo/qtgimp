#include <QtWidgets>

#include "main_window.h"
#include "menubar_handler.h"
#include "canvas_handler.h"

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
