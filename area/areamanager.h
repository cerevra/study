#ifndef AREAMANAGER_H
#define AREAMANAGER_H

#include "rect.h"

typedef std::vector<const Rect*> Rects;

class AreaManager
{
public:
    AreaManager();
    ~AreaManager();

    void   addRect(const Rect* rect);
    double result () const;

private:
    Rects m_rects;

    double m_result;
};

#endif // AREAMANAGER_H
