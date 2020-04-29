#pragma once
#include <memory>
#include "Shape.h"

class Circle final : public Shape {
public:
    explicit Circle(unsigned rad = 0, unsigned color = 0): Shape(color), m_radius(rad) {}
    ~Circle() override = default;
private:
    void drawShape(QPainter* painter) final;
    unsigned m_radius; // distance from the center of widget
};

