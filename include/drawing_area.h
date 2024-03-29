#ifndef POPROJ_DRAWING_AREA_H
#define POPROJ_DRAWING_AREA_H

#include <QWidget>
#include <deque>
#include "tool.h"
#include "pen_tool.h"
#include "eraser_tool.h"
#include "tool_manager.h"

class DrawingArea : public QWidget
{
Q_OBJECT
public:
    explicit DrawingArea(QWidget* parent = nullptr);
    std::unique_ptr<ToolManager> toolManager;
    void undo();
    void redo();
    void clearImage();
    QImage getImage();
    void setImage(QImage newImage);
    const int MAX_UNDO_STATES = 15;

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
    std::deque<QImage> history;
    int currentHistoryIndex = 0;

    QImage currentToolTempImage() const;
    void pushToHistory(const QImage& img);
    void applyHistoryImage(int index);
};


#endif //POPROJ_DRAWING_AREA_H
