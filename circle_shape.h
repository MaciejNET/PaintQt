#ifndef POPROJ_CIRCLE_SHAPE_H
#define POPROJ_CIRCLE_SHAPE_H

#include "tool.h"

class CircleShape : public Tool{
public:
    CircleShape(int size, QColor color);
    void mousePressEvent(QMouseEvent* event, QPoint& lastPoint) override;
    void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event, QPainter& painter) override;

private:
    QPen createQPen() override;
    QPoint point;
    QRect rect;
};


#endif //POPROJ_CIRCLE_SHAPE_H
