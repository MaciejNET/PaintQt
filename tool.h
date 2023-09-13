#ifndef POPROJ_TOOL_H
#define POPROJ_TOOL_H

#include <QMouseEvent>
#include <QPainter>

class Tool {
public:
    Tool(int size, QColor color)
    {
        this->size = size;
        this->color = color;
    }
    virtual ~Tool() = default;
    virtual void mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) = 0;
    virtual void mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) = 0;
    virtual void paintEvent(QPaintEvent *event, QPainter &painter, QSize size) = 0;
    virtual QPen createQPen() = 0;
    QImage getTempImage() {return tempImage;}

protected:
    int size;
    QColor color;
    QImage tempImage;
};


#endif //POPROJ_TOOL_H
