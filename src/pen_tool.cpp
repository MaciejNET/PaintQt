#include "../include/pen_tool.h"

PenTool::PenTool(int size, QColor color) : Tool(size, color){}

void PenTool::mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) {}

void PenTool::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size)
{
    QPoint currentPosition = event->pos();

    painter.setPen(this->createQPen());
    painter.drawLine(lastPoint, currentPosition);
}

void PenTool::mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) {}

void PenTool::paintEvent(QPaintEvent *event, QPainter &painter, QSize size) {}

QPen PenTool::createQPen()
{
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}
