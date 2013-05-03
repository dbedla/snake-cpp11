#include<iostream>
#include <vector>

#include <CGameControler.h>

#include <CPoint.h>
#include <key_handler.h>
#include <frame.h>
#include <def.h>

#include <snake.h>
#include <CMoveSnake.h>
#include <CLogger.h>
#include <CBasicWall.h>
#include <CColisionDetector.h>
#include <CItemsToEat.h>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread_time.hpp>
#include <boost/thread.hpp>



int main(void)
{
    CGameControler &Game = CGameControler::getInstance();
    Game.RunGame();
    return 0;
}

