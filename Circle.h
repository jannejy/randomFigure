#pragma once
#include <memory>
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(std::shared_ptr<FigureParams> params = nullptr): Shape(params) {}
    ~Circle() override = default;
private:
    void drawShape(QPainter* painter) override;
};

