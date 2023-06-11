#include "circle_shape.h"

CircleShape::CircleShape(int size, QColor color) : Tool(size, color) {
}

void CircleShape::mousePressEvent(QMouseEvent *event, QPoint &lastPoint) {
    point = lastPoint;
    rect = QRect();
    rect.setTopLeft(point);
}

void CircleShape::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint) {
    QPoint currentPosition = event->pos();

    rect.setBottomRight(currentPosition);

    painter.eraseRect(rect);
    painter.setPen(this->createQPen());
    painter.drawEllipse(rect);
}

void CircleShape::mouseReleaseEvent(QMouseEvent *event) {

}

void CircleShape::paintEvent(QPaintEvent *event, QPainter &painter) {

}

QPen CircleShape::createQPen() {
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}