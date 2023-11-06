//
// Created by Maciej Deroń on 18/09/2023.
//

#include <QInputDialog>
#include "../include/text_tool.h"

TextTool::TextTool(int size, QColor color) : Tool(size, color), font(QFont("Arial", size, QFont::Bold)) {}

void TextTool::mousePressEvent(QMouseEvent *event, QPoint &lastPoint, QSize size)
{
}

void TextTool::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint, QSize size)
{

}

void TextTool::mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image)
{
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Text Tool", "Enter text:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        QPainter painter(&image);
        painter.setFont(font);
        painter.setPen(createQPen());
        painter.drawText(lastPoint, text);
    }
}

void TextTool::paintEvent(QPaintEvent *event, QPainter &painter, QSize size) {}

QPen TextTool::createQPen()
{
    QPen pen(this->color, this->size, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    return pen;
}
