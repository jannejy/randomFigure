#include "Circle.h"
#include <QPainter>

void Circle::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.drawEllipse(QPoint(width() / 2,height() / 2), m_radius * 2, m_radius * 2);
}

Circle::Circle(int rad): m_radius(rad) {

}
