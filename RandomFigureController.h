#pragma once

#include "ui_DisplayRandomFigure.h"
#include <QMainWindow>
#include <memory>

class RandomFigureController: public QMainWindow, private Ui::DisplayRandomFigure {
    Q_OBJECT
public:
    RandomFigureController(QWidget* parent = nullptr);
    ~RandomFigureController() = default;

    Q_SLOT void drawFigure();
private:
    std::unique_ptr<QWidget> m_figurePtr;
};

