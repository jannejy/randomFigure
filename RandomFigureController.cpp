#include "RandomFigureController.h"
#include <QPushButton>
#include <memory>
#include <random>
#include <chrono>
#include "Shape.h"
#include "Circle.h"
#include "FigureParams.h"

RandomFigureController::RandomFigureController(QWidget* parent):
QMainWindow(parent), m_figurePtr(nullptr), m_params(std::make_shared<FigureParams>())
{
    setupUi(this);

    connect(pbGetRandomFigure, &QPushButton::clicked, this, &RandomFigureController::drawFigure);
    displayFigure->setLayout(new QVBoxLayout());
}

void RandomFigureController::drawFigure()
{
    setNewParams();
    if (m_figurePtr)
    {
        displayFigure->layout()->removeWidget(m_figurePtr.get());
    }
    m_figurePtr = std::make_shared<Circle>(m_params);
    m_figurePtr->repaint();
    displayFigure->layout()->addWidget(m_figurePtr.get());
}

void RandomFigureController::setNewParams()
{
    std::default_random_engine randomEngine{static_cast<long unsigned int>
                                            (std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    m_params->setDistance(randomEngine() % 99 + 1);
    m_params->setColor(randomEngine() % 17 + 2);
}
