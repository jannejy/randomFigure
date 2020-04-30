#include "Shape.h"
#include <QPainter>

void Shape::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setBrush(m_color);
    drawShape(&painter);
}

Shape::Shape(unsigned color)
{
    checkAndSetColor(color);
}

void Shape::checkAndSetColor(unsigned color)
{
    if (color > colorToUInt(Qt::GlobalColor::transparent))
    {
        throw std::out_of_range("Wrong cast into Qt::GlobalColor");
    }
    m_color = static_cast<Qt::GlobalColor>(color);
}

unsigned Shape::colorToUInt(Qt::GlobalColor color)
{
    return static_cast<unsigned>(color);
}
