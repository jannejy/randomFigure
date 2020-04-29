#include "Rectangle.h"
#include <QPainter>

void Rectangle::drawShape(QPainter *painter)
{
    painter->drawRect(QRect(width() / 2 - m_width / 2, height() / 2 - m_height / 2,
            m_width, m_height));
}
