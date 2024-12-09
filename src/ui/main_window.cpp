#include <QtWidgets>

#include "ui/main_window.h"
#include "ui/menu_bar.h"
#include "ui/canvas.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *window = new QWidget;
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout;

    statusBar()->showMessage(tr("Welcome to QTGimp!"));

    menuBarUi = new MenuBar(this);
    canvasUi = new Canvas(layout);

    window->setLayout(layout);

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
}

MainWindow::~MainWindow() {
    delete menuBarUi;
    delete canvasUi;
}
