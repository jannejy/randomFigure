#pragma once
#include <QWidget>
#include <memory>

class FigureParams;

class Shape: public QWidget {
public:
    explicit Shape(const std::shared_ptr<FigureParams>& params) : m_params(params) {}
    virtual ~Shape() = default;
protected:
    virtual void drawShape(QPainter*) = 0;
    void paintEvent(QPaintEvent* e) override;

    std::shared_ptr<const FigureParams> m_params;
};

