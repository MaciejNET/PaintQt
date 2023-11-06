#include "../include/tool_manager.h"
#include "../include/text_tool.h"

ToolManager::ToolManager(QSize size) :
    penColor(Qt::black),
    penSize(2),
    eraserSize(5),
    tool(std::make_unique<PenTool>(penSize, penColor)),
    currentTool(Tools::Pen),
    currentSize(size) {}

void ToolManager::changeTool(Tools newTool)
{
    switch (newTool)
    {
        case Tools::Pen:
            tool = std::make_unique<PenTool>(penSize, penColor);
            currentTool = Tools::Pen;
            isUsingPen = true;
            break;

        case Tools::Eraser:
            tool = std::make_unique<EraserTool>(eraserSize);
            currentTool = Tools::Eraser;
            isUsingPen = false;
            break;

        case Tools::Rectangle:
            tool = std::make_unique<RectangleShape>(penSize, penColor);
            currentTool = Tools::Rectangle;
            isUsingPen = true;
            break;

        case Tools::Circle:
            tool = std::make_unique<CircleShape>(penSize, penColor);
            currentTool = Tools::Circle;
            isUsingPen = true;
            break;

        case Tools::Line:
            tool = std::make_unique<LineShape>(penSize, penColor);
            currentTool = Tools::Line;
            isUsingPen = true;
            break;

        case Tools::Text:
            tool = std::make_unique<TextTool>(penSize, penColor);
            currentTool = Tools::Text;
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

void ToolManager::setSize(QSize newSize)
{
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

QImage ToolManager::getTempImage()
{
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

