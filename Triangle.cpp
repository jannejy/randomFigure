#include "Triangle.h"
#include <QPainter>

Triangle::Triangle(const QVector<QPoint>& points, unsigned int color) : Shape(color), m_points(points)
{
    if (points.size() != 3)
    {
        throw std::logic_error("No 3 points passed for creating triangle");
    }
}

void Triangle::drawShape(QPainter *painter)
{
    QPolygon p;
    for (const auto& points : m_points)
    {
        p << QPoint(points.x() + width() / 2, points.y() + height() / 2);
    }
    painter->drawPolygon(p);
}
