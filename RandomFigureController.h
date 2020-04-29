#pragma once

#include "ui_DisplayRandomFigure.h"
#include <QMainWindow>
#include <memory>

class FigureParams;
class Shape;

class RandomFigureController: public QMainWindow, private Ui::DisplayRandomFigure {
    Q_OBJECT
public:
    RandomFigureController(QWidget* parent = nullptr);
    ~RandomFigureController() = default;

    Q_SLOT void drawFigure();

private:
    void setNewParams();
private:
    std::shared_ptr<Shape> m_figurePtr;
    std::shared_ptr<FigureParams> m_params;
};

