#ifndef RECT_H
#define RECT_H

#include <vector>
#include <memory>

struct Point {
    Point (double x_, double y_)
        : x(x_)
        , y(y_)
    {}

    double x;
    double y;
};

class Rect;

typedef std::shared_ptr<Rect> RectP;

class Rect {
public:
    Rect(const Point& ld, const Point& rh);

    double area        () const;
    Rect* intersection(const Rect* rect) const;

private:
    Point  m_ld;
    Point  m_rh;

    double m_totalArea;
};

#endif // RECT_H
