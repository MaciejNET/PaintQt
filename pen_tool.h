#ifndef POPROJ_PEN_TOOL_H
#define POPROJ_PEN_TOOL_H

#include "tool.h"

class PenTool : public Tool{
public:
    PenTool(int size, QColor color);
    void mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) override;
    void mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size) override;
    void mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) override;
    void paintEvent(QPaintEvent *event, QPainter &painter, QSize size) override;

private:
    QPen createQPen() override;
};


#endif //POPROJ_PEN_TOOL_H
