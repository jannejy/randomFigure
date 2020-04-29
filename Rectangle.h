#pragma once
#include "Shape.h"

class Rectangle: public Shape {
public:
    explicit Rectangle(unsigned width = 0, unsigned height = 0, unsigned color = 0):
    Shape(color), m_width(width), m_height(height) {}
    ~Rectangle() override = default;
private:
    void drawShape(QPainter* painter) final;
    const unsigned m_width;
    const unsigned m_height;
};

