#include "RandomFigureController.h"
#include <QPushButton>
#include <memory>
#include <random>
#include <chrono>
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

void RandomFigureController::drawFigure()
{
    std::default_random_engine randomEngine{static_cast<long unsigned int>
        (std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    unsigned radius = randomEngine() % 99 + 1;
    if (m_figurePtr)
    {
        displayFigure->layout()->removeWidget(m_figurePtr.get());
    }
    m_figurePtr = std::make_unique<Circle>(radius);
    m_figurePtr->repaint();
    displayFigure->layout()->addWidget(m_figurePtr.get());
}
