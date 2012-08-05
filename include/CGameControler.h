#ifndef CGAMECONTROLER_H
#define CGAMECONTROLER_H

#include "../include/CPoint.h"
#include "../include/key_handler.h"
#include "../include/frame.h"
#include "../include/def.h"

#include "../include/snake.h"
#include "../include/CMoveSnake.h"
#include "../include/CLogger.h"
#include "../include/CBasicWall.h"
#include "../include/CColisionDetector.h"
#include "../include/CItemsToEat.h"
#include "../include/IFrame.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread_time.hpp>
#include <boost/thread.hpp>
#include <memory>
#include <algorithm>


const unsigned int MAX_TIMEOUT = 300;
const unsigned int MIN_TIMEOUT  = 100;
const unsigned int DELTA_TIMEOUT = 20;
const char GRAPHIC_SNAKE_BODY = 'o';
const char GRAPHIC_WALL = '#';
const char GRAPHIC_ELEMENT_TO_EAT = '@';

class CGameControler
{
public:

    void RunGame();
    static CGameControler& getInstance();
private:
    CGameControler();
    static CGameControler* _instance;

    unsigned int _gameTimeout;
    std::shared_ptr<CItemToEat> _eatMe;
    std::shared_ptr<IFrame<unsigned int, GraphicalRepresentation, PointsList> > _frame;
    std::shared_ptr<CSnake> _snake;
    CKeyHandler _keyHandler;
    CMoveSnake _moveSnakeObj;
    CLogger logger;
    std::shared_ptr<CBasicWall> _wall;
    CColisionDetector _colision;

    bool _play;

    void addSingleNonColisionElementToEat();
    bool snakeEatElement();
    void speedUP();

    void frameDriver();
    bool snakeDriver();
};



#endif // CGAMECONTROLER_H
