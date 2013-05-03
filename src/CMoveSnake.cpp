#include <CMoveSnake.h>

#include <iostream>

CMoveSnake::CMoveSnake(Direction startDirection )
{
    _oldDirection = _newDirection = startDirection;
    _move[UP]    = std::bind(&CMoveSnake::moveUp,  this, std::placeholders::_1);
    _move[DOWN]  = std::bind(&CMoveSnake::moveDown, this, std::placeholders::_1);
    _move[LEFT]  = std::bind(&CMoveSnake::moveLeft, this, std::placeholders::_1);
    _move[RIGHT] = std::bind(&CMoveSnake::moveRight, this, std::placeholders::_1);
}


Direction CMoveSnake::getDirection()
{
     boost::lock_guard<boost::mutex>  guard( _direction_mutex);
     if( ! isDirectionOpposed(_newDirection))
     {
          _oldDirection = _newDirection ;
     }
     else
     {
         _newDirection = _oldDirection;
     }
     return _oldDirection;
}


void CMoveSnake::setDirection(const Direction& direction)
{
    boost::lock_guard<boost::mutex>  guard( _direction_mutex);
    if( ! isDirectionOpposed(direction) )
    {
        if(_newDirection != direction  )
        {
            _newDirection = direction;
        }
    }
}

void CMoveSnake::moveObj(PointsList &body)
{
    auto move = _move[ getDirection() ];
    CPoint newHead = body.front();
    move(newHead);
    body.push_front(newHead);
    body.pop_back();
}



void CMoveSnake::moveDown(CPoint & head)
{

    head._y++;

}

void CMoveSnake::moveUp(CPoint &head)
{
    head._y--;
}

void CMoveSnake::moveRight(CPoint & head)
{
    head._x++;
    return;
}

void CMoveSnake::moveLeft(CPoint & head)
{
    head._x--;
    return;
}


bool CMoveSnake::isDirectionOpposed(const Direction &direction)
{
    if( (direction == UP    && _oldDirection != DOWN) ||
        (direction == DOWN  && _oldDirection != UP)   ||
        (direction == LEFT  && _oldDirection != RIGHT)||
        (direction == RIGHT && _oldDirection != LEFT)  )
    {
        return false;
    }
    return true;
}


void CMoveSnake::update(Direction direction)
{
    setDirection(direction);
}
