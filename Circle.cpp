#include "Circle.h"
#include <QPainter>

#include "FigureParams.h"

void Circle::drawShape(QPainter *painter) {
    unsigned distance = m_params->getDistance();
    painter->drawEllipse(QPoint(width() / 2,height() / 2), distance * 2, distance * 2);
}
