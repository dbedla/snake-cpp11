#ifndef CMOVESNAKE_H
#define CMOVESNAKE_H

#include "IMoveFrameObj.h"
#include "def.h"
#include "CPoint.h"
#include <map>
#include <functional>
#include <vector>
#include <algorithm>
#include <boost/thread.hpp>

class CMoveSnake: public IMoveFrameObj<PointsList, Direction>
{
public:
    CMoveSnake(Direction startDirection = UP);
    virtual void moveObj(PointsList & snake);
    virtual void setDirection(Direction direction);
    virtual Direction getDirection();

private:
    boost::mutex _direction_mutex;
    Direction _newDirection;
    Direction _oldDirection;

    std::map<Direction, std::function<void(CPoint &)> > _move;

    void moveLeft(CPoint &);
    void moveRight(CPoint &);
    void moveUp(CPoint &);
    void moveDown(CPoint &);

};

#endif // CMOVESNAKE_H
