#include "../include/CMoveSnake.h"

#include <iostream>

CMoveSnake::CMoveSnake(Direction startDirection )
{
    _oldDirection = _newDirection = startDirection;
    _oldDirection = RIGHT;
    _move[UP]    = std::bind(&CMoveSnake::moveUp,  this, std::placeholders::_1);
    _move[DOWN]  = std::bind(&CMoveSnake::moveDown, this, std::placeholders::_1);
    _move[LEFT]  = std::bind(&CMoveSnake::moveLeft, this, std::placeholders::_1);
    _move[RIGHT] = std::bind(&CMoveSnake::moveRight, this, std::placeholders::_1);
}


Direction CMoveSnake::getDirection()
{
     boost::lock_guard<boost::mutex>  guard( _direction_mutex);
     return _newDirection;
}


void CMoveSnake::setDirection(Direction direction)
{
    boost::lock_guard<boost::mutex>  guard( _direction_mutex);
    if( (direction == UP    && _newDirection != DOWN) ||
        (direction == DOWN  && _newDirection != UP)   ||
        (direction == LEFT  && _newDirection != RIGHT)||
        (direction == RIGHT && _newDirection != LEFT)  )
    {
        if(_newDirection != direction  )
        {
            _newDirection = direction;
        }
    }
}

void CMoveSnake::moveObj(PointsList &body)
{
    auto move = _move[_newDirection];
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
    //CPoint newBodypart = body.front();
    head._y--;
    //body.push_front(newBodypart);
    //body.pop_back();
}

void CMoveSnake::moveRight(CPoint & head)
{
    //CPoint newBodypart = body.front();
    head._x++;
    //body.push_front(newBodypart);
    //body.pop_back();
    return;
}

void CMoveSnake::moveLeft(CPoint & head)
{
    //CPoint newBodypart = body.front();
    head._x--;
    //body.push_front(newBodypart);
    //body.pop_back();
    return;
}



