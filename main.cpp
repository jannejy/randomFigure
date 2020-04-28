#include <iostream>
#include <QApplication>
#include "RandomFigureController.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    RandomFigureController randomFigureController;
    randomFigureController.show();
    return app.exec();
}
