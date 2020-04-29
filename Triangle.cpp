#include "Triangle.h"
#include <QPainter>

Triangle::Triangle(const QVector<QPoint>& points, unsigned int color) : Shape(color), m_points(points)
{
    assert(points.size() == 3);
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
