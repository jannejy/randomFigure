#pragma once

#include "ui_DisplayRandomFigure.h"
#include <QMainWindow>
#include <memory>
#include "Shape.h"

class RandomFigureController: public QMainWindow, private Ui::DisplayRandomFigure {
    Q_OBJECT
public:
    explicit RandomFigureController(QWidget* parent = nullptr);
    ~RandomFigureController() override = default;

    Q_SLOT void drawFigure();

private:
    void setNewParamsAndCreate();
private:
    std::unique_ptr<Shape> m_figurePtr = nullptr;
};

