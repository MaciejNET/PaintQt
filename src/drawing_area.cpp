#include "../include/drawing_area.h"

#include <utility>

DrawingArea::DrawingArea(QWidget* parent) : QWidget(parent), image(QImage(this->size(), QImage::Format_ARGB32))
{
    setAttribute(Qt::WA_StaticContents);
    image.fill(Qt::white);
    history.push_back(image);
    toolManager = std::make_unique<ToolManager>(this->size());
}

void DrawingArea::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        drawing = true;
        lastPoint = event->pos();
        toolManager->mousePressEvent(event, lastPoint);
    }
}

void DrawingArea::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
    {
        QPainter painter(&image);
        toolManager->mouseMoveEvent(event, painter, lastPoint);
        lastPoint = event->pos();
        update();
    }
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        toolManager->mouseReleaseEvent(event, lastPoint, image);
        drawing = false;
        pushToHistory(image);
    }
}

void DrawingArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, image, rect);

    QImage tempImage = currentToolTempImage();
    if (!tempImage.isNull())
    {
        painter.drawImage(rect, tempImage, rect);
    }
}


void DrawingArea::resizeEvent(QResizeEvent *event)
{
    QSize newSize(QWidget::width(), QWidget::height());
    if (image.size() == newSize) return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(Qt::white);

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), this->image);
    this->image = newImage;
    toolManager->setSize(newSize);
    update();
}

void DrawingArea::clearImage()
{
    QImage whiteImage(image.size(), QImage::Format_ARGB32);
    whiteImage.fill(Qt::white);

    if (image != whiteImage)
    {
        this->image = std::move(whiteImage);
        pushToHistory(this->image);
        update();
    }
}

void DrawingArea::undo()
{
    if (currentHistoryIndex > 0)
    {
        applyHistoryImage(--currentHistoryIndex);
    }
}

void DrawingArea::redo()
{
    if (currentHistoryIndex < history.size() - 1)
    {
        applyHistoryImage(++currentHistoryIndex);
    }
}

QImage DrawingArea::getImage()
{
    return image;
}

void DrawingArea::setImage(QImage newImage)
{
    this->image = std::move(newImage);
}

QImage DrawingArea::currentToolTempImage() const
{
    return toolManager->getTempImage();
}

void DrawingArea::pushToHistory(const QImage &img)
{
    while (history.size() > currentHistoryIndex + 1)
    {
        history.pop_back();
    }

    history.push_back(img);

    while (history.size() > MAX_UNDO_STATES)
    {
        history.pop_front();
        currentHistoryIndex = std::max(0, currentHistoryIndex - 1);
    }

    currentHistoryIndex = std::min(currentHistoryIndex + 1, MAX_UNDO_STATES);
}

void DrawingArea::applyHistoryImage(int index)
{
    if (index >= 0 && index < history.size())
    {
        image = history[index];
        update();
    }
}
