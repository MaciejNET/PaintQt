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

    /// Metoda, która wykonuje czynności gdy zostanie wciśnięty przycisk myszki
    /// \param event Standardowy mouse event
    /// \param lastPoint Ostatni punkt w którym znajdował się kursor
    virtual void mousePressEvent(QMouseEvent* event, QPoint& lastPoint) = 0;

    /// Metoda, która wykonuje czynności podczas poruszania myszą
    /// \param event Standrdowy mouse event
    /// \param painter Paiter umożliwający rysowanie na ekranie
    /// \param lastPoint Ostatni punkt w którym znajdował się kursor
    virtual void mouseMoveEvent(QMouseEvent* event, QPainter& painter, QPoint& lastPoint) = 0;

    /// Metoda, która wykonuje czynności gdy zostanie puszczony przycisk myszki
    /// \param event Standardowy mouse event
    virtual void mouseReleaseEvent(QMouseEvent* event) = 0;

    /// Metoda do rysowania na ekranie
    /// \param event Standardowy paint event
    /// \param painter Painter umożliwający rysowanie na ekranie
    virtual void paintEvent(QPaintEvent* event, QPainter& painter) = 0;

    /// Metoda, która tworzy QPen z własności klasy (size, color)
    /// \return QPen(size, color)
    virtual QPen createQPen() = 0;

protected:
    int size;
    QColor color;
};


#endif //POPROJ_TOOL_H
