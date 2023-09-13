#ifndef POPROJ_LINE_SHAPE_H
#define POPROJ_LINE_SHAPE_H

#include "tool.h"

class LineShape : public Tool{
public:
    LineShape(int size, QColor color);
    void mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) override;
    void mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size) override;
    void mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) override;
    void paintEvent(QPaintEvent *event, QPainter &painter, QSize size) override;

private:
    QPen createQPen() override;
    QPoint point;
    QLine line;
};


#endif //POPROJ_LINE_SHAPE_H
