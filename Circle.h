#pragma once
#include <QWidget>
#include <memory>

class FigureParams;

class Circle : public QWidget{
public:
    Circle(std::shared_ptr<FigureParams> params = nullptr): m_params(params) {}
    ~Circle() = default;

protected:
    void paintEvent(QPaintEvent* e);
private:
    std::shared_ptr<const FigureParams> m_params;
};

