#include "line_shape.h"

LineShape::LineShape(int size, QColor color) : Tool(size, color) {

}

void LineShape::mousePressEvent(QMouseEvent *event, QPoint &lastPoint)
{
    point = lastPoint;
    line.setP1(point);
}

void LineShape::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint)
{
    QPoint currentPosition = event->pos();

    line.setP2(currentPosition);

    painter.eraseRect(painter.viewport());
    painter.setPen(this->createQPen());
    painter.drawLine(line);
}


void LineShape::mouseReleaseEvent(QMouseEvent *event)
{

}

void LineShape::paintEvent(QPaintEvent *event, QPainter &painter)
{

}

QPen LineShape::createQPen() {
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}
