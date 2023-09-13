#include "rectangle_shape.h"

RectangleShape::RectangleShape(int size, QColor color) : Tool(size, color) {}

void RectangleShape::mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size)
{
    point = lastPoint;
    tempImage = QImage(size, QImage::Format_ARGB32);
    tempImage.fill(Qt::transparent);
}

void RectangleShape::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size)
{
    tempImage.fill(Qt::transparent);
    QPainter p(&tempImage);
    p.setPen(this->createQPen());
    p.drawRect(QRect(point, lastPoint));
}

void RectangleShape::mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image)
{
    QPainter painter(&image);
    painter.setPen(createQPen());
    painter.drawRect(QRect(point, lastPoint));
    tempImage.fill(Qt::transparent);
}

void RectangleShape::paintEvent(QPaintEvent *event, QPainter &painter, QSize size)
{

}

QPen RectangleShape::createQPen()
{
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}