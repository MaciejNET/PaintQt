#ifndef POPROJ_TOOL_MANAGER_H
#define POPROJ_TOOL_MANAGER_H

#include "tool.h"
#include "pen_tool.h"
#include "eraser_tool.h"
#include "line_shape.h"
#include "rectangle_shape.h"
#include "circle_shape.h"

enum Tools
{
    Pen,
    Eraser,
    Rectangle,
    Circle,
    Line
};

class ToolManager {
public:
    ToolManager();
    void changeTool(Tools newTool);
    void setSize(int newSize);
    void setColor(QColor newColor);
    int getSize();
    QColor getColor();
    void mousePressEvent(QMouseEvent* event, QPoint& lastPoint);
    void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event, QPainter& painter);
    bool isUsingPen = true;
private:
    Tool* tool;
    int penSize;
    QColor penColor;
    int eraserSize;
    Tools currentTool;
};


#endif //POPROJ_TOOL_MANAGER_H
