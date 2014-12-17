#include "areamanager.h"

AreaManager::AreaManager()
    : m_result(0)
{
}

AreaManager::~AreaManager()
{
    for(unsigned int i = 0; i < m_rects.size(); ++i){
        delete m_rects[i];
    }
    m_rects.clear();
}

void AreaManager::addRect(const Rect* rect)
{
    AreaManager aMan;

    for (unsigned int i = 0; i < m_rects.size(); ++i){
        aMan.addRect(m_rects[i]->intersection(rect));
    }

    m_result += rect->area() - aMan.result();
    m_rects.push_back(rect);
}

double AreaManager::result() const
{
    return  m_result;
}
