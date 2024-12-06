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

private:
    void createMenus();
    void createActions();

    void openFile();
    
    MainWindow *mainWindow;
    QMenuBar *menuBar;
    QMenu *fileMenu;
};

#endif // MENUBARHANDLER_H
