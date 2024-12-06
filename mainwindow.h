#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "menubarhandler.h"
#include "canvashandler.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    CanvasHandler *canvasHandler;
    MenuBarHandler *menuBarHandler;

private:
    void createActions();
    void createMenus();

    void openFile();
};
#endif // MAINWINDOW_H
