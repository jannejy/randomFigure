#include "RandomFigureController.h"
#include <QPushButton>
#include <memory>
#include <random>
#include <chrono>
#include <QMessageBox>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"

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
    try
    {
        setNewParamsAndCreate();
    }
    catch(const std::exception& e)
    {
        QMessageBox::critical(this, "Error!", QString::fromStdString(e.what()));
        return;
    }
    m_figurePtr->repaint();
    displayFigure->layout()->addWidget(m_figurePtr.get());
}

void RandomFigureController::setNewParamsAndCreate()
{
    std::default_random_engine randomEngine{static_cast<long unsigned int>
                                            (std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    unsigned color = randomEngine() % Shape::colorToUInt(Qt::darkCyan)
            + Shape::colorToUInt(Qt::black);
    int widget_width = displayFigure->width();
    int widget_height = displayFigure->height();
    QLayout* mainLayout = layout();
    if (mainLayout)
    {
        widget_width -= mainLayout->contentsMargins().left() + mainLayout->contentsMargins().right()
                + mainLayout->spacing() * 2;
        widget_height -= mainLayout->contentsMargins().top() + mainLayout->contentsMargins().bottom()
                         + mainLayout->spacing() * 2;
    }
    switch(randomEngine() % 4)
    {
        case 0:
        {
            unsigned radius = randomEngine() % std::min(widget_width / 2, widget_height / 2);
            m_figurePtr = std::make_unique<Circle>(radius, color);
            break;
        }
        case 1:
        {
            QVector<QPoint> points;
            for (int i = 0; i != 3; ++i)
            {
                int x = randomEngine() % widget_width;
                int y = randomEngine() % widget_height;
                points.push_back(QPoint(x, y));
            }
            m_figurePtr = std::make_unique<Triangle>(points, color);
            break;
        }
        case 2:
        {
            int w = randomEngine() % widget_width;
            int h = randomEngine() % widget_height;
            m_figurePtr = std::make_unique<Rectangle>(w, h, color);
            break;
        }
        case 3:
        {
            int length = randomEngine() % std::min(widget_width, widget_height);
            m_figurePtr = std::make_unique<Square>(length, color);
            break;
        }
        default:
            break;
    }
}
