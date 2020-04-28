#pragma once
#include <QWidget>

class Circle : public QWidget{
public:
    Circle(int rad = 0);
    ~Circle() = default;

protected:
    void paintEvent(QPaintEvent* e);
private:
    int m_radius = 5;
};

