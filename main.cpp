#include<iostream>
#include <vector>

#include "../include/CGameControler.h"

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



int main(void)
{
    CGameControler &Game = CGameControler::getInstance();
    Game.RunGame();
    return 0;
}

