#include "pen_tool.h"

PenTool::PenTool(int size, QColor color) : Tool(size, color){}

void PenTool::mousePressEvent(QMouseEvent *event, QPoint& lastPoint) {}

void PenTool::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint& lastPoint) {
    QPoint currentPosition = event->pos();

    painter.setPen(this->createQPen());
    painter.drawLine(lastPoint, currentPosition);
}

void PenTool::mouseReleaseEvent(QMouseEvent *event) {}

void PenTool::paintEvent(QPaintEvent *event, QPainter &painter) {}

QPen PenTool::createQPen() {
    QPen pen(color, size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    return pen;
}
