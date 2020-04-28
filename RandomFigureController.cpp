//
// Created by Ivan on 28.04.2020.
//

#include "RandomFigureController.h"
#include <QPushButton>
#include "Circle.h"

RandomFigureController::RandomFigureController(QWidget* parent):
QMainWindow(parent),
m_figurePtr(nullptr)
{
    setupUi(this);

    connect(pbGetRandomFigure, &QPushButton::clicked, this, &RandomFigureController::drawFigure);
    QLayout* layout = new QVBoxLayout();
    displayFigure->setLayout(layout);
}

void RandomFigureController::drawFigure() {
    static int radius = 2;
    if (m_figurePtr)
    {
        displayFigure->layout()->removeWidget(m_figurePtr.get());
    }
    m_figurePtr.reset(new Circle(radius));
    m_figurePtr->repaint();
    displayFigure->layout()->addWidget(m_figurePtr.get());
    radius *= 2;
}
