#ifndef POPROJ_RECTANGLE_SHAPE_H
#define POPROJ_RECTANGLE_SHAPE_H

#include <QMouseEvent>
#include "tool.h"

class RectangleShape : public Tool
{
public:
    RectangleShape(int size, QColor color);
    void mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) override;
    void mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size) override;
    void mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) override;
    void paintEvent(QPaintEvent *event, QPainter &painter, QSize size) override;

private:
    QPen createQPen() override;
    QPoint point;
};


#endif //POPROJ_RECTANGLE_SHAPE_H
