#ifndef CPOINT_H
#define CPOINT_H

#include <list>


class CPoint
{
public:
    CPoint():_x(0), _y(0){}
    CPoint(unsigned int x, unsigned int y):_x(x), _y(y){}
    //CPoint(CPoint&);

    bool operator<( const CPoint& rhs) const;
    bool operator==( const CPoint& rhs) const;
    unsigned int _x;
    unsigned int _y;

};

typedef std::list<CPoint> PointsList;

#endif // CPOINT_H
