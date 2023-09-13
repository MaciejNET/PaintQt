#include <QtGui/qpainterpath.h>
#include "eraser_tool.h"

EraserTool::EraserTool(int size) : Tool(size, Qt::white){}

void EraserTool::mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) {}

void EraserTool::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size)
{
    QPoint currentPosition = event->pos();

    painter.setPen(createQPen());
    painter.setBrush(this->color);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);

    int halfSize = this->size / 2;
    int numPoints = std::max(abs(currentPosition.x() - lastPoint.x()), abs(currentPosition.y() - lastPoint.y()));

    for (int i = 0; i <= numPoints; ++i)
    {
        float t = float(i) / float(numPoints);
        int x = lastPoint.x() + t * float(currentPosition.x() - lastPoint.x());
        int y = lastPoint.y() + t * float(currentPosition.y() - lastPoint.y());

        QRect rect(x - halfSize, y - halfSize, this->size, this->size);
        painter.drawRect(rect);
    }
}

void EraserTool::mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) {}

void EraserTool::paintEvent(QPaintEvent *event, QPainter &painter, QSize size) {}

QPen EraserTool::createQPen() {
    QPen pen(color, size, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    return pen;
}
