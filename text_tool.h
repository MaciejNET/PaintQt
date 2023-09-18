#ifndef PAINTQT_TEXT_TOOL_H
#define PAINTQT_TEXT_TOOL_H

#include "tool.h"

class TextTool : public Tool {
public:
    TextTool(int size, QColor color);
    void mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size) override;
    void mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size) override;
    void mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image) override;
    void paintEvent(QPaintEvent *event, QPainter &painter, QSize size) override;
    QPen createQPen() override;

private:
    QFont font;
};


#endif //PAINTQT_TEXT_TOOL_H
