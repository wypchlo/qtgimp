#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>

#include "ui/menu_bar.h"
#include "ui/canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Canvas *canvasUi;
    MenuBar *menuBarUi;

private:
    void createActions();
    void createMenus();

    void openFile();
};

#endif // UI_MAINWINDOW_H
