#include "Circle.h"

#include <QPainter>
#include "FigureParams.h"

void Circle::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setBrush(m_params->getColor());
    unsigned distance = m_params->getDistance();
    painter.drawEllipse(QPoint(width() / 2,height() / 2), distance * 2, distance * 2);
}