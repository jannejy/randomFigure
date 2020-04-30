#include "Circle.h"
#include <QPainter>

void Circle::drawShape(QPainter *painter)
{
    painter->drawEllipse(QPoint(width() / 2,height() / 2), m_radius, m_radius);
}
