#pragma once
#include <QWidget>

class Circle : public QWidget{
public:
    Circle(unsigned rad = 0): m_radius(rad) {}
    ~Circle() = default;

protected:
    void paintEvent(QPaintEvent* e);
private:
    unsigned m_radius;
};

