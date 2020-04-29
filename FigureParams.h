#pragma once
#include <QColor>

class FigureParams {
public:
    explicit FigureParams(unsigned dist = 0, unsigned color = 0): m_distance(dist)
    {
        checkAndSetColor(color);
    }

    void setDistance(unsigned dist) { m_distance = dist; }
    void setColor(unsigned color) { checkAndSetColor(color); }
    unsigned getColorUInt() const { return colorToUInt(m_color); }
    Qt::GlobalColor getColor() const { return m_color;}
    unsigned getDistance() const { return m_distance; }

private:
    void checkAndSetColor(unsigned color)
    {
        assert(color >= 0 && color <= colorToUInt(Qt::GlobalColor::transparent));
        m_color = static_cast<Qt::GlobalColor>(color);
    }

    static unsigned colorToUInt(Qt::GlobalColor color)
    {
        return static_cast<unsigned>(color);
    }

private:
    unsigned m_distance; // distance from the center of widget
    Qt::GlobalColor m_color; // color of a figure
};