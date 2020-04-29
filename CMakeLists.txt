cmake_minimum_required(VERSION 3.16)
project(randomFigure)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC_ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(randomFigure main.cpp RandomFigureController.cpp RandomFigureController.h Circle.cpp Circle.h Shape.cpp Shape.h)

target_link_libraries(randomFigure Qt5::Core)
target_link_libraries(randomFigure Qt5::Gui)
target_link_libraries(randomFigure Qt5::Widgets)