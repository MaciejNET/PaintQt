#ifndef POPROJ_CIRCLE_SHAPE_H
#define POPROJ_CIRCLE_SHAPE_H

#include "tool.h"

class CircleShape : public Tool
{
public:
    CircleShape(int size, QColor color);
    void mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) override;
    void mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size) override;
    void mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) override;
    void paintEvent(QPaintEvent *event, QPainter &painter, QSize size) override;

private:
    QPen createQPen() override;
    QPoint point;
};


#endif //POPROJ_CIRCLE_SHAPE_H
