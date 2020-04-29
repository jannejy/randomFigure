#include "Shape.h"
#include <QPainter>

void Shape::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setBrush(m_color);
    drawShape(&painter);
}

Shape::Shape(unsigned int color)
{
    checkAndSetColor(color);
}

void Shape::checkAndSetColor(unsigned color)
{
    assert(color >= 0 && color <= colorToUInt(Qt::GlobalColor::transparent));
    m_color = static_cast<Qt::GlobalColor>(color);
}

unsigned Shape::colorToUInt(Qt::GlobalColor color)
{
    return static_cast<unsigned>(color);
}
