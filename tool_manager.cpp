#include "tool_manager.h"

ToolManager::ToolManager(QSize size)
{
    this->penColor = Qt::black;
    this->penSize = 2;
    this->eraserSize = 5;
    this->tool = new PenTool(penSize, penColor);
    this->currentTool = Tools::Pen;
    this->currentSize = size;
}

void ToolManager::changeTool(Tools newTool)
{
    switch (newTool)
    {
        case Tools::Pen:
            delete tool;
            currentTool = Tools::Pen;
            tool = new PenTool(penSize, penColor);
            isUsingPen = true;
            break;

        case Tools::Eraser:
            delete tool;
            currentTool = Tools::Eraser;
            tool = new EraserTool(eraserSize);
            isUsingPen = false;
            break;

        case Tools::Rectangle:
            delete tool;
            currentTool = Tools::Rectangle;
            tool = new RectangleShape(penSize, penColor);
            isUsingPen = true;
            break;

        case Tools::Circle:
            delete tool;
            currentTool = Tools::Circle;
            tool = new CircleShape(penSize, penColor);
            isUsingPen = true;
            break;

        case Tools::Line:
            delete tool;
            currentTool = Tools::Line;
            tool = new LineShape(penSize, penColor);
            isUsingPen = true;
            break;

        default:
            break;
    }
}

void ToolManager::setToolSize(int newSize)
{
    if (isUsingPen)
    {
        this->penSize = newSize;
    }
    else
    {
        this->eraserSize = newSize;
    }
    this->changeTool(currentTool);
}

void ToolManager::setColor(QColor newColor)
{
    if (isUsingPen)
    {
        this->penColor = newColor;
    }
    this->changeTool(currentTool);
}

void ToolManager::setSize(QSize newSize) {
    this->currentSize = newSize;
}


int ToolManager::getToolSize() const
{
    if (isUsingPen)
    {
        return penSize;
    }

    return eraserSize;
}

QColor ToolManager::getColor()
{
    if (isUsingPen)
    {
        return penColor;
    }
    return Qt::white;
}

QImage ToolManager::getTempImage() {
    return tool->getTempImage();
}

void ToolManager::mousePressEvent(QMouseEvent *event, QPoint& lastPoint)
{
    tool->mousePressEvent(event, lastPoint, currentSize);
}

void ToolManager::mouseMoveEvent(QMouseEvent *event, QPainter &painter, QPoint &lastPoint)
{
    tool->mouseMoveEvent(event, painter, lastPoint, currentSize);
}

void ToolManager::mouseReleaseEvent(QMouseEvent *event, QPoint &lastPoint, QImage &image)
{
    tool->mouseReleaseEvent(event, lastPoint, image);
}

void ToolManager::paintEvent(QPaintEvent *event, QPainter &painter)
{
    tool->paintEvent(event, painter, currentSize);
}

