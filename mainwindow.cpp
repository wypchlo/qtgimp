#include <QtWidgets>

#include "mainwindow.h"
#include "menubarhandler.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *window = new QWidget;
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout;

    QString greeter = tr("Welcome to QTGimp!");
    statusBar()->showMessage(greeter);

    window->setLayout(layout);

    /*menuBarHandler =*/ new MenuBarHandler(this);

    //General window settings

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
}

MainWindow::~MainWindow() {

}
