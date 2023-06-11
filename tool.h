#ifndef POPROJ_TOOL_H
#define POPROJ_TOOL_H

#include <QMouseEvent>
#include <QPainter>

class Tool {
public:
    Tool(int size, QColor color)
    {
        this->size = size;
        this->color = color;
    }
    virtual ~Tool() = default;
    virtual void mousePressEvent(QMouseEvent* event, QPoint& lastPoint) = 0;
    virtual void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint) = 0;
    virtual void mouseReleaseEvent(QMouseEvent* event) = 0;
    virtual void paintEvent(QPaintEvent* event, QPainter& painter) = 0;
    virtual QPen createQPen() = 0;

protected:
    int size;
    QColor color;
};


#endif //POPROJ_TOOL_H
