#ifndef POPROJ_DRAWING_AREA_H
#define POPROJ_DRAWING_AREA_H

#include <QWidget>
#include "tool.h"
#include "pen_tool.h"
#include "eraser_tool.h"
#include "tool_manager.h"

///Klasa tworząca obszar do rysowania
class DrawingArea : public QWidget {
Q_OBJECT
public:
    explicit DrawingArea(QWidget* parent = nullptr);
    ToolManager* toolManager;

    ///Funkcja do cofania zmian
    void undo();

    ///Funkcja do przywracania zmian
    void redo();

    ///Funkcja do czyszczenia obrazu
    void clearImage();

    ///Funkcja do pobierania aktualnego obrazu
    QImage getImage();

    /// Ustawaia nowy obraz jako główny
    /// \param newImage Obraz do ustawiania jako główny
    void setImage(QImage newImage);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QImage image;
    bool drawing = false;
    QPoint lastPoint;
    std::vector<QImage> images;
    int imgNr = 0;

    bool canUndo();
    bool canRedo();
};


#endif //POPROJ_DRAWING_AREA_H
