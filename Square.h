#pragma once
#include "Shape.h"

class Square: public Shape {
public:
    explicit Square(unsigned sideLength = 0, unsigned color = 0):
            Shape(color), m_sideLength(sideLength) {}
    ~Square() override = default;
private:
    void drawShape(QPainter* painter) final;
    const unsigned m_sideLength;
};

