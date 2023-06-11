#ifndef POPROJ_ERASER_TOOL_H
#define POPROJ_ERASER_TOOL_H

#include "tool.h"

class EraserTool : public Tool{
public:
    explicit EraserTool(int size);
    void mousePressEvent(QMouseEvent* event, QPoint& lastPoint) override;
    void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event, QPainter& painter) override;
private:
    QPen createQPen() override;
};


#endif //POPROJ_ERASER_TOOL_H
