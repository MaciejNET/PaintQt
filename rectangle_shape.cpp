#include "rectangle_shape.h"

RectangleShape::RectangleShape(int size, QColor color) : Tool(size, color) {}

void RectangleShape::mousePressEvent(QMouseEvent *event, QPoint& lastPoint) {
    point = lastPoint;
    rect = QRect(point, point);
}

void RectangleShape::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint)
{
    QPoint currentPosition = event->pos();
    painter.eraseRect(rect);
    painter.setPen(this->createQPen());
    painter.drawRect(rect = QRect(point, currentPosition));
}

void RectangleShape::mouseReleaseEvent(QMouseEvent *event) {

}

void RectangleShape::paintEvent(QPaintEvent *event, QPainter &painter) {

}

QPen RectangleShape::createQPen() {
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}


