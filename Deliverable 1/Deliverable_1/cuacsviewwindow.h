#ifndef CUACSVIEWWINDOW_H
#define CUACSVIEWWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class cuACSViewWindow;
}

class cuACSViewWindow : public QMainWindow
{
//    Q_OBJECT

public:
    explicit cuACSViewWindow(QWidget *parent = 0);
    ~cuACSViewWindow();
    virtual void handlePermissions(int status) = 0; // Bridge Pattern
    virtual void viewData() = 0;    // Bridge Pattern

private:
//    Ui::cuACSViewWindow *ui;
};

#endif // CUACSVIEWWINDOW_H
