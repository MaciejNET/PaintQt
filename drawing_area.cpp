#include "drawing_area.h"

DrawingArea::DrawingArea(QWidget* parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    this->image = QImage(this->size(), QImage::Format_RGB32);
    this->image.fill(Qt::white);
    images.push_back(image);
    toolManager = new ToolManager;
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
        toolManager->mouseReleaseEvent(event);
        drawing = false;
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
    toolManager->paintEvent(event, painter);
    painter.drawImage(event->rect(), image, event->rect());
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
    this->image = newImage;
}

bool DrawingArea::canUndo()
{
    return imgNr > 0;
}

bool DrawingArea::canRedo()
{
    return imgNr < images.size()-1;
}
