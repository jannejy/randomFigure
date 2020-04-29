#pragma once
#include <QWidget>
#include <memory>

class Shape: public QWidget {
public:
    explicit Shape(unsigned color = 0);
    virtual ~Shape() = default;

    unsigned getColorUInt() const { return colorToUInt(m_color); }
    Qt::GlobalColor getColor() const { return m_color;}
    void setColor(unsigned color) { checkAndSetColor(color); }
protected:
    virtual void drawShape(QPainter*) = 0;
    void paintEvent(QPaintEvent* e) override;
private:
    void checkAndSetColor(unsigned color);
    static unsigned colorToUInt(Qt::GlobalColor color);

    Qt::GlobalColor m_color; // color of a figure
};

