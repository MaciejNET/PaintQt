#include "circle_shape.h"

CircleShape::CircleShape(int size, QColor color) : Tool(size, color) {
}

void CircleShape::mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) {
    point = lastPoint;
    tempImage = QImage(size, QImage::Format_ARGB32);
    tempImage.fill(Qt::transparent);
}

void CircleShape::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size) {
    tempImage.fill(Qt::transparent);
    QPainter p(&tempImage);
    p.setPen(this->createQPen());
    p.drawEllipse(QRect(point, lastPoint));
}

void CircleShape::mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) {
    QPainter painter(&image);
    painter.setPen(createQPen());
    painter.drawEllipse(QRect(point, lastPoint));
    tempImage.fill(Qt::transparent);
}

void CircleShape::paintEvent(QPaintEvent *event, QPainter &painter, QSize size) {

}

QPen CircleShape::createQPen() {
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}