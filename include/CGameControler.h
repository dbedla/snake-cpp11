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

class CGameControler
{
public:
    CGameControler();
    void RunGame();

private:
    //CPoint obj;
    CItemToEat *eatMe;
    CFrame *frame;
    CSnake snake;
    CKeyHandler keyHandler;
    CMoveSnake moveSnakeObj;
    CLogger logger;
    CBasicWall *wall;
    CColisionDetector colision_detector;
    bool _readKey;
    boost::mutex _mtxReadKey;
    void parseKeyMove(CMoveSnake &DirectionKeeper);

    void addSingleNonColisionElementToEat();
    void snakeEatelement();

    void stopKeboardRead();
    bool _play;
};



#endif // CGAMECONTROLER_H
