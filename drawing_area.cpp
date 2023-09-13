#include "drawing_area.h"

#include <utility>

DrawingArea::DrawingArea(QWidget* parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    this->image = QImage(this->size(), QImage::Format_ARGB32);
    this->image.fill(Qt::white);
    images.push_back(image);
    toolManager = new ToolManager(this->size());
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

        if (images.size() > MAX_UNDO_STATES)
        {
            images.erase(images.begin());
        }

        images.push_back(image);
        imgNr++;
        if (imgNr != images.size() - 1)
        {
            std::vector<QImage> newImages(images.begin(), images.begin()+imgNr);
            this->images = newImages;
            images.push_back(image);
        }
    }
}

void DrawingArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, image, rect);

    QImage tempImage = currentToolTempImage();
    if (!tempImage.isNull()) {
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
    this->image.fill(Qt::white);
    images.push_back(image);
    imgNr++;
    update();
}

void DrawingArea::undo()
{
    if (canUndo())
    {
        QImage newImage(QSize(width(), height()), QImage::Format_RGB32);
        newImage.fill(Qt::white);
        imgNr--;
        this->image = newImage;
        QPainter painter(&image);
        painter.drawImage(QPoint(0, 0), images.at(imgNr));
        update();
    }
}

void DrawingArea::redo()
{
    if (canRedo())
    {
        QImage newImage(QSize(width(), height()), QImage::Format_RGB32);
        newImage.fill(Qt::white);
        imgNr++;
        this->image = newImage;
        QPainter painter(&image);
        painter.drawImage(QPoint(0, 0), images.at(imgNr));
        update();
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

bool DrawingArea::canUndo() const
{
    return imgNr > 0;
}

bool DrawingArea::canRedo()
{
    return imgNr < images.size()-1;
}

QImage DrawingArea::currentToolTempImage() const {
    return toolManager->getTempImage();
}
