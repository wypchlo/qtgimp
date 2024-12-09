#ifndef UI_MENU_BAR_H
#define UI_MENU_BAR_H

#include <QtWidgets>

class MainWindow;

class MenuBar : public QObject
{
    Q_OBJECT

public:
    MenuBar(MainWindow *mainWindow);
    ~MenuBar();

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

#endif // UI_MENU_BAR_H
