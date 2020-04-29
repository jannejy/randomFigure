#include "Shape.h"
#include <QPainter>

#include "FigureParams.h"

void Shape::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.setBrush(m_params->getColor());
    drawShape(&painter);
}
