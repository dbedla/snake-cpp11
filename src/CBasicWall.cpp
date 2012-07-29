#include "../include/CBasicWall.h"


CBasicWall::CBasicWall(unsigned int widith, unsigned int height)
{
    for(int y=0; y<height; y++)
    {
        _wall.push_back( CPoint(0,y) );
        _wall.push_back( CPoint(widith-1,y) );
    }

    for(int x=0; x<widith; x++)
    {
        _wall.push_back( CPoint(x,0) );
        _wall.push_back( CPoint(x, height-1) );
    }

    _wall.sort();
    _wall.unique();
}


const PointsList& CBasicWall::getFrameElements() const
{
    return _wall;
}
