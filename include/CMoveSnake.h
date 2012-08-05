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
#include "IObserver.h"

class CMoveSnake: public IMoveFrameObj<PointsList, Direction>, public IObserver<Direction>
{
public:
    CMoveSnake(Direction startDirection = UP);
    virtual void moveObj(PointsList & snake);
    virtual void setDirection(Direction direction);
    virtual Direction getDirection();

    //IObserver
    virtual void update(Direction);


private:
    boost::mutex _direction_mutex;
    Direction _newDirection;
    Direction _oldDirection;

    std::map<Direction, std::function<void(CPoint &)> > _move;

    void moveLeft(CPoint &);
    void moveRight(CPoint &);
    void moveUp(CPoint &);
    void moveDown(CPoint &);
    bool isDirectionOpposed(Direction &direction);

};

#endif // CMOVESNAKE_H
