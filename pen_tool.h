#ifndef POPROJ_PEN_TOOL_H
#define POPROJ_PEN_TOOL_H


#include "tool.h"

///Narzędzie do rysowania
class PenTool : public Tool{
public:
    PenTool(int size, QColor color);
    void mousePressEvent(QMouseEvent* event, QPoint& lastPoint) override;
    void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event, QPainter& painter) override;

private:
    QPen createQPen() override;
};


#endif //POPROJ_PEN_TOOL_H
