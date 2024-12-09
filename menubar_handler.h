#ifndef MENUBARHANDLER_H
#define MENUBARHANDLER_H

#include <QtWidgets>

class MainWindow;

class MenuBarHandler : public QObject
{
    Q_OBJECT

public:
    MenuBarHandler(MainWindow *mainWindow);
    ~MenuBarHandler();

    QAction *openFileAction;
    QAction *saveFileAction;

    QAction *desaturationAction;
    QAction *colorInvertionAction;

private:
    void createMenus();
    void createActions();

    void openFile();
    void imageColorInvertion();
    
    MainWindow *mainWindow;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *filtersMenu;
};

#endif // MENUBARHANDLER_H
