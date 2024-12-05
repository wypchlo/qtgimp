#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
};

MainWindow::~MainWindow() {

}
