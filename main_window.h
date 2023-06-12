#ifndef POPROJ_MAIN_WINDOW_H
#define POPROJ_MAIN_WINDOW_H

#include <QMainWindow>
#include "tool.h"
#include "drawing_area.h"
#include <QToolBar>

///Klasa do obsługi głównego okna
class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    DrawingArea* drawingArea;

    void createDrawingArea();
    void createMenuBar();

private slots:
    void open();
    void save();
    void setPenTool();
    void setEraserTool();
    void setRectangleShape();
    void setCircleShape();
    void setLineShape();
    void setSize();
    void setColor();
    void undo();
    void redo();
    void clear();

private:
    QAction* openAction;
    QAction* saveAction;
    QAction* penAction;
    QAction* eraserAction;
    QAction* rectangleAction;
    QAction* circleAction;
    QAction* lineAction;
    QAction* sizeAction;
    QAction* colorAction;
    QAction* undoAction;
    QAction* redoAction;
    QAction* clearImage;
};


#endif //POPROJ_MAIN_WINDOW_H
