#include <QInputDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QImageWriter>
#include <QStandardPaths>
#include "main_window.h"
#include "drawing_area.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    createDrawingArea();
    createMenuBar();
}

void MainWindow::createDrawingArea()
{
    drawingArea = new DrawingArea(this);
    setCentralWidget(drawingArea);
}

void MainWindow::createMenuBar()
{
    QToolBar* toolBar = new QToolBar(this);

    openAction = toolBar -> addAction("Open");
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    saveAction = toolBar->addAction("Save");
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);

    toolBar->addSeparator();

    penAction = toolBar->addAction("Pen");
    connect(penAction, &QAction::triggered, this, &MainWindow::setPenTool);

    eraserAction = toolBar->addAction("Eraser");
    connect(eraserAction, &QAction::triggered, this, &MainWindow::setEraserTool);

    rectangleAction = toolBar->addAction("Rectangle");
    connect(rectangleAction, &QAction::triggered, this, &MainWindow::setRectangleShape);

    circleAction = toolBar->addAction("Circle");
    connect(circleAction, &QAction::triggered, this, &MainWindow::setCircleShape);

    lineAction = toolBar->addAction("Line");
    connect(lineAction, &QAction::triggered, this, &MainWindow::setLineShape);

    toolBar->addSeparator();

    sizeAction = toolBar->addAction("Size");
    connect(sizeAction, &QAction::triggered, this, &MainWindow::setSize);

    colorAction = toolBar->addAction("Color");
    connect(colorAction, &QAction::triggered, this, &MainWindow::setColor);

    toolBar->addSeparator();

    undoAction = toolBar->addAction("Undo");
    connect(undoAction, &QAction::triggered, this, &MainWindow::undo);

    redoAction = toolBar->addAction("Redo");
    connect(redoAction, &QAction::triggered, this, &MainWindow::redo);

    toolBar->addSeparator();

    clearImage = toolBar->addAction("Clear");
    connect(clearImage, &QAction::triggered, this, &MainWindow::clear);

    addToolBar(toolBar);
}

void MainWindow::open()
{
    QString defaultDir = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    QString filePath = QFileDialog::getOpenFileName(this, "Open Image", defaultDir, "Images (*.png *.jpg *.jpeg)");

    if (!filePath.isEmpty())
    {
        QImage image(filePath);
        if (!image.isNull())
        {
            drawingArea->setImage(image);
        }
        else
        {
            QMessageBox::warning(this, "Open Error", "Failed to open the image.");
        }
    }
}

void MainWindow::save()
{
    QString defaultDir = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", defaultDir, "Images (*.png *.jpg *.jpeg)");

    QImage imageToSave = drawingArea->getImage();
    bool successSave = imageToSave.save(filePath);

    if (successSave)
    {
        QMessageBox::information(this, "Image Saved", "The image has been saved successfully.");
    }
    else
    {
        QMessageBox::warning(this, "Save Error", "Failed to save the image.");
    }
}

void MainWindow::setPenTool()
{
    colorAction->setDisabled(false);
    drawingArea->toolManager->changeTool(Tools::Pen);
}

void MainWindow::setEraserTool()
{
    colorAction->setDisabled(true);
    drawingArea->toolManager->changeTool(Tools::Eraser);
}

void MainWindow::setRectangleShape()
{
    colorAction->setDisabled(false);
    drawingArea->toolManager->changeTool(Tools::Rectangle);
}

void MainWindow::setCircleShape()
{
    colorAction->setDisabled(false);
    drawingArea->toolManager->changeTool(Tools::Circle);
}

void MainWindow::setLineShape()
{
    colorAction->setDisabled(false);
    drawingArea->toolManager->changeTool(Tools::Line);
}

void MainWindow::setSize()
{
    bool ok;
    int newSize;
    if (drawingArea->toolManager->isUsingPen)
    {
        newSize = QInputDialog::getInt(this, "Pen", "Choose new size", drawingArea->toolManager->getSize(), 1, 25, 1, &ok);
    }
    else
    {
        newSize = QInputDialog::getInt(this, "Eraser", "Choose new size", drawingArea->toolManager->getSize(), 5, 50, 1, &ok);
    }

    if (ok)
    {
        drawingArea->toolManager->setSize(newSize);
    }
}

void MainWindow::setColor()
{
    QColor newColor = QColorDialog::getColor(drawingArea->toolManager->getColor());
    drawingArea->toolManager->setColor(newColor);
}

void MainWindow::undo()
{
    drawingArea->undo();
}

void MainWindow::redo()
{
    drawingArea->redo();
}

void MainWindow::clear()
{
    drawingArea->clearImage();
}
