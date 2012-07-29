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

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread_time.hpp>
#include <boost/thread.hpp>

/*
void testerOfsnakemove()
{
    CPoint headPos(10, 10);
    CSnake snake(headPos, 4);
    CMoveSnake moveSnakeObj;

    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj, &moveSnakeObj, std::placeholders::_1) ;

    //snake.moveSnake( move );
    //moveSnakeObj.setDirection(LEFT);
    //snake.moveSnake( move );
    //moveSnakeObj.setDirection(LEFT);
    //snake.moveSnake( move );
    moveSnakeObj.setDirection(UP);
    snake.moveSnake( move );

    moveSnakeObj.setDirection(RIGHT);
    snake.moveSnake( move );

    moveSnakeObj.setDirection(DOWN);
    snake.moveSnake( move );
    //moveSnakeObj.setDirection(DOWN);
    //snake.moveSnake( move );
    //moveSnakeObj.setDirection(RIGHT);
    //snake.moveSnake( move );
}*/

void tester_colision_detector(void)
{
    CBasicWall wall(20, 20);
    CPoint headPosition(4,3);
    CSnake snake(headPosition, 3);
    CColisionDetector colision_detector;
    CMoveSnake mveObj;
    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj, &mveObj, std::placeholders::_1);

    colision_detector(snake, wall);
    snake.moveSnake(move);

    colision_detector(snake, wall);
    snake.moveSnake(move);

    colision_detector(snake, wall);
    snake.moveSnake(move);

    colision_detector(snake, wall);
    snake.moveSnake(move);

}



int main(void)
{
    /*
    CPoint p(5,5);
    CFrame f;
    f.SetPoint(p);
    f.drawFrame();

    CKeyHandler keyHandler;
    keyHandler();
    */

    CGameControler Game;
    Game.RunGame();

    //testerOfsnakemove();

    //tester_colision_detector();

    //std::cout<<"2\n";
    return 0;
}
