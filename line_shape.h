#ifndef POPROJ_LINE_SHAPE_H
#define POPROJ_LINE_SHAPE_H

#include "tool.h"

///Narzędzie do rysowania lini prostej
class LineShape : public Tool{
public:
    LineShape(int size, QColor color);
    void mousePressEvent(QMouseEvent* event, QPoint& lastPoint) override;
    void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event, QPainter& painter) override;

private:
    QPen createQPen() override;
    QPoint point;
    QLine line;
};


#endif //POPROJ_LINE_SHAPE_H
