#include "line_shape.h"

LineShape::LineShape(int size, QColor color) : Tool(size, color) {

}

void LineShape::mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size)
{
    point = lastPoint;
    tempImage = QImage(size, QImage::Format_ARGB32);
    tempImage.fill(Qt::transparent);
}

void LineShape::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size)
{
    tempImage.fill(Qt::transparent);
    QPainter p(&tempImage);
    p.setPen(this->createQPen());
    p.drawLine(point, lastPoint);
}


void LineShape::mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image)
{
    QPainter painter(&image);
    painter.setPen(createQPen());
    painter.drawLine(point, lastPoint);
    tempImage.fill(Qt::transparent);
}

void LineShape::paintEvent(QPaintEvent *event, QPainter &painter, QSize size)
{

}

QPen LineShape::createQPen() {
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}
