#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *window = new QWidget;
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *testlabel = new QLabel(tr("This is simply a test to check if the layout is working"));
    QLabel *testlabel2 = new QLabel(tr("This is simply a second test to check if the layout is working"));
    //should appear one after another

    QString greeter = tr("Welcome to QTGimp!");
    statusBar()->showMessage(greeter);

    layout->addWidget(testlabel);
    layout->addWidget(testlabel2);
    window->setLayout(layout);

    setWindowTitle("QTGimp - " + tr("Main window"));
    setMinimumSize(300, 200);
    resize(600, 400);
}

MainWindow::~MainWindow() {

}
