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

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread_time.hpp>
#include <boost/thread.hpp>
#include <memory>

const unsigned int START_SPEED = 300;
const unsigned int SPEED_UP = 30;

class CGameControler
{
public:
    CGameControler();
    void RunGame();

private:
    //CPoint obj;
    unsigned int _gameSpeed;
    std::shared_ptr<CItemToEat> eatMe;
    std::shared_ptr<CFrame> frame;
    CSnake snake;
    CKeyHandler keyHandler;
    CMoveSnake moveSnakeObj;
    CLogger logger;
    std::shared_ptr<CBasicWall> wall;
    CColisionDetector colision_detector;
    bool _readKey;
    boost::mutex _mtxReadKey;
    void parseKeyMove(CMoveSnake &DirectionKeeper);

    void addSingleNonColisionElementToEat();
    bool snakeEatElement();
    void speedUP();

    void stopKeboardRead();
    bool _play;
};



#endif // CGAMECONTROLER_H
