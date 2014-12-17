
#include <algorithm>

#include "rect.h"

Rect::Rect(const Point& ld, const Point& rh)
    : m_ld(ld)
    , m_rh(rh)
{
    m_totalArea = m_ld.x < m_rh.x && m_ld.y < m_rh.y      ?
                      (m_rh.x - m_ld.x)*(m_rh.y - m_ld.y) : 0;
}

double Rect::area() const {
    return m_totalArea;
}

Rect* Rect::intersection(const Rect* rect) const
{
    using namespace std;
    return new Rect(Point(max(m_ld.x, rect->m_ld.x), max(m_ld.y, rect->m_ld.y)),
                    Point(min(m_rh.x, rect->m_rh.x), min(m_rh.y, rect->m_rh.y)));
}
