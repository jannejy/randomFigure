#include "Square.h"
#include <QPainter>

void Square::drawShape(QPainter *painter) {
    painter->drawRect(QRect(width() / 2 - m_sideLength / 2, height() / 2 - m_sideLength / 2,
                            m_sideLength, m_sideLength));
}
