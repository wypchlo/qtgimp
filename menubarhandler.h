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

private:
    void createMenus();
    void createActions();

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *openFile;
    QAction *saveFile;
};

#endif // MENUBARHANDLER_H
