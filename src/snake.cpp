#include "../include/snake.h"


CSnake::CSnake(CPoint headPosition, int startLength):minSnakeLen(MIN_SNAKE_LENGTH)
{
    if(startLength < minSnakeLen)
    {
        startLength = minSnakeLen;
    }

    for(int i=0; i<startLength; i++)
    {
        _body.push_back(headPosition);
        headPosition._y++;
    }
}


const int  CSnake::getMinSnakeLen()
{
    return minSnakeLen;
}



void CSnake::addBodyPart()
{
    CPoint lastPoint = _body.back();
    CPoint prelastPoint = *((_body.end()--)--);
    CPoint diffPoint(prelastPoint._x - prelastPoint._x, prelastPoint._y - prelastPoint._y);
    _body.push_back(CPoint( lastPoint._x + diffPoint._x , lastPoint._y + diffPoint._y));
}


const PointsList& CSnake::getFrameElements() const
{
    return _body;
}

void  CSnake::moveSnake( std::function<void(PointsList&)> &move)
{
    move(this->_body);
}
