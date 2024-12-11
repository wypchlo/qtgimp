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
    QAction *brightnessAction;

private:
    void createMenus();
    void createActions();

    void openFile();
    void imageColorInvertion();
    void imageDesaturation();
    void imageBrightness();
    void imageMath();
    
    MainWindow *mainWindow;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *modifiersMenu;
    QMenu *imageMathSubmenu;
};

#endif // UI_MENU_BAR_H
