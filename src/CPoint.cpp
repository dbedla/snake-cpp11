#include <CPoint.h>


bool CPoint::operator<(const CPoint& rhs) const
{
    if(this->_x < rhs._x)
    {
        return true;
    }


    if (this->_x == rhs._x)
    {
        if(this->_y < rhs._y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}


bool CPoint::operator==( const CPoint& rhs) const
{
    if(_x == rhs._x && _y == rhs._y)
    {
        return true;
    }
    return false;
}
