#include "RandomFigureController.h"
#include <QPushButton>
#include <memory>
#include <random>
#include <chrono>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

RandomFigureController::RandomFigureController(QWidget* parent):
QMainWindow(parent)
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
    unsigned color = randomEngine() % 17 + 2;
    switch(randomEngine() % 3)
    {
        case 0:
        {
            unsigned radius = randomEngine() % 99 + 1;
            m_figurePtr = std::make_unique<Circle>(radius, color);
            break;
        }
        case 1:
        {
            QVector<QPoint> points;
            for (int i = 0; i != 3; ++i)
            {
                int x = randomEngine() % 200 - 100;
                int y = randomEngine() % 200 - 100;
                points.push_back(QPoint(x, y));
            }
            m_figurePtr = std::make_unique<Triangle>(points, color);
            break;
        }
        case 2:
        {
            int w = randomEngine() % 200;
            int h = randomEngine() % 200;
            m_figurePtr = std::make_unique<Rectangle>(w, h, color);
            break;
        }
        default:
            break;
    }
}
