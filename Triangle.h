#pragma once

#include "Shape.h"

class Triangle: public Shape {
public:
    explicit Triangle(const QVector<QPoint>& points, unsigned color = 0);
    ~Triangle() override = default;
private:
    void drawShape(QPainter* painter) final;
    const QVector<QPoint> m_points;// distance from the center of widget
};

