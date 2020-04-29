#include "RandomFigureController.h"
#include <QPushButton>
#include <memory>
#include <random>
#include <chrono>
#include "Shape.h"
#include "Circle.h"

RandomFigureController::RandomFigureController(QWidget* parent):
QMainWindow(parent), m_figurePtr(nullptr)
{
    setupUi(this);

    connect(pbGetRandomFigure, &QPushButton::clicked, this, &RandomFigureController::drawFigure);
    displayFigure->setLayout(new QVBoxLayout());
}

void RandomFigureController::drawFigure()
{
    if (m_figurePtr)
    {
        displayFigure->layout()->removeWidget(m_figurePtr.get());
    }
    setNewParamsAndCreate();
    m_figurePtr->repaint();
    displayFigure->layout()->addWidget(m_figurePtr.get());
}

void RandomFigureController::setNewParamsAndCreate()
{
    std::default_random_engine randomEngine{static_cast<long unsigned int>
                                            (std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    unsigned radius = randomEngine() % 99 + 1;
    unsigned color = randomEngine() % 17 + 2;
    m_figurePtr = std::make_shared<Circle>(radius, color);
}
