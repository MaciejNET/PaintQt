#ifndef POPROJ_TOOL_MANAGER_H
#define POPROJ_TOOL_MANAGER_H

#include "tool.h"
#include "pen_tool.h"
#include "eraser_tool.h"
#include "line_shape.h"
#include "rectangle_shape.h"
#include "circle_shape.h"

enum Tools
{
    Pen,
    Eraser,
    Rectangle,
    Circle,
    Line
};

///Klasa do obsługi narzędzi
class ToolManager {
public:
    ToolManager();

    /// Metoda do ustawiania akutalnie używanego narzędzia
    /// \param newTool Nowe narzędzie
    void changeTool(Tools newTool);

    /// Funkcja do ustawania rozmiaru długopisu lub gumki
    /// \param newSize Nowy rozmiar
    void setSize(int newSize);

    /// Funkcja do ustawania koloru długopisu (jeżeli aktualnie używamy gmuki funkcja nic nie zrobi)
    /// \param newColor Nowy kolor
    void setColor(QColor newColor);

    /// Fukcja do pobierania aktualnego rozmiaru narzędzia
    /// \return Aktualny rozmiar narzędzia
    int getSize();

    /// Fukcja do pobierania aktualnego koloru narzędzia
    /// \return Aktualny kolor narzędzia
    QColor getColor();

    /// Metoda, która wykonuje czynności gdy zostanie wciśnięty przycisk myszki
    /// \param event Standardowy mouse event
    /// \param lastPoint Ostatni punkt w którym znajdował się kursor
    void mousePressEvent(QMouseEvent* event, QPoint& lastPoint);

    /// Metoda, która wykonuje czynności podczas poruszania myszą
    /// \param event Standrdowy mouse event
    /// \param painter Paiter umożliwający rysowanie na ekranie
    /// \param lastPoint Ostatni punkt w którym znajdował się kursor
    void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint);

    /// Metoda, która wykonuje czynności gdy zostanie puszczony przycisk myszki
    /// \param event Standardowy mouse event
    void mouseReleaseEvent(QMouseEvent* event);

    /// Metoda do rysowania na ekranie
    /// \param event Standardowy paint event
    /// \param painter Painter umożliwający rysowanie na ekranie
    void paintEvent(QPaintEvent* event, QPainter& painter);

    ///Flaga do sprawdzenia czy akutalnie używany jest długopis czy gumka
    bool isUsingPen = true;
private:
    Tool* tool;
    int penSize;
    QColor penColor;
    int eraserSize;
    Tools currentTool;
};


#endif //POPROJ_TOOL_MANAGER_H
