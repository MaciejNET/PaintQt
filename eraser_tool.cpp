#include "eraser_tool.h"

EraserTool::EraserTool(int size) : Tool(size, Qt::white){}

void EraserTool::mousePressEvent(QMouseEvent *event, QPoint& lastPoint) {}

void EraserTool::mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint)
{
    QPoint currentPosition = event->pos();

    painter.setPen(this->createQPen());
    painter.setBrush(Qt::white);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawLine(lastPoint, currentPosition);
}

void EraserTool::mouseReleaseEvent(QMouseEvent *event) {}

void EraserTool::paintEvent(QPaintEvent *event, QPainter &painter) {}

QPen EraserTool::createQPen() {
    QPen pen(color, size);

    return pen;
}
