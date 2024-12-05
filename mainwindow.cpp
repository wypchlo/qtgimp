#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *window = new QWidget;
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout;

    QString greeter = tr("Welcome to QTGimp!");
    statusBar()->showMessage(greeter);

    window->setLayout(layout);

    createActions();
    createMenus();

    //General window settings

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
}

void MainWindow::createActions() {
    openFile = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), tr("Open"), this);

    saveFile = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), tr("Save"), this);
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);
}

MainWindow::~MainWindow() {

}
